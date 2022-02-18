/*
 * KeyPad_int.c
 *
 *  Created on: Aug 31, 2019
 *      Author: ahmed
 */

#include "STD_TYPES.h"
#include "DIO_int.h"
#include "KeyPad_int.h"

u8 KPD_ROW[]= {R0,R1,R2,R3};
u8 KPD_COL[]= {C0,C1,C2,C3};
void KeyPad_voidInit(void )
{
// 1111 --> ROWS OUTPOT  0000 --> COLUMS INPUT   3LA PORT D
	DIO_voidSetPortDirection(KPD_PORT,0XF0);
	// KOL EL PORT OUTPUT WE A5ER 4 BIT PULL UP FA BN7OT 3LEHA ONES INPUTS + ONES = PULL UP :D
	DIO_voidSetPortValue(KPD_PORT,0XFF);

}

void KeyPad_voidGetKey(u8 *u8key )
{
u8 local_u8RowsIndex  ;
u8 local_u8ColIndex  ;
u8 Local_u8pinval ;
for(local_u8ColIndex=0 ; local_u8ColIndex<NUMOFCOLUMS ;local_u8ColIndex++)
{//عشان اتأكد انها pull up
	DIO_voidSetPortValue(KPD_PORT,0XFF);
	// 4 __5__6__7  دول الي هيكونو بزيرو ويقعدو يتكررو
	DIO_voidSetPinValue(KPD_PORT , KPD_COL[local_u8ColIndex],DIO_PIN_LOW);

	 /*ROWS */
	for(local_u8RowsIndex=0 ; local_u8RowsIndex<NUMOFCOLUMS;local_u8RowsIndex++)
	{
DIO_u8GetPinValue(KPD_PORT,KPD_ROW[local_u8ColIndex],&Local_u8pinval );
//LAZEM Local_u8pinval LW ANTA DOST 3LEHA هو في الاول وحايد دلوقتي لو هو داس علي ROWS معينه بتبقي بزيرو
// ! KDA NOT ZERO = TRUE Y3NY AD5OL
if(!Local_u8pinval)
{
	//3AWEZ AT2KET ANY DAYES EL ZORAR MARA WA7DA
	while(!Local_u8pinval)
	{//لازم بردو اشوف القيمه الحاليه لسه
		DIO_u8GetPinValue(KPD_PORT,KPD_ROW[local_u8ColIndex],&Local_u8pinval );
	}
	// كدا انا شلت ايدي من علي الزرار  مفروض يدخل يعملي الي انا عاوزو
	switch (local_u8ColIndex) //كدا معاه رقم الكولوم الي انا دايس عليه عاوز كدا اجيب الروز
	{
	case 0 :
	if(local_u8RowsIndex==0) *u8key ='1';
	if(local_u8RowsIndex==1) *u8key ='2';
	if(local_u8RowsIndex==2) *u8key ='3';
	if(local_u8RowsIndex==3) *u8key ='+';
	break;
	case 1 :
		if(local_u8RowsIndex==0) *u8key ='4';
		if(local_u8RowsIndex==1) *u8key ='5';
		if(local_u8RowsIndex==2) *u8key ='6';
		if(local_u8RowsIndex==3) *u8key ='-';
		break;
	case 2 :
		if(local_u8RowsIndex==0) *u8key ='7';
		if(local_u8RowsIndex==1) *u8key ='8';
		if(local_u8RowsIndex==2) *u8key ='9';
		if(local_u8RowsIndex==3) *u8key ='*';
		break;
	case 3  :
		if(local_u8RowsIndex==0) *u8key ='=';
		if(local_u8RowsIndex==1) *u8key ='/';
		if(local_u8RowsIndex==2) *u8key ='0';
		if(local_u8RowsIndex==3) *u8key ='0';
		break;

		//b3mlha implement( key - '0 ')

	}
}

	}


}

}
