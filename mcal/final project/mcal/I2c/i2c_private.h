/*
 * i2c_private.h
 *
 *  Created on: Sep 2, 2022
 *      Author: Toshiba
 */

#ifndef UART_I2C_PRIVATE_H_
#define UART_I2C_PRIVATE_H_

#define WRITE_BIT				1
#define READ_BIT				0

#define MASTER_START			0x08
#define MASTER_RESTART			0x10
#define MASTER_ARBITRATION		0x38

#define MASTER_WR_SADD_ACK		0x18
#define MASTER_WR_SADD_NACK		0x20
#define MASTER_WR_DATA_ACK		0x28
#define MASTER_WR_DATA_NACK		0x30

#define MASTER_RE_SADD_ACK		0x40
#define MASTER_RE_SADD_NACK		0x248
#define MASTER_RE_DATA_ACK		0x50
#define MASTER_RE_DATA_NACK		0x58

#endif /* UART_I2C_PRIVATE_H_ */
