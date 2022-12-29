/*
 * adc_config.h
 *
 *  Created on: Sep 6, 2022
 *      Author: Toshiba
 */

typedef enum
{
	AREF = 0b00,
	AVCC = 0b01,
	INTERNAL2_56V = 0b11
}adc_ref_t;

typedef enum
{
	PRESCALLER_2 = 0b00,
	PRESCALLER_4 = 0b10,
	PRESCALLER_8 = 0b11,
	PRESCALLER_16 = 0b01,
	PRESCALLER_32 = 0b101,
	PRESCALLER_64 = 0b011,
	PRESCALLER_128 = 0b111,
}adc_prescaller_val;


#define ADC_REF_VAL			AVCC
#define ADC_AUTO_TRIGGER	0
#define ADC_INT_ENABLE		1
#define ADC_PRESCALLER_SEL	PRESCALLER_64
#define ADC_CHANNEL			0
#define ADC_TRIGGER 		0b000
