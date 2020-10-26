/*!
  * @file     lq_led.c
  *
  * @brief    led驱动
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
#include "lq_led.h"




/*!
  * @brief    LED初始化
  *
  * @param    
  *
  * @return   
  *
  * @note     
  *
  * @example  LED_Init();
  *
  * @date     2019/8/6 星期二
  */
void LED_Init(void)
{
	//核心板RGB灯初始化
    PIN_InitPushPull(LED_R_PORT, LED_R_PIN);
	PIN_InitPushPull(LED_G_PORT, LED_G_PIN);
	PIN_InitPushPull(LED_B_PORT, LED_B_PIN);
	P(LED_R_PORT, LED_R_PIN) = 1;
	P(LED_G_PORT, LED_G_PIN) = 1;
	P(LED_B_PORT, LED_B_PIN) = 1;
}

/**
  * @brief    指定颜色的灯亮
  *
  * @param    color  ： 枚举LED_t中的颜色
  *
  * @return   
  *
  * @note     
  *
  * @example  LED_Color(red);   //红灯亮
  *
  * @date     2019/6/4 星期二
  */
void LED_Color(LED_t color)
{
    switch(color)
    {
        case white:
            P(LED_R_PORT, LED_R_PIN) = 0;//LED亮; 
            P(LED_G_PORT, LED_G_PIN) = 0;//LED亮; 
            P(LED_B_PORT, LED_B_PIN) = 0;//LED亮; 
            break;
        case black:
            P(LED_R_PORT, LED_R_PIN) = 1;//LED灭; 
            P(LED_G_PORT, LED_G_PIN) = 1;//LED灭; 
            P(LED_B_PORT, LED_B_PIN) = 1;//LED灭; 
            break;
        case red:
            P(LED_R_PORT, LED_R_PIN) = 0;//LED灭; 
            P(LED_G_PORT, LED_G_PIN) = 1;//LED亮; 
            P(LED_B_PORT, LED_B_PIN) = 1;//LED灭; 
            break;
        case green:
            P(LED_R_PORT, LED_R_PIN) = 1;//LED亮; 
            P(LED_G_PORT, LED_G_PIN) = 0;//LED灭; 
            P(LED_B_PORT, LED_B_PIN) = 1;//LED灭; 
            break;
        case blue:
            P(LED_R_PORT, LED_R_PIN) = 1;//LED灭; 
            P(LED_G_PORT, LED_G_PIN) = 1;//LED灭; 
            P(LED_B_PORT, LED_B_PIN) = 0;//LED亮; 
            break;
        case yellow:
            P(LED_R_PORT, LED_R_PIN) = 0;//LED亮; 
            P(LED_G_PORT, LED_G_PIN) = 0;//LED亮; 
            P(LED_B_PORT, LED_B_PIN) = 1;//LED灭; 
            break;
        case violet:
            P(LED_R_PORT, LED_R_PIN) = 0;//LED灭; 
            P(LED_G_PORT, LED_G_PIN) = 1;//LED亮; 
            P(LED_B_PORT, LED_B_PIN) = 0;//LED亮; 
            break;
        case cyan:
            P(LED_R_PORT, LED_R_PIN) = 1;//LED亮; 
            P(LED_G_PORT, LED_G_PIN) = 0;//LED灭; 
            P(LED_B_PORT, LED_B_PIN) = 0;//LED亮; 
            break;      
    }
}

/**
  * @brief    指定颜色闪烁
  *
  * @param    color  ： 枚举LED_t中的颜色
  *
  * @return   
  *
  * @note     
  *
  * @example  LED_ColorReverse(red); //翻转红灯
  *
  * @date     2019/6/4 星期二
  */
void LED_ColorReverse(LED_t color)
{
	static uint8_t xdata count = 0;
	if(count++ % 2)
    {
        LED_Color(color);   //亮指定颜色的灯
    }
    else
    {
        LED_Color(black);   //灭
    }
}


