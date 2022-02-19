/************************************************/
/* Author : Amr Abbdeen                         */
/* Date   : 5 Feb. 2019                         */
/* Version: V01                                 */          
/************************************************/

/*Comment: inital direction for I/O pins       */
/*Range  : DIO_u8_PIN_INIT_OUTPUT              */
/*         DIO_u8_PIN_INIT_INPUT               */

#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

#define DIO_PIN_INIT_OUTPUT 1
#define DIO_PIN_INIT_INPUT  0

#define DIO_PIN_INIT_HIGH   1
#define DIO_PIN_INIT_LOW    0

#define DIO_u8_PIN_DEFAULT     0  // should it be here ?


#define DDRA  ((Register*)                    0x3A)
#define PORTA ((Register*)                   0x3B)
#define PINA  ((Register*)                   0x39)

#define DDRB ((Register*)                    0x37)
#define PORTB ((Register*)                   0x38)
#define PINB  ((Register*)                   0x36)

#define DDRC  ((Register*)                   0x34)
#define PORTC ((Register*)                   0x35)
#define PINC  ((Register*)                   0x33)

#define DDRD  ((Register*)                   0x31)
#define PORTD ((Register*)                   0x32)
#define PIND  ((Register*)                   0x30)

/**********************************************************************************/
/* DIO_PIN_INPUT : represents 0 to indicate Pin direction is Input                */
/* DIO_PIN_OUTPUT: represents 1 to indicate Pin direction is Output               */
/* PIN_VALUE_HIGH: represents 1 to indicate Pin Value/state is High               */
/* PIN_VALUE_LOW: represents 0 to indicate Pin Value/state is LOW                 */
/* DIO_PORT_OUTPUT: represents 0xFF to indicate Port direction is Output          */
/* DIO_PORT_INPUT: represents 0x00 to indicate Port direction is Input            */
/* DIO_PORT_VALUE_MAX: represents 0xFF to indicate Max. value of Port register    */
/* width                                                                          */
/**********************************************************************************/

#define DIO_PIN_INPUT                         0
#define DIO_PIN_OUTPUT                        1
#define PIN_VALUE_HIGH                        1
#define PIN_VALUE_LOW                         0
#define DIO_PORT_OUTPUT                       0xFF
#define DIO_PORT_INPUT                        0x00
#define DIO_PORT_VALUE_MAX                    0xFF
#define DIO_PORT_VALUE_MIN                    0x00


#define DIO_NUMBER_PINS_IN_PORT               8

#define DIO_DDR_A                             0
#define DIO_DDR_B                             1
#define DIO_DDR_C                             2
#define DIO_DDR_D                             3

#define DIO_PORT_A                            0
#define DIO_PORT_B                            1
#define DIO_PORT_C                            2
#define DIO_PORT_D                            3

#define DIO_PIN_A                             0
#define DIO_PIN_B                             1
#define DIO_PIN_C                             2
#define DIO_PIN_D                             3

#endif // STD_TYPES_H_INCLUDED
/**********************************************************************************/
/* Author : Amr Abdeen                                                            */
/* Date   : 31 Jan. 2019                                                          */
/* Version: V01                                                                   */
/**********************************************************************************/
/* Description:                                                                   */
/*--------------                                                                  */
/* DIO private File is used to define private DIO Macros.Only accessed within     */
/* DIO Driver.                                                                    */
/*                                                                                */
/**********************************************************************************/

#ifndef ATMEGA32_REGISSTERS_H_
#define ATMEGA32_REGISSTERS_H_

/**********************************************************************************/
/* DIO Registers:                                                                 */
/*--------------                                                                  */
/* DDRx : represents the DATA DIRECTION Register where x is the Port Name.        */
/* PORTx: represents the PORT Register where x is the Port Name.                  */
/* PINx: represents the PIN Register where x is the Port Name.                    */
/*                                                                                */
/**********************************************************************************/

#define DDRA ((Register*)                    0x3A)
#define PORTA ((Register*)                   0x3B)
#define PINA  ((Register*)                   0x39)

#define DDRB ((Register*)                    0x37)
#define PORTB ((Register*)                   0x38)
#define PINB  ((Register*)                   0x36)

#define DDRC  ((Register*)                   0x34)
#define PORTC ((Register*)                   0x35)
#define PINC  ((Register*)                   0x33)

#define DDRD  ((Register*)                   0x31)
#define PORTD ((Register*)                   0x32)
#define PIND  ((Register*)                   0x30)


/**********************************************************************************/
/* DIO_PIN_INPUT : represents 0 to indicate Pin direction is Input                */
/* DIO_PIN_OUTPUT: represents 1 to indicate Pin direction is Output               */
/* PIN_VALUE_HIGH: represents 1 to indicate Pin Value/state is High               */
/* PIN_VALUE_LOW: represents 0 to indicate Pin Value/state is LOW                 */
/* DIO_PORT_OUTPUT: represents 0xFF to indicate Port direction is Output          */
/* DIO_PORT_INPUT: represents 0x00 to indicate Port direction is Input            */
/* DIO_PORT_VALUE_MAX: represents 0xFF to indicate Max. value of Port register    */
/* width                                                                          */
/**********************************************************************************/

#define DIO_PIN_INPUT                         0
#define DIO_PIN_OUTPUT                        1
#define PIN_VALUE_HIGH                        1
#define PIN_VALUE_LOW                         0
#define DIO_PORT_OUTPUT                       0xFF
#define DIO_PORT_INPUT                        0x00
#define DIO_PORT_VALUE_MAX                    0xFF
#define DIO_PORT_VALUE_MIN                    0x00


#define DIO_NUMBER_PINS_IN_PORT               8

#define DIO_DDR_A                             0
#define DIO_DDR_B                             1
#define DIO_DDR_C                             2
#define DIO_DDR_D                             3

#define DIO_PORT_A                            0
#define DIO_PORT_B                            1
#define DIO_PORT_C                            2
#define DIO_PORT_D                            3

#define DIO_PIN_A                             0
#define DIO_PIN_B                             1
#define DIO_PIN_C                             2
#define DIO_PIN_D                             3

#define DIO_MAXPINNB 32
#define DIO_MAXPORTNB 4


#endif // STD_TYPES_H_INCLUDED


