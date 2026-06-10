#ifndef EXODO_UI_H
#define EXODO_UI_H

#include <Arduino.h>

void page(const char *title, const char *line1, const char *line2);
void showDisplayTest();
void loading(const char *title, const char *message, uint16_t durationMs);
void drawScreen();

#endif
