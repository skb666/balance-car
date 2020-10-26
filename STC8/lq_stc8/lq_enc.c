/*!
  * @file     lq_enc.c
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

#include "lq_enc.h"

/* 用于暂存定时器高位 */
volatile uint8_t  xdata timerL = 0;

/* 编码器 API在lq_enc.h中 */

