/******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: Stepper_Motor.h
 *
 * Description: types for AVR
 *
 * Date Created: 21/8/2023
 *
 * Author: Moustafa Ahmed
 *
 *******************************************************************************/

/**-------------------------INCLUDES Section------------------------**/
#include "Header/Stepper_Motor.h"

#include "../Libraries/Libraries.h"
#include "../MCAL/Header/GPIO.h"

/**-------------------------Global Section--------------------------**/

/**-------------------------Definitions & Config Section------------**/
#define DELAY 25
/**-------------------------Function Definition Section-------------**/
/*
 * Description:
 * Initializing Stepper Motor
 */
void Stepper_Motor_init()
{
	/* Initialize stepper motor pins as outputs */
	GPIO_setupPinDirection(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN1, PIN_OUTPUT);
	GPIO_setupPinDirection(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN2, PIN_OUTPUT);
	GPIO_setupPinDirection(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN3, PIN_OUTPUT);
	GPIO_setupPinDirection(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN4, PIN_OUTPUT);

	/* Enable Pins direction */
	GPIO_setupPinDirection(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_EN1, PIN_OUTPUT);
	GPIO_setupPinDirection(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_EN2, PIN_OUTPUT);

	/* Disable stepper motor */
	GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_EN1, LOGIC_LOW);
	GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_EN2, LOGIC_LOW);
}
/*-------------------------------------------------------------------*/
/*
 * Description:
 * Step the motor in a given direction
 */
void stepper_rotate(Stepper_Motor_State direction, sint8 angle,sint8 current_angle)
{

	/**-----------------------Local Variables----------------------**/
	uint8 counter = 0; /* Counter for the FOR loop */
	sint8 actual_step = 0; /* Based on the current angle */

	/**-----------------------Main Section-------------------------**/

	/* Activate the motor */
	GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_EN1, LOGIC_HIGH);
	GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_EN2, LOGIC_HIGH);

	/** Calculation the number of steps needed based on the current angle **/
	if(Right_Direction == direction)
	{
		/* Calculate the steps needed */
		actual_step = angle - current_angle;

		if(actual_step < 0) /* If the result was negative then rotate left else rotate right */
		{
			actual_step = actual_step*(-1);
			direction = Left_Direction;
		}
		else
		{
			/* Do nothing it's already Right */
		}
	}
	else
	{
		/* Calculate the steps needed */
		actual_step = (angle*(-1)) - current_angle;

		if(actual_step < 0) /* If the result was negative then rotate left else rotate right */
		{
			actual_step = actual_step*(-1);
			/* Do nothing it's already set to LEFT */
		}
		else
		{
			direction = Right_Direction;
		}
	}
	/**-------------------------------------------------------------------**/

	if(Right_Direction == direction)
	{
		for(counter = 0; counter < actual_step; counter++)
		{
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN1, LOGIC_HIGH);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN2, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN3, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN4, LOGIC_LOW);
			_delay_ms(DELAY);

			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN1, LOGIC_HIGH);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN2, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN3, LOGIC_HIGH);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN4, LOGIC_LOW);
			_delay_ms(DELAY);

			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN1, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN2, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN3, LOGIC_HIGH);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN4, LOGIC_LOW);
			_delay_ms(DELAY);

			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN1, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN2, LOGIC_HIGH);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN3, LOGIC_HIGH);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN4, LOGIC_LOW);
			_delay_ms(DELAY);

			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN1, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN2, LOGIC_HIGH);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN3, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN4, LOGIC_LOW);
			_delay_ms(DELAY);

			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN1, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN2, LOGIC_HIGH);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN3, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN4, LOGIC_HIGH);
			_delay_ms(DELAY);

			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN1, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN2, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN3, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN4, LOGIC_HIGH);
			_delay_ms(DELAY);

			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN1, LOGIC_HIGH);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN2, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN3, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN4, LOGIC_HIGH);
			_delay_ms(DELAY);

			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN1, LOGIC_HIGH);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN2, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN3, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN4, LOGIC_LOW);
			_delay_ms(DELAY);
		}

	}
	else /* Left direction */
	{
		/*Description
		 * It moves with this sequence {1 , 1&4, 4, 4&2, 2, 2&3, 3, 3&1, 1}
		 */
		for(counter = 0; counter < actual_step; counter++)
		{
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN1, LOGIC_HIGH);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN2, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN3, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN4, LOGIC_LOW);
			_delay_ms(DELAY);

			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN1, LOGIC_HIGH);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN2, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN3, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN4, LOGIC_HIGH);
			_delay_ms(DELAY);

			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN1, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN2, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN3, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN4, LOGIC_HIGH);
			_delay_ms(DELAY);

			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN1, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN2, LOGIC_HIGH);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN3, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN4, LOGIC_HIGH);
			_delay_ms(DELAY);

			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN1, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN2, LOGIC_HIGH);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN3, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN4, LOGIC_LOW);
			_delay_ms(DELAY);

			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN1, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN2, LOGIC_HIGH);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN3, LOGIC_HIGH);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN4, LOGIC_LOW);
			_delay_ms(DELAY);

			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN1, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN2, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN3, LOGIC_HIGH);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN4, LOGIC_LOW);
			_delay_ms(DELAY);

			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN1, LOGIC_HIGH);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN2, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN3, LOGIC_HIGH);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN4, LOGIC_LOW);
			_delay_ms(DELAY);

			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN1, LOGIC_HIGH);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN2, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN3, LOGIC_LOW);
			GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_IN4, LOGIC_LOW);
			_delay_ms(DELAY);
		}
	}

	/* Disable the motor */
	GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_EN1, LOGIC_LOW);
	GPIO_writePin(STEPPER_MOTOR_OUTPUT_PORT, STEPPER_MOTOR_EN2, LOGIC_LOW);
}

/**---------------------------------END-----------------------------**/

