/*
 * WDT_main.c
 *
 *  Created on: Apr 9, 2019
 *      Author: Amr Abdeen
 Discription: Watchdog Test code
 */
#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "DIO_interface.h"
#include <util/delay.h>

#define WDTCR  ((Register*)                   0x41)

#define WDG_MODE_1  1
#define WDG_MODE_2 2
#define WDG_OP_MODE  WDG_MODE_1

int main(void)
{

	DIO_voidInit();

	/*** Case 1 : Normal ***/
#if WDG_OP_MODE == WDG_MODE_1
	/*WDT Code*/
	WDTCR->ByteAccess = 0x0F;  /*Enable WDG*/
	DIO_u8SetPinValue(0,1);
	_delay_ms(500);
	DIO_u8SetPinValue(0,0);
	_delay_ms(500);

	/* Disable Sequence */
	WDTCR->ByteAccess |=(1<<4) |(1<<3);
	WDTCR->ByteAccess =0x00;

#elif WDG_OP_MODE == WDG_MODE_2
	/*** Case 2 : Reset ***/
	/*WDT Code*/
	WDTCR->ByteAccess = 0x0F;  /*Enable WDG*/
	DIO_u8SetPinValue(0,1);
	_delay_ms(1100);
	DIO_u8SetPinValue(0,0);
	_delay_ms(1100);
	/* Disable Sequence */
	WDTCR->ByteAccess |=(1<<4) |(1<<3);
	WDTCR->ByteAccess =0x00;
#endif

	while(1);
	return 0;
}




