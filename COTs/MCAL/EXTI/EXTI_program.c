/*****************************************************************/
/*****************************************************************/
/************		Author: Kerolos Hanna			**************/
/************		Kerolos.Hanna@hotmail.com		**************/
/************		Layer:	MCAL					**************/
/************		SWC:	EXTI					**************/
/************		version: 1.00					**************/
/*****************************************************************/
/*****************************************************************/

#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"
#include "..\..\MCAL\DIO\DIO_interface.h"


#include "EXTI_register.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"

/*Global Pointers to Functions hold ISRs Addresses*/
void ( * EXTI_pvdInt0Fun ) (void) = NULL;
void ( * EXTI_pvdInt1Fun ) (void) = NULL;
void ( * EXTI_pvdInt2Fun ) (void) = NULL;

void EXTI_vdInt0Init(){ //PD2
#if		INT0_SENSE == LOW_LEVEL
	CLR_BIT(MCUCR, MCUCR_ISC11);
	CLR_BIT(MCUCR, MCUCR_ISC10);
#elif	INT0_SENSE == ON_CHANGE
	CLR_BIT(MCUCR, MCUCR_ISC11);
	SET_BIT(MCUCR, MCUCR_ISC10);
#elif	INT0_SENSE == RAISING_EDGE
	CLR_BIT(MCUCR, MCUCR_ISC10);
	SET_BIT(MCUCR, MCUCR_ISC11);
#elif	INT0_SENSE == FALLING_EDGE
	SET_BIT(MCUCR, MCUCR_ISC10);
	SET_BIT(MCUCR, MCUCR_ISC11);
#else
#error "Wrong INT0_SENSE configuration option"
#endif
#if INT0_INITIAL_STATE == ENABLED
	/*Enabling INT0 Peripheral interrupt*/
	SET_BIT(GICR, GICR_INT0);
#elif INT0_INITIAL_STATE == DISABLED
	/*Disabling INT0 Peripheral interrupt*/
	CLR_BIT(GICR, GICR_INT0);
#else
#error "Wrong INT0_INITIAL_STATE configuration option"
#endif
}
void EXTI_vdInt1Init(){ //PD3
#if		INT1_SENSE == LOW_LEVEL
	CLR_BIT(MCUCR, MCUCR_ISC01);
	CLR_BIT(MCUCR, MCUCR_ISC00);
#elif	INT1_SENSE == ON_CHANGE
	CLR_BIT(MCUCR, MCUCR_ISC01);
	SET_BIT(MCUCR, MCUCR_ISC00);
#elif	INT1_SENSE == RAISING_EDGE
	CLR_BIT(MCUCR, MCUCR_ISC00);
	SET_BIT(MCUCR, MCUCR_ISC01);
#elif	INT1_SENSE == FALLING_EDGE
	SET_BIT(MCUCR, MCUCR_ISC00);
	SET_BIT(MCUCR, MCUCR_ISC01);
#else
#error "Wrong INT1_SENSE configuration option"
#endif
#if INT0_INITIAL_STATE == ENABLED
	/*Enabling INT0 Peripheral interrupt*/
	SET_BIT(GICR, GICR_INT1);
#elif INT0_INITIAL_STATE == DISABLED
	/*Disabling INT0 Peripheral interrupt*/
	CLR_BIT(GICR, GICR_INT1);
#else
#error "Wrong INT1_INITIAL_STATE configuration option"
#endif
}
void EXTI_vdInt2Init(){ //PB2
#if	INT2_SENSE == RAISING_EDGE
	SET_BIT(MCUCSR, MCUCSR_INT2);
#elif	INT2_SENSE == FALLING_EDGE
	CLR_BIT(MCUCSR, MCUCSR_INT2);
#else
#error "Wrong INT2_SENSE configuration option"
#endif
#if INT0_INITIAL_STATE == ENABLED
	/*Enabling INT0 Peripheral interrupt*/
	SET_BIT(GICR, GICR_INT2);
#elif INT0_INITIAL_STATE == DISABLED
	/*Disabling INT0 Peripheral interrupt*/
	CLR_BIT(GICR, GICR_INT2);
#else
#error "Wrong INT2_INITIAL_STATE configuration option"
#endif
}

uint8 EXTI_u8SetPeripheral(uint8 Copy_u8Int, uint8 Copy_u8Status ){
	uint8 Local_u8ErrorState = OK;
	switch(Copy_u8Int){
	case EXTI_INT0:
		switch(Copy_u8Status){
		case ENABLED:
			SET_BIT(GICR, GICR_INT0);
			break;
		case DISABLED:
			CLR_BIT(GICR, GICR_INT0);
			break;
		default: Local_u8ErrorState = NOK;
		}
		break;
		case EXTI_INT1:
			switch(Copy_u8Status){
			case ENABLED:
				SET_BIT(GICR, GICR_INT1);
				break;
			case DISABLED:
				CLR_BIT(GICR, GICR_INT1);
				break;
			default: Local_u8ErrorState = NOK;
			}
			break;
			case EXTI_INT2:
				switch(Copy_u8Status){
				case ENABLED:
					SET_BIT(GICR, GICR_INT2);
					break;
				case DISABLED:
					CLR_BIT(GICR, GICR_INT2);
					break;
				default: Local_u8ErrorState = NOK;
				}
				break;
				default: Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}

uint8 EXTI_u8InerruptType(uint8 Copy_u8Int, uint8 Copy_u8IntType){
	uint8 Local_u8ErrorState = OK;
	switch(Copy_u8Int){
	case EXTI_INT0:
		switch(Copy_u8IntType){
		case EXTI_LOW:
			CLR_BIT(MCUCR, MCUCR_ISC11);
			CLR_BIT(MCUCR, MCUCR_ISC10);
			break;
		case EXTI_ON_CHANGE:
			CLR_BIT(MCUCR, MCUCR_ISC11);
			SET_BIT(MCUCR, MCUCR_ISC10);
			break;
		case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR, MCUCR_ISC10);
			SET_BIT(MCUCR, MCUCR_ISC11);
			break;
		case EXTI_RAISING_EDGE:
			SET_BIT(MCUCR, MCUCR_ISC10);
			SET_BIT(MCUCR, MCUCR_ISC11);
			break;
		default: Local_u8ErrorState = NOK;
		}
		break;
		case EXTI_INT1:
			switch(Copy_u8IntType){
			case EXTI_LOW:
				CLR_BIT(MCUCR, MCUCR_ISC01);
				CLR_BIT(MCUCR, MCUCR_ISC00);
				break;
			case EXTI_ON_CHANGE:
				CLR_BIT(MCUCR, MCUCR_ISC01);
				SET_BIT(MCUCR, MCUCR_ISC00);
				break;
			case EXTI_FALLING_EDGE:
				CLR_BIT(MCUCR, MCUCR_ISC00);
				SET_BIT(MCUCR, MCUCR_ISC01);
				break;
			case EXTI_RAISING_EDGE:
				SET_BIT(MCUCR, MCUCR_ISC00);
				SET_BIT(MCUCR, MCUCR_ISC01);
				break;
			default: Local_u8ErrorState = NOK;
			}
			break;
			case EXTI_INT2:
				switch(Copy_u8IntType){
				case EXTI_FALLING_EDGE:
					CLR_BIT(MCUCSR, MCUCSR_INT2);
					break;
				case EXTI_RAISING_EDGE:
					SET_BIT(MCUCSR, MCUCSR_INT2);
					break;
				default: Local_u8ErrorState = NOK;
				}
				break;
				default: Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}


void __vector_1 (void) __attribute__((signal));
void __vector_1 (void){
	if ( EXTI_pvdInt0Fun != NULL ){
		EXTI_pvdInt0Fun();
	}else{/*Do Nothing*/}
}

void __vector_2 (void) __attribute__((signal));
void __vector_2 (void){
	if ( EXTI_pvdInt1Fun != NULL ){
		EXTI_pvdInt1Fun();
	}else{/*Do Nothing*/}
}

void __vector_3 (void) __attribute__((signal));
void __vector_3 (void){
	if ( EXTI_pvdInt2Fun != NULL ){
		EXTI_pvdInt2Fun();
	}else{/*Do Nothing*/}
}

uint8 EXTI_u8Int0SetCallBack(void (*Copy_pvdInt0Func) (void)){
	uint8 Local_u8ErrorState = OK;

	if(Copy_pvdInt0Func != NULL){
		EXTI_pvdInt0Fun = Copy_pvdInt0Func;
	}else{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;
}
uint8 EXTI_u8Int1SetCallBack(void (*Copy_pvdInt1Func) (void)){
	uint8 Local_u8ErrorState = OK;

	if(Copy_pvdInt1Func != NULL){
		EXTI_pvdInt1Fun = Copy_pvdInt1Func;
	}else{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;
}
uint8 EXTI_u8Int2SetCallBack(void (*Copy_pvdInt2Func) (void)){
	uint8 Local_u8ErrorState = OK;

	if(Copy_pvdInt2Func != NULL){
		EXTI_pvdInt2Fun = Copy_pvdInt2Func;
	}else{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;
}
