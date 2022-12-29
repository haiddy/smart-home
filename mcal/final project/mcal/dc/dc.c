/*
 * dc.c
 *
 * Created: 9/7/2022 7:07:30 PM
 *  Author: Pc
 */
 #include "dc.h"

void dc_start()
 {

	dio_set_level(DC_LEFT_PORT,DC_LEFT_PIN,HIGH);
	dio_set_level(DC_RIGHT_PORT,DC_RIGHT_PIN,LOW);
 }

 dc_stop()
 {

	 dio_set_level(DC_LEFT_PORT,DC_LEFT_PIN,LOW);
	 dio_set_level(DC_RIGHT_PORT,DC_RIGHT_PIN,LOW);
 }
