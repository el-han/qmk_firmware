#include "blackwing.h"
#include "keymap_german.h"

enum blackwing_layers
{
    _L1,
    _L3,
    _L4,
    _MO,
    _Q1,
    _Q4
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_MU ALGR(DE_M)

enum custom_keycodes {
        SLS_BSL = SAFE_RANGE,
        C_SHIFT
};

bool isShiftPressed = false;
bool lockShift = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * .-----------------------------------------------------.                  .-----------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      |                  | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * | TAB    | -      | ,      | .      | P      | Y      |                  | F      | G      | C      | T      | Z      | ¨      |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * | L3     | A      | O      | E      | I      | U      |                  | H      | D      | R      | N      | S      | L3     |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * | L2     | /      | Q      | J      | K      | X      |                  | B      | M      | W      | V      | L      | L2     |
 * |--------+--------+--------+--------+--------+--------+--------..--------+--------+--------+--------+--------+--------+--------|
 * | CTRL   | META   | ALT    | L3     | L2     | SPACE  | TAB    || ENTER  | SPACE  | L2     | L3     | L4     | META   | CTRL   |
 * '--------+--------+--------+--------+--------+--------+--------''--------+--------+--------+--------+--------+--------+--------'
 */

[_L1] = {
    {KC_ESC,  DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    XXXXXXX, XXXXXXX, DE_6,    DE_7,    DE_8,    DE_9,    DE_0,     KC_BSPC},
    {KC_TAB,  DE_MINS, DE_COMM, DE_DOT,  DE_P,    DE_Y,    XXXXXXX, XXXXXXX, DE_F,    DE_G,    DE_C,    DE_T,    DE_Z,     KC_LEAD},
    {MO(_L3), DE_A,    DE_O,    DE_E,    DE_I,    DE_U,    XXXXXXX, XXXXXXX, DE_H,    DE_D,    DE_R,    DE_N,    DE_S,     MO(_L3)},
    {C_SHIFT, SLS_BSL, DE_Q,    DE_J,    DE_K,    DE_X,    XXXXXXX, XXXXXXX, DE_B,    DE_M,    DE_W,    DE_V,    DE_L,     C_SHIFT},
    {LM(_Q1, MOD_LCTL), KC_LGUI, KC_LALT, MO(_L3), KC_SPC,  C_SHIFT, KC_TAB,  KC_ENT,  C_SHIFT, KC_SPC,  MO(_L3), MO(_L4), KC_RGUI,  LM(_Q1, MOD_LCTL)}
},

/*
 * .-----------------------------------------------------.                  .-----------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      |                  | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * |        | _      | ;      | [      | ]      | *      |                  | +      | <      | >      | =      | $      |        |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * |        | @      | €      | {      | }      | !      |                  | ?      | (      | )      | -      | ß      |        |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * |        | |      | ^      | ´      | ~      | `      |                  | &      | µ      | "      | '      | #      |        |
 * |--------+--------+--------+--------+--------+--------+--------..--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        ||        |        |        | 0      |        |        |        |
 * '--------+--------+--------+--------+--------+--------+--------''--------+--------+--------+--------+--------+--------+--------'
 */

[_L3] = {
    {_______, XXXXXXX, DE_SQ2,  DE_SQ3,  DE_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DE_LCBR, DE_LBRC, DE_RBRC, DE_RCBR, _______},
    {_______, DE_UNDS, DE_SCLN, DE_LBRC, DE_RBRC, DE_ASTR, XXXXXXX, XXXXXXX, DE_PLUS, DE_LESS, DE_MORE, DE_EQL,  DE_DLR,  _______},
    {_______, DE_AT,   DE_EURO, DE_LCBR, DE_RCBR, DE_EXLM, XXXXXXX, XXXXXXX, DE_QST,  DE_LPRN, DE_RPRN, DE_MINS, DE_SS,   _______},
    {_______, DE_PIPE, DE_CIRC, DE_ACUT, DE_TILD, DE_GRV,  XXXXXXX, XXXXXXX, DE_AMPR, KC_MU,   DE_DQOT, DE_QUOT, DE_HASH, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/*
 * .-----------------------------------------------------.                  .-----------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     |                  | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * |        | PGUP   | BACKSP | UP     | DEL    | PGDOWN |                  | -      | 7      | 8      | 9      | +      |        |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * |        | HOME   | LEFT   | DOWN   | RIGHT  | END    |                  | /      | 3      | 5      | 6      | *      |        |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * |        | MUTE   | VOLDN  | VOLUP  | ENTER  | WHOME  |                  | =      | 1      | 2      | 3      | %      |        |
 * |--------+--------+--------+--------+--------+--------+--------..--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        ||        |        |        | 0      |        |        |        |
 * '--------+--------+--------+--------+--------+--------+--------''--------+--------+--------+--------+--------+--------+--------'
 */

[_L4] = {
    {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 },
    {_______, KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN, XXXXXXX, XXXXXXX, KC_PMNS, KC_7,    KC_8,    KC_9,    KC_PPLS, _______},
    {_______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  XXXXXXX, XXXXXXX, KC_PSLS, KC_4,    KC_5,    KC_6,    KC_PAST, _______},
    {_______, KC_MUTE, KC_VOLD, KC_VOLU, KC_ENT,  KC_WHOM, XXXXXXX, XXXXXXX, KC_PEQL, KC_1,    KC_2,    KC_3,    DE_PERC, MO(_MO)},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_0,    _______, _______, _______, DF(_Q1)}
},

[_MO] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, KC_BTN1, KC_MS_U, KC_BTN1, KC_WH_U, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, KC_BTN3, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
},

/* QWERTY
 * .-----------------------------------------------------.                  .-----------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      |                  | 6      | 7      | 8      | 9      | 0      | ß      |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * | +      | Q      | W      | E      | R      | T      |                  | Z      | U      | I      | O      | P      | Ü      |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * | #      | A      | S      | D      | F      | G      |                  | J      | H      | K      | L      | Ö      | Ä      |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * | SHIFT  | Y      | X      | C      | V      | B      |                  | N      | M      | ,      | .      | -      | SHIFT  |
 * |--------+--------+--------+--------+--------+--------+--------..--------+--------+--------+--------+--------+--------+--------|
 * | CTRL   | META   | ALT    | BSPACE | SPACE  | SHIFT  | TAB    || ENTER  | SHIFT  | SPACE  | DEL    | ALTGR  | META   | CTRL   |
 * '--------+--------+--------+--------+--------+--------+--------''--------+--------+--------+--------+--------+--------+--------'
 */

[_Q1] = { /* Standard; as compatible with dvorak and qwerty as possible */
    {KC_ESC,  DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    XXXXXXX, XXXXXXX, DE_6,    DE_7,    DE_8,    DE_9,    DE_0,     DE_SS  },
    {DE_PLUS, DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    XXXXXXX, XXXXXXX, DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,     DE_UE  },
    {DE_HASH, DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    XXXXXXX, XXXXXXX, DE_H,    DE_J,    DE_K,    DE_L,    DE_OE,    DE_AE  },
    {KC_LSFT, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    XXXXXXX, XXXXXXX, DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS,  KC_RSFT},
    {KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  KC_LSFT, KC_TAB,  KC_ENT,  KC_RSFT, KC_SPC,  MO(_Q4), KC_RALT, KC_RGUI,  KC_RCTL}
},

/*
 * .-----------------------------------------------------.                  .-----------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     |                  | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * |        | PGUP   | BACKSP | UP     | DEL    | PGDOWN |                  | -      | 7      | 8      | 9      | +      |        |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * |        | HOME   | LEFT   | DOWN   | RIGHT  | END    |                  | /      | 3      | 5      | 6      | *      |        |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * |        | MUTE   | VOLDN  | VOLUP  | ENTER  | WHOME  |                  | =      | 1      | 2      | 3      | %      |        |
 * |--------+--------+--------+--------+--------+--------+--------..--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        ||        |        |        | 0      |        |        |        |
 * '--------+--------+--------+--------+--------+--------+--------''--------+--------+--------+--------+--------+--------+--------'
 */

[_Q4] = {
    {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 },
    {_______, KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN, XXXXXXX, XXXXXXX, KC_PMNS, KC_7,    KC_8,    KC_9,    KC_PPLS, _______},
    {_______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  XXXXXXX, XXXXXXX, KC_PSLS, KC_4,    KC_5,    KC_6,    KC_PAST, _______},
    {_______, KC_MUTE, KC_VOLD, KC_VOLU, KC_ENT,  KC_WHOM, XXXXXXX, XXXXXXX, KC_PEQL, KC_1,    KC_2,    KC_3,    DE_PERC, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_0,    _______, _______, _______, DF(_L1)}
},

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

void matrix_scan_user(void)
{
    uint8_t layer = biton32(layer_state);

    switch (layer) {
    case _L1:
            if (isShiftPressed) {
                set_led_green;
            } else {
                set_led_off;
            }
            break;
    case _L3:
            set_led_cyan;
            break;
    case _L4:
            set_led_white;
            break;
    case _MO:
            set_led_red;
            break;
    case _Q4:
            set_led_white;
            break;
    default:
            break;
    }

    extern bool leading;
    extern uint16_t leader_time;
    extern uint16_t leader_sequence[5];
    extern uint8_t leader_sequence_size;


    if (leading) {
        if (leader_sequence_size == LEADER_SEQUENCE_LEN) {
            leading = false;
            leader_end();
        }
        else if (timer_elapsed(leader_time) > LEADER_TIMEOUT) {
            leading = false;
            leader_end();
        }

        if (leader_sequence[0] == (DE_A)) {
            register_code(DE_AE);
            unregister_code(DE_AE);
            leading = false;
            leader_end();
        }

        else if (leader_sequence[0] == (DE_O)) {
            register_code(DE_OE);
            unregister_code(DE_OE);
            leading = false;
            leader_end();
        }

        else if (leader_sequence[0] == (DE_U)) {
            register_code(DE_UE);
            unregister_code(DE_UE);
            leading = false;
            leader_end();
        }

        else if (leader_sequence[0] == (DE_P)) {
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(DE_P);
            unregister_code(DE_P);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
            leading = false;
            leader_end();
        }

        else if (leader_sequence[0] != 0) {
            leading = false;
            leader_end();
        }
    }
};

