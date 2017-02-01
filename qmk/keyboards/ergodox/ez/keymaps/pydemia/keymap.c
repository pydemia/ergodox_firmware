#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define SIGN "# -*- coding: utf-8 -*- \n'''\nCreated on \n\n@author: Young Ju Kim\n'''"

#define WKEY 0 // default layer
#define NPAD 1 // Numpad Layer
#define MAGI 2 // Magic Layer
#define LKEY 3 // Linux
#define PPTK 4 // PPT

#define EPRM M(1) // Macro 1: Reset EEPROM

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │  Esc  │  1  │  2  │  3  │  4  │  5  │CtFn5│     │  6  │  7  │  8  │  9  │  0  │  -  │   +   │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │  Tab  │  Q  │  W  │  E  │  R  │  T  │  <- │     │ Ctl │  Y  │  U  │  I  │  O  │  P  │   \   │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤  =  │     │ Ent ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │   ~   │  A  │  S  │  D  │  F  │  G  ├─────┤     ├─────┤  H  │  J  │  K  │  L  │  ;  │   '   │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤ Tg  │     │ Ctl ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │ LSHFT │  Z  │  X  │  C  │  V  │  B  │ Npd │     │ Fn5 │  N  │  M  │  ,  │  .  │  /  │ Shift │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │ CTL │CtAlt│Wn/Cd│ App │ ALT │                             │ RAt │ RCl │  [  │  ]  │ TgM │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │ Hom │ End │ │ Lft │ Rgt │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │ Pup │ │ Up  │     │     │
 *                             │ Spc │ Bsp ├─────┤ ├─────┤ Del │ Ent │
 *                             │     │     │ Pdn │ │ Dwn │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*

//Hyper: ALL_T(KC_NO)
//Meh: MEH_T(KC_NO)
[WKEY] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,   KC_1,          KC_2,    KC_3,         KC_4,    KC_5,  LCTL(KC_F5),         // TG(LKEY),
        KC_TAB,   KC_Q,          KC_W,    KC_E,         KC_R,    KC_T,  KC_EQUAL,
        KC_GRV,   KC_A,          KC_S,    KC_D,         KC_F,    KC_G,
        KC_LSFT,  KC_Z,          KC_X,    KC_C,         KC_V,    KC_B,  KC_FN1,
        KC_LCTRL, LCTL(KC_LALT), KC_LGUI, KC_APP,      KC_LALT,
                                                        KC_HOME, KC_END,
                                                                 KC_PGUP,
                                               KC_SPC,  KC_BSPC, KC_PGDN,
        // right hand
        KC_6,                KC_7,           KC_8,     KC_9,                 KC_0,                 KC_MINUS,  KC_PLUS,
        LCTL(KC_ENT),        KC_Y,           KC_U,     KC_I,                 KC_O,                 KC_P,      KC_BSLS,
                             KC_H,           KC_J,     KC_K,                 KC_L,                 KC_SCLN,   KC_QUOT,
        LCTL(KC_F5),         KC_N,           KC_M,     KC_COMM,              KC_DOT,               KC_SLSH,   KC_RSFT,
                             KC_RALT,        KC_RCTL,  KC_LBRC,              KC_RBRC,              KC_FN2,
        KC_LEFT,     KC_RGHT, 
        KC_UP,
        KC_DOWN,     KC_DELT,  KC_ENT
    ),
/* Keymap 1: Numpad Layer
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │  Ver  │ Fn1 │ Fn2 │ Fn3 │ Fn4 │ Fn5 │ Fn6 │     │ Fn7 │ Fn8 │ Fn9 │ F10 │ F11 │ F12 │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │ CAT │     │ Dfm │  [  │  ]  │  <- │     │     │  7  │  8  │  9  │  +  │  -  │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤     │     │     ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │     │     │ DTm │  {  │  }  ├─────┤     ├─────┤  4  │  5  │  6  │  *  │  /  │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤     │     │     ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │     │     │     │  (  │  )  │     │     │     │  1  │  2  │  3  │  ,  │ Up  │       │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │     │     │     │     │     │                             │  0  │  .  │ Lft │ Dwn │ Rgt │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │ Lft │ Rgt │ │ CLf │ CRt │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │ Up  │ │ Up  │     │     │
 *                             │ Ent │ Del ├─────┤ ├─────┤ Bsp │ Spc │
 *                             │     │     │ Dwn │ │ Dwn │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
// SYMBOLS M(0) = Version
[NPAD] = KEYMAP(
       // left hand
       KC_ESC,   KC_F1,  	  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,
       KC_TRNS, LCTL(LALT(KC_T)), KC_TRNS,  M(2),    KC_LBRC, KC_RBRC, M(1),
       KC_TRNS, KC_TRNS, 	  KC_TRNS,  M(3),    KC_LCBR, KC_RCBR,
       KC_TRNS, KC_TRNS, 	  KC_TRNS,  KC_TRNS, KC_LPRN, KC_RPRN, KC_TRNS,
          EPRM, KC_TRNS, 	  KC_TRNS,  KC_TRNS, KC_TRNS,
                                                        KC_LEFT, KC_RGHT,
                                                                 KC_UP,
                                               KC_ENT,  KC_DELT, KC_DOWN,

       // right hand
       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
       KC_TILD, KC_7,    KC_8,    KC_9,    KC_PLUS, KC_MINUS,KC_TRNS, 
                KC_4,    KC_5,    KC_6,    KC_ASTR, KC_SLSH, KC_TRNS,
       KC_TRNS, KC_1,    KC_2,    KC_3,    KC_COMM, KC_UP,   KC_TRNS,
                KC_0,    KC_DOT,  KC_LEFT, KC_DOWN, KC_RGHT,
       LCTL(KC_LEFT),     LCTL(KC_RGHT),
       KC_PGUP,
       KC_PGDN,     KC_BSPC,  KC_SPC
    ),
/* Keymap 2: Magic Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |  Up  |      |      |      |           |      |      |      |      |  {[  |  ]}  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Left | Down | Rght |      |------|           |------|      |      |      |   (  |   )  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM |      |      |      |      |                                       |      |      |      |      |       |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | SFHm | SFEd |       | Left | Right|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | PgUp |       |  Up  |        |      |
 *                                 | Space|Backsp|------|       |------|  Del   |Enter |
 *                                 |      |ace   | PgDn |       | Down |        |      |
 *                                 `--------------------'       `----------------------'
 */
// MAGI
[MAGI] = KEYMAP(
       // left hand
       KC_ESC,   KC_F1,           KC_F2,        KC_F3,   KC_F4,  KC_F5,   KC_F6,
       KC_TRNS,KC_TRNS,         KC_TRNS,        KC_UP,	 KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,KC_TRNS,         KC_LEFT,     	KC_DOWN, KC_RGHT, KC_TRNS,
       KC_TRNS,KC_TRNS,   KC_TRNS, KC_TRNS,  	KC_TRNS, KC_TRNS, KC_TRNS,
       KC_LCTRL,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       	       LSFT(KC_HOME),    LSFT(KC_END),
                                                                 KC_PGUP,
                                               KC_SPC,  KC_BSPC, KC_PGDN,
       // right hand
       KC_F7,   KC_F8,         KC_F9,        KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
       KC_TRNS, KC_TRNS,       KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,       KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                               KC_TRNS,      KC_TRNS,  KC_COMM, KC_TRNS,  KC_TRNS,
       KC_LEFT,     KC_RGHT,
       KC_UP,
       KC_DOWN,     KC_DELT,  KC_ENT
    ),
/* Keymap 3: Linux Key layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  | TgLk |           |   6  |   7  |   8  |   9  |   0  |   -  |   +    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|  =   |           |  <-  |------+------+------+------+------+--------|
 * |   ~    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|   '    |
 * |--------+------+------+------+------+------|      |           |CtrlF5|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl |CtlAlt|Wn/Cmd| App |  LAlt |                                       | RAlt | RCtl |  [   |  ]   | TgPT |
 *   `----------------------------------'                                      `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Home | End  |       | CtLf | CtRt |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | PgUp |       |  Up  |        |      |
 *                                 | Space|Backsp|------|       |------|  Del   |Enter |
 *                                 |      |ace   | PgDn |       | Down |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*

//Hyper: ALL_T(KC_NO)
//Meh: MEH_T(KC_NO)
[LKEY] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,   KC_1,          KC_2,    KC_3,         KC_4,    KC_5,  TG(LKEY),
        KC_TAB,   KC_Q,          KC_W,    KC_E,         KC_R,    KC_T,  KC_EQUAL,
        KC_GRV,   KC_A,          KC_S,    KC_D,         KC_F,    KC_G,
        KC_LSFT,  KC_Z,          KC_X,    KC_C,         KC_V,    KC_B,  LT(NPAD, TG(NPAD)),
        KC_LCTRL, LCTL(KC_LALT), KC_LGUI, KC_APP,      KC_LALT,
                                       			KC_HOME, KC_END,
                                                                 KC_PGUP,
                                               KC_SPC,  KC_DELT, KC_PGDN,
        // right hand
        KC_6,                KC_7,           KC_8,     KC_9,                 KC_0,                 KC_MINUS,  KC_PLUS,
        M(1),            KC_Y,           KC_U,     KC_I,                 KC_O,                 KC_P,      KC_BSLS,
                             KC_H,           KC_J,     KC_K,                 KC_L,                 KC_SCLN,   KC_QUOT,
        LCTL(KC_F5),         KC_N,           KC_M,     KC_COMM,              KC_DOT,               KC_SLSH,   LT(KC_RSFT, TG(NPAD)),
                             KC_RALT,        LSFT(KC_SPC),  KC_LBRC,              KC_RBRC,              KC_FN1,
        KC_HOME,     KC_END, 
        KC_PGUP,
        KC_PGDN,     KC_DELT,  KC_ENT
    ),
/* Keymap 4: PPT layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  | TgLk |           |   6  |   7  |   8  |   9  |   0  |   -  |   +    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|  =   |           |  <-  |------+------+------+------+------+--------|
 * |   ~    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|   '    |
 * |--------+------+------+------+------+------|      |           |CtrlF5|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl |CtlAlt|Wn/Cmd| App |  LAlt |                                       | RAlt | RCtl |  [   |  ]   | TgPT |
 *   `----------------------------------'                                      `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Home | End  |       | Left | Right|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | PgUp |       |  Up  |        |      |
 *                                 | Space|Backsp|------|       |------|  Del   |Enter |
 *                                 |      |ace   | PgDn |       | Down |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*

//Hyper: ALL_T(KC_NO)
//Meh: MEH_T(KC_NO)
[PPTK] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,   KC_1,          KC_2,    KC_3,         KC_4,    KC_5,  TG(LKEY),
        KC_TAB,   KC_Q,          KC_W,    KC_E,         KC_R,    KC_T,  KC_EQUAL,
        KC_GRV,   KC_A,          KC_S,    KC_D,         KC_F,    KC_G,
        KC_LSFT,  KC_Z,          KC_X,    KC_C,         KC_V,    KC_B,  LT(NPAD, TG(NPAD)),
        KC_LCTRL, LCTL(KC_LALT), KC_LGUI, KC_APP,      KC_LALT,
                                                        KC_HOME, KC_END,
                                                                 KC_PGUP,
                                               KC_SPC,  KC_BSPC, KC_PGDN,
        // right hand
        KC_6,                KC_7,           KC_8,     KC_9,                 KC_0,                 KC_MINUS,  KC_PLUS,
        M(1),            KC_Y,           KC_U,     KC_I,                 KC_O,                 KC_P,      KC_BSLS,
                             KC_H,           KC_J,     KC_K,                 KC_L,                 KC_SCLN,   KC_QUOT,
        LCTL(KC_F5),         KC_N,           KC_M,     KC_COMM,              KC_DOT,               KC_SLSH,   KC_RSFT,
                             KC_RALT,        LSFT(KC_SPC),  KC_LBRC,              KC_RBRC,              KC_FN1,
        KC_LEFT,     KC_RGHT, 
        KC_UP,
        KC_DOWN,     KC_DELT,  KC_ENT
    ),
};

/* Layer _ : ---
 * ┌─────────┬───────┬───────┬───────┬───────┬───────┬───────┐     ┌───────┬───────┬───────┬───────┬───────┬───────┬─────────┐
 * │         │       │       │       │       │       │       │     │       │       │       │       │       │       │         │
 * ├─────────┼───────┼───────┼───────┼───────┼───────┼───────┤     ├───────┼───────┼───────┼───────┼───────┼───────┼─────────┤
 * │         │  A    │    A  │    A  │    A  │    A  │       │     │       │       │   F9  │   F10 │   F11 │   F12 │         │
 * ├─────────┼───────┼───────┼───────┼───────┼───────┤       │     │       ├───────┼───────┼───────┼───────┼───────┼─────────┤
 * │         │  A    │    A  │    A  │    A  │    A  ├───────┤     ├───────┤       │   F5  │   F6  │   F7  │   F8  │         │
 * ├─────────┼───────┼───────┼───────┼───────┼───────┤  (TL2)│     │  (TL3)├───────┼───────┼───────┼───────┼───────┼─────────┤
 * │         │  A    │    A  │    A  │    A  │    A  │       │     │       │       │   F1  │   F2  │   F3  │   F4  │         │
 * └─┬───────┼───────┼───────┼───────┼───────┼───────┴───────┘     └───────┴───────┼───────┼───────┼───────┼───────┼───────┬─┘
 *   │       │       │(MO1)  │       │(MO4)  │                                     │(MO4)  │       │  (MO1)│       │       │
 *   └───────┴───────┴───────┴───────┴───────┘ ┌───────┬───────┐ ┌───────┬───────┐ └───────┴───────┴───────┴───────┴───────┘
 *                                             │ Ms    │ Ms    │ │   Ms  │  Ms   │
 *                                     ┌───────┼───────┼───────┤ ├───────┼───────┼───────┐
 *                                     │       │       │   MLC │ │ MRC   │       │       │
 *                                     │       │       ├───────┤ ├───────┤       │       │
 *                                     │       │       │       │ │       │       │       │
 *                                     └───────┴───────┴───────┘ └───────┴───────┴───────┘
 */

/* Layer _ : ---
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │  TAB  │  1  │  2  │  3  │  4  │  5  │  `  │     │  ´  │  6  │  7  │  8  │  9  │  0  │ BKSPC │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │   Y   │  X  │  V  │  L  │  C  │  W  │ HOM │     │ END │  K  │  H  │  G  │  F  │  Q  │  ß    │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤  E  │     │     ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │ Mod3  │  U  │  I  │  A  │  E  │  O  ├─────┤     ├─────┤  S  │  N  │  R  │  T  │  D  │ Mod3  │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤ TL2 │     │ TL3 ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │ LSHFT │  Ü  │  Ö  │  Ä  │  P  │  Z  │     │     │     │  B  │  M  │  ,  │  .  │  J  │ Shift │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │ CTL │ ALT │ MO1 │ Win │ Mod4│                             │ Mod4│ Win │ MO1 │ Alt │ CTL │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │  A  │  A  │ │  A  │  A  │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │  ─  │ │  ─  │     │     │
 *                             │ SPC │ RTN ├─────┤ ├─────┤ RTN │ SPC │
 *                             │     │     │ HYP │ │ MEH │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(NPAD),                // FN1 - Momentary Layer 1 (Numpad Layer)~
    [2] = ACTION_LAYER_TAP_TOGGLE(MAGI),                // FN2 - Momentary Layer 2 (Magic Layer)~

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          SEND_STRING ( "<-" );
        }
        break;
        case 2:
        if (record->event.pressed) { // For resetting EEPROM
          SEND_STRING ( "'%Y%m%d%H%M%S%f'" );
        }
        break;
	case 3:
        if (record->event.pressed) { // For resetting EEPROM
          SEND_STRING ( SIGN );
        }
        break;
//        case REQL:
//            return (record->event.pressed ?
//                    MACRO( T(LSFT(KC_COMMA)), T(KC_MINUS), END) : // For resetting EEPROM
//                    MACRO_NONE ) ;
    }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Print Timestamp Function
/*static macro_t *gettime(void) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    printf("%s\n", asctime(tm));
    return MACRO_NONE; 
}
*/
// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
