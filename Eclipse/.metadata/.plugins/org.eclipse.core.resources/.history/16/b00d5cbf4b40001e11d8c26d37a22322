/******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: DcMotor.c
 *
 * Description: types for AVR
 *
 * Date Created: 3/10/2022
 *
 * Author: Moustafa Ahmed
 *
 *******************************************************************************/

/**-------------------------INCLUDES Section------------------------**/

#include "Libraries.h"
#include "GPIO.h"
#include "DcMotor.h"
#include "TIMER.h"

/**-------------------------Function Definition Section-------------**/

void DCMotor_init()
{
	/*
	 * Motor is connected to L293D Driver
	 */
	GPIO_setupPinDirection(DC_MOTOR_IN1_OUTPUT_PORT_ID, L293D_IN1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_IN2_OUTPUT_PORT_ID, L293D_IN2_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_EN_PORT_ID, 		L293D_EN1_ID, PIN_OUTPUT);

} /* End DCMotor_init function */

/*----------------------------------------------------------------------------*/

void DcMotor_Rotate(DcMotor_State state, uint8 speed)
{
	/* Selecting the Direction of the MOTOR */
	if(state == ClockWise)
	{
		GPIO_writePin(DC_MOTOR_IN1_OUTPUT_PORT_ID, L293D_IN1_ID, LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_IN2_OUTPUT_PORT_ID, L293D_IN2_ID, LOGIC_LOW);
	}
	else if(state == Anti_ClockWise)
	{
		GPIO_writePin(DC_MOTOR_IN2_OUTPUT_PORT_ID, L293D_IN2_ID, LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_IN1_OUTPUT_PORT_ID, L293D_IN1_ID, LOGIC_LOW);
	}

	/* Sending the compare value to Timer everytime to change the motor speed */
	Timer0_PWM_Activate(&speed);
}

/*----------------------------------------------------------------------------*/

void DCMotor_stop()
{
	GPIO_writePin(DC_MOTOR_EN_PORT_ID, L293D_EN1_ID , LOGIC_LOW); /* Sending speed 0 to DCMotor_Speed() */
}   /* End DCMotor_stop()function */

/**---------------------------------END-----------------------------**/
