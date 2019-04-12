/*
 * stm32f10x_it.c
 *
 *  Created on: 2018. 7. 25.
 *      Author: james
 */

#include "stm32f10x_it.h"
#include "timerHandler.h"

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void USB_HP_CAN1_TX_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void USB_LP_CAN1_RX0_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void CAN1_RX1_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void CAN1_SCE_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void EXTI9_5_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void TIM1_BRK_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void TIM1_UP_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void TIM1_TRG_COM_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void TIM1_CC_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
		Timer2_ISR();
	}
}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void TIM3_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void TIM4_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void I2C1_EV_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void I2C1_ER_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void I2C2_EV_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void I2C2_ER_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void SPI1_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void SPI2_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void USART1_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void USART2_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void USART3_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void EXTI15_10_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void RTCAlarm_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void USBWakeUp_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void TIM8_BRK_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void TIM8_UP_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void TIM8_TRG_COM_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void TIM8_CC_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void ADC3_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void FSMC_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void SDIO_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void TIM5_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void SPI3_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void UART4_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void UART5_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void TIM6_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void TIM7_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void DMA2_Channel1_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void DMA2_Channel2_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void DMA2_Channel3_IRQHandler(void){}

/*******************************************
 * Function Name: USB_HP_CAN1_TX_IRQHandler
 * Description : This function handles ...
 * Input : None
 * Output : None
 * Return : None
 */
void DMA2_Channel4_5_IRQHandler(void){}



