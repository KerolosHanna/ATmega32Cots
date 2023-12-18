/*****************************************************************/
/************		Author: Kerolos Hanna"			**************/
/************		Kerolos.Hanna@hotmail.com		**************/
/************		Layer:	MCAL					**************/
/************		SWC:	ADC						**************/
/************		version: 1.00					**************/
/*****************************************************************/
/*****************************************************************/

#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

#define ADC_u32TIMEOUT			50000

#define ADC_REF					ADC_REF_AREF
/*	Use one of these
 *  ADC_REF_AREF
 *  ADC_REF_AVCC
 *  ADC_REF_INTERNAL
 * */

#define ADC_RESOLUTION			ADC_RESOLUTION_08BIT
/*
 * ADC_RESOLUTION_08BIT
 * ADC_RESOLUTION_10BIT
 * */

#define ADC_PRESCALER			ADCSRA_DIVIDED_BY_128
/*	Use one of these
 *	ADCSRA_DIVIDED_BY_2
 *	ADCSRA_DIVIDED_BY_4
 *	ADCSRA_DIVIDED_BY_8
 * 	ADCSRA_DIVIDED_BY_16
 *	ADCSRA_DIVIDED_BY_32
 * 	ADCSRA_DIVIDED_BY_64
 * 	ADCSRA_DIVIDED_BY_128
 * */

#define ADC_CONVERSION_MODE			ADC_CONVERSION_SINGLE
/*	Use one of these
 * 	ADC_CONVERSION_SINGLE
 * 	ADC_CONVERSION_AUTO
 * */

#define ADC_TRIGGER					ADC_AUTO_TRIGGER_DISABLE
/*
 * ADC_AUTO_TRIGGER_ENABLE
 * ADC_AUTO_TRIGGER_DISABLE
 * */

#define ADC_TRIGGER_MODE           	ADC_TRIGGER_FREE_RUNNING_MODE
/*
 * ADC_TRIGGER_FREE_RUNNING_MODE
 * ADC_TRIGGER_ANALOG_COMPARATOR
 * ADC_TRIGGER_EXTERNAL_INTERRUPT_REQUEST_0
 * ADC_TRIGGER_TIMER_COUNTER0_COMPARE_MATCH
 * ADC_TRIGGER_TIMER_COUNTER0_OVERFLOW
 * ADC_TRIGGER_TIMER_COUNTER1_COMPARE_MATCH_B
 * ADC_TRIGGER_TIMER_COUNTER1_OVERFLOW
 * ADC_TRIGGER_TIMER_COUNTER1_CAPTURE_EVENT
 */
#endif
