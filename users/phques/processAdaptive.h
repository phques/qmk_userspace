#pragma once

typedef struct _adaptive_key {
    uint16_t key1;
    uint16_t key2;
    uint16_t key3;
    const char *output;
} adaptive_key_t;

bool process_adaptive_key(uint16_t keycode);
