#include "tkissing.h"

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

    void safely_sethsv(uint16_t hue, uint8_t sat, uint8_t val) {
#ifdef RGB_MATRIX_H
        rgb_matrix_sethsv(hue, sat, val);
#endif
#ifdef RGBLIGHT_ENABLE
        rgblight_sethsv(hue, sat, val);
#endif
    }

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
                    safely_sethsv(HSV_WHITE);
                } else {
#ifdef RGB_MATRIX_H
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
#endif
                }
            }
            return false;  // Skip all further processing of this key
        case RGB_M_B:
            if (record->event.pressed) {
                if (shifted) {
                    safely_sethsv(HSV_RED);
                } else {
#ifdef RGB_MATRIX_H
#    ifndef DISABLE_RGB_MATRIX_BREATHING
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
#    endif
#endif
                }
            }
            return false;  // Skip all further processing of this key
        case RGB_M_G:
            if (record->event.pressed) {
                if (shifted) {
                    safely_sethsv(HSV_GREEN);
                } else {
#ifdef RGB_MATRIX_H
#    ifndef DISABLE_RGB_MATRIX_CYCLE_ALL
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_ALL);
#    endif
#endif
                }
            }
            return false;  // Skip all further processing of this key
        case RGB_M_K:

            if (record->event.pressed) {
                if (shifted) {
                    safely_sethsv(HSV_BLUE);
                } else {
#ifdef RGB_MATRIX_H
#    ifndef DISABLE_RGB_MATRIX_BAND_VAL
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_BAND_VAL);
#    endif
#endif
                }
            }
            return false;  // Skip all further processing of this key
        case RGB_M_R:
            if (record->event.pressed) {
                if (shifted) {
                    safely_sethsv(HSV_YELLOW);
                } else {
#ifdef RGB_MATRIX_H
#    ifndef DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_LEFT_RIGHT);
#    endif
#endif
                }
            }
            return false;  // Skip all further processing of this key
        case RGB_M_SN:
            if (record->event.pressed) {
                if (shifted) {
                    safely_sethsv(HSV_PINK);
                } else {
#ifdef RGB_MATRIX_H
#    ifndef DISABLE_RGB_MATRIX_RAINDROPS
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_RAINDROPS);
#    endif
#endif
                }
            }
            return false;  // Skip all further processing of this key
        case RGB_M_SW:
            if (record->event.pressed) {
                if (shifted) {
                    safely_sethsv(HSV_PURPLE);
                } else {
#ifdef RGB_MATRIX_H
#    ifndef DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_BAND_SPIRAL_VAL);
#    endif
#endif
                }
            }
            return false;  // Skip all further processing of this key
        case RGB_M_X:
            if (record->event.pressed) {
                if (shifted) {
                    safely_sethsv(HSV_MAGENTA);
                } else {
#ifdef RGB_MATRIX_H
#    ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
#    endif
#endif
                }
            }
            return false;  // Skip all further processing of this key
    }
    return process_record_keymap(keycode, record);
}
