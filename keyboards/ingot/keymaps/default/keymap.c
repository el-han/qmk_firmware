/* Copyright 2020 Vinam Arora <vinam@posteo.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keymap_german.h"

enum blackwing_layers
{
    _L1,
    _L3,
    _L4,
    // _MO,
    _Q1,
    _Q4
};

#define KC_MU ALGR(DE_M)

enum custom_keycodes {
        SLS_BSL = SAFE_RANGE,
        C_SHIFT
};

bool isShiftPressed = false;
bool lockShift = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * .-----------------------------------------------------.-----------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * | TAB    | -      | ,      | .      | P      | Y      | F      | G      | C      | T      | Z      | ¨      |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * | L3     | A      | O      | E      | I      | U      | H      | D      | R      | N      | S      | L3     |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * | L2     | /      | Q      | J      | K      | X      | B      | M      | W      | V      | L      | L2     |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | CTRL   | META   | ALT    |                   SPACE                             | L4     | META   | CTRL   |
 * '--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
 */

[_L1] = LAYOUT(
  KC_ESC,            KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,             KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, _______, _______, XXXXXXX,
  KC_ESC,            DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,              KC_BSPC, KC_BSPC, KC_BSPC, KC_INS,  KC_HOME, KC_PGUP, _______, _______, _______, _______, XXXXXXX,
  KC_TAB,            DE_MINS, DE_COMM, DE_DOT,  DE_P,    DE_Y,    DE_F,    DE_G,    DE_C,    DE_T,    DE_Z,              KC_LEAD, KC_LEAD, KC_ENT,  KC_DEL,  KC_END,  KC_PGDN, _______, _______, _______, _______, XXXXXXX,
  MO(_L3),           DE_A,    DE_O,    DE_E,    DE_I,    DE_U,    DE_H,    DE_D,    DE_R,    DE_N,    DE_S,              MO(_L3), MO(_L3), KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX,
  C_SHIFT,           SLS_BSL, DE_Q,    DE_J,    DE_K,    DE_X,    DE_B,    DE_M,    DE_W,    DE_V,    DE_L,              C_SHIFT, KC_UP,   KC_DEL,  XXXXXXX, KC_UP,   XXXXXXX, _______, _______, _______, _______, XXXXXXX,
  LM(_Q1, MOD_LCTL), KC_LGUI, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX, XXXXXXX, MO(_L4), LM(_Q1, MOD_LCTL), KC_LEFT, KC_DOWN, KC_RGHT, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, XXXXXXX
),

/*
 * .-----------------------------------------------------.-----------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * |        | _      | ;      | [      | ]      | *      | +      | <      | >      | =      | $      |        |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * |        | @      | €      | {      | }      | !      | ?      | (      | )      | -      | ß      |        |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * |        | |      | ^      | ´      | ~      | `      | &      | µ      | "      | '      | #      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        | 0      |        |        |        |
 * '--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
 */

[_L3] = LAYOUT(
  _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,
  _______,           XXXXXXX, DE_SUP2, DE_SUP3, DE_PIPE, XXXXXXX, XXXXXXX, DE_LCBR, DE_LBRC, DE_RBRC, DE_RCBR,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,
  _______,           DE_UNDS, DE_SCLN, DE_LBRC, DE_RBRC, DE_ASTR, DE_PLUS, DE_LABK, DE_RABK, DE_EQL,  DE_DLR,            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,
  _______,           DE_AT,   DE_EURO, DE_LCBR, DE_RCBR, DE_EXLM, DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_SS,             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,
  _______,           DE_PIPE, DE_CIRC, DE_ACUT, DE_TILD, DE_GRV,  DE_AMPR, KC_MU,   DE_DQUO, DE_QUOT, DE_HASH,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,
  _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX
),

/*
 * .-----------------------------------------------------.-----------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * |        | PGUP   | BACKSP | UP     | DEL    | PGDOWN | -      | 7      | 8      | 9      | +      |        |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * |        | HOME   | LEFT   | DOWN   | RIGHT  | END    | /      | 3      | 5      | 6      | *      |        |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * |        | MUTE   | VOLDN  | VOLUP  | ENTER  | WHOME  | =      | 1      | 2      | 3      | %      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        | 0      |        |        |        |
 * '--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
 */

[_L4] = LAYOUT(
  _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,
  KC_F1,             KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,            KC_F12 , _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,
  _______,           KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN, KC_PMNS, KC_7,    KC_8,    KC_9,    KC_PPLS,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,
  _______,           KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_PSLS, KC_4,    KC_5,    KC_6,    KC_PAST,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,
  _______,           KC_MUTE, KC_VOLD, KC_VOLU, KC_ENT,  KC_WHOM, KC_PEQL, KC_1,    KC_2,    KC_3,    DE_PERC,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,
  _______,           _______, _______, _______, _______, _______, KC_0,    _______, _______, _______, DF(_Q1),           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX
),

// [_MO] = {
//     {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
//     {_______, _______, KC_BTN1, KC_MS_U, KC_BTN1, KC_WH_U, _______, _______, _______, _______, _______, _______, _______, _______},
//     {_______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, _______, _______, _______, _______, _______, _______, _______},
//     {_______, _______, _______, _______, _______, KC_BTN3, _______, _______, _______, _______, _______, _______, _______, _______},
//     {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
// },

/* QWERTY
 * .-----------------------------------------------------.-----------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | ß      |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * | +      | Q      | W      | E      | R      | T      | Z      | U      | I      | O      | P      | Ü      |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * | #      | A      | S      | D      | F      | G      | J      | H      | K      | L      | Ö      | Ä      |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * | SHIFT  | Y      | X      | C      | V      | B      | N      | M      | ,      | .      | -      | SHIFT  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | CTRL   | META   | ALT    | BSPACE | SPACE  | SHIFT  | SHIFT  | SPACE  | DEL    | ALTGR  | META   | CTRL   |
 * '--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
 */

[_Q1] = LAYOUT(
  KC_ESC,            KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,             KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, _______, _______, XXXXXXX,
  KC_GRV,            KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,              KC_MINS, KC_EQL,  KC_BSPC, KC_INS,  KC_HOME, KC_PGUP, _______, _______, _______, _______, XXXXXXX,
  KC_TAB,            KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,              KC_LBRC, KC_RBRC, KC_NUBS, KC_DEL,  KC_END,  KC_PGDN, _______, _______, _______, _______, XXXXXXX,
  KC_RALT,           KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,           KC_QUOT, KC_NUHS, KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX,
  KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,           KC_RSFT, KC_UP,   KC_DEL,  XXXXXXX, KC_UP,   XXXXXXX, _______, _______, _______, _______, XXXXXXX,
  KC_LCTL,           KC_LGUI, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX, XXXXXXX, MO(_Q4), KC_RCTL,           KC_LEFT, KC_DOWN, KC_RGHT, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, XXXXXXX
),

/*
 * .-----------------------------------------------------.-----------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * |        | PGUP   | BACKSP | UP     | DEL    | PGDOWN | -      | 7      | 8      | 9      | +      |        |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * |        | HOME   | LEFT   | DOWN   | RIGHT  | END    | /      | 3      | 5      | 6      | *      |        |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * |        | MUTE   | VOLDN  | VOLUP  | ENTER  | WHOME  | =      | 1      | 2      | 3      | %      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        | 0      |        |        |        |
 * '--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
 */

[_Q4] = LAYOUT(
  _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,
  KC_F1,             KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,            KC_F12 , _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,
  _______,           KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN, KC_PMNS, KC_7,    KC_8,    KC_9,    KC_PPLS,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,
  _______,           KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_PSLS, KC_4,    KC_5,    KC_6,    KC_PAST,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,
  _______,           KC_MUTE, KC_VOLD, KC_VOLU, KC_ENT,  KC_WHOM, KC_PEQL, KC_1,    KC_2,    KC_3,    DE_PERC,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,
  _______,           _______, _______, _______, _______, _______, KC_0,    _______, _______, _______, DF(_L1),           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX
),

/* blank key layout template
 * .-----------------------------------------------------.                  .-----------------------------------------------------.
 * |        |        |        |        |        |        |                  |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |                  |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |                  |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |                  |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------..--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        ||        |        |        |        |        |        |        |
 * '--------+--------+--------+--------+--------+--------+--------''--------+--------+--------+--------+--------+--------+--------'
 */

};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    static bool wasShifted = false;

    switch (keycode) {
        // dynamically generate these.
        case SLS_BSL:
            if (record->event.pressed) {
                lockShift = true;
                if (isShiftPressed) {
                    wasShifted = true;
                    SEND_STRING(SS_UP(X_LSHIFT)SS_DOWN(X_RALT)SS_DOWN(X_MINUS));
                } else {
                    wasShifted = false;
                    SEND_STRING(SS_DOWN(X_LSHIFT)SS_DOWN(X_7));
                }
            } else {
                if (wasShifted) {
                    SEND_STRING(SS_UP(X_MINUS)SS_UP(X_RALT));
                    if (isShiftPressed)
                        SEND_STRING(SS_DOWN(X_LSHIFT));
                    lockShift = false;
                } else {
                    SEND_STRING(SS_UP(X_7));
                    if (!isShiftPressed)
                        SEND_STRING(SS_UP(X_LSHIFT));
                    lockShift = false;
                }
            }
            return false;
            break;
        case C_SHIFT:
            if (record->event.pressed) {
                if (!lockShift)
                    SEND_STRING(SS_DOWN(X_LSHIFT));
                isShiftPressed = true;
            } else {
                if (!lockShift)
                    SEND_STRING(SS_UP(X_LSHIFT));
                isShiftPressed = false;
            }
            return false;
            break;
    }
    return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void)
{
    LEADER_DICTIONARY() {

        leading = false;
        leader_end();

        SEQ_ONE_KEY(DE_A) {
            register_code(DE_ADIA);
            unregister_code(DE_ADIA);
        }

        SEQ_ONE_KEY(DE_O) {
            register_code(DE_ODIA);
            unregister_code(DE_ODIA);
        }

        SEQ_ONE_KEY(DE_U) {
            register_code(DE_UDIA);
            unregister_code(DE_UDIA);
        }

        SEQ_ONE_KEY(DE_P) {
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(DE_P);
            unregister_code(DE_P);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
        }
    }
};

