/*****************************************************************/
/************		Author: Kerolos Hanna"			**************/
/************		Kerolos.Hanna@hotmail.com		**************/
/************		Layer:	MCAL					**************/
/************		SWC:	TIMERS					**************/
/************		version: 1.00					**************/
/*****************************************************************/
/*****************************************************************/

#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"

#include "TIMERS_register.h"
#include "TIMERS_private.h"
#include "TIMERS_config.h"
#include "TIMERS_interface.h"

static void (*TIMER0_vdSetCallBack)(void) = NULL;
static void (*TIMER1_vdSetCallBack)(void) = NULL;
static void (*TIMER2_vdSetCallBack)(void) = NULL;

void TIMER_vdInit( TIMER_t *Timer ){
	switch(Timer->Timer){
	case TIMER0:
		// Set Timer Mode
		TCCR0 &= TIMER_MODE_MASK;
		TCCR0 |= Timer->TimerMode;

		// Set Interrupt Enable
		TIMSK &= TIMER_TIMSK_T0_MASK;
		if(Timer->TimerMode == TIMER_MODE_CTC){TIMSK |= TIMER_TIMSK_T0_COMARE_IE;}
		if(Timer->TimerMode == TIMER_MODE_NORMAL){TIMSK |= TIMER_TIMSK_T0_OVERFLOW_IE;}
		//Set OCR0 to 250
		OCR0 = Timer->OCR;

		//Set Pre-Scaler
		TCCR0 &= TIMER_PRE_SCALE_MASK;
		TCCR0 |= Timer->PreScaler;
		break;
	case TIMER1:
		break;
	case TIMER2:
		// Set Timer Mode
		TCCR2 &= TIMER_MODE_MASK;
		TCCR2 |= Timer->TimerMode;

		// Set Interrupt Enable
		TIMSK &= TIMER_TIMSK_T2_MASK;
		if(Timer->TimerMode == TIMER_MODE_CTC){TIMSK |= TIMER_TIMSK_T2_COMARE_IE;}
		if(Timer->TimerMode == TIMER_MODE_NORMAL){TIMSK |= TIMER_TIMSK_T2_OVERFLOW_IE;}
		//Set OCR0 to 250
		OCR2 = Timer->OCR;

		//Set Pre-Scaler
		TCCR2 &= TIMER_PRE_SCALE_MASK;
		TCCR2 |= Timer->PreScaler;
		break;
	}
}

uint8 TIMER_u8SetCallBack( uint8 Copy_u8Timer, void (*Copy_pdvCallBackFunction)(void) ){
	uint8 Local_u8ErorStatus = OK;
	if( Copy_pdvCallBackFunction != NULL ){
		switch(Copy_u8Timer){
		case TIMER0:
			TIMER0_vdSetCallBack = Copy_pdvCallBackFunction;
			break;
		case TIMER1:
			TIMER1_vdSetCallBack = Copy_pdvCallBackFunction;
			break;
		case TIMER2:
			TIMER2_vdSetCallBack = Copy_pdvCallBackFunction;
			break;
		}
	}else{
		Local_u8ErorStatus = NULL_POINTER;
	}
	return Local_u8ErorStatus;
}

//Timer/Counter 0 compare match ISR
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void){
	if( TIMER0_vdSetCallBack != NULL ){
		TIMER0_vdSetCallBack();
	}
}

//Timer/Counter 1 compare match A ISR
void __vector_7 (void) __attribute__((signal));
void __vector_7 (void){
	if( TIMER1_vdSetCallBack != NULL ){
		TIMER1_vdSetCallBack();
	}
}

//Timer/Counter 1 compare match B ISR
void __vector_8 (void) __attribute__((signal));
void __vector_8 (void){
	if( TIMER1_vdSetCallBack != NULL ){
		TIMER1_vdSetCallBack();
	}
}

//Timer/Counter 2 compare match ISR
void __vector_4 (void) __attribute__((signal));
void __vector_4 (void){
	if( TIMER2_vdSetCallBack != NULL ){
		TIMER2_vdSetCallBack();
	}
}
