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

#define IDLE										1
#define BUSY										2

#define SINGLE										1
#define CHAIN										2

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
#define ADC_RESOLUTION_08BIT						0x20 //0b00100000
#define ADC_RESOLUTION_10BIT                        0x00 //0b00000000

/*ADC Pre-scaler Options*/
#define ADCSRA_DIVIDED_BY_2							1
#define ADCSRA_DIVIDED_BY_4							2
#define ADCSRA_DIVIDED_BY_8							3
#define ADCSRA_DIVIDED_BY_16						4
#define ADCSRA_DIVIDED_BY_32						5
#define ADCSRA_DIVIDED_BY_64						6
#define ADCSRA_DIVIDED_BY_128						7

/*ADC Conversion Mode*/
#define ADC_CONVERSION_SINGLE						0x40 //0b01000000
#define ADC_CONVERSION_AUTO							0x60 //0b01100000

/*ADC Trigger Enable/Disable*/
#define ADC_AUTO_TRIGGER_ENABLE                     0x20 //0b00100000
#define ADC_AUTO_TRIGGER_DISABLE                    0x00 //0b00000000

/*ADC Trigger Modes*/
#define ADC_TRIGGER_FREE_RUNNING_MODE        	    0x00 //0b00000000
#define ADC_TRIGGER_ANALOG_COMPARATOR             	0x20 //0b00100000
#define ADC_TRIGGER_EXTERNAL_INTERRUPT_REQUEST_0    0x40 //0b01000000
#define ADC_TRIGGER_TIMER_COUNTER0_COMPARE_MATCH    0x60 //0b01100000
#define ADC_TRIGGER_TIMER_COUNTER0_OVERFLOW         0x80 //0b10000000
#define ADC_TRIGGER_TIMER_COUNTER1_COMPARE_MATCH_B  0xA0 //0b10100000
#define ADC_TRIGGER_TIMER_COUNTER1_OVERFLOW         0xC0 //0b11000000
#define ADC_TRIGGER_TIMER_COUNTER1_CAPTURE_EVENT    0xE0 //0b11100000

void ADC_AsynchronousConversionISR();
void ADC_ChainConversionISR();
#endif
