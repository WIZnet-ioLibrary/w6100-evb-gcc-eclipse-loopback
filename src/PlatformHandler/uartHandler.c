/*
 * uartHandler.c
 *
 *  Created on: 2018. 7. 25.
 *      Author: james
 */

#include "uartHandler.h"

void USART_Configuration(void)
{
	USART_InitTypeDef USART_InitStructure;

	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;


	USART_Init(DEBUG_UART, &USART_InitStructure);
	USART_Cmd(DEBUG_UART, ENABLE);
}

