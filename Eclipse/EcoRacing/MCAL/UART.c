/******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: uart.c
 *
 * Description: types for AVR
 *
 * Date Created: 13/10/2022
 *
 * Author: Moustafa Ahmed
 *
 *******************************************************************************/

/**-------------------------INCLUDES Section------------------------**/
#include "Header/UART.h"

#include "../Libraries/Libraries.h"
#include "Header/GPIO.h"

/**-------------------------Function Definition Section-------------**/


/*
 * Description:
 *
 */
void UART_init(UART_ConfigType *Config_Ptr)
{
	/**-------------------------Local Variables---------------------**/
	/* UBRR_VALUE will be used to set the baud rate later */
	uint16 a_ubrr_value = 0;
	/**-------------------------END Local Variables-----------------**/

	/* Setting the transmission speed */
	UCSRA = (UCSRA & 0xFD) | ((Config_Ptr->transmitSpeed)<<U2X);
	/*-------------------------------------------------------------------*/

	/* Setting the INTERRUPT for RX */
	UCSRB = (UCSRB & 0x7F) | ((Config_Ptr->receiverINT)<<RXCIE);
	/*-------------------------------------------------------------------*/

	/* Setting the INTERRUPT for TX */
	UCSRB = (UCSRB & 0x7F) | ((Config_Ptr->transmitterINT)<<TXCIE);
	/*-------------------------------------------------------------------*/

	/* Setting the data register empty INTERRUPT */
	UCSRB = (UCSRB & 0xDF) | ((Config_Ptr->emptyINT)<<UDRIE);
	/*-------------------------------------------------------------------*/

	/* Receiver Enable */
	UCSRB = (UCSRB & 0xEF) | ((Config_Ptr->receiverEN)<<RXEN);
	/*-------------------------------------------------------------------*/

	/* Transmitter Enable */
	UCSRB = (UCSRB & 0xF7) | ((Config_Ptr->transmitterEN)<<TXEN);
	/*-------------------------------------------------------------------*/

	/* Setting the character size on two separate register  */
	/* Adding only the third-bit to UCSRB and the 2 least bits to UCSRC */
	UCSRB = (UCSRB & 0xFB) | (((Config_Ptr->charSize)>>2)<<UCSZ2);
	UCSRC = (UCSRC & 0xF9) | (((Config_Ptr->charSize)<<6)>>5);
	/*-------------------------------------------------------------------*/

	/* USART Reg Select between UCSRC & UBRRH */
	UCSRC = (UCSRC & 0x7F) | ((Config_Ptr->regSelect)<<URSEL);
	/*-------------------------------------------------------------------*/

	/* USART Mode Select: 1- A-Synch , 2- Synch */
	UCSRC = (UCSRC & 0xBF) | ((Config_Ptr->modeSelect)<<UMSEL);
	/*-------------------------------------------------------------------*/

	/* Selecting the parity mode : Disabled/Even/ODD */
	UCSRC = (UCSRC & 0xCF) | ((Config_Ptr->paritySelect)<<4);
	/*-------------------------------------------------------------------*/

	/* Selecting the stop bit mode: 1-bit and 2-bit */
	UCSRC = (UCSRC & 0xF7) | ((Config_Ptr->stopBitSelect)<<USBS);
	/*-------------------------------------------------------------------*/

	/* Selecting the clock Polarity: Rising and Falling */
	UCSRC = (UCSRC & 0xFE) | (Config_Ptr->clockPolatiry);
	/*-------------------------------------------------------------------*/

	/* Setting the baud rate */
	/* At first you should calculate the UBRR value */
	a_ubrr_value = (uint16)((F_CPU*(Config_Ptr->transmitSpeed+1)/((Config_Ptr->baud_rate)*(16)))-1);

	/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
	UBRRH = a_ubrr_value>>8;
	UBRRL = a_ubrr_value;

	/*----------------------------END--------------------------------*/
}
/*-------------------------------------------------------------------*/

/*
 * Description :
 * Functional responsible for send byte to another UART device.
 */
void UART_sendByte(const uint8 data)
{
	/* Need to wait till the buffer is ready to get a new data */
	while(BIT_IS_CLEAR(UCSRA,UDRE)){}

	/* When it's ready then send it  */
	UDR = data;
}
/*-------------------------------------------------------------------*/

/*
 * Description :
 * Functional responsible for receive byte from another UART device.
 */
uint8 UART_receiveByte(void)
{
	/* Waiting till we get a new data */
	while(BIT_IS_CLEAR(UCSRA,RXC)){}

	/* Return it after getting it */
	return UDR;
}
/*-------------------------------------------------------------------*/

/*
 * Description :
 * Send the required string through UART to the other UART device.
 */
void UART_sendString(const uint8 *Str)
{
	/* Initialing a counter which moves the pointer to another location */
	uint8 a_stringCounter = 0;

	/* Sending byte by byte using UART_sendByte functio */
	while(Str[a_stringCounter] != '\0')
	{
		UART_sendByte(Str[a_stringCounter]);
		a_stringCounter++;
	}
}
/*-------------------------------------------------------------------*/

/*
 * Description :
 * Receive the required string until the '#' symbol through UART from the other UART device.
 */
void UART_receiveString(uint8 *Str,uint8 Size)
{
	/* Initialing a counter which moves the pointer to another location */
	uint8 a_stringCounter = 0;

	Str[a_stringCounter] = UART_receiveByte();

	/* We will start check for a specific character which means to us a null char*/
	while(Str[a_stringCounter] != 'E' && a_stringCounter <(Size-1))
	{
		a_stringCounter++;
		Str[a_stringCounter] = UART_receiveByte();
	}

	/* Then redefining the string by replacing the stop char with NULL char */
//	Str[a_stringCounter] = '\0';
}


/**---------------------------------END-----------------------------**/
