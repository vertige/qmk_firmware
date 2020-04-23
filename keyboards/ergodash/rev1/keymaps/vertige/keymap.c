#include QMK_KEYBOARD_H

// Layer assignments
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  // Layers
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Simple keycode assignments
#define EISU LALT(KC_GRV)
#define OS_LSFT OSM(MOD_LSFT)
#define CAPT SGUI(KC_3) // Command+Shift+3 on MacOS captures part of screen
#define OS_LGUI OSM(MOD_LGUI)
#define SFT_TAB S(KC_TAB)

//Tap Dance Declarations
enum {
  CP_CUT = 0,
  PT_ALL,
  LPR_AN,
  RPR_AN,
  SL_QM,
  BSL_CL,
  UNDO_R,
  MEDIA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |   =  |                    |   -  |   6  |   7  |   8  |   9  |   0  |Pscree| <- Opted for Cmd+Shift+3 (copy part of screen)
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  `   |   Q  |   W  |   E  |   R  |   T  |   [  |                    |   ]  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |  (.< |                    | >.)  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | Tab  | (<-sm upper key->) | Media|   N  |   M  |   ,  |   .  |   /  |  Up  |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  Alt |  Gui |Cp.Cut|------| Lower| Space|  Del |------| Bksp | Enter| Raise|------|Pt.All| Left | Right| Down |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_EQL ,                        KC_MINS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    CAPT,    \
    KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                        KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    TD(LPR_AN),                  TD(RPR_AN), KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    OS_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_TAB,                       TD(MEDIA), KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   \
    KC_LCTL, KC_LALT, OS_LGUI, TD(CP_CUT),       LOWER,   KC_SPC ,KC_DEL,         KC_BSPC,KC_ENT , RAISE,         TD(PT_ALL), KC_LEFT, KC_RGHT, KC_DOWN  \
  ),

  /* Lower (Contains Num Pad Layout)
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   @  |                    |   !  |   %  |   7  |   8  |   9  |   *  |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  ~   |   !  |   @  |   #  |   $  |   %  | \.:  |                    | /.?  |   ^  |   4  |   5  |   6  |   +  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   1  |   2  |   3  |   4  |   5  |   &  |                    |   |  |   (  |   7  |   8  |   9  |   -  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |ShfTab| (<-sm upper key->) |Und.Re|   )  |   0  |   =  |   .  |   /  |PageUp|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  Alt |  GUI |Cp/Cut|------| Lower| Space|  Del |------| Bksp | Enter| Raise|------|Pt/All| Home |  End |PageDn|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_AT,                          KC_EXLM, KC_PERC, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,  \
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, TD(BSL_CL),                   TD(SL_QM), KC_CIRC, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_PIPE, \
    KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_AMPR,                        KC_PIPE, KC_LPRN, KC_1,    KC_2,    KC_3,    KC_MINS, KC_DQT , \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    SFT_TAB,                     TD(UNDO_R), KC_RPRN, KC_M,    KC_EQL,  KC_DOT,  KC_SLSH, KC_PGUP, \
    KC_LCTL, KC_LALT, OS_LGUI, TD(CP_CUT),       LOWER,   KC_SPC ,KC_DEL,         KC_BSPC,KC_ENT , RAISE,         TD(PT_ALL), KC_HOME, KC_END,  KC_PGDN  \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   @  |                    |   !  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  ~   |   !  |   @  |   #  |   $  |   %  | \.:  |                    | /.?  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   1  |   2  |   3  |   4  |   5  |   &  |                    |   |  |   6  |   7  |   8  |   9  |   0  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |ShfTab| (<-sm upper key->) |Und.Re|   N  |   M  |   <  |   >  |   ?  |PageUp|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  Alt |  GUI |Cp/Cut|------| Lower| Space|  Del |------| Bksp | Enter| Raise|------|Pt/All| Home |  End |PageDn|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_AT,                          KC_EXLM, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LCBR,                        KC_RCBR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, TD(BSL_CL),                   TD(SL_QM), KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_AMPR,                        KC_PIPE, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DQT , \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    SFT_TAB,                     TD(UNDO_R), KC_N,    KC_M,    KC_LT,   KC_GT,   KC_QUES, KC_PGUP, \
    KC_LCTL, KC_LALT, OS_LGUI, TD(CP_CUT),       LOWER,   KC_SPC ,KC_DEL,         KC_BSPC,KC_ENT , RAISE,         TD(PT_ALL), KC_HOME, KC_END,  KC_PGDN  \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      | BL ON|  BRTG|  INC|   DEC|      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

// TAP DANCE FUNCTIONS
void copy_cut(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code(KC_LGUI); register_code(KC_C); unregister_code(KC_LGUI); unregister_code(KC_C);
    break;
  case 2:
    register_code(KC_LGUI); register_code(KC_X); unregister_code(KC_LGUI); unregister_code(KC_X);
    break;
  }
}

void paste_select_all(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code(KC_LGUI); register_code(KC_V); unregister_code(KC_LGUI); unregister_code(KC_V);
    break;
  case 2:
    register_code(KC_LGUI); register_code(KC_A); unregister_code(KC_LGUI); unregister_code(KC_A);
    break;
  }
}

void undo_redo(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code(KC_LGUI); register_code(KC_Z); unregister_code(KC_LGUI); unregister_code(KC_Z);
    break;
  case 2:
    register_code(KC_LGUI); register_code(KC_LSFT); register_code(KC_Z); unregister_code(KC_LGUI); unregister_code(KC_LSFT); unregister_code(KC_Z);
    break;
  }
}

void left_paren_angle(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code(KC_LSFT); register_code(KC_9); unregister_code(KC_LSFT); unregister_code(KC_9);
    break;
  case 2: 
    register_code(KC_LSFT); register_code(KC_COMM); unregister_code(KC_LSFT); unregister_code(KC_COMM);
    break;
  }
}

void right_paren_angle(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code(KC_LSFT); register_code(KC_0); unregister_code(KC_LSFT); unregister_code(KC_0);
    break;
  case 2: 
    register_code(KC_LSFT); register_code(KC_DOT); unregister_code(KC_LSFT); unregister_code(KC_DOT);
    break;
  }
}

void play_mute(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code(KC_MEDIA_PLAY_PAUSE); unregister_code(KC_MEDIA_PLAY_PAUSE);
    break;
  case 2: 
    register_code(KC_MUTE); unregister_code(KC_MUTE);
    break;
  }
}

void slash_question(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code(KC_SLSH); unregister_code(KC_SLSH);
    break;
  case 2: 
    register_code(KC_LSFT); register_code(KC_SLSH); unregister_code(KC_LSFT); unregister_code(KC_SLSH);
    break;
  }
}

void backslash_colon(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code(KC_BSLS); unregister_code(KC_BSLS);
    break;
  case 2: 
    register_code(KC_LSFT); register_code(KC_SCLN); unregister_code(KC_LSFT); unregister_code(KC_SCLN);
    break;
  }
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once to copy, twice to cut
  [CP_CUT] = ACTION_TAP_DANCE_FN(copy_cut),
  //Tap once to paste, twice to select all
  [PT_ALL] = ACTION_TAP_DANCE_FN(paste_select_all),
  [LPR_AN] = ACTION_TAP_DANCE_FN(left_paren_angle),
  [RPR_AN] = ACTION_TAP_DANCE_FN(right_paren_angle),
  [SL_QM]  = ACTION_TAP_DANCE_FN(slash_question),
  [BSL_CL] = ACTION_TAP_DANCE_FN(backslash_colon),
  [UNDO_R] = ACTION_TAP_DANCE_FN(undo_redo),
  //Tap once to play/pause, twice to mute
  [MEDIA]  = ACTION_TAP_DANCE_FN(play_mute),
};

// Predefined functions from Rev1 default
#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
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
