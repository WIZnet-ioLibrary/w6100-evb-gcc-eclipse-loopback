/*
 * stm32f10x_board.h
 *
 *  Created on: 2018. 7. 24.
 *      Author: james
 */

#ifndef STM32F10X_BOARD_H_
#define STM32F10X_BOARD_H_


#define DEVICE_BOARD_NAME	W6100-EVB

#ifdef DEVICE_BOARD_NAME
	#if (DEVICE_BOARD_NAME == W6100-EVB)
		#define __STM32F103__
		#define __W6100__
	#endif
#endif

////////////////////////////////
// Pin definitions			  //
////////////////////////////////
#if (DEVICE_BOARD_NAME == W6100-EVB)

	/* Port A */

	#define UART1_TX_PIN				GPIO_Pin_9
	#define UART1_TX_PORT				GPIOA

	#define UART1_RX_PIN				GPIO_Pin_10
	#define UART1_RX_PORT				GPIOA

	/* Port B */
	#define FSMC_NADV_PIN				GPIO_Pin_7
	#define FSMC_NADV_PORT				GPIOB

	#define SPI2_SCK_PIN				GPIO_Pin_13
	#define SPI2_SCK_PORT				GPIOB

	#define SPI2_MISO_PIN				GPIO_Pin_14
	#define SPI2_MISO_PORT				GPIOB

	#define SPI2_MOSI_PIN				GPIO_Pin_15
	#define SPI2_MOSI_PORT				GPIOB


	/* Port D */
	#define DA0_PIN						GPIO_Pin_14
	#define DA0_PORT					GPIOD

	#define DA1_PIN						GPIO_Pin_15
	#define DA1_PORT					GPIOD

	#define DA2_PIN						GPIO_Pin_0
	#define DA2_PORT					GPIOD

	#define DA3_PIN						GPIO_Pin_1
	#define DA3_PORT					GPIOD

	#define FSMC_NOE_PIN				GPIO_Pin_4
	#define FSMC_NOE_PORT				GPIOD

	#define FSMC_NWE_PIN				GPIO_Pin_5
	#define FSMC_NWE_PORT				GPIOD

	#define RSTn_PIN					GPIO_Pin_8
	#define RSTn_PORT					GPIOD

	#define INTn_PIN					GPIO_Pin_9
	#define INTn_PORT					GPIOD

	#define SPI2_NSS_PIN				GPIO_Pin_7
	#define SPI2_NSS_PORT				GPIOD


	/* Port E */
	#define DA4_PIN						GPIO_Pin_7
	#define DA4_PORT					GPIOE

	#define DA5_PIN						GPIO_Pin_8
	#define DA5_PORT					GPIOE

	#define DA6_PIN						GPIO_Pin_9
	#define DA6_PORT					GPIOE

	#define DA7_PIN						GPIO_Pin_10
	#define DA7_PORT					GPIOE

#endif

#endif /* STM32F10X_BOARD_H_ */
