/*****************************************************************/
/************		Author: Kerolos Hanna"			**************/
/************		Kerolos.Hanna@hotmail.com		**************/
/************		Layer:	MCAL					**************/
/************		SWC:	GENERIC_FUNC			**************/
/************		version: 1.00					**************/
/*****************************************************************/
/*****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GENERIC_FUNC_interface.h"


f32 s32Mapping(suint32 Copy_s23MinInput, suint32 Copy_s23MaxInput, suint32 Copy_s23MinOutput, suint32 Copy_s23MaxOutput, suint32 Copy_s23InputValue){
	f32 Local_s32OutputValue;

	Local_s32OutputValue = Copy_s23MinOutput + (((Copy_s23InputValue - Copy_s23MinInput)*(Copy_s23MaxOutput - Copy_s23MinOutput))/(Copy_s23MaxInput - Copy_s23MinInput));
	return Local_s32OutputValue;
}
