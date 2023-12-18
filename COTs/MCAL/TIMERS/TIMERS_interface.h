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

#define TIMER0	1
#define TIMER1	2
#define TIMER2	3

void TIMER_vdInit( uint8 Copy_u8Timer );

uint8 TIMER_u8SetCallBack( uint8 Copy_u8Timer, void (*Copy_pdvCallBackFunction)(void) );

#endif
