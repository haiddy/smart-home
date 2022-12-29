/*
 * adc.h
 *
 *  Created on: Sep 6, 2022
 *      Author: Toshiba
 */

#ifndef ADC_ADC_H_
#define ADC_ADC_H_

#include <stdint.h>

typedef enum
{
	ADC_AUTORUN
} adc_trigger_t;

void adc_init(void);
void adc_select_channel(uint8_t channel);
void adc_set_trigger(uint8_t state);
void adc_select_trigger(adc_trigger_t trigger);
void adc_start_conv();

uint8_t adc_is_dataready();
uint16_t adc_get_data();

#endif /* ADC_ADC_H_ */
