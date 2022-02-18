/*
 * LCD.prog.c
 *
 *  Created on: Sep 8, 2019
 *      Author: ahmed
 */

#include "AVR_DIO_REG.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "KeyPad_int.h"
#include "LCD.int.h"
#include <util/delay.h>



void Enablepulse ()
{
	DIO_voidSetPinValue (LCD_COMMAND_PORT,DIO_PIN_2, DIO_PIN_HIGH);
	DIO_voidSetPinValue (LCD_COMMAND_PORT,DIO_PIN_2, DIO_PIN_LOW);

	_delay_ms(50);

}
void intialize_LCD()
{
	DIO_voidSetPortDirection (LCD_DATA_PORT , DIO_PORT_OUTPUT);
	DIO_voidSetPortDirection (LCD_COMMAND_PORT , DIO_PORT_OUTPUT);
	DIO_voidSetPortValue (LCD_COMMAND_PORT , 0x00);

		WriteCommand (display_8_bit_2_lines_mode );
		WriteCommand (Clear_display_screen );
		WriteCommand (Display_on_cursor_off );
		WriteCommand (Force_cursor_to_beginning_1st_line );

}

void WriteCommand (u8 command )
{//Rs =0 for command port
	DIO_voidSetPinValue (LCD_COMMAND_PORT,DIO_PIN_0, DIO_PIN_LOW);
	DIO_voidSetPortValue (LCD_DATA_PORT , command);
	Enablepulse ();
}

void WriteData (u8 Data )
{//Rs =0 for command port
	DIO_voidSetPinValue (LCD_COMMAND_PORT,DIO_PIN_0, DIO_PIN_HIGH);
	DIO_voidSetPortValue (LCD_DATA_PORT , Data);
	Enablepulse ();
}
void LCD_u8WriteString (u8 *Copy_u8Data)
{
		while (*Copy_u8Data != '\0')
		{
			WriteData(*Copy_u8Data++);
		}
}
void lcd_voidGoToX_Y(u8 row , u8 col )
{
	u8 Local_u8Address;
	Local_u8Address = col+(row*LCD_u8_2ND_ROW);
    Local_u8Address |= LCD_u8_SET_DDRAM_ADDRESS;
    WriteCommand(Local_u8Address);

}

