#include "SettingsActions.h"

#include <Arduino.h>

#include "../core/AppState.h"
#include "../ui/Ui.h"

void status() {
  snprintf(textA, sizeof(textA), "Heap %lu KB", (unsigned long)(ESP.getFreeHeap() / 1024));
  snprintf(textB, sizeof(textB), "Up %lu sec", (unsigned long)(millis() / 1000));
  page("STATUS", textA, textB);
}

void about() {
  page("ABOUT", "ESP32 TOOLS", "Version 0.9.1");
}

void displayTest() {
  showDisplayTest();
}
