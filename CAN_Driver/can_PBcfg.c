/******************************************************************************
*
* Module:CAN
*
* File Name: can_pbcfg.c
*
* Description: Source file for Post build configurations of can module. 
*
* Author: Esmail Ahmed
*
*******************************************************************************/

#include "can.h"

/* PB structure used with SPI_Init API */
const CAN_ConfigType CAN_Configuration =
{
	CAN0,
	PA0,
	PA1,
	3,
	1,
	1,
	5,
	/* Message 1 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_ON,		 /* Message valid*/	
	
	/* Message 2 */
	0x2,			 /* Message ID */
	0x2,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	RECEIVE,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_ON,    /* Message remote disabled*/
	FOUR_BYTES,/* Message payload */
	STD_ON,		 /* Message valid*/
	
	/* Message 3 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 4 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 5 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 6 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 7 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 8 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 9 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 10 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 11 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 12 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 13 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 14 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 15 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 16 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 17 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 18 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 19 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 20 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 21 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 22 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 23 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 24 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 25 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 26 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 27 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 28 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 29 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 30 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 31 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF,	 /* Message valid*/
	
	/* Message 32 */
	0x1,			 /* Message ID */
	0x1,			 /* Message ID filter*/
  STD_OFF,	 /* Message ID ext disabled */
	STD_OFF,	 /* Message ID ext filter disabled */ 
	TRANSMIT,	 /* Message Type */
	STD_ON,		 /* Message Type filter enable */
	STD_ON,		 /* Message filter enable */
	STD_OFF,   /* Message remote disabled*/
	TWO_BYTES, /* Message payload */
	STD_OFF	   /* Message valid*/
};
	

