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

typedef struct{
	uint8 *Channels;
	uint8 Size;
	uint16 *ResultArr;
	void (* NotificationFunction )(void);
}ADC_Chain_t;

void ADC_vdInit();

uint8 ADC_u8SynchronousConversion( uint16 *Copy_pu16Reading, uint8 Copy_u8Channel );

//Don't forget to Enable the Global Interrupt to use this function
uint8 ADC_u8AsynchronousConversion( uint16 *Copy_pu16Reading, void (*Copy_pvdNotificationFunc) (void), uint8 Copy_u8Channel );

uint8 ADC_u8ChainConversion(ADC_Chain_t* CopyStruct);

#define MUX_SINGLE_ADC0								   0
#define MUX_SINGLE_ADC1                                1
#define MUX_SINGLE_ADC2                                2
#define MUX_SINGLE_ADC3                                3
#define MUX_SINGLE_ADC4                                4
#define MUX_SINGLE_ADC5                                5
#define MUX_SINGLE_ADC6                                6
#define MUX_SINGLE_ADC7                                7
#define MUX_POSITIVE_ADC0_NEGATIVE_ADC0_GAIN_x10       8
#define MUX_POSITIVE_ADC1_NEGATIVE_ADC0_GAIN_x10       9
#define MUX_POSITIVE_ADC0_NEGATIVE_ADC0_GAIN_x200      10
#define MUX_POSITIVE_ADC1_NEGATIVE_ADC0_GAIN_x200      11
#define MUX_POSITIVE_ADC2_NEGATIVE_ADC2_GAIN_x10       12
#define MUX_POSITIVE_ADC3_NEGATIVE_ADC2_GAIN_x10       13
#define MUX_POSITIVE_ADC2_NEGATIVE_ADC2_GAIN_x200      14
#define MUX_POSITIVE_ADC3_NEGATIVE_ADC2_GAIN_x200      15
#define MUX_POSITIVE_ADC0_NEGATIVE_ADC1_GAIN_x1        16
#define MUX_POSITIVE_ADC1_NEGATIVE_ADC1_GAIN_x1        17
#define MUX_POSITIVE_ADC2_NEGATIVE_ADC1_GAIN_x1        18
#define MUX_POSITIVE_ADC3_NEGATIVE_ADC1_GAIN_x1        19
#define MUX_POSITIVE_ADC4_NEGATIVE_ADC1_GAIN_x1        20
#define MUX_POSITIVE_ADC5_NEGATIVE_ADC1_GAIN_x1        21
#define MUX_POSITIVE_ADC6_NEGATIVE_ADC1_GAIN_x1        22
#define MUX_POSITIVE_ADC7_NEGATIVE_ADC1_GAIN_x1        23
#define MUX_POSITIVE_ADC0_NEGATIVE_ADC6_GAIN_x1        24
#define MUX_POSITIVE_ADC1_NEGATIVE_ADC6_GAIN_x1        25
#define MUX_POSITIVE_ADC2_NEGATIVE_ADC6_GAIN_x1        26
#define MUX_POSITIVE_ADC3_NEGATIVE_ADC6_GAIN_x1        27
#define MUX_POSITIVE_ADC4_NEGATIVE_ADC6_GAIN_x1        28
#define MUX_POSITIVE_ADC5_NEGATIVE_ADC6_GAIN_x1        29
#define MUX_SINGLE_V_BG                                30
#define MUX_SINGLE_GND                                 31

#endif
