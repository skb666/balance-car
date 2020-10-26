/*!
  * @file     test_exti.c
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
#include "test_exti.h"
#include "lq_gpio.h"
#include "lq_led.h"
/**
  * @brief    测试管脚外部中断   
  *
  * @param    无
  *
  * @return   无
  *
  * @note     STC8只有5个管脚有外部中断功能 具体请看lq_gpio.h
  *
  * @example  
  *
  * @date     2019/4/22 星期一
*/
void Test_EXTI()
{
	LED_Init();
	
	/* P37初始化 开启内部上拉电阻 */
	PIN_InitStandard(3, 7);
	PIN_EnablePullUp(3, 7);
	
	/* 设置 P37 中断优先级 */
	SET_INT0_PRIORITY(2);
	
	/* 使能下降沿中断 */
	INT3_Enable();
	
	/* 中断服务函数 在irq.c中 翻转LED */
	while(1)
	{
		
	}
	
}
