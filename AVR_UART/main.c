/*
 * main.c
 *
 *  Created on: Oct 12, 2019
 *      Author: ABDEEN
 */
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

// define some macros
#define BAUD 9600                                   // define baud
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)            // set baud rate value for UBRR

// function to initialize UART
void UART_voidInit (void)
{
    UBRRH = (BAUDRATE>>8);                      // shift the register right by 8 bits
    UBRRL = BAUDRATE;                           // set baud rate
    UCSRB|= (1<<TXEN)|(1<<RXEN);                // enable receiver and transmitter
    UCSRC|= (1<<UCSZ0)|(1<<UCSZ1);   // 8bit data format
}


static void sendChar(unsigned char myChar)
{
	while(!(UCSRA&(1<<UDRE)));
	UDR=myChar;
}

void UART_voidSendString(char*str)
{
//	static int i=0;
//	while(str[i] !='\0')
//	{
//		sendChar(str[i]);
//		i++;
//	}
//	i=0;
	while(*str>0)
	{
		sendChar(*str++);
	}
}




// function to receive data
unsigned char UART_voidReceiveChar (void)
{
    while(!((UCSRA) & (1<<RXC)));                   // wait while data is being received
    return UDR;                                   // return 8-bit data
}

int main(void)
{
	UART_voidInit();
	DDRA=0xFF;
	while(1)
	{
		UART_voidSendString("Amr Abdeen ");
		_delay_ms(500);

	}
	return 0;
}

