/******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: DcMotor.h
 *
 * Description: types for AVR
 *
 * Date Created: 3/10/2022
 *
 * Author: Moustafa Ahmed
 *
 *******************************************************************************/

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

/**-------------------------INCLUDES Section------------------------**/

#include "std_types.h"

/**-------------------------Definitions & Config Section------------**/

/* Modifiable Definitions*/
#define DC_MOTOR_IN1_OUTPUT_PORT_ID 	PORTA_ID
#define DC_MOTOR_IN2_OUTPUT_PORT_ID		PORTA_ID
#define DC_MOTOR_EN_PORT_ID				PORTB_ID
#define L293D_IN1_ID			 		PIN1_ID
#define L293D_IN2_ID 					PIN2_ID
#define L293D_EN1_ID 					PIN3_ID

/**-------------------------Enum Section----------------------------**/

typedef enum
{
	ClockWise,Anti_ClockWise
}DcMotor_State;

/**-------------------------Function Dec. Section-------------------**/
/*
 * Description:
 * Initializing the PORTs direction
 */
void DCMotor_init();
/*----------------------------------------------------------------------------*/

/*
 * Description:
 * Controlling the Speed and Rotation Direction of the motor
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed);
/*----------------------------------------------------------------------------*/

/*
 * Description:
 * Disabling the Motor's driver
 */
void DCMotor_stop();

/**-------------------------END-------------------------------------**/

#endif /* DCMOTOR_H_ */
