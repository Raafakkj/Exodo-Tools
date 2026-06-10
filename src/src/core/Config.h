#ifndef EXODO_CONFIG_H
#define EXODO_CONFIG_H

#include <Arduino.h>

#ifndef ESP32
  #error "This firmware was made for ESP32 only."
#endif

constexpr uint8_t W = 128;
constexpr uint8_t H = 64;       // Use 32 if your OLED is 128x32.
constexpr uint8_t OLED = 0x3C;  // Try 0x3D if the display does not start.
constexpr int8_t OLED_RST = -1;

constexpr uint8_t SDA_PIN = 21;
constexpr uint8_t SCL_PIN = 22;
constexpr uint8_t BTN_LEFT = 32;
constexpr uint8_t BTN_OK = 33;
constexpr uint8_t BTN_RIGHT = 25;

constexpr uint8_t STACK_MAX = 4;
constexpr uint16_t DEBOUNCE_MS = 35;
constexpr uint16_t CLOCK_MS = 1000;
constexpr uint16_t ANIM_MS = 90;

#define COUNT_ITEMS(x) (sizeof(x) / sizeof((x)[0]))

#endif
