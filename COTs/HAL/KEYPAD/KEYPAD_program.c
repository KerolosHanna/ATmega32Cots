/*****************************************************************/
/*****************************************************************/
/************		Author: Kerolos Hanna			**************/
/************		Kerolos.Hanna@hotmail.com		**************/
/************		Layer:	HAL						**************/
/************		SWC:	KEYPAD					**************/
/************		version: 1.00					**************/
/*****************************************************************/
/*****************************************************************/

#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"
#include "..\..\MCAL\DIO\DIO_Interface.h"
#include "..\..\MCAL\PORT\PORT_Interface.h"
#include "KEYPAD_config.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_private.h"
#include <util/delay.h>

uint8 KEYPAD_u8GetKey(){
	uint8 Local_u8PressedKey = KEYPAD_NO_KEY_PRESSED, Local_u8PinState = KEYPAD_KEY_UNPRESSED;
	uint8 Local_u8ColumnIndex = 0, Local_u8RowIndex = 0;
	static uint8 Local_u8KeyArray[KEYPAD_ROW_NUMBER][KEYPAD_COLUMN_NUMBER] = KEYPAD_VALUES;
	static uint8 Local_u8ColumnArray[KEYPAD_COLUMN_NUMBER]={KEYPAD_COLUMN0_PIN, KEYPAD_COLUMN1_PIN, KEYPAD_COLUMN2_PIN};
	static uint8 Local_u8RowArray[KEYPAD_ROW_NUMBER]={KEYPAD_ROW0_PIN, KEYPAD_ROW1_PIN, KEYPAD_ROW2_PIN, KEYPAD_ROW3_PIN};

	for(Local_u8ColumnIndex = 0 ; Local_u8ColumnIndex < KEYPAD_COLUMN_NUMBER ; Local_u8ColumnIndex++){

		/*Activate the current column*/
		DIO_u8SetPinValue(KEYPAD_COLUMN_PORT, Local_u8ColumnArray[Local_u8ColumnIndex], DIO_u8PIN_LOW);

		for(Local_u8RowIndex = 0 ; Local_u8RowIndex < KEYPAD_ROW_NUMBER ; Local_u8RowIndex ++){
			DIO_u8GetPinValue(KEYPAD_ROW_PORT, Local_u8RowArray[Local_u8RowIndex], &Local_u8PinState);

			if(Local_u8PinState == KEYPAD_KEY_PRESSED){
				Local_u8PressedKey = Local_u8KeyArray[Local_u8RowIndex][Local_u8ColumnIndex];
				while(Local_u8PinState == KEYPAD_KEY_PRESSED){
					DIO_u8GetPinValue(KEYPAD_ROW_PORT, Local_u8RowArray[Local_u8RowIndex], &Local_u8PinState);
				}
			}
		}
		/*Deactivate the current column*/
		DIO_u8SetPinValue(KEYPAD_COLUMN_PORT, Local_u8ColumnArray[Local_u8ColumnIndex], DIO_u8PIN_HIGH);
	}
	return Local_u8PressedKey;
}
