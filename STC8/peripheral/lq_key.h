/*!
  * @file     LQ_KEY.h
  *
  * @brief    按键驱动文件
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
  * @date     2019/10/18 星期五
  */ 
#ifndef __LQ_KEY_H
#define __LQ_KEY_H

#include "LQ_GPIO.h"

#if (STC8A == 1)

/* 按键管脚定义 */   
#define KEY0_PORT       4            /*!<  @brief    按键 的port  */
#define KEY0_PIN        1            /*!<  @brief    按键 的Pin   */
												
#define KEY1_PORT       4            /*!<  @brief    按键 的port  */
#define KEY1_PIN        2            /*!<  @brief    按键 的Pin   */
													
#define KEY2_PORT       2            /*!<  @brief    按键 的port  */
#define KEY2_PIN        7            /*!<  @brief    按键 的Pin   */

#else

/* 按键管脚定义 */   
#define KEY0_PORT       2            /*!<  @brief    按键 的port  */
#define KEY0_PIN        0            /*!<  @brief    按键 的Pin   */
												
#define KEY1_PORT       5            /*!<  @brief    按键 的port  */
#define KEY1_PIN        2            /*!<  @brief    按键 的Pin   */
													
#define KEY2_PORT       5            /*!<  @brief    按键 的port  */
#define KEY2_PIN        3            /*!<  @brief    按键 的Pin   */

#endif

/**
  * @brief    初始化龙邱母板上的按键
  *
  * @param    无
  *
  * @return   无
  *
  * @note     按键IO在LQ_KEY.h中通过宏定义选择
  *
  * @see      KEY_Init();
  *
  * @date     2019/6/4 星期二
  */
void KEY_Init(void);


/**
  * @brief    读取按键状态
  *
  * @param    mode： 0：不支持连续按;   1：支持连续按;
  *
  * @return   0：无按键按下  1：KEY0按下  2:KEY1按下  3:KEY2按下
  *
  * @note     使用前请先初始化按键
  *
  * @see      uint8_t key_flag = KEY_Read(0);
  *
  * @date     2019/6/4 星期二
  */
uint8_t KEY_Read(uint8_t mode);







#endif