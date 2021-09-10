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
/* Define Port IDs */
#define PORTA_ID											 (0U)
#define PORTB_ID											 (1U)
#define PORTE_ID											 (4U)
#define PORTF_ID											 (5U)
/* Define PMC different values used with GPIO_CTL */
#define CAN_PMC_1											 (3U)
#define CAN_PMC_2											 (8U)
#define SHIFT_FACTOR  								 (4U)					/*Factor used to shift PMC value half byte */
#define UNLOCK_VALUE  								 (0x4C4F434B)	/* Used to unlock PF0 in case used */
#define INIT_BIT										 	 (0U)					/* CAN initialization bit */
#define CFG_EN_BIT										 (6U)					/* BIT Timing enable bit */
#define INTERFACE_RAM_BIT	  					 (7U)					/* Write not Read bit to switch transfer direction*/
#define NUMBER_OF_MESSAGES  					 (32U)				/* Number of Messages that RAM can take */
#define MESSAGE_EXT_BIT								 (14U)				/* ID_Extension bit enable*/
#define MESSAGE_EXT_FILTER_ENABLE_BIT	 (15U)				/* ID_Extension filter bit enable*/
#define MESSAGE_TYPE_BIT							 (13U)				/* ID_Type bit select*/
#define MESSAGE_TYPE_FILTER_ENABLE_BIT (14U)				/* ID_Type bit filter enable*/
#define MESSAGE_VALID_BIT							 (15U)				/* Message valid bit enable*/
#define MESSAGE_REMOTE_ENABLE_BIT			 (9U)					/* Message remote bit enable*/
#define MESSAGE_FILTERING_ENABLE			 (12U)				/* Message filtering bit enable*/
#define MESSAGE_TRANSMIT_REQUEST			 (2U)					/* Message Transmit Request bit*/
#define TRANSMISSION_BUSY_BIT					 (15U)				/* Message Busy bit for polling*/
#define ONE_MESSAGE_BUFFER_BIT				 (7U)					/* Bit to make buffer for one message*/
/* Definitions used to update data */
#define CAN_COMM_MASK_RESET						 (0xFFFFFF08)
#define CAN_COMM_MASK_8BYTES_STORE		 (0xFFFFFF87)
#define SHIFT_ONE_BYTE								 (8U)					/*Factor used to shift Byte value one byte */
/* Defintions for receiving message */
#define RECEIVE_HANDLING_VALUE				 (0x007F)
#define NEW_DATA_FLAG									 (15U)
#define DATA_SIZE_MASK								 (0x0000000F)
/* Definitions for BIT Timing */
#define TIME_SEG1_SHIFT								 (8U)
#define TIME_SEG2_SHIFT								 (12U)
#define SYNC_JUMP_WIDTH_SHIFT					 (6U)
#define PRESCALER_EXT_SHIFT						 (5U)
/*******************************************************************************
****************************TYPES DECLARATION***********************************
*******************************************************************************/

/* Enum used to choose between CANs */
typedef enum{
	CAN0,CAN1
}CAN_ID;

/* Enum used to choose between PINs */
typedef enum{
	PF0=0 , PA0=0 , PA1=1 , PF3=3 , PB4=4 , PE4=4 , PB5=5 , PE5=5
}PIN_ID;

/* Enum used to choose number of Data bytes */
typedef enum{
	REMOTE_FRAME,ONE_BYTE,TWO_BYTES,THREE_BYTES,FOUR_BYTES,FIVE_BYTES,SIX_BYTES,SEVEN_BYTES,EIGHT_BYTES
}DATA_SIZE;

/* Enum used to choose message type */
typedef enum{
	RECEIVE , TRANSMIT
}MESSAGE_TYPE;

/* Message Structure Configuration */
typedef struct{
	/* ID of the message */
	uint32 message_id;
	/* ID mask filtering*/
	uint32 message_id_filter;
	/* ID extender enable */
	uint8 message_id_ext_enable;
	/* ID extender filter enable */
	uint8 message_id_ext_filter_enable;
	/* Message direction */
	uint8 message_type;
	/* Messge direction filter enable */
	uint8 message_type_filter_enable;
	/* Message filtering Enable*/
	uint8 message_filter_enable;
	/* Message Remote frame enable*/
	uint8 message_remote_enable;
	/* Data size of the payload*/
	uint8 message_payload;
	/* Message validity */
	uint8 message_valid;

	
}CAN_Message_Config;
/* Configureation structure passed to the init function */
typedef struct
{
	/* CAN used CAN0 or CAN1 */
	CAN_ID can_id;
	/* PIN For the CAN-Rx */
	PIN_ID pin_id_rx;
	/* PIN For the CAN-Tx */
	PIN_ID pin_id_tx;
	
	/* BIT TIMING Variables*/
	uint8 segment_before_sampling;
	uint8 segment_after_sampling;
	uint8 sync_jump_width;
	uint16 prescaler;
	
	/* Array of structuers for all can messages */
	CAN_Message_Config message[NUMBER_OF_MESSAGES];
	
}CAN_ConfigType;

/*******************************************************************************
*****************************FUNCTIONS PROTOTYPE********************************
*******************************************************************************/

/* This function is responsible for initializing the I2C */
void CAN_Init(const CAN_ConfigType *a_config_Ptr);

/* This function is responsible for Updating data */
void CAN_Data_Update(uint8 a_message_number , uint8 * a_payload , uint8 a_can_id);

/* This function is responsible for Sending data frame and remote frame */
void CAN_Send_Frame(uint8 a_message_number,uint8 a_can_id);

/* This function to check wether their is newdata */
uint8 CAN_Is_Message_Received(uint8 a_message_number,uint8 a_can_id);

/* This function responsbile for receiving data */
void CAN_Received_Message(uint8 a_message_number,uint8 a_can_id);


extern const CAN_ConfigType CAN_Configuration;
extern uint8 g_received_data[8];

#endif /* CAN_H */
