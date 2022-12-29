/*
 * LM35.h
 *
 * Created: 9/7/2022 7:06:42 PM
 *  Author: Pc
 */
 #include "../dio/dio.h"
 #include "../adc/adc.h"

#ifndef LM35_H_
#define LM35_H_

#define LM35_PORT	DIOA
#define LM35_PIN	PIN_1

void LM35_init();
void LM35_start();

#endif /* LM35_H_ */
