/*****************************************************************/
/************		Author: Kerolos Hanna"			**************/
/************		Kerolos.Hanna@hotmail.com		**************/
/************		Layer:	MCAL					**************/
/************		SWC:	ADC						**************/
/************		version: 1.00					**************/
/*****************************************************************/
/*****************************************************************/

#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"

#include "ADC_register.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_interface.h"

void ( * ADC_pvdIntFun ) (void) = NULL;

void ADC_vdInit(){
	/*ADC reference Voltage*/
	/*Clear the Reference bits in ADMUX*/
	ADMUX &= ADC_REF_MASK;
	/*Set the Reference Voltage*/
	ADMUX |= ADC_REF;

	/*Resolution*/
	/*Clear the Resolution bit in ADMUX Also its 1024 Resolution*/
	ADMUX &= ADC_RESOLUTION_MASK;
#if		ADC_RESOLUTION == ADC_RESOLUTION_08BIT
	/*Set the Resolution to 265*/
	ADMUX |= ADC_RESOLUTION;
#endif

	/*Set Pre-Scaler*/
	/*Clear the Pre-scaler bits in ADCSRA*/
	ADCSRA &= ADC_PRESCALER_MASK;
	/*Set the Timer Divider 2, 4, 8, 16, 32, 64, or 128*/
	ADCSRA |= ADC_PRESCALER;

	/*Clear The MUX bits in ADMUX*/
	ADMUX &= ADC_MUX_MASK;

	/*Conversion Mode*/
	/*Clear the Conversion Mode bits in ADCSRA*/
	ADCSRA &= ADC_CONVERSION_MASK;
	/*Set the Conversion Mode*/
	ADCSRA |= ADC_CONVERSION_MODE;

	/*Trigger Mode*/
	/*Clear the Trigger Enable/Disable bits in ADCSRA also set it to Disable*/
	ADCSRA &= ADC_TRIGGER_MASK;


#if ADC_TRIGGER == ADC_AUTO_TRIGGER_ENABLE

	/*Enable Auto triggering mode*/
	ADCSRA |= ADC_TRIGGER;

	/*Auto Trigger Mode*/
	/*Clear the Trigger Mode bits in SFIOR*/
	SFIOR &= SFIOR_TRIGGER_MASK;
	/*Set the Auto Trigger Mode*/
	SFIOR |= ADC_TRIGGER_MODE;

	/*Start Conversion*/
	SET_BIT(ADCSRA, ADCSRA_ADSC);

#endif
	/*Enabling the peripheral*/
	SET_BIT(ADCSRA, ADCSRA_ADEN);
}

uint8 ADC_u16SynchronousConversion( uint8 *Copy_pu8Reading, uint8 Copy_u8Channel ){

	uint8 Local_u8ErrorState = OK;
	uint32 Local_u32Counter = 0;

	//Clear The MUX bits in ADMUX
	ADMUX &= ADC_MUX_MASK;

	//Set the Required channel
	ADMUX |= Copy_u8Channel;

	//Start Conversion
	SET_BIT(ADCSRA, ADCSRA_ADSC);

	//Polling busy waiting till the conversion is complete or counter reach timeout
	while( ((GET_BIT(ADCSRA, ADCSRA_ADIF)) == 0) && (Local_u32Counter != ADC_u32TIMEOUT) ){
		Local_u32Counter++;
	}

	if ((Local_u32Counter == ADC_u32TIMEOUT)){
		//the loop is broken because counter reached timeout
		Local_u8ErrorState = NOK;
	}else{
		//the loop is broken because flag is raised
		// the conversion complete flag
		SET_BIT(ADCSRA, ADCSRA_ADIF);

		//Return the Value
#if		ADC_RESOLUTION == ADC_RESOLUTION_08BIT
		*Copy_pu8Reading = ADCH;
#elif	ADC_RESOLUTION == ADC_RESOLUTION_10BIT
		*Copy_pu8Reading = ADC_10_BIT;
#endif
	}


	return Local_u8ErrorState;
}


/*void __vector_1 (void) __attribute__((signal));
void __vector_1 (void){
	if ( ADC_pvdIntFun != NULL ){
		ADC_pvdIntFun();
	}else{}//Do Nothing
}*/

uint8 ADC_u8IntSetCallBack(void (*Copy_pvdIntFunc) (void)){
	uint8 Local_u8ErrorState = OK;

	if(Copy_pvdIntFunc != NULL){
		ADC_pvdIntFun = Copy_pvdIntFunc;
	}else{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;
}
