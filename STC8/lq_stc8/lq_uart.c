/*!
  * @file     lq_uart.c
  *
  * @brief    uart 驱动文件
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
#include "lq_uart.h"

/* 用于暂存定时器重装载值 */
volatile uint16_t  xdata timerReload = 0;

/* 串口忙标志位 */
volatile uint8_t   xdata uart1Busy = 0;
volatile uint8_t   xdata uart2Busy = 0;
volatile uint8_t   xdata uart3Busy = 0;
volatile uint8_t   xdata uart4Busy = 0;

/* printf 重定向 */
char putchar(char c)//重定向
{
	UART1_PutChar(c);  //使用printf函数时会调用  可以自行修改
	return c;
}


/*!
  * @brief    打印已知长度的数组
  * 
  * @param    buff  ： 要打印的字符串地址    
  * @param    len   ： 要打印的长度
  *
  * @return   无
  *
  * @note     使用前请先初始化对应串口
  *
  * @see      UART1_PutBuff("123456789",5);//实际发送5个字节‘1’‘2’‘3’‘4’‘5’    
  *
  * @date     2019/10/21 星期一
  */
void UART1_PutBuff(uint8_t *buff, uint16_t len) 
{
	uint16_t xdata temp = 0;
	for(temp = 0; temp < len; temp++)
	{
		UART1_PutChar(*(buff+temp));
	}  
}   

/*!
  * @brief    打印已知长度的数组
  * 
  * @param    buff  ： 要打印的字符串地址    
  * @param    len   ： 要打印的长度
  *
  * @return   无
  *
  * @note     使用前请先初始化对应串口
  *
  * @see      UART2_PutBuff("123456789",5);//实际发送5个字节‘1’‘2’‘3’‘4’‘5’    
  *
  * @date     2019/10/21 星期一
  */
void UART2_PutBuff(uint8_t *buff, uint16_t len) 
{
	uint16_t xdata temp = 0;
	for(temp = 0; temp < len; temp++)
	{
		UART2_PutChar(*(buff+temp));
	}  
}   

/*!
  * @brief    打印已知长度的数组
  * 
  * @param    buff  ： 要打印的字符串地址    
  * @param    len   ： 要打印的长度
  *
  * @return   无
  *
  * @note     使用前请先初始化对应串口
  *
  * @see      UART3_PutBuff("123456789",5);//实际发送5个字节‘1’‘2’‘3’‘4’‘5’    
  *
  * @date     2019/10/21 星期一
  */
void UART3_PutBuff(uint8_t *buff, uint16_t len) 
{
	uint16_t xdata temp = 0;
	for(temp = 0; temp < len; temp++)
	{
		UART3_PutChar(*(buff+temp));
	}  
}   


/*!
  * @brief    打印已知长度的数组
  * 
  * @param    buff  ： 要打印的字符串地址    
  * @param    len   ： 要打印的长度
  *
  * @return   无
  *
  * @note     使用前请先初始化对应串口
  *
  * @see      UART4_PutBuff("123456789",5);//实际发送5个字节‘1’‘2’‘3’‘4’‘5’    
  *
  * @date     2019/10/21 星期一
  */
void UART4_PutBuff(uint8_t *buff, uint16_t len) 
{
	uint16_t xdata temp = 0;
	for(temp = 0; temp < len; temp++)
	{
		UART4_PutChar(*(buff+temp));
	}  
}   

/*!
  * @brief    串口打印字符串
  *
  * @param    str   ： 要打印的字符串地址 
  *
  * @return   无
  *
  * @note     使用前请先初始化对应串口
  *
  * @see      UART1_PutStr("123456789"); //发送9个字节      
  *
  * @date     2019/10/21 星期一
  */
void UART1_PutStr(uint8_t *str) 
{
	while(*str)
	{
		UART1_PutChar(*str++);
	}
}     

/*!
  * @brief    串口打印字符串
  *
  * @param    str   ： 要打印的字符串地址 
  *
  * @return   无
  *
  * @note     使用前请先初始化对应串口
  *
  * @see      UART2_PutStr("123456789"); //发送9个字节      
  *
  * @date     2019/10/21 星期一
  */
void UART2_PutStr(uint8_t *str) 
{
	while(*str)
	{
		UART2_PutChar(*str++);
	}
} 

/*!
  * @brief    串口打印字符串
  *
  * @param    str   ： 要打印的字符串地址 
  *
  * @return   无
  *
  * @note     使用前请先初始化对应串口
  *
  * @see      UART3_PutStr("123456789"); //发送9个字节      
  *
  * @date     2019/10/21 星期一
  */
void UART3_PutStr(uint8_t *str) 
{
	while(*str)
	{
		UART3_PutChar(*str++);
	}
} 

/*!
  * @brief    串口打印字符串
  *
  * @param    str   ： 要打印的字符串地址 
  *
  * @return   无
  *
  * @note     使用前请先初始化对应串口
  *
  * @see      UART4_PutStr("123456789"); //发送9个字节      
  *
  * @date     2019/10/21 星期一
  */
void UART4_PutStr(uint8_t *str) 
{
	while(*str)
	{
		UART4_PutChar(*str++);
	}
} 





