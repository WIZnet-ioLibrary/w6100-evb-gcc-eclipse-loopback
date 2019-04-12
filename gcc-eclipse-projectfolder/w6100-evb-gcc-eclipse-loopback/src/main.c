/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2014 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"

#include "Timer.h"
#include "BlinkLed.h"

#include "nvicHandler.h"
#include "rccHandler.h"
#include "gpioHandler.h"
#include "uartHandler.h"
#include "timerHandler.h"
#include "fsmcHandler.h"
#include "spiHandler.h"

#include "wizchip_conf.h"
#include "W6100RelFunctions.h"


// ----------------------------------------------------------------------------
//
// Standalone STM32F1 led blink sample (trace via DEBUG).
//
// In debug configurations, demonstrate how to print a greeting message
// on the trace device. In release configurations the message is
// simply discarded.
//
// Then demonstrates how to blink a led with 1 Hz, using a
// continuous loop and SysTick delays.
//
// Trace support is enabled by adding the TRACE macro definition.
// By default the trace messages are forwarded to the DEBUG output,
// but can be rerouted to any device or completely suppressed, by
// changing the definitions required in system/src/diag/trace_impl.c
// (currently OS_USE_TRACE_SEMIHOSTING_DEBUG/_STDOUT).
//
// The external clock frequency is specified as a preprocessor definition
// passed to the compiler via a command line option (see the 'C/C++ General' ->
// 'Paths and Symbols' -> the 'Symbols' tab, if you want to change it).
// The value selected during project creation was HSE_VALUE=12000000.
//
// Note: The default clock settings take the user defined HSE_VALUE and try
// to reach the maximum possible system clock. For the default 8 MHz input
// the result is guaranteed, but for other values it might not be possible,
// so please adjust the PLL settings in system/src/cmsis/system_stm32f10x.c
//

// ----- Timing definitions -------------------------------------------------

// Keep the LED on for 2/3 of a second.
#define BLINK_ON_TICKS  (TIMER_FREQUENCY_HZ * 3 / 4)
#define BLINK_OFF_TICKS (TIMER_FREQUENCY_HZ - BLINK_ON_TICKS)

// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

wiz_NetInfo gWIZNETINFO = { .mac = {0x00,0x08,0xdc,0x12,0x34,0x56},
							.ip = {192,168,177,120},
							.sn = {255, 255, 255, 0},
							.gw = {192, 168, 177, 1},
							.dns = {168, 126, 63, 1},
							//.dhcp = NETINFO_STATIC,
							.lla={0xfe,0x80,0x00,0x00,
									0x00,0x00, 0x00,0x00,
									0x02,0x08, 0xdc,0xff,
									0xfe,0x57, 0x12,0x34},   ///< Source Link Local Address
							.gua={0x20,0x01,0x02,0xb8,
									0x00,0x10,0x00,0x01,
									0x02,0x08,0xdc,0xff,
									0xfe,0x57,0x12,0x34},   ///< Source Global Unicast Address
							.sn6={0xff,0xff,0xff,0xff,
									0xff,0xff,0xff,0xff,
									0x00,0x00,0x00, 0x00,
									0x00,0x00,0x00,0x00 },   ///< IPv6 Prefix
							.gw6={0xfe, 0x80, 0x00,0x00,
									0x00,0x00,0x00,0x00,
									0x02,0x00, 0x87,0xff,
									0xfe,0x08, 0x4c,0x81}   ///< Gateway IPv6 Address
};

uint8_t WIZ_Dest_IP_virtual[4] = {192, 168, 0, 230};                  //DST_IP Address
uint8_t WIZ_Dest_IP_Google[4] = {216, 58, 200, 174};              //DST_IP Address

uint8_t mcastipv4_0[4] ={239,1,2,3};
uint8_t mcastipv4_1[4] ={239,1,2,4};
uint8_t mcastipv4_2[4] ={239,1,2,5};
uint8_t mcastipv4_3[4] ={239,1,2,6};

uint16_t WIZ_Dest_PORT = 15000;                                 //DST_IP port

//////////////////////////////////////////////////////////////////////
/*******************IPv6  ADDRESS**************************/
//////////////////////////////////////////////////////////////////////

uint8_t Zero_IP[16] = {0x00, };


uint8_t DestIP6_L[16] = {0xfe,0x80, 0x00,0x00,
						0x00,0x00, 0x00,0x00,
                        0x31,0x71,0x98,0x05,
                        0x70,0x24,0x4b,0xb1
												};

uint8_t DestIP6_G[16] = {0x20,0x01,0x02,0xb8,
                          0x00,0x10,0x00,0x01,
                          0x31,0x71,0x98,0x05,
                          0x70,0x24,0x4b,0xb1
                         };


#define ETH_MAX_BUF_SIZE	1024
uint8_t  remote_ip[4] = {192,168,177,200};                      //
uint16_t remote_port = 8080;
unsigned char ethBuf0[ETH_MAX_BUF_SIZE];
unsigned char ethBuf1[ETH_MAX_BUF_SIZE];
unsigned char ethBuf2[ETH_MAX_BUF_SIZE];
unsigned char ethBuf3[ETH_MAX_BUF_SIZE];
unsigned char ethBuf4[ETH_MAX_BUF_SIZE];
unsigned char ethBuf5[ETH_MAX_BUF_SIZE];
unsigned char ethBuf6[ETH_MAX_BUF_SIZE];
unsigned char ethBuf7[ETH_MAX_BUF_SIZE];

uint8_t bLoopback = 1;
uint8_t bRandomPacket = 0;
uint8_t bAnyPacket = 0;
uint16_t pack_size = 0;

void delay(unsigned int);
void print_network_information(void);

int
main(int argc, char* argv[])
{
//  // Send a greeting to the trace device (skipped on Release).
//  trace_puts("Hello ARM World!");
//
//  // At this stage the system clock should have already been configured
//  // at high speed.
//  trace_printf("System clock: %u Hz\n", SystemCoreClock);
//
  timer_start();

  blink_led_init();

  RCC_Configuration();
  NVIC_Configuration();
  GPIO_Configuration();
  USART_Configuration();
  Timer_Configuration();


  printf("System clock: %ld Hz\n", SystemCoreClock);



  uint8_t syslock = SYS_NET_LOCK;
  uint8_t svr_ipv4[4] = {192, 168, 177, 235};
  uint8_t svr_ipv6[16] = {0xfe, 0x80, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0xc1, 0x0b, 0x0a, 0xdf,
						0xea, 0xf4, 0xf4, 0x2d};

  uint16_t version;

#if _WIZCHIP_IO_MODE_ & _WIZCHIP_IO_MODE_SPI_
	/* SPI method callback registration */
	#if defined SPI_DMA
		reg_wizchip_spi_cbfunc(spiReadByte, spiWriteByte,spiReadBurst,spiWriteBurst);
	#else
		reg_wizchip_spi_cbfunc(spiReadByte, spiWriteByte,0,0);
	#endif
	/* CS function register */
	reg_wizchip_cs_cbfunc(csEnable,csDisable);
#else
	/* Indirect bus method callback registration */
	#if defined BUS_DMA
			reg_wizchip_bus_cbfunc(busReadByte, busWriteByte,busReadBurst,busWriteBurst);
	#else
			reg_wizchip_bus_cbfunc(busReadByte, busWriteByte,0,0);
	#endif
#endif
#if _WIZCHIP_IO_MODE_ == _WIZCHIP_IO_MODE_BUS_INDIR_
	FSMC_Configuration();
#else
	SPI_Configuration();
#endif

	resetAssert();
	delay(100);
	resetDeassert();
	delay(100);

	W6100Initialze();
	ctlwizchip(CW_SYS_UNLOCK,& syslock);
	ctlwizchip(CW_GET_VER,&version);
	printf("Version: %x\r\n", version);

	ctlnetwork(CN_SET_NETINFO,&gWIZNETINFO);


	printf("Register value after W6100 initialize!\r\n");

	print_network_information();

	setDevtime(0);

	int currTime = 0;

	uint8_t is_off = 1;

	while (1)
	{
		int tmpTime;

		loopback_udps(0,ethBuf0,50000,AS_IPV4);
		loopback_udps(1,ethBuf1,50001,AS_IPV6);
		loopback_udps(2,ethBuf2,50002,AS_IPDUAL);
		loopback_tcps(3,ethBuf3,50003,AS_IPV4);
		loopback_tcps(4,ethBuf4,50004,AS_IPV6);
		loopback_tcps(5,ethBuf5,50005,AS_IPDUAL);
		loopback_tcpc(6,ethBuf6,svr_ipv4,50006,AS_IPV4);
		loopback_tcpc(7,ethBuf7,svr_ipv6,50007,AS_IPV6);

		if((tmpTime = getDevtime()) != currTime)
		{
			currTime = tmpTime;
			if(is_off)
			{
				blink_led_on();
				is_off = 0;
			}else
			{
				blink_led_off();
				is_off = 1;
			}
		}
	}
  // Infinite loop, never return.
}

void delay(unsigned int count)
{
	uint32_t temp;
	temp = (uint32_t)count + millis();
	while(temp > millis()){}
}

void print_network_information(void)
{
    uint8_t tmp_array[16];
//    uint8_t i;
	wizchip_getnetinfo(&gWIZNETINFO);
	printf("Mac address: %02x:%02x:%02x:%02x:%02x:%02x\n\r",gWIZNETINFO.mac[0],gWIZNETINFO.mac[1],gWIZNETINFO.mac[2],gWIZNETINFO.mac[3],gWIZNETINFO.mac[4],gWIZNETINFO.mac[5]);
	printf("IP address : %d.%d.%d.%d\n\r",gWIZNETINFO.ip[0],gWIZNETINFO.ip[1],gWIZNETINFO.ip[2],gWIZNETINFO.ip[3]);
	printf("SM Mask	   : %d.%d.%d.%d\n\r",gWIZNETINFO.sn[0],gWIZNETINFO.sn[1],gWIZNETINFO.sn[2],gWIZNETINFO.sn[3]);
	printf("Gate way   : %d.%d.%d.%d\n\r",gWIZNETINFO.gw[0],gWIZNETINFO.gw[1],gWIZNETINFO.gw[2],gWIZNETINFO.gw[3]);
	printf("DNS Server : %d.%d.%d.%d\n\r",gWIZNETINFO.dns[0],gWIZNETINFO.dns[1],gWIZNETINFO.dns[2],gWIZNETINFO.dns[3]);
	getGA6R(tmp_array);
    printf("GW6 : %04X:%04X", ((uint16_t)tmp_array[0] << 8) | ((uint16_t)tmp_array[1]),
    		((uint16_t)tmp_array[2] << 8) | ((uint16_t)tmp_array[3]));
    printf(":%04X:%04X", ((uint16_t)tmp_array[4] << 8) | ((uint16_t)tmp_array[5]),
    		((uint16_t)tmp_array[6] << 8) | ((uint16_t)tmp_array[7]));
    printf(":%04X:%04X", ((uint16_t)tmp_array[8] << 8) | ((uint16_t)tmp_array[9]),
    		((uint16_t)tmp_array[10] << 8) | ((uint16_t)tmp_array[11]));
    printf(":%04X:%04X\r\n ", ((uint16_t)tmp_array[12] << 8) | ((uint16_t)tmp_array[13]),
    		((uint16_t)tmp_array[14] << 8) | ((uint16_t)tmp_array[15]));

	getLLAR(tmp_array);
	printf("LLA : %04X:%04X", ((uint16_t)tmp_array[0] << 8) | ((uint16_t)tmp_array[1]),
			((uint16_t)tmp_array[2] << 8) | ((uint16_t)tmp_array[3]));
	printf(":%04X:%04X", ((uint16_t)tmp_array[4] << 8) | ((uint16_t)tmp_array[5]),
			((uint16_t)tmp_array[6] << 8) | ((uint16_t)tmp_array[7]));
	printf(":%04X:%04X", ((uint16_t)tmp_array[8] << 8) | ((uint16_t)tmp_array[9]),
			((uint16_t)tmp_array[10] << 8) | ((uint16_t)tmp_array[11]));
	printf(":%04X:%04X\r\n", ((uint16_t)tmp_array[12] << 8) | ((uint16_t)tmp_array[13]),
			((uint16_t)tmp_array[14] << 8) | ((uint16_t)tmp_array[15]));
	getGUAR(tmp_array);
	printf("GUA : %04X:%04X", ((uint16_t)tmp_array[0] << 8) | ((uint16_t)tmp_array[1]),
			((uint16_t)tmp_array[2] << 8) | ((uint16_t)tmp_array[3]));
	printf(":%04X:%04X", ((uint16_t)tmp_array[4] << 8) | ((uint16_t)tmp_array[5]),
			((uint16_t)tmp_array[6] << 8) | ((uint16_t)tmp_array[7]));
	printf(":%04X:%04X", ((uint16_t)tmp_array[8] << 8) | ((uint16_t)tmp_array[9]),
			((uint16_t)tmp_array[10] << 8) | ((uint16_t)tmp_array[11]));
	printf(":%04X:%04X\r\n", ((uint16_t)tmp_array[12] << 8) | ((uint16_t)tmp_array[13]),
			((uint16_t)tmp_array[14] << 8) | ((uint16_t)tmp_array[15]));

	getSUB6R(tmp_array);
	printf("SUB6 : %04X:%04X", ((uint16_t)tmp_array[0] << 8) | ((uint16_t)tmp_array[1]),
			((uint16_t)tmp_array[2] << 8) | ((uint16_t)tmp_array[3]));
	printf(":%04X:%04X", ((uint16_t)tmp_array[4] << 8) | ((uint16_t)tmp_array[5]),
			((uint16_t)tmp_array[6] << 8) | ((uint16_t)tmp_array[7]));
	printf(":%04X:%04X", ((uint16_t)tmp_array[8] << 8) | ((uint16_t)tmp_array[9]),
			((uint16_t)tmp_array[10] << 8) | ((uint16_t)tmp_array[11]));
	printf(":%04X:%04X\r\n", ((uint16_t)tmp_array[12] << 8) | ((uint16_t)tmp_array[13]),
			((uint16_t)tmp_array[14] << 8) | ((uint16_t)tmp_array[15]));


	printf("\r\nNETCFGLOCK : %x\r\n", getNETLCKR());
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
