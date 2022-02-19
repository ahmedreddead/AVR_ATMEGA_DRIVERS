#include "STD_TYPES.h"
#include "BIT_CALC.h"

#include "DIO_interface.h"

#include "DIO_config.h"

#include "DIO_private.h"




void DIO_voidInit(void)
{
    DDRA->ByteAccess=CONC_8bit (DIO_u8_PIN0_DIR,
                           DIO_u8_PIN1_DIR,
                           DIO_u8_PIN2_DIR,
                           DIO_u8_PIN3_DIR,
                           DIO_u8_PIN4_DIR,
                           DIO_u8_PIN5_DIR,
                           DIO_u8_PIN6_DIR,
                           DIO_u8_PIN7_DIR
    );

    DDRB->ByteAccess=CONC_8bit(DIO_u8_PIN8_DIR ,
                          DIO_u8_PIN9_DIR ,
                          DIO_u8_PIN10_DIR,
                          DIO_u8_PIN11_DIR,
                          DIO_u8_PIN12_DIR,
                          DIO_u8_PIN13_DIR,
                          DIO_u8_PIN14_DIR,
                          DIO_u8_PIN15_DIR
    );

     DDRC->ByteAccess=CONC_8bit(DIO_u8_PIN16_DIR,
                           DIO_u8_PIN17_DIR,
                           DIO_u8_PIN18_DIR,
                           DIO_u8_PIN19_DIR,
                           DIO_u8_PIN20_DIR,
                           DIO_u8_PIN21_DIR,
                           DIO_u8_PIN22_DIR,
                           DIO_u8_PIN23_DIR
    );

     DDRD->ByteAccess=CONC_8bit(DIO_u8_PIN24_DIR,
                           DIO_u8_PIN25_DIR,
                           DIO_u8_PIN26_DIR,
                           DIO_u8_PIN27_DIR,
                           DIO_u8_PIN28_DIR,
                           DIO_u8_PIN29_DIR,
                           DIO_u8_PIN30_DIR,
                           DIO_u8_PIN31_DIR
    );


     // SET PORT VALUES  :
     PORTA->ByteAccess=CONC_8bit (DIO_u8_PIN0_VALUE,
                            DIO_u8_PIN1_VALUE,
                            DIO_u8_PIN2_VALUE,
                            DIO_u8_PIN3_VALUE,
                            DIO_u8_PIN4_VALUE,
                            DIO_u8_PIN5_VALUE,
                            DIO_u8_PIN6_VALUE,
                            DIO_u8_PIN7_VALUE
     );

     PORTB->ByteAccess=CONC_8bit(DIO_u8_PIN8_VALUE ,
                           DIO_u8_PIN9_VALUE,
                           DIO_u8_PIN10_VALUE,
                           DIO_u8_PIN11_VALUE,
                           DIO_u8_PIN12_VALUE,
                           DIO_u8_PIN13_VALUE,
                           DIO_u8_PIN14_VALUE,
                           DIO_u8_PIN15_VALUE
     );
      PORTC->ByteAccess=CONC_8bit(DIO_u8_PIN16_VALUE,
                            DIO_u8_PIN17_VALUE,
                            DIO_u8_PIN18_VALUE,
                            DIO_u8_PIN19_VALUE,
                            DIO_u8_PIN20_VALUE,
                            DIO_u8_PIN21_VALUE,
                            DIO_u8_PIN22_VALUE,
                            DIO_u8_PIN23_VALUE
     );
      PORTD->ByteAccess=CONC_8bit(DIO_u8_PIN24_VALUE,
                            DIO_u8_PIN25_VALUE,
                            DIO_u8_PIN26_VALUE,
                            DIO_u8_PIN27_VALUE,
                            DIO_u8_PIN28_VALUE,
                            DIO_u8_PIN29_VALUE,
                            DIO_u8_PIN30_VALUE,
                            DIO_u8_PIN31_VALUE
     );


  return;
}




//  pin APIs
u8 DIO_u8SetPinDirection(u8  Copy_u8PinNb, u8 Copy_u8Direction){
    u8 Local_u8Error=ERROR_OK;
    u8 Local_u8PinId;
    u8 Local_u8PortId;
    if((Copy_u8PinNb >= DIO_MAXPINNB) || (Copy_u8Direction !=DIO_PIN_OUTPUT && Copy_u8Direction != DIO_PIN_INPUT)){
      Local_u8Error = ERROR_NOK;
    }else{

      Local_u8PinId= Copy_u8PinNb %  DIO_NUMBER_PINS_IN_PORT;
      Local_u8PortId = Copy_u8PinNb / DIO_NUMBER_PINS_IN_PORT;
      switch (Local_u8PortId){
        case DIO_DDR_A :
          BIT_CALC_ASSIGN_BIT(DDRA->ByteAccess,Local_u8PinId,Copy_u8Direction);
        break;
        case DIO_DDR_B:
          BIT_CALC_ASSIGN_BIT(DDRB->ByteAccess,Local_u8PinId,Copy_u8Direction);
        break;
        case DIO_DDR_C:
          BIT_CALC_ASSIGN_BIT(DDRC->ByteAccess,Local_u8PinId,Copy_u8Direction);
        break;
        case DIO_DDR_D:
          BIT_CALC_ASSIGN_BIT(DDRD->ByteAccess,Local_u8PinId,Copy_u8Direction);
        break;
      }

    }
    return Local_u8Error;
}
u8 DIO_u8SetPinValue(u8  Copy_u8PinNb, u8  Copy_u8PinValue){
	/*********************************************************/
	/*Description :                                          */
	/*------------                                           */
	/*		this function set PIN VALUE                     */
	/*	INPUTS :                                             */
	/*			Copy_u8PinNb     : PIN Number                */
	/* 	 	 	Copy_u8PinValue : PIN VALUE                  */
	/*	OUTPUT:                                              */
	/*			return ERROR STATE                           */
	/*********************************************************/
   u8 Local_u8Error=ERROR_OK;
  u8 Local_u8PinId;
  u8 Local_u8PortId;
  if((Copy_u8PinNb >= DIO_MAXPINNB) || (Copy_u8PinValue !=DIO_PIN_OUTPUT && Copy_u8PinValue != DIO_PIN_INPUT)){
    Local_u8Error = ERROR_NOK;
  }else{

    Local_u8PinId= Copy_u8PinNb %  DIO_NUMBER_PINS_IN_PORT;
    Local_u8PortId = Copy_u8PinNb / DIO_NUMBER_PINS_IN_PORT;
    switch (Local_u8PortId){
      case DIO_PORT_A :
        BIT_CALC_ASSIGN_BIT(PORTA->ByteAccess,Local_u8PinId,Copy_u8PinValue);
      break;
      case DIO_PORT_B:
        BIT_CALC_ASSIGN_BIT(PORTB->ByteAccess,Local_u8PinId,Copy_u8PinValue);
      break;
      case DIO_PORT_C:
        BIT_CALC_ASSIGN_BIT(PORTC->ByteAccess,Local_u8PinId,Copy_u8PinValue);
      break;
      case DIO_PORT_D:
        BIT_CALC_ASSIGN_BIT(PORTD->ByteAccess,Local_u8PinId,Copy_u8PinValue);
      break;
    }

  }
  return Local_u8Error;
}
u8 DIO_u8GetPinValue(u8  Copy_u8PinNb, u8 *  Copy_pu8PinValue){
	/*********************************************************/
	/*Description :                                          */
	/*------------                                           */
	/*		this function reads pin value and save it        */
	/* 		in Copy_pu8PinValue                              */
	/*	INPUTS :                                             */
	/*			Copy_u8PinNb     : PIN Number                */
	/* 	 	 	Copy_u8PinValue  : PIN VALUE                 */
	/*	OUTPUT:                                              */
	/*			return :ERROR STATE                          */
	/*********************************************************/
  u8 Local_u8Error=ERROR_OK;
    u8 Local_u8PinId;
    u8 Local_u8PortId;
    if((Copy_u8PinNb >= DIO_MAXPINNB) || (Copy_pu8PinValue ==NULL)){
      Local_u8Error = ERROR_NOK;
    }else{

      Local_u8PinId= Copy_u8PinNb %  DIO_NUMBER_PINS_IN_PORT;
      Local_u8PortId = Copy_u8PinNb / DIO_NUMBER_PINS_IN_PORT;
      switch (Local_u8PortId){
        case DIO_PIN_A :
          *Copy_pu8PinValue = BIT_CALC_GET_BIT(PINA->ByteAccess,Local_u8PinId);
        break;
        case DIO_PIN_B:
          *Copy_pu8PinValue = BIT_CALC_GET_BIT(PINB->ByteAccess,Local_u8PinId);
        break;
        case DIO_PIN_C:
          *Copy_pu8PinValue = BIT_CALC_GET_BIT(PINC->ByteAccess,Local_u8PinId);
        break;
        case DIO_PIN_D:
          *Copy_pu8PinValue = BIT_CALC_GET_BIT(PIND->ByteAccess,Local_u8PinId);
        break;
      }

    }
    return Local_u8Error;
}

// port APIs
u8 DIO_u8SetPortDirection(u8 Copy_u8PortNb, u8  Copy_u8Direction){
	/*********************************************************/
	/*Description :                                          */
	/*------------                                           */
	/*		this function SETS PORT DIRECTION                */
	/*	INPUTS :                                             */
	/*			Copy_u8PortNb    : PORT Number               */
	/* 	 	 	Copy_u8Direction  : PORT direction           */
	/*	OUTPUT:                                              */
	/*			return :ERROR STATE                          */
	/*********************************************************/
  u8 Local_u8Error=ERROR_OK;
  if((Copy_u8PortNb >= DIO_MAXPORTNB) || (Copy_u8Direction <=DIO_PORT_OUTPUT && Copy_u8Direction >= DIO_PORT_INPUT)){
    Local_u8Error = ERROR_NOK;
  }else{
    switch (Copy_u8PortNb){
      case DIO_PORT_A :
        BIT_CALC_SET_PORT_DIRECTION(PORTA->ByteAccess,Copy_u8Direction);
      break;
      case DIO_PORT_B:
        BIT_CALC_SET_PORT_DIRECTION(PORTB->ByteAccess,Copy_u8Direction);
      break;
      case DIO_PORT_C:
        BIT_CALC_SET_PORT_DIRECTION(PORTC->ByteAccess,Copy_u8Direction);
      break;
      case DIO_PORT_D:
        BIT_CALC_SET_PORT_DIRECTION(PORTD->ByteAccess,Copy_u8Direction);
      break;
    }

  }
  return Local_u8Error;
}
u8 DIO_u8SetPortnValue(u8  Copy_u8PortNb, u8  Copy_u8PortValue){
	/*********************************************************/
	/*Description :                                          */
	/*------------                                           */
	/*		this function SETS PORT VALUE                    */
	/*	INPUTS :                                             */
	/*			Copy_u8PortNb    : PORT Number               */
	/* 	 	 	Copy_u8Direction  : PORT VALUE               */
	/*	OUTPUT:                                              */
	/*			return :ERROR STATE                          */
	/*********************************************************/
  u8 Local_u8Error=ERROR_OK;

    if((Copy_u8PortNb >= DIO_MAXPORTNB) || (Copy_u8PortValue > DIO_PORT_VALUE_MAX || Copy_u8PortValue < DIO_PORT_VALUE_MIN)){
    Local_u8Error = ERROR_NOK;
  }else{
    switch (Copy_u8PortNb){
      case DIO_PORT_A :
        BIT_CALC_SET_PORT_VALUE(PORTA->ByteAccess,Copy_u8PortValue);
      break;
      case DIO_PORT_B:
        BIT_CALC_SET_PORT_VALUE(PORTB->ByteAccess,Copy_u8PortValue);
      break;
      case DIO_PORT_C:
        BIT_CALC_SET_PORT_VALUE(PORTC->ByteAccess,Copy_u8PortValue);
      break;
      case DIO_PORT_D:
        BIT_CALC_SET_PORT_VALUE(PORTD->ByteAccess,Copy_u8PortValue);
      break;
    }

  }
  return Local_u8Error;
}
u8 DIO_u8GetPortnValue(u8  Copy_u8PinNb, u8 *  Copy_pu8PortValue){
	/*********************************************************/
	/*Description :                                          */
	/*------------                                           */
	/*		this function GETS PORT VALUE and store it       */
	/*      in  Copy_pu8PortValue                            */
	/*	INPUTS :                                             */
	/*			Copy_u8PortNb    : PORT Number               */
	/* 	 	 	Copy_u8Direction : PORT direction            */
	/*	OUTPUT:                                              */
	/*			return :ERROR STATE                          */
	/*********************************************************/
  u8 Local_u8Error=ERROR_OK;
  if((Copy_u8PinNb >= DIO_MAXPORTNB) ){
    Local_u8Error = ERROR_NOK;
  }else{
    switch (Copy_u8PinNb){
      case DIO_PORT_A :
        *Copy_pu8PortValue = PINA->ByteAccess;
      break;
      case DIO_PORT_B:
        *Copy_pu8PortValue = PINB->ByteAccess;
      break;
      case DIO_PORT_C:
        *Copy_pu8PortValue = PINC->ByteAccess;
      break;
      case DIO_PORT_D:
        *Copy_pu8PortValue = PIND->ByteAccess;
      break;
    }

  }
  return Local_u8Error;
}
