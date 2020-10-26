/*!
  * @file     test_timer.c
  *
  * @brief    STC8
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
#include "test_timer.h"
#include "lq_timer.h"
#include "lq_led.h"



/**
  * @brief    测试定时器中断   
  *
  * @param    无
  *
  * @return   无
  *
  * @note     
  *
  * @example  
  *
  * @date     2020/4/1 
*/
void Test_TIMER()
{
	uint32_t xdata msysTick = 0;
	uint32_t xdata msysTime = 0;
	TIMER0_InitSys();
	LED_Init();
	
	while(1)
	{
		/* 判断 500 ms 是否过去 */
		msysTime = TIMER0_GetUs() - msysTick;
		if(msysTime > 500000UL)
		{
			msysTick = TIMER0_GetUs();
			
			LED_ColorReverse(red);
		}
	}
	
}
