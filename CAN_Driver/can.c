/******************************************************************************
*
* Module:CAN
*
* File Name: can.h
*
* Description: Source file for can module.
*
* Author: Esmail Ahmed
*
*******************************************************************************/
#include "can_registers.h"
#include "can.h"

/*******************************************************************************
 *****************************GLOBAL VARIABLES**********************************
 *******************************************************************************/
/* Global pointer to hold CAN0 configurations*/
static const CAN_ConfigType *g_can0_config_Ptr = NULL_PTR;
/* Global pointer to hold CAN1 configurations*/
static const CAN_ConfigType *g_can1_config_Ptr = NULL_PTR;
/* Global array to hold received data */
uint8 g_received_data[8];

/*******************************************************************************
*************************FUNCTIONS DEFINITIONS**********************************
*******************************************************************************/

/********************************************************************************
*[Function Name]: CAN_init.
*[Description]  : This function is responsible for initializing the CAN.
*[in]		: CAN_ConfigType *a_config_Ptr:pointer contains address of structure.
*[out]		: None.
*[in/out]	: None.
*[Returns]	: None.
*********************************************************************************/
void CAN_Init(const CAN_ConfigType *a_config_Ptr){
	
	/* Pointer to point at the Base Address of the CAN */ 
  volatile uint32 * CAN_Ptr = NULL_PTR;
	/* Pointer to messages */
	const CAN_Message_Config * messages = NULL_PTR;
   /* Delay to give port time to be enabled */
  volatile unsigned long delay = 0;
	/* See which CAN to configure */
	
	if(a_config_Ptr->can_id == CAN0){
		
		/* Put Pointer in a global pointer */
	  g_can0_config_Ptr = a_config_Ptr;
		/* Initialize CAN CLOCK */ 
		SET_BIT(CAN_ClOCK_REGISTER,CAN0);

  /*******************GPIO INITIALIZATION******************/	
		if(a_config_Ptr->pin_id_rx == PF0)
		{
			/* Unlock PF0 before use */
			*(GPIO_PORTF_BASE_ADDRESS+PORT_LOCK_REG_OFFSET)= UNLOCK_VALUE;
			SET_BIT(*(GPIO_PORTF_BASE_ADDRESS+PORT_COMMIT_REG_OFFSET),PF0);
		 
		 /* For Rx PIN:
		 * Initialize required port or ports 
		 * Select Alternative Function
		 * Set CTML value
		 * Enable Digital
		 * Set Direction
		 */
			SET_BIT(PORT_ClOCK_REGISTER,PORTF_ID);
			delay=PORT_ClOCK_REGISTER;
			SET_BIT(*(GPIO_PORTF_BASE_ADDRESS+PORT_ALT_FUNC_REG_OFFSET),PF0);
			*(GPIO_PORTF_BASE_ADDRESS+PORT_CTL_REG_OFFSET) &= 0xFFFFFFF0;
			*(GPIO_PORTF_BASE_ADDRESS+PORT_CTL_REG_OFFSET) |= CAN_PMC_1;
			SET_BIT(*(GPIO_PORTF_BASE_ADDRESS+PORT_DIGITAL_ENABLE_REG_OFFSET),PF0);
			CLEAR_BIT(*(GPIO_PORTF_BASE_ADDRESS+PORT_DIR_REG_OFFSET),PF0);
		}
		else if(a_config_Ptr->pin_id_rx == PB4)
		{
			SET_BIT(PORT_ClOCK_REGISTER,PORTB_ID);
			SET_BIT(*(GPIO_PORTB_BASE_ADDRESS+PORT_ALT_FUNC_REG_OFFSET),PB4);
			*(GPIO_PORTB_BASE_ADDRESS+PORT_CTL_REG_OFFSET) &= 0xFFF0FFFF;
			*(GPIO_PORTB_BASE_ADDRESS+PORT_CTL_REG_OFFSET) |= (CAN_PMC_2 << (PB4 * SHIFT_FACTOR));
			SET_BIT(*(GPIO_PORTB_BASE_ADDRESS+PORT_DIGITAL_ENABLE_REG_OFFSET),PB4);
			CLEAR_BIT(*(GPIO_PORTB_BASE_ADDRESS+PORT_DIR_REG_OFFSET),PB4);
		}
		else if(a_config_Ptr->pin_id_rx == PE4)
		{
			SET_BIT(PORT_ClOCK_REGISTER,PORTE_ID);
			SET_BIT(*(GPIO_PORTE_BASE_ADDRESS+PORT_ALT_FUNC_REG_OFFSET),PE4);
			*(GPIO_PORTE_BASE_ADDRESS+PORT_CTL_REG_OFFSET) &= 0xFFF0FFFF;
			*(GPIO_PORTE_BASE_ADDRESS+PORT_CTL_REG_OFFSET) = (CAN_PMC_2 << (PE4 * SHIFT_FACTOR));
			SET_BIT(*(GPIO_PORTE_BASE_ADDRESS+PORT_DIGITAL_ENABLE_REG_OFFSET),PE4);
			CLEAR_BIT(*(GPIO_PORTE_BASE_ADDRESS+PORT_DIR_REG_OFFSET),PE4);
		}
		else
		{
			/* DO NOTHING */
		}
		
		/* For Tx PIN:
		 * Initialize required port or ports 
		 * Select Alternative Function
		 * Set CTML value
		 * Enable Digital
		 * Set Direction
		*/
		if(a_config_Ptr->pin_id_tx == PF3)
		{
			SET_BIT(PORT_ClOCK_REGISTER,PORTF_ID);
			SET_BIT(*(GPIO_PORTF_BASE_ADDRESS+PORT_ALT_FUNC_REG_OFFSET),PF3);
			*(GPIO_PORTF_BASE_ADDRESS+PORT_CTL_REG_OFFSET) &= 0xFFFF0FFF;
			*(GPIO_PORTF_BASE_ADDRESS+PORT_CTL_REG_OFFSET) = (CAN_PMC_1 << (PF3 * SHIFT_FACTOR));
			SET_BIT(*(GPIO_PORTF_BASE_ADDRESS+PORT_DIGITAL_ENABLE_REG_OFFSET),PF3);
			SET_BIT(*(GPIO_PORTF_BASE_ADDRESS+PORT_DIR_REG_OFFSET),PF3);
		}
		else if(a_config_Ptr->pin_id_tx == PB5)
		{
			SET_BIT(PORT_ClOCK_REGISTER,PORTB_ID);
			SET_BIT(*(GPIO_PORTB_BASE_ADDRESS+PORT_ALT_FUNC_REG_OFFSET),PB5);
			*(GPIO_PORTB_BASE_ADDRESS+PORT_CTL_REG_OFFSET) &= 0xFF0FFFFF;
			*(GPIO_PORTB_BASE_ADDRESS+PORT_CTL_REG_OFFSET) = (CAN_PMC_2 << (PB5 * SHIFT_FACTOR));
			SET_BIT(*(GPIO_PORTB_BASE_ADDRESS+PORT_DIGITAL_ENABLE_REG_OFFSET),PB5);
			SET_BIT(*(GPIO_PORTB_BASE_ADDRESS+PORT_DIR_REG_OFFSET),PB5);
		}
		else if(a_config_Ptr->pin_id_tx == PE5)
		{
			SET_BIT(PORT_ClOCK_REGISTER,PORTE_ID);
			SET_BIT(*(GPIO_PORTE_BASE_ADDRESS+PORT_ALT_FUNC_REG_OFFSET),PE5);
			*(GPIO_PORTE_BASE_ADDRESS+PORT_CTL_REG_OFFSET) &= 0xFF0FFFFF;
			*(GPIO_PORTE_BASE_ADDRESS+PORT_CTL_REG_OFFSET) = (CAN_PMC_2 << (PE5 * SHIFT_FACTOR));
			SET_BIT(*(GPIO_PORTE_BASE_ADDRESS+PORT_DIGITAL_ENABLE_REG_OFFSET),PE5);
			SET_BIT(*(GPIO_PORTE_BASE_ADDRESS+PORT_DIR_REG_OFFSET),PE5);
		}
		else
		{
			/* DO NOTHING */
		}
		
	}
	else if (a_config_Ptr->can_id == CAN1){
		
		/* Put Pointer in a global pointer */
	  g_can1_config_Ptr = a_config_Ptr;
		/* Initialize CAN CLOCK */ 
		SET_BIT(CAN_ClOCK_REGISTER,CAN1);
	  
		/*******************GPIO INITIALIZATION******************/	
		
		/* For Rx PIN:
		 * Initialize required port or ports 
		 * Select Alternative Function
		 * Set CTML value
		 * Enable Digital
		 * Set Direction
		*/
		if(a_config_Ptr->pin_id_rx == PA0)
		{			
			SET_BIT(PORT_ClOCK_REGISTER,PORTA_ID);
			SET_BIT(*(GPIO_PORTA_BASE_ADDRESS+PORT_ALT_FUNC_REG_OFFSET),PA0);
			*(GPIO_PORTA_BASE_ADDRESS+PORT_CTL_REG_OFFSET) &= 0xFFFFFFF0;
			*(GPIO_PORTA_BASE_ADDRESS+PORT_CTL_REG_OFFSET) = CAN_PMC_2;
			SET_BIT(*(GPIO_PORTA_BASE_ADDRESS+PORT_DIGITAL_ENABLE_REG_OFFSET),PA0);
			CLEAR_BIT(*(GPIO_PORTA_BASE_ADDRESS+PORT_DIR_REG_OFFSET),PA0);
		}
	  
		/* For Tx PIN:
		 * Initialize required port or ports 
		 * Select Alternative Function
		 * Set CTML value
		 * Enable Digital
		 * Set Direction
		*/
		if(a_config_Ptr->pin_id_tx == PA1)
		{			
			SET_BIT(PORT_ClOCK_REGISTER,PORTA_ID);
			SET_BIT(*(GPIO_PORTA_BASE_ADDRESS+PORT_ALT_FUNC_REG_OFFSET),PA1);
			*(GPIO_PORTA_BASE_ADDRESS+PORT_CTL_REG_OFFSET) &= 0xFFFFFF0F;
			*(GPIO_PORTA_BASE_ADDRESS+PORT_CTL_REG_OFFSET) = (CAN_PMC_2 << (PA1 * SHIFT_FACTOR));
			SET_BIT(*(GPIO_PORTA_BASE_ADDRESS+PORT_DIGITAL_ENABLE_REG_OFFSET),PA1);
			SET_BIT(*(GPIO_PORTA_BASE_ADDRESS+PORT_DIR_REG_OFFSET),PA1);
		}
	}
	else{
		/* NOTHING TO DO SO RETURN*/
		return;
	}
  
	/* Switch case to select the required port */
  switch(a_config_Ptr->can_id)
  {
     case CAN0: CAN_Ptr = &CAN_0_BASE_ADDRESS;	/* CAN0 is used */
		break;
     case CAN1: CAN_Ptr = &CAN_1_BASE_ADDRESS;	/* CAN1 is used */
		break;
  }
	
	/*********************** Initialize state********************************/
	SET_BIT(*(CAN_Ptr + CAN_CONTROL_REG),INIT_BIT);	/* To disable all transfers */
	SET_BIT(*(CAN_Ptr + CAN_CONTROL_REG),CFG_EN_BIT); /* To access CANBIT regs */
	
	/**********************1-BIT TIMING Setting******************************/
	*(CAN_Ptr + CAN_BIT_TIMING_REG) = STD_OFF;  																																				/* Reset Bit Timing register */
	*(CAN_Ptr + CAN_BIT_TIMING_REG) = a_config_Ptr->prescaler-1; 																												/* Set prescaler Bits */
	*(CAN_Ptr + CAN_PRESCALER_EXT_REG) = ((a_config_Ptr->prescaler-1) >> PRESCALER_EXT_SHIFT);   												/* Set prescaler Bits Extension */
	*(CAN_Ptr + CAN_BIT_TIMING_REG) |= (uint32)((a_config_Ptr->sync_jump_width-1) << SYNC_JUMP_WIDTH_SHIFT);  		      /* Set Synchoranization Jump Width */
	*(CAN_Ptr + CAN_BIT_TIMING_REG) |= (uint32)((a_config_Ptr->segment_before_sampling-1) << TIME_SEG1_SHIFT); 				  /* Set Time Segment Befor Sample Point */
	*(CAN_Ptr + CAN_BIT_TIMING_REG) |= (uint32)((a_config_Ptr->segment_after_sampling-1) << TIME_SEG2_SHIFT); 					/* Set Time Segment After Sample Point */
	CLEAR_BIT(*(CAN_Ptr + CAN_CONTROL_REG),CFG_EN_BIT); /* To lock CANBIT regs */
	
	/**********************2-Messages Configuration***************************/
	messages = a_config_Ptr->message;
	
	/* Transfer from Interface to RAM */
	SET_BIT(*(CAN_Ptr + CAN_IF1_COMM_MASK_REG),INTERFACE_RAM_BIT);
	
	/* Transfer of Control ,arbitiration and mask data enable*/
	*(CAN_Ptr + CAN_IF1_COMM_MASK_REG) |= 0x00000070;
	
	/* Make buffer for just one message*/
	SET_BIT(*(CAN_Ptr + CAN_IF1_MSG_CTL_REG),ONE_MESSAGE_BUFFER_BIT);
	
	for(uint8 messages_counter = 0;messages_counter < NUMBER_OF_MESSAGES;messages_counter++)
	{
		/* Check if ID have extension or not */
		if(messages[messages_counter].message_id_ext_enable == STD_ON)
		{
			SET_BIT(*(CAN_Ptr + CAN_IF1_ARB2_REG),MESSAGE_EXT_BIT);
			*(CAN_Ptr + CAN_IF1_ARB1_REG) = (uint16) messages[messages_counter].message_id; /* Store first 16 bits of ID */
			*(CAN_Ptr + CAN_IF1_ARB2_REG) = (messages[messages_counter].message_id >> 16); /* Store ID_ext 13 bits */
			
			/* Check if ID_ext is used in Filtering */
			if(messages[messages_counter].message_id_ext_filter_enable == STD_ON)
			{
				SET_BIT(*(CAN_Ptr + CAN_IF1_MASK2_REG),MESSAGE_EXT_FILTER_ENABLE_BIT);
				*(CAN_Ptr + CAN_IF1_MASK1_REG) = (uint16) messages[messages_counter].message_id_filter; /* Store first 16 bits of Mask */
				*(CAN_Ptr + CAN_IF1_MASK2_REG) = (messages[messages_counter].message_id_filter >> 16); /* Store Mask_ext 13 bits */
			}
			else
			{
				/* Do Nothing */
			}
		}
		else if(messages[messages_counter].message_id_ext_enable == STD_OFF)
		{
			*(CAN_Ptr + CAN_IF1_ARB2_REG) = (messages[messages_counter].message_id << 2);/* Store ID */
			*(CAN_Ptr + CAN_IF1_MASK2_REG) = (messages[messages_counter].message_id_filter << 2);/* Store MASK */
		}
		else
		{
			/* Do Nothing */
		}
		
		/* Select Message Type */
		if(messages[messages_counter].message_type == TRANSMIT)
		{
			CLEAR_BIT(*(CAN_Ptr + CAN_IF1_ARB2_REG),MESSAGE_TYPE_BIT);	/* Transmit message */
		}
		else if(messages[messages_counter].message_type == RECEIVE)
		{
			SET_BIT(*(CAN_Ptr + CAN_IF1_ARB2_REG),MESSAGE_TYPE_BIT);		/* Receive message*/
		}
		else
		{
			/* DO NOTHING */
		}
		
		/* See if Message Type is used in filtering*/
		if(messages[messages_counter].message_type_filter_enable == STD_ON)
		{
			SET_BIT(*(CAN_Ptr + CAN_IF1_MASK2_REG),MESSAGE_TYPE_FILTER_ENABLE_BIT); /* Message Type is used*/
		}
		else if(messages[messages_counter].message_type_filter_enable == STD_OFF)
		{
			CLEAR_BIT(*(CAN_Ptr + CAN_IF1_MASK2_REG),MESSAGE_TYPE_FILTER_ENABLE_BIT); /* Message Type is not used */
		}
		else
		{
			/* DO NOTHING */
		}		
		
		/* See if Message is valid*/
		if(messages[messages_counter].message_valid == STD_ON)
		{
			SET_BIT(*(CAN_Ptr + CAN_IF1_ARB2_REG),MESSAGE_VALID_BIT); /* Message is valid */
		}
		else if(messages[messages_counter].message_valid == STD_OFF)
		{
			CLEAR_BIT(*(CAN_Ptr + CAN_IF1_MASK2_REG),MESSAGE_VALID_BIT); /* Message is not valid */
		}
		else
		{
			/* DO NOTHING */
		}
		
		/* See if Message is used with remote frame*/
		if(messages[messages_counter].message_remote_enable == STD_ON)
		{
			SET_BIT(*(CAN_Ptr + CAN_IF1_MSG_CTL_REG),MESSAGE_REMOTE_ENABLE_BIT); /* Message is used with remote frame */
		}
		else if(messages[messages_counter].message_remote_enable == STD_OFF)
		{
			CLEAR_BIT(*(CAN_Ptr + CAN_IF1_MSG_CTL_REG),MESSAGE_REMOTE_ENABLE_BIT); /* Message is not used with remote frame */
		}
		else
		{
			/* DO NOTHING */
		}
		
		/* Enable and disable Filtering*/
		if(messages[messages_counter].message_filter_enable == STD_ON)
		{
			SET_BIT(*(CAN_Ptr + CAN_IF1_MSG_CTL_REG),MESSAGE_FILTERING_ENABLE);
		}
		else if(messages[messages_counter].message_filter_enable == STD_OFF)
		{
			CLEAR_BIT(*(CAN_Ptr + CAN_IF1_MSG_CTL_REG),MESSAGE_FILTERING_ENABLE);
		}
		else
		{
			/* DO NOTHING */
		}
		
		/* DATA Length of the Message */
		*(CAN_Ptr + CAN_IF1_MSG_CTL_REG) &= 0xFFFFFFF0; /* CLEAR Length spot */
		*(CAN_Ptr + CAN_IF1_MSG_CTL_REG) |= messages[messages_counter].message_payload;	/* SET Length */
		
		/* PUT Message number to transfer its data to RAM */
		*(CAN_Ptr + CAN_IF1_COMM_REQ_REG) = messages_counter + 1;
		
		/* PULL Transmission Request */
		SET_BIT(*(CAN_Ptr + CAN_IF1_COMM_MASK_REG),MESSAGE_TRANSMIT_REQUEST);
		
		/* Polling until transmission ends */
		while(BIT_IS_SET(*(CAN_Ptr + CAN_IF1_COMM_REQ_REG),TRANSMISSION_BUSY_BIT));	
	  
		/* Clear Transmission Request */
	  CLEAR_BIT(*(CAN_Ptr + CAN_IF1_COMM_MASK_REG),MESSAGE_TRANSMIT_REQUEST);
	}
	
	/*ENABLE CAN*/
	CLEAR_BIT(*(CAN_Ptr + CAN_CONTROL_REG),INIT_BIT);	/* To enable all transfers */
	CLEAR_BIT(*(CAN_Ptr + CAN_CONTROL_REG),CFG_EN_BIT); /* To not access CANBIT regs */
}


/********************************************************************************
*[Function Name]: CAN_Data_Update.
*[Description]  : This function is responsible for Updating data.
*[in]		: a_message_number : Contains the message number from 1 to 32.
*					* a_payload			 : Contains pointer to data we want to store.
*					a_can_id				 : Contains which can we are updating in CAN0 or CAN1.
*[out]		: None.
*[in/out]	: None.
*[Returns]	: None.
*********************************************************************************/
void CAN_Data_Update(uint8 a_message_number , uint8 * a_payload , uint8 a_can_id)
{
	/* Pointer to point at the Base Address of the CAN */ 
  volatile uint32 * CAN_Ptr = NULL_PTR;
	
	/* Pointer to global configuration required */
	const CAN_ConfigType *config_Ptr = NULL_PTR;
	
	/* Switch Case to choose which CAN is used */
	switch(a_can_id)
  {
     case CAN0: CAN_Ptr = &CAN_0_BASE_ADDRESS;
								config_Ptr = g_can0_config_Ptr;
		break;
     case CAN1: CAN_Ptr = &CAN_1_BASE_ADDRESS;
								config_Ptr = g_can1_config_Ptr;
		break;
  }
	
	/* Reset some bits of comm mask */
	*( CAN_Ptr + CAN_IF1_COMM_MASK_REG) &= CAN_COMM_MASK_RESET;
	
	/* Transfer of Control ,arbitiration and mask data Disable
	* Enable Transfer to RAM 
	* Enable 8 bytes transfer 
	*/
	*( CAN_Ptr + CAN_IF1_COMM_MASK_REG) |= CAN_COMM_MASK_8BYTES_STORE;
	
	a_message_number = a_message_number-1;	/* To match array */
	uint8 Bytes = config_Ptr->message[a_message_number].message_payload;/* Store number of bytes */
	
	/* Clear all Data interface registers */
	*( CAN_Ptr + CAN_IF1_DATA_A1)=0;
	*( CAN_Ptr + CAN_IF1_DATA_A2)=0;
	*( CAN_Ptr + CAN_IF1_DATA_B1)=0;
	*( CAN_Ptr + CAN_IF1_DATA_B2)=0;
	
	/* Fill the Data */
	while(Bytes){
		switch(Bytes)
		{
			case ONE_BYTE:  	*( CAN_Ptr + CAN_IF1_DATA_A1)|= a_payload[0];
			break;
			case TWO_BYTES:  	*( CAN_Ptr + CAN_IF1_DATA_A1)|=(uint16)(a_payload[1] << SHIFT_ONE_BYTE);
			break;
			case THREE_BYTES: *( CAN_Ptr + CAN_IF1_DATA_A2)|= a_payload[2];
			break;
			case FOUR_BYTES:  *( CAN_Ptr + CAN_IF1_DATA_A2)|=(uint16)(a_payload[3] << SHIFT_ONE_BYTE);
			break;
			case FIVE_BYTES:  *( CAN_Ptr + CAN_IF1_DATA_B1)|= a_payload[4];
			break;
			case SIX_BYTES:  	*( CAN_Ptr + CAN_IF1_DATA_B1)|=(uint16)(a_payload[5] << SHIFT_ONE_BYTE);
			break;
			case SEVEN_BYTES: *( CAN_Ptr + CAN_IF1_DATA_B2)|= a_payload[6];
			break;
			case EIGHT_BYTES: *( CAN_Ptr + CAN_IF1_DATA_B2)|=(uint16)(a_payload[7] << SHIFT_ONE_BYTE);
			break;
		}
		Bytes = Bytes - 1;
	}
	
	/* PUT Message number to transfer its data to RAM */
	*(CAN_Ptr + CAN_IF1_COMM_REQ_REG) = a_message_number + 1;
	
	/* PULL Transmission Request */
	SET_BIT(*(CAN_Ptr + CAN_IF1_COMM_MASK_REG),MESSAGE_TRANSMIT_REQUEST);
	
	/* Polling until transmission ends */
	while(BIT_IS_SET(*(CAN_Ptr + CAN_IF1_COMM_REQ_REG),TRANSMISSION_BUSY_BIT));	
	
	/* Clear Transmission Request */
	CLEAR_BIT(*(CAN_Ptr + CAN_IF1_COMM_MASK_REG),MESSAGE_TRANSMIT_REQUEST);
}

/********************************************************************************
*[Function Name]: CAN_Send_Frame.
*[Description]  : This function is responsible for Sending data frame and remote frame.
*[in]		: a_message_number : Contains the message number from 1 to 32.
*					a_can_id				 : Contains which can we are updating in CAN0 or CAN1.
*[out]		: None.
*[in/out]	: None.
*[Returns]	: None.
*********************************************************************************/
void CAN_Send_Frame(uint8 a_message_number,uint8 a_can_id)
{
	/* Pointer to point at the Base Address of the CAN */ 
  volatile uint32 * CAN_Ptr = NULL_PTR;
	
	/* Pointer to global configuration required */
	const CAN_ConfigType *config_Ptr = NULL_PTR;
	
	/* Switch Case to choose which CAN is used */
	switch(a_can_id)
  {
     case CAN0: CAN_Ptr = &CAN_0_BASE_ADDRESS;
								config_Ptr = g_can0_config_Ptr;
		break;
     case CAN1: CAN_Ptr = &CAN_1_BASE_ADDRESS;
								config_Ptr = g_can1_config_Ptr;
		break;
  }
	
	/* Set transmission from RAM to interace */
	CLEAR_BIT(*(CAN_Ptr + CAN_IF1_COMM_MASK_REG),INTERFACE_RAM_BIT);
	
	/* PUT Message number to transfer its data to RAM */
	*(CAN_Ptr + CAN_IF1_COMM_REQ_REG) = a_message_number ;
	
	/* PULL Transmission Request */
	SET_BIT(*(CAN_Ptr + CAN_IF1_COMM_MASK_REG),MESSAGE_TRANSMIT_REQUEST);
	
	/* Polling until transmission ends */
	while(BIT_IS_SET(*(CAN_Ptr + CAN_IF1_COMM_REQ_REG),TRANSMISSION_BUSY_BIT));	
	
	/* Clear Transmission Request */
	CLEAR_BIT(*(CAN_Ptr + CAN_IF1_COMM_MASK_REG),MESSAGE_TRANSMIT_REQUEST);
}


/********************************************************************************
*[Function Name]: CAN_Is_Message_Received.
*[Description]  : This function to check wether their is newdata.
*[in]		: a_message_number : Contains the message number from 1 to 32.
*					a_can_id				 : Contains which can we are updating in CAN0 or CAN1.
*[out]		: None.
*[in/out]	: None.
*[Returns]	: None.
*********************************************************************************/
uint8 CAN_Is_Message_Received(uint8 a_message_number,uint8 a_can_id)
{
	/* Pointer to point at the Base Address of the CAN */ 
  volatile uint32 * CAN_Ptr = NULL_PTR;
	
	/* Pointer to global configuration required */
	const CAN_ConfigType *config_Ptr = NULL_PTR;
  
	/* Switch Case to choose which CAN is used */
	switch(a_can_id)
  {
     case CAN0: CAN_Ptr = &CAN_0_BASE_ADDRESS;
								config_Ptr = g_can0_config_Ptr;
		break;
     case CAN1: CAN_Ptr = &CAN_1_BASE_ADDRESS;
								config_Ptr = g_can1_config_Ptr;
		break;
  }
	
	/* See if messge number > 16 used DATA2 if not use DATA1 */
	if(a_message_number > 16)
	{
		if(BIT_IS_SET(*(CAN_Ptr + CAN_NEW_DATA2), (a_message_number-17) ))
		{
			return TRUE;
		}
	}
	else if(a_message_number <= 16)
	{
		if(BIT_IS_SET(*(CAN_Ptr + CAN_NEW_DATA1), (a_message_number-1) ))
		{
			return TRUE;
		}
	}
	else
	{
		/* DO NOTHING */
	}
	return FALSE;	/* No Data was received */
}

/********************************************************************************
*[Function Name]: CAN_Received_Message.
*[Description]  : This function responsbile for receiving data.
*[in]		: a_message_number : Contains the message number from 1 to 32.
*					a_can_id				 : Contains which can we are updating in CAN0 or CAN1.
*[out]		: None.
*[in/out]	: None.
*[Returns]	: None.
*********************************************************************************/
void CAN_Received_Message(uint8 a_message_number,uint8 a_can_id)
{
	/* Pointer to point at the Base Address of the CAN */ 
  volatile uint32 * CAN_Ptr = NULL_PTR;
	
	/* Pointer to global configuration required */
	const CAN_ConfigType *config_Ptr = NULL_PTR;
	
	/* Switch Case to choose which CAN is used */
	switch(a_can_id)
  {
     case CAN0: CAN_Ptr = &CAN_0_BASE_ADDRESS;
								config_Ptr = g_can0_config_Ptr;
		break;
     case CAN1: CAN_Ptr = &CAN_1_BASE_ADDRESS;
								config_Ptr = g_can1_config_Ptr;
		break;
  }
	
	/* To move message object from RAM to Interface */
	*(CAN_Ptr + CAN_IF2_MSG_CTL_REG)  = RECEIVE_HANDLING_VALUE;
	*(CAN_Ptr + CAN_IF2_COMM_REQ_REG) =  a_message_number;
	
	/* Clear New Data flg */
	CLEAR_BIT(*(CAN_Ptr + CAN_IF2_MSG_CTL_REG),NEW_DATA_FLAG);
	
	a_message_number = a_message_number-1;	/* To match array */
	uint8 Bytes = DATA_SIZE_MASK & *(CAN_Ptr + CAN_IF2_MSG_CTL_REG);/* Store number of bytes */
	
	/* Fill the Data */
	while(Bytes){
		switch(Bytes)
		{
			case ONE_BYTE:  	g_received_data[0] = (uint8)*( CAN_Ptr + CAN_IF2_DATA_A1);
			break;
			case TWO_BYTES:  	g_received_data[1] = (uint8)(*( CAN_Ptr + CAN_IF2_DATA_A1) >> SHIFT_ONE_BYTE);
			break;
			case THREE_BYTES: g_received_data[2] = (uint8)*( CAN_Ptr + CAN_IF2_DATA_A2);
			break;
			case FOUR_BYTES:  g_received_data[3] = (uint8)(*( CAN_Ptr + CAN_IF2_DATA_A2) >> SHIFT_ONE_BYTE);
			break;
			case FIVE_BYTES:  g_received_data[4] = (uint8)*( CAN_Ptr + CAN_IF2_DATA_B1);
			break;
			case SIX_BYTES:  	g_received_data[5] = (uint8)(*( CAN_Ptr + CAN_IF2_DATA_B1) >> SHIFT_ONE_BYTE);
			break;
			case SEVEN_BYTES: g_received_data[6] = (uint8)*( CAN_Ptr + CAN_IF2_DATA_B2);
			break;
			case EIGHT_BYTES: g_received_data[7] = (uint8)(*( CAN_Ptr + CAN_IF2_DATA_B2) >> SHIFT_ONE_BYTE);
		}
		Bytes = Bytes - 1;
	}
}

