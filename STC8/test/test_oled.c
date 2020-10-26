/*!
  * @file     test_oled.c
  *
  * @brief    oled测试
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
#include "lq_oled.h"
#include "test_oled.h"

/* 不精确延时 */
extern void delayms(uint32_t ms);

/**
  * @brief    OLED 测试函数
  *
  * @param    无
  *
  * @return   无
  *
  * @note     无
  *
  * @example  Test_OLED();
  *
  * @date     2019/6/25 星期二
  */
void Test_OLED(void)
{      
    OLED_Init();                          //LCD初始化 
    OLED_Show_LQLogo();                   //显示LOGO
    delayms(2000);  
    OLED_CLS();       
  
    while (1)
    {  
        OLED_P6x8Str(0,7,"OLED 3.");         //字符串
		delayms(1000);
        OLED_Rectangle(0, 0, 127,62,0);      //绘制矩形
        OLED_Rectangle(24,8,88,55,1);
		OLED_Rectangle(32,16,80,47,1);
		OLED_Rectangle(40,24,72,39,1);
        delayms(1000);
        OLED_CLS();                          //清屏
        
        OLED_P8x16Str(0, 0,"OLED 4.");       //显示字符串
        OLED_P14x16Str(0,3,"北京龙邱");      //显示汉字
        OLED_PutPixel(120,60);
        delayms(1000);
        OLED_CLS();                          //清屏
        
        OLED_Fill();                         //填充
        delayms(1000);
        OLED_CLS();                          //清屏 
        
        //延时
        delayms(50);
    }
}
