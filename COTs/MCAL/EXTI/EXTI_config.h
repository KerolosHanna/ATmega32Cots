/*****************************************************************/
/*****************************************************************/
/************		Author: Kerolos Hanna			**************/
/************		Kerolos.Hanna@hotmail.com		**************/
/************		Layer:	MCAL					**************/
/************		SWC:	EXTI					**************/
/************		version: 1.00					**************/
/*****************************************************************/
/*****************************************************************/

#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

#define EXTI_BUILD_TYPE		PREBUILD

/* Types
 * LOW_LEVEL	|_____|
 * ON_CHANGE	|__-__| or |--_--|
 * FALLING_EDGE	|--_--|
 * RAISING_EDGE	|__-__|
 */

/*Accepts all types*/
#define INT0_SENSE				FALLING_EDGE
/*Accepts all types*/
#define INT1_SENSE				FALLING_EDGE
/*Accepts only falling or Rising edge*/
#define INT2_SENSE				FALLING_EDGE


/*ENABLED or DISABLED*/
#define INT0_INITIAL_STATE		ENABLED
#define INT1_INITIAL_STATE		ENABLED
#define INT2_INITIAL_STATE		ENABLED

#endif
