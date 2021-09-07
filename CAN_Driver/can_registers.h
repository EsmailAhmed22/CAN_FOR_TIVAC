/******************************************************************************
*
* Module:CAN
*
* File Name: can.h
*
* Description: Header file for TM4C123GH6PM Microcontroller - CAN Driver Registers
*
* Author: Esmail Ahmed
*
*******************************************************************************/

#ifndef CAN_REGS_H
#define CAN_REGS_H

#include "Std_Types.h"

/* Needed to initialize the port Clock and CAN Clock */
#define PORT_ClOCK_REGISTER           (*((volatile uint32 *)0x400FE608))

/* Needed GPIO Registers for CAN pins Initialization */
/* Base Address of GPIO PORTS using APB Bus */
#define GPIO_PORTA_BASE_ADDRESS       (*((volatile uint32 *)0x40004000))
#define GPIO_PORTB_BASE_ADDRESS       (*((volatile uint32 *)0x40005000))
#define GPIO_PORTE_BASE_ADDRESS       (*((volatile uint32 *)0x40024000))
#define GPIO_PORTF_BASE_ADDRESS       (*((volatile uint32 *)0x40025000))
/* GPIO Registers offset addresses */
#define PORT_DATA_REG_OFFSET              0x3FC
#define PORT_DIR_REG_OFFSET               0x400
#define PORT_ALT_FUNC_REG_OFFSET          0x420
#define PORT_PULL_UP_REG_OFFSET           0x510
#define PORT_PULL_DOWN_REG_OFFSET         0x514
#define PORT_DIGITAL_ENABLE_REG_OFFSET    0x51C
#define PORT_LOCK_REG_OFFSET              0x520
#define PORT_COMMIT_REG_OFFSET            0x524
#define PORT_ANALOG_MODE_SEL_REG_OFFSET   0x528
#define PORT_CTL_REG_OFFSET               0x52C

/* CAN Base Address */
#define CAN_0_BASE_ADDRESS       (*((volatile uint32 *)0x40040000))
#define CAN_1_BASE_ADDRESS       (*((volatile uint32 *)0x40041000))

/* CAN Registers offset addresses */
#define CAN_CONTROL_REG					 0x000	
#define CAN_STATUS_REG					 0x004	
#define CAN_ERROR_COUNTER_REG		 0x008	
#define CAN_BIT_TIMING_REG			 0x00C	
#define CAN_INTERRUPT_REG				 0x010	
#define CAN_TEST_REG					   0x014	
#define CAN_PRESCALER_EXT_REG	   0x018	
#define CAN_IF1_COMM_REQ_REG		 0x020	
#define CAN_IF2_COMM_REQ_REG		 0x080	
#define CAN_IF1_COMM_MASK_REG		 0x024	
#define CAN_IF2_COMM_MASK_REG		 0x084	
#define CAN_IF1_MASK1_REG				 0x028	
#define CAN_IF2_MASK1_REG				 0x088	
#define CAN_IF1_MASK2_REG				 0x02C	
#define CAN_IF2_MASK2_REG				 0x08C		
#define CAN_IF1_ARB1_REG				 0x030	
#define CAN_IF2_ARB1_REG				 0x090		
#define CAN_IF1_ARB2_REG				 0x034	
#define CAN_IF2_ARB2_REG				 0x094
#define CAN_IF1_MSG_CTL_REG			 0x038	
#define CAN_IF2_MSG_CTL_REG			 0x098
#define CAN_IF1_DATA_A1					 0x03C
#define CAN_IF2_DATA_A1					 0x09C
#define CAN_IF1_DATA_A2					 0x040
#define CAN_IF2_DATA_A2					 0x0A0
#define CAN_IF1_DATA_B1					 0x044
#define CAN_IF2_DATA_B1					 0x0A4
#define CAN_IF1_DATA_B2					 0x048
#define CAN_IF2_DATA_B2					 0x0A8
#define CAN_TRANS_REQ1					 0x100
#define CAN_TRANS_REQ2					 0x104
#define CAN_NEW_DATA1						 0x120
#define CAN_NEW_DATA2						 0x124
#define CAN_INT_PEND1						 0x140		
#define CAN_INT_PEND2						 0x144	
#define CAN_MSG_VALID1					 0x160
#define CAN_MSG_VALID2					 0x164



/* NVIC Registers for CAN Interrupt handling */
#define NVIC_PRI9_REG             (*((volatile uint32 *)0xE000E424)) 	/* For CAN0 */
#define NVIC_PRI10_REG            (*((volatile uint32 *)0xE000E428))	/* For CAN1 */
#define NVIC_EN1_REG              (*((volatile uint32 *)0xE000E104))

#endif
