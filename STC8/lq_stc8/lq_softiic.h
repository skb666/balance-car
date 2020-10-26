/*!
  * @file     LQ_SOFTIIC.h
  *
  * @brief    模拟IIC驱动文件
  *
  * @company  北京龙邱智能科技
  *
  * @author   LQ-005
  *
  * @note     无
  *
  * @version  V1.1  2019/12/06 优化注释 Doxygen
  *
  * @par URL  http://shop36265907.taobao.com
  *           http://www.lqist.cn
  *
  * @date     2019/10/23 星期三
  */ 
#ifndef __LQ_SOFTIIC_H
#define __LQ_SOFTIIC_H

#include "lq_gpio.h"

/* 注意 IIC总线规定，IIC空闲时 SCL和SDA都为高电平 最好外部上拉（一定不能下拉） */
/* 模拟 IIC需要注意，IIC地址左移一位 例如MPU6050 模拟就是地址 0xD0 */
/* 想换用别的IO 直接修改宏定义 SOFT_IIC_SCL_PIN 、 SOFT_IIC_SDA_PIN 即可 */

#if (STC8A == 1)
#define SOFT_IIC_SCL_PORT  2
#define SOFT_IIC_SCL_PIN   5   /*!< P25  作为 SCL */

#define SOFT_IIC_SDA_PORT  2
#define SOFT_IIC_SDA_PIN   4   /*!< P24  作为 SDA */

#else
#define SOFT_IIC_SCL_PORT  1
#define SOFT_IIC_SCL_PIN   0   /*!< P15  作为 SCL */

#define SOFT_IIC_SDA_PORT  1
#define SOFT_IIC_SDA_PIN   1   /*!< P14  作为 SDA */

#endif

#define SDA_OUT            PIN_InitPushPull(SOFT_IIC_SDA_PORT, SOFT_IIC_SDA_PIN);
#define SDA_IN             PIN_InitPureInput(SOFT_IIC_SDA_PORT, SOFT_IIC_SDA_PIN);

#define IIC_SCL_INIT   PIN_InitOpenDrain(SOFT_IIC_SCL_PORT, SOFT_IIC_SCL_PIN);    PIN_EnablePullUp(SOFT_IIC_SCL_PORT, SOFT_IIC_SCL_PIN); 
#define IIC_SDA_INIT   PIN_InitOpenDrain(SOFT_IIC_SDA_PORT, SOFT_IIC_SDA_PIN);    PIN_EnablePullUp(SOFT_IIC_SDA_PORT, SOFT_IIC_SDA_PIN); 

#define IIC_SCL_H      P(SOFT_IIC_SCL_PORT, SOFT_IIC_SCL_PIN) = 1;
#define IIC_SCL_L      P(SOFT_IIC_SCL_PORT, SOFT_IIC_SCL_PIN) = 0;

#define IIC_SDA_H      P(SOFT_IIC_SDA_PORT, SOFT_IIC_SDA_PIN) = 1;
#define IIC_SDA_L      P(SOFT_IIC_SDA_PORT, SOFT_IIC_SDA_PIN) = 0;

#define IIC_SDA_READ   P(SOFT_IIC_SDA_PORT, SOFT_IIC_SDA_PIN)


/*---------------------------------------------------------------
            IIC内部函数
----------------------------------------------------------------*/		 
void IIC_Start(void);			        //发送IIC开始信号
void IIC_Stop(void);	  	            //发送IIC停止信号
void IIC_Ack(void);					//IIC发送ACK信号
void IIC_NAck(void);				    //IIC不发送ACK信号
uint8_t IIC_WaitAck(void); 		        //IIC等待ACK信号
void IIC_SendByte(uint8_t data_t);        //IIC发送一个字节
uint8_t IIC_ReadByte(uint8_t ack);       //IIC读取一个字节


/*---------------------------------------------------------------
            IIC用户函数
----------------------------------------------------------------*/
/*!
  * @brief    模拟IIC初始化
  *
  * @param    无
  *
  * @return   无
  *
  * @note     无
  *
  * @see      IIC_Init();  //模拟IIC初始化 IIC管脚在LQ_SOFTIIC.h中定义
  *
  * @date     2019/10/23 星期三
  */
void IIC_Init(void);                    

/*!
  * @brief    模拟IIC读取指定设备 指定寄存器的一个值
  *
  * @param    I2C_Addr  目标设备地址
  * @param    reg       目标寄存器
  * @param    buf       存放读出字节
  *
  * @return   1失败 0成功
  *
  * @note     无
  *
  * @see      uint8_t data;  
  * @see      IIC_ReadByteFromSlave(0xD0, 0x75, &data);   //读 IIC地址为 0xD0器件（MPU6050）寄存器0x75
  *
  * @date     2019/10/23 星期三
  */	
uint8_t IIC_ReadByteFromSlave(uint8_t I2C_Addr,uint8_t reg,uint8_t *buf);

/*!
  * @brief    模拟IIC读取指定设备 指定寄存器的n个值
  *
  * @param    dev       目标设备地址
  * @param    reg       目标寄存器
  * @param    length    读取长度
  * @param    data      存放读出数据
  *
  * @return   1失败 0成功
  *
  * @note     无
  *
  * @see      uint8_t data[14];  
  * @see      IIC_ReadByteFromSlave(0xD0, 0X3B, 14, &data);   //读 14个字节
  *
  * @date     2019/10/23 星期三
  */
uint8_t IIC_ReadMultByteFromSlave(uint8_t dev, uint8_t reg, uint8_t length, uint8_t *data_t);

/*!
  * @brief    模拟IIC写指定设备 指定寄存器的一个值
  *
  * @param    I2C_Addr  目标设备地址
  * @param    reg       目标寄存器
  * @param    data      写入的数据
  *
  * @return   1失败 0成功
  *
  * @note     无
  *
  * @see      IIC_ReadByteFromSlave(0xD0, 0X6B, 0X80);   //IIC地址为 0xD0器件（MPU6050）寄存器0x6B 写入0x80
  *
  * @date     2019/10/23 星期三
  */
uint8_t IIC_WriteByteToSlave(uint8_t I2C_Addr,uint8_t reg,uint8_t buf);

/*!
  * @brief    模拟IIC写指定设备 指定寄存器的n个值
  *
  * @param    dev       目标设备地址
  * @param    reg       目标寄存器
  * @param    length    写入长度
  * @param    data      存放写入数据
  *
  * @return   1失败 0成功
  *
  * @note     无
  *
  * @see      IIC_WriteMultByteToSlave(0xD0, 0X6B, 1, 0X80);   //向寄存器0x6B写入0x80
  *
  * @date     2019/10/23 星期三
  */
uint8_t IIC_WriteMultByteToSlave(uint8_t dev, uint8_t reg, uint8_t length, uint8_t* data_t);

#endif
