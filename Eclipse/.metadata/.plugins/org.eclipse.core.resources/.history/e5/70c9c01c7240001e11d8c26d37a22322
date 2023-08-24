/******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: LCD.c
 *
 * Description: types for AVR
 *
 * Date Created: 2/10/2022
 *
 * Author: Moustafa Ahmed
 *
 *******************************************************************************/

/**-------------------------INCLUDES Section------------------------**/
#include <stdlib.h>
#include "Libraries.h"
#include "GPIO.h"
#include "LCD.h"


/**-------------------------Function Definition Section-------------**/

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_init(void)
{
	/* Configure the direction for RS and E pins as output pins */
	GPIO_setupPinDirection(LCD_RS_PORT, LCD_RS_PIN , PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_EN_PORT, LCD_EN_PIN , PIN_OUTPUT);

	_delay_ms(20);		/* LCD Power ON delay always > 15ms */

	/* Configure the data port as output port */
#if(LCD_DATA_MODE == 8) /* Using 8 bit mode */
	{
		GPIO_setupPortDirection(LCD_OUTPUT_PORT, PORT_OUTPUT);
		LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);
	}
#elif(LCD_DATA_MODE == 4) /* Using 4 bit mode */
	{

		GPIO_setupPinDirection(LCD_OUT_PORT, LCD_D4_PIN , PIN_OUTPUT);
		GPIO_setupPinDirection(LCD_OUT_PORT, LCD_D5_PIN , PIN_OUTPUT);
		GPIO_setupPinDirection(LCD_OUT_PORT, LCD_D6_PIN , PIN_OUTPUT);
		GPIO_setupPinDirection(LCD_OUT_PORT, LCD_D7_PIN , PIN_OUTPUT);
		LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);
	}

#endif

	LCD_sendCommand(DISPLAY_ON_CURSOR_OFF ); /* cursor off */
	LCD_sendCommand(LCD_CLR_DISPLAY); 		 /* clear LCD at the beginning */
}

/*----------------------------------------------------------------------------*/

/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(uint8 command)
{
	GPIO_writePin(LCD_RS_PORT, LCD_RS_PIN, LOGIC_LOW); 	/* Setting to Command Register selection */
	_delay_ms(1);
	GPIO_writePin(LCD_EN_PORT, LCD_EN_PIN, LOGIC_HIGH); /* Enable LCD */
	_delay_ms(1);

#if(LCD_DATA_MODE == 8)
	{
		GPIO_writePort(LCD_OUTPUT_PORT, command); 			/* Sending the command through the 8 pins*/
	}
#else
	{
		/* Sending the LAST four BITS */
		GPIO_writePin(LCD_OUTPUT_PORT, LCD_D4_PIN , GET_BIT(command,4));
		GPIO_writePin(LCD_OUTPUT_PORT, LCD_D5_PIN , GET_BIT(command,5));
		GPIO_writePin(LCD_OUTPUT_PORT, LCD_D6_PIN , GET_BIT(command,6));
		GPIO_writePin(LCD_OUTPUT_PORT, LCD_D7_PIN , GET_BIT(command,7));

		_delay_ms(1);
		GPIO_writePin(LCD_EN_PORT, LCD_EN_PIN, LOGIC_LOW); /* De-activating the LCD */
		_delay_ms(1);
		GPIO_writePin(LCD_EN_PORT, LCD_EN_PIN, LOGIC_HIGH); /* Enable LCD */
		_delay_ms(1);

		/* Sending the FIRST four BITS */
		GPIO_writePin(LCD_OUTPUT_PORT, LCD_D4_PIN , GET_BIT(command,0));
		GPIO_writePin(LCD_OUTPUT_PORT, LCD_D5_PIN , GET_BIT(command,1));
		GPIO_writePin(LCD_OUTPUT_PORT, LCD_D6_PIN , GET_BIT(command,2));
		GPIO_writePin(LCD_OUTPUT_PORT, LCD_D7_PIN , GET_BIT(command,3));
	}
#endif

	/* Shared Part must be added at the END */
	_delay_ms(1);
	GPIO_writePin(LCD_EN_PORT, LCD_EN_PIN, LOGIC_LOW); /* De-activating the LCD */
	_delay_ms(1);
}

/*----------------------------------------------------------------------------*/

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_displayCharacter(uint8 data)
{
	GPIO_writePin(LCD_RS_PORT, LCD_RS_PIN, LOGIC_HIGH); /* Activating the Data Register */
	_delay_ms(1);
	GPIO_writePin(LCD_EN_PORT, LCD_EN_PIN, LOGIC_HIGH); /* Activating the LCD */
	_delay_ms(1);


#if(LCD_DATA_MODE == 8)
	{
		GPIO_writePort(LCD_OUTPUT_PORT, data); /* Sending the Data */
		_delay_ms(1);
	}
#else
	{
		/* Sending the LAST four BITS */
		GPIO_writePin(LCD_OUTPUT_PORT, LCD_D4_PIN , GET_BIT(data,4));
		GPIO_writePin(LCD_OUTPUT_PORT, LCD_D5_PIN , GET_BIT(data,5));
		GPIO_writePin(LCD_OUTPUT_PORT, LCD_D6_PIN , GET_BIT(data,6));
		GPIO_writePin(LCD_OUTPUT_PORT, LCD_D7_PIN , GET_BIT(data,7));

		_delay_ms(1);
		GPIO_writePin(LCD_EN_PORT, LCD_EN_PIN, LOGIC_LOW); /* De-activating the LCD */
		_delay_ms(1);
		GPIO_writePin(LCD_EN_PORT, LCD_EN_PIN, LOGIC_HIGH); /* Enable LCD */
		_delay_ms(1);

		/* Sending the FIRST four BITS */
		GPIO_writePin(LCD_OUTPUT_PORT, LCD_D4_PIN , GET_BIT(data,0));
		GPIO_writePin(LCD_OUTPUT_PORT, LCD_D5_PIN , GET_BIT(data,1));
		GPIO_writePin(LCD_OUTPUT_PORT, LCD_D6_PIN , GET_BIT(data,2));
		GPIO_writePin(LCD_OUTPUT_PORT, LCD_D7_PIN , GET_BIT(data,3));
		_delay_ms(1);
	}
#endif

	GPIO_writePin(LCD_EN_PORT, LCD_EN_PIN, LOGIC_LOW); /* Activating the LCD */
	_delay_ms(1);
}

/*----------------------------------------------------------------------------*/

/*
 * Description :
 * Display the required string on the screen
 */
void LCD_displayString(const char *Str)
{
	uint8 a_stringCounter = 0; /* Counting the array of chars */

	while(Str[a_stringCounter] != '\0')
	{
		LCD_displayCharacter(Str[a_stringCounter]);
		a_stringCounter++;
	}
}

/*----------------------------------------------------------------------------*/

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_moveCursor(uint8 row,uint8 col)
{
	uint8 a_lcd_memory_address;

	/* Calculate the required address in the LCD DDRAM */
	switch(row)
	{
	case 0:
		a_lcd_memory_address=col;
		break;
	case 1:
		a_lcd_memory_address=col+0x40;
		break;
	case 2:
		a_lcd_memory_address=col+0x10;
		break;
	case 3:
		a_lcd_memory_address=col+0x50;
		break;
	}
	/* Move the LCD cursor to this specific address */
	LCD_sendCommand(a_lcd_memory_address | START_AT_FIRST_LINE);
}

/*----------------------------------------------------------------------------*/

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_moveCursor(row,col); /* go to to the required LCD position */
	LCD_displayString(Str); /* display the string */
}

/*----------------------------------------------------------------------------*/

/*
 * Description :
 * Display the required Char in a specified row and column index on the screen
 */
void LCD_displayCharRowColumn(uint8 row,uint8 col,uint8 data)
{
	LCD_moveCursor(row,col); /* go to to the required LCD position */
	LCD_displayCharacter(data); /* display the string */
}

/*----------------------------------------------------------------------------*/

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_intgerToString(int data)
{
	char buff[16]; 				/* String to hold the ascii result */
	itoa(data,buff,10); 		/* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
	LCD_displayString(buff); 	/* Display the string */
}

/*----------------------------------------------------------------------------*/

/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLR_DISPLAY);
}

/**---------------------------------END-----------------------------**/


