/******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: TIMER.h
 *
 * Description: types for AVR
 *
 * Date Created: 15/10/2022
 *
 * Author: Moustafa Ahmed
 *
 *******************************************************************************/
#ifndef TIMER_H_
#define TIMER_H_

/**-------------------------INCLUDES Section------------------------**/

#include "std_types.h"

/**-------------------------Definitions & Config Section------------**/
#define PWM0_PORT_ID		PORTB_ID
#define PWM0_PIN_ID			PIN3_ID

/**-------------------------Enum Section----------------------------**/


/**                         Timer0 Section							**/

typedef enum
{
	F0_NO_CLK,F0_NO_PRESCALING,F0_TIMER8,F0_TIMER64,F0_TIMER256,F0_TIMER1024
}Timer0_PreScaler;
/*-------------------------------------------------------------------*/
typedef enum
{
	TIMER0_FORCE_COMP_OFF,TIMER0_FORCE_COMP_ON
}Timer0_ForceComapare;
/*-------------------------------------------------------------------*/
typedef enum
{
	TIMER0_NORMAL,TIMER0_PWM,TIMER0_CTC,TIMER0_FAST_PWM
}Timer0_WaveForm;
/*-------------------------------------------------------------------*/
typedef enum
{
	TIMER0_COMP_NORMAL,TIMER0_COMP_TOGGLE,TIMER0_COMP_CLEAR,TIMER0_COMP_SET
}Timer0_CompareMode;
/*-------------------------------------------------------------------*/
typedef enum
{
	TIMER0_COMP_INT_OFF,TIMER0_COMP_INT_ON
}Timer0_CompareInterruptEnable;
/*-------------------------------------------------------------------*/
typedef enum
{
	TIMER0_OVF_INT_OFF,TIMER0_OVF_INT_ON
}Timer0_OvfInterrupt;
/*-------------------------------------------------------------------*/

/**                         Timer1 Section							**/

/* Compare Output Mode for channel A */
typedef enum
{
	Normal_A,Toggle_A,Clear_A,Set_A
}TIMER1_CompareModeA;
/*-------------------------------------------------------------------*/

/* Compare Output Mode for channel B */
typedef enum
{
	Normal_B,Toggle_B,Clear_B,Set_B
}TIMER1_CompareModeB;
/*-------------------------------------------------------------------*/

/* Force Output Compare for channel A*/
typedef enum
{
	Channel_A_OFF,Channel_A_ON
}TIMER1_ForceCompareA;
/*-------------------------------------------------------------------*/

/* Force Output Compare for channel B*/
typedef enum
{
	Channel_B_OFF,Channel_B_ON
}TIMER1_ForceCompareB;
/*-------------------------------------------------------------------*/

/* Input capture noise canceler */
typedef enum
{
	NOISE_CANCELER_OFF,NOISE_CANCELER_ON
}TIMER1_NoiseControl;
/*-------------------------------------------------------------------*/

/* Input capture edge select */
typedef enum
{
	TIMER1_FALLING_EDGE,TIMER1_RAISING_EDGE
}TIMER1_EdgeControl;
/*-------------------------------------------------------------------*/

/* Controlling the waveform generation */
typedef enum
{
	NORMAL,PHASE_CORRECT_8,PHASE_CORRECT_9,PHASE_CORRECT_10,CTC_OCR1A,
	FAST_PWM_8,
	FAST_PWM_9,FAST_PWM_10,PWM_P_F_CORRECT_ICR1,PWM_P_F_CORRECT_OCR1A,
	PWM_PHASE_CORRECT_ICR1,PWM_PHASE_CORRECT_OCR1A,CTC_ICR1,RESERVED,
	FAST_PWM_OCR1,
	FAST_PWM_OCR1A

}TIMER1_WaveForm;
/*-------------------------------------------------------------------*/

/* Clock Select pre-scaling */
typedef enum
{
	NO_CLOCK,NO_PRESCALING,F_TIMER18,F_TIMER164,F_TIMER1256,F_TIMER11024,EX_FALLING,
	EX_RISING
}TIMER1_ClockSelect;
/*-------------------------------------------------------------------*/

/* Interrupt Register */
typedef enum
{
	DISABLE_INTERRUPT, ENABLE_INTERRUPT
}TIMER1_InterruptActivate;
/*-------------------------------------------------------------------*/

/**                         Timer2 Section							**/

typedef enum
{
	F2_NO_CLK,F2_NO_PRESCALING,F2_TIMER8,F2_TIMER32,F2_TIMER64,F2_TIMER128,F2_TIMER256,F2_TIMER1024
}Timer2_PreScaler;
/*-------------------------------------------------------------------*/
typedef enum
{
	TIMER2_FORCE_COMP_OFF,TIMER2_FORCE_COMP_ON
}Timer2_ForceComapare;
/*-------------------------------------------------------------------*/
typedef enum
{
	TIMER2_NORMAL,TIMER2_PWM,TIMER2_CTC,TIMER2_FAST_PWM
}Timer2_WaveForm;
/*-------------------------------------------------------------------*/
typedef enum
{
	TIMER2_COMP_NORMAL,TIMER2_COMP_TOGGLE,TIMER2_COMP_CLEAR,TIMER2_COMP_SET
}Timer2_CompareMode;
/*-------------------------------------------------------------------*/
typedef enum
{
	TIMER2_COMP_INT_OFF,TIMER2_COMP_INT_ON
}Timer2_CompareInterruptEnable;
/*-------------------------------------------------------------------*/
typedef enum
{
	TIMER2_OVF_INT_OFF,TIMER2_OVF_INT_ON
}Timer2_OvfInterrupt;
/*-------------------------------------------------------------------*/

/**-------------------------Struct Section--------------------------**/

/*--------------------------Timer0 Section--------------------------*/
/* Please Copy the below comment before Initializing Timer0 */
/*
 * file name: TIMER.h
 *  -> Structure Configuration:
 *
 *  Timer0_PreScaler :
 *  Timer0_ForceCompare :
 *  Timer0_WaveForm :
 *  Timer0_CompareMode :
 *  Timer0_COMP_INT :
 *  Timer0_OVF_INT :
 *  Timer0_TCNT0_Value :
 *  Timer0_OCR0_Value :
 */
typedef struct
{
	Timer0_PreScaler Timer0_PreScaler;
	Timer0_ForceComapare Timer0_ForceCompare;
	Timer0_WaveForm	Timer0_WaveForm;
	Timer0_CompareMode Timer0_CompareMode;
	Timer0_CompareInterruptEnable Timer0_COMP_INT;
	Timer0_OvfInterrupt Timer0_OVF_INT;
	uint8 Timer0_TCNT0_Value;
	uint8 Timer0_OCR0_Value;
}Timer0_ConfigType;

/*--------------------------Timer1 Section--------------------------*/

/* Please Copy the below comment before Initializing Timer1 */
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
 *  TCNT1_Value : 4850
 *  OCR1A_Value : 4883
 *  OCR1B_Value : ---
 */
typedef struct
{
	TIMER1_CompareModeA CompareModeA;
	TIMER1_CompareModeB CompareModeB;
	TIMER1_ForceCompareA ForceCompareA;
	TIMER1_ForceCompareB ForceCompareB;
	TIMER1_EdgeControl EdgeControl;
	TIMER1_NoiseControl NoiseControl;
	TIMER1_ClockSelect F_TIMER1_CLOCK;
	TIMER1_WaveForm WaveForm;
	TIMER1_InterruptActivate interruptA;
	TIMER1_InterruptActivate interruptB;
	TIMER1_InterruptActivate interruptOvf;
	uint16 TCNT1_Value;
	uint16 OCR1A_Value;
	uint16 OCR1B_Value;

}Timer1_ConfigType;
/*--------------------------Timer2 Section--------------------------*/
/* Please Copy the below comment before Initializing Timer2 */
/*
 * file name: TIMER.h
 *  -> Structure Configuration:
 *
 *  Timer2_PreScaler :
 *  Timer2_ForceCompare :
 *  Timer2_WaveForm :
 *  Timer2_CompareMode :
 *  Timer2_COMP_INT :
 *  Timer2_OVF_INT :
 *  Timer2_TCNT2_Value :
 *  Timer2_OCR2_Value :
 */
typedef struct
{
	Timer2_PreScaler Timer2_PreScaler;
	Timer2_ForceComapare Timer2_ForceCompare;
	Timer2_WaveForm	Timer2_WaveForm;
	Timer2_CompareMode Timer2_CompareMode;
	Timer2_CompareInterruptEnable Timer2_COMP_INT;
	Timer2_OvfInterrupt Timer2_OVF_INT;
	uint8 Timer2_TCNT2_Value;
	uint8 Timer2_OCR2_Value;
}Timer2_ConfigType;
/**-------------------------Function Dec. Section-------------------**/

/**                         Timer0 Section							**/
/*
 * Initializing Timer0
 */
void Timer0_Init(const Timer0_ConfigType *Config_Ptr);
/*-------------------------------------------------------------------*/
/*
 * Description:
 * De-Initializing Everything
 */
void Timer0_deInit(void);

/*-------------------------------------------------------------------*/
/* Description: Function to set the Call Back function address. */
void Timer0_setCallBackZERO(void(*a_ptr)(void));
/*-------------------------------------------------------------------*/

/*
 * Initializing Timer0_PWM
 */
void Timer0_PWM_Init(const Timer0_ConfigType *Config_Ptr);
/*-------------------------------------------------------------------*/

/*
 * Setting Timer0_PWM
 */
void Timer0_PWM_Activate(uint8 *SetDuty_Ptr);
/*-------------------------------------------------------------------*/

/**------------------------Timer ONE-----------------------**/
/*
 * Initializing Timer1
 */
void Timer1_Init(const Timer1_ConfigType *Config_Ptr);
/*-------------------------------------------------------------------*/
/*
 * Description:
 * De-Initializing Everything
 */
void Timer1_deInit(void);

/*-------------------------------------------------------------------*/
/* Description: Function to set the Call Back function address. */
void Timer1_setCallBackONE(void(*a_ptr)(void));

/**------------------------Timer TWO-----------------------**/
/*
 * Initializing Timer2
 */
void Timer2_Init(const Timer2_ConfigType *Config_Ptr);
/*-------------------------------------------------------------------*/
/*
 * Description:
 * De-Initializing Everything
 */
void Timer2_deInit(void);

/*-------------------------------------------------------------------*/
/* Description: Function to set the Call Back function address. */
void Timer2_setCallBackTWO(void(*a_ptr)(void));

/**-------------------------END-------------------------------------**/

#endif /* TIMER_H_ */
