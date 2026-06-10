#include "MenuRegistry.h"

#include "../actions/AppActions.h"
#include "../core/Config.h"
#include "../actions/HomeActions.h"
#include "Input.h"
#include "../actions/SettingsActions.h"
#include "../actions/WifiActions.h"

const Item wifiItems[] = {
  { "Back", ICON_BACK, back, nullptr },
  { "Sniffer", ICON_SCAN, wifiSniffing, nullptr },
  { "Channels", ICON_WIFI, wifiChannels, nullptr }
};

const Item appItems[] = {
  { "Back", ICON_BACK, back, nullptr },
  { "Action 1", ICON_APPS, appOne, nullptr },
  { "Action 2", ICON_APPS, appTwo, nullptr }
};

const Item settingsItems[] = {
  { "Back", ICON_BACK, back, nullptr },
  { "Status", ICON_SETTINGS, status, nullptr },
  { "About", ICON_INFO, about, nullptr },
  { "Display", ICON_DISPLAY, displayTest, nullptr }
};

const Menu wifiMenu = { "WIFI", wifiItems, COUNT_ITEMS(wifiItems) };
const Menu appMenu = { "APPS", appItems, COUNT_ITEMS(appItems) };
const Menu settingsMenu = { "SETTINGS", settingsItems, COUNT_ITEMS(settingsItems) };

const Item mainItems[] = {
  { "Home", ICON_HOME, home, nullptr },
  { "WiFi", ICON_WIFI, nullptr, &wifiMenu },
  { "Apps", ICON_APPS, nullptr, &appMenu },
  { "Settings", ICON_SETTINGS, nullptr, &settingsMenu }
};

const Menu mainMenu = { "EXODO", mainItems, COUNT_ITEMS(mainItems) };
