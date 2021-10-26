// Dokuu // Okami // April 2021

#pragma once

#undef PRODUCT
#define PRODUCT Okami

#define EE_HANDS

#define USE_SERIAL_PD2
#define TAPPING_TERM 170
#define IGNORE_MOD_TAP_INTERRUPT
#define LAYER_STATE_8BIT // 8-layer limit, saves ~462 bytes
#define OLED_TIMEOUT 200000
#define OLED_FONT_H "keyboards/crkbd/keymaps/okami/glcdfont.c"

/* RGB Settings */
#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    #define RGBLED_NUM 6
    #define RGBLIGHT_SLEEP
    #define RGBLIGHT_SPLIT
    #define RGBLIGHT_LIMIT_VAL 255
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
    #define RGBLIGHT_DEFAULT_HUE 43
    // #define RGBLIGHT_ANIMATIONS
    // #define RGBLIGHT_EFFECT_BREATHING
   //  #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_TWINKLE
#endif
