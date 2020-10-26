/*!
  * @file     lq_iic.c
  *
  * @brief    iic 驱动文件
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

#include "lq_iic.h"

/* 存放临时数据 */
uint8_t xdata iicSendLen = 0;


/* 读n个寄存器  
 * addr  从机地址  MPU6050为0xD0
 * reg   寄存器
 * buff  读取寄存器值存放的缓冲区
 * len   读取len个寄存器
*/
void IIC_ReadMultReg(uint8_t addr, uint8_t reg, uint8_t* buff, uint8_t len)
{
	uint8_t xdata temp = 0;
	EAXSFR();
	I2c_Start();
	I2c_SendData(addr);
	I2c_GetAck(); 
	I2c_SendData(reg);
	I2c_GetAck(); 
	I2c_Start();
	I2c_SendData((addr+1));
	I2c_GetAck(); 
	for(iicSendLen = 0; iicSendLen < len; iicSendLen++)
	{
		I2c_GetData(temp);
		I2c_GetAck(); 
		*(buff + iicSendLen) = temp;
	}
	I2c_Stop();
	EAXRAM();
}

