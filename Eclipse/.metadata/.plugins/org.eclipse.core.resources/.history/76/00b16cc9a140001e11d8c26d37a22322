/******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: TIMER.c
 *
 * Description: types for AVR
 *
 * Date Created: 15/10/2022
 *
 * Author: Moustafa Ahmed
 *
 *******************************************************************************/

/**-------------------------INCLUDES Section------------------------**/
#include "Libraries.h"
#include "GPIO.h"
#include "TIMER.h"

/**-------------------------Global Variables Section----------------**/

/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_callBackPtrZERO)(void)= NULL_PTR;
static volatile void (*g_callBackPtrONE)(void) = NULL_PTR;
static volatile void (*g_callBackPtrTWO)(void) = NULL_PTR;

/**-------------------------Extern Section--------------------------**/

/**-------------------------Interrupts Section----------------------**/
/**                               TIMER 0                          **/
/* Interrupt for normal mode */
ISR(TIMER0_OVF_vect)
{
	if(g_callBackPtrZERO != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtrZERO)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}
/*-------------------------------------------------------------------*/
/* Interrupt for Compare Mode */
ISR(TIMER0_COMP_vect)
{
	if(g_callBackPtrZERO != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtrZERO)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}

/*------------------------------------------------------------------*/
/**                               TIMER 1                          **/

/* Interrupt for normal mode */
ISR(TIMER1_OVF_vect)
{
	if(g_callBackPtrONE != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtrONE)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}
/*-------------------------------------------------------------------*/
/* Interrupt for Compare Mode */
ISR(TIMER1_COMPA_vect)
{
	if(g_callBackPtrONE != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtrONE)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}
/*-------------------------------------------------------------------*/
/**                               TIMER 2                          **/

/* Interrupt for normal mode */
ISR(TIMER2_OVF_vect)
{
	if(g_callBackPtrTWO != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtrTWO)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}
/*-------------------------------------------------------------------*/
/* Interrupt for Compare Mode */
ISR(TIMER2_COMP_vect)
{
	if(g_callBackPtrTWO != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtrTWO)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}

/**-------------------------Function Definition Section-------------**/


/**------------------------Timer ZERO-----------------------**/
/*
 * Initializing Timer0
 */
void Timer0_Init(const Timer0_ConfigType *Config_Ptr)
{
	/* Selecting Force Output Compare */
	TCCR0 = (TCCR0 & 0x7F) | ((Config_Ptr->Timer0_ForceCompare)<<FOC0);

	/* Selecting the WaveForm Generation */
	TCCR0 = (TCCR0 & 0xBF) | (((Config_Ptr->Timer0_WaveForm)<<7)>>1);
	TCCR0 = (TCCR0 & 0xF7) | (((Config_Ptr->Timer0_WaveForm)>>1)<<WGM01);

	/* Select Compare Match output mode */
	TCCR0 = (TCCR0 & 0xCF) | ((Config_Ptr->Timer0_CompareMode)<<4);

	/* Select the Prescaler Value */
	TCCR0 = (TCCR0 & 0xF8) | ((Config_Ptr->Timer0_PreScaler));

	/* Choosing the OVF value */
	TCNT0 = Config_Ptr->Timer0_TCNT0_Value;

	/* Choosing OCR0 value */
	OCR0 = Config_Ptr->Timer0_OCR0_Value;

	/* Enabling Interrupt for Compare */
	TIMSK = (TIMSK & 0xFD) | ((Config_Ptr->Timer0_COMP_INT)<<OCIE0);

	/* Enabling Interrupts for OVF */
	TIMSK = (TIMSK & 0xFE) | ((Config_Ptr->Timer0_OVF_INT));
}
/*-------------------------------------------------------------------*/
/*
 * Description:
 * De-Initializing Everything
 */
void Timer0_deInit(void)
{
	TCCR0 = 0;
	TIMSK = (TIMSK & 0xFC);
}

/*-------------------------------------------------------------------*/
/* Description: Function to set the Call Back function address. */
void Timer0_setCallBackZERO(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtrZERO = a_ptr;
}
/*-------------------------------------------------------------------*/

/*
 * Initializing Timer0_PWM
 */
void Timer0_PWM_Init(const Timer0_ConfigType *Config_Ptr)
{
	TCNT0 = 0; /* Set Timer Initial Value to 0 */

	/* Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC */
	GPIO_setupPinDirection(PWM0_PORT_ID, PWM0_PIN_ID, PIN_OUTPUT);

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = Dependent on the user
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01);
	TCCR0 |= Config_Ptr->Timer0_PreScaler;
}

/*----------------------------------------------------------------------------*/

/*
 * Setting Timer0_PWM
 */
void Timer0_PWM_Activate(uint8 *SetDuty_Ptr)
{
	TCNT0 = 0; /* Set Timer Initial Value to 0 */
	OCR0  = *SetDuty_Ptr; /* Set Compare Value */
}

/**----------------------------Timer1----------------------------**/

/*
 * Initializing TIMER0
 */
void Timer1_Init(const Timer1_ConfigType *Config_Ptr)
{
	/* Compare Output Mode for channel A */
	TCCR1A = (TCCR1A & 0x3F) | (Config_Ptr->CompareModeA<<6);

	/* Compare Output Mode for channel B */
	TCCR1A = (TCCR1A & 0xCF) | (Config_Ptr->CompareModeB<<4);

	/* Force Output Compare for Channel A */
	TCCR1A = (TCCR1A & 0xF7) | (Config_Ptr->ForceCompareA<<3);

	/* Force Output Compare for Channel B */
	TCCR1A = (TCCR1A & 0xFB) | (Config_Ptr->ForceCompareB<<2);

	/* Setting the waveform */
	TCCR1A = (TCCR1A & 0xFC) | ((Config_Ptr->WaveForm<<6)>>6); /* Getting the first 2 bits only */
	TCCR1B = (TCCR1B & 0xE7) | ((Config_Ptr->WaveForm>>2)<<3); /* Getting bit 2 and 3 only*/

	/* Noise Canceler */
	TCCR1B = (TCCR1B & 0x7F) | ((Config_Ptr->NoiseControl)<<7);

	/* Edge Select */
	TCCR1B = (TCCR1B & 0xBF) | ((Config_Ptr->EdgeControl)<<ICES1);

	/* Clock Selection */
	TCCR1B = (TCCR1B & 0xF8) | (Config_Ptr->F_TIMER1_CLOCK);

	/* Enable compare A interrupt */
	TIMSK = (TIMSK & 0xEF) | ((Config_Ptr->interruptA)<<OCIE1A);

	/* Enable compare B interrupt */
	TIMSK = (TIMSK & 0xF7) | ((Config_Ptr->interruptB)<<OCIE1B);

	/* Enable OverFlow interrupt */
	TIMSK = (TIMSK & 0xFB) | ((Config_Ptr->interruptOvf)<<TOIE1);

	/* Initial Value for Timer1 */
	TCNT1 = Config_Ptr->TCNT1_Value;

	/* Initializing the compare value register */
	OCR1A = Config_Ptr->OCR1A_Value;
	OCR1B = Config_Ptr->OCR1B_Value;
}
/*-------------------------------------------------------------------*/

/* Description: Function to set the Call Back function address. */
void Timer1_setCallBackONE(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtrONE = a_ptr;
}
/*-------------------------------------------------------------------*/

/*
 * Description:
 * De-Initializing Everything
 */
void Timer1_deInit()
{
	TCCR1A = 0;
	TCCR1B = 0;
	TIMSK = TIMSK & 0xC3;
}
/**------------------------Timer TWO-----------------------**/
/*
 * Initializing Timer2
 */
void Timer2_Init(const Timer2_ConfigType *Config_Ptr)
{
	/* Selecting Force Output Compare */
		TCCR2 = (TCCR2 & 0x7F) | ((Config_Ptr->Timer2_ForceCompare)<<FOC2);

		/* Selecting the WaveForm Generation */
		TCCR2 = (TCCR2 & 0xBF) | (((Config_Ptr->Timer2_WaveForm)<<7)>>1);
		TCCR2 = (TCCR2 & 0xF7) | (((Config_Ptr->Timer2_WaveForm)>>1)<<WGM21);

		/* Select Compare Match output mode */
		TCCR2 = (TCCR2 & 0xCF) | ((Config_Ptr->Timer2_CompareMode)<<4);

		/* Select the Prescaler Value */
		TCCR2 = (TCCR2 & 0xF8) | ((Config_Ptr->Timer2_PreScaler));

		/* Choosing the OVF value */
		TCNT0 = Config_Ptr->Timer2_TCNT2_Value;

		/* Choosing OCR2 value */
		OCR2 = Config_Ptr->Timer2_OCR2_Value;

		/* Enabling Interrupt for Compare */
		TIMSK = (TIMSK & 0x7F) | ((Config_Ptr->Timer2_COMP_INT)<<OCIE2);

		/* Enabling Interrupts for OVF */
		TIMSK = (TIMSK & 0xBF) | ((Config_Ptr->Timer2_OVF_INT));
}
/*-------------------------------------------------------------------*/
/*
 * Description:
 * De-Initializing Everything
 */
void Timer2_deInit(void)
{
	TCCR2 = 0;
	TIMSK = (TIMSK & 0x3F);
}

/*-------------------------------------------------------------------*/
/* Description: Function to set the Call Back function address. */
void Timer2_setCallBackTWO(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtrTWO = a_ptr;
}

/**---------------------------------END-----------------------------**/
