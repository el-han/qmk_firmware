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

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */

#define VENDOR_ID       0xfeed
#define PRODUCT_ID      0x7070
#define DEVICE_VER      0x0001

#define MANUFACTURER    Elli
#define PRODUCT         Ingot

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 12
#define MATRIX_COLS 11
#define MATRIX_ROW_PINS { F4, F5, F6, F7, C7, C6, D0, B7, B3, B2, B1, B0 }
#define MATRIX_COL_PINS { D1, D2, D3, D5, D4, D6, D7, B4, B5, B6, F1 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

// The pin connected to the data pin of the LEDs
#define RGB_DI_PIN F0
// The number of LEDs connected
#define RGBLED_NUM 112

#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 10
/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

// /* disable debug print */
// #define NO_DEBUG

// /* disable print */
// #define NO_PRINT

// /* disable action features */
// #define NO_ACTION_LAYER
// #define NO_ACTION_TAPPING
// #define NO_ACTION_ONESHOT
// #define NO_ACTION_MACRO
// #define NO_ACTION_FUNCTION

#define LEADER_TIMEOUT 300
