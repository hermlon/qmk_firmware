/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "teensy_lc_onekey.h"

enum custom_keycodes {
  KC_AE = SAFE_RANGE,
  KC_OE,
  KC_UE,
  KC_SS
};

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
		LAYOUT(
		KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
                KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
                KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
                KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LSFT,
                KC_LCTL, MO(1), KC_LALT, KC_SPC, KC_ALGR, KC_LGUI, KC_RGUI, MO(2)),

		LAYOUT(
                KC_GRAVE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DELETE, 
                KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
		
		LAYOUT(
                KC_TRNS, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, KC_TRNS, KC_TRNS, KC_TRNS, 
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, KC_TRNS, KC_TRNS, KC_UE, KC_TRNS, KC_OE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                KC_TRNS, KC_AE, KC_SS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_AE:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LGUI) SS_TAP(X_A) SS_LSFT(SS_TAP(X_QUOTE)));
      }
      break;
    case KC_OE:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LGUI) SS_TAP(X_O) SS_LSFT(SS_TAP(X_QUOTE)));
      }
      break;
    case KC_UE:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LGUI) SS_TAP(X_U) SS_LSFT(SS_TAP(X_QUOTE)));
      }
      break;
    case KC_SS:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LGUI) SS_TAP(X_S) SS_TAP(X_S));
      }
      break;
}
  return true;
};
