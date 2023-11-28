/*****************************************************************/
/************		Author: Kerolos Hanna"			**************/
/************		Kerolos.Hanna@hotmail.com		**************/
/************		Layer:	MCAL					**************/
/************		SWC:	ADC						**************/
/************		version: 1.00					**************/
/*****************************************************************/
/*****************************************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#define ADCSRA_DIVIDED_BY_2		1
#define ADCSRA_DIVIDED_BY_4		2
#define ADCSRA_DIVIDED_BY_8		3
#define ADCSRA_DIVIDED_BY_16	4
#define ADCSRA_DIVIDED_BY_32	5
#define ADCSRA_DIVIDED_BY_64	6
#define ADCSRA_DIVIDED_BY_128	7

void ADC_vdInit();

uint8 ADC_u8ChannelReading( uint8 Copy_u8Channel );




#endif
