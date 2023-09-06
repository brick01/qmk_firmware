#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F8  |  F9  |  F10 |  F11 |  F12 | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |  ; : |  ' " |
 * |------+------+------+------+------+------|L_KNOB |    |R_KNOB |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |  , < |  . > |  / ? |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_QWERTY] = LAYOUT(
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    DM_REC1, DM_PLY1, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                          KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC,  KC_ENT,  MO(_RAISE), KC_BSPC, KC_RGUI
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      | HOME | PGUP | PGDN | END  |      |                    |  F6  |  F7  | PSCR | SCRL | PAUS | INST |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   `  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   ~  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   [  |   ]  |   \  |   -  |   =  |-------|    |-------|   |  |   _  |   +  |   {  |   }  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______,                   KC_F6,   KC_F7,   KC_PSCR, KC_SCRL, KC_PAUS, KC_INS,
  KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
  _______, KC_LBRC, KC_RBRC, KC_BSLS, KC_MINS, KC_EQL,  _______, _______, KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |VIM W |VIM E |      |      |                    | Copy | Undo |      |      |Paste |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |VIM D |      |      |-------.    ,-------| Left | Down |  Up  |Right | HOME | END  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |VIM X |      |      |VIM B |-------|    |-------|      | PGDN | PGUP |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, LCTL(KC_RGHT), LCTL(KC_RGHT), _______, _______,       RCTL(KC_INS), RCTL(KC_Z), _______, _______, RSFT(KC_INS), _______,
  _______, _______, _______, KC_BSPC, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_HOME, KC_END,
  _______, _______, KC_DEL,  _______, _______, LCTL(KC_LEFT), _______, _______, _______, KC_PGDN, KC_PGUP, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      | XXXX | XXXX | XXXX |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | XXXX | XXXX | XXXX |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_ADJUST] = LAYOUT(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______
  )
};

/* Activate the adjust state
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
*/

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}

// Rotary encoder related code
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { // Encoder on master side
    if(IS_LAYER_ON(_RAISE)) { // on Raise layer
      //
      if (clockwise) {
          tap_code16(C(KC_TAB));
      } else {
          tap_code16(C(S(KC_TAB)));
      }
    }
    else {
      if (clockwise) {
          tap_code16(A(KC_TAB));
      } else {
          tap_code16(A(S(KC_TAB)));
      }
    }
  }
  else if (index == 1) { // Encoder on slave side
    if(IS_LAYER_ON(_LOWER)) { // on Lower layer
      //
      if (clockwise) {
          tap_code(KC_PGUP);
      } else {
          tap_code(KC_PGDN);
      }
    }
    else {
      if (clockwise) {
          tap_code(KC_VOLU);
      } else {
          tap_code(KC_VOLD);
      }
    }
  }
    return true;
}
#endif
