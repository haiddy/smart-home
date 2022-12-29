/*
 * keypad.h
 *
 *  Created on: Sep 6, 2022
 *      Author: Toshiba
 */

#ifndef KEYPAD_KEYPAD_H_
#define KEYPAD_KEYPAD_H_

#include <stdint.h>

void keypad_init();
uint8_t key_get_pressed_key();

#endif /* KEYPAD_KEYPAD_H_ */
