/*****************************************************************/
/************		Author: Kerolos Hanna"			**************/
/************		Kerolos.Hanna@hotmail.com		**************/
/************		Layer:	MCAL					**************/
/************		SWC:	TIMERS					**************/
/************		version: 1.00					**************/
/*****************************************************************/
/*****************************************************************/

#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

typedef struct{
	uint8 Timer;
	uint8 WaveformMode;
	uint8 OutputModeA;
	uint8 OutputModeB;
	uint8 OCR;
	uint16 ICR;
	uint16 OCRA;
	uint16 OCRB;
	uint8 PreScaler;
	void (*vdCallBackFunction)(void);
}TIMER_t;

void TIMER_vdSetOCR( TIMER_t *Timer );
void TIMER_vdInit( TIMER_t *Timer );
uint8 TIMER_u8SetCallBack( uint8 Copy_u8Timer, void (*Copy_pdvCallBackFunction)(void) );

#define TIMER0									1
#define TIMER1									2
#define TIMER1A									3
#define TIMER1B									4
#define TIMER2									5

#define TIMER_WAVEFORM_NORMAL					0b00000000
#define TIMER_WAVEFORM_CTC						0b00001000
#define TIMER_WAVEFORM_FAST_PWM					0b01001000
#define TIMER_WAVEFORM_CORRECT_PWM				0b01000000

#define TIMER1_WAVEFORM_NORMAL					1
#define TIMER1_WAVEFORM_P_CORRECT_PWM_OCR       2
#define TIMER1_WAVEFORM_P_CORRECT_PWM_ICR       3
#define TIMER1_WAVEFORM_P_CORRECT_CTC_ICR       4
#define TIMER1_WAVEFORM_P_CORRECT_PWM_8BIT      5
#define TIMER1_WAVEFORM_P_CORRECT_PWM_9BIT      6
#define TIMER1_WAVEFORM_P_CORRECT_PWM_10BIT     7
#define TIMER1_WAVEFORM_P_CORRECT_CTC_OCR       8
#define TIMER1_WAVEFORM_FAST_PWM_OCR            9
#define TIMER1_WAVEFORM_FAST_PWM_ICR            10
#define TIMER1_WAVEFORM_FAST_PWM_8BIT           11
#define TIMER1_WAVEFORM_FAST_PWM_9BIT           12
#define TIMER1_WAVEFORM_FAST_PWM_10BIT          13
#define TIMER1_WAVEFORM_P_F_CORRECT_PWM_OCR     14
#define TIMER1_WAVEFORM_P_F_CORRECT_PWM_ICR     15

#define TIMER_OUTPUT_NORMAL    	    			0b00000000
#define TIMER_OUTPUT_TOGGLE    	    			0b00010000
#define TIMER_OUTPUT_CLEAR      	   			0b00100000
#define TIMER_OUTPUT_SET          				0b00110000

#define TIMER_PRE_SCALE_1	                    0b00000001
#define TIMER_PRE_SCALE_8                       0b00000010
#define TIMER_PRE_SCALE_64                      0b00000011
#define TIMER_PRE_SCALE_256                     0b00000100
#define TIMER_PRE_SCALE_1024                    0b00000101
#define TIMER_PRE_SCALE_EXT_FALLING_EADGE       0b00000110
#define TIMER_PRE_SCALE_EXT_RISING_EADGE        0b00000111

#define TIMER_TIMSK_T0_COMARE_IE				0b00000010
#define TIMER_TIMSK_T0_OVERFLOW_IE				0b00000001

#define TIMER_TIMSK_T1_INPUT_CAPTURE_IE			0b00100000
#define TIMER_TIMSK_T1A_COMARE_IE				0b00010000
#define TIMER_TIMSK_T1B_COMARE_IE				0b00001000
#define TIMER_TIMSK_T1_OVERFLOW_IE				0b00000100

#define TIMER_TIMSK_T2_COMARE_IE				0b10000000
#define TIMER_TIMSK_T2_OVERFLOW_IE				0b01000000

#endif
