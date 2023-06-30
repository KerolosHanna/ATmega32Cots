/*****************************************************************/
/*****************************************************************/
/************		Author: Kerolos Hanna			**************/
/************		Kerolos.Hanna@hotmail.com		**************/
/************		Layer:	MCAL					**************/
/************		SWC:	PORT					**************/
/************		version: 1.00					**************/
/*****************************************************************/
/*****************************************************************/

#ifndef PORT_PRIVATE_H
#define PORT_PRIVATE_H

#define INPUT		0
#define OUTPUT		1

#define PULLUP		0
#define PULLDOWN	1

#define LOW			0
#define HIGH		1

#define CONC(b7, b6, b5, b4, b3, b2, b1, b0)	CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELPER(b7, b6, b5, b4, b3, b2, b1, b0)	0b##b7##b6##b5##b4##b3##b2##b1##b0

#define PORTA_DIRECTION CONC(PORTA_PIN7_DIRECTION, PORTA_PIN6_DIRECTION, PORTA_PIN5_DIRECTION, PORTA_PIN4_DIRECTION, PORTA_PIN3_DIRECTION, PORTA_PIN2_DIRECTION, PORTA_PIN1_DIRECTION, PORTA_PIN0_DIRECTION);
#define PORTB_DIRECTION CONC(PORTB_PIN7_DIRECTION, PORTB_PIN6_DIRECTION, PORTB_PIN5_DIRECTION, PORTB_PIN4_DIRECTION, PORTB_PIN3_DIRECTION, PORTB_PIN2_DIRECTION, PORTB_PIN1_DIRECTION, PORTB_PIN0_DIRECTION);
#define PORTC_DIRECTION CONC(PORTC_PIN7_DIRECTION, PORTC_PIN6_DIRECTION, PORTC_PIN5_DIRECTION, PORTC_PIN4_DIRECTION, PORTC_PIN3_DIRECTION, PORTC_PIN2_DIRECTION, PORTC_PIN1_DIRECTION, PORTC_PIN0_DIRECTION);
#define PORTD_DIRECTION CONC(PORTD_PIN7_DIRECTION, PORTD_PIN6_DIRECTION, PORTD_PIN5_DIRECTION, PORTD_PIN4_DIRECTION, PORTD_PIN3_DIRECTION, PORTD_PIN2_DIRECTION, PORTD_PIN1_DIRECTION, PORTD_PIN0_DIRECTION);

#define PORTA_VALUE CONC(PORTA_PIN7_VALUE, PORTA_PIN6_VALUE, PORTA_PIN5_VALUE, PORTA_PIN4_VALUE, PORTA_PIN3_VALUE, PORTA_PIN2_VALUE, PORTA_PIN1_VALUE, PORTA_PIN0_VALUE);
#define PORTB_VALUE CONC(PORTB_PIN7_VALUE, PORTB_PIN6_VALUE, PORTB_PIN5_VALUE, PORTB_PIN4_VALUE, PORTB_PIN3_VALUE, PORTB_PIN2_VALUE, PORTB_PIN1_VALUE, PORTB_PIN0_VALUE);
#define PORTC_VALUE CONC(PORTC_PIN7_VALUE, PORTC_PIN6_VALUE, PORTC_PIN5_VALUE, PORTC_PIN4_VALUE, PORTC_PIN3_VALUE, PORTC_PIN2_VALUE, PORTC_PIN1_VALUE, PORTC_PIN0_VALUE);
#define PORTD_VALUE CONC(PORTD_PIN7_VALUE, PORTD_PIN6_VALUE, PORTD_PIN5_VALUE, PORTD_PIN4_VALUE, PORTD_PIN3_VALUE, PORTD_PIN2_VALUE, PORTD_PIN1_VALUE, PORTD_PIN0_VALUE);

#endif