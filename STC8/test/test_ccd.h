/*!
  * @file     test_ccd.h
  *
  * @brief    STC8
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

#ifndef __TEST_CCD_H
#define __TEST_CCD_H

#include "stc8.h"

/**
  * @brief    CCD管脚初始化
  *
  * @param    无
  *
  * @return   无
  *
  * @note     
  *
  * @example  
  *
  * @date     2020/4/22 星期一
*/
void CCD_Init(void) ;

/**
  * @brief    CCD采集函数
  *
  * @param    p  ：  存放采集数据的首地址
  *
  * @return   无
  *
  * @note     
  *
  * @example  uint16_t ccd_buf[128];
  *           CCD_Collect(ccd_buf); 
  *
  * @date     2020/4/22 
*/
void CCD_Collect(uint16_t *p) ;


/**
  * @brief    测试CCD  OLED画图 并上报上位机 
  *
  * @param    无
  *
  * @return   无
  *
  * @note     
  *
  * @example  
  *
  * @date     2020/4/22 星期一
*/
void Test_CCD(void);



#endif