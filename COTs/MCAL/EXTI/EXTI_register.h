/*****************************************************************/
/*****************************************************************/
/************		Author: Kerolos Hanna			**************/
/************		Kerolos.Hanna@hotmail.com		**************/
/************		Layer:	MCAL					**************/
/************		SWC:	EXTI					**************/
/************		version: 1.00					**************/
/*****************************************************************/
/*****************************************************************/

#ifndef EXTI_REGISTER_H
#define EXTI_REGISTER_H

#define GICR			*( (volatile uint8 *) 0x5B )	//General Interrupt Control Register
#define GICR_INT1		7								//PD2 Supports Falling/Rising/Low/On change
#define GICR_INT0		6								//PD3 Supports Falling/Rising/Low/On change
#define GICR_INT2		5								//PB2 Supports Falling/Rising

#define GIFR			*( (volatile uint8 *) 0x5A )	//General Interrupt Flag Register

#define MCUCR			*( (volatile uint8 *) 0x55 )	//MCU Control Register
#define MCUCR_ISC00		0
#define MCUCR_ISC01		1
#define MCUCR_ISC10		2
#define MCUCR_ISC11		3

#define MCUCSR			*( (volatile uint8 *) 0x54 )	//MCU Control and Status Register
#define MCUCSR_INT2		6

#endif
