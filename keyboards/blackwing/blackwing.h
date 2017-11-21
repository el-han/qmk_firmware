#ifndef BLACKWING_H
#define BLACKWING_H

#include "quantum.h"
#include "matrix.h"

#define red_led_off   PORTF |= (1<<5)
#define red_led_on    PORTF &= ~(1<<5)
#define blu_led_off   PORTF |= (1<<4)
#define blu_led_on    PORTF &= ~(1<<4)
#define grn_led_off   PORTD |= (1<<1)
#define grn_led_on    PORTD &= ~(1<<1)

#define set_led_off     red_led_off; grn_led_off; blu_led_off
#define set_led_red     red_led_on;  grn_led_off; blu_led_off
#define set_led_blue    red_led_off; grn_led_off; blu_led_on
#define set_led_green   red_led_off; grn_led_on;  blu_led_off
#define set_led_yellow  red_led_on;  grn_led_on;  blu_led_off
#define set_led_magenta red_led_on;  grn_led_off; blu_led_on
#define set_led_cyan    red_led_off; grn_led_on;  blu_led_on
#define set_led_white   red_led_on;  grn_led_on;  blu_led_on

/*
#define LED_B 5
#define LED_R 6
#define LED_G 7

#define all_leds_off PORTF &= ~(1<<LED_B) & ~(1<<LED_R) & ~(1<<LED_G)

#define red_led_on   PORTF |= (1<<LED_R)
#define red_led_off  PORTF &= ~(1<<LED_R)
#define grn_led_on   PORTF |= (1<<LED_G)
#define grn_led_off  PORTF &= ~(1<<LED_G)
#define blu_led_on   PORTF |= (1<<LED_B)
#define blu_led_off  PORTF &= ~(1<<LED_B)

#define set_led_off     PORTF &= ~(1<<LED_B) & ~(1<<LED_R) & ~(1<<LED_G)
#define set_led_red     PORTF = PORTF & ~(1<<LED_B) & ~(1<<LED_G) | (1<<LED_R)
#define set_led_blue    PORTF = PORTF & ~(1<<LED_G) & ~(1<<LED_R) | (1<<LED_B)
#define set_led_green   PORTF = PORTF & ~(1<<LED_B) & ~(1<<LED_R) | (1<<LED_G)
#define set_led_yellow  PORTF = PORTF & ~(1<<LED_B) | (1<<LED_R) | (1<<LED_G)
#define set_led_magenta PORTF = PORTF & ~(1<<LED_G) | (1<<LED_R) | (1<<LED_B)
#define set_led_cyan    PORTF = PORTF & ~(1<<LED_R) | (1<<LED_B) | (1<<LED_G)
#define set_led_white   PORTF |= (1<<LED_B) | (1<<LED_R) | (1<<LED_G)
*/

// This a shortcut to help you visually see your layout.
// The first section contains all of the arguements
// The second converts the arguments into a two-dimensional array
#define KEYMAP( \
  l00, l01, l02, l03, l04, l05,                r05, r04, r03, r02, r01, r00, \
  l10, l11, l12, l13, l14, l15,                r15, r14, r13, r12, r11, r10, \
  l20, l21, l22, l23, l24, l25,                r25, r24, r23, r22, r21, r20, \
  l30, l31, l32, l33, l34, l35,                r35, r34, r33, r32, r31, r30, \
  l40, l41, l42, l43, l44, l45, l50,      r50, r45, r44, r43, r42, r41, r40  \
) \
{ \
	{ l00, l01, l02, l03, l04, l05, KC_NO,  KC_NO, r05, r04, r03, r02, r01, r00 }, \
	{ l10, l11, l12, l13, l14, l15, KC_NO,  KC_NO, r15, r14, r13, r12, r11, r10 }, \
	{ l20, l21, l22, l23, l24, l25, KC_NO,  KC_NO, r25, r24, r23, r22, r21, r20 }, \
	{ l30, l31, l32, l33, l34, l35, KC_NO,  KC_NO, r35, r34, r33, r32, r31, r30 }, \
	{ l40, l41, l42, l43, l44, l45, l50,      r50, r45, r44, r43, r42, r41, r40 }, \
}

#endif
