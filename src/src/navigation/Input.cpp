#include "Input.h"

#include "../core/AppState.h"
#include "../core/Config.h"
#include "MenuRegistry.h"

void beginButton(Button &button, uint8_t pin) {
  button.pin = pin;
  pinMode(pin, INPUT_PULLUP);
  button.stable = button.last = digitalRead(pin);
  button.changedAt = millis();
}

static void readButton(Button &button) {
  const bool reading = digitalRead(button.pin);

  if (reading != button.last) {
    button.last = reading;
    button.changedAt = millis();
  }

  if (millis() - button.changedAt > DEBOUNCE_MS && reading != button.stable) {
    button.stable = reading;
    button.click = (reading == LOW);
  }
}

static bool takeClick(Button &button) {
  if (!button.click) return false;
  button.click = false;
  return true;
}

void back() {
  activeMenu = stackSize ? menuStack[--stackSize] : &mainMenu;
  selected = 0;
  screen = SCREEN_MENU;
  dirty = true;
}

static void openSelectedItem() {
  const Item &item = activeMenu->items[selected];

  if (item.submenu) {
    if (stackSize < STACK_MAX) menuStack[stackSize++] = activeMenu;
    activeMenu = item.submenu;
    selected = 0;
    dirty = true;
  } else if (item.action) {
    item.action();
  }
}

void updateInput() {
  readButton(leftBtn);
  readButton(okBtn);
  readButton(rightBtn);

  if (screen != SCREEN_MENU) {
    if (takeClick(okBtn)) {
      screen = SCREEN_MENU;
      dirty = true;
    }
    takeClick(leftBtn);
    takeClick(rightBtn);
    return;
  }

  if (takeClick(leftBtn)) {
    selected = selected ? selected - 1 : activeMenu->count - 1;
    dirty = true;
  }

  if (takeClick(rightBtn)) {
    selected = (selected + 1) % activeMenu->count;
    dirty = true;
  }

  if (takeClick(okBtn)) {
    openSelectedItem();
  }
}
