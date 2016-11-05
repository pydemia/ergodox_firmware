#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define WKEY 0 // default layer
#define SYMB 1 // SYMBOLS
#define NPAD 2 // Numpad
#define LKEY 3 // Linux
#define PPTK 4 // PPT

#define EPRM M(1) // Macro 1: Reset EEPROM

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |   =  |           |   6  |   7  |   8  |   9  |   0  |   -  |   +    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |  Tg  |           |  Tg  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------| Npad |           | Symb |------+------+------+------+------+--------|
 * |   ~    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|   '    |
 * |--------+------+------+------+------+------|  Tg  |           |CtrlF5|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | LKEY |           |      |   N  |   M  |   ,  |   .  | //Up | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl |CtlAlt|Wn/Cmd| Men |  LAlt |                                       | RAlt | RCtl | [/Lf | ]Dwm | TgPT |
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
[WKEY] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,   KC_1,          KC_2,    KC_3,         KC_4,    KC_5,  KC_EQUAL,
        KC_TAB,   KC_Q,          KC_W,    KC_E,         KC_R,    KC_T,  TG(NPAD),
        KC_GRV,   KC_A,          KC_S,    KC_D,         KC_F,    KC_G,
        KC_LSFT,  KC_Z,          KC_X,    KC_C,         KC_V,    KC_B,  TG(LKEY),
        KC_LCTRL, LCTL(KC_LALT), KC_LGUI, KC_MENU,      KC_LALT,
                                                        KC_HOME, KC_END,
                                                                 KC_PGUP,
                                               KC_SPC,  KC_BSPC, KC_PGDN,
        // right hand
        KC_6,                KC_7,           KC_8,     KC_9,                 KC_0,                 KC_MINUS,  KC_PLUS,
        TG(SYMB),            KC_Y,           KC_U,     KC_I,                 KC_O,                 KC_P,      KC_BSLS,
                             KC_H,           KC_J,     KC_K,                 KC_L,                 KC_SCLN,   KC_QUOT,
        LCTL(KC_F5),         KC_N,           KC_M,     KC_COMM,              KC_DOT,               KC_SLSH,   KC_RSFT,
                             KC_RALT,        KC_RCTL,  KC_LBRC,              KC_RBRC,              TG(PPTK),
        KC_LEFT,     KC_RGHT, 
        KC_UP,
        KC_DOWN,     KC_DELT,  KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |   &  |   *  |   [  |   ]  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   +  |   -  |   *  |   /  |   |  |------|           |------|   <  |   >  |  =   |   (  |   )  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   <  |   >  |   =  |   %  |   &  |      |           |      |      |      |      |   {  |   }  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM |      |      |      |      |                                       |      |   .  |   ,  |   =  |       |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Home | End  |       | Left | Right|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | PgUp |       |  Up  |        |      |
 *                                 | Space|Backsp|------|       |------|  Del   |Enter |
 *                                 |      |ace   | PgDn |       | Down |        |      |
 *                                 `--------------------'       `----------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_ESC,   KC_F1,           KC_F2,        KC_F3,   KC_F4,  KC_F5,   KC_F6,
       KC_TRNS,KC_EXLM,         KC_AT,        KC_HASH, KC_DLR, KC_PERC, KC_TRNS,
       KC_TRNS,KC_PLUS,         KC_MINUS,     KC_ASTR, KC_SLSH,KC_PIPE,
       KC_TRNS,LSFT(KC_COMM),   LSFT(KC_DOT), KC_EQL,  KC_PERC,KC_AMPR, KC_TRNS,
          EPRM,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       			KC_HOME, KC_END,
                                                                 KC_PGUP,
                                               KC_SPC,  KC_BSPC, KC_PGDN,
       // right hand
       KC_F7,   KC_F8,         KC_F9,        KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
       KC_TRNS, KC_CIRC,       KC_AMPR,      KC_ASTR, KC_LBRC, KC_RBRC, KC_TRNS,
                LSFT(KC_COMM), LSFT(KC_DOT), KC_EQL,  KC_LPRN, KC_RPRN, KC_TRNS,
       KC_TRNS, KC_TRNS,       KC_TRNS,      KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS,
                               KC_TRNS,      KC_DOT,  KC_COMM, KC_EQL,  KC_TRNS,
       KC_LEFT,     KC_RGHT,
       KC_UP,
       KC_DOWN,     KC_DELT,  KC_ENT
    ),
/* Keymap 2: Numpad Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   +    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   7  |   8  |   9  |   [  |   ]  |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------|   4  |   5  |   6  |   (  |   )  |   *    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   1  |   2  |   3  |   ,  |  Up  |   /    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM |      |      |      |      |                                       |   0  |   .  | Left | Down | Right |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Home | End  |       | Left | Right|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | PgUp |       |  Up  |        |      |
 *                                 | Space|Backsp|------|       |------|  Del   |Enter |
 *                                 |      |ace   | PgDn |       | Down |        |      |
 *                                 `--------------------'       `----------------------'
 */
// SYMBOLS M(0) = Version
[NPAD] = KEYMAP(
       // left hand
       KC_ESC,   KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
       KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
       KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
       KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,
          EPRM, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                       			KC_HOME, KC_END,
                                                                 KC_PGUP,
                                               KC_SPC,  KC_BSPC, KC_PGDN,
       // right hand
       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PLUS,
       KC_TRNS, KC_7,    KC_8,    KC_9,    KC_LBRC, KC_RBRC, KC_MINUS, 
                KC_4,    KC_5,    KC_6,    KC_LPRN, KC_RPRN, KC_ASTR,
       KC_TRNS, KC_1,    KC_2,    KC_3,    KC_COMM, KC_UP,   KC_SLSH,
                KC_0,    KC_DOT,  KC_LEFT, KC_DOWN, KC_RGHT,
       KC_LEFT,     KC_RGHT,
       KC_UP,
       KC_DOWN,     KC_DELT,  KC_ENT
    ),
/* Keymap 3: Linux Key layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |   =  |           |   6  |   7  |   8  |   9  |   0  |   -  |   +    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   ~    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|   '    |
 * |--------+------+------+------+------+------|      |           |CtrlF5|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  | //Up | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl |CtlAlt|Wn/Cmd| Men |  LAlt |                                       | ShSp | RCtl | [/Lf | ]Dwm | Sm/Rt |
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

[LKEY] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,   KC_1,          KC_2,    KC_3,         KC_4,    KC_5,  LSFT(KC_EQL),
        KC_TAB,   KC_Q,          KC_W,    KC_E,         KC_R,    KC_T,  KC_TRNS,
        KC_GRV,   KC_A,          KC_S,    KC_D,         KC_F,    KC_G,
        KC_LSFT,  KC_Z,          KC_X,    KC_C,         KC_V,    KC_B,  KC_TRNS,
        KC_LCTRL, LCTL(KC_LALT), KC_LGUI, KC_MENU,      KC_LALT,
                                                        KC_HOME, KC_END,
                                                                 KC_PGUP,
                                               KC_SPC,  KC_BSPC, KC_PGDN,
        // right hand
        KC_6,                KC_7,           KC_8,     KC_9,                 KC_0,                 KC_MINUS,  KC_PLUS,
        TG(SYMB),            KC_Y,           KC_U,     KC_I,                 KC_O,                 KC_P,      KC_BSLS,
                             KC_H,           KC_J,     KC_K,                 KC_L,                 KC_SCLN,   KC_QUOT,
        LCTL(KC_F5),         KC_N,           KC_M,     KC_COMM,              KC_DOT,               KC_SLSH,   KC_RSFT,
                             LSFT(KC_SPC),   KC_RCTL,  KC_LBRC,              KC_RBRC,              SYMB,
        KC_LEFT,     KC_RGHT,
        KC_UP,
        KC_DOWN,     KC_DELT,  KC_ENT
    ),
/* Keymap 4: PPT layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |   6  |           |   7  |   8  |   9  |   0  |   -  |   +   |   =   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |  Tg  |           |  Tg  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------| Npad |           | Symb |------+------+------+------+------+--------|
 * |   ~    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|   '    |
 * |--------+------+------+------+------+------|  Tg  |           |CtrlF5|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | LKEY |           |      |   N  |   M  |   ,  |   .  | //Up | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl |CtlAlt|Wn/Cmd| Men |  LAlt |                                       | RAlt | RCtl | [/Lf | ]Dwm | TgPT |
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
        KC_ESC,   KC_1,          KC_2,    KC_3,         KC_4,    KC_5,  KC_6,
        KC_TAB,   KC_Q,          KC_W,    KC_E,         KC_R,    KC_T,  TG(NPAD),
        KC_GRV,   KC_A,          KC_S,    KC_D,         KC_F,    KC_G,
        KC_LSFT,  KC_Z,          KC_X,    KC_C,         KC_V,    KC_B,  TG(LKEY),
        KC_LCTRL, LCTL(KC_LALT), KC_LGUI, KC_MENU,      KC_LALT,
                                                        KC_HOME, KC_END,
                                                                 KC_PGUP,
                                               KC_SPC,  KC_BSPC, KC_PGDN,
        // right hand
        KC_7,                KC_8,           KC_9,     KC_0,                 KC_MINUS,             KC_PLUS,   KC_EQUAL,
        TG(SYMB),            KC_Y,           KC_U,     KC_I,                 KC_O,                 KC_P,      KC_BSLS,
                             KC_H,           KC_J,     KC_K,                 KC_L,                 KC_SCLN,   KC_QUOT,
        LCTL(KC_F5),         KC_N,           KC_M,     KC_COMM,              KC_DOT,               KC_SLSH,   KC_RSFT,
                             KC_RALT,        KC_RCTL,  KC_LBRC,              KC_RBRC,              TG(PPTK),
        KC_LEFT,     KC_RGHT, 
        KC_UP,
        KC_DOWN,     KC_DELT,  KC_ENT
    ),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
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
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


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
