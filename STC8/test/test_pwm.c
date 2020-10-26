/*!
  * @file     test_pwm.c
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
#include "test_pwm.h"
#include "lq_pwm.h"

/* 不精确延时 */
extern void delayms(uint32_t ms);

#if (STC8A == 1)

/**
  * @brief    测试STC8A 母板 PWM  接口 
  *
  * @param    无
  *
  * @return   无
  *
  * @note      
  *
  * @see      
  *
  * @date     2020/4/1 星期一
  */
void Test_PWM(void)
{
	char xdata duty = 0;
	
	PWM_Init(2, 0, 12500, 0);
	PWM_Init(2, 1, 12500, 0);
	PWM_Init(2, 2, 12500, 0);
	PWM_Init(2, 3, 12500, 0);
	
	
	while(1)
	{
		
		if(duty > 0)
		{
			PWM_SetDuty(2, 0, 0);
			PWM_SetDuty(2, 1, duty * 1000);
			PWM_SetDuty(2, 2, 0);
			PWM_SetDuty(2, 3, duty * 1000);
		}
		else
		{
			PWM_SetDuty(2, 0, -duty * 1000);
			PWM_SetDuty(2, 1, 0);
			PWM_SetDuty(2, 2, -duty * 1000);
			PWM_SetDuty(2, 3, 0);
		}
		
		
		
		duty ++;
		
		if(duty > 5)
		{
			duty = -5;
		}
		
		delayms(1000);
	}
	
}


#else


/**
  * @brief    测试STC8H 母板 PWM  接口 
  *
  * @param    无
  *
  * @return   无
  *
  * @note      
  *
  * @see      
  *
  * @date     2020/4/1 星期一
  */
void Test_PWM(void)
{
	char xdata duty = 0;
	
	PWM_Init(0, 0, 12500, 0);   //初始化 P10
	PWM_Init(1, 1, 12500, 0);   //初始化 P22
	PWM_Init(1, 2, 12500, 0);   //初始化 P24
	PWM_Init(1, 3, 12500, 0);   //初始化 P26
	
	
	while(1)
	{
		
		if(duty > 0)
		{
			PWM_SetDuty(0, 0, 0);
			PWM_SetDuty(1, 1, duty * 1000);
			PWM_SetDuty(1, 2, 0);
			PWM_SetDuty(1, 3, duty * 1000);
		}
		else
		{
			PWM_SetDuty(0, 0, -duty * 1000);
			PWM_SetDuty(1, 1, 0);
			PWM_SetDuty(1, 2, -duty * 1000);
			PWM_SetDuty(1, 3, 0);
		}
		
		
		
		duty ++;
		
		if(duty > 5)
		{
			duty = -5;
		}
		
		delayms(1000);
	}
	
}
#endif
