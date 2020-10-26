/*!
  * @file     lq_spi.h
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
  
#ifndef __LQ_SPI_H
#define __LQ_SPI_H
  
#include "stc8.h"
#include "lq_gpio.h"

/*========================================================================================*/
/*========================================================================================*/
/*===========================SPI底层驱动 用户无需关心=====================================*/
/*========================================================================================*/
/*========================================================================================*/
//sfr SPCTL  = 0xCE;	SPI控制寄存器
//   7       6       5       4       3       2       1       0    	Reset Value
//	SSIG	SPEN	DORD	MSTR	CPOL	CPHA	SPR1	SPR0		0x00

#define	SPI_SSIG_None()		SPCTL |=  (1<<7)		/* 1: 忽略SS脚	*/
#define	SPI_SSIG_Enable()	SPCTL &= ~(1<<7)		/* 0: SS脚用于决定主从机	*/
#define	SPI_Enable()		SPCTL |=  (1<<6)		/* 1: 允许SPI	*/
#define	SPI_Disable()		SPCTL &= ~(1<<6)		/* 0: 禁止SPI	*/
#define	SPI_LSB_First()		SPCTL |=  (1<<5)		/* 1: LSB先发	*/
#define	SPI_MSB_First()		SPCTL &= ~(1<<5)		/* 0: MSB先发	*/
#define	SPI_Master()		SPCTL |=  (1<<4)		/* 1: 设为主机	*/
#define	SPI_Slave()			SPCTL &= ~(1<<4)		/* 0: 设为从机	*/
#define	SPI_SCLK_NormalH()	SPCTL |=  (1<<3)		/* 1: 空闲时SCLK为高电平	*/
#define	SPI_SCLK_NormalL()	SPCTL &= ~(1<<3)		/* 0: 空闲时SCLK为低电平	*/
#define	SPI_PhaseH()		SPCTL |=  (1<<2)		/* 1: 数据在 SCLK 的前时钟沿驱动，后时钟沿采样	*/
#define	SPI_PhaseL()		SPCTL &= ~(1<<2)		/* 0: 数据 SS 管脚为低电平驱动第一位数据并在 SCLK 的后时钟沿改变数据，前时钟沿采样数据（必须 SSIG＝ 0	*/
#define	SPI_Speed(n)		SPCTL = (SPCTL & ~3) | (n)	/*设置速度, 0 -- fosc/4, 1 -- fosc/8, 2 -- fosc/16, 3 -- fosc/32	*/
                                                
//sfr SPSTAT  = 0xCD;	//SPI状态寄存器
//   7       6      5   4   3   2   1   0    	Reset Value
//	SPIF	WCOL	-	-	-	-	-	-
#define	SPIF	0x80		/* SPI传输完成标志。写入1清0。*/
#define	WCOL	0x40		/* SPI写冲突标志。写入1清0。  */
/* 清除中断标志位 */
#define     SPI_Clear()             SPSTAT |= SPIF

/* SPI 等待发送完成 */
#define     SPI_Wait()              while (!(SPSTAT & 0x80)); SPSTAT = 0xc0;

#define		SPI_USE_P12P13P14P15()	P_SW1 &= ~0x0c,	PIN1_InitStandard(2), PIN1_InitStandard(3), PIN1_InitStandard(4), PIN1_InitStandard(5)				/* 将SPI切换到P12(SS) P13(MOSI) P14(MISO) P15(SCLK)(上电默认)。*/
#define		SPI_USE_P22P23P24P25()	P_SW1 &= ~0x0c, P_SW1 |= (1<<3),	  PIN2_InitStandard(2), PIN2_InitStandard(3), PIN2_InitStandard(4), PIN2_InitStandard(5)	/* 将SPI切换到P22(SS) P23(MOSI) P24(MISO) P25(SCLK)。*/
#define		SPI_USE_P54P40P41P43()	P_SW1 &= ~0x0c, P_SW1 |= (1<<4),	  PIN5_InitStandard(4), PIN4_InitStandard(0), PIN4_InitStandard(1), PIN4_InitStandard(3)	/* 将SPI切换到P54(SS) P40(MOSI) P41(MISO) P43(SCLK)。*/
#define		SPI_USE_P35P34P33P32()	P_SW1 |= 0x0c ,	PIN3_InitStandard(5), PIN3_InitStandard(4), PIN3_InitStandard(3), PIN3_InitStandard(2)              /* 将SPI切换到P35(SS) P34(MOSI) P33(MISO) P32(SCLK)。*/

//							7     6     5    4    3    2    1     0    Reset Value
//sfr IE2       = 0xAF;		-     -     -    -    -    -   ESPI  ES2   0000,0000B	//Auxiliary Interrupt   
#define		SPI_INT_ENABLE()		IE2 |=  2	/* 允许SPI中断		*/
#define		SPI_INT_DISABLE()		IE2 &= ~2	/* 禁止SPI中断		*/









/*========================================================================================*/
/*========================================================================================*/
/*===================================SPI 用户API =========================================*/
/*========================================================================================*/
/*========================================================================================*/

/*初始化 SPI   bsp为SPI速度 设置速度, 0 -- MAIN_Fosc/4, 1 -- MAIN_Fosc/8, 2 -- MAIN_Fosc/16, 3 -- MAIN_Fosc/32	
  * @param      mode            0: CLK空闲时刻为低电平 在第一个CLK跳边沿 捕获数据
  * @param      mode            1: CLK空闲时刻为低电平 在第二个CLK跳边沿 捕获数据
  * @param      mode            2: CLK空闲时刻为高电平 在第一个CLK跳边沿 捕获数据
  * @param      mode            3: CLK空闲时刻为高电平 在第二个CLK跳边沿 捕获数据 */
#define     SPI_InitP12P13P14P15(bsp, mode)   SPI_USE_P12P13P14P15();SPI_SSIG_None();SPI_Enable();SPI_INT_DISABLE();SPI_MSB_First();SPI_Master();if(mode/2 == 1){SPI_SCLK_NormalH();} else {SPI_SCLK_NormalL();}if(mode%2 == 1) SPI_PhaseH(); else SPI_PhaseL();SPI_Speed(bsp);SPI_SS_1 = 0;
#define     SPI_InitP22P23P24P25(bsp, mode)   SPI_USE_P22P23P24P25();SPI_SSIG_None();SPI_Enable();SPI_INT_DISABLE();SPI_MSB_First();SPI_Master();if(mode/2 == 1){SPI_SCLK_NormalH();} else {SPI_SCLK_NormalL();}if(mode%2 == 1) SPI_PhaseH(); else SPI_PhaseL();SPI_Speed(bsp);SPI_SS_2 = 0;
#if (STC8A != 1)  //STC8A SPI没有下面这组管脚
#define     SPI_InitP54P40P41P43(bsp, mode)   SPI_USE_P54P40P41P43();SPI_SSIG_None();SPI_Enable();SPI_INT_DISABLE();SPI_MSB_First();SPI_Master();if(mode/2 == 1){SPI_SCLK_NormalH();} else {SPI_SCLK_NormalL();}if(mode%2 == 1) SPI_PhaseH(); else SPI_PhaseL();SPI_Speed(bsp);SPI_SS_3 = 0;
#endif
#define     SPI_InitP35P34P33P32(bsp, mode)   SPI_USE_P35P34P33P32();SPI_SSIG_None();SPI_Enable();SPI_INT_DISABLE();SPI_MSB_First();SPI_Master();if(mode/2 == 1){SPI_SCLK_NormalH();} else {SPI_SCLK_NormalL();}if(mode%2 == 1) SPI_PhaseH(); else SPI_PhaseL();SPI_Speed(bsp);SPI_SS_4 = 0;


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
uint8_t  SPI_ReadWriteNByte(uint8_t *txData, uint8_t *rxData, uint8_t len);

#endif
