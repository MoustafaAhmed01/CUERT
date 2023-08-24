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

#ifndef HAL_HEADER_STEPPER_MOTOR_H_
#define HAL_HEADER_STEPPER_MOTOR_H_

/**-------------------------INCLUDES Section------------------------**/

#include "../../Libraries/std_types.h"

/**-------------------------Definitions & Config Section------------**/

#define STEPPER_MOTOR_OUTPUT_PORT		PORTC_ID
#define STEPPER_MOTOR_OUTPUT_PORT_PINS 	PORTC
#define STEPPER_MOTOR_IN1  				PIN0_ID
#define STEPPER_MOTOR_IN2  				PIN1_ID
#define STEPPER_MOTOR_IN3  				PIN2_ID
#define STEPPER_MOTOR_IN4  				PIN3_ID
#define STEPPER_MOTOR_EN1				PIN6_ID
#define STEPPER_MOTOR_EN2				PIN7_ID
/**-------------------------Enum Section----------------------------**/

typedef enum
{
	Left_Direction, Right_Direction
}Stepper_Motor_State;

/**-------------------------Function Dec. Section-------------------**/
/*
 * Description:
 * Initializing Stepper Motor
 */
void Stepper_Motor_init();

/*
 * Description:
 * Step the motor in a given direction
 */
void stepper_rotate(Stepper_Motor_State direction, sint8 angle,sint8 current_angle);

/**-------------------------END-------------------------------------**/
#endif /* HAL_HEADER_STEPPER_MOTOR_H_ */

