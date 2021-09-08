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
#define PORTA_ID						(0U)
#define PORTB_ID						(1U)
#define PORTE_ID						(4U)
#define PORTF_ID						(5U)
#define CAN_PMC_1						(3U)
#define CAN_PMC_2						(8U)
#define SHIFT_FACTOR  			(4U)
#define UNLOCK_VALUE  			(0x4C4F434B)
#define INIT_BIT						(0U)
#define CFG_EN_BIT					(6U)
#define PRESCALER_CLEAR 		(0xFFFFFF10)
#define INTERFACE_RAM_BIT	  (7U)
#define NUMBER_OF_MESSAGES  (32U)
#define MESSAGE_ID_OFFSET		(1U)
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
	ONE_BYTE = 1,TWO_BYTES,THREE_BYTES,FOUR_BYTES,FIVE_BYTES,SIX_BYTES,SEVEM_BYTES,EIGHT_BYTES
}DATA_SIZE;
/* Message Structure Configuration */
typedef struct{
	/* Transfer IDMASK + DIR + MXTD of the message object into the Interface registers or not. */
	uint8 access_mask_bits;
	/* Transfer ID + DIR + XTD + MSGVAL of the message object into the Interface registers or not.*/
	uint8 access_arbit_bits;
	/* Transfer the control bits into the interface registers. */
	uint8 access_control_bits;
	/* Data Transmission request between message buffer and interface.*/
	uint8 new_data_request;
	/* Transmit the bytes(0,1,2,3) between message object and interface.*/
	uint8 data_0_to_3_bytes;
	/* Transmit the bytes(4,5,6,7) between message object and interface.*/
	uint8 data_4_to_7_bytes;
	/*The extended bit is used for acceptance filtering or not. */
	uint8 extender_acceptance;
	/*The direction bit is used for acceptance filtering or not. */
	uint8 direction_acceptance;
	/* 11-bit ID identifier value*/
	uint16 id_acceptance;
	/* Extention of 11-bit ID identifier value*/
	uint16 id_ext_acceptance;
	/* The message id */
	uint16 id;
	/* The message id ext*/
	uint16 id_ext;
	/* Specify if message is valid or ignored */
	uint8 message_validity;
	/* Id ext enable*/
	uint8 id_ext_enable;
	/* Direction of the ID is transmitted or received*/
	uint8 direction;
	/* Enable Acceptance filtering */
	uint8 acceptance_enable;
	/* Automatic transmission enable */
	uint8 auto_trans_enable;
	/* Number of Data Bytes*/
	uint8 data_bytes;
	
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
