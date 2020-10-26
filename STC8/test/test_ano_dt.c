/*!
  * @file     TEST_ANO_DT.c
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
#include "test_ano_dt.h"
#include "ANO_DT.h"
#include "math.h"
#include "lq_uart.h"
#include "lq_led.h"

/** 声明外部延时函数 */
extern void delayms(uint32_t ms);

/**
  * @brief    测试上报匿名上位机
  *
  * @param    
  *
  * @return   
  *
  * @note     发送 5路 正玄波
  *
  * @example  
  *
  * @date     2019/6/17 星期一
  */
void Test_ANO_DT(void)    
{
    float xdata data1 = 0.0f;
    float xdata data2 = 45.0f; 
    float xdata data3 = 90.0f;   
    float xdata data4 = 135.0f;   
    float xdata data5 = 60.0f;
    code float PI = 3.1415926f;
    
    LED_Init();   

    UART1_InitTimer1P30P31(115200);      //初始化串口   
   
    while(1)
    {

		ANO_DT_send_int16((int16_t)(sin(data1/180.0f * PI) * 100),
					  (int16_t)(sin(data2/180.0f * PI) * 100),
					  (int16_t)(sin(data3/180.0f * PI) * 100),
					  (int16_t)(sin(data4/180.0f * PI) * 100), 
					  (int16_t)(sin(data5/180.0f * PI) * 100), 
					  0, 
					  0,
					  0);  

         
        delayms(20);
		
        if(data1 > 180.0f) data1 = -180;
        if(data2 > 180.0f) data2 = -180;
        if(data3 > 180.0f) data3 = -180;
        if(data4 > 180.0f) data4 = -180;
        if(data5 > 180.0f) data5 = -180;
        
        data1 += 1;
        data2 += 2;
        data3 += 3;
        data4 += 4;
        data5 += 5;
		
		LED_ColorReverse(green);
    }
}


