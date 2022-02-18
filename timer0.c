/*
 * timer0.c
 *
 *  Created on: Oct 5, 2019
 *      Author: ahmed
 */
#include "AVR_DIO_REG.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "EXTI.h"
#include "timer0.h"

void Init_voidTimer0 ()

{

	SET_BIT (TCCR0,FOC0);
	//at normal mode
	CLEAR_BIT (TCCR0,WGM00); CLEAR_BIT (TCCR0,WGM01);
	// this 3 bits determine the clock cycle with prescale or not // 8 prescale
	CLEAR_BIT (TCCR0,CS00);   SET_BIT (TCCR0,CS01);   CLEAR_BIT (TCCR0,CS02);  //010
	//00 NORMAL MODE OC0 IS OFF
	CLEAR_BIT (TCCR0,COM00); CLEAR_BIT (TCCR0,COM01);
	Enable_voidOverFlowInterrupt();

}

void Preload_voidsetPreloadvalue (u8 u8preload)
{
	TCNT0 = u8preload ;

}

void Enable_voidOverFlowInterrupt()
{
	SET_BIT (TIMSK,TOIE0);
}


