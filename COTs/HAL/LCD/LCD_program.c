/*****************************************************************/
/*****************************************************************/
/************		Author: Kerolos Hanna			**************/
/************		Kerolos.Hanna@hotmail.com		**************/
/************		Layer:	HAL					**************/
/************		SWC:	LCD						**************/
/************		version: 1.00					**************/
/*****************************************************************/
/*****************************************************************/

#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"
#include "..\..\MCAL\DIO\DIO_interface.h"

#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include <util/delay.h>

void LCD_vdInit(){
#if LCD_CONNECTION_TYPE == LCD_8BIT
	DIO_u8SetPortDirection(LCD_DATA_PORT, DIO_u8PORT_OUTPUT);
	_delay_ms(40);
	LCD_u8SendCommand( LCD_8BIT_2LINES );
#endif

#if LCD_CONNECTION_TYPE == LCD_4BIT
	_delay_ms(40);
	LCD_u8SendCommand( LCD_4BIT_MODE );
	LCD_u8SendCommand( LCD_4BIT_2LINES );
#endif

	LCD_u8SendCommand( LCD_DISP_ON_CURSOR_OFF );
	LCD_u8SendCommand( LCD_ENTRY_INC );
	LCD_u8SendCommand( LCD_CLEAR_SCREEN );
	LCD_u8SendCommand( LCD_BEGIN_AT_FIRST_ROW );
	_delay_ms(10);
}

uint8 LCD_u8SendCommand(uint8 Copy_u8Command){
	uint8 Local_u8ErrorState = 0;

	/*RS -> LOW for Command*/
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_u8PIN_LOW);
	/*RW -> LOW for Write*/
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_u8PIN_LOW);

	/*LCD Connected to 8 Bit mode*/
#if LCD_CONNECTION_TYPE == LCD_8BIT
	/*Sending the Command Value*/
	DIO_u8SetPortValue(LCD_DATA_PORT, Copy_u8Command);

	/*Pulse the Enable */
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_u8PIN_HIGH);
	_delay_ms(LCD_EN_PULS);
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_u8PIN_LOW);
	return Local_u8ErrorState ;
#endif

	/*LCD Connected to 4 Bit mode*/
#if LCD_CONNECTION_TYPE == LCD_4BIT
	/*Sending the Most Significant Bits of the Command Value*/
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(Copy_u8Command, 4));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(Copy_u8Command, 5));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(Copy_u8Command, 6));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(Copy_u8Command, 7));

	/*Pulse the Enable */
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_u8PIN_HIGH);
	_delay_ms(LCD_EN_PULS);
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_u8PIN_LOW);

	/*Sending the Most Least Bits of the Command Value*/
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(Copy_u8Command, 0));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(Copy_u8Command, 1));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(Copy_u8Command, 2));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(Copy_u8Command, 3));

	/*Pulse the Enable */
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_u8PIN_HIGH);
	_delay_ms(LCD_EN_PULS);
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_u8PIN_LOW);

#endif
	return Local_u8ErrorState ;
}
uint8 LCD_u8SendData(uint8 Copy_u8Data){
	uint8 Local_u8ErrorState = 0;

	/*RS -> HIGH for data*/
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_u8PIN_HIGH);
	/*RW -> LOW for Write*/
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_u8PIN_LOW);

	/*LCD Connected to 8 Bit mode*/
#if LCD_CONNECTION_TYPE == LCD_8BIT
	DIO_u8SetPortValue(LCD_DATA_PORT, Copy_u8Data);
	/*Pulse the Enable */
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_u8PIN_HIGH);
	_delay_ms(LCD_EN_PULS);
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_u8PIN_LOW);
	return Local_u8ErrorState ;

#endif

	/*LCD Connected to 4 Bit mode*/
#if LCD_CONNECTION_TYPE == LCD_4BIT
	/*Sending the Most Bits of the Data Value*/
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(Copy_u8Data, 4));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(Copy_u8Data, 5));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(Copy_u8Data, 6));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(Copy_u8Data, 7));

	/*Pulse the Enable */
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_u8PIN_HIGH);
	_delay_ms(LCD_EN_PULS);
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_u8PIN_LOW);

	/*Sending the Most Least Bits of the Data Value*/
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(Copy_u8Data, 0));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(Copy_u8Data, 1));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(Copy_u8Data, 2));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(Copy_u8Data, 3));

	/*Pulse the Enable */
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_u8PIN_HIGH);
	_delay_ms(LCD_EN_PULS);
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_u8PIN_LOW);

#endif
	return Local_u8ErrorState ;
}


uint8 LCD_u8SendString(const uint8* copy_u8String){
	uint8 Local_u8ErrorState = 0;
	/*Setting the Loop COunter*/
	uint8 LoopCounter = 0;


	while( copy_u8String[LoopCounter] != '\0')
	{
		/*checking if the line ends*/
		if( LoopCounter == 16 )
		{
			/*If the line ends move to the second line*/
			LCD_u8SendCommand(LCD_BEGIN_AT_SECOND_ROW);
		}
		/*Sending character by character*/
		LCD_u8SendData(copy_u8String[LoopCounter]);
		LoopCounter++;
	}
	return Local_u8ErrorState ;
}

uint8 LCD_u8GoToXnY(uint8 Copy_u8X, uint8 Copy_u8Y){
	uint8 Local_u8ErrorState = 0;
	uint8 CursorAddress = 0;
	/*Calculating the address value*/
	/*the first line starts at 0x00*/
	if		(Copy_u8Y == 0){CursorAddress = LCD_BEGIN_AT_FIRST_ROW + Copy_u8X;}
	/*the second line starts at 0x40*/
	else if	(Copy_u8Y == 1){CursorAddress = LCD_BEGIN_AT_SECOND_ROW + Copy_u8X;}
	else{Local_u8ErrorState = 1;}

	/*Send the location after calculating the value*/
	LCD_u8SendCommand(CursorAddress);

	return Local_u8ErrorState ;
}

uint8 LCD_u8CreateShape(uint8* Copy_u8ShapeArray, uint8 Copy_u8ShapeNumber){
	uint8 Local_u8ErrorState = 0;

	/*checking the memory location*/
	if(Copy_u8ShapeNumber <= 7){
		/*accessing the CGRAM address*/
		LCD_u8SendCommand((Copy_u8ShapeNumber * LCD_CHAR_SIZE) + LCD_CGRAM_BASE_ADDRESS);
		for(uint8 LoopCounter = 0; LoopCounter <= 7 ; LoopCounter++){
			/*sending row by row of the cell*/
			LCD_u8SendData(Copy_u8ShapeArray[LoopCounter]);
		}
	}else{
		Local_u8ErrorState = 1;
	}
	LCD_u8SendCommand(LCD_BEGIN_AT_FIRST_ROW);
	return Local_u8ErrorState;
}

uint8 LCD_u8SendNumber(const uint32 Copy_u32Number){
	uint8 Local_u8ErrorState = 0;

	uint32 NamerSelected= (uint32)Copy_u32Number;
	uint8 SizeOfArray, Printing;

	if (NamerSelected == 0) {
		SizeOfArray = 1;
	} else {
		while (NamerSelected != 0) {
			NamerSelected /= 10;
			SizeOfArray++;
		}
	}
	NamerSelected=(uint32)Copy_u32Number;
	uint8 NumbersArray[SizeOfArray];
	for (uint8 LoopCounter = 0; LoopCounter < SizeOfArray; LoopCounter++) {
		Printing = NamerSelected % 10;
		NumbersArray[SizeOfArray - 1 - LoopCounter] = Printing;
		NamerSelected /= 10;
	}

	for (uint8 LoopCounter = 0; LoopCounter < SizeOfArray; LoopCounter++) {
		Printing = (NumbersArray[LoopCounter] + '0');
		LCD_u8SendData(Printing);
	}
	return Local_u8ErrorState;
}

