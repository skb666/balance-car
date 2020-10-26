/*!
  * @file     LQ_12864.h
  *
  * @brief    OLED驱动
  *
  * @company  北京龙邱智能科技
  *
  * @author   LQ-005
  *
  * @note     Tab键 4个空格
  *
  * @version  V1.1  2019/12/06 优化注释 Doxygen
  *
  * @Software IAR8.32 or MDK5.28
  *
  * @par URL  http://shop36265907.taobao.com
  *           http://www.lqist.cn
  *
  * @date     2019/11/11 星期一
  */ 
#ifndef _LQOLED_H
#define _LQOLED_H

#include "stc8.h"

/*!
  * @brief    OLED初始化
  *
  * @param    无
  *
  * @return   无
  *
  * @note     如果修改管脚 需要修改初始化的管脚 
  *
  * @see      OLED_Init();
  *
  * @date     2019/6/13 星期四
  */
void OLED_Init(void);

/*!
  * @brief    OLED全亮
  *
  * @param    无   
  *
  * @return   无
  *
  * @note     无
  *
  * @see      OLED_Fill(); //OLED全亮 用于检测坏点
  *
  * @date     2019/6/13 星期四
  */
void OLED_Fill(void);

/*!
  * @brief    OLED清屏
  *
  * @param    无  
  *
  * @return   无
  *
  * @note     无
  *
  * @see      OLED_CLS(); //清屏
  *
  * @date     2019/6/13 星期四
  */
void OLED_CLS(void);

/*!
  * @brief    画一个点
  *
  * @param    x  : 0-127 
  * @param    y  : 0-63
  *
  * @return   无
  *
  * @note     OLED是按字节显示的 一个字节8位，代表8个纵向像素点，
  * @note     因此如果画点 OLED_PutPixel(0,0); OLED_PutPixel(0,1); 只会显示点(0, 1) (0,0)则在画点(0,1)时清除掉
  *
  * @see      OLED_PutPixel(0, 0); //画一个点 左上角为0,0  右下角 127,63
  *
  * @date     2019/6/13 星期四
  */
void OLED_PutPixel(unsigned char x,unsigned char y);

/*!
  * @brief    清除8个点
  *
  * @param    x  : 0-127
  * @param    y  : 0-63
  *
  * @return   无
  *
  * @note     OLED是按字节显示的 一个字节8位，代表8个纵向像素点，
  *
  * @see      OLED_ClrDot(0, 0); //清除(0,0)-(0,7)8个点 左上角为0,0  右下角 127,63
  *
  * @date     2019/6/13 星期四
  */
void OLED_ClrDot(unsigned char x,unsigned char y);

/*!
  * @brief    画矩形
  *
  * @param    x1  : 0-127   左上角坐标（x1,y1）
  * @param    y1  : 0-63
  * @param    x2  : 0-127   右下角坐标（x2，y2）
  * @param    y2  : 0-63
  * @param    gif : 是否开启动画效果
  *
  * @return   无
  *
  * @note     无
  *
  * @see      OLED_Rectangle(0, 0, 127,62,0);   //绘制矩形
  *
  * @date     2019/6/13 星期四
  */
void OLED_Rectangle(unsigned char x1,unsigned char y1,unsigned char x2,unsigned char y2,unsigned char gif);

/*!
  * @brief    写入一组标准ASCII字符串
  *
  * @param    x  : 0-127   
  * @param    y  : 0-7
  * @param    ch : 要显示的字符串
  *
  * @return   无
  *
  * @note     无
  *
  * @see      OLED_P6x8Str(0,0,"OLED 3.");  //显示字符串
  *
  * @date     2019/6/13 星期四
  */
void OLED_P6x8Str(unsigned char x,unsigned char y, char ch[]);

/*!
  * @brief    写入一组标准ASCII字符串
  *
  * @param    x  : 0-127   
  * @param    y  : 0-6
  * @param    ch : 要显示的字符串
  *
  * @return   无
  *
  * @note     一个字符高16  OLED高度64  
  *
  * @see      OLED_P8x16Str(0,0,"OLED 3.");  //显示字符串
  *
  * @date     2019/6/13 星期四
  */
void OLED_P8x16Str(unsigned char x,unsigned char y, char ch[]);

/*!
  * @brief    输出汉字字符串
  *
  * @param    x  : 0-127   
  * @param    y  : 0-6
  * @param    ch : 要显示的字符串
  *
  * @return   无
  *
  * @note     一个字符高16  OLED高度64   字库需要自己制作
  *
  * @see      OLED_P14x16Str(0,4,"北京龙邱");   //显示汉字
  *
  * @date     2019/6/13 星期四
  */
void OLED_P14x16Str(unsigned char x,unsigned char y, char ch[]);



/*!
  * @brief    显示BMP图片 最大 128×64
  *
  * @param    x0  : 0-127   左上角坐标（x0,y0）
  * @param    y0  : 0-63
  * @param    wide: 1-127   图片宽度
  * @param    high: 1-64    图片高度
  * @param    bmp : 要显示的图片
  *
  * @return   无
  *
  * @note     图片需要用软件转化
  *
  * @see      OLED_Show_BMP(0, 0, 104, 64, longqiu104x64); //画龙邱loge
  *
  * @date     2019/6/13 星期四
  */
void OLED_Show_BMP(unsigned char x0,unsigned char y0,unsigned char wide,unsigned char high,const uint8_t * bmp);

/*!
  * @brief    显示龙邱图片128×64
  *
  * @param    无 
  *
  * @return   无
  *
  * @note     无
  *
  * @see      OLED_Show_LQLogo();
  *
  * @date     2019/6/13 星期四
  */
void OLED_Show_LQLogo(void);



/*!
  * @brief    OLED命令
  *
  * @param    cmd ：命令
  *
  * @return   无
  *
  * @note     无
  *
  * @see      内部调用
  *
  * @date     2019/6/13 星期四
  */
void OLED_WrCmd(unsigned char cmd);


/*!
  * @brief    OLED画点命令
  *
  * @param    data ：要画的点
  *
  * @return   无
  *
  * @note     无
  *
  * @see      内部调用
  *
  * @date     2019/6/13 星期四
  */
void OLED_WrDat(unsigned char dat);


/*!
  * @brief    OLED设置点
  *
  * @param    x ：坐标   
  * @param    y ：坐标
  *
  * @return   无
  *
  * @note     无
  *
  * @see      内部调用
  *
  * @date     2019/6/13 星期四
  */
void OLED_Set_Pos(unsigned char x, unsigned char y);
	


#endif


