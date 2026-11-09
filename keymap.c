#include "nedsi.h"

// Expands the userspace row macros before handing them to the keyboard layout.
#define LAYOUT_microdox(...) LAYOUT_split_3x5_3(__VA_ARGS__)

// The shared userspace dropped these when the Scylla gaming layer was
// reworked; this board keeps its gaming layer as it was, so they live here.
// GAME_Z used to tap A (a copy-paste slip); it taps Z now.
#define GAME_A LSFT_T(KC_A)
#define GAME_Z LCTL_T(KC_Z)
#define ________________GAMING_L2_________________     GAME_A,    KC_S,    KC_D,    KC_F,    KC_G
#define ________________GAMING_L3_________________     GAME_Z,    KC_X,    KC_C,    KC_V,    KC_B

// Gaming toggle on NAV, where it was before the userspace change.
#undef ________________NAV_L3________________
#define ________________NAV_L3________________      _______, _______,TG(_GAMING), _______, UNIWL

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = LAYOUT_microdox(
    ________________MAIN_L1________________,                                ________________MAIN_R1________________,
    ________________MAIN_L2________________,                                ________________MAIN_R2________________,
    ________________MAIN_L3________________,                                ________________MAIN_R3________________,
                    MO(_SYM), KC_TAB, CACCCV,                       KC_MPLY, KC_SPC, MO(_NUM)
    ),

    [_GAMING] = LAYOUT_microdox(
    ________________MAIN_L1________________,                                ________________MAIN_R1________________,
    ________________GAMING_L2_________________,                             ________________MAIN_R2________________,
    ________________GAMING_L3_________________,                             ________________MAIN_R3________________,
                      LT(_SYM, KC_ESC), KC_SPC, KC_TAB,             KC_LALT, KC_SPC, LT(_NUM, KC_ENT)
    ),

    [_SYM] = LAYOUT_microdox(
    ________________SYM_L1________________,                                ________________SYM_R1________________,
    ________________SYM_L2________________,                                ________________SYM_R2________________,
    ________________SYM_L3________________,                                ________________SYM_R3________________,
                        _______, _______, _______,                      _______, _______,MO(_NAV)
    ),

    [_ACC] = LAYOUT_microdox(
    ________________ACC_L1________________,                                ________________ACC_R1________________,
    ________________ACC_L2________________,                                ________________ACC_R2________________,
    ________________ACC_L3________________,                                ________________ACC_R3________________,
                        _______, _______, _______,                      _______, _______, _______
    ),

    [_NUM] = LAYOUT_microdox(
    ________________NUM_L1________________,                                ________________NUM_R1________________,
    ________________NUM_L2________________,                                ________________NUM_R2________________,
    ________________NUM_L3________________,                                ________________NUM_R3________________,
                       MO(_NAV), _______, _______,                      _______, _______, _______
    ),

    [_NAV] = LAYOUT_microdox(
    ________________NAV_L1________________,                                ________________NAV_R1________________,
    ________________NAV_L2________________,                                ________________NAV_R2________________,
    ________________NAV_L3________________,                                ________________NAV_R3________________,
                        _______, _______, _______,                      _______, _______, _______
    ),

    [_MISC] = LAYOUT_microdox(
    ________________MISC_L1________________,                                ________________MISC_R1________________,
    ________________MISC_L2________________,                                ________________MISC_R2________________,
    ________________MISC_L3________________,                                ________________MISC_R3________________,
                        _______, _______, _______,                      _______, _______, _______
    )
};


__attribute__ ((weak))
void matrix_init_keymap(void) {}
void matrix_init_user(void) {

  // Start in WinCompose mode.
  set_unicode_input_mode(UNICODE_MODE_WINCOMPOSE);

  matrix_init_keymap();
}


#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (clockwise) {
      tap_code16(KC_VOLD);
  } else {
      tap_code16(KC_VOLU);
  }
  return false;
}
#endif
