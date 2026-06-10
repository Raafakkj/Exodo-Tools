#ifndef EXODO_APP_STATE_H
#define EXODO_APP_STATE_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "Config.h"
#include "Types.h"

extern Adafruit_SSD1306 oled;

extern Button leftBtn;
extern Button okBtn;
extern Button rightBtn;

extern Screen screen;
extern const Menu *activeMenu;
extern const Menu *menuStack[STACK_MAX];
extern uint8_t stackSize;
extern uint8_t selected;
extern bool dirty;
extern uint32_t clockTick;
extern uint32_t animTick;

extern const char *pageTitle;
extern const char *pageLine1;
extern const char *pageLine2;
extern char textA[22];
extern char textB[22];

#endif
