#pragma once

typedef struct _adaptive_2key {
    uint16_t key1;
    uint16_t key2;
    const char *output;
} adaptive_2key_t;

typedef struct _adaptive_3key {
    uint16_t key1;
    uint16_t key2;
    uint16_t key3;
    const char *output;
} adaptive_3key_t;

bool process_adaptive_key(uint16_t keycode);
