/*!
  * @file     lq_enc.h
  *
  * @brief    带方向编码器 驱动文件
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
#ifndef __LQ_ENC_H
#define __LQ_ENC_H

#include "stc8.h"
#include "lq_timer.h"

/* 用于暂存定时器高位 */
extern volatile uint8_t  xdata timerL;

/*========================================================================================*/
/*========================================================================================*/
/*=====================================编码器 API =========================================*/
/*========================================================================================*/
/*========================================================================================*/
/*
	编码器需要使用带方向编码器  51单片机可以使用TIEMR对外部脉冲进行计数 
	TImer0 脉冲计数管脚 P34
    TImer1 脉冲计数管脚 P35
    TImer2 脉冲计数管脚 P12
    TImer3 脉冲计数管脚 P04
    TImer4 脉冲计数管脚 P06
	
	获取编码器脉冲读数 需要
	1.初始化定时器 
		TIMER3_EncInit();
		
	2.读取定时器值
		uint16_t xdata encValue = 0;
		TIMER3_GetValue(encValue);

*/
                               
#define  TIMER0_EncInit()      Timer0_AsCounterP34(),Timer0_16bitAutoReload(),Timer0_1T(),Timer0_InterruptDisable(),T0_Load(0),Timer0_Run()
#define  TIMER1_EncInit()      Timer1_AsCounterP35(),Timer1_16bitAutoReload(),Timer1_1T(),Timer1_InterruptDisable(),T1_Load(0),Timer1_Run()
#define  TIMER2_EncInit()      Timer2_AsCounterP12(),Timer2_1T(),Timer2_InterruptDisable(),T2_Load(0),Timer2_Run()
#define  TIMER3_EncInit()      Timer3_AsCounterP04(),Timer3_1T(),Timer3_InterruptDisable(),T3_Load(0),Timer3_Run()
#define  TIMER4_EncInit()      Timer4_AsCounterP06(),Timer4_1T(),Timer4_InterruptDisable(),T4_Load(0),Timer4_Run()

#define Timer_EncInit(n)       TIMER##n##_EncInit()
/**
 * 初始化定时器 脉冲计数功能
 * n : 定时器N
 */
 #define TIMER_EncInit(n)       Timer_EncInit(n)


/* 获取定时器读数  value为16位无符号值 */
#define  TIMER0_GetValue(value){do\
								{\
									value   = TH0;\
									timerL  = TL0;\
								}while(value != TH0);\
								Timer0_Stop();\
								T0_Load(0);\
								Timer0_Run();\
								value = value << 8 | timerL;}

#define  TIMER1_GetValue(value){do\
								{\
									value   = TH1;\
									timerL  = TL1;\
								}while(value != TH1);\
								Timer1_Stop();\
								T1_Load(0);\
								Timer1_Run();\
								value = value << 8 | timerL;}

#define  TIMER2_GetValue(value){do\
								{\
									value   = TH2;\
									timerL  = TL2;\
								}while(value != TH2);\
								Timer2_Stop();\
								T2_Load(0);\
								Timer2_Run();\
								value = value << 8 | timerL;}

#define  TIMER3_GetValue(value){do\
								{\
									value   = TH3;\
									timerL  = TL3;\
								}while(value != TH3);\
								Timer3_Stop();\
								T3_Load(0);\
								Timer3_Run();\
								value = value << 8 | timerL;}

#define  TIMER4_GetValue(value){do\
								{\
									value   = TH4;\
									timerL  = TL4;\
								}while(value != TH4);\
								Timer4_Stop();\
								T4_Load(0);\
								Timer4_Run();\
								value = value << 8 | timerL;}

 

 #define Timer_GetValue(n, value)       TIMER##n##_GetValue(value)
/**
 * 初始化定时器 脉冲计数功能
 * n : 定时器N
 */
 #define TIMER_GetValue(n, value)       Timer_GetValue(n, value)
 
 
 
#endif
