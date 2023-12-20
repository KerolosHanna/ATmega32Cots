/*****************************************************************/
/************		Author: Kerolos Hanna"			**************/
/************		Kerolos.Hanna@hotmail.com		**************/
/************		Layer:	MCAL					**************/
/************		SWC:	TIMERS					**************/
/************		version: 1.00					**************/
/*****************************************************************/
/*****************************************************************/

#ifndef TIMERS_REGISTER_HT
#define TIMERS_REGISTER_H

#define TCCR0			*( (volatile uint8 *) 0x53 )	//Timer 0  Control Register
#define TCCR1A			*( (volatile uint8 *) 0x4F )	//Timer 1A Control Register
#define TCCR1B			*( (volatile uint8 *) 0x4E )	//Timer 1B Control Register
#define TCCR2			*( (volatile uint8 *) 0x45 )	//Timer 2  Control Register

#define ICR1        	*( (volatile uint16 *) 0x46 )	//Timer 1 Input Capture Register

#define OCR0			*( (volatile uint8 *) 0x5c )	//Output compare register 0
#define OCR1A			*( (volatile uint16 *) 0x4A )	//Output compare register 1A
#define OCR1B			*( (volatile uint16 *) 0x48 )	//Output compare register 1B
#define OCR2			*( (volatile uint8 *) 0x43 )	//Output compare register 2

#define TIMSK			*( (volatile uint8 *) 0x59 )	//Timer Mask

#define TIMSK_OCIE0		1								//Output Compare 0 Interrupt Enable
#define TIMSK_TOIE0		0								//Output Over Flow 0 Interrupt Enable

#define TIMSK_OCIE2		7								//Output Compare 2 Interrupt Enable
#define TIMSK_TOIE2		6								//Output Over Flow 0 Interrupt Enable

#define TCCR_WGM0		6								//Waveform Generation Mode bit 0
#define TCCR_WGM1		3                               //Waveform Generation Mode bit 1
#define TCCR1A_WGM10	0                               //Timer 1A Waveform Generation Mode bit 1
#define TCCR1A_WGM11	1                               //Timer 1A Waveform Generation Mode bit 1
#define TCCR1B_WGM12	3                               //Timer 1B Waveform Generation Mode bit 1
#define TCCR1B_WGM13	4                               //Timer 1B Waveform Generation Mode bit 1

#define TCCR_CS2		2                               //Pre-Scaler timer 0 and 2 bit 2
#define TCCR_CS1		1                               //Pre-Scaler timer 0 and 2 bit 1
#define TCCR_CS0		0                               //Pre-Scaler timer 0 and 2 bit 0

#define TCNT0			*( (volatile uint8 *) 0x52 )
#define TCNT1			*( (volatile uint16 *) 0x4c )
#define TCNT2			*( (volatile uint8 *) 0X44 )


#endif
