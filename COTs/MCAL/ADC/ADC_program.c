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

void ADC_vdInit(){

	/*ADC reference Voltage*/
	/*Clear the Reference bits in ADMUX*/
	ADMUX &= ADC_REF_MASK;
	/*Set the Reference Type*/
	ADMUX |= ADC_REF;

	/*Activate Left Adjust*/
	SET_BIT(ADMUX, ADMUX_ADLAR);

	/*Set Pre-Scaler*/
	/*Clear the Pre-scaler bits in ADCSRA*/
	ADCSRA &= ADC_PRESCALER_MASK;
	/*Set the Timer Divider*/
	ADCSRA |= ADCSRA_TIMER;

	/*Enabling peripheral*/
	SET_BIT(ADCSRA, ADCSRA_ADEN);
}

uint8 ADC_u8ChannelReading( uint8 Copy_u8Channel ){

	/*Clear The MUX bits in ADMUX*/
	ADMUX &= ADC_MUX_MASK;

	/*Set the Required channel*/
	ADMUX |= Copy_u8Channel;

	/*Start Conversion*/
	SET_BIT(ADCSRA, ADCSRA_ADSC);

	/*Polling busy waiting till the conversion is complete*/
	while( (GET_BIT(ADCSRA, ADCSRA_ADIF)) == 0 );

	/*Clear the conversion complete flag*/
	SET_BIT(ADCSRA, ADCSRA_ADIF);

	/*Return the Value*/
	return ADCH;
}
