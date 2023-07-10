/*****************************************************************/
/*****************************************************************/
/************		Author: Kerolos Hanna			**************/
/************		Kerolos.Hanna@hotmail.com		**************/
/************		Layer:	MCAL					**************/
/************		SWC:	GIE						**************/
/************		version: 1.00					**************/
/*****************************************************************/
/*****************************************************************/

#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"
#include "..\..\MCAL\DIO\DIO_interface.h"

#include "GIE_register.h"
#include "GIE_config.h"
#include "GIE_private.h"
#include "GIE_interface.h"

void GIE_vdEnable(){
	SET_BIT(SREG, SREG_I);
}
void GIE_vdDisable(){
	CLR_BIT(SREG, SREG_I);
}
