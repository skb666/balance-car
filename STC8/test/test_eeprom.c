/*!
  * @file     test_eeprom.c
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
#include "stdio.h"
#include "test_eeprom.h"
#include "lq_uart.h"
#include "lq_eeprom.h"


/**
  * @brief    测试内部EEPROM  
  *
  * @param    无
  *
  * @return   无
  *
  * @note     注意  芯片内部EEPROM大小 由ISP下载软件设置 从地址0x0000开始  
  *
  * @example  
  *
  * @date     2019/4/22 星期一
*/
void Test_EEPROM()
{
	uint8_t xdata i = 0;
	
	/* 存放 eeprom 读取到的值 */
	uint8_t pdata u8rData[8];
	uint32_t pdata u32rData[8];
	float pdata frData[8];
	
	/* 存放 eeprom 将要写入的值 */
	uint8_t xdata u8wData[8];
	uint32_t xdata u32wData[8];
	float xdata fwData[8];
	
	/* 串口初始化 用作打印 */
	UART1_InitTimer1P30P31(115200);
	
	/* 注意 写入之前需要先擦除 */
	EEPROM_Erase(0x0000);   //擦出扇区
	
	/* 读写入值进行赋值 */
	for(i = 0; i < 8; i++)
	{
		u8wData[i]  = 3 * i;
		u32wData[i] = 30 * i;
		fwData[i]   = 3.5f * i;
	}
	
	/* 写入u8 */
	for(i = 0; i < 8; i++)
	{
		EEPROM_Write(0x0000 + i, u8wData[i]);
	}
	
	/* 写入u32 */
	for(i = 0; i < sizeof(u32wData); i++)
	{
		EEPROM_Write(0x0008 + i, ((uint8_t *)u32wData)[i]);
	}
	
	/* 写入float */
	for(i = 0; i < sizeof(fwData); i++)
	{
		EEPROM_Write(0x0040 + i, ((uint8_t *)fwData)[i]);
	}
	
	/* 读取u8 */
	for(i = 0; i < 8; i++)
	{
		EEPROM_Read(0x0000 + i, u8rData[i]);
	}
	
	/* 读取u32 */
	for(i = 0; i < sizeof(u32wData); i++)
	{
		EEPROM_Read(0x0008 + i, ((uint8_t *)u32rData)[i]);
	}
	
	/* 读取float */
	for(i = 0; i < sizeof(fwData); i++)
	{
		EEPROM_Read(0x0040 + i, ((uint8_t *)frData)[i]);
	}

	/* 比较写入和读取 */
	for(i = 0; i < 8; i++)
	{
		if(u8rData[i] != u8wData[i])
		{
			printf(" u8 error : %d \r\n", (int)u8rData[i]);
			printf(" eeprom 读写错误 \r\n");
		}else{
			printf("%d\r\n", (int)u8rData[i]);
		}
	}

	/* 比较写入和读取 */
	for(i = 0; i < 8; i++)
	{
		if(u32rData[i] != u32wData[i])
		{
			printf(" u32 error : %ld \r\n", u32rData[i]);
			printf(" eeprom 读写错误 \r\n");
		}else{
			printf("%ld\r\n", u32rData[i]);
		}
	}

	/* 比较写入和读取 */
	for(i = 0; i < 8; i++)
	{
		if(frData[i] != fwData[i])
		{
			printf(" float error : %f \r\n", frData[i]);
			printf(" eeprom 读写错误 \r\n");
		}else{
			printf("%f\r\n", frData[i]);
		}
	}
	
	printf(" eeprom 测试结束 \r\n");
}

