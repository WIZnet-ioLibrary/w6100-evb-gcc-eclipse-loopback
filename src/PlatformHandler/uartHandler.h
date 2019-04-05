/*
 * uartHanlder.h
 *
 *  Created on: 2018. 7. 25.
 *      Author: james
 */

#ifndef PLATFORMHANDLER_UARTHANDLER_H_
#define PLATFORMHANDLER_UARTHANDLER_H_


#include "stm32f10x_usart.h"

#define DEBUG_UART USART1

void USART_Configuration(void);

#endif /* PLATFORMHANDLER_UARTHANDLER_H_ */
