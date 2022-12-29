/*
 * ldr.c
 *
 *  Created on: Sep 7, 2022
 *      Author: Toshiba
 */
#include "ldr.h"
#include "../dio/dio.h"
#include <avr/delay.h>

void ldr_init()
{

	dio_set_direction(DIOA, PIN_0, INPUT);

	float result = 0.0;
	float volt=0.0;

	adc_init();
	adc_select_channel(0);
	dio_set_direction(DIOA,PIN_4, OUTPUT);
	//dio_set_level(DIOB, PIN_0, 0);
	//_delay_ms(500);


		adc_start_conv();
		while(adc_is_dataready() == 0);
		result = adc_get_data();
		//volt = result*STEP;
		volt = (result*5.0)/1024.0;
		if(volt < 5.0f && volt > 3.0f)
			{dio_set_level(DIOA, PIN_4, HIGH);
			}
		else if(volt < 3.0f && volt > 1.0f)
			{
			dio_set_level(DIOA, PIN_4, LOW);
			}

		_delay_ms(100);


}
