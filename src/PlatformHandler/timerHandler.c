/*
 * timerHandler.c
 *
 *  Created on: 2018. 7. 24.
 *      Author: james
 */


#include "timerHandler.h"

volatile uint16_t msec_cnt = 0;
volatile uint8_t  sec_cnt = 0;
volatile uint8_t  min_cnt = 0;
volatile uint8_t  hour_cnt = 0;
volatile uint16_t day_cnt = 0;
volatile uint32_t devtime_sec = 0;
volatile uint32_t devtime_msec = 0;

uint8_t enable_phylink_check = 1;
volatile uint32_t phylink_down_time_msec;

void Timer_Configuration(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

	/* Time base configuration */
	TIM_TimeBaseStructure.TIM_Period = 1000-1;
	TIM_TimeBaseStructure.TIM_Prescaler = (SystemCoreClock/1000000) - 1;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

//	/* Prescaler configuration */
//	TIM_PrescalerConfig(TIM2, 71, TIM_PSCReloadMode_Immediate);

	/* TIM enable counter */
	TIM_Cmd(TIM2, ENABLE);

	/* TIM IT enable */
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
}

void Timer2_ISR(void)
{
	msec_cnt++; // millisecond counter

	devtime_msec++;

//	seg_timer_msec();		// [msec] time counter for SEG (S2E)
//	segcp_timer_msec();		// [msec] time counter for SEGCP (Config)
//	device_timer_msec();	// [msec] time counter for DeviceHandler (fw update)

//	if(enable_phylink_check) // will be modified
//	{
//		if(phylink_down_time_msec < 0xffffffff)	phylink_down_time_msec++;
//		else									phylink_down_time_msec = 0;
//	}
//
//	if(flag_s2e_application_running)
//	{
//		gpio_handler_timer_msec();
//	}

	/* Second Process */
	if(msec_cnt >= 1000) //second //if((msec_cnt % 1000) == 0)
	{
		msec_cnt = 0;
		sec_cnt++;

//		seg_timer_sec(); // [sec] time counter for SEG
//
//		DHCP_time_handler();	// Time counter for DHCP timeout
//		DNS_time_handler();		// Time counter for DNS timeout

		devtime_sec++; // device time counter, Can be updated this counter value by time protocol like NTP.
	}

	/* Minute Process */
	if(sec_cnt >= 60) //if((sec_cnt % 60) == 0)
	{
		sec_cnt = 0;
		min_cnt++;
	}

	/* Hour Process */
	if(min_cnt >= 60)
	{
		min_cnt = 0;
		hour_cnt++;
	}

    /* Day Process */
	if(hour_cnt >= 24)
	{
		hour_cnt = 0;
		day_cnt++;
	}
}

uint32_t getDevtime(void)
{
	return devtime_sec;
}

void setDevtime(uint32_t timeval_sec)
{
	devtime_sec = timeval_sec;
}

uint32_t getNow(void)
{
	return getDevtime();
}

uint32_t millis(void)
{
	return devtime_msec;
}

uint32_t getDeviceUptime_day(void)
{
	return day_cnt;
}

uint32_t getDeviceUptime_hour(void)
{
	return hour_cnt;
}

uint8_t getDeviceUptime_min(void)
{
	return min_cnt;
}

uint8_t getDeviceUptime_sec(void)
{
	return sec_cnt;
}

uint16_t getDeviceUptime_msec(void)
{
	return msec_cnt;
}


void set_phylink_time_check(uint8_t enable)
{
	if(enable == 1) // start
	{
		phylink_down_time_msec = 0; // counter variable clear
	}
	else // stop
	{
		;
	}

	enable_phylink_check = enable;
}

uint32_t get_phylink_downtime(void)
{
	return phylink_down_time_msec;
}

