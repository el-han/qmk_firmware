#include "blackwing.h"
#include "keymap_german.h"

enum blackwing_layers
{
  _STD,
//  _L2,
  _L3,
  _L4
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_MU ALGR(DE_M)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .-----------------------------------------------------.                  .-----------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      |                  | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * | TAB    | Q      | W      | E      | R      | T      |                  | Y      | U      | I      | O      | P      | ¨      |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * | L3     | A      | S      | D      | F      | G      |                  | J      | H      | K      | L      | ;      | L3     |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * | L2     | Z      | X      | C      | V      | B      |                  | N      | M      | ,      | .      | /      | L2     |
 * |--------+--------+--------+--------+--------+--------+--------..--------+--------+--------+--------+--------+--------+--------|
 * | CTRL   | META   | ALT    | L3     | L2     | SPACE  | TAB    || ENTER  | SPACE  | L2     | L3     | L4     | META   | CTRL   |
 * '--------+--------+--------+--------+--------+--------+--------''--------+--------+--------+--------+--------+--------+--------'
 */

[_STD] = { /* Standard; as compatible with dvorak and qwerty as possible */
  {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC},
  {KC_TAB,  DE_MINS, DE_COMM, DE_DOT,  DE_P,    DE_Y,    XXXXXXX, XXXXXXX, DE_F,    DE_G,    DE_C,    DE_T,    DE_Z,     KC_LEAD},
  {MO(_L3), DE_A,    DE_O,    DE_E,    DE_I,    DE_U,    XXXXXXX, XXXXXXX, DE_H,    DE_D,    DE_R,    DE_N,    DE_S,     MO(_L3)},
  {KC_LSFT, DE_SLSH, DE_Q,    DE_J,    DE_K,    DE_X,    XXXXXXX, XXXXXXX, DE_B,    DE_M,    DE_W,    DE_V,    DE_L,     KC_LSFT},
  {KC_LCTL, KC_LGUI, KC_LALT, MO(_L3), KC_SPC,  KC_LSFT, KC_TAB,  KC_ENT,  KC_LSFT, KC_SPC,  MO(_L3), MO(_L4), KC_RGUI,  KC_RCTL}
},

/* QWERTY
 * .-----------------------------------------------------.                  .-----------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      |                  | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * | TAB    | Q      | W      | E      | R      | T      |                  | Y      | U      | I      | O      | P      | ¨      |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * | L3     | A      | S      | D      | F      | G      |                  | J      | H      | K      | L      | ;      | L3     |
 * |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 * | L2     | Z      | X      | C      | V      | B      |                  | N      | M      | ,      | .      | /      | L2     |
 * |--------+--------+--------+--------+--------+--------+--------..--------+--------+--------+--------+--------+--------+--------|
 * | CTRL   | META   | ALT    | L3     | L2     | SPACE  | TAB    || ENTER  | SPACE  | L2     | L3     | L4     | META   | CTRL   |
 * '--------+--------+--------+--------+--------+--------+--------''--------+--------+--------+--------+--------+--------+--------'
 */

// [_L2] = { /* Standard; as compatible with dvorak and qwerty as possible */
//   {LSFT(KC_ESC),  LSFT(DE_1),    LSFT(DE_2),    LSFT(DE_3),    LSFT(DE_4),    LSFT(DE_5),    XXXXXXX,          XXXXXXX,       LSFT(DE_6),    LSFT(DE_7),    LSFT(DE_8),    LSFT(DE_9),    LSFT(DE_0),     LSFT(KC_BSPC)},
//   {LSFT(KC_TAB),  LSFT(DE_MINS), LSFT(DE_COMM), LSFT(DE_DOT),  LSFT(DE_P),    LSFT(DE_Y),    XXXXXXX,          XXXXXXX,       LSFT(DE_F),    LSFT(DE_G),    LSFT(DE_C),    LSFT(DE_T),    LSFT(DE_Z),     DE_RING},
//   {MO(_L3),       LSFT(DE_A),    LSFT(DE_O),    LSFT(DE_E),    LSFT(DE_I),    LSFT(DE_U),    XXXXXXX,          XXXXXXX,       LSFT(DE_H),    LSFT(DE_D),    LSFT(DE_R),    LSFT(DE_N),    LSFT(DE_S),     MO(_L3)},
//   {KC_LSFT,       DE_BSLS,       LSFT(DE_Q),    LSFT(DE_J),    LSFT(DE_K),    LSFT(DE_X),    XXXXXXX,          XXXXXXX,       LSFT(DE_B),    LSFT(DE_M),    LSFT(DE_W),    LSFT(DE_V),    LSFT(DE_L),     KC_LSFT},
//   {LSFT(KC_LCTL), LSFT(KC_LGUI), KC_LALT,       MO(_L3),       LSFT(KC_SPC),  KC_LSFT,       LSFT(KC_TAB),     LSFT(KC_ENT),  KC_LSFT,       LSFT(KC_SPC),  MO(_L3),       MO(_L4),       KC_RGUI,        LSFT(KC_RCTL)}
// },

/* Fn layout, for typing purposes (Dvorak result in parens)
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

[_L3] = { /* Standard; as compatible with dvorak and qwerty as possible */
  {KC_ESC,  XXXXXXX, DE_SQ2,  DE_SQ3,  DE_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DE_LCBR, DE_LBRC, DE_RBRC, DE_RCBR,  KC_BSPC},
  {KC_TAB,  DE_UNDS, DE_SCLN, DE_LBRC, DE_RBRC, DE_ASTR, XXXXXXX, XXXXXXX, DE_PLUS, DE_LESS, DE_MORE, DE_EQL,  DE_DLR,   DE_RING},
  {MO(_L3), DE_AT,   DE_EURO, DE_LCBR, DE_RCBR, DE_EXLM, XXXXXXX, XXXXXXX, DE_QST,  DE_LPRN,  DE_RPRN, DE_MINS, DE_SS,   MO(_L3)},
  {KC_LSFT, DE_PIPE, DE_CIRC, DE_ACUT, DE_TILD, DE_GRV,  XXXXXXX, XXXXXXX, DE_AMPR, KC_MU,   DE_DQOT, DE_QUOT, DE_HASH,  KC_LSFT},
  {KC_LCTL, KC_LGUI, KC_LALT, MO(_L3), KC_SPC,  KC_LSFT, KC_TAB,  KC_ENT,  KC_LSFT, KC_SPC,  MO(_L3), MO(_L4), KC_RGUI,  KC_RCTL}
},

/* Fn layout, for typing purposes (Dvorak result in parens)
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

[_L4] = { /* Function Layer, primary alternative layer featuring numpad on right hand,
                                   cursor keys on left hand, and all symbols*/
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12  },
  {_______, KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN, XXXXXXX, XXXXXXX, KC_PMNS, KC_7,    KC_8,    KC_9,    KC_PPLS, _______ },
  {_______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  XXXXXXX, XXXXXXX, KC_PSLS, KC_4,    KC_5,    KC_6,    KC_PAST, _______ },
  {_______, KC_MUTE, KC_VOLD, KC_VOLU, KC_ENT,  KC_WHOM, XXXXXXX, XXXXXXX, KC_PEQL, KC_1,    KC_2,    KC_3,    DE_PERC, _______ },
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
  // case _L2:
  //     set_led_green;
  //     break;
  case _L3:
      set_led_cyan;
      break;
  case _L4:
      set_led_white;
      break;
  default:
      break;
  }

  extern bool leading; extern uint16_t leader_time;
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(DE_A) {
      register_code(DE_AE);
      unregister_code(DE_AE);
    }

    SEQ_ONE_KEY(DE_O) {
      register_code(DE_OE);
      unregister_code(DE_OE);
    }

    SEQ_ONE_KEY(DE_U) {
      register_code(DE_UE);
      unregister_code(DE_UE);
    }
  }
};

