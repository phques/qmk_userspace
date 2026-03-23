#pragma once

#include "action.h"

int8_t keyOverrideIndex(uint16_t keycode);
bool process_keyOverride(uint16_t keycode, keyrecord_t *record);
