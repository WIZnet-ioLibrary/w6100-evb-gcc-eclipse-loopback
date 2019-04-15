/**
  ******************************************************************************
  * @file    retarget.c 
  * @author  IOP Team
  * @version V1.0.0
  * @date    01-May-2015
  * @brief   Using for printf function
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, WIZnet SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2015 WIZnet Co.,Ltd.</center></h2>
  ******************************************************************************
  */ 

#include <stdio.h>
#include "stm32f10x_usart.h"


// Replaced the defines for UART Selector to Callback functions.
#define USING_UART1
#if defined (USING_UART0)
    #define UART_SEND_BYTE(ch)  UartPutc(USART0,ch)
    #define UART_RECV_BYTE()    UartGetc(USART0)
#elif defined (USING_UART1)
    #define UART_SEND_BYTE(ch)  UartPutc(USART1,ch)
    #define UART_RECV_BYTE()    UartGetc(USART1)
#elif defined (USING_UART2)
    #define UART_SEND_BYTE(ch)  UartPutc(USART2,ch)
    #define UART_RECV_BYTE()    UartGetc(USART2)
#endif


uint8_t UartPutc(USART_TypeDef* UARTx, uint8_t ch)
{
    USART_SendData(UARTx, (uint16_t)ch);

    while(USART_GetFlagStatus(UARTx, USART_FLAG_TXE) == RESET);

    return (ch);
}

#if defined ( __CC_ARM   )
/******************************************************************************/
/* Retarget functions for ARM DS-5 Professional / Keil MDK                    */
/******************************************************************************/
#include <time.h>
#include <rt_misc.h>
#pragma import(__use_no_semihosting_swi)

struct __FILE { int handle; /* Add whatever you need here */ };
FILE __stdout;
FILE __stdin;

int fputc(int ch, FILE *f) {
    return (UART_SEND_BYTE(ch));
}

int fgetc(FILE *f) {
    return (UART_SEND_BYTE(UART_RECV_BYTE()));
}

int ferror(FILE *f) {
    /* Your implementation of ferror */
    return EOF;
}

void _ttywrch(int ch) {
    UART_SEND_BYTE(ch);
}

void _sys_exit(int return_code) {
    label:  goto label;  /* endless loop */
}

#elif defined (__GNUC__)
/******************************************************************************/
/* Retarget functions for GNU Tools for ARM Embedded Processors               */
/******************************************************************************/
#include <sys/stat.h>

__attribute__ ((used))  int _write (int fd, char *ptr, int len)
{
    int i;
    for (i=0; i<len;i++)
    {
        UART_SEND_BYTE(ptr[i]); // call character output function
    }

    return len;
}
#else //using TOOLCHAIN_IAR

int putchar(int ch)
{
    return (UART_SEND_BYTE(ch));
}

int getchar(void)
{
    return (UART_SEND_BYTE(UART_RECV_BYTE()));
}

#endif
