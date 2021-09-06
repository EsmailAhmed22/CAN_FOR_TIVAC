/******************************************************************************
*
* Module:CAN
*
* File Name: can.h
*
* Description: Header file for TM4C123GH6PM Microcontroller - CAN Driver
*
* Author: Esmail Ahmed
*
*******************************************************************************/

#ifndef CAN_H
#define CAN_H

#include "Std_Types.h"
#include "Common_Macros.h"
#include "can_registers.h"

/*******************************************************************************
*****************************PREPRPCESSOR MACROS********************************
*******************************************************************************/

/*******************************************************************************
****************************TYPES DECLARATION***********************************
*******************************************************************************/


/* Configureation structure passed to the init function */
typedef struct
{
	
}CAN_ConfigType;

/*******************************************************************************
*****************************FUNCTIONS PROTOTYPE********************************
*******************************************************************************/

/* This function is responsible for initializing the I2C */
void CAN_init(const CAN_ConfigType *a_config_Ptr);


/*This function is responsible for saving the address that will be called*/
void CAN_callBackAdress(void(*a_Func_Read_Ptr)(void),void(*a_Func_Write_Ptr)(void));

extern const CAN_ConfigType I2C_Configuration;
#endif /* CAN_H */
