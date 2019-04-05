/*
 * nvicHandler.c
 *
 *  Created on: 2018. 7. 24.
 *      Author: james
 */

#include "nvicHandler.h"

void NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;

#ifdef VECT_TAB_RAM
	NVIC_SetVectorTable(NVIC_VectTab_RAM, 0x0);
#else	// VECT_TAB_FLASH
	/* Configure one bit for preemption priority */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

//	/* Enable the USART1 Interrupt */
//	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn; //IRQChannel is defined in stm32f10x.h
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure);
//
//	/* Enable the USART3 Interrupt */
//	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn; //IRQChannel is defined in stm32f10x.h
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure);
//
//	/* Enable the UART4 Interrupt */
//	NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn; //IRQChannel is defined in stm32f10x.h
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure);
//
//	/* Enable the UART5 Interrupt */
//	NVIC_InitStructure.NVIC_IRQChannel = UART5_IRQn; //IRQChannel is defined in stm32f10x.h
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure);
//
	/* Enable the TIM2 global Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn; //IRQChannel is defined in stm32f10x.h
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
//
//	NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0000);
#endif
}
