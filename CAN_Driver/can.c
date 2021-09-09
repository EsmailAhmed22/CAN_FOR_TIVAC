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
void CAN_init(const CAN_ConfigType *a_config_Ptr){
	/* Pointer to point at the Base Address of the CAN */ 
  volatile uint32 * CAN_Ptr = NULL_PTR;
	/* Pointer to messages */
	volatile CAN_Message_Config * messages = NULL_PTR;
   /* Delay to give port time to be enabled */
  volatile unsigned long delay = 0;
	/* See which CAN to configure */
	if(a_config_Ptr->can_id == CAN0){
		/* Initialize CAN CLOCK */ 
		SET_BIT(CAN_ClOCK_REGISTER,CAN0);
		/* For Rx PIN:
		 * Initialize required port or ports 
		 * Select Alternative Function
		 * Set CTML value
		 * Enable Digital
		 * Set Direction
		*/
		if(a_config_Ptr->pin_id_rx == PF0)
		{
			/* Unlock PF0 before use */
			*(GPIO_PORTF_BASE_ADDRESS+PORT_LOCK_REG_OFFSET)= UNLOCK_VALUE;
			SET_BIT(*(GPIO_PORTF_BASE_ADDRESS+PORT_COMMIT_REG_OFFSET),PF0);
			
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
		/* Initialize CAN CLOCK */ 
		SET_BIT(CAN_ClOCK_REGISTER,CAN1);
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
     case CAN0: CAN_Ptr = &CAN_0_BASE_ADDRESS;
		break;
     case CAN1: CAN_Ptr = &CAN_1_BASE_ADDRESS;
		break;
  }
	/* Initialize state */
	SET_BIT(*(CAN_Ptr + CAN_CONTROL_REG),INIT_BIT);	/* To disable all transfers */
	SET_BIT(*(CAN_Ptr + CAN_CONTROL_REG),CFG_EN_BIT); /* To access CANBIT regs */
	*(CAN_Ptr + CAN_BIT_TIMING_REG) &= PRESCALER_CLEAR ; /* Clear Prescaler Bits only */
	*(CAN_Ptr + CAN_BIT_TIMING_REG) |= a_config_Ptr->prescaler; /* Set prescaler Bits only */
	*(CAN_Ptr + CAN_PRESCALER_EXT_REG) = a_config_Ptr->prescaler_ext; /* Set prescaler Bits only */
	/* Initialize all messages */
	messages = a_config_Ptr->message;
	SET_BIT(*(CAN_Ptr + CAN_IF1_COMM_MASK_REG),INTERFACE_RAM_BIT); /* Transfer from Interface to RAM */
	/* Transfer of Control ,arbitiration and mask data enable*/
	*(CAN_Ptr + CAN_IF1_COMM_MASK_REG) |= 0xFFFFFF7F;
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
			CLEAR_BIT(*(CAN_Ptr + CAN_IF1_ARB2_REG),MESSAGE_TYPE_BIT);
		}
		else if(messages[messages_counter].message_type == RECEIVE)
		{
			SET_BIT(*(CAN_Ptr + CAN_IF1_ARB2_REG),MESSAGE_TYPE_BIT);
		}
		else
		{
			/* DO NOTHING */
		}
		/* See if Message Type is used in filtering*/
		if(messages[messages_counter].message_type_filter_enable == STD_ON)
		{
			SET_BIT(*(CAN_Ptr + CAN_IF1_MASK2_REG),MESSAGE_TYPE_FILTER_ENABLE_BIT);
		}
		else if(messages[messages_counter].message_type_filter_enable == STD_OFF)
		{
			CLEAR_BIT(*(CAN_Ptr + CAN_IF1_MASK2_REG),MESSAGE_TYPE_FILTER_ENABLE_BIT);
		}
		else
		{
			/* DO NOTHING */
		}		
		/* See if Message is valid*/
		if(messages[messages_counter].message_valid == STD_ON)
		{
			SET_BIT(*(CAN_Ptr + CAN_IF1_ARB2_REG),MESSAGE_VALID_BIT);
		}
		else if(messages[messages_counter].message_valid == STD_OFF)
		{
			CLEAR_BIT(*(CAN_Ptr + CAN_IF1_MASK2_REG),MESSAGE_VALID_BIT);
		}
		else
		{
			/* DO NOTHING */
		}
		/* See if Message is used with remote frame*/
		if(messages[messages_counter].message_remote_enable == STD_ON)
		{
			SET_BIT(*(CAN_Ptr + CAN_IF1_MSG_CTL_REG),MESSAGE_REMOTE_ENABLE_BIT);
		}
		else if(messages[messages_counter].message_remote_enable == STD_OFF)
		{
			CLEAR_BIT(*(CAN_Ptr + CAN_IF1_MSG_CTL_REG),MESSAGE_REMOTE_ENABLE_BIT);
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
	}
	
	/*ENABLE CAN*/
	CLEAR_BIT(*(CAN_Ptr + CAN_CONTROL_REG),INIT_BIT);	/* To enable all transfers */
	CLEAR_BIT(*(CAN_Ptr + CAN_CONTROL_REG),CFG_EN_BIT); /* To not access CANBIT regs */
}

/*******************************************************************************
***************************INTERRUPT HANDLER************************************
*******************************************************************************/

/* ISR for Receiving a Byte*/     
void CAN_Receive_Handler(void)
{
}
