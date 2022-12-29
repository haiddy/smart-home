/*
 * keypad_private.h
 *
 *  Created on: Sep 6, 2022
 *      Author: Toshiba
 */

#ifndef KEYPAD_KEYPAD_PRIVATE_H_
#define KEYPAD_KEYPAD_PRIVATE_H_

#include "../dio/dio.h"

typedef struct{
		dio_t port;
		dio_pin_t pin;
}porting_t;

#endif /* KEYPAD_KEYPAD_PRIVATE_H_ */
