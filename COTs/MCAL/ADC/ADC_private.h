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

#define ADC_REF_AREF			0x00 //0b00000000
#define ADC_REF_AVCC			0x40 //0b01000000
#define ADC_REF_INTERNAL		0xc0 //0b11000000

#define ADC_REF_MASK			0x3F //0b00111111
#define ADC_PRESCALER_MASK		0xF8 //0b11111000
#define ADC_MUX_MASK			0xE0 //0b11100000

#endif
