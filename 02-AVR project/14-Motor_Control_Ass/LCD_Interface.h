/*
 * LCD.h
 *
 *  Created on: Aug 14, 2021
 *      Author: Mosad
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


/************* Commands ***************/
#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position


/****************** Prototypes *********************/
void LCD_voidInit(void);
void LCD_voidSendCommand (u8 Cpy_command );
void LCD_voidSendChar (u8 Cpy_data);
void LCD_voidWriteString(const u8 *Cpy_str);
void LCD_voidGoTo(u8 Cpy_row , u8 Cpy_column);

/* Block number from 0 to 7 */
void LCD_voidAddNewPattern (u8 *Cpy_patternArray , u8 Cpy_blockNumber);
void LCD_voidWritePattern (u8 Cpy_blockNumber , u8 Cpy_row , u8 Cpy_column);

#endif /* LCD_INTERFACE_H_ */
