 /******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: LCD.h
 *
 * Description: types for AVR
 *
 * Date Created: 2/10/2022
 *
 * Author: Moustafa Ahmed
 *
 *******************************************************************************/


#ifndef HAL_HEADER_LCD_H_
#define HAL_HEADER_LCD_H_

/**-------------------------INCLUDES Section------------------------**/
#include "../../Libraries/std_types.h"
/**-------------------------Definitions & Config Section------------**/

/* Command to LCD instruction Register */
#define LCD_CLR_DISPLAY 						0x01
#define LCD_GO_TO_HOME                 			0x02
#define SHIFT_CURSOR_TO_LEFT 					0x04
#define SHIFT_CURSOR_TO_RIGHT 					0x06
#define SHIFT_DISPLAY_LEFT 						0x07
#define SHIFT_DISPLAY_RIGHT 					0x05
#define DISPLAY_OFF_CURSOR_ON 					0x0A
#define DISPLAY_ON_CURSOR_ON 					0x0E
#define DISPLAY_ON_CURSOR_OFF 					0x0C
#define DISPLAY_ON_CURSOR_BLINKING 				0x0F
#define LCD_TWO_LINES_EIGHT_BITS_MODE  			0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE   			0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   	0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   	0x32
#define START_AT_FIRST_LINE 					0x80
#define START_AT_SECOND_LINE 					0xC0

/* Modifiable */
#define LCD_DATA_MODE 					4

#if((LCD_DATA_MODE != 4) && (LCD_DATA_MODE != 8))

#error "Number of Data bits should be equal to 4 or 8"

#endif

#define LCD_OUTPUT_PORT 				PORTA_ID

#define LCD_RS_PORT						PORTA_ID
#define LCD_RS_PIN 						PIN0_ID

#define LCD_RW_PORT
#define LCD_RW_PIN

#define LCD_EN_PORT						PORTA_ID
#define LCD_EN_PIN						PIN1_ID

#if (LCD_DATA_MODE == 4)

#define LCD_D4_PIN						PIN4_ID
#define LCD_D5_PIN						PIN5_ID
#define LCD_D6_PIN						PIN6_ID
#define LCD_D7_PIN						PIN7_ID

#endif
/**-------------------------Function Dec. Section-------------------**/

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_init(void);

/*----------------------------------------------------------------------------*/

/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(uint8 command);

/*----------------------------------------------------------------------------*/

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_displayCharacter(uint8 data);

/*----------------------------------------------------------------------------*/

/*
 * Description :
 * Display the required string on the screen
 */
void LCD_displayString(const char *Str);

/*----------------------------------------------------------------------------*/

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_moveCursor(uint8 row,uint8 col);

/*----------------------------------------------------------------------------*/

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);

/*----------------------------------------------------------------------------*/

/*
 * Description :
 * Display the required Char in a specified row and column index on the screen
 */
void LCD_displayCharRowColumn(uint8 row,uint8 col,uint8 data);
/*----------------------------------------------------------------------------*/

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_intgerToString(int data);

/*----------------------------------------------------------------------------*/

/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(void);

/**---------------------------------END-----------------------------**/

#endif /* HAL_HEADER_LCD_H_ */
