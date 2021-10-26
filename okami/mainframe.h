// Dokuu // Okami // April 2021

//#include "kitten.c"
// For cat set rotation to 0
#include "punk.c"
// For punk set rotation to 270
//#include "bongo.c"
// For bongo set rotation to 180
// #include "minimap.c"

extern keymap_config_t keymap_config;
static uint32_t oled_timer = 0;

/* Oled Shutoff after PC Down */
void suspend_power_down_user(void) {
    oled_off();
}

/* Idle Switch */
void matrix_scan_user(void) {
     if (timer_elapsed32(oled_timer) > 300000 && timer_elapsed32(oled_timer) < 499999 ) {
     if (get_highest_layer(layer_state) == _GAME) {
          layer_off(_GAME);
          layer_on(_BASE);
       }
         return;
    }
}

/* Rotations */
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_0;
  }
    else {
    return OLED_ROTATION_270;
  }
}

/* Left Oled */
void render_left(void) {
  switch (get_highest_layer(layer_state)){
          case _GAME:
             render_space();
             render_layer_state();
             render_separator();
             render_brand();
              break;
          case _WEAPON:
             render_space();
             render_layer_state();
             render_separator();
             render_w();
              break;
          default:
              render_space();
              render_layer_state();
              render_separator();
              render_brand();
      }
}

/* Right Oled */
static void render_right(void) {
       render_anim();
       //print_matrix();
}

/* Establishing Sides */
void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_left();
    } else {
        render_right();
    }
}

/* Macros */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
switch (keycode) {
   case PWD1:
    if (record->event.pressed) {
      SEND_STRING("---");
    } else {
    }
    return false;
   case PWD2:
    if (record->event.pressed) {
      SEND_STRING("-----");
    } else {
    }
    break;
 }
 return true;
}
