#include "tkissing.h"

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t temp_mod = get_mods();
    uint8_t temp_osm = get_oneshot_mods();

    uint8_t shifted = (temp_mod | temp_osm) & MOD_MASK_SHIFT;

    switch (keycode) {
        case KC_MAKE:  // Compiles the firmware, and adds the flash command based on keyboard bootloader
            if (!record->event.pressed) {

                clear_mods();
                clear_oneshot_mods();
                SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP);
                if (shifted) {
                    SEND_STRING(":bin && mv .build/*.bin .");
                }
                if ((temp_mod | temp_osm) & MOD_MASK_CTRL) {
                    SEND_STRING(" && mv .build/*.hex .");
                }
                tap_code(KC_ENT);
                set_mods(temp_mod);
            }
            break;
        case RGB_M_P:
            if (record->event.pressed) {
                if (shifted) {
                    rgb_matrix_sethsv(HSV_WHITE);
                } else {
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
                }
            }
            return false;  // Skip all further processing of this key
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
                    rgb_matrix_sethsv(HSV_MAGENTA);
                } else {
#ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
#endif
                }
            }
            return false;  // Skip all further processing of this key
    }
    return process_record_keymap(keycode, record);
}