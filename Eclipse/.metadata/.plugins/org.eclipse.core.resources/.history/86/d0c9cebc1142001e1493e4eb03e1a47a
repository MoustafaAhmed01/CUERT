/******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: CUERT.c
 *
 * Description: types for AVR
 *
 * Date Created: 21/8/2023
 *
 * Author: Moustafa Ahmed Adel
 *
 *******************************************************************************/
/**-------------------------INCLUDES Section------------------------**/

#include <stdio.h>
#include "../HAL/Header/DcMotor.h"
#include "../HAL/Header/LCD.h"
#include "../HAL/Header/Stepper_Motor.h"
#include "../Libraries/Libraries.h"
#include "../Libraries/std_types.h"
#include "../MCAL/Header/TIMER.h"
#include "../MCAL/Header/UART.h"
/**-------------------------Extern  Section-------------------------**/

/**-------------------------Global  Section-------------------------**/

/**-------------------------STRUCTURES------------------------------**/

/* Numbers will be saved right here */
struct DISPLAY_STRUCT
{
	uint8 Second_ONE,Second_TWO,Minute_ONE,Minute_TWO,Hour_ONE,Hour_TWO, AM_PM;
}Display;


/**-------------------------Function Dec. Section-------------------**/

/*
 * Description:
 * This will be the function which will be called back by the Timer
 */
void App_timer1(void);
/*-------------------------------------------------------------------*/
/*
 * Description:
 * Display time on LCD
 */
void LCD_Time_Display(void);
/*-------------------------------------------------------------------*/
/* Converts String to int */
uint8 String_Intger_Converter(uint8 First, uint8 Second, uint8 Third);
/*-------------------------------------------------------------------*/

/* Check on the received command if it applies to our terms */
uint8 Receive_Check(uint8 *Check_ptr);

/**-------------------------Function Section------------------------**/
/* Initializing all drivers */
void Drivers_init(void)
{
	/* Initializing UART
	 *
	 * UART_trSpeed : Double Speed
	 * UART_RECEIVE_INT : No
	 * UART_TRANSMIT_INT :No
	 * UART_EMPTY_INT : No
	 * UART_RECEIVER : Yes
	 * UART_TRANSMITTER : No
	 * UART_CharSize : 8-bit
	 * UART_REG_SELECT : UBRRH
	 * UART_MODE_SELECT : A-Sync
	 * UART_PARITY_SELECT : No
	 * UART_STOP_BIT_SELECT : 1-bit
	 * UART_CLOCK_POLARITY : A-Sync Rising
	 * baud_rate : 9600
	 *
	 */
	UART_ConfigType UART_Config = {DOUBLE_TR_SPEED, RECEIVE_INT_EN_OFF,TRANSMIT_INT_EN_OFF,EMPTY_INT_EN_OFF,RECEIVER_EN_ON,TRANSMITTER_EN_OFF,EIGHT_BIT,UBRRH_REG,ASYNCHRONOUS,PARITY_DISABLE,ONE_BIT,A_Sync_RISING_EDGE,9600};
	UART_init(&UART_Config); /* Received to Config_ptr */
	/* ------------------------------------------------------------------ */

	/* Initializing DC-Motor */
	DCMotor_init();
	/* ------------------------------------------------------------------ */

	/* Initializing Timer0 PWM */
	Timer0_ConfigType Timer0_PWM_Config;
	Timer0_PWM_Config.Timer0_PreScaler = F0_TIMER64; /* F_CPU/64. Assuming F_PWM = 500 Hz */
	Timer0_PWM_Init(&Timer0_PWM_Config);
	/* ------------------------------------------------------------------ */

	/* Initializing LCD 4-PIN Mode */
	LCD_init();
	/* ------------------------------------------------------------------ */

	/* Stepper Motor Init */
	Stepper_Motor_init();
	/* ------------------------------------------------------------------ */

	/* Initializing Timer 1 */
	/*
	 * file name: TIMER.h
	 *  -> Structure Configuration:
	 *
	 *  CompareModeA : Normal
	 *  CompareModeB : Normal
	 *  ForceCompareA : Activated
	 *  ForceCompareB : Disabled
	 *  EdgeControl : ---
	 *  NoiseControl : Disabled
	 *  F_TIMER1_CLOCK : F_CPU/1024
	 *  WaveForm : CTC mode ,TOP: OCR1A
	 *  interruptA : Enabled
	 *  interruptB : Disabled
	 *  interruptOvf : Disabled
	 *  TCNT1_Value : 0
	 *  OCR1A_Value : 7813
	 *  OCR1B_Value : ---
	 */
	Timer1_ConfigType TIMER1_Config = {Normal_A,Normal_B,Channel_A_ON,Channel_B_OFF,TIMER1_FALLING_EDGE,NOISE_CANCELER_OFF,F_TIMER11024,CTC_OCR1A,ENABLE_INTERRUPT,DISABLE_INTERRUPT,DISABLE_INTERRUPT,0,7813,0};
	/* Setting the callback function*/
	Timer1_setCallBackONE(App_timer1);
	Timer1_Init(&TIMER1_Config); /* Start Timer */

	/* ------------------------------------------------------------------ */
	/* Time Init */
	Display.AM_PM = 'A';

	/* ------------------------------------------------------------------ */
	/* Activating Interrupt system */
	SREG |= (1<<7);
}

/* ------------------------------------------------------------------ */

int main()
{
	/**-----------------------Local Variables----------------------**/
	/* Receive UART data unit = unsigned 8 bit variable (unsigned char) */
	volatile uint8 const l_Received_Data_Size = 8;
	volatile uint8 l_Received_Data[l_Received_Data_Size];

	/* Speed Value */
	uint8 l_Speed_Value = 0;

	/* Rotational Degree */
	sint8 l_Rot_Degree = 0;

	/* Current rotational angle */
	volatile sint8 l_Current_Angle = 0;

	/* Check flag */
	uint8 flag = FALSE;

	/**-----------------------Pre-start Section--------------------**/

	/* Initializing all drivers: UART, DCMotor, Timer0, LCD, Stepper Motor */
	Drivers_init();

	/**-----------------------Main Section-------------------------**/
	while(1)
	{

		flag = FALSE; 				/* Return to FALSE after each loop */

		while(!flag) 				/* Check point */
		{
			/* Wait for data to be received and then based on it will perform another actions */
			UART_receiveString(l_Received_Data,l_Received_Data_Size);

			if('C' == Receive_Check(l_Received_Data)) /* If the first step check was correct cont */
			{
				flag = TRUE;
			}
			else
			{
				flag = FALSE;
			}
		}
		/*------------------------------------------------------------*/

		/*----------- Convert String to intger ----------*/

		/* Get the speed value */
		l_Speed_Value = String_Intger_Converter(l_Received_Data[0], l_Received_Data[1], l_Received_Data[2]);
		/* Get the rotational degree */
		l_Rot_Degree = String_Intger_Converter('0', l_Received_Data[4], l_Received_Data[5]);

		/*-------------------------------------------------------------*/


		/*-------------------LCD display---------------*/

		/* Init LCD everytime just for special reasons */
		LCD_init();
		LCD_clearScreen();

		/* Display the Speed */
		LCD_moveCursor(0, 0);
		LCD_displayString("Speed: ");
		LCD_moveCursor(0, 7);
		LCD_intgerToString(l_Speed_Value);
		if(l_Speed_Value >= 100)
		{
			/* Do nothing */
		}
		else
		{
			/* Leave a space after to remove the zero */
			LCD_displayCharacter(' ');
		}
		/*-----------------------------------*/

		/* Display the rotational angle */
		LCD_moveCursor(0, 15);

		if('R' == l_Received_Data[6] || ('0' == l_Received_Data[5] && '0' == l_Received_Data[4] ))
		{
			LCD_displayString("Direction: +");
		}
		else
		{
			LCD_displayString("Direction: -");
		}
		LCD_moveCursor(0, 27);

		LCD_intgerToString(l_Rot_Degree);
		/*---------------------------------------------------------------*/

		/*---------------DC Motor------------*/
		if('F' == l_Received_Data[3])
		{
			DcMotor_Rotate(Anti_ClockWise, ((255*l_Speed_Value)/100));
		}
		else
		{
			DcMotor_Rotate(ClockWise, ((255*l_Speed_Value)/100));
		}

		/*---------------Stepper Motor------------*/
		if( 'R' == l_Received_Data[6] )
		{
			stepper_rotate(Right_Direction, l_Rot_Degree,l_Current_Angle);
			l_Current_Angle = l_Rot_Degree;
		}
		else
		{
			stepper_rotate(Left_Direction, l_Rot_Degree, l_Current_Angle);
			l_Current_Angle = (l_Rot_Degree * (-1));
		}
	}

	return 0;
}
/**-------------------------END MAIN--------------------------------**/

/**-------------------------Function Section------------------------**/

/* Converts String to int */
uint8 String_Intger_Converter(uint8 First, uint8 Second, uint8 Third)
{
	return (((First-'0')*100) +((Second-'0')*10)+((Third-'0')));
}
/*-------------------------------------------------------------------*/

/**-----------------------Check Section-----------------------------**/

/* Check on the received command if it applies to our terms */
uint8 Receive_Check(uint8 *Check_ptr)
{
	/* Check on the last char which is should be 'E' */
	if('E' == Check_ptr[7]) /* If it equals 0 or 1 */
	{
		/* Change E to become '\0' as it should be */
		Check_ptr[7] = '\0';
	}
	else
	{
		return 'I';
	}
	/*-----------------------------------*/
	/* Check on the first char */
	if('0' == Check_ptr[0] || '1' == Check_ptr[0]) /* If it equals 0 or 1 */
	{
		/* Do nothing */
	}
	else
	{
		return 'I';
	}
	/*-----------------------------------*/
	/* Check on the Second char */
	if(Check_ptr[1] >= 48 && Check_ptr[1] <= 57) /* If it's in between 0 and 9 */
	{
		/* Do nothing */
	}
	else
	{
		return 'I';
	}
	/*-----------------------------------*/
	/* Check on the Third char */
	if(Check_ptr[2] >= 48 && Check_ptr[2] <= 57) /* If it's in between 0 and 9 */
	{
		/* Do nothing */
	}
	else
	{
		return 'I';
	}
	/*-----------------------------------*/
	/* Check on the 4th char */
	if('F' ==  Check_ptr[3] || 'B' == Check_ptr[3]) /* If it equals 'F' or 'B' */
	{
		/* Do nothing */
	}
	else
	{
		return 'I';
	}
	/*-----------------------------------*/
	/* Check on the 5th char */
	if(Check_ptr[4] >= 48 && Check_ptr[4] <= 52) /* If it's in between 0 and 4 */
	{
		/* Do nothing */
	}
	else
	{
		return 'I';
	}
	/*-----------------------------------*/
	/* Check on the 6th char */
	if(Check_ptr[5] >= 48 && Check_ptr[5] <= 57) /* If it's in between 0 and 9 and make sure it's between 0 and 45*/
	{
		if(Check_ptr[4] == 52) /* The rotational degree was 4X then X should be between 0 and 5 */
		{
			if(Check_ptr[5] >= 48 && Check_ptr[5] <= 53) /* 0 ~ 5 */
			{
				/* Do nothing */
			}
			else
			{
				return 'I';
			}
		}
	}
	else
	{
		return 'I';
	}
	/*-----------------------------------*/
	/* Check on the 7th char */
	if('L' ==  Check_ptr[6] || 'R' == Check_ptr[6]) /* If it equals 'L' or 'R' */
	{
		/* Do nothing */
	}
	else
	{
		return 'I';
	}
	/*-----------------------------------*/

	/* Return correct if it has passed all the prev checks */
	return 'C';
}

/**-----------------------Time Managment Section--------------------**/

/*-------------------------------------------------------------------*/
/*
 * Description:
 * This will be the function which will be called back by the Timer
 */
void App_timer1()
{
	/**-----------------------Local Variables----------------------**/

	/**-----------------------Main Section-------------------------**/
	/** The main thing that will change everything is Seconds, So, we have to check it at first **/
	if(Display.Second_ONE == 9 && Display.Second_TWO == 5) /* If the first and Second digits were at max no. 59 */
	{
		/*  Then we will Inc the next but let's make sure the next not at it's max digits */
		if(Display.Minute_ONE == 9) /* If the first Digit in Minute was 9 So, it's as it's max no. */
		{
			/* Then we will inc. the next which is Minute Two but let's make sure it's not at it's max no. */
			if(Display.Minute_TWO == 5) /* If second digit in Minute was 5 then it's at it's max no. */
			{
				/* Then we will inc the next which is the Hours but, let's make sure again */
				if(Display.Hour_ONE == 2)  /* If the FIRST digit in hours was at it's max */
				{
					if(Display.Hour_TWO == 1) /* If the SECOND digit in hours was at it's max */
					{
						/* Reset */
						if(Display.AM_PM == 'A')
						{
							Display.AM_PM = 'P';
						}
						else
						{
							Display.AM_PM = 'A';
						}
					}
					else  /* Means Hour_TWO not at it's max != 5 So, Inc. it */
					{
						Display.Hour_TWO++;
						Display.Second_ONE = 0;
						Display.Second_TWO = 0;
						Display.Minute_ONE = 0;
						Display.Minute_TWO = 0;
						Display.Hour_ONE = 0;
					}
				}
				else /* Means Hour_ONE not at it's max != 9 So, Inc. it */
				{
					Display.Hour_ONE++	;
					Display.Second_ONE = 0;
					Display.Second_TWO = 0;
					Display.Minute_ONE = 0;
					Display.Minute_TWO = 0;
				}
			}
			else /* Means Minute_TWO not at it's max != 5 So, Inc. it */
			{
				Display.Second_ONE = 0;
				Display.Second_TWO = 0;
				Display.Minute_ONE = 0;
				Display.Minute_TWO++;
			}
		}
		else /* Means Minute_ONE not at it's max != 9 So, Inc. it */
		{
			Display.Second_ONE = 0;
			Display.Second_TWO = 0;
			Display.Minute_ONE++;
		}
	}
	else if(Display.Second_ONE == 9) /* Means the Second_TWO not at it's max no.!= 5 So, Inc it */
	{
		Display.Second_ONE = 0;
		Display.Second_TWO++;
	}
	else /* Means the Second_ONE not at it's max no.!= 9 So, Inc it */
	{
		Display.Second_ONE++;
	}
	LCD_Time_Display();
}

/*-------------------------------------------------------------------*/
/*
 * Description:
 * Display time on LCD
 */
void LCD_Time_Display(void)
{
	/* Display Time format as Time: 00:00:00 AM */
	LCD_displayStringRowColumn(1, 6, "Time: "); /* Displaying Time: */

	if(Display.AM_PM == 'A') /* Displaying AM or PM */
	{
		LCD_displayStringRowColumn(1, 21, "AM");
	}
	else
	{
		LCD_displayStringRowColumn(1, 21, "PM");
	}
	/* Displaying Hours */
	LCD_moveCursor(1, 12);
	LCD_intgerToString(Display.Hour_TWO);
	LCD_moveCursor(1, 13);
	LCD_intgerToString(Display.Hour_ONE);

	LCD_displayCharRowColumn(1, 14, ':');

	/* Displaying Minutes */
	LCD_moveCursor(1, 15);
	LCD_intgerToString(Display.Minute_TWO);
	LCD_moveCursor(1, 16);
	LCD_intgerToString(Display.Minute_ONE);

	LCD_displayCharRowColumn(1, 17, ':');

	/* Displaying Seconds */
	LCD_moveCursor(1, 18);
	LCD_intgerToString(Display.Second_TWO);
	LCD_moveCursor(1, 19);
	LCD_intgerToString(Display.Second_ONE);

	LCD_displayCharacter(' ');
}
/*-------------------------------------------------------------------*/
