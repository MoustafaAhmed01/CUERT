 /******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: std_types.h
 *
 * Description: types for AVR
 *
 * Date Created: 20/9/2022
 *
 * Author: Moustafa Ahmed
 *
 *******************************************************************************/

#ifndef LIBRARIES_STD_TYPES_H_
#define LIBRARIES_STD_TYPES_H_

/*-------------------------Type Define Section------------------------*/
typedef unsigned char         uint8;          /*           0 .. 255              */
typedef signed char           sint8;          /*        -128 .. +127             */
typedef unsigned short        uint16;         /*           0 .. 65535            */
typedef signed short          sint16;         /*      -32768 .. +32767           */
typedef unsigned long         uint32;         /*           0 .. 4294967295       */
typedef signed long           sint32;         /* -2147483648 .. +2147483647      */
typedef unsigned long long    uint64;         /*       0 .. 18446744073709551615  */
typedef signed long long      sint64;         /* -9223372036854775808 .. 9223372036854775807 */
typedef float                 float32;
typedef double                float64;

/*-------------------------Define Section-----------------------------*/

#define SET_BIT(REG,BIT_NUM) 		(REG=REG|(1<<BIT_NUM))   	 /* Add ONE to this bit */
#define CLEAR_BIT(REG,BIT_NUM) 		(REG=REG&(~(1<<BIT_NUM))) /* Add ZERO to this bit */

#define GET_BIT(REG,BIT) ( ( REG & (1<<BIT) ) >> BIT )

#define TOGGLE_BIT(REG,BIT_NUM) 	(REG^=(1<<BIT_NUM))		 					/* Toggle Pin */
#define ROR(REG,BIT_NUM) (REG = 	(REG>>BIT_NUM) | (REG<<8-BIT_NUM)) 			/* Rotate right */
#define ROL(REG,BIT_NUM) (REG = 	( REG<< BIT_NUM) | (REG>>(8 - BIT_NUM))) 	/* Rotate Left */

#define BIT_IS_SET(REG,BIT_NUM) 	(REG&(1<<BIT_NUM)) 		/* Check if a specific bit is set in Register */
#define BIT_IS_CLEAR(REG,BIT_NUM) 	(!(REG&(1<<BIT_NUM))) /* Check if a specific bit is ZERO in Register */

#define NULL_PTR    				((void*)0)

/*-------------------------Boolean Section-----------------------------*/

/* Boolean Data Type */
typedef unsigned char boolean;

/* Boolean Values */
#ifndef FALSE
#define FALSE      			(0u)
#endif
#ifndef TRUE
#define TRUE        		(1u)
#endif

#define LOGIC_HIGH        	(1u)
#define LOGIC_LOW         	(0u)

/*-----------------------------END-----------------------------------*/
#endif /* LIBRARIES_STD_TYPES_H_ */
