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

/* CAN Registers for CAN configuration */


/* NVIC Registers for CAN Interrupt handling */
#define NVIC_PRI9_REG             (*((volatile uint32 *)0xE000E424)) 	/* For CAN0 */
#define NVIC_PRI10_REG            (*((volatile uint32 *)0xE000E428))	/* For CAN1 */
#define NVIC_EN1_REG              (*((volatile uint32 *)0xE000E104))

#endif
