/*!
  * @file     test_uart.c
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
#include "test_uart.h"
#include "lq_uart.h"
#include "stdio.h"
#include "stc8.h"

/* 不精确延时 */
extern void delayms(uint32_t ms);

/**
  * @brief    测试串口   
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
void Test_UART()
{
	uint8_t xdata uartSendData = 10;
	uint32_t xdata u32Data = 1000;
	
	UART1_InitTimer1P30P31(115200);  //初始化串口
	
	UART3_InitTimer2P50P51(115200);  //初始化串口

	while(1)
	{
		printf("uart1 打印， 注意 uart初始化波特率时 会使用stc8.h中的 MAIN_Fosc \r\n");    //printf 会调用lq_uart.c 中的putchar() 函数 如果修改printf对应的串口 则修改putchar() 函数即可
		printf("MAIN_Fosc 必须要和ISP软件中的时钟频率保持一致 否则可能会乱码 \r\n");
		
		printf("注意打印uint8_t 类型时 ： %d \r\n", (int)uartSendData);
		printf("注意打印uint32_t 类型时 ： %ld \r\n", u32Data);
		
		delayms(100);

		UART3_PutStr("MAIN_Fosc 必须要和ISP软件中的时钟频率保持一致 否则可能会乱码 \r\n");

		UART3_PutStr("\r\n");
		
		UART1_PutStr("MAIN_Fosc 必须要和ISP软件中的时钟频率保持一致 否则可能会乱码 \r\n");

		UART1_PutStr("\r\n");
	}
	
}