/*
 * timer0.h
 *
 *  Created on: Oct 5, 2019
 *      Author: ahmed
 */

#ifndef TIMER0_H_
#define TIMER0_H_

#define FOC0 7 // ZERO IF YOU WANT PWM --1 ANY ELSE

#define CS00 0
#define CS01 1  // this 3 bits determine the clock cycle with prescale or not
#define CS02 2

#define WGM00 6    //00 NORMAL MODE -- 01 PWM -- 10 CTC -- 11 FAST PWM
#define WGM01 3


#define COM00 4
#define COM01 5  //00 NORMAL MODE OC0 IS OFF

//TIMSK


//• Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable
#define TOIE0 0
//• Bit 1 – OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable
#define OCIE0 1

//Timer/Counter Interrupt Flag Register – TIFR

//• Bit 0 – TOV0: Timer/Counter0 Overflow Flag
#define TOV0 0
//• Bit 1 – OCF0: Output Compare Flag 0
#define OCF0 1

void Init_voidTimer0 ();

void Preload_voidsetPreloadvalue (u8 u8preload);

void Enable_voidOverFlowInterrupt();


#endif /* TIMER0_H_ */
