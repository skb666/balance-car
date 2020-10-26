/*!
  * @file     lq_spi.c
  *
  * @brief    spi 驱动文件
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
#include "lq_spi.h"
  
/**
  * @brief    SPI读写N个字节
  *
  * @param    txData  ：  写入的buff
  * @param    rxData  ：  读出的buff
  * @param    len     ：  长度
  *
  * @return   无
  *
  * @note     无
  *
  * @see      uint8_t tbuff[2], rbuff[2];
  * @see      SPI_ReadWriteNByte(tbuff, rbuff, 2); //使用SPI 读写两个字节 
  *
  * @date     2019/6/3 星期一
  */
uint8_t  SPI_ReadWriteNByte(uint8_t *txData, uint8_t *rxData, uint8_t len)
{
#if (STC8A== 1)
	SPI_SS_1 = 0;
#else
	SPI_SS_4 = 0;
#endif
	while(len--)
	{
		SPDAT = *txData++;
		SPI_Wait();
		*rxData++ = SPDAT;
	}
#if (STC8A== 1)
	SPI_SS_1 = 1;
#else
	SPI_SS_4 = 1;
#endif
	return 0;
}
  