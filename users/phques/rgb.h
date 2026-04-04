#pragma once

#include "action_layer.h"

extern bool rgb_set_indicators(layer_state_t state);
extern void rgb_set_background(void);
extern void rgb_set_suspend(bool is_suspended);
extern void rgb_refresh(void);