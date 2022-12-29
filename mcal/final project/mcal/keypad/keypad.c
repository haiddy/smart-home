#include "keypad_config.h"
 #include "keypad_private.h"
 #include "keypad.h"
 #include <stdint.h>
 # define F_CPU 1000000UL
 #include <util/delay.h>



 void keypad_init ()
 {

	porting_t raw_arr [KEYPAD_RAW_NUM] = KEYPAD_RAW_ARR_VALUE;
	porting_t column_arr [KEYPAD_COLUMN_NUM] = KEYPAD_COL_ARR_VALUE;

	for (int i = 0 ; i < KEYPAD_RAW_NUM ; i++)
	{
		dio_set_direction(raw_arr[i].port,raw_arr[i].pin,INPUT);
	}



	for (int i =0 ; i < KEYPAD_COLUMN_NUM ; i++)
	{
		dio_set_direction(raw_arr[i].port,column_arr[i].pin,OUTPUT);
	}

 }

 uint8_t key_get_pressed_key()
 {
	char keys[KEYPAD_RAW_NUM][KEYPAD_COLUMN_NUM] = KEYPAD_KEY_VALUES;

	porting_t row_arr[KEYPAD_RAW_NUM] = KEYPAD_RAW_ARR_VALUE;
	porting_t col_arr[KEYPAD_COLUMN_NUM] = KEYPAD_COL_ARR_VALUE;

	//while(1)
	//{

	for(int8_t i = 0; i < KEYPAD_COLUMN_NUM; i++)
	{
		dio_set_level(col_arr[i].port,col_arr[i].pin,HIGH);
	}


	for(uint8_t c = 0; c < KEYPAD_COLUMN_NUM; c++)
	{
		dio_set_level(col_arr[c].port,col_arr[c].pin, LOW);

		for(uint8_t i = 0; i < KEYPAD_RAW_NUM; i++)
		{
			_delay_ms(5);

			if(dio_get_level(row_arr[i].port,row_arr[i].pin) == LOW)
			{
				_delay_ms(3);

				while(dio_get_level(row_arr[i].port,row_arr[i].pin) == LOW)
				{

				}

				return keys[i][c];
			}

		}
		dio_set_level(col_arr[c].port,col_arr[c].pin, HIGH);
	}
	//}
	return 0;

 }
