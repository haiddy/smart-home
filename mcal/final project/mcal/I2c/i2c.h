/*
 * i2c.h
 *
 *  Created on: Sep 2, 2022
 *      Author: Toshiba
 */

#ifndef I2C_I2C_H_
#define I2C_I2C_H_

#include <stdint.h>

typedef enum
{
	I2C_OK,
	I2C_FAIL,
	I2C_START_ERR,
	I2C_RESTART_ERR,
	I2C_TIMEOUT_ERR,
	I2C_SLAVE_NACK_ERR,
	I2C_DATA_NACK_ERR,
}i2c_err_t;

void i2c_init_master(uint8_t address);
void i2c_init_slave(uint8_t address);

i2c_err_t i2c_set_start();
i2c_err_t i2c_set_repeatedstart();
i2c_err_t i2c_set_stop();
i2c_err_t i2c_send_addresswrite(uint8_t address);
i2c_err_t i2c_send_addressread(uint8_t address);
i2c_err_t i2c_send_data(uint8_t data);
i2c_err_t i2c_master_receive_data(uint8_t* buff);
i2c_err_t i2c_slave_receive_data(uint8_t* buff);
i2c_err_t i2c_set_ack(uint8_t state);

#endif /* I2C_I2C_H_ */
