/*****************************************************************/
/*****************************************************************/
/************		Author: Kerolos Hanna			**************/
/************		Kerolos.Hanna@hotmail.com		**************/
/************		Layer:	HAL						**************/
/************		SWC:	KEYPAD					**************/
/************		version: 1.00					**************/
/*****************************************************************/
/*****************************************************************/

#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H

#define KEYPAD_PORT				DIO_u8PORTC
#define KEYPAD_NO_KEY_PRESSED	0xFF

#define KEYPAD_KEY_PRESSED		0
#define KEYPAD_KEY_UNPRESSED	1

#define KEYPAD_COLUMN_NUMBER	3
#define KEYPAD_ROW_NUMBER		4

#define KEYPAD_VALUES			{{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}, {'*', '0', '#'}}

#define KEYPAD_COLUMN0_PIN		DIO_u8PIN0
#define KEYPAD_COLUMN1_PIN      DIO_u8PIN1
#define KEYPAD_COLUMN2_PIN      DIO_u8PIN2
#define KEYPAD_ROW0_PIN         DIO_u8PIN3
#define KEYPAD_ROW1_PIN         DIO_u8PIN4
#define KEYPAD_ROW2_PIN         DIO_u8PIN5
#define KEYPAD_ROW3_PIN         DIO_u8PIN6

#endif
