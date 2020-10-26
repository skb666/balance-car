/*!
  * @file     test_enc.c
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
#include "test_enc.h"
#include "lq_enc.h"
#include "lq_uart.h"
#include "stdio.h"
#include "lq_led.h"
#include "lq_oled.h"

/* 不精确延时 */
extern void delayms(uint32_t ms);
#if (STC8A == 1)

/* STC8A编码器方向管脚 */
#define ENC1_DIR_PORT     0
#define ENC1_DIR_INDEX    7

#define ENC2_DIR_PORT     5
#define ENC2_DIR_INDEX    2
#else

/* STC8H编码器方向管脚 */
#define ENC1_DIR_PORT     0
#define ENC1_DIR_INDEX    5

#define ENC2_DIR_PORT     4
#define ENC2_DIR_INDEX    7

#endif
/**
  * @brief    测试带方向编码器   
  *
  * @param    无
  *
  * @return   无
  *
  * @note      
  *
  * @example  
  *
  * @date     2019/4/22 星期一
*/
void Test_ENC()
{
	uint8_t xdata txt[32];
	int xdata encValue1 = 0, encValue2 = 0;
	UART1_InitTimer1P30P31(115200);
	LED_Init();
	OLED_Init();
	
	TIMER3_EncInit();   //初始化定时器3  对P04管脚 脉冲计数
	TIMER4_EncInit();   //初始化定时器4  对P06管脚 脉冲计数
	
	/* 初始化 编码器方向管脚 */	
	PIN_InitStandard(ENC1_DIR_PORT, ENC1_DIR_INDEX);	
	PIN_InitStandard(ENC2_DIR_PORT, ENC2_DIR_INDEX); 
	
	
	while(1)
	{
		/* 获取计数值 */
		TIMER3_GetValue(encValue1);
		
		/* 方向管脚为低电平 倒转 */
		if(!P(ENC1_DIR_PORT, ENC1_DIR_INDEX))
		{
			encValue1 = -encValue1;
		}
		
		/* 获取计数值 */
		TIMER4_GetValue(encValue2);
		
		/* 方向管脚为低电平 倒转 */
		if(!P(ENC2_DIR_PORT, ENC2_DIR_INDEX))
		{
			encValue2 = -encValue2;
		}
		
		printf("value1: %d \r\n", encValue1);
		printf("value2: %d \r\n", encValue2);
		
		sprintf(txt, "value1: %5d", encValue1);   
		OLED_P6x8Str(0, 0, txt);                //OLED显示
		
		sprintf(txt, "value2: %5d", encValue2);   
		OLED_P6x8Str(0, 1, txt);                //OLED显示
		
		delayms(10);
		
		
		
	}
	

}
