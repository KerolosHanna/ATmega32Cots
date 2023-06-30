/*****************************************************************/
/*****************************************************************/
/************		Author: Kerolos Hanna			**************/
/************		Kerolos.Hanna@hotmail.com		**************/
/************		Layer:	HAL					**************/
/************		SWC:	LCD						**************/
/************		version: 1.00					**************/
/*****************************************************************/
/*****************************************************************/

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

void LCD_vdInit();

uint8 LCD_u8SendCommand(uint8 Copy_u8Command);
uint8 LCD_u8SendData(uint8 Copy_u8Data);
uint8 lCD_u8SendString(const uint8* copy_u8String);
uint8 LCD_u8GoToXnY(uint8 Copy_u8X, uint8 Copy_u8Y);

uint8 LCD_u8CreateShape(uint8* Copy_u8ShapeArray, uint8 Copy_u8ShapeNumber);

uint8 LCD_u8SendNumber(uint32 Copy_u32Number);


//Defining LCD Commands
#define LCD_8BIT_2LINES   							(0x38)
#define LCD_4BIT_MODE   							(0x02)
#define LCD_4BIT_2LINES   							(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON_CURSOR_OFF						(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)

#define LCD_CHAR_SIZE								(0x08)
#define LCD_CGRAM_BASE_ADDRESS						(0x40)

#endif
