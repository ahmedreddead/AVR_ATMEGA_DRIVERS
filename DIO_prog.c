/*
 * DIO_prog.c
 *
 *  Created on: Aug 23, 2019
 *      Author: ahmed
 */
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "BIT_MATH.h"
#include "AVR_DIO_REG.h"

u8 DIO_voidSetPinDirection (u8 Copy_u8Port,u8 Copy_u8Pin , u8 Copy_u8Direction)
{
	u8 local_u8ErrorState = 0 ;
	if(Copy_u8Pin	<=7&& Copy_u8Direction <=1 )
	{
switch (Copy_u8Port)
{


case (DIO_PORTA):ASSIGN_BIT(DDRA,Copy_u8Pin,Copy_u8Direction); break;
case (DIO_PORTB):ASSIGN_BIT(DDRB,Copy_u8Pin,Copy_u8Direction); break;
case (DIO_PORTC):ASSIGN_BIT(DDRC,Copy_u8Pin,Copy_u8Direction); break;
case (DIO_PORTD):ASSIGN_BIT(DDRD,Copy_u8Pin,Copy_u8Direction); break;
default : local_u8ErrorState=1; break;
}}
	else {

 local_u8ErrorState=1;

	}
return  local_u8ErrorState  ;
}




u8 DIO_voidSetPinValue (u8 Copy_u8Port,u8 Copy_u8Pin , u8 Copy_u8Value)

{
	u8 local_u8ErrorState = 0 ;
	if(Copy_u8Pin	<=7&& Copy_u8Value <=1 )
	{
switch (Copy_u8Port)
{


case (DIO_PORTA):ASSIGN_BIT(PORTA , Copy_u8Pin , Copy_u8Value); break;
case (DIO_PORTB):ASSIGN_BIT(PORTB , Copy_u8Pin , Copy_u8Value); break;
case (DIO_PORTC):ASSIGN_BIT(PORTC , Copy_u8Pin , Copy_u8Value); break;
case (DIO_PORTD):ASSIGN_BIT(PORTD , Copy_u8Pin , Copy_u8Value); break;

default : local_u8ErrorState=1; break;
}}
	else {

 local_u8ErrorState=1;

	}
return  local_u8ErrorState  ;
}



void DIO_u8SetSeven(u8 Copy_u8Port,u8 Num)
{

u8 ArrayNum[10] ={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};

DIO_voidSetPortDirection(DIO_PORTA,DIO_PORT_OUTPUT);


switch (Num)
{
case 0:DIO_voidSetPortValue (Copy_u8Port , ~ArrayNum[0]);break ;
case 1:DIO_voidSetPortValue (Copy_u8Port , ~ArrayNum[1]);break ;
case 2:DIO_voidSetPortValue (Copy_u8Port , ~ArrayNum[2]);break ;
case 3:DIO_voidSetPortValue (Copy_u8Port , ~ArrayNum[3]);break ;
case 4:DIO_voidSetPortValue (Copy_u8Port , ~ArrayNum[4]);break ;
case 5:DIO_voidSetPortValue (Copy_u8Port , ~ArrayNum[5]);break ;
case 6:DIO_voidSetPortValue (Copy_u8Port , ~ArrayNum[6]);break ;
case 7:DIO_voidSetPortValue (Copy_u8Port , ~ArrayNum[7]);break ;
case 8:DIO_voidSetPortValue (Copy_u8Port , ~ArrayNum[8]);break ;
case 9:DIO_voidSetPortValue (Copy_u8Port , ~ArrayNum[9]);break ;
default : DIO_voidSetPortValue (Copy_u8Port , ~ArrayNum[0]);break ;
}



}
void DIO_voidSetPortDirection (u8 Copy_u8Port , u8 Copy_u8Direction)

{
switch (Copy_u8Port)
{
case (DIO_PORTA):DDRA =Copy_u8Direction; break ;
case (DIO_PORTB):DDRB =Copy_u8Direction; break ;
case (DIO_PORTC):DDRC =Copy_u8Direction; break ;
case (DIO_PORTD):DDRD =Copy_u8Direction; break ;
}

}

void DIO_voidSetPortValue (u8 Copy_u8Port , u8 Copy_u8Value)

{
switch (Copy_u8Port)
{
case (DIO_PORTA):PORTA =Copy_u8Value; break ;
case (DIO_PORTB):PORTB =Copy_u8Value; break ;
case (DIO_PORTC):PORTC =Copy_u8Value; break ;
case (DIO_PORTD):PORTD =Copy_u8Value; break ;
}

}



u8 DIO_u8GetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin , u8 *Copy_Pu8Value)
{
u8 Local_u8ErrorState=0;
switch (Copy_u8Port)
{
case (DIO_PORTA):*Copy_Pu8Value=GET_BIT(PINA,Copy_u8Pin) ;  break ;
case (DIO_PORTB):*Copy_Pu8Value=GET_BIT(PINB,Copy_u8Pin) ;  break ;
case (DIO_PORTC):*Copy_Pu8Value=GET_BIT(PINC,Copy_u8Pin) ;  break ;
case (DIO_PORTD):*Copy_Pu8Value=GET_BIT(PIND,Copy_u8Pin) ;  break ;

default: Local_u8ErrorState=1;
}
return Local_u8ErrorState;
}


