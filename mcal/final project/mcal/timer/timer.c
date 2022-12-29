/*
 * timer.c
 *
 *  Created on: Sep 1, 2022
 *      Author: Toshiba
 */

#include "timer.h"
#include "../dio/dio.h"
#include <avr/io.h>

#define SET_BIT(reg, bit_n) 	reg |= 1<<bit_n
#define CLR_BIT(reg, bit_n)		reg &= ~(0b1<<bit_n)

void timer0_init()
{
	//NORMAL
	CLR_BIT(TCCR0, WGM00);
	CLR_BIT(TCCR0, WGM01);
	//preload
	TCNT0 = 0;
	//prescaller -> 1024
	SET_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS01);
	SET_BIT(TCCR0, CS02);
	//enable interrupt
	SET_BIT(TIMSK, TOIE0);
}

void timer0_deinit()
{
	CLR_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);
	//disable interrupt
	CLR_BIT(TIMSK, TOIE0);
}

uint8_t timer0_get_counter()
{
	return TCNT0;
}

void pwm_init()
{
	//FAST PWM
	SET_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);
	//preload
	TCNT0 = 0;
	//prescaller -> 64
	SET_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);
	//NON-inverting mode
	CLR_BIT(TCCR0, COM00);
	SET_BIT(TCCR0, COM01);
//	//enable interrupt
//	SET_BIT(TIMSK, TOIE0);
//	SET_BIT(TIMSK, OCIE0);
//	//overflow flag
//	SET_BIT(TIFR, OCF0);

	dio_set_direction(DIOB, PIN_3, OUTPUT);
}

void pwm_deinit()
{
	CLR_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);
	//disable interrupt
	CLR_BIT(TIMSK, TOIE0);
}

uint8_t pwm_counter()
{
	return TCNT0;
}
