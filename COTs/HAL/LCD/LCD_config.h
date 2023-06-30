/*****************************************************************/
/*****************************************************************/
/************		Author: Kerolos Hanna			**************/
/************		Kerolos.Hanna@hotmail.com		**************/
/************		Layer:	HAL					**************/
/************		SWC:	LCD						**************/
/************		version: 1.00					**************/
/*****************************************************************/
/*****************************************************************/




#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/*Types of Connection*/
#define	LCD_4BIT		4
#define	LCD_8BIT		8

/*Selected type of connection*/
#define LCD_CONNECTION_TYPE		LCD_4BIT

/*configuring controlling pins*/
#define LCD_CTRL_PORT	DIO_u8PORTB
#define LCD_RS_PIN		DIO_u8PIN1
#define LCD_RW_PIN		DIO_u8PIN2
#define LCD_EN_PIN		DIO_u8PIN3

/*LCD Connected to 8 Bit mode*/
#if LCD_CONNECTION_TYPE == LCD_8BIT

#define LCD_DATA_PORT	DIO_u8PORTA

#endif

/*LCD Connected to 4 Bit mode*/
#if LCD_CONNECTION_TYPE == LCD_4BIT

#define LCD_DATA_PORT	DIO_u8PORTA
#define LCD_D4_PIN		DIO_u8PIN4
#define LCD_D5_PIN		DIO_u8PIN5
#define LCD_D6_PIN		DIO_u8PIN6
#define LCD_D7_PIN		DIO_u8PIN7

#endif

#define LCD_EN_PULS		2

#endif
