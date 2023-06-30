/*****************************************************************/
/*****************************************************************/
/************		Author: Kerolos Hanna			**************/
/************		Kerolos.Hanna@hotmail.com		**************/
/************		Layer:	MCAL					**************/
/************		SWC:	PORT					**************/
/************		version: 1.00					**************/
/*****************************************************************/
/*****************************************************************/

#include "..\..\LIB\STD_TYPES.h"

#include "PORT_config.h"
#include "PORT_private.h"
#include "PORT_interface.h"
#include "PORT_register.h"

void PORT_vdInit(){
	DDRA	=	PORTA_DIRECTION;
	DDRB	=	PORTB_DIRECTION;
	DDRC	=	PORTC_DIRECTION;
	DDRD	=	PORTD_DIRECTION;

	PORTA	=	PORTA_VALUE;
	PORTB	=	PORTB_VALUE;
	PORTC	=	PORTC_VALUE;
	PORTD	=	PORTD_VALUE;
}
