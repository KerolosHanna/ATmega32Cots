/*****************************************************************/
/************		Author: Kerolos Hanna"			**************/
/************		Kerolos.Hanna@hotmail.com		**************/
/************		Layer:	MCAL					**************/
/************		SWC:	ADC						**************/
/************		version: 1.00					**************/
/*****************************************************************/
/*****************************************************************/

#ifndef ADC_REGISTER_H
#define ADC_REGISTER_H

#define ADMUX			*( (volatile uint8 *) 0x27 )  // ADC multiplexer selection register
#define ADMUX_REFS1		7                             // Reference selection bit l
#define ADMUX_REFS0		6                             // Reference selection bit O
#define ADMUX_ADLAR		5                             // ADC left adjust result

/*****************************************************************/

#define ADCSRA 			*( (volatile uint8 *) 0x26 )  // ADC control and status register A
#define ADCSRA_ADEN		7                             // ADC enable
#define ADCSRA_ADSC     6                             // Start conversion
#define ADCSRA_ADATE    5                             // Auto trigger enable
#define ADCSRA_ADIF     4                             // Interrupt flag
#define ADCSRA_ADIE     3                             // Interrupt enable
#define ADCSRA_ADPS2    2                             // Pre-scaler bit 2
#define ADCSRA_ADPS1    1                             // Pre-scaler bit l
#define ADCSRA_ADPS0    0                             // Pre-scaler bit 0

/*****************************************************************/

#define ADCH    		*( (volatile uint8 *) 0x25 )   // ADC high register
#define ADCL    		*( (volatile uint8 *) 0x24 )   // ADC Low register

/*****************************************************************/
#endif
