/*
#include "AVR_DIO_REG.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "KeyPad_int.h"
#include "LCD.int.h"
#include <util/delay.h>
#include "EXTI.h"
#include "timer0.h"
#include "Adc.h"
#include <stdlib.h>
/*
int main (void )
{
	 DIO_voidSetPortDirection (DIO_PORTA , DIO_PORT_INPUT);
	 DIO_voidSetPortDirection (DIO_PORTB , DIO_PORT_OUTPUT);
	 Init_void_Adc();
	 intialize_LCD();

	    u8 string[5];
	 	u16 reading=0 ;
	 	 lcd_voidGoToX_Y(0,7);
	 			 	WriteData ('*');
	 			 	lcd_voidGoToX_Y(0,8);
	 			 	WriteData('C');

while(1)
{
	        Start_void_Adc_1_converstion();
		 	LM35(&reading);
		 	itoa(reading,string,10);
		 	lcd_voidGoToX_Y(0,5);
		 	LCD_u8WriteString(string);


}


}

int main (void )
{
	DIO_voidSetPortDirection (DIO_PORTA , DIO_PORT_OUTPUT);

	while(1)
	{
		DIO_voidSetPinValue (DIO_PORTA,0 ,DIO_PIN_HIGH);
		_delay_ms(1);
		DIO_voidSetPinValue (DIO_PORTA,0 ,DIO_PIN_LOW);
		_delay_ms(19);
		_delay_ms(500);
		        DIO_voidSetPinValue (DIO_PORTA,0 ,DIO_PIN_HIGH);
				_delay_ms(1.5);
				DIO_voidSetPinValue (DIO_PORTA,0 ,DIO_PIN_LOW);
				_delay_ms(18.5);
				_delay_ms(500);
				DIO_voidSetPinValue (DIO_PORTA,0 ,DIO_PIN_HIGH);
						_delay_ms(2);
						DIO_voidSetPinValue (DIO_PORTA,0 ,DIO_PIN_LOW);
						_delay_ms(18);
						_delay_ms(500);


	}

}
*/

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

// define some macros
#define BAUD 19200                                   // define baud
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)            // set baud rate value for UBRR

// function to initialize UART
void UART_voidInit (void)
{
    UBRRH = (BAUDRATE>>8);                      // shift the register right by 8 bits
    UBRRL = BAUDRATE;     // set baud rate

    /*
• Bit 4 – RXEN: Receiver Enable

Writing this bit to one enables the USART Receiver. The Receiver will override normal
port operation for the RxD pin when enabled. Disabling the Receiver will flush the
receive buffer invalidating the FE, DOR, and PE Flags.

• Bit 3 – TXEN: Transmitter Enable

Writing this bit to one enables the USART Transmitter. The Transmitter will override nor-
mal port operation for the TxD pin when enabled. The disabling of the Transmitter
(writing TXEN to zero) will not become effective until ongoing and pending transmis-
sions are completed, i.e., when the transmit Shift Register and transmit Buffer Register*/

    UCSRB|= (1<<TXEN)|(1<<RXEN);                // enable receiver and transmitter


    //UCSZ1 UCSZ0 on UCSRC
    UCSRC|= (1<<UCSZ0)|(1<<UCSZ1);   // 8bit data format
}


static void sendChar(unsigned char myChar)
{//The UDRE Flag indicates if the transmit buffer (UDR) is ready to receive new data
	while(!(UCSRA&(1<<UDRE)));
	UDR=myChar;
}

void UART_voidSendString(char*str)
{
	static int i=0;
	while(str[i] !='\0')
	{
		sendChar(str[i]);
		i++;
	}
	i=0;
	//while(*str>0)
	//{
	//	sendChar(*str++);
	//}
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
		UART_voidSendString("ahmed mohamed / ahmed khaled / omer  / Ghith");

		_delay_ms(1000);

	}
	return 0;
}



