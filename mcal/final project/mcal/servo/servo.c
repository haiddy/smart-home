/*
 * servo.c

 *
 *  Created on: Aug 28, 2022
 *      Author: Desktop
 */

#include <avr/io.h>
#include "servo.h"
#include "../lcd/lcd.h"
#include "servo_config.h"
#include "../dio/dio.h"
#include <avr/delay.h>

#define SET_BIT(reg, bit_n)   reg|= 1<<bit_n;
#define CLR_BIT(reg, bit_n)   reg&= ~(1<<bit_n);
static int i=0;
static int counter =0;
static int pazz =0;
char arr_pass[PASS_LENGTH] = PASS;
char arr_key[PASS_LENGTH];

void check_pass(char key)
{

	//arr_key[i] = key;
	//char a = i+'0';
	if(key == arr_pass[i])
	{
		counter ++;
	}
	else
	{
		pazz++;
	}

	if(counter == 4)
	{
		init_servo();
		servo_move90();
		 lcd_set_curser(0,0);
		 lcd_send_data('W');
		 lcd_send_data('E');
		 lcd_send_data('L');
		 lcd_send_data('L');
		 lcd_send_data('C');
		 lcd_send_data('O');
		 lcd_send_data('M');
		 lcd_send_data('E');
		 _delay_ms(1000);
		 servo_move0();
	}
	else if(pazz == 4)
	{

		dio_set_level(DIOA, PIN_5, HIGH);
		lcd_set_curser(0,0);
				 lcd_send_data('W');
				 lcd_send_data('r');
				 lcd_send_data('o');
				 lcd_send_data('n');
				 lcd_send_data('g');
				 lcd_send_data(' ');
				 lcd_send_data('P');
				 lcd_send_data('a');
				 lcd_send_data('s');
				 lcd_send_data('s');
				 lcd_send_data('!');
				 lcd_send_data('!');

	}

	i++;
}


void init_servo(){

	 //Fast pwm
	dio_set_direction(DIOD,PIN_5,OUTPUT);
	 CLR_BIT(TCCR1A, WGM10);
	 SET_BIT(TCCR1A, WGM11);
	 SET_BIT(TCCR1B, WGM12);
	 SET_BIT(TCCR1B, WGM13);

	 ICR1=2499;
	 TCNT1=0;

	 //clear on compare
	  SET_BIT(TCCR1A, COM1A1);
	  CLR_BIT(TCCR1A, COM1A0);

	 //clk source -> 64
	 CLR_BIT(TCCR1B, CS10);
	 SET_BIT(TCCR1B, CS11);
	 CLR_BIT(TCCR1A, CS12);


	 //output compare register
	// SET_BIT(TCCR1A, OCR1A);
	// SET_BIT(TCCR1A, CS10);

}

void servo_move90(){
	OCR1A = 2000;	/* Set servo at +90° position */
	//_delay_ms(1500);

 }

void servo_move0(){
	 OCR1A = 0;	/* Set servo at 0° position */
	 //_delay_ms(1500);
 }
