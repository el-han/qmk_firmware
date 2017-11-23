#include "blackwing.h"

enum blackwing_layers
{
  _STD,
  _L4
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .-----------------------------------------------------.                  .-----------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      |                  | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * | TAB    | Q      | W      | E      | R      | T      |                  | Y      | U      | I      | O      | P      | ¨      |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * | L3     | A      | S      | D      | F      | G      |                  | J      | H      | K      | L      | ;      | L3     |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * | SHIFT  | Z      | X      | C      | V      | B      |                  | N      | M      | ,      | .      | /      | SHIFT  |
 * |--------+--------+--------+--------+--------+--------+--------..--------+--------+--------+--------+--------+--------+--------|
 * | CTRL   | META   | ALT    | L3     | SHIFT  | SPACE  | TAB    || ENTER  | SPACE  | SHIFT  | L3     | ALTGR  | META   | CTRL   |
 * '--------+--------+--------+--------+--------+--------+--------''--------+--------+--------+--------+--------+--------+--------'
 */

[_STD] = { /* Standard; as compatible with dvorak and qwerty as possible */
  {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC},
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX, XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC},
  {KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX, XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_CAPS},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT},
  {KC_LCTL, KC_LGUI, KC_LALT, KC_CAPS, KC_SPC,  KC_LSFT, KC_TAB,  KC_ENT,  KC_RSFT, KC_SPC,  KC_CAPS, MO(_L4), KC_RGUI,  KC_RCTL}
},

/* Fn layout, for typing purposes (Dvorak result in parens)
 * .-----------------------------------------------------.                  .-----------------------------------------------------.
 * |        |        |        |        |        |        |                  |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * |        | PGUP   | BACKSP | UP     | DEL    | PGDOWN |                  | -      | 7      | 8      | 9      | +      |        |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * |        | HOME   | LEFT   | DOWN   | RIGHT  | END    |                  | /      | 3      | 5      | 6      | *      |        |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * |        | MUTE   | VOLDN  | VOLUP  | DOLLAR | WHOME  |                  | =      | 1      | 2      | 3      | %      |        |
 * |--------+--------+--------+--------+--------+--------+--------..--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        ||        |        |        | 0      |        |        |        |
 * '--------+--------+--------+--------+--------+--------+--------''--------+--------+--------+--------+--------+--------+--------'
 */

[_L4] = { /* Function Layer, primary alternative layer featuring numpad on right hand,
                                   cursor keys on left hand, and all symbols*/
  {_______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______ },
  {_______, KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN, XXXXXXX, XXXXXXX, KC_PMNS, KC_7,    KC_8,    KC_9,    KC_PPLS, _______ },
  {_______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  XXXXXXX, XXXXXXX, KC_PSLS, KC_4,    KC_5,    KC_6,    KC_PAST, _______ },
  {_______, KC_MUTE, KC_VOLD, KC_VOLU, KC_DLR,  KC_WHOM, XXXXXXX, XXXXXXX, KC_PEQL, KC_1,    KC_2,    KC_3,    KC_PERC, _______ },
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_0,    _______, _______, _______ }
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

void matrix_scan_user(void)
{
    uint8_t layer = biton32(layer_state);

    switch (layer) {
    case _STD:
        set_led_off;
        break;
    case _L4:
        set_led_red;
        break;
    default:
        break;
    }
};

