#ifndef EXODO_TYPES_H
#define EXODO_TYPES_H

#include <Arduino.h>

enum Screen : uint8_t {
  SCREEN_MENU,
  SCREEN_PAGE,
  SCREEN_TEST
};

enum Icon : uint8_t {
  ICON_HOME,
  ICON_WIFI,
  ICON_APPS,
  ICON_SETTINGS,
  ICON_BACK,
  ICON_INFO,
  ICON_SCAN,
  ICON_DISPLAY
};

struct Button {
  uint8_t pin;
  bool stable = HIGH;
  bool last = HIGH;
  bool click = false;
  uint32_t changedAt = 0;
};

struct Menu;

struct Item {
  const char *name;
  Icon icon;
  void (*action)();
  const Menu *submenu;
};

struct Menu {
  const char *title;
  const Item *items;
  uint8_t count;
};

#endif
