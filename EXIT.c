/*
 * EXIT.c
 *
 *  Created on: Sep 20, 2019
 *      Author: ahmed
 */
#include "AVR_DIO_REG.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "EXTI.h"
#include "timer0.h"
void (*funptr[19])(void)= {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

void EXTI_void_callback(void (*fun )(void),u8 Copy_u8IdNum )
{
	//funptr=fun ;
	if(fun != NULL)
	{
		if( Copy_u8IdNum==1)
		{
                funptr[0]=fun;
		}
		if( Copy_u8IdNum==2)
				{
		                funptr[1]=fun;
				}
		if( Copy_u8IdNum==3)
				{
		                funptr[2]=fun;
				}
		if( Copy_u8IdNum==11)
						{
				                funptr[10]=fun;
						}
		if( Copy_u8IdNum==16)
								{
						                funptr[15]=fun;
								}
	}


}
void __vector_1 (void)
{
if(funptr[0] !=NULL)
	{funptr[0]();
	Sie();
	}

}
void __vector_2 (void)
{
	Sie();}
void __vector_3 (void)
{
	Sie();}
//TIMER OVERFLOW
void __vector_11 (void)
{
if(funptr[10] !=NULL)
	{
	funptr[10]();
	Enable_voidOverFlowInterrupt();
	Sie();
	}

}
//ADC Conversion Complete
void __vector_16 (void)
{
if(funptr[15] !=NULL)
	{
	funptr[15]();
	Sie();
	}

}


//Enable Global Interrupt
void Sie(void)
{
	SET_BIT(SREG,7);
}

//TYPE OF raising or falling edges

void EXTI_void_MCUCR(u8 IntrruptType,u8 LevelType)
{

switch (IntrruptType)
{
case 0 :

	switch (LevelType)
	{
	case 0 : CLEAR_BIT(MCUCR,0); CLEAR_BIT(MCUCR,1); break ;
	case 1 : SET_BIT(MCUCR,0);   CLEAR_BIT(MCUCR,1); break ;
	case 2 : CLEAR_BIT(MCUCR,0); SET_BIT(MCUCR,1);  break ;
	case 3 : SET_BIT(MCUCR,0);   SET_BIT(MCUCR,1);  break ;
	default : break ;
	break ;
	}
	break;

case 1 :

	switch (LevelType)
		{
	    case 0 : CLEAR_BIT(MCUCR,2); CLEAR_BIT(MCUCR,3); break ;
		case 1 : SET_BIT(MCUCR,2);   CLEAR_BIT(MCUCR,3); break ;
		case 2 : CLEAR_BIT(MCUCR,2); SET_BIT(MCUCR,3);  break ;
		case 3 : SET_BIT(MCUCR,2);   SET_BIT(MCUCR,3);  break ;
		default : break ;
		break ;
		}
	break;

default : break ;

}
}
//ENABLE INTERRUPT
void EXTI_void_GICR(u8 IntrruptType)
{
	switch (IntrruptType)
	{
	case 0 : SET_BIT(GICR,6); break ;
	case 1 : SET_BIT(GICR,7); break ;
	case 2 : SET_BIT(GICR,5); break ;
	default : break ;

	}

}











