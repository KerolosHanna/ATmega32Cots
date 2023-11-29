/*****************************************************************/
/************		Author: Kerolos Hanna"			**************/
/************		Kerolos.Hanna@hotmail.com		**************/
/************		Layer:	MCAL					**************/
/************		SWC:	ADC						**************/
/************		version: 1.00					**************/
/*****************************************************************/
/*****************************************************************/

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/*ADC Masks*/
#define ADC_REF_MASK								0x3F //0b00111111
#define ADC_PRESCALER_MASK							0xF8 //0b11111000
#define ADC_MUX_MASK								0xE0 //0b11100000
#define ADC_CONVERSION_MASK							0x9F //0b10011111
#define ADC_TRIGGER_MASK							0xDF //0b00011111
#define SFIOR_TRIGGER_MASK							0x1F //0b00011111
#define ADC_RESOLUTION_MASK							0xDF //0b11011111

/*ADC Reference Voltage Options*/
#define ADC_REF_AREF								0x00 //0b00000000
#define ADC_REF_AVCC								0x40 //0b01000000
#define ADC_REF_INTERNAL							0xc0 //0b11000000

/*ADC Resolution*/
#define ADC_RESOLUTION_08BIT						0xFF //0b11111111
#define ADC_RESOLUTION_10BIT                        0xDF //0b11011111

/*ADC Pre-scaler Options*/
#define ADCSRA_DIVIDED_BY_2							1
#define ADCSRA_DIVIDED_BY_4							2
#define ADCSRA_DIVIDED_BY_8							3
#define ADCSRA_DIVIDED_BY_16						4
#define ADCSRA_DIVIDED_BY_32						5
#define ADCSRA_DIVIDED_BY_64						6
#define ADCSRA_DIVIDED_BY_128						7

/*ADC Conversion Mode*/
#define ADC_CONVERSION_SINGLE						0xDF //0b11011111
#define ADC_CONVERSION_AUTO							0xFF //0b11111111

/*ADC Trigger Enable/Disable*/
#define ADC_AUTO_TRIGGER_ENABLE                     0xFF //0b11111111
#define ADC_AUTO_TRIGGER_DISABLE                    0xDF //0b11011111

/*ADC Trigger Modes*/
#define ADC_TRIGGER_FREE_RUNNING_MODE        	    0x1F //0b0011111
#define ADC_TRIGGER_ANALOG_COMPARATOR             	0x3F //0b00111111
#define ADC_TRIGGER_EXTERNAL_INTERRUPT_REQUEST_0    0x5F //0b01011111
#define ADC_TRIGGER_TIMER_COUNTER0_COMPARE_MATCH    0x7F //0b01111111
#define ADC_TRIGGER_TIMER_COUNTER0_OVERFLOW         0x9F //0b10011111
#define ADC_TRIGGER_TIMER_COUNTER1_COMPARE_MATCH_B  0xBF //0b10111111
#define ADC_TRIGGER_TIMER_COUNTER1_OVERFLOW         0xDF //0b11011111
#define ADC_TRIGGER_TIMER_COUNTER1_CAPTURE_EVENT    0xFF //0b11111111

#endif
