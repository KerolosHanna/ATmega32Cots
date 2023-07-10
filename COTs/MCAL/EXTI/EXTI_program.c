/*****************************************************************/
/*****************************************************************/
/************		Author: Kerolos Hanna			**************/
/************		Kerolos.Hanna@hotmail.com		**************/
/************		Layer:	MCAL					**************/
/************		SWC:	EXTI						**************/
/************		version: 1.00					**************/
/*****************************************************************/
/*****************************************************************/

#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"
#include "..\..\MCAL\DIO\DIO_interface.h"


#include "EXTI_register.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"


void EXTI_vdInt0Init(){
	/*Setting the Interrupt type*/
	EXTI_vdInerruptType(EXTI_INT0, EXTI_FALLING_EDGE);

	/*Enabling INT0 Peripheral interrupt*/
	SET_BIT(GICR, GICR_INT0);
}
void EXTI_vdInt1Init(){
	/*Setting the Interrupt type*/
	EXTI_vdInerruptType(EXTI_INT1, EXTI_FALLING_EDGE);

	/*Enabling INT0 Peripheral interrupt*/
	SET_BIT(GICR, GICR_INT1);
}
void EXTI_vdInt2Init(){
	/*only accepts falling or raising edges*/
	/*Setting the Interrupt type*/
	EXTI_vdInerruptType(EXTI_INT2, EXTI_FALLING_EDGE);

	/*Enabling INT0 Peripheral interrupt*/
	SET_BIT(GICR, GICR_INT2);
}

void EXTI_vdInerruptType(uint8 Copy_IntPin, uint8 Copy_IntType){
	switch(Copy_IntPin){
	case EXTI_INT0:
		switch(Copy_IntType){
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
		}
		break;
		case EXTI_INT1:
			switch(Copy_IntType){
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
			}
			break;
			case EXTI_INT2:
				switch(Copy_IntType){
				case EXTI_FALLING_EDGE:
					CLR_BIT(MCUCSR, MCUCSR_INT2);
					break;
				case EXTI_RAISING_EDGE:
					SET_BIT(MCUCSR, MCUCSR_INT2);
					break;
				}
				break;
	}
}
