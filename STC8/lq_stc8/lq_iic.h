/*!
  * @file     lq_iic.h
  *
  * @brief    iic 驱动文件
  *
  * @company  北京龙邱智能科技
  *
  * @author   LQ-005
  *
  * @note     硬件IIC速度实测只有 100K
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
  
#ifndef __LQ_IIC_H
#define __LQ_IIC_H
  
#include "reg51.h"
#include "lq_gpio.h"

/* 存放临时数据 */
extern uint8_t xdata iicSendLen;

/* 注意 操作IIC寄存器时 需要 先开启 EAXSFR()  访问完成后 EAXRAM() */


/*========================================================================================*/
/*========================================================================================*/
/*===========================IIC底层驱动 用户无需关心=====================================*/
/*========================================================================================*/
/*========================================================================================*/
/* IIC功能使能 */
#define    I2c_Enable()             I2CCFG |=  0x80
#define    I2c_Disable()            I2CCFG &= ~0x80
							      
/* IIC主从模式 */                 
#define    I2c_Master()             I2CCFG |=  0x40
#define    I2c_Slave()              I2CCFG &= ~0x40

/* IIC 时钟  MAIN_Fosc/2/(div * 2 + 1)  bps 波特率 */
#define    I2c_SetDiv(bps)          I2CCFG &= 0x3F; //if((MAIN_Fosc/24/bps - 2) > 0x3f) I2CCFG |= 0x3f; else I2CCFG |= (MAIN_Fosc/24/bps - 2);

/* IIC 中断 使能 */
#define    I2c_InterruptEnable()    I2CMSCR |= 0x80
#define    I2c_InterruptDisable()   I2CMSCR &= ~0x80

/* IIC 自动发送 若自动发送功能被使能，当 MCU 执行完成对 I2CTXD 数据寄存器的写操作后， I2C 控制器会自动
触发“ 1010”命令，即自动发送数据并接收 ACK 信号。*/
#define    I2c_EnableWdta()         I2CMSAUX |= 1

/* 清除中断标志位 */
#define    I2c_Clear()              I2CMSST &= ~(1<<6)

/* IIC 等待命令完成 */
#define    I2c_Wait()               while (!(I2CMSST & 0x40)); I2CMSST &= ~0x40;

/* 接收ACK */
#define    I2c_GetAck()             I2CMSCR = 0x03; I2c_Wait(); 

/* 发送ACK    */
#define    I2c_SendAck()            I2CMSST = 0x00; I2CMSCR = 0x05; I2c_Wait()

/* 发送NACK    */
#define    I2c_SendNAck()           I2CMSST = 0x01; I2CMSCR = 0x05; I2c_Wait()

/* IIC 发送一个数据 */
#define    I2c_SendData(n)          I2CTXD = n; I2CMSCR = 0x02; I2c_Wait()

/* IIC 接收一个数据 并发送ACK0 */
#define    I2c_GetData(n)           I2CMSCR = 0x04; I2c_Wait(); n = I2CRXD


/* IIC 起始信号 */
#define    I2c_Start()                  I2CMSCR = 0x01; I2c_Wait()
									    
/* IIC 停止信号 */                      
#define    I2c_Stop()                   I2CMSCR = 0x06; I2c_Wait()


/*========================================================================================*/
/*========================================================================================*/
/*===========================     IIC 用户API   ==========================================*/
/*========================================================================================*/
/*========================================================================================*/
/*



*/
/* IIC初始化 SCL SDA  bsp是IIC波特率 */
#define  IIC_InitP15P14(bps)      P_SW2 &= ~0x30; PIN1_InitStandard(5); PIN1_InitStandard(4); EAXSFR(); I2CCFG = 0; I2c_SetDiv(bps); I2c_Enable() ; I2c_Master();  I2CMSST = 0; EAXRAM()
#define  IIC_InitP25P24(bps)      P_SW2 |= 0x10 ; PIN2_InitStandard(5); PIN2_InitStandard(4); EAXSFR(); I2CCFG = 0; I2c_SetDiv(bps); I2c_Enable() ; I2c_Master();  I2CMSST = 0; EAXRAM()

/* 写一个寄存器  
 * addr  从机地址  MPU6050为0xD0
 * reg   寄存器
 * value 写入寄存器值
*/
#define  IIC_WriteReg(addr, reg, value) {EAXSFR(); I2c_Start(); I2c_SendData(addr); I2c_GetAck(); I2c_SendData(reg);I2c_GetAck();I2c_SendData(value);I2c_GetAck(); I2c_Stop(); EAXRAM();}

/* 读一个寄存器  
 * addr  从机地址  MPU6050为0xD0
 * reg   寄存器
 * value 读取寄存器值
*/
#define  IIC_ReadReg(addr, reg, value) {EAXSFR(); I2c_Start(); I2c_SendData(addr); I2c_GetAck(); I2c_SendData(reg);I2c_GetAck(); I2c_Start();I2c_SendData((addr+1)); I2c_GetAck(); I2c_GetData(value);I2c_GetAck(); I2c_Stop(); EAXRAM();}


/* 读n个寄存器  
 * addr  从机地址  MPU6050为0xD0
 * reg   寄存器
 * buff  读取寄存器值存放的缓冲区
 * len   读取len个寄存器
*/
void IIC_ReadMultReg(uint8_t addr, uint8_t reg, uint8_t* buff, uint8_t len);



#endif
  