/*!
  * @file     TEST_KEY.c
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
#include "test_key.h"
#include "lq_key.h"
#include "lq_led.h"


/** 声明外部延时函数 */
extern void delayms(uint32_t ms);


/**
  * @brief    测试按键
  *
  * @param    无
  *
  * @return   无
  *
  * @note     无
  *
  * @see      Test_KEY();
  *
  * @date     2019/6/4 星期二
  */
void Test_KEY(void)
{ 
    LED_Init();
    KEY_Init(); 
    while (1)
    {  
        switch(KEY_Read(1))  
        {
            case 1:
                LED_Color(red);     
                break;           
            case 2:      
                LED_Color(green);   
                break;
            case 3:      
                LED_Color(blue);    
                break;
            default:
                LED_Color(white);   
                break;
        }

        delayms(50);
    }
}