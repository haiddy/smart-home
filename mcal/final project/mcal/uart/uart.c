#include "uart.h"
#include <avr/io.h>
#include <avr/interrupt.h>


#define SET_BIT(reg, bit_n)		reg |= (0b1<<bit_n)
#define CLR_BIT(reg, bit_n)		reg &= ~(0b1<<bit_n)
#define GET_BIT(reg, bit_n)		((reg>>bit_n)&0x01)

void (*g_tx_cb)(void);
void (*g_rx_cb)(void);

ISR(USART_TXC_vect)
{
	if(g_tx_cb)
	{
		g_tx_cb();
	}
}

ISR(USART_RXC_vect)
{
	if(g_rx_cb)
	{
		g_rx_cb();
	}
}

void uart_init()
{
	//enable tx , rx
	UCSRB = 1<<RXEN | 1<<TXEN;

	//data size 8
	CLR_BIT(UCSRB, UCSZ2);

	uint8_t ucsrc_val = 0;
	SET_BIT(ucsrc_val,UCSZ0);
	SET_BIT(ucsrc_val,UCSZ1);
	//stop bit size 1
	CLR_BIT(ucsrc_val,USBS);
	//async
	CLR_BIT(ucsrc_val,UMSEL);
	//parity check disabled
	CLR_BIT(ucsrc_val,UPM0);
	CLR_BIT(ucsrc_val,UPM1);

	UCSRC = 1<<URSEL | ucsrc_val;
	//baud rate
	//9600 -> 8MHZ
	UBRRL = 51;
	UBRRH = 0X00;

	//interrupts
	CLR_BIT(UCSRB,RXCIE);
	CLR_BIT(UCSRB,TXCIE);
	CLR_BIT(UCSRB,UDRIE);
}

void uart_send_data(uint8_t data)
{
	while(GET_BIT(UCSRA,UDRE) != 1);
	UDR = data;
}

uint8_t uart_receive_data()
{
	return UDR;
}

uint8_t uart_is_data_ready()
{
	return GET_BIT(UCSRA,RXC);
}

void uart_send_str(char* str)
{
	uint8_t i = 0;
	while(str[i] != '\0')
	{
//		while(GET_BIT(UCSRA,UDRE) != 1);
//		UDR = str[i];
		uart_send_data(str[i]);
		i++;
	}
}

void uart_receive_str(char* str,uint8_t length,char terminal)
{
	uint8_t i=0;
	do
	{
		while(uart_is_data_ready() != 1);
		str[i] = uart_receive_data;
		i++;
	}while(i<length && str[i-1] != terminal);
	str[i--] = 0;
}

void uart_set_tx_callback(void (*callback)(void))
{
	g_tx_cb = callback;
}

void uart_set_rx_callback(void (*callback)(void))
{
	g_tx_cb = callback;
}
