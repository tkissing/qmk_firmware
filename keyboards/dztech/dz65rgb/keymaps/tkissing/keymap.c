#include QMK_KEYBOARD_H
#include "rgblight_list.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_65_ansi(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_DEL,
                        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_VOLU,
                        KC_GESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_VOLD,
                        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_MUTE,
                        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(1), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
	[1] = LAYOUT_65_ansi(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_HOME,
                        KC_TAB, RGB_TOG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP,
                        KC_GESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_TRNS, KC_ENT, KC_PGDN,
                        KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RSFT, KC_PSCR, KC_END,
                        KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, MO(2), KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT
    ),
	[2] = LAYOUT_65_ansi(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_HOME,
                        KC_TAB, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, KC_PGUP,
                        KC_GESC, RGB_SPI, RGB_SPD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, EEP_RST, KC_PGDN,
                        KC_LSFT, RGB_M_P, RGB_M_X, RGB_M_SW, RGB_M_SN, RGB_M_B, RGB_M_G, RGB_M_K, RGB_M_R, KC_TRNS, KC_TRNS, KC_RSFT, KC_UP, KC_END,
                        KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT
    )
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t shifted = get_mods() & (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT));
    switch (keycode) {
        case RGB_M_B:
            if (record->event.pressed) {
                if (shifted) {
                    rgb_matrix_sethsv(HSV_RED);
                } else {
#ifndef DISABLE_RGB_MATRIX_BREATHING
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
#endif
                }
            }
            return false;  // Skip all further processing of this key
        case RGB_M_G:
            if (record->event.pressed) {
                if (shifted) {
                    rgb_matrix_sethsv(HSV_GREEN);
                } else {
#ifndef DISABLE_RGB_MATRIX_CYCLE_ALL
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_ALL);
#endif
                }
            }
            return false;  // Skip all further processing of this key
        case RGB_M_K:

            if (record->event.pressed) {
                if (shifted) {
                    rgb_matrix_sethsv(HSV_BLUE);
                } else {
#ifndef DISABLE_RGB_MATRIX_BAND_VAL
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_BAND_VAL);
#endif
                }
            }
            return false;  // Skip all further processing of this key
        case RGB_M_R:
            if (record->event.pressed) {
                if (shifted) {
                    rgb_matrix_sethsv(HSV_YELLOW);
                } else {
#ifndef DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_LEFT_RIGHT);
#endif
                }
            }
            return false;  // Skip all further processing of this key
        case RGB_M_SN:
            if (record->event.pressed) {
                if (shifted) {
                    rgb_matrix_sethsv(HSV_PINK);
                } else {
#ifndef DISABLE_RGB_MATRIX_RAINDROPS
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_RAINDROPS);
#endif
                }
            }
            return false;  // Skip all further processing of this key
        case RGB_M_SW:
            if (record->event.pressed) {
                if (shifted) {
                    rgb_matrix_sethsv(HSV_PURPLE);
                } else {
#ifndef DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_BAND_SPIRAL_VAL);
#endif
                }
            }
            return false;  // Skip all further processing of this key
        case RGB_M_X:
            if (record->event.pressed) {
                if (shifted) {
                    rgb_matrix_sethsv(HSV_WHITE);
                } else {
#ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
#endif
                }
            }
            return false;  // Skip all further processing of this key
        default:
            return true;  // Process all other keycodes normally
    }
}
