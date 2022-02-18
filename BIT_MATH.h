/*
 * BIT_MATH.h
 *
 *  Created on: Aug 23, 2019
 *      Author: ahmed
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR,BIT_NO) (VAR |=(1<<BIT_NO))

#define CLEAR_BIT(VAR,BIT_NO) (VAR &=~(1<<BIT_NO))

#define TOGGLE(VAR,BIT_NO) (VAR ^=(1<<BIT_NO))
#define GET_BIT(VAR,BIT_NO) ((VAR>>BIT_NO)&0X01)
#define ASSIGN_BIT(VAR,BIT_NO,VAL)  ( VAR =  (VAR &(~(1<<BIT_NO)))| (VAL<<BIT_NO))

#endif /* BIT_MATH_H_ */
