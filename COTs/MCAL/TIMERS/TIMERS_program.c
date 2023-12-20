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
static void (*TIMER1A_vdSetCallBack)(void) = NULL;
static void (*TIMER1B_vdSetCallBack)(void) = NULL;
static void (*TIMER2_vdSetCallBack)(void) = NULL;

void TIMER_vdSetOCR( TIMER_t *Timer ){
	switch(Timer->Timer){
	case TIMER0:
		//Set OCR
		OCR0 = Timer->OCR;
		break;
	case TIMER1:
		//Set OCR
		ICR1 = Timer->ICR;
		OCR1A = Timer->OCRA;
		OCR1B = Timer->OCRB;
		break;
	case TIMER2:
		//Set OCR
		OCR2 = Timer->OCR;
		break;
	}
}

void TIMER_vdInit( TIMER_t *Timer ){
	switch(Timer->Timer){
	case TIMER0:
		// Set Timer Waveform Mode
		TCCR0 &= TIMER_WAVEFORM_MASK;
		TCCR0 |= Timer->WaveformMode;

		// Set Interrupt Enable
		TIMSK &= TIMER_TIMSK_T0_MASK;
		if(Timer->WaveformMode == TIMER_WAVEFORM_CTC)	{TIMSK |= TIMER_TIMSK_T0_COMARE_IE;}
		if(Timer->WaveformMode == TIMER_WAVEFORM_NORMAL){TIMSK |= TIMER_TIMSK_T0_OVERFLOW_IE;}

		// Set output mode
		TCCR0 &= TIMER_OUTPUT_MASK;
		if(Timer->WaveformMode != TIMER_WAVEFORM_NORMAL){TCCR0 |= Timer->OutputModeA;}

		//Set OCR
		OCR0 = Timer->OCR;

		//Set Pre-Scaler
		TCCR0 &= TIMER_PRE_SCALE_MASK;
		TCCR0 |= Timer->PreScaler;
		break;
	case TIMER1:

		// Set Timer Waveform Mode
		TCCR1A &= TIMER1A_WAVEFORM_MASK;
		TCCR1B &= TIMER1B_WAVEFORM_MASK;

		switch(Timer->WaveformMode){
		case TIMER1_WAVEFORM_NORMAL:
			TCCR1A |= TIMER1A_WAVEFORM_NORMAL;
			TCCR1B |= TIMER1B_WAVEFORM_NORMAL;
			break;
		case TIMER1_WAVEFORM_P_CORRECT_PWM_OCR:
			TCCR1A |= TIMER1A_WAVEFORM_P_CORRECT_PWM_OCR;
			TCCR1B |= TIMER1B_WAVEFORM_P_CORRECT_PWM_OCR;
			break;
		case TIMER1_WAVEFORM_P_CORRECT_PWM_ICR:
			TCCR1A |= TIMER1A_WAVEFORM_P_CORRECT_PWM_ICR;
			TCCR1B |= TIMER1B_WAVEFORM_P_CORRECT_PWM_ICR;
			break;
		case TIMER1_WAVEFORM_P_CORRECT_CTC_ICR:
			TCCR1A |= TIMER1A_WAVEFORM_P_CORRECT_CTC_ICR;
			TCCR1B |= TIMER1B_WAVEFORM_P_CORRECT_CTC_ICR;
			break;
		case TIMER1_WAVEFORM_P_CORRECT_PWM_8BIT:
			TCCR1A |= TIMER1A_WAVEFORM_P_CORRECT_PWM_8BIT;
			TCCR1B |= TIMER1B_WAVEFORM_P_CORRECT_PWM_8BIT;
			break;
		case TIMER1_WAVEFORM_P_CORRECT_PWM_9BIT:
			TCCR1A |= TIMER1A_WAVEFORM_P_CORRECT_PWM_9BIT;
			TCCR1B |= TIMER1B_WAVEFORM_P_CORRECT_PWM_9BIT;
			break;
		case TIMER1_WAVEFORM_P_CORRECT_PWM_10BIT:
			TCCR1A |= TIMER1A_WAVEFORM_P_CORRECT_PWM_10BIT;
			TCCR1B |= TIMER1B_WAVEFORM_P_CORRECT_PWM_10BIT;
			break;
		case TIMER1_WAVEFORM_P_CORRECT_CTC_OCR:
			TCCR1A |= TIMER1A_WAVEFORM_P_CORRECT_CTC_OCR;
			TCCR1B |= TIMER1B_WAVEFORM_P_CORRECT_CTC_OCR;
			break;
		case TIMER1_WAVEFORM_FAST_PWM_OCR:
			TCCR1A |= TIMER1A_WAVEFORM_FAST_PWM_OCR;
			TCCR1B |= TIMER1B_WAVEFORM_FAST_PWM_OCR;
			break;
		case TIMER1_WAVEFORM_FAST_PWM_ICR:
			TCCR1A |= TIMER1A_WAVEFORM_FAST_PWM_ICR;
			TCCR1B |= TIMER1B_WAVEFORM_FAST_PWM_ICR;
			break;
		case TIMER1_WAVEFORM_FAST_PWM_8BIT:
			TCCR1A |= TIMER1A_WAVEFORM_FAST_PWM_8BIT;
			TCCR1B |= TIMER1B_WAVEFORM_FAST_PWM_8BIT;
			break;
		case TIMER1_WAVEFORM_FAST_PWM_9BIT:
			TCCR1A |= TIMER1A_WAVEFORM_FAST_PWM_9BIT;
			TCCR1B |= TIMER1B_WAVEFORM_FAST_PWM_9BIT;
			break;
		case TIMER1_WAVEFORM_FAST_PWM_10BIT:
			TCCR1A |= TIMER1A_WAVEFORM_FAST_PWM_10BIT;
			TCCR1B |= TIMER1B_WAVEFORM_FAST_PWM_10BIT;
			break;
		case TIMER1_WAVEFORM_P_F_CORRECT_PWM_OCR:
			TCCR1A |= TIMER1A_WAVEFORM_P_F_CORRECT_PWM_OCR;
			TCCR1B |= TIMER1B_WAVEFORM_P_F_CORRECT_PWM_OCR;
			break;
		case TIMER1_WAVEFORM_P_F_CORRECT_PWM_ICR:
			TCCR1A |= TIMER1A_WAVEFORM_P_F_CORRECT_PWM_ICR;
			TCCR1B |= TIMER1B_WAVEFORM_P_F_CORRECT_PWM_ICR;
			break;
		}

		// Set Interrupt Enable
		TIMSK &= TIMER_TIMSK_T1_MASK;

		//Set output mode
		if( Timer->WaveformMode != TIMER1_WAVEFORM_NORMAL ){
			TCCR1A &= TIMER1_OUTPUT_MASK;
			TCCR1A |= Timer->OutputModeA;
			TCCR1B |= (Timer->OutputModeB << 2);
		}

		//Set OCRs and ICRs
		ICR1 = Timer->ICR;
		OCR1A = Timer->OCRA;
		OCR1B = Timer->OCRB;

		//Set Pre-Scaler
		TCCR1B &= TIMER_PRE_SCALE_MASK;
		TCCR1B |= Timer->PreScaler;
		break;
		case TIMER2:
			// Set Timer Waveform Mode
			TCCR2 &= TIMER_WAVEFORM_MASK;
			TCCR2 |= Timer->WaveformMode;

			// Set Interrupt Enable
			TIMSK &= TIMER_TIMSK_T2_MASK;
			if(Timer->WaveformMode == TIMER_WAVEFORM_CTC){
				TIMSK |= TIMER_TIMSK_T2_COMARE_IE;
			}
			else if(Timer->WaveformMode == TIMER_WAVEFORM_NORMAL){
				TIMSK |= TIMER_TIMSK_T2_OVERFLOW_IE;
			}

			// Set output mode
			if( Timer->WaveformMode != TIMER_WAVEFORM_NORMAL ){
				TCCR2 &= TIMER_OUTPUT_MASK;
				TCCR2 |= Timer->OutputModeA;
			}

			//Set OCR
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
		case TIMER1A:
			TIMER1A_vdSetCallBack = Copy_pdvCallBackFunction;
			break;
		case TIMER1B:
			TIMER1B_vdSetCallBack = Copy_pdvCallBackFunction;
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
	if( TIMER1A_vdSetCallBack != NULL ){
		TIMER1A_vdSetCallBack();
	}
}

//Timer/Counter 1 compare match B ISR
void __vector_8 (void) __attribute__((signal));
void __vector_8 (void){
	if( TIMER1B_vdSetCallBack != NULL ){
		TIMER1B_vdSetCallBack();
	}
}

//Timer/Counter 2 compare match ISR
void __vector_4 (void) __attribute__((signal));
void __vector_4 (void){
	if( TIMER2_vdSetCallBack != NULL ){
		TIMER2_vdSetCallBack();
	}
}
