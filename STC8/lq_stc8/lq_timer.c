/*!
  * @file     lq_timer.c
  *
  * @brief    定时器 驱动文件
  *
  * @company  北京龙邱智能科技
  *
  * @author   LQ-005
  *
  * @note     无
  *
  * @version  V1.0
  *
  * @par URL  http://shop36265907.taobao.com
  *           http://www.lqist.cn
  *
  * @email    chiusir@163.com
  *
  * @date     2020年3月20日
  */

#include "lq_timer.h"



/* 定时器API函数 在 lq_timer.h 中 */



/* 当TIMER0 用作时基时 存放时间片数用 */
volatile uint32_t xdata s_timerCounter = 0;



/**
  * @brief    TIMER0 当作系统时基  初始化后可以使用精确延时和程序计时器功能函数
  *
  * @param    无 
  *
  * @return   无
  *
  * @note     当使用TIMER0_GetUs(); TIMER0_GetMs(); 函数时 必须先进行初始化  注意时钟必须24Mhz
  *
  * @see      TIMER0_InitSys();   
  *
  * @date     2020/3/12 
  */
void TIMER0_InitSys(void)
{
	TIMER0_Init(1000);
	
	s_timerCounter = 0;
}


/**
  * @brief    TIMER0 当作系统时基时  获取当前时间 us
  *
  * @param    无 
  *
  * @return   当前 us数
  *
  * @note     当使用TIMER0_GetUs(); 函数时 必须先进行初始化  注意时钟必须24Mhz
  *
  * @see      uint32_t sysTick = TIMER0_GetUs();   
  *
  * @date     2020/3/12 
  */
uint32_t TIMER0_GetUs(void)
{
	volatile uint16_t xdata value = 0;
	volatile uint8_t xdata timer0L = 0;
	do
	{
		value    = TH0;
		timer0L  = TL0;
	}while(value != TH0);
	value = value << 8 | timer0L;

	return (uint32_t)((s_timerCounter*1000) + ((value - 63536) >> 1));
}


/**
  * @brief    TIMER0 当作系统时基时  获取当前时间 ms
  *
  * @param    无 
  *
  * @return   当前 ms数
  *
  * @note     当使用TIMER0_GetMs(); 函数时 必须先进行初始化  注意时钟必须24Mhz
  *
  * @see      uint32_t sysTick = TIMER0_GetMs();   
  *
  * @date     2020/3/12 
  */
uint32_t TIMER0_GetMs(void)
{
	volatile uint16_t xdata value = 0;
	volatile uint8_t xdata timer0L = 0;
	do
	{
		value    = TH0;
		timer0L  = TL0;
	}while(value != TH0);
	value = value << 8 | timer0L;
	
	return (uint32_t)(s_timerCounter);
}


/**
  * @brief    TIMER0 当作系统时基时  延时函数 us
  *
  * @param    延时时间 us 
  *
  * @return   无
  *
  * @note     当使用TIMER0_DelayUs(); 函数时 必须先进行初始化  注意时钟必须24Mhz
  *
  * @see      TIMER0_DelayUs(1000);   
  *
  * @date     2020/3/12 
  */
void TIMER0_DelayUs(uint32_t us)
{
	volatile uint32_t xdata sysTick = 0;
	sysTick = TIMER0_GetUs(); 
	
	while((TIMER0_GetUs() - sysTick) <= us);
}


/**
  * @brief    TIMER0 当作系统时基时  延时函数 ms
  *
  * @param    延时时间 ms 
  *
  * @return   无
  *
  * @note     当使用TIMER0_DelayMs(); 函数时 必须先进行初始化  注意时钟必须24Mhz
  *
  * @see      TIMER0_DelayMs(1000);   
  *
  * @date     2020/3/12 
  */
void TIMER0_DelayMs(uint32_t ms)
{
	while(ms--)
	{
		TIMER0_DelayUs(1000);
	}
}
