/******************************************************************************
*
* Module:Application
*
* File Name: App.c
*
* Description: Source file for Application that will use can.
*
* Author: Esmail Ahmed
*
*******************************************************************************/
#include "can.h"

int main(void)
{
	/* Initialize Can Driver */
	CAN_Init(&CAN_Configuration);
	while(1)
		{
			/* Write desired Application here */
		}
		
}
