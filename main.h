/*!
  * @file     main.c
  *
  * @brief    STC8H
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
#ifndef __LQ_MAIN_H
#define __LQ_MAIN_H

/* 51 底层头文件 */
#include "stc8.h"
#include "math.h"
#include "stdlib.h"
#include "intrins.h"
#include "stdio.h"
#include "lq_adc.h"
#include "lq_enc.h"
#include "lq_gpio.h"
#include "lq_pwm.h"
#include "lq_spi.h"
#include "lq_timer.h"
#include "lq_uart.h"
#include "lq_softiic.h"
#include "lq_eeprom.h"

/* 模块驱动头文件 */
#include "lq_led.h"
#include "lq_key.h"
#include "lq_oled.h"
#include "lq_mpu6050.h"
#include "lq_icm20602.h"
#include "lq_9ax.h"
#include "ANO_DT.h"

#include "Motor.h"
#include "PID.h"
#include "Value.h"
#include "eeprom.h"
#include "Enc.h"
#include "filter.h"
#include "BLE.h"
#include "ADC.h"
#include "CCD.h"

#define OLED_DBG	0
#define DEBUG		1
#define RGB_Init	PIN_InitStandard(2, 5);PIN_EnablePullUp(2, 5);PIN_InitStandard(2, 6);PIN_EnablePullUp(2, 6);PIN_InitStandard(2, 7);PIN_EnablePullUp(2, 7)
#define BEEP_Init	PIN_InitStandard(0, 4);PIN_EnablePullUp(0, 4)
#define Dial_Init	PIN_InitStandard(0, 1);PIN_EnablePullUp(0, 1);PIN_InitStandard(0, 0);PIN_EnablePullUp(0, 0)
#define R			P(2, 7)
#define G			P(2, 6)
#define B			P(2, 5)
#define BEEP		P(0, 4)
#define Dial1 		P(0, 1)
#define Dial2 		P(0, 0)

#endif
