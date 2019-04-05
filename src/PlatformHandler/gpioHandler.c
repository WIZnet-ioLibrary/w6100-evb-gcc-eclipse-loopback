/*
 * gpioHandler.c
 *
 *  Created on: 2018. 7. 24.
 *      Author: james
 */

#include "stm32f10x_board.h"
#include "gpioHandler.h"

void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	// Configure pin in output push/pull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 ;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/*For SPI*/
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = SPI2_SCK_PIN | SPI2_MOSI_PIN | SPI2_MISO_PIN;
	GPIO_Init(SPI2_SCK_PORT, &GPIO_InitStructure);

	/*For CS*/
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = SPI2_NSS_PIN;
	GPIO_Init(SPI2_NSS_PORT, &GPIO_InitStructure);

	/*For Reset*/
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = RSTn_PIN;
	GPIO_Init(RSTn_PORT, &GPIO_InitStructure);

	/* GPIOD configuration for data 0~3 and */
	GPIO_InitStructure.GPIO_Pin = DA0_PIN | DA1_PIN | DA2_PIN | DA3_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(DA0_PORT, &GPIO_InitStructure);

	/* GPIOE configuration for fsmc data d4~d7*/
	GPIO_InitStructure.GPIO_Pin = DA4_PIN | DA5_PIN  | DA6_PIN  | DA7_PIN ;
	GPIO_Init(DA4_PORT, &GPIO_InitStructure);

	/* GPIOB configuration for fsmc nadv */
	GPIO_InitStructure.GPIO_Pin = FSMC_NADV_PIN;
	GPIO_Init(FSMC_NADV_PORT, &GPIO_InitStructure);

	/* NOE and NWE configuration */
	GPIO_InitStructure.GPIO_Pin = FSMC_NOE_PIN | FSMC_NWE_PIN;
	GPIO_Init(FSMC_NOE_PORT, &GPIO_InitStructure);

}

