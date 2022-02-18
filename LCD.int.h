/*
 * LCD.int.h
 *
 *  Created on: Sep 8, 2019
 *      Author: ahmed
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_


#define LCD_COMMAND_PORT DIO_PORTC
#define LCD_DATA_PORT DIO_PORTB

#define Clear_display_screen 0x01

#define Return_home 0x02

#define shift_cursor_to_left 0x04

#define shift_cursor_to_right 0x06

#define Shift_display_right 0x05

#define Shift_display_lift 0x07

#define Display_off_cursor_off 0x08

#define Display_off_cursor_on 0x0A

#define Display_on_cursor_off 0x0C


#define Display_on_cursor_blinking 0x0F

#define Shift_cursor_position_to_left 0x10

#define Shift_cursor_position_to_right 0x14

#define Shift_the_entire_display_to_the_left 0x18

#define Shift_the_entire_display_to_the_right 0x1C

#define Force_cursor_to_beginning_1st_line 0x80

#define Force_cursor_to_beginning_2nd_line 0xC0

#define display_8_bit_2_lines_mode 0x38


#define LCD_u8_2ND_ROW            (u8)0x40
#define LCD_u8_LINE1_END          (u8)0x90
#define LCD_u8_LINE2_START        (u8)0xC0
#define LCD_u8_LINE2_END          (u8)0xD0

#define LCD_u8_SET_DDRAM_ADDRESS         (u8)0x80

void Enablepulse ();


void intialize_LCD();


void WriteCommand (u8 command );


void WriteData (u8 Data );

void LCD_u8WriteString (u8 *Copy_u8Data);

void lcd_voidGoToX_Y(u8 row , u8 col );



#endif /* LCD_INT_H_ */
