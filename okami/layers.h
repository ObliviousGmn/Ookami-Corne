// Dokuu // Okami // April 2021 //

#define _BASE 0
#define _GAME 1
#define _WEAPON 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 5
#define _FCTION 6

enum layers {
  BASE = SAFE_RANGE,
  GAME,
  WEAPON,
  LOWER,
  RAISE,
  ADJUST,
  FCTION,
  PWD1,
  PWD2
};

#define SCRSHT S(G(KC_S))
#define PASTE C(KC_V)
#define COPY C(KC_C)
#define CUT C(KC_X)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define WEAPON MO(_WEAPON)
#define FCTION MO(_FCTION)
#define GAME TG(_GAME)

// Adjust Layer?
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
