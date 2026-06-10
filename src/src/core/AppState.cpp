#include "AppState.h"

Adafruit_SSD1306 oled(W, H, &Wire, OLED_RST);

Button leftBtn;
Button okBtn;
Button rightBtn;

Screen screen = SCREEN_MENU;
const Menu *activeMenu = nullptr;
const Menu *menuStack[STACK_MAX];
uint8_t stackSize = 0;
uint8_t selected = 0;
bool dirty = true;
uint32_t clockTick = 0;
uint32_t animTick = 0;

const char *pageTitle = "";
const char *pageLine1 = "";
const char *pageLine2 = "";
char textA[22];
char textB[22];
