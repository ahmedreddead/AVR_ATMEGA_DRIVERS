/*
 * DIO_int.h
 *
 *  Created on: Aug 23, 2019
 *      Author: ahmed
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_


u8 DIO_voidSetPinDirection (u8 Copy_u8Port,u8 Copy_u8Pin , u8 Copy_u8Direction);
u8 DIO_voidSetPinValue (u8 Copy_u8Port,u8 Copy_u8Pin , u8 Copy_u8Value);
void DIO_voidSetPortDirection (u8 Copy_u8Port , u8 Copy_u8Direction);
void DIO_voidSetPortValue (u8 Copy_u8Port , u8 Copy_u8Value);
u8 DIO_u8GetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin , u8 *Copy_Pu8Value);
void DIO_u8SetSeven(u8 Copy_u8Port,u8 Num);






#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3
#define DIO_PIN_INPUT 0

#define DIO_PIN_OUTPUT 1

#define DIO_PORT_INPUT 0

#define DIO_PORT_OUTPUT 255

#define DIO_PIN_0 0
#define DIO_PIN_1 1
#define DIO_PIN_2 2
#define DIO_PIN_3 3
#define DIO_PIN_4 4
#define DIO_PIN_5 5
#define DIO_PIN_6 6
#define DIO_PIN_7 7

#define DIO_PORT_HIGH 255
#define DIO_PIN_HIGH 1
#define DIO_PIN_LOW 0

#define DIO_PORT_LOW 0

#endif /* DIO_INT_H_ */
