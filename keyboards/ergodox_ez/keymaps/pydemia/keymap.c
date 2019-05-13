#include QMK_KEYBOARD_H
#include "version.h"
#include "action_layer.h"
#include "process_tap_dance.h"
#include "ergodox_ez.h"

#define WKEY 0 // default layer
#define NPAD 1 // Numpad Layer
#define MAGI 2 // Magic Layer
#define ACTN 3 // Action Layer,
#define LCOM 4 // Left Command Layer
#define RESV 5 // Reserved Layer
#define LKEY 6 // Linux Layer
#define PPTK 7 // PPT Layer

// // Layer Change
// const uint16_t PROGMEM fn_actions[] = {
//     [1] = ACTION_LAYER_TAP_TOGGLE(NPAD),  // FN1 - Momentary Layer 1 (Numpad Layer)~
//     [2] = ACTION_LAYER_TAP_TOGGLE(MAGI),  // FN2 - Momentary Layer 2 (Magic Layer)~
//     [3] = ACTION_LAYER_TAP_TOGGLE(ACTN),  // FN3 - Momentary Layer 3 (Action Layer)~
//     [4] = ACTION_LAYER_TAP_TOGGLE(LCMD),  // FN4 - Momentary Layer 4 (MacOS Layer)~
//     [5] = ACTION_LAYER_TAP_TOGGLE(RESV),  // FN5 - Momentary Layer 5 (Reserved Layer)~
//     [6] = ACTION_LAYER_TAP_TOGGLE(LKEY),  // FN6 - Momentary Layer 6 (PPT Layer)~

// };




// Python Code Format
#define SIGNITURE "# -*- coding: utf-8 -*- \n"\
"'''\n"\
"Created  : " __DATE__ " " __TIME__"\n"\
"Modified : " __DATE__ " " __TIME__"\n"\
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

#define SQLCOMMENT

// Macro Key

// MACRO START ---------------------------------------------------------------------


#define QMK_VER_KEY     M(0)
#define SIGN_KEY        M(1)
#define ASSIGN_R_KEY    M(2)
#define PY_DTFM_KEY     M(3)
#define SPYD_CELL_KEY   M(4)
#define R_FOLDING_KEY   M(5)
#define SQL_NORMAL_KEY  M(6)
#define SQL_LEFT_KEY    M(7)
#define SQL_LEFTSUB_KEY M(8)
#define PIP_STR_KEY     M(9)
#define DT_STR_KEY      M(10)
#define TM_STR_KEY      M(11)
#define DTTM_STR_KEY    M(12)
#define D_QUOTE_KEY     M(13)
#define BRC_KEY         M(14)
#define CBR_KEY         M(15)
#define PRN_KEY         M(16)
#define HOME_SFT_KEY    M(17)
#define END_SFT_KEY     M(18)
#define SQLCOMMENT_KEY  M(19)

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt )
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
          SEND_STRING ( SIGNITURE );
        }
        break;
        case 2:
        if (record->event.pressed) { // <-
          //SEND_STRING ( "<-" );
          return MACRO(D(LSFT), T(COMMA), U(LSFT), T(MINUS), END);
        }
        break;
        case 3:
        if (record->event.pressed) { // '%Y%m%d%H%M%S%f'
          SEND_STRING ( "'%Y%m%d%H%M%S%f'" );
          //return MACRO(D(LSFT), T(COMMA), U(LSFT), T(MINUS), END);
        }
        break;
        case 4:
        if (record->event.pressed) { // # %% (For Python Spyder)
          //SEND_STRING ( "# %%" );
          return MACRO(D(LSFT), T(3), T(SPC), T(5), T(5), U(LSFT), END);
        }
        break;
        case 5:
        if (record->event.pressed) { // # %% (For Python Spyder)
          //SEND_STRING ( "# %%" );
          return MACRO( D(LSFT), T(3), U(LSFT), T(SPC), T(SPC), T(MINUS), T(MINUS), T(MINUS), T(MINUS),
                        T(LEFT), T(LEFT), T(LEFT), T(LEFT), T(LEFT), END);
        }
        break;
        case 6:
        if (record->event.pressed) { // For resetting EEPROM
          SEND_STRING ( SQL_NORMAL_STR );
        }
        break;
        case 7:
        if (record->event.pressed) { // For resetting EEPROM
          SEND_STRING ( SQL_LEFT_STR );
        }
        break;
        case 8:
        if (record->event.pressed) { // For resetting EEPROM
          SEND_STRING ( SQL_LEFT_SUB_STR );
        }
        break;
        case 9:
        if (record->event.pressed) { // For resetting EEPROM
          SEND_STRING ( PIP_STR );
        }
        break;
        case 10:
        if (record->event.pressed) { // For resetting EEPROM
          SEND_STRING ( __DATE__ );
        }
        break;
        case 11:
        if (record->event.pressed) { // For resetting EEPROM
          SEND_STRING ( __TIME__ );
        }
        break;
        case 12:
        if (record->event.pressed) { // For resetting EEPROM
          SEND_STRING ( DATETIME_STR );
        }
        break;
        case 13:
        if (record->event.pressed) { // For resetting EEPROM
          //SEND_STRING ( " );
          return MACRO(D(LSFT), T(QUOT), U(LSFT), END);
        }
        break;
        case 14:
        if (record->event.pressed) { // For resetting EEPROM
          return MACRO( T(LBRC), T(RBRC), T(LEFT), END );
        }
        break;
        case 15:
        if (record->event.pressed) { // For resetting EEPROM
          return MACRO( D(LSFT), T(LBRC), T(RBRC), U(LSFT), T(LEFT), END );
          //return MACRO( T(LCBR), T(RCBR), T(LEFT), END );
        }
        break;
        case 16:
        if (record->event.pressed) { // For resetting EEPROM
          return MACRO( D(LSFT), T(9), T(0), U(LSFT), T(LEFT), END );
        }
        break;
        case 17:
        if (record->event.pressed) { // For resetting EEPROM
          return MACRO( D(LSFT), T(HOME), U(LSFT), END );
        }
        break;
        case 18:
        if (record->event.pressed) { // For resetting EEPROM
          return MACRO( D(LSFT), T(END), U(LSFT), END );
        }
        break;
        case 19:
        if (record->event.pressed) { // For resetting EEPROM
          return MACRO( T(SLSH), D(LSFT), T(8), U(LSFT), T(ENTER), T(ENTER), D(LSFT), T(8), U(LSFT), T(SLSH), T(UP), END );
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



// Tap Dance Key
#define ASSIGN_TAP     TD(ASSIGN_MARK)
#define F01_TAP        TD(F01)
#define F02_TAP        TD(F02)
#define F03_TAP        TD(F03)
#define F04_TAP        TD(F04)
#define F05_TAP        TD(F05)
#define F06_TAP        TD(F06)
#define F07_TAP        TD(F07)
#define F08_TAP        TD(F08)
#define F09_TAP        TD(F09)
#define F10_TAP        TD(F10)
#define F11_TAP        TD(F11)
#define F12_TAP        TD(F12)

#define CUT_TAP        TD(CUT)
#define COPY_TAP       TD(COPY)
#define PASTE_TAP      TD(PASTE)

#define D_QUOTE_TAP    TD(D_QUOTE)

#define PGUP_BWEB_TAP  TD(PGUP_BWEB)
#define PGDN_FWEB_TAP  TD(PGDN_FWEB)
/*
#define T_DBRC_TAP     TD(T_DBRC)
#define G_DCBR_TAP     TD(G_DCBR)
#define B_DPRN_TAP     TD(B_DPRN)
*/
#define J_DBRC_TAP     TD(J_DBRC)
#define K_DCBR_TAP     TD(K_DCBR)
#define L_DPRN_TAP     TD(L_DPRN)


// Tap Dance Start ------------------------------------------------------------

//In Layer declaration, add tap dance item in place of a key code



// CUSTOM KEYMAP START -----------------------------------------------------

// T & []
void dance_press_t (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {

    register_code(KC_T);
    unregister_code(KC_T);

  } else {
    clear_keyboard_but_mods();
  }
}
void dance_dbrc (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {

    register_code(KC_LBRC);
    unregister_code(KC_LBRC);

    register_code(KC_RBRC);
    unregister_code(KC_RBRC);

    register_code(KC_LEFT);
    unregister_code(KC_LEFT);

  } else {
    clear_keyboard_but_mods();
  }
}
/*
// G & {}
void dance_press_g (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {

    register_code(KC_G);
    unregister_code(KC_G);

  } else {
    clear_keyboard_but_mods();
  }
}
void dance_dcbr (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {

    register_code(KC_LSFT);
    register_code(KC_LBRC);
    unregister_code(KC_LBRC);

    register_code(KC_RBRC);
    unregister_code(KC_RBRC);
    unregister_code(KC_LSFT);

    register_code(KC_LEFT);
    unregister_code(KC_LEFT);

  } else {
    clear_keyboard_but_mods();
  }
}

// B & ()
void dance_press_b (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {

    register_code(KC_B);
    unregister_code(KC_B);

  } else {
    clear_keyboard_but_mods();
  }
}
void dance_dprn (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {

    register_code(KC_LSFT);
    register_code(KC_9);
    unregister_code(KC_9);

    register_code(KC_0);
    unregister_code(KC_0);
    unregister_code(KC_LSFT);

    register_code(KC_LEFT);
    unregister_code(KC_LEFT);

  } else {
    clear_keyboard_but_mods();
  }
}
*/

// = & <-
void dance_press_equal (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {

    register_code(KC_EQUAL);
    unregister_code(KC_EQUAL);

  } else {
    clear_keyboard_but_mods();
  }
}
void dance_press_rassign (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {

    register_code(KC_LSFT);
    register_code(KC_COMMA);
    unregister_code(KC_COMMA);
    unregister_code(KC_LSFT);

    register_code(KC_MINUS);
    unregister_code(KC_MINUS);

  } else {
    clear_keyboard_but_mods();
  }
}

// = & <-
void dance_press_home (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {

    register_code(KC_HOME);
    unregister_code(KC_HOME);

  } else {
    clear_keyboard_but_mods();
  }
}
void dance_press_shifthome (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {

    register_code(KC_LSFT);
    register_code(KC_HOME);
    unregister_code(KC_HOME);
    unregister_code(KC_LSFT);

  } else {
    clear_keyboard_but_mods();
  }
}


// = & <-
void dance_press_end (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {

    register_code(KC_END);
    unregister_code(KC_END);

  } else {
    clear_keyboard_but_mods();
  }
}
void dance_press_shiftend (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {

    register_code(KC_LSFT);
    register_code(KC_END);
    unregister_code(KC_END);
    unregister_code(KC_LSFT);

  } else {
    clear_keyboard_but_mods();
  }
}
// CUSTOM KEYMAP END -------------------------------------------------------



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

  D_QUOTE,

  PGUP_BWEB,
  PGDN_FWEB,
/*
  T_DBRC,
  G_DCBR,
  B_DPRN,
*/
  HOME_SFT,
  END_SFT,

  J_DBRC,
  K_DCBR,
  L_DPRN
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {

  [ASSIGN_MARK] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_press_equal, dance_press_rassign),

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

  [D_QUOTE] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, LSFT(KC_QUOT)),

  [PGUP_BWEB] = ACTION_TAP_DANCE_DOUBLE(KC_PGUP, LALT(KC_LEFT)),
  [PGDN_FWEB] = ACTION_TAP_DANCE_DOUBLE(KC_PGDN, LALT(KC_RGHT)),
/*
  [T_DBRC] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_press_t, dance_dbrc),
  [G_DCBR] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_press_g, dance_dcbr),
  [B_DPRN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_press_b, dance_dprn),
*/
  [HOME_SFT] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, LSFT(KC_HOME)),
  [END_SFT]  = ACTION_TAP_DANCE_DOUBLE(KC_END, LSFT(KC_END)),

  [J_DBRC] = ACTION_TAP_DANCE_DOUBLE(KC_J, BRC_KEY),
  [K_DCBR] = ACTION_TAP_DANCE_DOUBLE(KC_K, CBR_KEY),
  [L_DPRN] = ACTION_TAP_DANCE_DOUBLE(KC_L, PRN_KEY),

};

// Tap Dance End --------------------------------------------------------------


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic layer
 *
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │  Esc  │  1  │  2  │  3  │  4  │  5  │CtFn5│     │  6  │  7  │  8  │  9  │  0  │  -  │   +   │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │  Tab  │  Q  │  W  │  E  │  R  │ T[] │ Tg  │     │  <- │  Y  │  U  │  I  │  O  │  P  │   \   │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤ Lcm │     │  =  ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │   ~   │  A  │  S  │  D  │  F  │ G{} ├─────┤     ├─────┤  H  │ J[] │ K{} │ L() │  ;  │  ' "  │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤ Tg  │     │     ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │  Sft  │  Z  │  X  │  C  │  V  │ B() │ Npd │     │     │  N  │  M  │  ,  │  .  │  /  │ Shift │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │ CTL │ App │Wn/Cd│ TgA │ ALT │                             │ RAt │ RCl │  [  │  ]  │ ( ) │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │ TgM │CtEnt│ │ Lft │ Rgt │
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
[WKEY] = LAYOUT_ergodox(  // layer 0 : default
// left hand
KC_ESC,           KC_1,           KC_2,           KC_3,         KC_4,           KC_5,       LCTL(KC_F5), // TG(LKEY),
KC_TAB,           KC_Q,           KC_W,           KC_E,         KC_R,           KC_T,       TT(LCOM),
KC_GRV,           KC_A,           KC_S,           KC_D,         KC_F,           KC_G,
KC_LSFT,          KC_Z,           KC_X,           KC_C,         KC_V,           KC_B,        TT(NPAD),
CTL_T(KC_LCTL),   KC_APP,         KC_LGUI,         TT(ACTN),       ALT_T(KC_LALT),
                                                                         TT(MAGI),           LCTL(KC_ENT),
                                                                                          KC_HOME,
                                                      KC_SPC,           KC_BSPC,          KC_END,
// right hand
KC_6,             KC_7,       KC_8,       KC_9,         KC_0,             KC_MINUS,         KC_PLUS,
ASSIGN_TAP,       KC_Y,       KC_U,       KC_I,         KC_O,             KC_P,             KC_BSLS,
                  KC_H,       KC_J,       KC_K,         KC_L,             KC_SCLN,          D_QUOTE_TAP,
TT(LCOM),           KC_N,       KC_M,       KC_COMM,      KC_DOT,           KC_SLSH,          KC_RSFT,
                  KC_RALT,    KC_RCTL,    KC_LBRC,      KC_RBRC,          M(16),// TT(ACTN),
KC_LEFT,          KC_RGHT,
KC_UP,
KC_DOWN,          KC_DELT,    KC_ENT
),

/* Keymap 1: Numpad Layer
 *
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │       │     │     │ Dfm │ #-- │ #%% │     │     │Calc │     │     │     │     │     │ PrScr │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │     │     │ ( ) │  (  │  )  │     │     │ <-  │  7  │  8  │  9  │  +  │  -  │ MyCom │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤     │     │     ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │     │     │ [ ] │  [  │  ]  ├─────┤     ├─────┤  4  │  5  │  6  │  *  │  /  │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤     │     │  -  ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │     │     │ { } │  {  │  }  │     │     │     │  1  │  2  │  3  │  ,  │ Up  │       │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │     │     │     │     │     │                             │  0  │  .  │ Lft │ Dwn │ Rgt │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │     │AlEnt│ │ CLf │ CRt │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │ SHm │ │ PUp │     │     │
 *                             │ Spc │ Bsp ├─────┤ ├─────┤ Del │ Ent │
 *                             │     │     │ SDn │ │ PDn │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
// SYMBOLS M(0) = Version
[NPAD] = LAYOUT_ergodox( //QMK_VER_KEY
//SQLCOMMENT_KEY, SQL_NORMAL_KEY, SQL_LEFT_KEY, SQL_LEFTSUB_KEY
// left hand
KC_TRNS,        KC_TRNS,      KC_TRNS,        PY_DTFM_KEY,    R_FOLDING_KEY,   SPYD_CELL_KEY,   KC_TRNS,
KC_TRNS,        KC_TRNS,      KC_TRNS,        M(16),          KC_LPRN,         KC_RPRN,         KC_TRNS,//KC_QUOT,M(1),
KC_TRNS,        KC_TRNS,      KC_TRNS,        M(14),          KC_LBRC,         KC_RBRC,
KC_TRNS,        KC_TRNS,      KC_TRNS,        M(15),          KC_LCBR,         KC_RCBR,         KC_TRNS,
KC_TRNS,        KC_TRNS,      KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                        KC_TRNS,         LALT(KC_ENT),
                                                                                                         LSFT(KC_HOME),
                                                                       KC_SPC,          KC_BSPC,         LSFT(KC_END),

// right hand
KC_CALC,          KC_TRNS,           KC_TRNS,        KC_TRNS,          KC_TRNS,         KC_TRNS,         KC_PSCREEN,
ASSIGN_R_KEY,     KC_7,              KC_8,           KC_9,             KC_PLUS,         KC_MINUS,        KC_MYCM,
                  KC_4,              KC_5,           KC_6,             KC_ASTR,         KC_SLSH,         KC_TRNS,
KC_MINUS,         KC_1,              KC_2,           KC_3,             KC_COMM,         KC_UP,           KC_TRNS,
                  KC_0,              KC_DOT,         KC_LEFT,          KC_DOWN,         KC_RGHT,
LCTL(KC_LEFT),    LCTL(KC_RGHT),
KC_PGUP,
KC_PGDN,          KC_DELT,           KC_ENT
),


/* Keymap 2: Magic Layer
 *
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │ SIGN  │  1  │  2  │  3  │  4  │  5  │     │     │Calc │     │     │     │     │     │ PrScr │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │  6  │  7  │  8  │  9  │  0  │     │     │  +  │  7  │  8  │  9  │  +  │  -  │ MyCom │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤     │     │     ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │     │     │     │     │     ├─────┤     ├─────┤  4  │  5  │  6  │  *  │  /  │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤     │     │  -  ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │     │     │     │     │     │     │     │     │  1  │  2  │  3  │  ,  │ Up  │       │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │     │     │     │     │     │                             │  0  │  .  │ Lft │ Dwn │ Rgt │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │     │AlEnt│ │ CLf │ CRt │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │ SHm │ │ PUp │     │     │
 *                             │ Ent │ Bsp ├─────┤ ├─────┤ Del │ Spc │
 *                             │     │     │ SDn │ │ PDn │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
// MAGI
[MAGI] = LAYOUT_ergodox(
// left hand
SIGN_KEY,     KC_1,          KC_2,          KC_3,          KC_4,        KC_5,          KC_TRNS,
KC_TRNS,      KC_6,          KC_7,          KC_8,          KC_9,        KC_0,          KC_TRNS,
KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,     KC_TRNS,
KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,     KC_TRNS,       KC_TRNS,
KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
                               	                                                   KC_TRNS,           LALT(KC_ENT),
                                                                                                      KC_PGUP,
                                                                     KC_SPC,       KC_BSPC,           KC_PGDN,
// right hand
KC_CALC,          KC_TRNS,           KC_TRNS,        KC_TRNS,          KC_TRNS,         KC_TRNS,         KC_PSCREEN,
KC_PLUS,          KC_7,              KC_8,           KC_9,             KC_PLUS,         KC_MINUS,        KC_MYCM,
                  KC_4,              KC_5,           KC_6,             KC_ASTR,         KC_SLSH,         KC_TRNS,
KC_MINUS,         KC_1,              KC_2,           KC_3,             KC_COMM,         KC_UP,           KC_TRNS,
                  KC_0,              KC_DOT,         KC_LEFT,          KC_DOWN,         KC_RGHT,
KC_LEFT,          KC_RGHT,
KC_UP,
KC_DOWN,          KC_DELT,          KC_ENT
),

/* Keymap 3: Action Layer
 *
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │ QMKVer│ F1  │ F2  │ F3  │ F4  │ F5  │     │     │     │     │     │     │     │     │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │ F6  │ F7  │ F8  │ F9  │ F10 │     │     │     │     │     │     │     │     │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤     │     │     ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │ F11 │ F12 │ F13 │ F14 │ F15 ├─────┤     ├─────┤     │     │     │     │     │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤     │     │     ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │     │     │     │     │     │     │     │     │     │     │     │     │     │       │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │     │     │     │     │     │                             │     │     │     │     │     │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │     │     │ │ CLf │ CRt │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │ Ctl │ Alt │ Hom │ │ PUp │     │     │
 *                             │ Ent │ Ent ├─────┤ ├─────┤ Del │ Spc │
 *                             │     │     │ End │ │ PDn │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
// ACTN
[ACTN] = LAYOUT_ergodox(
// left hand
QMK_VER_KEY,   KC_F1,             KC_F2,          KC_F3,           KC_F4,           KC_F5,             KC_TRNS,
KC_TRNS,       KC_F6,             KC_F7,          KC_F8,           KC_F9,           KC_F10,            KC_TRNS,
KC_TRNS,       KC_F11,            KC_F12,         KC_F13,          KC_F14,          KC_F15,
KC_TRNS,       KC_TRNS,           KC_TRNS,        KC_TRNS,         KC_TRNS,         KC_TRNS,           KC_TRNS,
KC_TRNS,       KC_TRNS,           KC_TRNS,        KC_TRNS,         KC_TRNS,
                               	                                                    KC_TRNS,           KC_TRNS,
                                                                                                       KC_HOME,
                                                                   CTL_T(KC_ENT),    ALT_T(KC_ENT),           KC_END,
// right hand
KC_TRNS,   KC_TRNS,         KC_TRNS,        KC_PAUSE,   KC_TRNS,   KC_TRNS,   KC_TRNS,
KC_TRNS, KC_TRNS,       KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,       KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_TRNS, KC_TRNS,       KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                       KC_TRNS,      KC_TRNS,  KC_COMM,  KC_TRNS,  KC_TRNS,
KC_LEFT,     KC_RGHT,
KC_UP,
KC_DOWN,     KC_DELT,  KC_ENT
),
/* Keymap 4: Lcmd Layer
 *
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │  Esc  │  1  │  2  │  3  │  4  │  5  │CtFn5│     │  6  │  7  │  8  │  9  │  0  │  -  │   +   │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │  Tab  │  Q  │  W  │  E  │  R  │ T[] │  <- │     │ Tg  │  Y  │  U  │  I  │  O  │  P  │   \   │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤  =  │     │ Mgc ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │   ~   │  A  │  S  │  D  │  F  │ G{} ├─────┤     ├─────┤  H  │ J[] │ K{} │ L() │  ;  │  ' "  │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤ Tg  │     │     ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │  Sft  │  Z  │  X  │  C  │  V  │ B() │ Npd │     │     │  N  │  M  │  ,  │  .  │  /  │ Shift │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │ Cmd │CtCmd│ Ctl │ App │ ALT │                             │CdSpc│ RCl │  [  │  ]  │ ( ) │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │ TgA │CtEnt│ │ Lft │ Rgt │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │ Hom │ │ Up  │     │     │
 *                             │ Spc │ Bsp ├─────┤ ├─────┤ Del │ Ent │
 *                             │     │     │ End │ │ Dwn │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
// LCMD
[LCOM] = LAYOUT_ergodox(
// left hand
KC_ESC,           KC_1,           KC_2,           KC_3,         KC_4,           KC_5,       LSFT(KC_ENT), // TG(LKEY),
KC_TAB,           KC_Q,           KC_W,           KC_E,         KC_R,           KC_T,       ASSIGN_TAP,
KC_GRV,           KC_A,           KC_S,           KC_D,         KC_F,           KC_G,
KC_LSFT,          KC_Z,           KC_X,           KC_C,         KC_V,           KC_B,        TT(NPAD),
CTL_T(KC_LCTL),   KC_TRNS,        KC_LGUI,        KC_APP,       ALT_T(KC_LALT),
                                                                         TT(ACTN),           LCTL(KC_ENT),
                                                                                          KC_HOME,
                                                      KC_SPC,           KC_BSPC,          KC_END,
// right hand
KC_6,             KC_7,           KC_8,       KC_9,         KC_0,             KC_MINUS,         KC_PLUS,
KC_TRNS,          KC_Y,           KC_U,       KC_I,         KC_O,             KC_P,             KC_BSLS,
                  KC_H,           KC_J,       KC_K,         KC_L,             KC_SCLN,          D_QUOTE_TAP,
KC_TRNS,          KC_N,           KC_M,       KC_COMM,      KC_DOT,           KC_SLSH,          KC_RSFT,
                  KC_RALT,        KC_RGUI,    KC_LBRC,      KC_RBRC,          M(16),// TT(ACTN),
KC_LEFT,          KC_RGHT,
KC_UP,
KC_DOWN,          KC_DELT,    KC_ENT
),
/* Keymap 5: Reserved Layer
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
// RESV
[RESV] = LAYOUT_ergodox(  // layer 0 : default
// left hand
TD(0),    KC_1,          KC_2,    KC_3,         KC_4,    KC_5,  LCTL(KC_F5),         // TG(LKEY),
KC_TAB,   KC_Q,          KC_W,    KC_E,         KC_R,    KC_T,  ASSIGN_R_KEY,
KC_GRV,   KC_A,          KC_S,    KC_D,         KC_F,    KC_G,
SFT_T(KC_CAPS),  KC_Z,          KC_X,    KC_C,         KC_V,    KC_B,   TT(NPAD),
CTL_T(KC_LCTL),  TT(MAGI)/*LCTL(KC_LALT)*/, KC_LGUI, KC_APP,      ALT_T(KC_LALT),
                                                KC_PGUP, KC_PGDN,
                                                         KC_HOME,
                                       KC_SPC,  KC_BSPC, KC_END,
// right hand
KC_6,                KC_7,           KC_8,     KC_9,                 KC_0,                 KC_MINUS,  KC_PLUS,
LCTL(KC_ENT),        KC_Y,           KC_U,     KC_I,                 KC_O,                 KC_P,      KC_BSLS,
                     KC_H,           KC_J,     KC_K,                 KC_L,                 KC_SCLN,   KC_QUOT,
LCTL(KC_F5),         KC_N,           KC_M,     KC_COMM,              KC_DOT,               KC_SLSH,   KC_RSFT,
                     KC_RALT,        KC_RCTL,  KC_LBRC,              KC_RBRC,              M(16),// TT(ACTN),
KC_LEFT,     KC_RGHT,
KC_UP,
KC_DOWN,     KC_DELT,  KC_ENT
),
/* Keymap 6: Linux Key layer
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
[LKEY] = LAYOUT_ergodox(  // layer 0 : default
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
                     KC_RALT,        LSFT(KC_SPC),  KC_LBRC,              KC_RBRC,               TT(NPAD),
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
[PPTK] = LAYOUT_ergodox(  // layer 0 : default
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
                     KC_RALT,        LSFT(KC_SPC),  KC_LBRC,              KC_RBRC,               TT(NPAD),
KC_LEFT,     KC_RGHT,
KC_UP,
KC_DOWN,     KC_DELT,  KC_ENT
),
};

// /* Keymap 4: Mac OS Layer
//  *
//  * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
//  * │  Esc  │  1  │  2  │  3  │  4  │  5  │CtFn5│     │  6  │  7  │  8  │  9  │  0  │  -  │   +   │
//  * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
//  * │  Tab  │  Q  │  W  │  E  │  R  │ T[] │  <- │     │ Tg  │  Y  │  U  │  I  │  O  │  P  │   \   │
//  * ├───────┼─────┼─────┼─────┼─────┼─────┤  =  │     │ Mgc ├─────┼─────┼─────┼─────┼─────┼───────┤
//  * │   ~   │  A  │  S  │  D  │  F  │ G{} ├─────┤     ├─────┤  H  │ J[] │ K{} │ L() │  ;  │  ' "  │
//  * ├───────┼─────┼─────┼─────┼─────┼─────┤ Tg  │     │     ├─────┼─────┼─────┼─────┼─────┼───────┤
//  * │  Sft  │  Z  │  X  │  C  │  V  │ B() │ Npd │     │     │  N  │  M  │  ,  │  .  │  /  │ Shift │
//  * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
//  *   │ Cmd │CtCmd│ Ctl │ App │ ALT │                             │CdSpc│ RCl │  [  │  ]  │ ( ) │
//  *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
//  *                                   │ TgA │CtEnt│ │ Lft │ Rgt │
//  *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
//  *                             │     │     │ Hom │ │ Up  │     │     │
//  *                             │ Spc │ Bsp ├─────┤ ├─────┤ Del │ Ent │
//  *                             │     │     │ End │ │ Dwn │     │     │
//  *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
//  */
// // MOSL
// [MOSL] = LAYOUT_ergodox(
// // left hand
// KC_ESC,           KC_1,           KC_2,           KC_3,         KC_4,           KC_5,       LSFT(KC_ENT), // TG(LKEY),
// KC_TAB,           KC_Q,           KC_W,           KC_E,         KC_R,           KC_T,       ASSIGN_TAP,
// KC_GRV,           KC_A,           KC_S,           KC_D,         KC_F,           KC_G,
// KC_LSFT,          KC_Z,           KC_X,           KC_C,         KC_V,           KC_B,        TT(NPAD),
// CTL_T(KC_LCTL),   KC_TRNS,        KC_LGUI,        KC_APP,       ALT_T(KC_LALT),
//                                                                          TT(ACTN),           LCTL(KC_ENT),
//                                                                                           KC_HOME,
//                                                       KC_SPC,           KC_BSPC,          KC_END,
// // right hand
// KC_6,             KC_7,           KC_8,       KC_9,         KC_0,             KC_MINUS,         KC_PLUS,
// KC_TRNS,          KC_Y,           KC_U,       KC_I,         KC_O,             KC_P,             KC_BSLS,
//                   KC_H,           KC_J,       KC_K,         KC_L,             KC_SCLN,          D_QUOTE_TAP,
// KC_TRNS,          KC_N,           KC_M,       KC_COMM,      KC_DOT,           KC_SLSH,          KC_RSFT,
//                   KC_RALT,        KC_RGUI,    KC_LBRC,      KC_RBRC,          M(16),// TT(ACTN),
// KC_LEFT,          KC_RGHT,
// KC_UP,
// KC_DOWN,          KC_DELT,    KC_ENT
// ),
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
            ergodox_right_led_2_off();
            ergodox_right_led_3_off();
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_1_off();
            ergodox_right_led_3_off();
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_1_off();
            ergodox_right_led_2_off();
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_3_off();
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }
}
