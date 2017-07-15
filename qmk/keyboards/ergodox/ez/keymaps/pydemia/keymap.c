#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "process_tap_dance.h"

#define WKEY 0 // default layer
#define NPAD 1 // Numpad Layer
#define MAGI 2 // Magic Layer
#define ACTN 3 // Action Layer
#define LKEY 4 // Linux Layer
#define PPTK 5 // Linux Layer

// Layer Change
const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(NPAD),  // FN1 - Momentary Layer 1 (Numpad Layer)~
    [2] = ACTION_LAYER_TAP_TOGGLE(MAGI),  // FN2 - Momentary Layer 2 (Magic Layer)~
    [3] = ACTION_LAYER_TAP_TOGGLE(ACTN),  // FN3 - Momentary Layer 3 (Action Layer)~
    [4] = ACTION_LAYER_TAP_TOGGLE(LKEY),  // FN4 - Momentary Layer 4 (PPT Layer)~

};


#define QMK_VER_KEY     M(0)
#define ASSIGN_R_KEY    M(1)
#define PY_DTFM_KEY     M(2)
#define SPYD_BLOCK_KEY  M(3)
#define SQL_NORMAL_KEY  M(4)
#define SQL_LEFT_KEY    M(5)
#define SQL_LEFTSUB_KEY M(6)
#define PIP_STR_KEY     M(7)
#define DT_STR_KEY      M(8)
#define TM_STR_KEY      M(9)
#define DTTM_STR_KEY    M(10)
#define D_QUOTE_KEY     M(11)
#define CUT_KEY         M(12)
#define COPY_KEY        M(13)
#define PASTE_KEY       M(14)

#define SIGN_KEY        M(100)

// Tap Dance Start ------------------------------------------------------------

//In Layer declaration, add tap dance item in place of a key code

//Tap Dance Declarations
enum {
  ASSIGN_MARK = 0,

  F01,
  F02,
  F03,
  F04,
  F05,
  F06,
  F07,
  F08,
  F09,
  F10,
  F11,
  F12,

  SFT_CAPS,

  CUT,
  COPY,
  PASTE,

  D_QUOTE,

  PGUP_BWEB,
  PGDN_FWEB,
};


//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [ASSIGN_MARK] = ACTION_TAP_DANCE_DOUBLE(KC_EQUAL, ASSIGN_R_KEY),

  [F01] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_F1),
  [F02] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_F2),
  [F03] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_F3),
  [F04] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_F4),
  [F05] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_F5),
  [F06] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_F6),
  [F07] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_F7),
  [F08] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_F8),
  [F09] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_F9),
  [F10] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_F10),
  [F11] = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_F11),
  [F12] = ACTION_TAP_DANCE_DOUBLE(KC_PLUS, KC_F12),

  [SFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),

  [CUT]   = ACTION_TAP_DANCE_DOUBLE(KC_X, CUT_KEY),
  [COPY]  = ACTION_TAP_DANCE_DOUBLE(KC_C, COPY_KEY),
  [PASTE] = ACTION_TAP_DANCE_DOUBLE(KC_V, PASTE_KEY),

  [D_QUOTE] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, LSFT(KC_QUOT)),

  [PGUP_BWEB] = ACTION_TAP_DANCE_DOUBLE(KC_PGUP, LALT(KC_LEFT)),
  [PGDN_FWEB] = ACTION_TAP_DANCE_DOUBLE(KC_PGDN, LALT(KC_RGHT)),
};

// Tap Dance End --------------------------------------------------------------


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
 * │ SftCp │  Z  │  X  │  C  │  V  │  B  │ Npd │     │ Fn5 │  N  │  M  │  ,  │  .  │  /  │ Shift │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │ CTL │ TgM │Wn/Cd│ App │ ALT │                             │ RAt │ RCl │  [  │  ]  │ TgA │
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
KC_ESC,           TD(F01),    TD(F02),    TD(F03),      TD(F04),          TD(F05),          LCTL(KC_F5),         // TG(LKEY),
KC_TAB,           KC_Q,       KC_W,       KC_E,         KC_R,             KC_T,             TD(ASSIGN_MARK),
LT(MAGI, KC_GRV), KC_A,       KC_S,       KC_D,         KC_F,             KC_G,
TD(SFT_CAPS),     KC_Z,       KC_X,       KC_C,         KC_V,             KC_B,             KC_FN1,
CTL_T(KC_LCTL),   KC_FN2,     KC_LGUI,    KC_APP,       ALT_T(KC_LALT),
                                                                        TD(PGUP_BWEB),    TD(PGDN_FWEB),
                                                                        KC_HOME,
                                                      KC_SPC,           KC_BSPC,          KC_END,
// right hand
TD(F06),          TD(F07),    TD(F08),    TD(F09),      TD(F10),          TD(F11),          TD(F12),
ASSIGN_R_KEY,     KC_Y,       KC_U,       KC_I,         KC_O,             KC_P,             KC_BSLS,
                  KC_H,       KC_J,       KC_K,         KC_L,             KC_SCLN,          TD(D_QUOTE),
LCTL(KC_ENT),     KC_N,       KC_M,       KC_COMM,      KC_DOT,           KC_SLSH,          KC_RSFT,
                  KC_RALT,    KC_RCTL,    KC_LBRC,      KC_RBRC,          KC_FN3,
KC_LEFT,          KC_RGHT, 
KC_UP,
KC_DOWN,          KC_DELT,    KC_ENT
),

/* Keymap 1: Numpad Layer
 *
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │  Ver  │     │     │     │     │ #%% │     │     │     │     │     │     │     │     │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │     │DTTM │ Dfm │  (  │  )  │ <-  │     │     │  7  │  8  │  9  │  +  │  -  │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤     │     │     ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │     │ DAT │ NOW │  [  │  ]  ├─────┤     ├─────┤  4  │  5  │  6  │  *  │  /  │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤     │     │     ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │ PIP │ TIM │     │  {  │  }  │     │     │     │  1  │  2  │  3  │  ,  │ Up  │       │
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
QMK_VER_KEY,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,   SPYD_BLOCK_KEY,   KC_TRNS,
KC_TRNS,  KC_TRNS,  DTTM_STR_KEY,     PY_DTFM_KEY,     KC_LPRN,  KC_RPRN,  ASSIGN_R_KEY,//KC_QUOT,M(1),
KC_TRNS,   KC_TRNS,  DT_STR_KEY,     DTTM_STR_KEY,    KC_LBRC,  KC_RBRC,
KC_TRNS,   PIP_STR_KEY,  TM_STR_KEY,     KC_TRNS,  KC_LCBR,  KC_RCBR,  KC_TRNS,
KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                KC_LEFT,  KC_RGHT,
                                                          LSFT(KC_HOME),
                                       KC_ENT,  KC_BSPC,  LSFT(KC_END),

// right hand
KC_TRNS,   KC_TRNS,    KC_TRNS,        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
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
 * │ SIGN  │     │     │     │     │     │     │     │     │     │     │     │     │     │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │  6  │  7  │  8  │  9  │  0  │ #%% │     │     │  7  │  8  │  9  │  +  │  -  │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤     │     │     ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │ DAT │ TIM │DTTM │  [  │  ]  ├─────┤     ├─────┤  4  │  5  │  6  │  *  │  /  │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤     │     │     ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │ SQr │ LQr │ SQr │  {  │  }  │     │     │     │  1  │  2  │  3  │  ,  │ Up  │       │
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
SIGN_KEY,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
KC_TRNS,     KC_6,   KC_7,               KC_8,       KC_9,    KC_0,    KC_TRNS,
KC_TRNS,      DT_STR_KEY,   TM_STR_KEY,          DTTM_STR_KEY,    KC_TRNS, KC_TRNS,
KC_TRNS,      SQL_NORMAL_KEY,   SQL_LEFT_KEY,     SQL_LEFTSUB_KEY,  KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                               	       LSFT(KC_HOME),     LSFT(KC_END),
                                                          KC_PGUP,
                                       KC_SPC,  KC_BSPC,  KC_PGDN,
// right hand
KC_TRNS,   KC_TRNS,         KC_TRNS,        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
KC_TRNS, KC_TRNS,       KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,       KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_TRNS, KC_TRNS,       KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                       KC_TRNS,      KC_TRNS,  KC_COMM,  KC_TRNS,  KC_TRNS,
KC_LEFT,     KC_RGHT,
KC_UP,
KC_DOWN,     KC_DELT,  KC_ENT
),

/* Keymap 3: Action Layer
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
// ACTN
[ACTN] = KEYMAP(  // layer 0 : default
// left hand
TD(0),   KC_1,          KC_2,    KC_3,         KC_4,    KC_5,  LCTL(KC_F5),         // TG(LKEY),
KC_TAB,   KC_Q,          KC_W,    KC_E,         KC_R,    KC_T,  ASSIGN_R_KEY,
KC_GRV,   KC_A,          KC_S,    KC_D,         KC_F,    KC_G,
SFT_T(KC_CAPS),  KC_Z,          KC_X,    KC_C,         KC_V,    KC_B,  KC_FN1,
CTL_T(KC_LCTL), KC_FN2/*LCTL(KC_LALT)*/, KC_LGUI, KC_APP,      ALT_T(KC_LALT),
                                                KC_PGUP, KC_PGDN,
                                                         KC_HOME,
                                       KC_SPC,  KC_BSPC, KC_END,
// right hand
KC_6,                KC_7,           KC_8,     KC_9,                 KC_0,                 KC_MINUS,  KC_PLUS,
LCTL(KC_ENT),        KC_Y,           KC_U,     KC_I,                 KC_O,                 KC_P,      KC_BSLS,
                     KC_H,           KC_J,     KC_K,                 KC_L,                 KC_SCLN,   KC_QUOT,
LCTL(KC_F5),         KC_N,           KC_M,     KC_COMM,              KC_DOT,               KC_SLSH,   KC_RSFT,
                     KC_RALT,        KC_RCTL,  KC_LBRC,              KC_RBRC,              KC_FN3,
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
ASSIGN_R_KEY,            KC_Y,           KC_U,     KC_I,                 KC_O,                 KC_P,      KC_BSLS,
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
ASSIGN_R_KEY,            KC_Y,           KC_U,     KC_I,                 KC_O,                 KC_P,      KC_BSLS,
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


// MACRO START ---------------------------------------------------------------------

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
          //SEND_STRING ( "<-" );
          return MACRO(D(LSFT), T(COMMA), U(LSFT), T(MINUS), END);
        }
        break;
        case 2:
        if (record->event.pressed) { // For resetting EEPROM
          SEND_STRING ( "'%Y%m%d%H%M%S%f'" );
          //return MACRO(D(LSFT), T(COMMA), U(LSFT), T(MINUS), END);
        }
        break;
        case 3:
        if (record->event.pressed) { // For resetting EEPROM
          //SEND_STRING ( "# %%" );
          return MACRO(D(LSFT), T(3), T(SPC), T(5), T(5), U(LSFT), END);
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
          //SEND_STRING ( " );
          return MACRO(D(LSFT), T(QUOT), U(LSFT), END);
        }
        break;
        case 12:
        if (record->event.pressed) { // For resetting EEPROM
          return MACRO(D(RCTL), T(X), U(RCTL), END);
        }
        break;
        case 13:
        if (record->event.pressed) { // For resetting EEPROM
          return MACRO(D(RCTL), T(C), U(RCTL), END);
        }
        break;
        case 14:
        if (record->event.pressed) { // For resetting EEPROM
          return MACRO(D(RCTL), T(V), U(RCTL), END);
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

// MACRO END -----------------------------------------------------------------------


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
