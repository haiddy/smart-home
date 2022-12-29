/*
 * spi.c
 *
 *  Created on: Aug 31, 2022
 *      Author: Toshiba
 */
#include "spi.h"
#include <avr/io.h>

#define SET_BIT(reg, bit_n)		reg |= (0b1<<bit_n)
#define CLR_BIT(reg, bit_n)		reg &= ~(0b1<<bit_n)
#define GET_BIT(reg, bit_n)		((reg>>bit_n)&0x01)

void master_init()
{
	SET_BIT(SPCR,SPE);		//enable spi
	SET_BIT(SPCR,DORD);		//LSB
	SET_BIT(SPCR,MSTR); 	//Master select
	CLR_BIT(SPCR,CPOL);		//clock polarity  leading:falling edge
	SET_BIT(SPCR,CPHA);		//setup : leading edge

	CLR_BIT(SPCR,SPR0);		//prescaller 64
	SET_BIT(SPCR,SPR1);
	CLR_BIT(SPCR,SPI2X);

	SET_BIT(SPCR,SPIE);		//interrupt
}

void slave_init()
{
		SET_BIT(SPCR,SPE);		//enable spi
		SET_BIT(SPCR,DORD);		//LSB
		CLR_BIT(SPCR,MSTR); 	//Slave select
		CLR_BIT(SPCR,CPOL);		//clock polarity  leading:falling edge
		SET_BIT(SPCR,CPHA);		//setup : leading edge

		CLR_BIT(SPCR,SPR0);		//prescaller 64
		SET_BIT(SPCR,SPR1);
		CLR_BIT(SPCR,SPI2X);

		SET_BIT(SPCR,SPIE);
}

uint8_t transfer_data(uint8_t data)
{
	SPDR = data;
	//waiting
	while(GET_BIT(SPSR,SPIF) == 0);

	return SPDR;
}

