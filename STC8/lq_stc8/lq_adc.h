/*!
  * @file     lq_adc.h
  *
  * @brief    adc 驱动文件
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

#ifndef __LQ_ADC_H__
#define __LQ_ADC_H__

#include "stc8.h"
#include "intrins.h"
#include "lq_gpio.h"


/*========================================================================================*/
/*========================================================================================*/
/*===========================ADC底层驱动 用户无需关心===================================*/
/*========================================================================================*/
/*========================================================================================*/

//ADC 特殊功能寄存器
//sfr ADC_CONTR   =   0xbc;
#define ADC_POWER   0x80
#define ADC_START   0x40
#define ADC_FLAG    0x20
//sfr ADC_RES     =   0xbd;
//sfr ADC_RESL    =   0xbe;
//sfr ADCCFG      =   0xde;
#define ADC_RESFMT  0x20

/* 设置 ADC 左对齐 ADC_RES 存放ADC转换结果高8位   ADC_RESL 高位存放剩下结果 */
#define Adc_Left            ADCCFG  &= ~ADC_RESFMT

/* 设置 ADC 右对齐 ADC_RESL 存放ADC转换结果低8位  ADC_RES  低位存放剩下结果*/
#define Adc_Right           ADCCFG  |= ADC_RESFMT

/* 设置 ADC 时钟  ADC时钟 = 系统时钟/2/(Div+1)   Div范围 0-15 */
#define Adc_SetDiv(Div)     ADCCFG  &= 0xf0, ADCCFG |= Div

/* 打开ADC模块电源 */
#define Adc_Power()         ADC_CONTR = ADC_POWER 

/* 配置ADC模块 */
#define Adc_InitConfig()    Adc_Right, Adc_SetDiv(0), Adc_Power() 

/* 配置ADC转换通道*/
#define Adc_SetChannel(channel) ADC_CONTR &= 0xf0, ADC_CONTR |= channel

/* 启动ADC转换 */
#define Adc_Start()         ADC_CONTR |= 0x40

/* ADC中断使能 */
#define Adc_EnableInterrupt()  EADC = 1

/* ADC中断关闭 */
#define Adc_DisableInterrupt() EADC = 0

/* 清除 ADC中断标志位*/
#define ADC_Clear()            ADC_CONTR &= ~(1<<5)

/*========================================================================================*/
/*========================================================================================*/
/*===========================ADC 用户API =================================================*/
/*========================================================================================*/
/*========================================================================================*/
/*
	SCT8H 有15个ADC通道 每个通道对应管脚如下
	0     P1.0          8  P0.0
    1     P1.1          9  P0.1
    2     P5.4          10 P0.2
    3     P1.3          11 P0.3
    4     P1.4          12 P0.4
    5     P1.5          13 P0.5
    6     P1.6          14 P0.6
    7     P1.7          15 测试内部 1.19V
	
	SCT8G/STC8A 有15个ADC通道 每个通道对应管脚如下
	0     P1.0          8  P0.0
    1     P1.1          9  P0.1
    2     P1.2          10 P0.2
    3     P1.3          11 P0.3
    4     P1.4          12 P0.4
    5     P1.5          13 P0.5
    6     P1.6          14 P0.6
    7     P1.7          15 测试内部 1.19V
	
	注意 STC8A和STC8H8为12位ADC  8G为10位ADC
	
	读取ADC通道值
	1. ADC通道初始化
		ADC0_Init();    //初始化P10为ADC通道
		
	2. 读取ADC通道值
		uint16_t xdata adcValue = 0;
		ADC_GetValue(0, adcValue);
*/

/* 初始化ADC 通道 */
#define ADC0_Init()         PIN1_InitPureInput(0), Adc_InitConfig()
#define ADC1_Init()         PIN1_InitPureInput(1), Adc_InitConfig()
#if (STC8H == 1)
#define ADC2_Init()         PIN5_InitPureInput(4), Adc_InitConfig()
#else
#define ADC2_Init()         PIN1_InitPureInput(2), Adc_InitConfig()
#endif
#define ADC3_Init()         PIN1_InitPureInput(3), Adc_InitConfig()
#define ADC4_Init()         PIN1_InitPureInput(4), Adc_InitConfig()
#define ADC5_Init()         PIN1_InitPureInput(5), Adc_InitConfig()
#define ADC6_Init()         PIN1_InitPureInput(6), Adc_InitConfig()
#define ADC7_Init()         PIN1_InitPureInput(7), Adc_InitConfig()
#define ADC8_Init()         PIN0_InitPureInput(0), Adc_InitConfig()
#define ADC9_Init()         PIN0_InitPureInput(1), Adc_InitConfig()
#define ADC10_Init()        PIN0_InitPureInput(2), Adc_InitConfig()
#define ADC11_Init()        PIN0_InitPureInput(3), Adc_InitConfig()
#define ADC12_Init()        PIN0_InitPureInput(4), Adc_InitConfig()
#define ADC13_Init()        PIN0_InitPureInput(5), Adc_InitConfig()
#define ADC14_Init()        PIN0_InitPureInput(6), Adc_InitConfig()

#define Adc_Init(channel)   ADC##channel##_Init()

/**
 * 初始化ADC通道值 
 * channel : ADC通道
 */
#define ADC_Init(channel)   Adc_Init(channel)

/**
 * 获取ADC通道值 
 * channel : ADC通道
 * value   : 存放通道值
 */
#define ADC_GetValue(channel, value)       {Adc_SetChannel(channel);\
											Adc_Start();\
											_nop_();\
											_nop_();\
											while (!(ADC_CONTR & 0x20));\
											ADC_CONTR &= ~0x20;\
											value = ADC_RES<<8 | ADC_RESL;}


#endif 
