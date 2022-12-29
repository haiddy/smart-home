/*
 * spi.h
 *
 *  Created on: Aug 31, 2022
 *      Author: Toshiba
 */

#ifndef SPI_SPI_H_
#define SPI_SPI_H_

#include <stdint.h>

void master_init();
void slave_init();
uint8_t transfer_data(uint8_t data);

#endif /* SPI_SPI_H_ */
