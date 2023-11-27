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

// home rows
#define KK_A     GUI_T(KC_A)
#define KK_S     ALT_T(KC_S)
#define KK_D     CTL_T(KC_D)
#define KK_F     SFT_T(KC_F)
#define KK_J     SFT_T(KC_J)
#define KK_K     CTL_T(KC_K)
#define KK_L     ALT_T(KC_L)
#define KK_SCLN  GUI_T(KC_SCLN)

// below home alt gr
#define KK_X     RALT_T(KC_X)
#define KK_DOT   RALT_T(KC_DOT)

// opening marks
#define KK_OQUES   ALGR(KC_SLASH)
#define KK_OEXLM   ALGR(KC_EXLM)

enum crkbd_layers {
  L_BASE,
  L_NUM,
  L_SYM,
  L_NAV_FN,
  L_MOUSE,
  L_MEDIA,
  L_MIDI
};

#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

#define XXXX XXXXXXX


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KK_A,    KK_S,    KK_D,    KK_F,    KC_G,                         KC_H,    KK_J,    KK_K,    KK_L, KK_SCLN, 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_Z,    KK_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KK_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
  LT(L_MEDIA,KC_DEL), LT(L_NUM,KC_BACKSPACE), LT(L_MOUSE,KC_ESC),  LT(L_NAV_FN,KC_ENT), LT(L_SYM,KC_SPACE), LT(L_MIDI,KC_TAB)
                                    //`--------------------------'  `--------------------------'
  ),
  [L_NUM] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                         KC_ASTR, KC_7,    KC_8,    KC_9,   KC_EQUAL, 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXX,                         KC_MINS, KC_4,    KC_5,    KC_6,    KC_COLN, 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                         KC_PLUS, KC_1,    KC_2,    KC_3,    KC_SLSH,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
                                      XXXX,XXXX,XXXX,           KC_ENT, KC_0, KC_DOT
                             //`--------------------------'  `--------------------------'
  ),
  [L_SYM] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXX,   KC_AT,    KC_CIRC, KC_AMPR,KC_GRAVE,                     KC_UNDS, KC_PIPE,   KC_DLR, KC_PERC, KC_TILD, 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LABK, KC_LBRC, KC_LCBR, KC_LPRN, KC_QUOT,                      KC_DQUO, KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK, 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KK_OQUES,KK_OEXLM,  XXXX  ,  XXXX  , XXXX   ,                     XXXX,    CW_TOGG,  KC_HASH, KC_EXLM, KC_QUES,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
                                      XXXX,XXXX,XXXX,           XXXX,XXXX,XXXX
                             //`--------------------------'  `--------------------------'
  ),
  [L_NAV_FN] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_F1,   KC_F2,    KC_F3,   KC_F4,    XXXX,                        XXXX  ,   XXXX ,  XXXX  ,  XXXX  ,  XXXX  , 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_F5,   KC_F6,    KC_F7,   KC_F8,    XXXX,                        XXXX  , KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_F9,  KC_F10,   KC_F11,  KC_F12,    XXXX,                        XXXX  , KC_HOME, KC_PGUP, KC_PGDN, KC_END, 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
                                      XXXX,XXXX,XXXX,           XXXX,XXXX,XXXX
                             //`--------------------------'  `--------------------------'
  ),
  [L_MOUSE] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                          XXXX  ,   XXXX ,  XXXX  ,  XXXX  ,  XXXX  , 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXX,    XXXX,    KC_ACL0, KC_ACL1, KC_ACL2,                     KC_APP,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                        XXXX  ,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
                                      XXXX,XXXX,XXXX,           KC_BTN2,KC_BTN1,KC_BTN3
                             //`--------------------------'  `--------------------------'
  ),
  [L_MEDIA] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                        RGB_TOG , RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                          XXXX , KC_MPRV , KC_VOLD, KC_VOLU, KC_MNXT, 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                          XXXX,    XXXX,    XXXX,    XXXX,    XXXX,  
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
                                      XXXX,XXXX,XXXX,           KC_MSTP,KC_MPLY,KC_MUTE
                             //`--------------------------'  `--------------------------'
  ),
  [L_MIDI] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      MI_Cs,   MI_Ds,    XXXX,   MI_Fs,    MI_Gs,                       MI_As  ,   XXXX ,  MI_Cs ,  MI_Ds ,  XXXX  , 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      MI_C,    MI_D,    MI_E,    MI_F,    MI_G,                          MI_A  ,   MI_B ,  MI_C  ,  MI_D  ,  MI_E  , 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      MI_OCTD, MI_OCTU,    XXXX,    XXXX,    XXXX,                      XXXX  ,   XXXX ,  XXXX  ,  XXXX  ,  XXXX  , 
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
                                      XXXX,XXXX,XXXX,           XXXX,XXXX,XXXX
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
        case L_BASE:
            oled_write_ln_P(PSTR("BASE"), false);
            break;
        case L_NUM:
            oled_write_ln_P(PSTR("NUM"), false);
            break;
        case L_SYM:
            oled_write_ln_P(PSTR("SYM"), false);
            break;
        case L_NAV_FN:
            oled_write_ln_P(PSTR("NAV_FN"), false);
            break;
        case L_MEDIA:
            oled_write_ln_P(PSTR("MEDIA"), false);
            break;
        case L_MIDI:
            oled_write_ln_P(PSTR("MIDI"), false);
            break;
        case L_MOUSE:
            oled_write_ln_P(PSTR("MOUSE"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Other"), false);
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


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }

  switch (keycode) {
    case KK_A:
      break;
    case KK_S:
      break;
    case KK_D:
      break;
    case KK_F:
      break;
    case KK_J:
      break;
    case KK_K:
      break;
    case KK_L:
      break;
    case KK_SCLN:
      break;
  }

  return true;
}
#endif // OLED_ENABLE
