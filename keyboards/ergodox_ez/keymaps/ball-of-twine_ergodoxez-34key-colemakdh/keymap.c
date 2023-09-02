#include QMK_KEYBOARD_H
#include "version.h"

#define __ KC_TRANSPARENT
#define LG(kc) LGUI_T(kc)
#define LA(kc) LALT_T(kc)
#define LC(kc) LCTL_T(kc)
#define LS(kc) LSFT_T(kc)
#define RG(kc) RGUI_T(kc)
#define RA(kc) RALT_T(kc)
#define RC(kc) RCTL_T(kc)
#define RS(kc) RSFT_T(kc)

enum layers {
    BASE_COLEMAK,
    BASE_QWERTY,
    LAYER_SYMBOLS,
    LAYER_NAV,
    LAYER_MOUSE,
    LAYER_FULL_NOMODS
};

enum tap_dance_codes {
    TD_ESC
    // TD_RPRN_SFT
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap BASE_COLEMAK [0] - Colemak-DH base layer
 * ┌─────┬───────┬───────┬────────┬─────────┬─────┬─────┐          ┌─────┬─────┬─────────┬────────┬───────┬───────┬─────┐
 * |     |       |       |        |         |     |     |          |     |     |         |        |       |       |     |
 * ├─────┼───────┼───────┼────────┼─────────┼─────┼─────┤          ├─────┼─────┼─────────┼────────┼───────┼───────┼─────┤
 * |     |   Q   |   W   |    F   |    P    |  B  |     |          |     |  J  |    L    |    U   |   Y   |   ;   |     |
 * ├─────┼───────┼───────┼────────┼─────────┼─────┤     |          |     ├─────┼─────────┼────────┼───────┼───────┼─────┤
 * |     | A/Gui | R/Alt | S/Ctrl | T/Shift |  G  |─────|          ├─────┤  M  | N/Shift | E/Ctrl | I/Alt | O/Gui |     |
 * ├─────┼───────┼───────┼────────┼─────────┼─────┤     |          |     ├─────┼─────────┼────────┼───────┼───────┼─────┤
 * |     |   X   |   C   |    D   |    V    |  Z  |     |          |     |  K  |    H    |    ,   |   .   |   /   |     |
 * ├─────┼───────┼───────┼────────┼─────────┼─────┴─────┘          └─────┴─────┼─────────┼────────┼───────┼───────┼─────┤
 * |     |       |       |        |         |                                  |         |        |       |       |     |
 * └─────┴───────┴───────┴────────┴─────────┘                                  └─────────┴────────┴───────┴───────┴─────┘
 *                                        ┌───────┬─────┐          ┌─────┬───────┐                                       
 *                                        |       |     |          |     |       |                                       
 *                                ┌───────┼───────┼─────┤          ├─────┼───────┼───────┐                               
 *                                | Space | Bkspc |     |          |     |       | Enter |                               
 *                                | /Tab  | /Del  ├─────┤          ├─────┤  Tab  |       |                               
 *                                | >Sym  |       |     |          |     |       | >Nav  |                               
 *                                └───────┴───────┴─────┘          └─────┴───────┴───────┘                               
 */
  [BASE_COLEMAK] = LAYOUT_ergodox_pretty(
    __, _______,  _______,  _______,  _______,  _______, __,        __, _______, _______,  _______,  _______,  _______,  __,
    __, KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,    __,        __, KC_J,    KC_L,     KC_U,     KC_Y,     KC_SCLN,  __,
    __, LG(KC_A), LA(KC_R), LC(KC_S), LS(KC_T), KC_G,    /*   1.5u   */ KC_M,    RS(KC_N), RC(KC_E), RA(KC_I), RG(KC_O), __,
    __, KC_X,     KC_C,     KC_D,     KC_V,     KC_Z,    __,        __, KC_K,    KC_H,     KC_COMM,  KC_DOT,   KC_SLSH,  __,
    __, _______,  _______,  _______,  _______,                                   _______,  _______,  _______,  _______,  __,
                                                _______, __,        __, _______,
                       /*        2.0u        */ /*2.0u*/ __,        __, /*2.0u*/ /*      2.0u      */
                      LT(LAYER_SYMBOLS,KC_SPC), KC_BSPC, __,        __, KC_TAB,  LT(LAYER_NAV,KC_ENT)
  ),
/* Keymap BASE_QWERTY [1] Qwerty base layer
 * ┌─────┬───────┬───────┬────────┬────────┬─────┬─────┐          ┌─────┬─────┬─────────┬────────┬───────┬───────┬─────┐
 * |     |       |       |        |        |     |     |          |     |     |         |        |       |       |     |
 * ├─────┼───────┼───────┼────────┼────────┼─────┼─────┤          ├─────┼─────┼─────────┼────────┼───────┼───────┼─────┤
 * |     |   Q   |   W   |   E    |    R   |  T  |     |          |     |  Y  |    U    |   I    |   O   |   P   |     |
 * ├─────┼───────┼───────┼────────┼────────┼─────┤     |          |     ├─────┼─────────┼────────┼───────┼───────┼─────┤
 * |     | A/Gui | S/Alt | D/Ctrl | F/Shft |  G  |─────|          ├─────┤  H  | J/Shift | K/Ctrl | L/Alt | ;/Gui |     |
 * ├─────┼───────┼───────┼────────┼────────┼─────┤     |          |     ├─────┼─────────┼────────┼───────┼───────┼─────┤
 * |     |   Z   |   X   |   C    |    V   |  B  |     |          |     |  N  |    M    |   ,    |   .   |   /   |     |
 * ├─────┼───────┼───────┼────────┼────────┼─────┴─────┘          └─────┴─────┼─────────┼────────┼───────┼───────┼─────┤
 * |     |       |       |        |        |                                  |         |        |       |       |     |
 * └─────┴───────┴───────┴────────┴────────┘                                  └─────────┴────────┴───────┴───────┴─────┘
 *                                       ┌───────┬─────┐          ┌─────┬───────┐                                       
 *                                       |       |     |          |     |       |                                       
 *                               ┌───────┼───────┼─────┤          ├─────┼───────┼───────┐                               
 *                               | Space | Bkspc |     |          |     |       | Enter |                               
 *                               | /Tab  | /Del  ├─────┤          ├─────┤  Tab  |       |                               
 *                               | >Sym  |       |     |          |     |       | >Nav  |                               
 *                               └───────┴───────┴─────┘          └─────┴───────┴───────┘                               
 */
  [BASE_QWERTY] = LAYOUT_ergodox_pretty(
    __, _______,  _______,  _______,  _______,  __,   __,        __, __,   _______,  _______,  _______,  _______,     __,     
    __, KC_Q,     KC_W,     KC_E,     KC_R,     KC_T, __,        __, KC_Y, KC_U,     KC_I,     KC_O,     KC_P,        __,     
    __, LG(KC_A), LA(KC_S), LC(KC_D), LS(KC_F), KC_G, /*   1.5u   */ KC_H, RS(KC_J), RC(KC_K), RA(KC_L), RG(KC_SCLN), __,     
    __, KC_Z,     KC_X,     KC_C,     KC_V,     KC_B, __,        __, KC_N, KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,     __,     
    __, _______,  _______,  _______,  _______,                             _______,  _______,  _______,  _______,     __,     
                                             _______, __,        __, _______, 
                   /*         2.0u        */ /*2.0u*/ __,        __, /*2.0u*/ /*      2.0u      */
                   LT(LAYER_SYMBOLS,KC_SPC), KC_BSPC, __,        __, KC_TAB,  LT(LAYER_NAV,KC_ENT)
  ),
/* Keymap LAYER_SYMBOLS [2] Symbols layer
 * ┌─────┬──────────┬─────┬─────┬─────┬─────┬─────┐          ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * |     |          |     |     |     |     |     |          |     |     |     |     |     |     |     |
 * ├─────┼──────────┼─────┼─────┼─────┼─────┼─────┤          ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * |     | Esc/Base |  -  |  {  |  }  |  _  |     |          |     |  *  | 7 & | 8 * | 9 ( |  +  |     |
 * ├─────┼──────────┼─────┼─────┼─────┼─────┤     |          |     ├─────┼─────┼─────┼─────┼─────┼─────┤
 * |     |  Gui/Fn  | ' " |  (  |  )  |  =  |─────|          ├─────┤  .  | 4 $ | 5 % | 6 ^ | 0 ) |     |
 * ├─────┼──────────┼─────┼─────┼─────┼─────┤     |          |     ├─────┼─────┼─────┼─────┼─────┼─────┤
 * |     | Caps/Alt | ` ~ |  [  |  ]  | \ | |     |          |     |  /  | 1 ! | 2 @ | 3 # |  -  |     |
 * ├─────┼──────────┼─────┼─────┼─────┼─────┴─────┘          └─────┴─────┼─────┼─────┼─────┼─────┼─────┤
 * |     |          |     |     |     |                                  |     |     |     |     |     |
 * └─────┴──────────┴─────┴─────┴─────┘                                  └─────┴─────┴─────┴─────┴─────┘
 *                                    ┌─────┬─────┐          ┌─────┬─────┐                              
 *                                    |     |     |          |     |     |                              
 *                              ┌─────┼─────┼─────┤          ├─────┼─────┼─────┐                        
 *                              |     |     |     |          |     |     |     |                        
 *                              |     |     ├─────┤          ├─────┤     |     |                        
 *                              |     |     |     |          |     |     |     |                        
 *                              └─────┴─────┴─────┘          └─────┴─────┴─────┘                        
 */
  [LAYER_SYMBOLS] = LAYOUT_ergodox_pretty(
    __, _______,     _______, _______, _______, _______, __,        __, _______, __,   __,   __,   _______, __,
    __, TD(TD_ESC),  KC_MINS, KC_LCBR, KC_RCBR, KC_UNDS, __,        __, KC_ASTR, KC_7, KC_8, KC_9, KC_PLUS, __,
    __, KC_LGUI,     KC_QUOT, KC_LPRN, KC_RPRN, KC_EQL,  /*   1.5u   */ KC_DOT,  KC_4, KC_5, KC_6, KC_0,    __,
    __, LT(KC_CAPS), KC_GRV,  KC_LBRC, KC_RBRC, KC_BSLS, __,        __, KC_SLSH, KC_1, KC_2, KC_3, KC_MINS, __,
    __, _______,     _______, _______, _______,                                  __,   __,   __,   _______, __,
                                               _______, __,        __, _______,
                                      /*2.0u*/ /*2.0u*/ __,        __, /*2.0u*/ /*2.0u*/
                                /*LT*/KC_TRNS, _______, __,        __, _______, _______
  ),
/* Keymap LAYER_NAV [3] Navigation layer
 * ┌─────┬──────────┬───────┬──────┬───────┬─────┬─────┐          ┌─────┬───────┬──────┬──────┬────────┬────────┬─────────┐
 * |     |          |       |      |       |     |     |          |     |       |      |      |        |        |         |
 * ├─────┼──────────┼───────┼──────┼───────┼─────┼─────┤          ├─────┼───────┼──────┼──────┼────────┼────────┼─────────┤
 * |     | Esc/Base |       |      |       |     |     |          |     |  Ins  | Home |  Up  |  End   |  PgUp  |         |
 * ├─────┼──────────┼───────┼──────┼───────┼─────┤     |          |     ├───────┼──────┼──────┼────────┼────────┼─────────┤
 * |     |   Gui    |  Alt  | Ctrl | Shift |     |─────|          ├─────┤  Del  | Left | Down | Right  | PgDown |         |
 * ├─────┼──────────┼───────┼──────┼───────┼─────┤     |          |     ├───────┼──────┼──────┼────────┼────────┼─────────┤
 * |     |          |       |      |       |     |     |          |     | >cmak | >Sym | >Nav | >Mouse | >qwert | >NoMods |
 * ├─────┼──────────┼───────┼──────┼───────┼─────┴─────┘          └─────┴───────┼──────┼──────┼────────┼────────┼─────────┤
 * |     |          |       |      |       |                                    |      |      |        |        |         |
 * └─────┴──────────┴───────┴──────┴───────┘                                    └──────┴──────┴────────┴────────┴─────────┘
 *                                         ┌─────┬─────┐          ┌─────┬─────┐                                      
 *                                         |     |     |          |     |     |                                      
 *                                   ┌─────┼─────┼─────┤          ├─────┼─────┼─────┐                                
 *                                   |     |     |     |          |     |     |     |                                
 *                                   |     |     ├─────┤          ├─────┤     |     |                                
 *                                   |     |     |     |          |     |     |     |                                
 *                                   └─────┴─────┴─────┘          └─────┴─────┴─────┘                                
 */
  [LAYER_NAV] = LAYOUT_ergodox_pretty(
    __, _______,    _______, _______, _______, _______, __,        __, _______,   _______, _______, _______, _______, __,
    __, TD(TD_ESC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, __,        __, KC_INSERT, KC_HOME, KC_UP,   KC_END,  KC_PGUP, __,
    __, KC_LGUI,    KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, /*   1.5u   */ KC_DELETE, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, __,
    __, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, __,        __, DF(BASE_COLEMAK), TO(LAYER_SYMBOLS), TO(LAYER_NAV), TO(LAYER_MOUSE), DF(BASE_QWERTY), TO(LAYER_FULL_NOMODS),
    __, _______,    _______, _______, _______,                                    _______, _______, _______, _______, __,
                                               _______, __,        __, _______,
                                      /*2.0u*/ /*2.0u*/ __,        __, /*2.0u*/ /*   2.0u   */
                                      _______, _______, __,        __, _______, KC_TRNS/*LT*/
  ),
/* Keymap LAYER_MOUSE [4] Mouse layer
 * ┌─────┬──────────┬────────┬────────┬─────────┬──────┬─────┐          ┌─────┬─────┬───────┬──────┬─────┬─────┬─────┐
 * |     |          |        |        |         |      |     |          |     |     |       |      |     |     |     |
 * ├─────┼──────────┼────────┼────────┼─────────┼──────┼─────┤          ├─────┼─────┼───────┼──────┼─────┼─────┼─────┤
 * |     | Esc/Base |  WhlL  |  MsUp  |  WhlR   | WhlU |     |          |     |     |       |      |     |     |     |
 * ├─────┼──────────┼────────┼────────┼─────────┼──────┤     |          |     ├─────┼───────┼──────┼─────┼─────┼─────┤
 * |     |          | MsLeft | MsDown | MsRight | WhlD |─────|          ├─────┤     | Shift | Ctrl | Alt | Gui |     |
 * ├─────┼──────────┼────────┼────────┼─────────┼──────┤     |          |     ├─────┼───────┼──────┼─────┼─────┼─────┤
 * |     |          |        |        |         | Mclk |     |          |     |     |       |      |     |     |     |
 * ├─────┼──────────┼────────┼────────┼─────────┼──────┴─────┘          └─────┴─────┼───────┼──────┼─────┼─────┼─────┤
 * |     |          |        |        |         |                                   |       |      |     |     |     |
 * └─────┴──────────┴────────┴────────┴─────────┘                                   └───────┴──────┴─────┴─────┴─────┘
 *                                              ┌──────┬─────┐          ┌─────┬─────┐                                 
 *                                              |      |     |          |     |     |                                 
 *                                       ┌──────┼──────┼─────┤          ├─────┼─────┼──────┐                          
 *                                       |      |      |     |          |     |     |      |                          
 *                                       | Lclk | Rclk ├─────┤          ├─────┤     |      |                          
 *                                       |      |      |     |          |     |     |      |                          
 *                                       └──────┴──────┴─────┘          └─────┴─────┴──────┘                          
 */
  [LAYER_MOUSE] = LAYOUT_ergodox_pretty(
    __, _______,    _______,       _______,    _______,        _______,       __,        __, _______, _______, _______, _______, _______, __,
    __, TD(TD_ESC), KC_MS_WH_LEFT, KC_MS_UP,   KC_MS_WH_RIGHT, KC_MS_WH_UP,   __,        __, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, __,
    __, XXXXXXX,    KC_MS_LEFT,    KC_MS_DOWN, KC_MS_RIGHT,    KC_MS_WH_DOWN, /*   1.5u   */ XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, __,
    __, XXXXXXX,    XXXXXXX,       XXXXXXX,    XXXXXXX,        KC_MS_BTN3,    __,        __, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, __,
    __, _______,    _______,       _______,    _______,                                               _______, _______, _______, _______, __,
                                                                     _______, __,        __, _______,
                                                      /*  2.0u */ /*  2.0u */ __,        __, /*2.0u*/ /*2.0u*/
                                                      KC_MS_BTN1, KC_MS_BTN2, __,        __, _______, _______
  ),
/* Keymap LAYER_FULL_NOMODS [5] Qwerty layer will all keys set and no mods (for gaming)
 * ┌──────────┬─────┬─────┬───────┬───────┬─────┬─────┐          ┌─────┬─────┬─────┬───────┬─────┬─────┬───────┐
 * | Esc/base |  1  |  2  |   3   |   4   |  5  | KP6 |          | KP5 |  6  |  7  |   8   |  9  |  0  |   -   |
 * ├──────────┼─────┼─────┼───────┼───────┼─────┼─────┤          ├─────┼─────┼─────┼───────┼─────┼─────┼───────┤
 * |   Tab    |  Q  |  W  |   E   |   R   |  T  | KP7 |          | KP4 |  Y  |  U  |   I   |  O  |  P  |   \   |
 * ├──────────┼─────┼─────┼───────┼───────┼─────┤     |          |     ├─────┼─────┼───────┼─────┼─────┼───────┤
 * |   KP0    |  A  |  S  |   D   |   F   |  G  |─────|          ├─────┤  H  |  J  |   K   |  L  |  ;  |   '   |
 * ├──────────┼─────┼─────┼───────┼───────┼─────┤     |          |     ├─────┼─────┼───────┼─────┼─────┼───────┤
 * |  Shift   |  Z  |  X  |   C   |   V   |  B  | KP8 |          | KP3 |  N  |  M  |   ,   |  .  |  /  | Shift |
 * ├──────────┼─────┼─────┼───────┼───────┼─────┴─────┘          └─────┴─────┼─────┼───────┼─────┼─────┼───────┤
 * |   Ctrl   | Win | Alt | Left  | Right |                                  | Up  | Down  |  [  |  ]  |  KP1  |
 * └──────────┴─────┴─────┴───────┴───────┘                                  └─────┴───────┴─────┴─────┴───────┘
 *                                    ┌───────┬──────┐          ┌──────┬───────┐                                   
 *                                    |  F13  | F14  |          | F15  |  F16  |                                   
 *                            ┌───────┼───────┼──────┤          ├──────┼───────┼───────┐                           
 *                            |       |       | Home |          | PgUp |       |       |                           
 *                            | Space | Bkspc ├──────┤          ├──────┤  Tab  | Enter |                           
 *                            |       |       | End  |          | PgDn |       |       |                           
 *                            └───────┴───────┴──────┘          └──────┴───────┴───────┘                                                    
 */
  [LAYER_FULL_NOMODS] = LAYOUT_ergodox_pretty(
    TD(TD_ESC), KC_1,    KC_2,    KC_3,    KC_4,  KC_5, KC_P6,        KC_P5,  KC_6,  KC_7,  KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,  KC_T, KC_P7,        KC_P4,  KC_Y,  KC_U,  KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_P0,      KC_A,    KC_S,    KC_D,    KC_F,  KC_G, /*      1.5u      */  KC_H,  KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,  KC_B, KC_P8,        KC_P3,  KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL,    KC_LGUI, KC_LALT, KC_LEFT, KC_RIGHT,                                 KC_UP, KC_DOWN, KC_LBRC, KC_RBRC, KC_P1,
                                              KC_F13,  KC_F14,        KC_F15,  KC_F16,
                                    /*2.0u*/ /*2.0u*/ KC_HOME,        KC_PGUP, /*2.0u*/ /*2.0u*/
                                     KC_SPC, KC_BSPC,  KC_END,        KC_PGDN, KC_TAB,   KC_ENT
  )
};

// const uint16_t PROGMEM combo_df_qwert[] = { KC_H, KC_COMMA, KC_DOT, KC_SLASH, COMBO_END};
// const uint16_t PROGMEM combo_df_cmak[] = { KC_M, KC_COMMA, KC_DOT, KC_SLASH, COMBO_END};

// combo_t key_combos[COMBO_COUNT] = {
//     COMBO(combo_df_qwert, DF(BASE_COLEMAK)),
//     COMBO(combo_df_cmak, DF(BASE_QWERTY)),
// };


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case LT(LAYER_NAV, KC_SPC):
    /* code */
    break;
  default:
    break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
// void keyboard_post_init_user(void) {
//   debug_enable=true;
//   debug_matrix=true;
//   debug_keyboard=true;
//   debug_mouse=true;
// }

// enum led_state {
//   OFF = 0,
//   ON = 100
// } uint;

// void set_ergodox_leds(uint led1, uint led2, uint led3) {
void set_ergodox_leds(bool led1, bool led2, bool led3) {
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  if (led1) {
    ergodox_right_led_1_on();
    // ergodox_right_led_1_set(led1);
    ergodox_right_led_1_set(50);
  }
  if (led2) {
    ergodox_right_led_2_on();
    // ergodox_right_led_2_set(led2);
    ergodox_right_led_2_set(10);
  }
  if (led3) {
    ergodox_right_led_3_on();
    // ergodox_right_led_3_set(led3);
    ergodox_right_led_3_set(10);
  }
}

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  uint8_t layer = biton(state);
  ergodox_board_led_off();
  switch (layer) {
    case BASE_COLEMAK:      set_ergodox_leds(0, 0, 0); break;
    case BASE_QWERTY:       set_ergodox_leds(1, 1, 1); break;
    case LAYER_SYMBOLS:     set_ergodox_leds(1, 0, 0); break;
    case LAYER_NAV:         set_ergodox_leds(0, 1, 0); break;
    case LAYER_MOUSE:       set_ergodox_leds(0, 0, 1); break;
    case LAYER_FULL_NOMODS: set_ergodox_leds(1, 1, 1); break;
    default:                set_ergodox_leds(0, 0, 0); break;
  }
  return state;
};

// void caps_word_set_user(bool active) {
//   if (active) {
//     
//   }
// }


bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record);

bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
  // switch (keycode) {
  //   #ifndef NO_AUTO_SHIFT_ALPHA
  //   case KC_A ... KC_Z:
  //   #endif
  //   #ifndef NO_AUTO_SHIFT_NUMERIC
  //   case KC_1 ... KC_0:
  //   #endif
  //   #ifndef NO_AUTO_SHIFT_SPECIAL
  //   case KC_TAB:
  //   case KC_MINUS ... KC_SLASH:
  //   case KC_NONUS_BACKSLASH:
  //   #endif
  //   return true;
  // }
  return get_custom_auto_shifted_key(keycode, record);
}

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case KC_0:
    case KC_1:
    case KC_2:
    case KC_3:
    case KC_4:
    case KC_5:
    case KC_6:
    case KC_7:
    case KC_8:
    case KC_9:
    case KC_BACKSLASH:
    case KC_GRAVE:
    case KC_QUOT:
      return true;
    default:
      return false;
  }
}


const key_override_t space_key_override   = ko_make_basic(MOD_MASK_SHIFT, LT(LAYER_SYMBOLS,KC_SPC), KC_TAB);
const key_override_t delete_key_override  = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

/* override GUI + number key = fn key */
const key_override_t ko_gui_f1  = ko_make_basic(MOD_MASK_GUI, KC_1,    KC_F1);
const key_override_t ko_gui_f2  = ko_make_basic(MOD_MASK_GUI, KC_2,    KC_F2);
const key_override_t ko_gui_f3  = ko_make_basic(MOD_MASK_GUI, KC_3,    KC_F3);
const key_override_t ko_gui_f4  = ko_make_basic(MOD_MASK_GUI, KC_4,    KC_F4);
const key_override_t ko_gui_f5  = ko_make_basic(MOD_MASK_GUI, KC_5,    KC_F5);
const key_override_t ko_gui_f6  = ko_make_basic(MOD_MASK_GUI, KC_6,    KC_F6);
const key_override_t ko_gui_f7  = ko_make_basic(MOD_MASK_GUI, KC_7,    KC_F7);
const key_override_t ko_gui_f8  = ko_make_basic(MOD_MASK_GUI, KC_8,    KC_F8);
const key_override_t ko_gui_f9  = ko_make_basic(MOD_MASK_GUI, KC_9,    KC_F9);
const key_override_t ko_gui_f10 = ko_make_basic(MOD_MASK_GUI, KC_PLUS, KC_F10);
const key_override_t ko_gui_f11 = ko_make_basic(MOD_MASK_GUI, KC_0,    KC_F11);
const key_override_t ko_gui_f12 = ko_make_basic(MOD_MASK_GUI, KC_MINS, KC_F12);

/* override ALT + number key = numpad number key (useful for typing unicode chars via "alt codes")*/
const key_override_t ko_alt_p1 = ko_make_basic(MOD_MASK_ALT, KC_1, KC_P1);
const key_override_t ko_alt_p2 = ko_make_basic(MOD_MASK_ALT, KC_2, KC_P2);
const key_override_t ko_alt_p3 = ko_make_basic(MOD_MASK_ALT, KC_3, KC_P3);
const key_override_t ko_alt_p4 = ko_make_basic(MOD_MASK_ALT, KC_4, KC_P4);
const key_override_t ko_alt_p5 = ko_make_basic(MOD_MASK_ALT, KC_5, KC_P5);
const key_override_t ko_alt_p6 = ko_make_basic(MOD_MASK_ALT, KC_6, KC_P6);
const key_override_t ko_alt_p7 = ko_make_basic(MOD_MASK_ALT, KC_7, KC_P7);
const key_override_t ko_alt_p8 = ko_make_basic(MOD_MASK_ALT, KC_8, KC_P8);
const key_override_t ko_alt_p9 = ko_make_basic(MOD_MASK_ALT, KC_9, KC_P9);
const key_override_t ko_alt_p0 = ko_make_basic(MOD_MASK_ALT, KC_0, KC_P0);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&space_key_override, &delete_key_override,
  
  &ko_gui_f7, &ko_gui_f8, &ko_gui_f9, &ko_gui_f10,
  &ko_gui_f4, &ko_gui_f5, &ko_gui_f6, &ko_gui_f11,
  &ko_gui_f1, &ko_gui_f2, &ko_gui_f3, &ko_gui_f12,

  &ko_alt_p7, &ko_alt_p8, &ko_alt_p9,
  &ko_alt_p4, &ko_alt_p5, &ko_alt_p6, &ko_alt_p0,
  &ko_alt_p1, &ko_alt_p2, &ko_alt_p3,
	NULL // Null terminate the array of overrides!
};

// typedef struct {
//     bool is_press_action;
//     uint8_t step;
// } tap;

// enum {
//     SINGLE_TAP = 1,
//     SINGLE_HOLD,
//     DOUBLE_TAP,
//     DOUBLE_HOLD,
//     DOUBLE_SINGLE_TAP,
//     MORE_TAPS
// };

// TD_ESC uses td_layer_move, so we don't need an array
// also we only use the uint8_t step
// static uint8_t rprn_sft_dance_step;
// static tap dance_state[0];

// uint8_t dance_step(tap_dance_state_t *state);

// uint8_t dance_step(tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (state->interrupted || !state->pressed) return SINGLE_TAP;
//         else return SINGLE_HOLD;
//     } else if (state->count == 2) {
//         if (state->interrupted) return DOUBLE_SINGLE_TAP;
//         else if (state->pressed) return DOUBLE_HOLD;
//         else return DOUBLE_TAP;
//     }
//     return MORE_TAPS;
// }

/*TD fn advanced for esc/mo(base layer)
// void on_dance_esc(tap_dance_state_t *state, void *user_data);
// void dance_esc_finished(tap_dance_state_t *state, void *user_data);
// void dance_esc_reset(tap_dance_state_t *state, void *user_data);

// void on_dance_esc(tap_dance_state_t *state, void *user_data) {
//     if(state->count == 3) {
//         tap_code16(KC_ESCAPE);
//         tap_code16(KC_ESCAPE);
//         tap_code16(KC_ESCAPE);
//     }
//     if(state->count > 3) {
//         tap_code16(KC_ESCAPE);
//     }
// }

// void dance_esc_finished(tap_dance_state_t *state, void *user_data) {
//     dance_state[0].step = dance_step(state);
//     switch (dance_state[0].step) {
//         case SINGLE_TAP: register_code16(KC_ESCAPE); break;
//         case DOUBLE_TAP: 
//             if (IS_LAYER_ON(BASE_COLEMAK)) {
//                 layer_move(BASE_COLEMAK);
//             } else if (IS_LAYER_ON(BASE_QWERTY)) {
//                 layer_move(BASE_QWERTY);
//             }
//             break;
//         case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
//     }
// }

// void dance_esc_reset(tap_dance_state_t *state, void *user_data) {
//     wait_ms(10);
//     switch (dance_state[0].step) {
//         case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
//         case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
//     }
//     dance_state[0].step = 0;
// }
*/

// void on_dance_rprn_sft(tap_dance_state_t *state, void *user_data);
// void dance_rprn_sft_finished(tap_dance_state_t *state, void *user_data);
// void dance_rprn_sft_reset(tap_dance_state_t *state, void *user_data);

// void on_dance_rprn_sft(tap_dance_state_t *state, void *user_data) {
//     if(state->count == 3) {
//         tap_code16(KC_RPRN);
//         tap_code16(KC_RPRN);
//         tap_code16(KC_RPRN);
//     }
//     if(state->count > 3) {
//         tap_code16(KC_RPRN);
//     }
// }

// void dance_rprn_sft_finished(tap_dance_state_t *state, void *user_data) {
//     rprn_sft_dance_step = dance_step(state);
//     switch (rprn_sft_dance_step) {
//         case SINGLE_TAP: register_code16(KC_RPRN); break;
//         case SINGLE_HOLD: register_mods(MOD_MASK_SHIFT); break;
//         case DOUBLE_SINGLE_TAP: tap_code16(KC_RPRN); register_code16(KC_RPRN); //break;
//         // case DOUBLE_HOLD: tap_code16(KC_RPRN); register_mods(MOD_MASK_SHIFT);
//     }
// }

// void dance_rprn_sft_reset(tap_dance_state_t *state, void *user_data) {
//     wait_ms(10);
//     switch (rprn_sft_dance_step) {
//         case SINGLE_TAP: unregister_code16(KC_RPRN); break;
//         case SINGLE_HOLD: unregister_mods(MOD_MASK_SHIFT); break;
//         case DOUBLE_SINGLE_TAP: unregister_code16(KC_RPRN); //break;
//         // case DOUBLE_HOLD: unregister_mods(MOD_MASK_SHIFT);
//     }
//     rprn_sft_dance_step = 0;
// }

tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC] = ACTION_TAP_DANCE_LAYER_MOVE(KC_ESC, BASE_COLEMAK),
    // [TD_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_esc, dance_esc_finished, dance_esc_reset)
    // [TD_RPRN_SFT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_rprn_sft, dance_rprn_sft_finished, dance_rprn_sft_reset),
    // [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
};
