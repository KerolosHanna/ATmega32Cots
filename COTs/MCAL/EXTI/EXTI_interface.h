/*****************************************************************/
/*****************************************************************/
/************		Author: Kerolos Hanna			**************/
/************		Kerolos.Hanna@hotmail.com		**************/
/************		Layer:	MCAL					**************/
/************		SWC:	EXTI					**************/
/************		version: 1.00					**************/
/*****************************************************************/
/*****************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define EXTI_INT0				0
#define EXTI_INT1				1
#define EXTI_INT2				2

#define EXTI_LOW				0
#define EXTI_ON_CHANGE			1
#define EXTI_FALLING_EDGE		2
#define EXTI_RAISING_EDGE		3

void EXTI_vdInt0Init();
void EXTI_vdInt1Init();
void EXTI_vdInt2Init();

void EXTI_vdInerruptType(uint8 Copy_IntPin, uint8 Copy_IntType);

#endif
