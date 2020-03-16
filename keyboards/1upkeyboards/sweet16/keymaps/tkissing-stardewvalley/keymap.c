#include QMK_KEYBOARD_H

enum my_layers { _LAYER_BASE = 0, _LAYER_FN, _LAYER_QMK };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LAYER_BASE] = LAYOUT_ortho_4x4(
        KC_1,    KC_2, KC_3, TT(_LAYER_FN),
        KC_4,    KC_5, KC_6, KC_TAB,
        KC_LSFT, KC_W, KC_C, KC_ESC,
        KC_A,    KC_S, KC_D, KC_X
    ),
    [_LAYER_FN] = LAYOUT_ortho_4x4(
        KC_7,    KC_8,    KC_9,       KC_TRNS,
        KC_0,    KC_MINS, KC_EQL,     TT(_LAYER_QMK),
        KC_LALT, KC_MS_U, KC_MS_BTN1, KC_Y,
        KC_MS_L, KC_MS_D, KC_MS_R,    KC_MS_BTN2
    ),
    [_LAYER_QMK] = LAYOUT_ortho_4x4(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        RESET,  KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};
