/*****************************************************************/
/*****************************************************************/
/************		Author: Kerolos Hanna			**************/
/************		Kerolos.Hanna@hotmail.com		**************/
/************		Layer:	MCAL					**************/
/************		SWC:	EXTI						**************/
/************		version: 1.00					**************/
/*****************************************************************/
/*****************************************************************/

#ifndef EXTI_REGISTER_H
#define EXTI_REGISTER_H

#define GICR			*( (volatile uint8 *) 0x5B )
#define GICR_INT1		7
#define GICR_INT0		6
#define GICR_INT2		5

#define GIFR			*( (volatile uint8 *) 0x5A )

#define MCUCR			*( (volatile uint8 *) 0x55 )
#define MCUCR_ISC00		0
#define MCUCR_ISC01		1
#define MCUCR_ISC10		2
#define MCUCR_ISC11		3

#define MCSCR			*( (volatile uint8 *) 0x54 )
#define MCSCR_INT2		6

#endif
