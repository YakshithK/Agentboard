// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    CTRL_GUI = SAFE_RANGE,
    ENC_SHIFT_TAB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ENT,        // SW1
        KC_SLSH,       // SW2
        CTRL_GUI,      // SW3
        ENC_SHIFT_TAB  // Encoder switch
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTRL_GUI:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LGUI);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
            }
            return false;

        case ENC_SHIFT_TAB:
            if (record->event.pressed) {
                tap_code16(S(KC_TAB));
            }
            return false;
    }

    return true;
}

#if defined(ENCODER_MAP_ENABLE)

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {
        ENCODER_CCW_CW(KC_UP, KC_DOWN)
    }
};

#endif

#ifdef OLED_ENABLE

bool oled_task_user(void) {
    oled_clear();

    oled_write_ln_P(PSTR("AGENTBOARD"), false);
    oled_write_ln_P(PSTR("----------"), false);

    oled_write_P(PSTR("SW1: ENTER\n"), false);
    oled_write_P(PSTR("SW2: /\n"), false);
    oled_write_P(PSTR("SW3: CTRL+WIN\n"), false);
    oled_write_P(PSTR("ENC: SHIFT+TAB"), false);

    return false;
}

#endif