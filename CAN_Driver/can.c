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
			SET_BIT(*(GPIO_PORTF_BASE_ADDRESS+PORT_ALT_FUNC_REG_OFFSET),PF0);
			*(GPIO_PORTF_BASE_ADDRESS+PORT_CTL_REG_OFFSET) = CAN_PMC_1;
			SET_BIT(*(GPIO_PORTF_BASE_ADDRESS+PORT_DIGITAL_ENABLE_REG_OFFSET),PF0);
			CLEAR_BIT(*(GPIO_PORTF_BASE_ADDRESS+PORT_DIR_REG_OFFSET),PF0);
		}
		else if(a_config_Ptr->pin_id_rx == PB4)
		{
			SET_BIT(PORT_ClOCK_REGISTER,PORTB_ID);
			SET_BIT(*(GPIO_PORTB_BASE_ADDRESS+PORT_ALT_FUNC_REG_OFFSET),PB4);
			*(GPIO_PORTB_BASE_ADDRESS+PORT_CTL_REG_OFFSET) = (CAN_PMC_2 << (PB4 * SHIFT_FACTOR));
			SET_BIT(*(GPIO_PORTB_BASE_ADDRESS+PORT_DIGITAL_ENABLE_REG_OFFSET),PB4);
			CLEAR_BIT(*(GPIO_PORTB_BASE_ADDRESS+PORT_DIR_REG_OFFSET),PB4);
		}
		else if(a_config_Ptr->pin_id_rx == PE4)
		{
			SET_BIT(PORT_ClOCK_REGISTER,PORTE_ID);
			SET_BIT(*(GPIO_PORTE_BASE_ADDRESS+PORT_ALT_FUNC_REG_OFFSET),PE4);
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
			*(GPIO_PORTF_BASE_ADDRESS+PORT_CTL_REG_OFFSET) = (CAN_PMC_1 << (PF3 * SHIFT_FACTOR));
			SET_BIT(*(GPIO_PORTF_BASE_ADDRESS+PORT_DIGITAL_ENABLE_REG_OFFSET),PF3);
			SET_BIT(*(GPIO_PORTF_BASE_ADDRESS+PORT_DIR_REG_OFFSET),PF3);
		}
		else if(a_config_Ptr->pin_id_tx == PB5)
		{
			SET_BIT(PORT_ClOCK_REGISTER,PORTB_ID);
			SET_BIT(*(GPIO_PORTB_BASE_ADDRESS+PORT_ALT_FUNC_REG_OFFSET),PB5);
			*(GPIO_PORTB_BASE_ADDRESS+PORT_CTL_REG_OFFSET) = (CAN_PMC_2 << (PB5 * SHIFT_FACTOR));
			SET_BIT(*(GPIO_PORTB_BASE_ADDRESS+PORT_DIGITAL_ENABLE_REG_OFFSET),PB5);
			SET_BIT(*(GPIO_PORTB_BASE_ADDRESS+PORT_DIR_REG_OFFSET),PB5);
		}
		else if(a_config_Ptr->pin_id_tx == PE5)
		{
			SET_BIT(PORT_ClOCK_REGISTER,PORTE_ID);
			SET_BIT(*(GPIO_PORTE_BASE_ADDRESS+PORT_ALT_FUNC_REG_OFFSET),PE5);
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
			*(GPIO_PORTA_BASE_ADDRESS+PORT_CTL_REG_OFFSET) = (CAN_PMC_2 << (PA1 * SHIFT_FACTOR));
			SET_BIT(*(GPIO_PORTA_BASE_ADDRESS+PORT_DIGITAL_ENABLE_REG_OFFSET),PA1);
			SET_BIT(*(GPIO_PORTA_BASE_ADDRESS+PORT_DIR_REG_OFFSET),PA1);
		}
	}
	else{
		/* NOTHING TO DO SO RETURN*/
		return;
	}
}

/*******************************************************************************
***************************INTERRUPT HANDLER************************************
*******************************************************************************/

/* ISR for Receiving a Byte*/     
void CAN_Receive_Handler(void)
{
}
