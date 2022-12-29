/*
 * timer.h
 *
 *  Created on: Sep 1, 2022
 *      Author: Toshiba
 */

#ifndef TIMER_TIMER_H_
#define TIMER_TIMER_H_

#include <stdint.h>

typedef enum
{
	TIMER0,
	TIMER1,
	TIMER2
} timer_t;

typedef enum
{
	NORMAL = 0,
	CTC,
	PWM,
	FAST_PWM
} timer_output_t;

typedef enum
{
	TIMER_NO_CLKSRC,
	TIMER_PRESC_1,
	TIMER_PRESC_8,
	TIMER_PRESC_64,
	TIMER_PRESC_256,
	TIMER_PRESC_11024,
	TIMER_EXTCLK_RISING,
	TIMER_EXTCLK_FALLING
} timer_clksrc_t;

typedef enum
{
	CTC_PIN_DISCONNECTED,
	CTC_PIN_TOGGLE,
	CTC_PIN_CLR,
	CTC_PIN_SET
} ctc_outmode_t;

typedef struct
{
	//timer_mode_t mode;
	timer_output_t output_mode;
	timer_clksrc_t prescaller;
	uint8_t int_state;
} timer_config_t;

void timer_init(timer_t timer, timer_config_t config);
void timer_set_state(uint8_t state);
void timer_set_preload(timer_t timer, uint16_t preload);
void timer_set_ctcmode(timer_t timer, ctc_outmode_t ctcmode);
void timer_set_interrupt(uint8_t state);
uint16_t timer_get_counter();
uint8_t timer_is_overflow(timer_t timer);

void timer0_init();
void timer0_deinit();
uint8_t timer0_get_counter();

void pwm_init();
void pwm_deinit();
uint8_t pwm_get_counter();

#endif
