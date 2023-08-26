#include QMK_KEYBOARD_H
#include "version.h"
#include "print.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)

enum layers {
    BASE_COLEMAK,
    BASE_QWERTY,
    LAYER_SYMBOLS,
    LAYER_NAV,
    LAYER_MOUSE,
    LAYER_FN_KEYS
};

enum tap_dance_codes {
    TD_ESC
    // DANCE_1,
    // DANCE_2,
    // DANCE_3,
    // DANCE_4,
    // DANCE_5,
    // DANCE_6,
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer (colemak-dh)
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
 *                                | Space |       |     |          |     |       | Enter |                               
 *                                |  /L1  | Bkspc ├─────┤          ├─────┤  Tab  |  /L2  |                               
 *                                |       |       |     |          |     |       |       |                               
 *                                └───────┴───────┴─────┘          └─────┴───────┴───────┘                               
 */
  [BASE_COLEMAK] = LAYOUT_ergodox_pretty(
    _______, _______,      _______,      _______,      _______,      _______, _______,        _______, _______, _______,      _______,      _______,      _______,      _______,
    _______, KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,    _______,        _______, KC_J,    KC_L,         KC_U,         KC_Y,         KC_SCLN,      _______,
    _______, LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G,    /*1.5u*/        /*1.5u*/ KC_M,    RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O), _______,
    _______, KC_X,         KC_C,         KC_D,         KC_V,         KC_Z,    _______,        _______, KC_K,    KC_H,         KC_COMMA,     KC_DOT,       KC_SLASH,     _______,
    _______, _______,      _______,      _______,      _______,                                                 _______,      _______,      _______,      _______,      _______,
                                                                     _______, _______,        _______, _______,
                                                       /*2.0u*/      /*2.0u*/ _______,        _______, /*2.0u*/ /*2.0u*/
                                                       LT(2,KC_SPC), KC_BSPC, _______,        _______, KC_TAB,  LT(3,KC_ENT)
  ),
/* Keymap 1: Qwerty
 * ┌─────┬───────┬───────┬────────┬─────────┬─────┬─────┐          ┌─────┬─────┬─────────┬────────┬───────┬───────┬─────┐
 * |     |       |       |        |         |     |     |          |     |     |         |        |       |       |     |
 * ├─────┼───────┼───────┼────────┼─────────┼─────┼─────┤          ├─────┼─────┼─────────┼────────┼───────┼───────┼─────┤
 * |     | Q/L0  |   W   |   E    |    R    |  T  |     |          |     |  Y  |    U    |   I    |   O   |   P   |     |
 * ├─────┼───────┼───────┼────────┼─────────┼─────┤     |          |     ├─────┼─────────┼────────┼───────┼───────┼─────┤
 * |     | A/Gui | S/Alt | D/Ctrl | F/Shift |  G  |─────|          ├─────┤  H  | J/Shift | K/Ctrl | L/Alt | ;/Gui |     |
 * ├─────┼───────┼───────┼────────┼─────────┼─────┤     |          |     ├─────┼─────────┼────────┼───────┼───────┼─────┤
 * |     |   Z   |   X   |   C    |    V    |  B  |     |          |     |  N  |    M    |   ,    |   .   |   /   |     |
 * ├─────┼───────┼───────┼────────┼─────────┼─────┴─────┘          └─────┴─────┼─────────┼────────┼───────┼───────┼─────┤
 * |     |       |       |        |         |                                  |         |        |       |       |     |
 * └─────┴───────┴───────┴────────┴─────────┘                                  └─────────┴────────┴───────┴───────┴─────┘
 *                                        ┌───────┬─────┐          ┌─────┬───────┐                                       
 *                                        |       |     |          |     |       |                                       
 *                                ┌───────┼───────┼─────┤          ├─────┼───────┼───────┐                               
 *                                | Space |       |     |          |     |       | Enter |                               
 *                                |  /L1  | Bkspc ├─────┤          ├─────┤  Tab  |  /L2  |                               
 *                                |       |       |     |          |     |       |       |                               
 *                                └───────┴───────┴─────┘          └─────┴───────┴───────┘                               
 */
  [BASE_QWERTY] = LAYOUT_ergodox_pretty(
    _______, _______,      _______,      _______,      _______,      _______, _______,        _______, _______, _______,      _______,      _______,      _______,         _______,
    _______, KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,    _______,        _______, KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,            _______,
    _______, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,    /*1.5u*/        /*1.5u*/ KC_H,    RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), _______,
    _______, KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,    _______,        _______, KC_N,    KC_M,         KC_COMMA,     KC_DOT,       KC_SLASH,        _______,
    _______, _______,      _______,      _______,      _______,                                                 _______,      _______,      _______,      _______,         _______,
                                                                     _______, _______,        _______, _______,
                                                       /*2.0u*/      /*2.0u*/ _______,        _______, /*2.0u*/ /*2.0u*/
                                                       LT(2,KC_SPC), KC_BSPC, _______,        _______, KC_TAB,  LT(3,KC_ENT)
  ),
/* Keymap 2: Symbols
 * ┌─────┬────────┬─────┬─────┬─────────┬─────┬─────┐          ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * |     |        |     |     |         |     |     |          |     |     |     |     |     |     |     |
 * ├─────┼────────┼─────┼─────┼─────────┼─────┼─────┤          ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * |     | ESC/L0 |  -  |  {  |    }    |  _  |     |          |     |  -  |  7  |  8  |  9  |  +  |     |
 * ├─────┼────────┼─────┼─────┼─────────┼─────┤     |          |     ├─────┼─────┼─────┼─────┼─────┼─────┤
 * |     | NOP/L4 |  =  |  (  | )/Shift |  +  |─────|          ├─────┤  *  |  4  |  5  |  6  |  0  |     |
 * ├─────┼────────┼─────┼─────┼─────────┼─────┤     |          |     ├─────┼─────┼─────┼─────┼─────┼─────┤
 * |     |        |  \  |  [  |    ]    |  |  |     |          |     |  .  |  1  |  2  |  3  |  -  |     |
 * ├─────┼────────┼─────┼─────┼─────────┼─────┴─────┘          └─────┴─────┼─────┼─────┼─────┼─────┼─────┤
 * |     |        |     |     |         |                                  |     |     |     |     |     |
 * └─────┴────────┴─────┴─────┴─────────┘                                  └─────┴─────┴─────┴─────┴─────┘
 *                                      ┌─────┬─────┐          ┌─────┬─────┐                                     
 *                                      |     |     |          |     |     |                                     
 *                                ┌─────┼─────┼─────┤          ├─────┼─────┼─────┐                               
 *                                |     |     |     |          |     |     |     |                               
 *                                |     |     ├─────┤          ├─────┤     |     |                               
 *                                |     |     |     |          |     |     |     |                               
 *                                └─────┴─────┴─────┘          └─────┴─────┴─────┘                               
 */
  [LAYER_SYMBOLS] = LAYOUT_ergodox_pretty(
    _______, _______,    _______,  _______, _______,         _______,  _______,        _______, _______,  _______, _______, _______, _______,  _______,
    _______, TD(TD_ESC), KC_NO,    KC_LCBR, KC_RCBR,         KC_MINUS, _______,        _______, KC_MINUS, KC_7,    KC_8,    KC_9,    KC_PLUS,  _______,
    _______, MO(5),      KC_QUOTE, KC_LPRN, LSFT_T(KC_RPRN), KC_EQUAL, /*1.5u*/        /*1.5u*/ KC_ASTR,  KC_4,    KC_5,    KC_6,    KC_0,     _______,
    _______, KC_NO,      KC_NO,    KC_LBRC, KC_RBRC,         KC_BSLS,  _______,        _______, KC_DOT,   KC_1,    KC_2,    KC_3,    KC_MINUS, _______,
    _______, _______,    _______,  _______, _______,                                                      _______, _______, _______, _______,  _______,
                                                              _______, _______,        _______, _______,
                                                     /*2.0u*/ /*2.0u*/ _______,        _______, /*2.0u*/ /*2.0u*/
                                               KC_TRNS/*LT*/, _______, _______,        _______, _______, _______
  ),
/* Keymap 3: Navigation
 * ┌─────┬────────┬───────┬──────┬───────┬─────┬─────┐          ┌─────┬─────┬───────┬──────┬───────┬────────┬─────┐
 * |     |        |       |      |       |     |     |          |     |     |       |      |       |        |     |
 * ├─────┼────────┼───────┼──────┼───────┼─────┼─────┤          ├─────┼─────┼───────┼──────┼───────┼────────┼─────┤
 * |     | Esc/L0 |       |      |       |     |     |          |     | Ins | Home  |  Up  |  End  |  PgUp  |     |
 * ├─────┼────────┼───────┼──────┼───────┼─────┤     |          |     ├─────┼───────┼──────┼───────┼────────┼─────┤
 * |     |  Gui   |  Alt  | Ctrl | Shift |     |─────|          ├─────┤ Del | Left  | Down | Right | PgDown |     |
 * ├─────┼────────┼───────┼──────┼───────┼─────┤     |          |     ├─────┼───────┼──────┼───────┼────────┼─────┤
 * |     |        |       |      |       |     |     |          |     | L1  |  L2   |  L3  |  L4   |   L5   |     |
 * ├─────┼────────┼───────┼──────┼───────┼─────┴─────┘          └─────┴─────┼───────┼──────┼───────┼────────┼─────┤
 * |     |        |       |      |       |                                  |       |      |       |        |     |
 * └─────┴────────┴───────┴──────┴───────┘                                  └───────┴──────┴───────┴────────┴─────┘
 *                                       ┌─────┬─────┐          ┌─────┬─────┐                                      
 *                                       |     |     |          |     |     |                                      
 *                                 ┌─────┼─────┼─────┤          ├─────┼─────┼─────┐                                
 *                                 |     |     |     |          |     |     |     |                                
 *                                 |     |     ├─────┤          ├─────┤     |     |                                
 *                                 |     |     |     |          |     |     |     |                                
 *                                 └─────┴─────┴─────┘          └─────┴─────┴─────┘                                
 */
  [LAYER_NAV] = LAYOUT_ergodox_pretty(
    _______, _______,    _______, _______, _______, _______, _______,        _______, _______,   _______, _______, _______, _______, _______,
    _______, TD(TD_ESC), KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,        _______, KC_INSERT, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______,
    _______, KC_LGUI,    KC_LALT, KC_LCTL, KC_LSFT, KC_NO,   /*1.5u*/        /*1.5u*/ KC_DELETE, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
    _______, KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,        _______, _______,   TO(2),   TO(3),   TO(4),   TO(5),   _______,
    _______, _______,    _______, _______, _______,                                              _______, _______, _______, _______, _______,
                                                    _______, _______,        _______, _______,
                                           /*2.0u*/ /*2.0u*/ _______,        _______, /*2.0u*/ /*2.0u*/
                                           _______, _______, _______,        _______, _______, KC_TRNS/*LT*/
  ),
/* Keymap 4: Mouse
 * ┌─────┬────────┬────────┬────────┬─────────┬──────┬─────┐          ┌─────┬──────┬─────────┬────────┬────────┬────────┬─────┐
 * |     |        |        |        |         |      |     |          |     |      |         |        |        |        |     |
 * ├─────┼────────┼────────┼────────┼─────────┼──────┼─────┤          ├─────┼──────┼─────────┼────────┼────────┼────────┼─────┤
 * |     | Esc/L0 |  WhlL  |  MsUp  |  WhlR   | WhlU |     |          |     |      |         |        |        |        |     |
 * ├─────┼────────┼────────┼────────┼─────────┼──────┤     |          |     ├──────┼─────────┼────────┼────────┼────────┼─────┤
 * |     |        | MsLeft | MsDown | MsRight | WhlD |─────|          ├─────┤      |  Shift  |  Ctrl  |  Alt   |  Gui   |     |
 * ├─────┼────────┼────────┼────────┼─────────┼──────┤     |          |     ├──────┼─────────┼────────┼────────┼────────┼─────┤
 * |     |        |        |        |         | Mclk |     |          |     |      |         |        |        |        |     |
 * ├─────┼────────┼────────┼────────┼─────────┼──────┴─────┘          └─────┴──────┼─────────┼────────┼────────┼────────┼─────┤
 * |     |        |        |        |         |                                    |         |        |        |        |     |
 * └─────┴────────┴────────┴────────┴─────────┘                                    └─────────┴────────┴────────┴────────┴─────┘
 *                                            ┌──────┬─────┐          ┌─────┬──────┐                                           
 *                                            |      |     |          |     |      |                                           
 *                                     ┌──────┼──────┼─────┤          ├─────┼──────┼──────┐                                    
 *                                     |      |      |     |          |     |      |      |                                    
 *                                     | Lclk | Rclk ├─────┤          ├─────┤      |      |                                    
 *                                     |      |      |     |          |     |      |      |                                    
 *                                     └──────┴──────┴─────┘          └─────┴──────┴──────┘                                    
 */
  [LAYER_MOUSE] = LAYOUT_ergodox_pretty(
    _______, _______,    _______,       _______,    _______,        _______,       _______,        _______, _______, _______, _______, _______, _______, _______,
    _______, TD(TD_ESC), KC_MS_WH_LEFT, KC_MS_UP,   KC_MS_WH_RIGHT, KC_MS_WH_UP,   _______,        _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
    _______, KC_NO,      KC_MS_LEFT,    KC_MS_DOWN, KC_MS_RIGHT,    KC_MS_WH_DOWN, /*1.5u*/        /*1.5u*/ KC_NO,   KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
    _______, KC_NO,      KC_NO,         KC_NO,      KC_NO,          KC_MS_BTN3,    _______,        _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
    _______, _______,    _______,       _______,    _______,                                                         _______, _______, _______, _______, _______,
                                                                          _______, _______,        _______, _______,
                                                                 /*2.0u*/ /*2.0u*/ _______,        _______, /*2.0u*/ /*2.0u*/
                                                                 _______, _______, _______,        _______, _______, _______
  ),
/* Keymap 5: function keys
 * ┌─────┬────────┬─────┬─────┬─────┬─────┬─────┐          ┌─────┬─────┬─────┬─────┬─────┬────────┬─────┐
 * |     |        |     |     |     |     |     |          |     |     |     |     |     |        |     |
 * ├─────┼────────┼─────┼─────┼─────┼─────┼─────┤          ├─────┼─────┼─────┼─────┼─────┼────────┼─────┤
 * |     | Esc/L0 |     |     |     |     |     |          |     |     | F7  | F8  | F9  |  F10   |     |
 * ├─────┼────────┼─────┼─────┼─────┼─────┤     |          |     ├─────┼─────┼─────┼─────┼────────┼─────┤
 * |     |        |     |     |     |     |─────|          ├─────┤     | F4  | F5  | F6  |  F11   |     |
 * ├─────┼────────┼─────┼─────┼─────┼─────┤     |          |     ├─────┼─────┼─────┼─────┼────────┼─────┤
 * |     |        |     |     |     |     |     |          |     |     | F1  | F2  | F3  |  F12   |     |
 * ├─────┼────────┼─────┼─────┼─────┼─────┴─────┘          └─────┴─────┼─────┼─────┼─────┼────────┼─────┤
 * |     |        |     |     |     |                                  |     |     |     |        |     |
 * └─────┴────────┴─────┴─────┴─────┘                                  └─────┴─────┴─────┴────────┴─────┘
 *                                  ┌─────┬─────┐          ┌─────┬─────┐                                 
 *                                  |     |     |          |     |     |                                 
 *                            ┌─────┼─────┼─────┤          ├─────┼─────┼─────┐                           
 *                            |     |     |     |          |     |     |     |                           
 *                            |     |     ├─────┤          ├─────┤     |     |                           
 *                            |     |     |     |          |     |     |     |                           
 *                            └─────┴─────┴─────┘          └─────┴─────┴─────┘                           
 */
  [LAYER_FN_KEYS] = LAYOUT_ergodox_pretty(
    _______, _______,       _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______,
    _______, TD(TD_ESC),    KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,        _______, KC_NO,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
    _______, KC_TRNS/*MO*/, KC_NO,   KC_NO,   KC_NO,   KC_NO,   /*1.5u*/        /*1.5u*/ KC_NO,   KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,
    _______, KC_NO,         KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,        _______, KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______,
    _______, _______,       _______, _______, _______,                                            _______, _______, _______, _______, _______,
                                                       _______, _______,        _______, _______,
                                              /*2.0u*/ /*2.0u*/ _______,        _______, /*2.0u*/ /*2.0u*/
                                              _______, _______, _______,        _______, _______, _______
  )
};


const uint16_t PROGMEM combo_df_qwert[] = { KC_H, KC_COMMA, KC_DOT, KC_SLASH, COMBO_END};
const uint16_t PROGMEM combo_df_cmak[] = { KC_M, KC_COMMA, KC_DOT, KC_SLASH, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_df_qwert, DF(BASE_COLEMAK)),
    COMBO(combo_df_cmak, DF(BASE_QWERTY)),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
  uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 
  return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
//   debug_enable=true;
//   debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  uint8_t layer = biton(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case BASE_COLEMAK:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case BASE_QWERTY:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case LAYER_SYMBOLS:
    case LAYER_FN_KEYS: /*"sublayer" of Symbols*/
      ergodox_right_led_1_on();
      break;
    case LAYER_NAV:
      ergodox_right_led_2_on();
      break;
    case LAYER_MOUSE:
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[0];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_esc(tap_dance_state_t *state, void *user_data);
void dance_esc_finished(tap_dance_state_t *state, void *user_data);
void dance_esc_reset(tap_dance_state_t *state, void *user_data);

void on_dance_esc(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if(state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

void dance_esc_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: 
            if (IS_LAYER_ON(BASE_COLEMAK)) {
                layer_move(BASE_COLEMAK);
            } else if (IS_LAYER_ON(BASE_QWERTY)) {
                layer_move(BASE_QWERTY);
            }
            break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_esc_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
    }
    dance_state[0].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC] = ACTION_TAP_DANCE_LAYER_MOVE(KC_ESC, BASE_COLEMAK)
    // [TD_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_esc, dance_esc_finished, dance_esc_reset)
    // [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finishxed, dance_1_reset),
    // [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
};
