/*!
  * @file     lq_led.h
  *
  * @brief    led驱动
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
#ifndef __LQ_LED_H__
#define __LQ_LED_H__

#include "lq_gpio.h"

/** 
  * @brief RGB LED颜色枚举体
  */ 
typedef enum
{
  white = 0,  /*!<白色 */
  black = 1,  /*!<黑色 */
  red   = 2,  /*!<红   */
  green = 3,  /*!<绿   */
  blue  = 4,  /*!<蓝色 */
  yellow= 5,  /*!<黄色 */
  violet= 6,  /*!<紫色 */
  cyan  = 7,  /*!<青色 */
}LED_t;


/* STC8A 核心板RGB灯 */
#if (STC8A == 1)

/* LED管脚定义 */
#define LED_R_PORT       4            /*!<  @brief    核心板RGB灯 R灯的port  */
#define LED_R_PIN        4            /*!<  @brief    核心板RGB灯 R灯的Pin   */

#define LED_G_PORT       4            /*!<  @brief    核心板RGB灯 G灯的port  */
#define LED_G_PIN        0            /*!<  @brief    核心板RGB灯 G灯的Pin   */

#define LED_B_PORT       5            /*!<  @brief    核心板RGB灯 G灯的port  */
#define LED_B_PIN        5            /*!<  @brief    核心板RGB灯 G灯的Pin   */



#else  /* STC8H 核心板RGB灯 */

/* LED管脚定义 */
#define LED_R_PORT       2            /*!<  @brief    核心板RGB灯 R灯的port  */
#define LED_R_PIN        7            /*!<  @brief    核心板RGB灯 R灯的Pin   */

#define LED_G_PORT       4            /*!<  @brief    核心板RGB灯 G灯的port  */
#define LED_G_PIN        5            /*!<  @brief    核心板RGB灯 G灯的Pin   */

#define LED_B_PORT       4            /*!<  @brief    核心板RGB灯 G灯的port  */
#define LED_B_PIN        6            /*!<  @brief    核心板RGB灯 G灯的Pin   */

#endif

/*!
  * @brief    LED初始化
  *
  * @param    
  *
  * @return   
  *
  * @note     
  *
  * @example  LED_Init();
  *
  * @date     2019/8/6 星期二
  */
void LED_Init(void);

/**
  * @brief    指定颜色的灯亮
  *
  * @param    color  ： 枚举LED_t中的颜色
  *
  * @return   
  *
  * @note     
  *
  * @example  LED_Color(red);   //红灯亮
  *
  * @date     2019/6/4 星期二
  */
void LED_Color(LED_t color);

/**
  * @brief    指定颜色闪烁
  *
  * @param    color  ： 枚举LED_t中的颜色
  *
  * @return   
  *
  * @note     
  *
  * @example  LED_ColorReverse(red); //翻转红灯
  *
  * @date     2019/6/4 星期二
  */
void LED_ColorReverse(LED_t color);





#endif 