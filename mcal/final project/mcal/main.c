/*
 * main.c
 *
 *  Created on: Sep 6, 2022
 *      Author: Toshiba
 */

#include <avr/io.h>
#include <avr/delay.h>
#include "adc/adc.h"
#include "dio/dio.h"
#include "lcd/lcd.h"
#include "dc/dc.h"
#include "lm35/lm.h"


int main()
{
	dio_set_direction(DC_LEFT_PORT,DC_LEFT_PIN,  OUTPUT);
	dio_set_direction(DC_RIGHT_PORT,DC_RIGHT_PIN,  OUTPUT);

	dio_set_direction(DIOA, PIN_1, INPUT);
	dio_set_direction(DIOA, PIN_5, OUTPUT);

	lcd_init();
	keypad_init();
	adc_init();

	dio_set_direction(DIOA, PIN_0, INPUT);
	dio_set_direction(DIOA,PIN_4, OUTPUT);

	float result = 0.0;
	float volt=0.0;
	uint8_t lm_result = 0;
	float celsius = 0.0;

	while(1)
	{
		LM35_init();
		LM35_start();

		char key = key_get_pressed_key();
				if(key != 0)
				{
					lcd_send_data(key);
					check_pass(key);
				}

		adc_select_channel(0);
		ldr_init();

	}
	return  0 ;
}
