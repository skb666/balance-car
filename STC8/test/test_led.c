/*!
  * @file     test_led.c
  *
  * @brief    led²âÊÔ
  *
  * @company  ±±¾©ÁúÇñÖÇÄÜ¿Æ¼¼
  *
  * @author   LQ-005
  *
  * @note     ÎÞ
  *
  * @version  V1.0
  *
  * @par URL  http://shop36265907.taobao.com
  *           http://www.lqist.cn
  *
  * @email    chiusir@163.com
  *
  * @date     2020Äê3ÔÂ20ÈÕ
  */
#include "lq_led.h"
#include "test_led.h"

/* ²»¾«È·ÑÓÊ± */
extern void delayms(uint32_t ms);


  
  
 /**
  * @brief    ²âÊÔLEDµÆ
  *
  * @param    
  *
  * @return   
  *
  * @note     
  *
  * @example  
  *
  * @date     2019/6/4 ÐÇÆÚ¶þ
  */
 
  
void Test_LED(void)
{
    LED_Init();   
    while (1)
    {          
		uint8_t xdata i;

		LED_Color(red);     //ºìµÆ
		delayms(1000);
		
		LED_Color(green);   //ÂÌµÆ
		delayms(1000);
		
		LED_Color(blue);    //À¶µÆ
		delayms(1000);
		
		LED_Color(violet);  //×ÏµÆ
		delayms(1000);
		
		LED_Color(yellow);  //»ÆµÆ
		delayms(1000);
		
		LED_Color(cyan);    //ÇàµÆ
		delayms(1000);
		
		LED_Color(white);   //°×µÆ
		delayms(1000);
		
		LED_Color(black);   //¹ØµÆ
		delayms(1000);

		for( i = 0; i < 20; i++)
		{
			LED_ColorReverse(red);     //ºìµÆÉÁË¸
			delayms(100);
		}		

		for( i = 0; i < 20; i++)
		{
			LED_ColorReverse(green);   //ÂÌµÆÉÁË¸
			delayms(100);
		}		

		for( i = 0; i < 20; i++)
		{
			LED_ColorReverse(blue);    //À¶µÆÉÁË¸
			delayms(100);
		}		

		for( i = 0; i < 20; i++)
		{
			LED_ColorReverse(violet);  //×ÏµÆÉÁË¸
			delayms(100);
		}		

		for( i = 0; i < 20; i++)
		{
			LED_ColorReverse(yellow);  //»ÆµÆÉÁË¸
			delayms(100);
		}		

		for( i = 0; i < 20; i++)
		{
			LED_ColorReverse(cyan);    //ÇàµÆÉÁË¸
			delayms(100);
		}				

		for( i = 0; i < 20; i++)
		{
			LED_ColorReverse(white);   //°×µÆÉÁË¸
			delayms(100);
		}
    }
}

