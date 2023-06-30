/*****************************************************************/
/*****************************************************************/
/************		Author: Kerolos Hanna			**************/
/************		Kerolos.Hanna@hotmail.com		**************/
/************		Layer:	MCAL					**************/
/************		SWC:	DIO						**************/
/************		version: 1.00					**************/
/*****************************************************************/
/*****************************************************************/


#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "DIO_private.h"


/*Directions Functions*/
uint8 DIO_u8SetPinDirection(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Direction){
	uint8 Local_u8ErrorState = 0;
	if(Copy_u8Pin <= 7){
		if(Copy_u8Direction == DIO_u8PIN_INPUT){
			switch (Copy_u8Port){
			case DIO_u8PORTA:CLR_BIT(DDRA, Copy_u8Pin);break;
			case DIO_u8PORTB:CLR_BIT(DDRB, Copy_u8Pin);break;
			case DIO_u8PORTC:CLR_BIT(DDRC, Copy_u8Pin);break;
			case DIO_u8PORTD:CLR_BIT(DDRD, Copy_u8Pin);break;
			default: Local_u8ErrorState = 1;break;
			}
		}else if(Copy_u8Direction == DIO_u8PIN_OUTPUT){
			switch (Copy_u8Port){
			case DIO_u8PORTA:SET_BIT(DDRA, Copy_u8Pin);break;
			case DIO_u8PORTB:SET_BIT(DDRB, Copy_u8Pin);break;
			case DIO_u8PORTC:SET_BIT(DDRC, Copy_u8Pin);break;
			case DIO_u8PORTD:SET_BIT(DDRD, Copy_u8Pin);break;
			default: Local_u8ErrorState = 1;break;
			}
		}else{
			Local_u8ErrorState = 1;
		}
	}else{
		Local_u8ErrorState = 1;
	}

	return Local_u8ErrorState;
}

uint8 DIO_u8SetPortDirection(uint8 Copy_u8Port, uint8 Copy_u8Direction){
	uint8 Local_u8ErrorState = 0;

	if(Copy_u8Direction >= DIO_u8PORT_INPUT || Copy_u8Direction <= DIO_u8PORT_OUTPUT ){
		switch (Copy_u8Port){
		case DIO_u8PORTA:DDRA=Copy_u8Direction;break;
		case DIO_u8PORTB:DDRB=Copy_u8Direction;break;
		case DIO_u8PORTC:DDRC=Copy_u8Direction;break;
		case DIO_u8PORTD:DDRD=Copy_u8Direction;break;
		default: Local_u8ErrorState = 1;break;
		}
	}else{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

/*Output Values Functions*/
uint8 DIO_u8SetPinValue(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Value){
	uint8 Local_u8ErrorState = 0;
	if(Copy_u8Pin <= 7){
		if(Copy_u8Value == DIO_u8PIN_LOW){
			switch (Copy_u8Port){
			case DIO_u8PORTA:CLR_BIT(PORTA, Copy_u8Pin);break;
			case DIO_u8PORTB:CLR_BIT(PORTB, Copy_u8Pin);break;
			case DIO_u8PORTC:CLR_BIT(PORTC, Copy_u8Pin);break;
			case DIO_u8PORTD:CLR_BIT(PORTD, Copy_u8Pin);break;
			default: Local_u8ErrorState = 1;break;
			}
		}else if(Copy_u8Value == DIO_u8PIN_HIGH){
			switch (Copy_u8Port){
			case DIO_u8PORTA:SET_BIT(PORTA, Copy_u8Pin);break;
			case DIO_u8PORTB:SET_BIT(PORTB, Copy_u8Pin);break;
			case DIO_u8PORTC:SET_BIT(PORTC, Copy_u8Pin);break;
			case DIO_u8PORTD:SET_BIT(PORTD, Copy_u8Pin);break;
			default: Local_u8ErrorState = 1;break;
			}
		}else{
			Local_u8ErrorState = 1;
		}
	}else{
		Local_u8ErrorState = 1;
	}

	return Local_u8ErrorState;
}

uint8 DIO_u8SetPortValue(uint8 Copy_u8Port, uint8 Copy_u8Value){
	uint8 Local_u8ErrorState = 0;

	if(Copy_u8Value >= DIO_u8PORT_INPUT || Copy_u8Value <= DIO_u8PORT_OUTPUT ){
		switch (Copy_u8Port){
		case DIO_u8PORTA:PORTA=Copy_u8Value;break;
		case DIO_u8PORTB:PORTB=Copy_u8Value;break;
		case DIO_u8PORTC:PORTC=Copy_u8Value;break;
		case DIO_u8PORTD:PORTD=Copy_u8Value;break;
		default: Local_u8ErrorState = 1;break;
		}
	}else{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

/*Reading Functions*/
uint8 DIO_u8GetPinValue(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8* Copy_pu8Value){
	uint8 Local_u8ErrorState = 0;
	if( (Copy_pu8Value != NULL) && (Copy_u8Pin <= 7) ){

			switch (Copy_u8Port){
			case DIO_u8PORTA:*Copy_pu8Value = GET_BIT(PINA, Copy_u8Pin);break;
			case DIO_u8PORTB:*Copy_pu8Value = GET_BIT(PINB, Copy_u8Pin);break;
			case DIO_u8PORTC:*Copy_pu8Value = GET_BIT(PINC, Copy_u8Pin);break;
			case DIO_u8PORTD:*Copy_pu8Value = GET_BIT(PIND, Copy_u8Pin);break;
			default: Local_u8ErrorState = 1;break;
			}

	}else{
		Local_u8ErrorState = 1;
	}

	return Local_u8ErrorState;
}
