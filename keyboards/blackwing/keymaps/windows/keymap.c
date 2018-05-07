#include "blackwing.h"
#include "keymap_german.h"

enum blackwing_layers
{
  _STD,
  _L2,
  _L3,
  _L4
};

// Fillers to make layering more clear
#define ------- KC_TRNS
#define XXXXXXX KC_NO
#define KC_MU ALGR(DE_M)

enum custom_keycodes {
    SLS_BSL = SAFE_RANGE,
    C_SHIFT
};

bool isShiftPressed = false;

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
  {C_SHIFT, SLS_BSL, DE_Q,    DE_J,    DE_K,    DE_X,    XXXXXXX, XXXXXXX, DE_B,    DE_M,    DE_W,    DE_V,    DE_L,     C_SHIFT},
  {KC_LCTL, KC_LGUI, KC_LALT, MO(_L3), KC_SPC,  C_SHIFT, KC_TAB,  KC_ENT,  C_SHIFT, KC_SPC,  MO(_L3), MO(_L4), KC_RGUI,  KC_RCTL}
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

[_L2] = { /* Standard; as compatible with dvorak and qwerty as possible */
  {_______, DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    XXXXXXX, XXXXXXX, DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    KC_BSPC},
  {_______, DE_MINS, DE_COMM, DE_DOT,  DE_P,    DE_Y,    XXXXXXX, XXXXXXX, DE_F,    DE_G,    DE_C,    DE_T,    DE_Z,    DE_RING},
  {_______, DE_A,    DE_O,    DE_E,    DE_I,    DE_U,    XXXXXXX, XXXXXXX, DE_H,    DE_D,    DE_R,    DE_N,    DE_S,    -------},
  {_______, DE_BSLS, DE_Q,    DE_J,    DE_K,    DE_X,    XXXXXXX, XXXXXXX, DE_B,    DE_M,    DE_W,    DE_V,    DE_L,    -------},
  {_______, _______, _______, _______,_______,  _______, _______, _______, _______, _______, _______, _______, _______, -------}
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

[_L3] = { /* Standard; as compatible with dvorak and qwerty as possible */
  {_______, XXXXXXX, DE_SQ2,  DE_SQ3,  DE_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DE_LCBR, DE_LBRC, DE_RBRC, DE_RCBR, -------},
  {_______, DE_UNDS, DE_SCLN, DE_LBRC, DE_RBRC, DE_ASTR, XXXXXXX, XXXXXXX, DE_PLUS, DE_LESS, DE_MORE, DE_EQL,  DE_DLR,  -------},
  {_______, DE_AT,   DE_EURO, DE_LCBR, DE_RCBR, DE_EXLM, XXXXXXX, XXXXXXX, DE_QST,  DE_LPRN, DE_RPRN, DE_MINS, DE_SS,   -------},
  {_______, DE_PIPE, DE_CIRC, DE_ACUT, DE_TILD, DE_GRV,  XXXXXXX, XXXXXXX, DE_AMPR, KC_MU,   DE_DQOT, DE_QUOT, DE_HASH, -------},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, -------}
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
  {_______, KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN, XXXXXXX, XXXXXXX, KC_PMNS, KC_7,    KC_8,    KC_9,    KC_PPLS, ------- },
  {_______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  XXXXXXX, XXXXXXX, KC_PSLS, KC_4,    KC_5,    KC_6,    KC_PAST, ------- },
  {_______, KC_MUTE, KC_VOLD, KC_VOLU, KC_ENT,  KC_WHOM, XXXXXXX, XXXXXXX, KC_PEQL, KC_1,    KC_2,    KC_3,    DE_PERC, ------- },
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_0,    _______, _______, ------- }
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case SLS_BSL:
      if (record->event.pressed) {
        if (isShiftPressed)
          SEND_STRING(SS_UP(X_LSHIFT)SS_DOWN(X_RALT)SS_TAP(X_MINUS)SS_UP(X_RALT)SS_DOWN(X_LSHIFT));
        else
          SEND_STRING(SS_DOWN(X_LSHIFT)SS_TAP(X_7)SS_UP(X_LSHIFT));
      }
      return false;
      break;
    case C_SHIFT:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSHIFT));
        isShiftPressed = true;
        set_led_green;
      } else {
        SEND_STRING(SS_UP(X_LSHIFT));
        isShiftPressed = false;
        //set_led_off;
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
  case _STD:
      set_led_off;
      break;
  case _L2:
      set_led_green;
      //register_code(KC_LSFT);
      break;
  case _L3:
      set_led_cyan;
      break;
  case _L4:
      set_led_red;
      break;
  default:
      break;
  }

  extern bool leading; extern uint16_t leader_time; extern uint16_t leader_sequence[5];

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

