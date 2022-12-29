/*
 * uart.h
 *
 *  Created on: Aug 31, 2022
 *      Author: Toshiba
 */

#ifndef UART_UART_H_
#define UART_UART_H_

#include <stdint.h>

void uart_init();
void uart_send_data(uint8_t data);
uint8_t uart_receive_data();
uint8_t uart_is_data_ready();
void uart_send_str(char* str);
void uart_receive_str(char* str,uint8_t length,char terminal);
void uart_set_tx_callback(void (*callback)(void));
void uart_set_rx_callback(void (*callback)(void));

#endif /* UART_UART_H_ */
