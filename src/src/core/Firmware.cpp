#include "Firmware.h"

#include <Arduino.h>
#include <Wire.h>

#include "AppState.h"
#include "Config.h"
#include "../navigation/Input.h"
#include "../navigation/MenuRegistry.h"
#include "../ui/Ui.h"

void setupFirmware() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);
  Wire.setClock(400000);

  beginButton(leftBtn, BTN_LEFT);
  beginButton(okBtn, BTN_OK);
  beginButton(rightBtn, BTN_RIGHT);

  if (!oled.begin(SSD1306_SWITCHCAPVCC, OLED)) {
    Serial.println("OLED not found. Check I2C wiring, address 0x3C/0x3D, and power.");
    while (true) delay(1000);
  }

  oled.setTextWrap(false);
  activeMenu = &mainMenu;
  loading("EXODO", "Boot", 4000);

  screen = SCREEN_MENU;
  selected = 0;
  stackSize = 0;
  dirty = false;
  drawScreen();
}

void loopFirmware() {
  updateInput();

  if (millis() - clockTick > CLOCK_MS) {
    clockTick = millis();
    dirty = true;
  }

  if (screen == SCREEN_TEST && millis() - animTick > ANIM_MS) {
    animTick = millis();
    dirty = true;
  }

  if (dirty) {
    dirty = false;
    drawScreen();
  }
}
