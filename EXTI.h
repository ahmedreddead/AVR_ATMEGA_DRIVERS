/*
 * EXTI.h
 *
 *  Created on: Sep 20, 2019
 *      Author: ahmed
 */

#ifndef EXTI_H_
#define EXTI_H_

#define NULL (void*)0

#define INT0 0

#define INT1 1

#define INT2 2

#define LOW_LEVEL 0
#define ANY_LOGICAL_CHANGE 1
#define FAILLING_EDEG 2
#define RAISING_EDGE 3




void EXTI_void_callback(void (*fun )(void),u8 Copy_u8IdNum);
void __vector_1 (void);
void __vector_2 (void);
void __vector_3 (void);
void __vector_11 (void);

void Sie(void);

void EXTI_void_MCUCR(u8 IntrruptType,u8 LevelType);
void EXTI_void_GICR(u8 IntrruptType);
#endif /* EXTI_H_ */
