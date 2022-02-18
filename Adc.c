/*
 * Adc.c
 *
 *  Created on: Oct 6, 2019
 *      Author: ahmed
 */
#include "AVR_DIO_REG.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "EXTI.h"
#include "timer0.h"
#include "Adc.h"

void Init_void_Adc()
{
	//ADMUX
	//• Bit 7:6 – REFS1:0: Reference Selection Bits
	//1 1 Internal 2.56V Voltage Reference with external capacitor at AREF pin
	SET_BIT(ADMUX,REFS1);   SET_BIT(ADMUX,REFS0);
	//• Bits 4:0 – MUX4:0: Analog Channel and Gain Selection Bits
	//00000 ADC0
    CLEAR_BIT(ADMUX,MUX0);CLEAR_BIT(ADMUX,MUX1);CLEAR_BIT(ADMUX,MUX2);CLEAR_BIT(ADMUX,MUX3);CLEAR_BIT(ADMUX,MUX4);

    SET_BIT(ADCSRA,ADPS2);
    SET_BIT(ADCSRA,ADPS1);
    SET_BIT(ADCSRA,ADPS0);

}
void Start_void_Adc_1_converstion()
{
//ADCSRA
	//adc enable
	SET_BIT(ADCSRA,ADEN);
	//adc one con
	SET_BIT(ADCSRA,ADSC);

}
void Start_void_Adc_Auto_converstion()
{
	//ADCSRA
		//adc enable
		SET_BIT(ADCSRA,ADEN);
		//adc auto con
		SET_BIT(ADCSRA,ADATE);

}
void GetReading_voidAdc16bit(u16 *u16Reading)
{
	while((ADCSRA & (1<<ADIF))== 0 );
	*u16Reading=ADCL;
	*u16Reading |=(ADCH <<8);
}
void GetReading_voidAdc8bit(u8 *u8Reading)
{
	while((ADCSRA & (1<<ADIF))== 0 );
u16 res;
res=ADCL;
res |=(ADCH <<8);
*u8Reading=res/4;
}
void Enable_void_Intrrupt_Adc()
{
	SET_BIT(ADCSRA,ADIE);

}

void LM35 (u16 *temp)
{  u16 reading;
	GetReading_voidAdc16bit(&reading);
	*temp=reading*2.5/10;
}



