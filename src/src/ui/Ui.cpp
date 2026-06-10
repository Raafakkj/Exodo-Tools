#include "Ui.h"

#include <string.h>

#include "../core/AppState.h"
#include "../core/Config.h"

void page(const char *title, const char *line1, const char *line2) {
  pageTitle = title;
  pageLine1 = line1;
  pageLine2 = line2;
  screen = SCREEN_PAGE;
  dirty = true;
}

void showDisplayTest() {
  screen = SCREEN_TEST;
  dirty = true;
}

static bool compact() {
  return H <= 32;
}

static void centerText(const char *text, int16_t y, uint8_t size, uint16_t color, uint16_t bg = SSD1306_BLACK) {
  int16_t x1, y1;
  uint16_t tw, th;
  oled.setTextSize(size);
  oled.setTextColor(color, bg);
  oled.getTextBounds(text, 0, y, &x1, &y1, &tw, &th);
  oled.setCursor(tw >= W ? 0 : (W - tw) / 2, y);
  oled.print(text);
  oled.setTextSize(1);
  oled.setTextColor(SSD1306_WHITE);
}

static void drawHeader(const char *title) {
  const uint32_t seconds = millis() / 1000;
  char timeText[6];
  snprintf(timeText, sizeof(timeText), "%02lu:%02lu", (unsigned long)((seconds / 60) % 100), (unsigned long)(seconds % 60));

  oled.fillRect(0, 0, W, 10, SSD1306_WHITE);
  oled.setTextColor(SSD1306_BLACK);
  oled.setCursor(2, 1);
  oled.print(title);
  oled.setCursor(84, 1);
  oled.print(timeText);
  oled.drawRect(118, 2, 8, 5, SSD1306_BLACK);
  oled.drawPixel(126, 4, SSD1306_BLACK);
  oled.fillRect(120, 4, 4, 2, SSD1306_BLACK);
  oled.setTextColor(SSD1306_WHITE);
}

static const char *iconText(Icon icon) {
  static const char *icons[] = { "H", "W", "A", "S", "<", "i", "?", "D" };
  return icons[icon];
}

static void drawIcon(Icon icon, int16_t x, int16_t y, int16_t size) {
  int16_t x1, y1;
  uint16_t tw, th;
  const char *label = iconText(icon);

  oled.setTextSize(1);
  oled.fillRoundRect(x, y, size, size, 5, SSD1306_WHITE);
  oled.getTextBounds(label, 0, 0, &x1, &y1, &tw, &th);
  oled.setTextColor(SSD1306_BLACK);
  oled.setCursor(x + ((size - tw) / 2), y + ((size - th) / 2));
  oled.print(label);
  oled.setTextColor(SSD1306_WHITE);
}

static void drawDots() {
  const int16_t start = (W - ((activeMenu->count - 1) * 8)) / 2;
  const int16_t y = H - 5;

  for (uint8_t i = 0; i < activeMenu->count; i++) {
    const int16_t x = start + (i * 8);
    if (i == selected) {
      oled.fillCircle(x, y, 2, SSD1306_WHITE);
    } else {
      oled.drawCircle(x, y, 1, SSD1306_WHITE);
    }
  }
}

static void drawMenu() {
  const Item &item = activeMenu->items[selected];
  oled.clearDisplay();
  drawHeader(activeMenu->title);

  if (compact()) {
    oled.fillRoundRect(9, 12, 110, 14, 3, SSD1306_WHITE);
    oled.setTextColor(SSD1306_BLACK);
    oled.setCursor(16, 16);
    oled.print(item.name);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(1, 16);
    oled.print("<");
    oled.setCursor(122, 16);
    oled.print(">");
  } else {
    oled.drawRoundRect(4, 14, 120, 38, 6, SSD1306_WHITE);
    drawIcon(item.icon, 8, 18, 30);
    oled.setCursor(46, 21);
    oled.print(selected + 1);
    oled.print("/");
    oled.print(activeMenu->count);
    oled.setCursor(46, 33);
    oled.print(item.name);
    oled.setCursor(2, 29);
    oled.print("<");
    oled.setCursor(122, 29);
    oled.print(">");
  }

  drawDots();
  oled.display();
}

static void drawPage() {
  oled.clearDisplay();
  drawHeader(pageTitle);

  if (compact()) {
    centerText(pageLine1, 15, 1, SSD1306_WHITE);
    centerText(pageLine2, 24, 1, SSD1306_WHITE);
  } else {
    oled.drawRoundRect(8, 17, 112, 34, 6, SSD1306_WHITE);
    centerText(pageLine1, 24, 1, SSD1306_WHITE);
    centerText(pageLine2, 36, 1, SSD1306_WHITE);
    centerText("OK = BACK", 55, 1, SSD1306_WHITE);
  }

  oled.display();
}

static void drawDisplayTest() {
  const uint8_t frame = (millis() / ANIM_MS) % 9;
  const int16_t top = compact() ? 13 : 18;
  const int16_t height = compact() ? 16 : 34;

  oled.clearDisplay();
  drawHeader("DISPLAY");
  oled.drawRoundRect(8, top, 112, height, 4, SSD1306_WHITE);
  oled.fillRoundRect(12 + (frame * 11), top + 7, 14, compact() ? 8 : 20, 3, SSD1306_WHITE);
  oled.display();
}

static void drawLogoE(int16_t x, int16_t y) {
  oled.fillRect(x, y, 2, 15, SSD1306_WHITE);
  oled.fillRect(x, y, 10, 2, SSD1306_WHITE);
  oled.fillRect(x, y + 6, 8, 2, SSD1306_WHITE);
  oled.fillRect(x, y + 13, 10, 2, SSD1306_WHITE);
}

static void drawLogoX(int16_t x, int16_t y) {
  for (uint8_t i = 0; i < 2; i++) {
    oled.drawLine(x + i, y, x + 10 + i, y + 14, SSD1306_WHITE);
    oled.drawLine(x + 10 + i, y, x + i, y + 14, SSD1306_WHITE);
  }
}

static void drawLogoO(int16_t x, int16_t y) {
  oled.drawRoundRect(x, y, 12, 15, 4, SSD1306_WHITE);
  oled.drawRoundRect(x + 1, y + 1, 10, 13, 3, SSD1306_WHITE);
}

static void drawLogoD(int16_t x, int16_t y) {
  oled.fillRect(x, y, 2, 15, SSD1306_WHITE);
  oled.fillRect(x + 2, y, 7, 2, SSD1306_WHITE);
  oled.fillRect(x + 2, y + 13, 7, 2, SSD1306_WHITE);
  oled.fillRect(x + 9, y + 2, 2, 11, SSD1306_WHITE);
  oled.drawPixel(x + 10, y + 3, SSD1306_WHITE);
  oled.drawPixel(x + 10, y + 11, SSD1306_WHITE);
}

static void drawSpacedText(const char *text, int16_t y, uint8_t gap) {
  const uint8_t len = strlen(text);
  const int16_t width = (len * 6) + ((len - 1) * gap);
  int16_t x = (W - width) / 2;

  oled.setTextSize(1);
  oled.setTextColor(SSD1306_WHITE);

  for (uint8_t i = 0; i < len; i++) {
    oled.setCursor(x, y);
    oled.print(text[i]);
    x += 6 + gap;
  }
}

static void drawExodoLogo(int16_t y) {
  int16_t x = 29;

  drawLogoE(x, y);
  x += 13;
  drawLogoX(x, y);
  x += 14;
  drawLogoO(x, y);
  x += 15;
  drawLogoD(x, y);
  x += 15;
  drawLogoO(x, y);

  drawSpacedText("TOOLS", y + 19, 2);
}

static uint8_t largeGlyphRow(char glyph, uint8_t row) {
  switch (glyph) {
    case 'D': {
      static const uint8_t rows[] = { 0x1E, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1E };
      return rows[row];
    }
    case 'E': {
      static const uint8_t rows[] = { 0x1F, 0x10, 0x10, 0x1E, 0x10, 0x10, 0x1F };
      return rows[row];
    }
    case 'O': {
      static const uint8_t rows[] = { 0x0E, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0E };
      return rows[row];
    }
    case 'X': {
      static const uint8_t rows[] = { 0x11, 0x0A, 0x04, 0x04, 0x04, 0x0A, 0x11 };
      return rows[row];
    }
    default:
      return 0;
  }
}

static uint8_t smallGlyphRow(char glyph, uint8_t row) {
  switch (glyph) {
    case 'L': {
      static const uint8_t rows[] = { 0x4, 0x4, 0x4, 0x4, 0x7 };
      return rows[row];
    }
    case 'O': {
      static const uint8_t rows[] = { 0x7, 0x5, 0x5, 0x5, 0x7 };
      return rows[row];
    }
    case 'S': {
      static const uint8_t rows[] = { 0x7, 0x4, 0x7, 0x1, 0x7 };
      return rows[row];
    }
    case 'T': {
      static const uint8_t rows[] = { 0x7, 0x2, 0x2, 0x2, 0x2 };
      return rows[row];
    }
    default:
      return 0;
  }
}

static void drawLargeGlyph(char glyph, int16_t x, int16_t y, uint8_t scale) {
  for (uint8_t row = 0; row < 7; row++) {
    const uint8_t bits = largeGlyphRow(glyph, row);
    for (uint8_t col = 0; col < 5; col++) {
      if (bits & (1 << (4 - col))) {
        oled.fillRect(x + (col * scale), y + (row * scale), scale, scale, SSD1306_WHITE);
      }
    }
  }
}

static void drawSmallGlyph(char glyph, int16_t x, int16_t y, uint8_t scale) {
  for (uint8_t row = 0; row < 5; row++) {
    const uint8_t bits = smallGlyphRow(glyph, row);
    for (uint8_t col = 0; col < 3; col++) {
      if (bits & (1 << (2 - col))) {
        oled.fillRect(x + (col * scale), y + (row * scale), scale, scale, SSD1306_WHITE);
      }
    }
  }
}

static void drawLargeWord(const char *text, int16_t x, int16_t y, uint8_t scale, uint8_t gap) {
  for (uint8_t i = 0; text[i] != '\0'; i++) {
    drawLargeGlyph(text[i], x, y, scale);
    x += (5 * scale) + gap;
  }
}

static void drawSmallWord(const char *text, int16_t x, int16_t y, uint8_t scale, uint8_t gap) {
  for (uint8_t i = 0; text[i] != '\0'; i++) {
    drawSmallGlyph(text[i], x, y, scale);
    x += (3 * scale) + gap;
  }
}

static void drawBootFrame(uint8_t frame) {
  oled.drawRect(2, 2, 124, 60, SSD1306_WHITE);

  for (uint8_t x = 6; x < 124; x += 8) {
    oled.drawPixel(x, 0, SSD1306_WHITE);
    oled.drawPixel(x, 63, SSD1306_WHITE);
  }

  for (uint8_t y = 6; y < 60; y += 8) {
    oled.drawPixel(0, y, SSD1306_WHITE);
    oled.drawPixel(127, y, SSD1306_WHITE);
  }

  for (uint8_t x = 8; x < 122; x += 8) {
    for (uint8_t y = 8; y < 58; y += 8) {
      if (((x + y + frame) % 16) == 0) {
        oled.drawPixel(x, y, SSD1306_WHITE);
      }
    }
  }
}

static void drawBootMascot(int16_t x, int16_t y) {
  oled.fillRoundRect(x + 2, y + 4, 18, 17, 4, SSD1306_WHITE);
  oled.fillRect(x, y + 5, 5, 7, SSD1306_WHITE);
  oled.fillRect(x + 17, y + 5, 5, 7, SSD1306_WHITE);
  oled.fillRect(x + 4, y + 2, 4, 5, SSD1306_WHITE);
  oled.fillRect(x + 14, y + 2, 4, 5, SSD1306_WHITE);

  oled.fillRect(x + 6, y + 10, 4, 3, SSD1306_BLACK);
  oled.fillRect(x + 13, y + 10, 4, 3, SSD1306_BLACK);
  oled.drawLine(x + 6, y + 16, x + 10, y + 19, SSD1306_BLACK);
  oled.drawLine(x + 10, y + 19, x + 16, y + 19, SSD1306_BLACK);
  oled.drawLine(x + 16, y + 19, x + 19, y + 16, SSD1306_BLACK);
}

static void drawBootCable() {
  oled.drawLine(10, 58, 10, 51, SSD1306_WHITE);
  oled.drawLine(10, 51, 17, 44, SSD1306_WHITE);
  oled.drawLine(17, 44, 34, 44, SSD1306_WHITE);
  oled.drawLine(34, 44, 42, 50, SSD1306_WHITE);
  oled.drawLine(42, 50, 57, 45, SSD1306_WHITE);
  oled.drawLine(57, 45, 64, 47, SSD1306_WHITE);
  oled.drawLine(64, 47, 56, 54, SSD1306_WHITE);
  oled.drawLine(56, 54, 38, 54, SSD1306_WHITE);
  oled.drawCircle(25, 51, 5, SSD1306_WHITE);
  oled.drawPixel(24, 50, SSD1306_WHITE);
  oled.drawPixel(28, 50, SSD1306_WHITE);
  oled.drawLine(52, 58, 67, 58, SSD1306_WHITE);
}

static void drawBootLoading(uint8_t frame, uint8_t percent) {
  const uint8_t progressWidth = map(percent, 0, 100, 0, 118);

  oled.clearDisplay();
  drawBootFrame(frame);
  drawBootMascot(8, 7);
  drawLargeWord("EXODO", 34, 8, 2, 1);
  drawSmallWord("TOOLS", 82, 28, 2, 2);
  drawBootCable();

  oled.setTextSize(1);
  oled.setTextColor(SSD1306_WHITE);
  oled.setCursor(98, 51);
  oled.print("0.9.1");

  oled.fillRect(5, 60, progressWidth, 1, SSD1306_WHITE);
  oled.drawPixel(5 + ((frame * 9) % 118), 59, SSD1306_WHITE);
  oled.display();
}

static void drawCompactBootLoading(uint8_t frame, uint8_t percent) {
  const uint8_t progressWidth = map(percent, 0, 100, 0, 118);

  oled.clearDisplay();
  oled.drawRect(2, 2, 124, 28, SSD1306_WHITE);
  centerText("EXODO", 7, 2, SSD1306_WHITE);
  drawSpacedText("TOOLS", 24, 1);
  oled.fillRect(5, 30, progressWidth, 1, SSD1306_WHITE);
  oled.drawPixel(5 + ((frame * 9) % 118), 29, SSD1306_WHITE);
  oled.display();
}

static void drawCompactLoading(const char *message, uint8_t frame, uint8_t percent) {
  const uint8_t barWidth = map(percent, 0, 100, 0, 104);

  oled.clearDisplay();
  centerText("EXODO TOOLS", 2, 1, SSD1306_WHITE);
  centerText(message, 12, 1, SSD1306_WHITE);
  oled.drawRoundRect(11, 23, 106, 7, 3, SSD1306_WHITE);
  oled.fillRoundRect(12, 24, barWidth, 5, 2, SSD1306_WHITE);
  oled.drawPixel(13 + ((frame * 9) % 102), 27, SSD1306_BLACK);
  oled.display();
}

static void drawLoading(const char *title, const char *message, uint8_t frame, uint8_t percent) {
  if (strcmp(title, "EXODO") == 0 && strcmp(message, "Boot") == 0) {
    if (compact()) {
      drawCompactBootLoading(frame, percent);
    } else {
      drawBootLoading(frame, percent);
    }
    return;
  }

  if (compact()) {
    drawCompactLoading(message, frame, percent);
    return;
  }

  const int16_t barY = 48;
  const uint8_t barWidth = map(percent, 0, 100, 0, 104);
  char statusText[22];
  snprintf(statusText, sizeof(statusText), "%s / %s", title, message);

  oled.clearDisplay();
  drawExodoLogo(4);
  centerText(statusText, 35, 1, SSD1306_WHITE);
  oled.drawRoundRect(11, barY, 106, 8, 4, SSD1306_WHITE);
  oled.fillRoundRect(12, barY + 1, barWidth, 6, 3, SSD1306_WHITE);
  oled.drawPixel(13 + ((frame * 9) % 102), barY + 5, SSD1306_BLACK);
  drawSpacedText("LOADING", 56, 1);

  oled.display();
}

void loading(const char *title, const char *message, uint16_t durationMs) {
  if (durationMs == 0) durationMs = 1;

  const uint32_t start = millis();
  uint8_t frame = 0;

  while (millis() - start < durationMs) {
    uint32_t percent = ((millis() - start) * 100UL) / durationMs;
    if (percent > 100) percent = 100;
    drawLoading(title, message, frame++, (uint8_t)percent);
    delay(ANIM_MS);
  }
}

void drawScreen() {
  if (screen == SCREEN_MENU) {
    drawMenu();
  } else if (screen == SCREEN_PAGE) {
    drawPage();
  } else {
    drawDisplayTest();
  }
}
