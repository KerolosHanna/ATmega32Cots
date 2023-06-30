	/*****************************************************************/
/*****************************************************************/
/************		Author: Kerolos Hanna			**************/
/************		Kerolos.Hanna@hotmail.com		**************/
/************		Layer:	MCAL					**************/
/************		SWC:	DIO						**************/
/************		version: 1.00					**************/
/*****************************************************************/
/*****************************************************************/

#ifndef DIO_REGISTER_H
#define DIO_REGISTER_H

/*Defining Port A Registers*/
#define PORTA	*( (volatile uint8 *) 0x3B )
#define DDRA	*( (volatile uint8 *) 0x3A )
#define PINA	*( (volatile uint8 *) 0x39 )

/*Defining Port A Registers*/
#define PORTB	*( (volatile uint8 *) 0x38 )
#define DDRB	*( (volatile uint8 *) 0x37 )
#define PINB	*( (volatile uint8 *) 0x36 )

/*Defining Port A Registers*/
#define PORTC	*( (volatile uint8 *) 0x35 )
#define DDRC	*( (volatile uint8 *) 0x34 )
#define PINC	*( (volatile uint8 *) 0x33 )

/*Defining Port A Registers*/
#define PORTD	*( (volatile uint8 *) 0x32 )
#define DDRD	*( (volatile uint8 *) 0x31 )
#define PIND	*( (volatile uint8 *) 0x30 )


#endif