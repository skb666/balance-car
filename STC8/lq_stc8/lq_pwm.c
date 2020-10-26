/*!
  * @file     lq_pwm.c
  *
  * @brief    pwm驱动文件
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


#include "lq_pwm.h"

/* pwm API在lq_pwm.h中 */




/* STC8G  */
#if (STC8G == 1)

/** PWM 周期时钟数 */
uint16_t xdata PWM_Period[6];

#elif (STC8A == 1)

/** PWM 周期时钟数 */
uint16_t xdata PWM_Period;

#elif (STC8H == 1)

/** PWM 周期时钟数 */
uint16_t xdata PWM_Period[3];


#endif


