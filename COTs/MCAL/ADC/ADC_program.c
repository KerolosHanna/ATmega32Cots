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

static void ( * ADC_pvdCallBackNotificationFunc ) (void) = NULL;

static uint16 *ADC_pu16Reading = NULL;
static uint8 ADC_u8State = IDLE;
static uint8 ADC_u8ISRType;

static uint8	* ADC_pu8ChainChannels = NULL;
static uint16	* ADC_pu16ChainResult = NULL;
static uint8	ADC_u8ChainSize;
static uint8	ADC_u8ChainIndex = 0;

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

uint8 ADC_u8SynchronousConversion( uint16 *Copy_pu16Reading, uint8 Copy_u8Channel ){

	uint8 Local_u8ErrorState = OK;
	if(ADC_u8State == IDLE){

		uint32 Local_u32Counter = 0;

		ADC_u8State = BUSY;
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
			*Copy_pu16Reading = ADCH;
#elif	ADC_RESOLUTION == ADC_RESOLUTION_10BIT
			*Copy_pu16Reading = ADC_10_BIT;
#endif
			ADC_u8State = IDLE;
		}
	}else{
		Local_u8ErrorState = BUSY_FUNCTION;
	}//Do Nothing

	return Local_u8ErrorState;
}

uint8 ADC_u8AsynchronousConversion( uint16 *Copy_pu16Reading, void (*Copy_pvdNotificationFunc) (void), uint8 Copy_u8Channel ){
	uint8 Local_u8ErrorState = OK;
	if(ADC_u8State == IDLE){
		if((Copy_pvdNotificationFunc == NULL) || (Copy_pu16Reading == NULL)){
			Local_u8ErrorState = NULL_POINTER;
		}else{
			ADC_u8ISRType = SINGLE;
			// Set ADC Conversion State to Busy
			ADC_u8State = BUSY;

			//Initialising the call back notification function globally
			ADC_pvdCallBackNotificationFunc = Copy_pvdNotificationFunc;
			//Initialising the reading variable globally
			ADC_pu16Reading = Copy_pu16Reading;

			//Clear The MUX bits in ADMUX
			ADMUX &= ADC_MUX_MASK;
			//Set the Required channel
			ADMUX |= Copy_u8Channel;

			//Start Conversion
			SET_BIT(ADCSRA, ADCSRA_ADSC);
			//Interrupt Enable
			SET_BIT(ADCSRA, ADCSRA_ADIE);
		}
	}else{
		//Return Busy Function
		Local_u8ErrorState = BUSY_FUNCTION;
	}//Do Nothing
	return Local_u8ErrorState;

}

uint8 ADC_u8ChainConversion(ADC_Chain_t* CopyStruct){
	uint8 Local_u8ErrorState = OK;
	if(ADC_u8State == IDLE){
		if( (CopyStruct->NotificationFunction) == NULL || CopyStruct->ResultArr == NULL){
			Local_u8ErrorState = NULL_POINTER;
		}else{
			ADC_u8ISRType = CHAIN;

			// Set ADC Conversion State to Busy
			ADC_u8State = BUSY;

			ADC_pu8ChainChannels = CopyStruct->Channels;

			//Initialising the Result array globally
			ADC_pu16ChainResult = CopyStruct->ResultArr;

			//Initialising the Chain Size globally
			ADC_u8ChainSize = CopyStruct->Size;

			//Initialising the call back notification function globally
			ADC_pvdCallBackNotificationFunc = CopyStruct->NotificationFunction;

			ADC_u8ChainIndex = 0;

			//Clear The MUX bits in ADMUX
			ADMUX &= ADC_MUX_MASK;

			//Set the First channel
			ADMUX |= ADC_pu8ChainChannels[ADC_u8ChainIndex];

			//Start Conversion
			SET_BIT(ADCSRA, ADCSRA_ADSC);
			//Interrupt Enable
			SET_BIT(ADCSRA, ADCSRA_ADIE);
		}
	}else{
		//Return Busy Function
		Local_u8ErrorState = BUSY_FUNCTION;
	}//Do Nothing
	return Local_u8ErrorState;
}

void __vector_16 (void) __attribute__((signal));
void __vector_16 (void){
	if (ADC_u8ISRType == SINGLE){
		ADC_AsynchronousConversionISR();
	}else if(ADC_u8ISRType == CHAIN){
		ADC_ChainConversionISR();
	}else{
		//Do Nothing
	}
}

void ADC_AsynchronousConversionISR(){
	//Return the Value
#if		ADC_RESOLUTION == ADC_RESOLUTION_08BIT
	*ADC_pu16Reading = ADCH;
#elif	ADC_RESOLUTION == ADC_RESOLUTION_10BIT
	*ADC_pu16Reading = ADC_10_BIT;
#endif

	//Free the Conversion State
	ADC_u8State = IDLE;

	//Call the Interrupt Function
	ADC_pvdCallBackNotificationFunc();

	//ADC conversion Interrupt Disable
	CLR_BIT(ADCSRA, ADCSRA_ADIE);
}

void ADC_ChainConversionISR(){

	//Return the Value
#if		ADC_RESOLUTION == ADC_RESOLUTION_08BIT
	ADC_pu16ChainResult[ADC_u8ChainIndex] = ADCH;
#elif	ADC_RESOLUTION == ADC_RESOLUTION_10BIT
	ADC_pu16ChainResult[ADC_u8ChainIndex] = ADC_10_BIT;
#endif
	ADC_u8ChainIndex++;

	if (ADC_u8ChainIndex == ADC_u8ChainSize){
		//Free the Conversion State
		ADC_u8State = IDLE;

		// Invoke the call back notification function
		ADC_pvdCallBackNotificationFunc();

		//ADC conversion Interrupt Disable
		CLR_BIT(ADCSRA, ADCSRA_ADIE);
	}else{
		//Clear The MUX bits in ADMUX
		ADMUX &= ADC_MUX_MASK;

		//Set the New channel
		ADMUX |= ADC_pu8ChainChannels[ADC_u8ChainIndex];

		//Start Conversion
		SET_BIT(ADCSRA, ADCSRA_ADSC);
	}

}
