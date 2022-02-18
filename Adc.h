/*
 * Adc.h
 *
 *  Created on: Oct 6, 2019
 *      Author: ahmed
 */

#ifndef ADC_H_
#define ADC_H_
//ADMUX

//• Bit 7:6 – REFS1:0: Reference Selection Bits
#define REFS1 7
#define REFS0 6
//0 0 AREF, Internal Vref turned off
//0 1 AVCC with external capacitor at AREF pin
//1 0 Reserved
//1 1 Internal 2.56V Voltage Reference with external capacitor at AREF pin

// • Bit 5 – ADLAR: ADC Left Adjust Result
#define ADLAR 5

//• Bits 4:0 – MUX4:0: Analog Channel and Gain Selection Bits
/*
00000 ADC0
00001 ADC1
00010 ADC2
00011 ADC3
00100 ADC4
00101 ADC5
00110 ADC6
00111 ADC7
*/

#define MUX4 4
#define MUX3 3
#define MUX2 2
#define MUX1 1
#define MUX0 0
//<___________________________________________________________>
//<___________________________________________________________>
//<___________________________________________________________>
//ADC Control and Status Register A – ADCSRA

//• Bit 7 – ADEN: ADC Enable
#define ADEN 7
//• Bit 6 – ADSC: ADC Start Conversion
#define ADSC 6
//• Bit 5 – ADATE: ADC Auto Trigger Enable (بيفضل يعمل convertion )
#define ADATE 5
//• Bit 4 – ADIF: ADC Interrupt Flag
#define ADIF 4
//• Bit 3 – ADIE: ADC Interrupt Enable
#define ADIE 3
/*
 • Bits 2:0 – ADPS2:0: ADC Prescaler Select Bits
These bits determine the division factor between the XTAL frequency and the input
clock to the ADC.
Table 85. ADC Prescaler Selections
ADPS2 ADPS1 ADPS0 Division Factor
0       0     0 --> 2
0       0     1 --> 2
0       1     0 --> 4
0       1     1 --> 8
1       0     0 --> 16
1       0     1 --> 32
1       1     0 --> 64
1       1     1 --> 128
*/
// • Bits 2:0 – ADPS2:0: ADC Prescaler Select Bits
#define ADPS2 2
#define ADPS1 1
#define ADPS0 0
//<___________________________________________________________>
//<___________________________________________________________>
//<___________________________________________________________>

//Special FunctionIO Register –SFIOR
/*
• Bit 7:5 – ADTS2:0: ADC Auto Trigger Source
If ADATE in ADCSRA is written to one, the value of these bits selects which source will
trigger an ADC conversion. If ADATE is cleared, the ADTS2:0 settings will have no
effect. A conversion will be triggered by the rising edge of the selected Interrupt Flag.
Note that switching from a trigger source that is cleared to a trigger source that is set,
will generate a positive edge on the trigger signal. If ADEN in ADCSRA is set, this will
start a conversion. Switching to Free Running mode (ADTS[2:0]=0) will not cause a trig-
ger event, even if the ADC Interrupt Flag is set .
Table 86. ADC Auto Trigger Source Selections
ADTS2 ADTS1 ADTS0
Trigger Source
0 0 0 Free Running mode
0 0 1 Analog Comparator
0 1 0 External Interrupt Request 0
0 1 1 Timer/Counter0 Compare Match
1 0 0 Timer/Counter0 Overflow
1 0 1 Timer/Counter Compare Match B
1 1 0 Timer/Counter1 Overflow
1 1 1 Timer/Counter1 Capture Event */

#define ADTS2 2
#define ADTS1 1
#define ADTS0 0

void Init_void_Adc();

void Start_void_Adc_1_converstion();

void Start_void_Adc_Auto_converstion();

void GetReading_voidAdc16bit(u16 *u16Reading);

void GetReading_voidAdc8bit(u8 *u8Reading);

void Enable_void_Intrrupt_Adc();
void LM35 (u16 *temp);

#endif /* ADC_H_ */
