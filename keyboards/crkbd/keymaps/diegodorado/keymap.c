/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

// opening marks
#define KK_OQUES   ALGR(KC_SLASH)
#define KK_OEXLM   ALGR(KC_EXLM)
#define XXXX XXXXXXX

#undef LAYOUT
#define LAYOUT( \
  L00, L01, L02, L03, L04,           R00, R01, R02, R03, R04, \
  L10, L11, L12, L13, L14,           R10, R11, R12, R13, R14, \
  L20, L21, L22, L23, L24,           R20, R21, R22, R23, R24, \
                      L30, L31, R30, R31 \
  ) \
  { \
    { KC_NO, L00, L01, L02, L03, L04 }, \
    { KC_NO, L10, L11, L12, L13, L14 }, \
    { KC_NO, L20, L21, L22, L23, L24 }, \
    { KC_NO, KC_NO, KC_NO, XXXX, L30, L31 }, \
    { KC_NO, R04, R03, R02, R01, R00 }, \
    { KC_NO, R14, R13, R12, R11, R10 }, \
    { KC_NO, R24, R23, R22, R21, R20 }, \
    { KC_NO, KC_NO, KC_NO, XXXX, R31, R30 } \
  }

enum custom_keycodes {
    SPC_OR_ENT = SAFE_RANGE,
    KL_SFT,
};

enum crkbd_layers {
  L_LOW,
  L_UPP,
  L_SYM,
  L_NUM,
  L_MOD,
  L_MED
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_LOW] = LAYOUT(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
                                  MO(L_MOD), LT(L_UPP,KC_ESC),      MT(MOD_LCTL, KC_SPC) , MO(L_SYM)
                                //`--------------------------'  `--------------------------'
  ),
  [L_UPP] = LAYOUT(
  //,--------------------------------------------.                    ,--------------------------------------------.
      S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T),                      S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P), 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G),                      S(KC_H), S(KC_J), S(KC_K), S(KC_L), S(KC_SCLN), 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B),                      S(KC_N), S(KC_M),S(KC_COMM),S(KC_DOT),S(KC_SLSH),
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
                                          XXXX, XXXX,               MT(MOD_LCTL, KC_ENT), MO(L_NUM)
                                //`--------------------------'  `--------------------------'
  ),
  [L_SYM] = LAYOUT(
  //,--------------------------------------------.                    ,--------------------------------------------.
     KC_GRAVE,   KC_AT, KC_HASH, KC_CIRC,KC_PERC,                          XXXX,  KC_DLR, KC_AMPR, KC_PIPE, KC_BSLS,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KC_SLASH, KC_ASTR, KC_PLUS, KC_MINS, KC_EQL,                          XXXX, KC_DQUO, KC_LPRN, KC_LBRC, KC_LCBR,  
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_TILD,    XXXX,    XXXX, KC_UNDS, KC_EXLM,                         XXXX, KC_QUOT, KC_RPRN, KC_RBRC, KC_RCBR,  
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
                                  XXXX, XXXX,                               XXXX, MO(L_NUM)
                                //`--------------------------'  `--------------------------'
  ),
  [L_NUM] = LAYOUT(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                         XXXX   , XXXX,    XXXX,    XXXX,   XXXX, 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_6,    KC_4,    KC_0,    KC_2,    XXXX,                         XXXX , KC_3,    KC_1,    KC_5,    KC_7, 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXX,    XXXX,    XXXX,    KC_8,    XXXX,                         XXXX, KC_9,    XXXX,    XXXX,    XXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
                                  XXXX, XXXX,                               XXXX, XXXX
                                //`--------------------------'  `--------------------------'
  ),
  [L_MOD] = LAYOUT(
  //,--------------------------------------------.                    ,--------------------------------------------.
     KC_MUTE, KC_VOLD, KC_VOLU,   XXXX,    XXXX,                         XXXX  ,   XXXX ,   KC_UP,  XXXX  ,  XXXX  , 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
OSM(MOD_LGUI),OSM(MOD_LALT),XXXX,KC_BSPC, CW_TOGG,                       XXXX  , KC_LEFT, KC_DOWN,  KC_RGHT, XXXX  , 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXX,  OSM(MOD_RALT),XXXX,  KC_DEL, XXXX,                        XXXX  , KC_HOME, KC_PGUP, KC_PGDN, KC_END, 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
                                  XXXX, XXXX,                               XXXX, XXXX
                             //`--------------------------'  `--------------------------'
  ),
  [L_MED] = LAYOUT(
  //,-------------------------------------------- .                    ,--------------------------------------------.
      XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                        RGB_TOG , RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                          XXXX , KC_MPRV , KC_VOLD, KC_VOLU, KC_MNXT, 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                          XXXX,    XXXX,    XXXX,    XXXX,    XXXX,  
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
                                  XXXX, XXXX,                               XXXX, XXXX
                             //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    // switch (layer_state) {
    switch (get_highest_layer(layer_state)) {
        case L_LOW:
            oled_write_ln_P(PSTR("LOW"), false);
            break;
        case L_UPP:
            oled_write_ln_P(PSTR("UPP"), false);
            break;
        case L_NUM:
            oled_write_ln_P(PSTR("NUM"), false);
            break;
        case L_SYM:
            oled_write_ln_P(PSTR("SYM"), false);
            break;
        case L_MOD:
            oled_write_ln_P(PSTR("MOD"), false);
            break;
        case L_MED:
            oled_write_ln_P(PSTR("MED"), false);
            break;
        default:
            oled_write_ln_P(PSTR("OTH"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
   oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

static struct {
    bool active;
    uint8_t code;
    uint8_t tap;
    uint8_t mods;
    bool left;
} bilateral_combinations = { false };

void bilateral_combinations_hold(uint8_t code, uint8_t tap, uint8_t mods, keypos_t key) {
    bilateral_combinations.active = true;
    bilateral_combinations.code = code;
    bilateral_combinations.tap = tap;
    bilateral_combinations.mods = mods;
    bilateral_combinations.left = key.row < MATRIX_ROWS / 2;
}

void bilateral_combinations_release(uint8_t code) {
    if (bilateral_combinations.active && (code == bilateral_combinations.code)) {
        bilateral_combinations.active = false;
    }
}

void bilateral_combinations_tap(keypos_t key) {
    if (bilateral_combinations.active) {
        if (key.row < MATRIX_ROWS / 2) {
            unregister_mods(bilateral_combinations.mods);
            tap_code(bilateral_combinations.tap);
            bilateral_combinations.active = false;
        }
    }
}


#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }

  switch (keycode) {
      case SPC_OR_ENT:
          if (record->event.pressed) {
              if (get_mods() & MOD_MASK_SHIFT) {
                  // Shift is held, send Enter
                  SEND_STRING(SS_TAP(X_ENTER));
              } else {
                  // Shift is not held, send Space
                  SEND_STRING(SS_TAP(X_SPACE));
              }
          }
          break;

      case KL_SFT:
          if (record->event.pressed) {
              layer_off(L_SYM);
              layer_on(L_NUM);
          } else {
              layer_off(L_NUM);
              layer_on(L_SYM);
          }
          return false;
          break;
  }

  return true;
}

