/*
 * KeyPad_int.h
 *
 *  Created on: Aug 31, 2019
 *      Author: ahmed
 */

#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_

#define KPD_PORT DIO_PORTC


#define NUMOFCOLUMS 4

#define R0 0
#define R1 1
#define R2 2
#define R3 3

#define C0 4
#define C1 5
#define C2 6
#define C3 7




void KeyPad_voidInit(void );
void KeyPad_voidGetKey(u8 *u8key );

#endif /* KEYPAD_INT_H_ */
