/*!
  * @file     ANO_DT.h
  *
  * @brief    匿名上位机驱动
  *
  * @company  匿名
  *
  * @author   匿名
  *
  * @note     无
  *
  * @version  V1.1  2019/12/06 优化注释 Doxygen
  *
  * @Software IAR8.32 or MDK5.28
  *
  * @par URL  http://shop36265907.taobao.com
  *           http://www.lqist.cn
  *
  * @date     2019/10/18 星期五
  */ 
#ifndef __ANO_DT_H
#define __ANO_DT_H

#include "stc8.h"

/*!
  * @brief    向上位机发送发送8个int16_t数据
  *
  * @param    data1 - data8  ： 发送给上位机显示波形
  *
  * @return   无
  *
  * @note     无
  *
  * @see      ANO_DT_send_int16(1, 2, 3, 0, 0, 0, 0, 0);
  *
  * @date     2019/5/28 星期二
  */
void ANO_DT_send_int16(int16_t data1, int16_t data2, int16_t data3, int16_t data4, int16_t data5, int16_t data6, int16_t data7, int16_t data8);






	
#endif

