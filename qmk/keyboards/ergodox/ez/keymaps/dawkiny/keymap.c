#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define WKEY 0 // default layer
#define NPAD 1 // Numpad Layer
#define MAGI 2 // Magic Layer
#define LKEY 3 // Linux
#define PPTK 4 // PPT

#define EPRM M(1) // Macro 1: Reset EEPROM


/*// Tap Dance Start------------------------------------------------------------
#ifdef TAP_DANCE_ENABLE
#define SFT_CAP TD(0)	// Left shift, double tap for caps
#endif
#ifndef TAP_DANCE_ENABLE
#define SFT_CAP KC_LSFT // Regular left shift
#endif
#ifdef TAP_DANCE_ENABLE
#define QUOTE_SD TD(1)	// Single Quote, double tap for Double Quotes
#endif
#ifndef TAP_DANCE_ENABLE
#define QUOTE_SD kC_QUOT // Regular Single Quote
#endif
// Tap Dance Definitions
#ifdef TAP_DANCE_ENABLE
qk_tap_dance_action_t tap_dance_actions[] = {
	[0]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [1]  = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, LALT(KC_QUOT))
};
#endif
*/
// Tap Dance End ------------------------------------------------------------



//Tap Dance Declarations
enum {
  TD_01 = 0,
  TD_02,
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_01] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_CAPS),
  [TD_02] = ACTION_TAP_DANCE_DOUBLE(KC_I, KC_RBRC)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic layer
 *
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │  Esc  │  1  │  2  │  3  │  4  │  5  │CtFn5│     │  6  │  7  │  8  │  9  │  0  │  -  │   +   │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │  Tab  │  Q  │  W  │  E  │  R  │  T  │  <- │     │ Ctl │  Y  │  U  │  I  │  O  │  P  │   \   │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤  =  │     │ Ent ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │   ~   │  A  │  S  │  D  │  F  │  G  ├─────┤     ├─────┤  H  │  J  │  K  │  L  │  ;  │   '   │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤ Tg  │     │ Ctl ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │ LSHFT │  Z  │  X  │  C  │  V  │  B  │ Npd │     │ Fn5 │  N  │  M  │  ,  │  .  │  /  │ Shift │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │ CTL │ TgM │Wn/Cd│ App │ ALT │                             │ RAt │ RCl │  [  │  ]  │ TgM │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │ Pup │ Pdn │ │ Lft │ Rgt │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │ Hom │ │ Up  │     │     │
 *                             │ Spc │ Bsp ├─────┤ ├─────┤ Del │ Ent │
 *                             │     │     │ End │ │ Dwn │     │     │
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
        KC_GRV,   KC_A,          KC_S,    KC_D,         KC_F,    KC_G,  QUOTE_SD,
        SFT_CAP,  KC_Z,          KC_X,    KC_C,         KC_V,    KC_B,  KC_FN1,
        CTL_T(), KC_FN2/*LCTL(KC_LALT)*/, KC_RGUI, KC_APP,      ALT_T(),
                                                        KC_PGUP, KC_PGDN,
                                                                 KC_HOME,
                                               KC_SPC,  KC_BSPC, KC_END,
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
 *
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │  Ver  │ Fn1 │ Fn2 │ Fn3 │ Fn4 │ Fn5 │ Fn6 │     │ Fn7 │ Fn8 │ Fn9 │ F10 │ F11 │ F12 │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │ DTTM  │     │ DAT │ Dfm │  (  │  )  │ #%% │     │     │  7  │  8  │  9  │  +  │  -  │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤     │     │     ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │  DAT  │     │ TIM │ NOW │  [  │  ]  ├─────┤     ├─────┤  4  │  5  │  6  │  *  │  /  │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤     │     │     ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │  TIM  │     │ PIP │     │  {  │  }  │     │     │     │  1  │  2  │  3  │  ,  │ Up  │       │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │     │     │     │     │     │                             │  0  │  .  │ Lft │ Dwn │ Rgt │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │ Lft │ Rgt │ │ CLf │ CRt │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │ SHm │ │ PUp │     │     │
 *                             │ Ent │ Bsp ├─────┤ ├─────┤ Del │ Spc │
 *                             │     │     │ SDn │ │ PDn │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
// SYMBOLS M(0) = Version
[NPAD] = KEYMAP(
       // left hand
       M(0),   KC_F1,  	  KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,
       M(10),  KC_TRNS,  M(8),     M(2),     KC_LPRN,  KC_RPRN,  M(3),//KC_QUOT,M(1),
       M(8),   KC_TRNS,  M(9),     M(10),    KC_LBRC,  KC_RBRC,
       M(9),   KC_TRNS,  M(7),     KC_TRNS,  KC_LCBR,  KC_RCBR,  KC_TRNS,
      KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                        KC_LEFT,  KC_RGHT,
                                                                  LSFT(KC_HOME),
                                               KC_ENT,  KC_BSPC,  LSFT(KC_END),

       // right hand
       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
       KC_TILD, KC_7,    KC_8,    KC_9,    KC_PLUS, KC_MINUS,KC_TRNS, 
                KC_4,    KC_5,    KC_6,    KC_ASTR, KC_SLSH, KC_TRNS,
       KC_TRNS, KC_1,    KC_2,    KC_3,    KC_COMM, KC_UP,   KC_TRNS,
                KC_0,    KC_DOT,  KC_LEFT, KC_DOWN, KC_RGHT,
       LCTL(KC_LEFT),     LCTL(KC_RGHT),
       KC_PGUP,
       KC_PGDN,     KC_DELT,  KC_SPC
    ),

/* Keymap 2: Magic Layer
 *
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │ SIGN  │ Fn1 │ Fn2 │ Fn3 │ Fn4 │ Fn5 │ Fn6 │     │ Fn7 │ Fn8 │ Fn9 │ F10 │ F11 │ F12 │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │ DTTM  │ NQr │     │     │  (  │  )  │ #%% │     │     │  7  │  8  │  9  │  +  │  -  │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤     │     │     ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │  DAT  │ LQr │     │     │  [  │  ]  ├─────┤     ├─────┤  4  │  5  │  6  │  *  │  /  │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤     │     │     ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │  TIM  │ SQr │     │     │  {  │  }  │     │     │     │  1  │  2  │  3  │  ,  │ Up  │       │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │     │     │     │     │     │                             │  0  │  .  │ Lft │ Dwn │ Rgt │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │ Lft │ Rgt │ │ CLf │ CRt │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │ SHm │ │ PUp │     │     │
 *                             │ Ent │ Bsp ├─────┤ ├─────┤ Del │ Spc │
 *                             │     │     │ SDn │ │ PDn │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
// MAGI
[MAGI] = KEYMAP(
       // left hand
       M(100),   KC_F1,    KC_F2,     KC_F3,    KC_F4,   KC_F5,   KC_F6,
       M(10),    M(4),     KC_TRNS,   KC_UP,    KC_TRNS, KC_TRNS, KC_TRNS,
       M(8),     M(5),     KC_TRNS,   KC_DOWN,  KC_RGHT, KC_TRNS,
       M(9),     M(6),     KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       	       LSFT(KC_HOME),     LSFT(KC_END),
                                                                  KC_PGUP,
                                               KC_SPC,  KC_BSPC,  KC_PGDN,
       // right hand
       KC_F7,   KC_F8,         KC_F9,        KC_F10,   KC_F11,   KC_F12,   KC_TRNS,
       KC_TRNS, KC_TRNS,       KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                KC_TRNS,       KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,       KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                               KC_TRNS,      KC_TRNS,  KC_COMM,  KC_TRNS,  KC_TRNS,
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


// --- CUSTOM FORMAT STRING ---
#define QUOTE(...) #__VA_ARGS__
const char *sql_query = QUOTE(
    SELECT word_id
    FROM table1, table2
    WHERE table2.word_id = table1.word_id
    ORDER BY table1.word ASC
);

// Python Code Format
#define SIGNITURE "# -*- coding: utf-8 -*- \n"\
"'''\n"\
"\n"\
"Created on \n"\
"\n"\
"@author: Young Ju Kim\n"\
"'''\n"

// Query Strings
#define SQL_NORMAL_STR "SELECT\r\n"\
"     A.col\r\n"\
"    ,A.*\r\n"\
"FROM\r\n"\
"    a.aa A\r\n"\
"WHERE\r\n"\
"    A.col = NULL\r\n"\
"AND A.col <> 1\r\n"\
"AND A.col BETWEEN '01' AND '02'\r\n"


#define SQL_LEFT_STR "SELECT\r\n"\
"     A.*\r\n"\
"    ,B.*\r\n"\
"FROM\r\n"\
"    a.aa A\r\n"\
"    LEFT OUTER JOIN b.bb B\r\n"\
"    ON\r\n"\
"        B.col = A.col --NULL\r\n"\
"    AND B.col = A.col --NULL\r\n"\
"WHERE\r\n"\
"    B.col = NULL\r\n"\
"AND A.col <> 1\r\n"\
"AND A.col BETWEEN '01' AND '02'\r\n"


#define SQL_LEFT_SUB_STR "SELECT\r\n"\
"     A.*\r\n"\
"    ,B.*\r\n"\
"FROM\r\n"\
"    a.aa A\r\n"\
"    LEFT OUTER JOIN\r\n"\
"        (\r\n"\
"        SELECT\r\n"\
"             C.col\r\n"\
"        FROM\r\n"\
"            c.cc C\r\n"\
"        WHERE\r\n"\
"            C.col = NULL\r\n"\
"        ) B\r\n"\
"    ON\r\n"\
"        B.col = A.col --NULL\r\n"\
"    AND B.col = A.col --NULL\r\n"\
"WHERE\r\n"\
"    B.col = NULL\r\n"\
"AND A.col <> 1\r\n"\
"AND A.col BETWEEN '01' AND '02'\r\n"

// pip String
#define PIP_STR "pip install --cert=c:/sslproxy.crt "


#define DATETIME_STR __DATE__ " " __TIME__ 

// DATE to INT Function
char pre_macro_date_to_int(const char *str_pre_macro_date)
{
    const int comfile_date_len = 12;
 
    // error check
    if (NULL == str_pre_macro_date || comfile_date_len - 1 != strlen(str_pre_macro_date))
        return 0;
 
    const char month_names[] = "JanFebMarAprMayJunJulAugSepOctNovDec";
 
    char s_month[5] = {0,};
    int iyear = 0, iday = 0;
 
    sscanf(str_pre_macro_date, "%s %d %d", s_month, &iday, &iyear);
    int imonth = (strstr(month_names, s_month) - month_names) / 3 + 1;

    //snprintf(date_string, 100, "%d", date_int);
    return 10000 * iyear + 100 * imonth + iday;
};


// TIME to INT Functions
int pre_macro_time_to_int(const char *str_pre_macro_time)
{
    const int comfile_time_len = 9;
 
    if (NULL == str_pre_macro_time || comfile_time_len -1 != strlen(str_pre_macro_time))
        return 0;
 
    int ihour = 0, iminute = 0, isec = 0;
    sscanf(str_pre_macro_time, "%d:%d:%d", &ihour, &iminute, &isec);
 
    // 030511
    return ihour * 10000 + iminute * 100 + isec;
};


#define QUOTE(...) #__VA_ARGS__
char *date_str = QUOTE(
"a"
//pre_macro_date_to_int(__DATE__)
);

#define FDATE (char const[]){ __DATE__[7], __DATE__[8]}


// Layer Change
const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(NPAD),                // FN1 - Momentary Layer 1 (Numpad Layer)~
    [2] = ACTION_LAYER_TAP_TOGGLE(MAGI),                // FN2 - Momentary Layer 2 (Magic Layer)~

};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
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
          SEND_STRING ( "# %%" );
        }
        break;
        case 4:
        if (record->event.pressed) { // For resetting EEPROM
          SEND_STRING ( SQL_NORMAL_STR );
        }
        break;
        case 5:
        if (record->event.pressed) { // For resetting EEPROM
          SEND_STRING ( SQL_LEFT_STR );
        }
        break;
        case 6:
        if (record->event.pressed) { // For resetting EEPROM
          SEND_STRING ( SQL_LEFT_SUB_STR );
        }
        break;
        case 7:
        if (record->event.pressed) { // For resetting EEPROM
          SEND_STRING ( PIP_STR );
        }
        break;
        case 8:
        if (record->event.pressed) { // For resetting EEPROM
          SEND_STRING ( __DATE__ );
        }
        break;
        case 9:
        if (record->event.pressed) { // For resetting EEPROM
          SEND_STRING ( __TIME__ );
        }
        break;
        case 10:
        if (record->event.pressed) { // For resetting EEPROM
          SEND_STRING ( DATETIME_STR );
        }
        break;
        case 11:
        if (record->event.pressed) { // For resetting EEPROM
          SEND_STRING ( "" );
        }
        break;
        case 12:
        if (record->event.pressed) { // For resetting EEPROM
          SEND_STRING ( SIGNITURE );
        }
        break;
        case 13:
        if (record->event.pressed) { // For resetting EEPROM
          SEND_STRING ( SIGNITURE );
        }
        break;
        case 14:
        if (record->event.pressed) { // For resetting EEPROM
          SEND_STRING ( SIGNITURE );
        }
        break;
        case 99:
        if (record->event.pressed) { // For resetting EEPROM
          /*char buff[100];
          time_t now = time (0);
          strftime (buff, 100, "%Y-%m-%d %H:%M:%S.000", localtime (&now));
          //printf ("%s\n", buff);*/
          SEND_STRING ( SIGNITURE );
        }
        break;
        case 100:
        if (record->event.pressed) { // For resetting EEPROM
          SEND_STRING ( SIGNITURE );
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
