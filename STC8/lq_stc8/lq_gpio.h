/*!
  * @file     lq_gpio.h
  *
  * @brief    gpio 驱动文件
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
#ifndef __LQ_GPIO_H
#define __LQ_GPIO_H

#include "stc8.h"

/*========================================================================================*/
/*========================================================================================*/
/*=============================GPIO底层 用户无需关心======================================*/
/*========================================================================================*/
/*========================================================================================*/

/**  
 * GPIO 初始化宏定义
 * bitn :管脚标号
 * 例子 PIN0_InitPushPull(5)  //初始化P05 推挽输出模式
 */
#define PIN0_InitStandard(bitn)			P0M1 &= ~(1<<bitn),	P0M0 &= ~(1<<bitn)	/* 00  */
#define PIN0_InitPushPull(bitn)			P0M1 &= ~(1<<bitn),	P0M0 |=  (1<<bitn)	/* 01  */
#define PIN0_InitPureInput(bitn)		P0M1 |=  (1<<bitn),	P0M0 &= ~(1<<bitn)	/* 10  */
#define PIN0_InitOpenDrain(bitn)		P0M1 |=  (1<<bitn),	P0M0 |=  (1<<bitn)	/* 11  */
                                                                     
#define PIN1_InitStandard(bitn)			P1M1 &= ~(1<<bitn),	P1M0 &= ~(1<<bitn)
#define PIN1_InitPushPull(bitn)			P1M1 &= ~(1<<bitn),	P1M0 |=  (1<<bitn)
#define PIN1_InitPureInput(bitn)		P1M1 |=  (1<<bitn),	P1M0 &= ~(1<<bitn)
#define PIN1_InitOpenDrain(bitn)		P1M1 |=  (1<<bitn),	P1M0 |=  (1<<bitn)
                                                                     
#define PIN2_InitStandard(bitn)			P2M1 &= ~(1<<bitn),	P2M0 &= ~(1<<bitn)
#define PIN2_InitPushPull(bitn)			P2M1 &= ~(1<<bitn),	P2M0 |=  (1<<bitn)
#define PIN2_InitPureInput(bitn)		P2M1 |=  (1<<bitn),	P2M0 &= ~(1<<bitn)
#define PIN2_InitOpenDrain(bitn)		P2M1 |=  (1<<bitn),	P2M0 |=  (1<<bitn)
                                                                     
#define PIN3_InitStandard(bitn)			P3M1 &= ~(1<<bitn),	P3M0 &= ~(1<<bitn)
#define PIN3_InitPushPull(bitn)			P3M1 &= ~(1<<bitn),	P3M0 |=  (1<<bitn)
#define PIN3_InitPureInput(bitn)		P3M1 |=  (1<<bitn),	P3M0 &= ~(1<<bitn)
#define PIN3_InitOpenDrain(bitn)		P3M1 |=  (1<<bitn),	P3M0 |=  (1<<bitn)
                                                                     
#define PIN4_InitStandard(bitn)			P4M1 &= ~(1<<bitn),	P4M0 &= ~(1<<bitn)
#define PIN4_InitPushPull(bitn)			P4M1 &= ~(1<<bitn),	P4M0 |=  (1<<bitn)
#define PIN4_InitPureInput(bitn)		P4M1 |=  (1<<bitn),	P4M0 &= ~(1<<bitn)
#define PIN4_InitOpenDrain(bitn)		P4M1 |=  (1<<bitn),	P4M0 |=  (1<<bitn)
                                                                     
#define PIN5_InitStandard(bitn)			P5M1 &= ~(1<<bitn),	P5M0 &= ~(1<<bitn)
#define PIN5_InitPushPull(bitn)			P5M1 &= ~(1<<bitn),	P5M0 |=  (1<<bitn)
#define PIN5_InitPureInput(bitn)		P5M1 |=  (1<<bitn),	P5M0 &= ~(1<<bitn)
#define PIN5_InitOpenDrain(bitn)		P5M1 |=  (1<<bitn),	P5M0 |=  (1<<bitn)
                                                                     
#define PIN6_InitStandard(bitn)			P6M1 &= ~(1<<bitn),	P6M0 &= ~(1<<bitn)
#define PIN6_InitPushPull(bitn)			P6M1 &= ~(1<<bitn),	P6M0 |=  (1<<bitn)
#define PIN6_InitPureInput(bitn)		P6M1 |=  (1<<bitn),	P6M0 &= ~(1<<bitn)
#define PIN6_InitOpenDrain(bitn)		P6M1 |=  (1<<bitn),	P6M0 |=  (1<<bitn)
                                                                     
#define PIN7_InitStandard(bitn)			P7M1 &= ~(1<<bitn),	P7M0 &= ~(1<<bitn)
#define PIN7_InitPushPull(bitn)			P7M1 &= ~(1<<bitn),	P7M0 |=  (1<<bitn)
#define PIN7_InitPureInput(bitn)		P7M1 |=  (1<<bitn),	P7M0 &= ~(1<<bitn)
#define PIN7_InitOpenDrain(bitn)		P7M1 |=  (1<<bitn),	P7M0 |=  (1<<bitn)


#define Pin_InitStandard(N, bitn)		PIN##N##_InitStandard(bitn)	/* 00  */
#define Pin_InitPushPull(N, bitn)		PIN##N##_InitPushPull(bitn)	/* 01  */
#define Pin_InitPureInput(N, bitn)		PIN##N##_InitPureInput(bitn)	/* 10  */
#define Pin_InitOpenDrain(N, bitn)		PIN##N##_InitOpenDrain(bitn)	/* 11  */

#define PIn(N, bitn)                      P##N##bitn


/**  
 * STC8G 系列每个GPIO均新增了一个4.1K的上拉电阻  
 * bitn :管脚标号
 * 例子 PIN0_EnablePullUp(5)  //P05 管脚开启内部4.1K上拉电阻
 */
#define PIN0_EnablePullUp(bitn)       EAXSFR(),P0PU |=  (1<<bitn), EAXRAM()
#define PIN1_EnablePullUp(bitn)       EAXSFR(),P1PU |=  (1<<bitn), EAXRAM()
#define PIN2_EnablePullUp(bitn)       EAXSFR(),P2PU |=  (1<<bitn), EAXRAM()
#define PIN3_EnablePullUp(bitn)       EAXSFR(),P3PU |=  (1<<bitn), EAXRAM()
#define PIN4_EnablePullUp(bitn)       EAXSFR(),P4PU |=  (1<<bitn), EAXRAM()
#define PIN5_EnablePullUp(bitn)       EAXSFR(),P5PU |=  (1<<bitn), EAXRAM()
#define PIN6_EnablePullUp(bitn)       EAXSFR(),P6PU |=  (1<<bitn), EAXRAM()
#define PIN7_EnablePullUp(bitn)       EAXSFR(),P7PU |=  (1<<bitn), EAXRAM()

#define PIN0_DisablePullUp(bitn)       EAXSFR(),P0PU &=  ~(1<<bitn), EAXRAM()
#define PIN1_DisablePullUp(bitn)       EAXSFR(),P1PU &=  ~(1<<bitn), EAXRAM()
#define PIN2_DisablePullUp(bitn)       EAXSFR(),P2PU &=  ~(1<<bitn), EAXRAM()
#define PIN3_DisablePullUp(bitn)       EAXSFR(),P3PU &=  ~(1<<bitn), EAXRAM()
#define PIN4_DisablePullUp(bitn)       EAXSFR(),P4PU &=  ~(1<<bitn), EAXRAM()
#define PIN5_DisablePullUp(bitn)       EAXSFR(),P5PU &=  ~(1<<bitn), EAXRAM()
#define PIN6_DisablePullUp(bitn)       EAXSFR(),P6PU &=  ~(1<<bitn), EAXRAM()
#define PIN7_DisablePullUp(bitn)       EAXSFR(),P7PU &=  ~(1<<bitn), EAXRAM()

#define Pin_EnablePullUp(N, bitn)		PIN##N##_EnablePullUp(bitn)	
#define Pin_DisablePullUp(N, bitn)		PIN##N##_DisablePullUp(bitn)	


/*========================================================================================*/
/*========================================================================================*/
/*==================================GPIO用户API===========================================*/
/*========================================================================================*/
/*========================================================================================*/

/*
	GPIO初始化需要两步 
	1. 确定IO工作模式                 
        	PIN_InitPushPull(0, 5)  //初始化P05 推挽输出模式
			
	2. 确定是否启用IO的4.1K上拉电阻 
        	PIN_EnablePullUp(0, 5)  //P05 管脚开启内部4.1K上拉电阻
*/



/*
PnM1    PnM0    I/O 口工作模式
0        0      准双向口（传统8051端口模式，弱上拉）
                灌电流可达20mA，拉电流为270～150μA（存在制造误差）
				
0        1      推挽输出（强上拉输出，可达20mA，要加限流电阻）

1        0      高阻输入（电流既不能流入也不能流出） ADC管脚使用该模式

1        1      开漏输出（ Open-Drain），内部上拉电阻断开
                开漏模式既可读外部状态也可对外输出（高电平或低电
                平）。如要正确读外部状态或需要对外输出高电平，需外加
                上拉电阻，否则读不到外部状态，也对外输不出高电平
*/

/**  
 * GPIO 初始化宏定义
 * N    :管脚Port  例如 P20管脚的Port为 2
 * bitn :管脚标号  例如 P20管脚的标号为 0
 * 例子 PIN_InitPushPull(2, 5)  //初始化P25 推挽输出模式
 */                   
#define PIN_InitStandard(N, bitn)		Pin_InitStandard(N, bitn)	/* 00  */
#define PIN_InitPushPull(N, bitn)		Pin_InitPushPull(N, bitn)	/* 01  */
#define PIN_InitPureInput(N, bitn)		Pin_InitPureInput(N, bitn)	/* 10  */
#define PIN_InitOpenDrain(N, bitn)		Pin_InitOpenDrain(N, bitn)	/* 11  */

#define P(N, bitn)                      PIn(N, bitn)


/**  
 * STC8G 系列每个GPIO均新增了一个4.1K的上拉电阻  
 * bitn :管脚标号
 * 例子 PIN_EnablePullUp(0, 5)  //P05 管脚开启内部4.1K上拉电阻
 */
#define PIN_EnablePullUp(N, bitn)       Pin_EnablePullUp(N, bitn)
#define PIN_DisablePullUp(N, bitn)      Pin_DisablePullUp(N, bitn)

/*========================================================================================*/
/*========================================================================================*/
/*==================================GPIO外部中断==========================================*/
/*========================================================================================*/
/*========================================================================================*/

/*
	STC8只有5个管脚有外部中断功能 
	INT0  外部中断管脚 P32  
	INT1  外部中断管脚 P33 
	INT2  外部中断管脚 P36 
	INT3  外部中断管脚 P37 
	INT4  外部中断管脚 P30 

	GPIO外部中断初始化需要
	1. 确定IO工作模式  
	        PIN_InitStandard(3, 2);
			
	2. 确定是否启用IO的4.1K上拉电阻
			PIN_EnablePullUp(3, 2);
			
	3. 确定GPIO 触发中断方式(INT0 INT1 可以配置中断触发方式 INT2 INT3 INT4 只可以下降沿触发中断)
			INT0_Fall();
			
	4. 设置中断优先级(设置中断优先级 n范围： 0-3  3优先级最高，如果不设置默认优先级0) 
			SET_INT0_PRIORITY(1);  //设置INT0 中断优先级
	
	5. 开启中断
			INT0_Enable();
	
	6. 编写中断服务函数（INT2 INT3 INT4 需要在中断服务函数中清除中断标志位）(中断服务函数默认写在irq.c中)
			void INT0Tnterrupt()   interrupt    0
			{
				
			}
			
*/

/* T0 T1 可以配置中断触发方式 T2 T3 T4 只可以下降沿触发中断 */
#define	INT0_Fall()		IT0 = 1		/* INT0 下降沿中断           */
#define	INT0_RiseFall()	IT0 = 0		/* INT0 下降沿上升沿均中断   */
#define	INT1_Fall()		IT1 = 1		/* INT1 下降沿中断           */
#define	INT1_RiseFall()	IT0 = 0		/* INT1 下降沿上升沿均中断   */


//                                     7    6    5    4    3     2       1       0      Reset Value
//INT_CLKO:  中断与时钟输出控制寄存器  -   EX4  EX3  EX2   -   T2CLKO  T1CLKO  T0CLKO    0000,0000
#define	INT4_Enable()	INT_CLKO |= (1 << 6)
#define	INT3_Enable()	INT_CLKO |= (1 << 5)	
#define	INT2_Enable()	INT_CLKO |= (1 << 4)	
#define	INT1_Enable()	EX1 = 1
#define	INT0_Enable()	EX0 = 1

#define	INT4_Disable()	INT_CLKO &= ~(1 << 6)
#define	INT3_Disable()	INT_CLKO &= ~(1 << 5)	
#define	INT2_Disable()	INT_CLKO &= ~(1 << 4)	
#define	INT1_Disable()	EX1 = 0
#define	INT0_Disable()	EX0 = 0


//                               7    6       5       4      3    2     1     0      Reset Value
//AUXINTIF:  辅助中断标志寄存器  -  INT4IF  INT3IF  INT2IF   -   T4IF  T3IF  T2IF    0000,0000
#define	INT4IF	0x40
#define	INT3IF	0x20
#define	INT2IF	0x10


#define	INT4_Clear()	AUXINTIF &= ~INT4IF		/* 清除外中断4标志位 需手动清除 */
#define	INT3_Clear()	AUXINTIF &= ~INT3IF		/* 清除外中断3标志位 需手动清除 */
#define	INT2_Clear()	AUXINTIF &= ~INT2IF		/* 清除外中断2标志位 需手动清除 */
#define	INT1_Clear()	IE1 = 0					/* 清除外中断1标志位 硬件自动清除 */
#define	INT0_Clear()	IE0 = 0					/* 清除外中断0标志位 硬件自动清除 */


#endif
