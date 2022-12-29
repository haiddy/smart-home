/*
 * i2c.c
 *
 *  Created on: Sep 2, 2022
 *      Author: Toshiba
 */
#include "i2c.h"
#include "i2c_private.h"
#include <avr/io.h>
#include <avr/delay.h>

#define SET_BIT(reg, bit_n)		reg |= (0b1<<bit_n)
#define CLR_BIT(reg, bit_n)		reg &= ~(0b1<<bit_n)
#define GET_BIT(reg, bit_n)		((reg>>bit_n)&0x01)

void i2c_init_master(uint8_t address)
{
	//clock 400khz
	TWBR = 2;
	CLR_BIT(TWSR, TWPS0);
	CLR_BIT(TWSR, TWPS1);

	//clear status bits
	TWSR &= ~(0b111111<<TWS3);
	//set slave address
	TWSR = address<<1;
	//disable interrupt
	CLR_BIT(TWCR, TWIE);
	//enable i2c
	SET_BIT(TWCR, TWEN);
}

void i2c_init_slave(uint8_t address)
{
	//clear status bits
	TWSR &= ~(0b111111<<TWS3);
	//set slave address
	TWSR = address<<1;
	//disable interrupt
	CLR_BIT(TWCR, TWIE);
	//enable i2c
	SET_BIT(TWCR, TWEN);
}

i2c_err_t i2c_set_start()
{
	i2c_err_t err = I2C_OK;
	uint8_t timeout = 0;
	SET_BIT(TWCR, TWSTA);
	while(GET_BIT(TWCR, TWINT) == 0 && timeout < 20000)
	{
		_delay_ms(1);
		timeout++;
	}
	if(timeout == 20000)
	{
		CLR_BIT(TWCR, TWSTA);
		return I2C_TIMEOUT_ERR;
	}
	CLR_BIT(TWCR, TWSTA);

	if((TWSR & 0xF8) != MASTER_START)
	{
		err = I2C_START_ERR;
	}
//	//clear interrupt flag
//	SET_BIT(TWCR, TWINT);

	return err;
}

i2c_err_t i2c_set_repeatedstart()
{
	i2c_err_t err = I2C_OK;
	uint8_t timeout = 0;
	SET_BIT(TWCR, TWSTA);

	while(GET_BIT(TWCR, TWINT) == 0 && timeout < 20000)
	{
		_delay_ms(1);
		timeout++;
	}
	if(timeout == 20000)
	{
		CLR_BIT(TWCR, TWSTA);
		return I2C_TIMEOUT_ERR;
	}
	CLR_BIT(TWCR, TWSTA);

	if(TWSR & 0xF8 != MASTER_START)
	{
		err = I2C_RESTART_ERR;
	}
	//clear interrupt
	SET_BIT(TWCR, TWINT);

	return err;
}

i2c_err_t i2c_set_stop()
{
	i2c_err_t err = I2C_OK;
	SET_BIT(TWCR, TWSTA);

	return err;
}

i2c_err_t i2c_send_addresswrite(uint8_t address)
{
	i2c_err_t err = I2C_OK;
	TWDR = (address<<1) | WRITE_BIT;
	//clear interrupt flag
	SET_BIT(TWCR, TWINT);
	uint16_t timeout = 0;
	while(GET_BIT(TWCR, TWINT) == 0 && timeout < 20000)
	{
		_delay_ms(1);
		timeout++;
	}
	if(timeout == 20000)
	{
		return I2C_TIMEOUT_ERR;
	}

	if(TWSR & 0xF8 != MASTER_WR_SADD_ACK)
	{
		err = I2C_SLAVE_NACK_ERR;
	}

	return err;
}

i2c_err_t i2c_send_addressread(uint8_t address)
{
	i2c_err_t err = I2C_OK;
	TWDR = (address<<1) | READ_BIT;
	//clear interrupt flag
	SET_BIT(TWCR, TWINT);
	uint16_t timeout = 0;

	while(GET_BIT(TWCR, TWINT) == 0 && timeout < 20000)
	{
		_delay_ms(1);
		timeout++;
	}

	//clear interrupt flag
	SET_BIT(TWCR, TWINT);

	if(timeout == 20000)
	{
		return I2C_TIMEOUT_ERR;
	}

	if(TWSR & 0xF8 != MASTER_RE_SADD_ACK)
	{
		err = I2C_SLAVE_NACK_ERR;
	}

	return err;
}

i2c_err_t i2c_send_data(uint8_t data)
{
	i2c_err_t err = I2C_OK;
	TWDR = data;
	//clear interrupt flag
	SET_BIT(TWCR, TWINT);
	uint16_t timeout = 0;

	while(GET_BIT(TWCR, TWINT) == 0 && timeout < 20000)
	{
		_delay_ms(1);
		timeout++;
	}
	if(timeout == 20000)
	{
		return I2C_TIMEOUT_ERR;
	}

	if(TWSR & 0xF8 != MASTER_WR_SADD_ACK)
	{
		err = I2C_DATA_NACK_ERR;
	}

	return err;
}

i2c_err_t i2c_master_receive_data(uint8_t* buff)
{
	i2c_err_t err = I2C_OK;
	uint16_t timeout = 0;

	if(GET_BIT(TWCR, TWINT) == 1)
	{
		return I2C_FAIL;
	}
	//clear interrupt flag
	SET_BIT(TWCR, TWINT);

	while(GET_BIT(TWCR, TWINT) == 0 && timeout < 20000)
	{
		_delay_ms(1);
		timeout ++;
	}

	if(timeout == 20000)
	{
		return I2C_TIMEOUT_ERR;
	}
	//read status reg
	if(GET_BIT(TWCR, TWINT) == 1)
	{
		if(TWSR & 0xF8 != MASTER_RE_DATA_ACK)
		{
			err = I2C_DATA_NACK_ERR;
		}
	}
	else
	{
		if(TWSR & 0xF8 != MASTER_RE_DATA_ACK)
		{
			err = I2C_FAIL;
		}
	}
	//read data reg
	*buff = TWDR;

	return err;
}

i2c_err_t i2c_slave_receive_data(uint8_t* buff)
{

}

i2c_err_t i2c_set_ack(uint8_t state)
{
	if(state == 1)
	{
		SET_BIT(TWCR, TWEA);
	}
	else
	{
		CLR_BIT(TWCR, TWEA);
	}
}

