/*
 * LM35.c
 *
 * Created: 9/7/2022 7:06:58 PM
 *  Author: Pc
 */

 #include "LM.h"
 #include <stdint.h>
 #include "../dc/dc.h"

 void LM35_init()
 {

	 adc_init();
	 adc_select_channel(1);
 }

 void LM35_start()
 {
	uint8_t result;
	float celsius;
	adc_start_conv();
	while(adc_is_dataready()==0);
	 result = adc_get_data();

	celsius = (result*4.88);
	celsius = (celsius/10.00);

	if((int)celsius>5)

	{


		dc_start();


	}

	else if((int)celsius<=5)
	{

		dc_stop();


	}



 }
