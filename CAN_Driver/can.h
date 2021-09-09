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
#include "Compiler.h"
/*******************************************************************************
*****************************PREPRPCESSOR MACROS********************************
*******************************************************************************/
#define PORTA_ID											 (0U)
#define PORTB_ID											 (1U)
#define PORTE_ID											 (4U)
#define PORTF_ID											 (5U)
#define CAN_PMC_1											 (3U)
#define CAN_PMC_2											 (8U)
#define SHIFT_FACTOR  								 (4U)
#define UNLOCK_VALUE  								 (0x4C4F434B)
#define INIT_BIT										 	 (0U)
#define CFG_EN_BIT										 (6U)
#define PRESCALER_CLEAR 							 (0xFFFFFF10)
#define INTERFACE_RAM_BIT	  					 (7U)
#define NUMBER_OF_MESSAGES  					 (32U)
#define MESSAGE_EXT_BIT								 (14U)
#define MESSAGE_EXT_FILTER_ENABLE_BIT	 (15U)
#define MESSAGE_TYPE_BIT							 (13U)
#define MESSAGE_TYPE_FILTER_ENABLE_BIT (14U)
#define MESSAGE_VALID_BIT							 (15U)
#define MESSAGE_REMOTE_ENABLE_BIT			 (9U)
#define MESSAGE_FILTERING_ENABLE			 (12U)
#define MESSAGE_TRANSMIT_REQUEST			 (2U)
#define TRANSMISSION_BUSY_BIT					 (15U)
#define ONE_MESSAGE_BUFFER_BIT				 (7U)
/*******************************************************************************
****************************TYPES DECLARATION***********************************
*******************************************************************************/

typedef enum{
	CAN0,CAN1
}CAN_ID;
typedef enum{
	PF0=0 , PA0=0 , PA1=1 , PF3=3 , PB4=4 , PE4=4 , PB5=5 , PE5=5
}PIN_ID;
typedef enum{
	REMOTE_FRAME,ONE_BYTE,TWO_BYTES,THREE_BYTES,FOUR_BYTES,FIVE_BYTES,SIX_BYTES,SEVEM_BYTES,EIGHT_BYTES
}DATA_SIZE;
typedef enum{
	RECEIVE , TRANSMIT
}MESSAGE_TYPE;
/* Message Structure Configuration */
typedef struct{
	/* ID extender enable */
	uint8 message_id_ext_enable;
	/* ID extender filter enable */
	uint8 message_id_ext_filter_enable;
	/* Message direction */
	uint8 message_type;
	/* Messge direction filter enable */
	uint8 message_type_filter_enable;
	/* ID of the message */
	uint32 message_id;
	/* ID mask filtering*/
	uint32 message_id_filter;
	/* Message validity */
	uint8 message_valid;
	/* Message Remote frame enable*/
	uint8 message_remote_enable;
	/* Message filtering Enable*/
	uint8 message_filter_enable;
	/* Data size of the payload*/
	uint8 message_payload;
	
}CAN_Message_Config;
/* Configureation structure passed to the init function */
typedef struct
{
	CAN_ID can_id;
	PIN_ID pin_id_rx;
	PIN_ID pin_id_tx;
	uint8	 prescaler;
	uint8  prescaler_ext;
	CAN_Message_Config message[NUMBER_OF_MESSAGES];
	
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
