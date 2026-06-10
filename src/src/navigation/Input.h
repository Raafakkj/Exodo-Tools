#ifndef EXODO_INPUT_H
#define EXODO_INPUT_H

#include <Arduino.h>

#include "../core/Types.h"

void beginButton(Button &button, uint8_t pin);
void updateInput();
void back();

#endif
