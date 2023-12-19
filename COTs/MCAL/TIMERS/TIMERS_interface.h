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
	uint8 TimerMode;
	uint8 OCR;
	uint8 PreScaler;
}TIMER_t;

#define TIMER0	1
#define TIMER1	2
#define TIMER2	3

#define TIMER_MODE_MASK							0b10110111
#define TIMER_MODE_NORMAL						0b00000000
#define TIMER_MODE_CTC							0b00001000
#define TIMER_MODE_FAST_PWM						0b01001000
#define TIMER_MODE_CORRECT_PWM					0b01000000

#define TIMER_COMPARE_MASK						0b11001111
#define TIMER_COMPARE_NORMAL        			0b00000000
#define TIMER_COMPARE_TOGGLE        			0b00010000
#define TIMER_COMPARE_CLEAR         			0b00100000
#define TIMER_COMPARE_SET          				0b00110000

#define TIMER_PRE_SCALE_MASK					0b11111000
#define TIMER_PRE_SCALE_1	                    0b00000001
#define TIMER_PRE_SCALE_8                       0b00000010
#define TIMER_PRE_SCALE_64                      0b00000011
#define TIMER_PRE_SCALE_256                     0b00000100
#define TIMER_PRE_SCALE_1024                    0b00000101
#define TIMER_PRE_SCALE_EXT_FALLING_EADGE       0b00000110
#define TIMER_PRE_SCALE_EXT_RISING_EADGE        0b00000111

#define TIMER_TIMSK_T0_MASK						0b11111100
#define TIMER_TIMSK_T0_COMARE_IE				0b00000010
#define TIMER_TIMSK_T0_OVERFLOW_IE				0b00000001

#define TIMER_TIMSK_T2_MASK						0b00111111
#define TIMER_TIMSK_T2_COMARE_IE				0b10000000
#define TIMER_TIMSK_T2_OVERFLOW_IE				0b01000000

void TIMER_vdInit( TIMER_t *Timer );

uint8 TIMER_u8SetCallBack( uint8 Copy_u8Timer, void (*Copy_pdvCallBackFunction)(void) );

#endif
