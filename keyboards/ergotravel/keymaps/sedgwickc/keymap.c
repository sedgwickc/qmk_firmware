#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

enum unicode_name {
  BANG, // ‽
  IRONY, // ⸮
  SNEK // snke 🐍
};

const uint32_t PROGMEM unicode_map[] = {
  [BANG]      = 0x0203D, // ‽
  [IRONY]     = 0x02E2E, // ⸮
  [SNEK]      = 0x1F40D // snke 🐍
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_ADJT ADJUST
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_DBUG DEBUG
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
     TAB , Q  , W  , E  , R  , T  , ESC,      PGUP,  Y , U  , I  , O  , P  ,BSPC,
  //|----+----+----+----+----+----+----|     |----+----+----+----+---+----+----|
     LSPO, A  , S  , D  , F  , G  , F5 ,    PGDOWN,  H , J  , K  , L  ,SCLN,RSPC,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
     LCTL, Z  , X  , C  , V  , B  , DEL,       INS,  N , M  ,COMM,DOT ,SLSH,RCTL ,
  //|----+----+----+----+----+----+----.     .----+----+----+----+----+----+----|
     PSCR,LGUI,LEFT,RIGHT,LOWR,ENT,                 SPC,RASE,UP ,DOWN,LGUI,LALT
  //`----+----+----+--+-+----/----/               \----\----+----+----+----+----'
  ),

  [_LOWER] = LAYOUT_kc(
    //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
        NO ,EXLM, AT ,LCBR,RCBR,GRAVE,NO ,       NO , END, 7  , 8  , 9  , NO ,NO,
    //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
       MINS,HASH, DLR,ASTR,EQUAL,PIPE, NO,       NO, HOME, 4  , 5  , 6  , NO ,UNDS,
    //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
        NO ,PERC,CIRC,LBRC,RBRC,TILD, NO ,      MUTE,AMPR, 1  , 2  , 3  ,BSLS,ENT ,
    //|----+----+----+----+----+----+----.     .----+----+----+----+----+----+----|
        NO , NO , NO , NO , NO ,NO,                 DQT,QUOTE, PLUS, 0  , NO , NO 
    //`----+----+----+--+-+----/----/               \----\----+----+----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
    //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
        NO ,EXLM, AT ,LCBR,RCBR,GRAVE, NO,       NO , NO , F7 , F8 , F9 , F10,BSPC,
    //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
       MINS,HASH, DLR,ASTR,EQUAL,PIPE, NO,        D,  Y  , F4 , F5 , F6 , F11,DEL ,
    //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
        NO ,PERC,CIRC,LBRC,RBRC,TILD, NO ,      SPC,  N  , F1 , F2 , F3 , F12,ENT ,
    //|----+----+----+----+----+----+----.     .----+----+----+----+----+----+----|
        NO , NO , NO , NO , NO ,NO,                  SPC, RASE,LEFT, UP ,DOWN,RIGHT
    //`----+----+----+--+-+----/----/               \----\----+----+----+----+----'
  ),

  [_ADJUST] = LAYOUT_kc(
    //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
       ESC , F1 , F2 , F3 , F4 , F5 , F6,         F7,  F8, F9 ,F10 , F11, F12,BSPC,
    //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
       TAB , Q  , W  , E  , R  , T  , C ,         D,  Y  , U  , I  , O  , P  ,DEL ,
    //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
       LSFT, Z  , X  , C  , V  , B  , A,        SPC,  N  , M  ,COMM,DOT ,SLSH,ENT ,
    //|----+----+----+----+----+----+----.     .----+----+----+----+----+----+----|
       LCTL,LGUI,LALT,ADJT,LOWR,SPC,                 SPC, RASE,LEFT, UP ,DOWN,RIGHT
    //`----+----+----+--+-+----/----/               \----\----+----+----+----+----'
  )

};

   



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
