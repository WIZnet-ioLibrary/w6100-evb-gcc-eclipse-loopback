/*
 * rccHandler.c
 *
 *  Created on: 2018. 7. 24.
 *      Author: james
 */

#include "rccHandler.h"


void RCC_Configuration(void)
{

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 | RCC_APB1Periph_SPI2, ENABLE);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB |
                        RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE, ENABLE );

    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC, ENABLE);
}
