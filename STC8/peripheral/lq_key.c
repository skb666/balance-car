/*!
  * @file     LQ_KEY.c
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
#include "lq_key.h"
#include "lq_gpio.h"

/** 声明外部延时函数 */
extern void delayms(uint32_t ms);




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
void KEY_Init(void)
{  
    /* 设置上拉输入 */
    PIN_InitStandard(KEY0_PORT,  KEY0_PIN);
    PIN_InitStandard(KEY1_PORT,  KEY1_PIN);
    PIN_InitStandard(KEY2_PORT,  KEY2_PIN); 
	
	PIN_EnablePullUp(KEY0_PORT,  KEY0_PIN);
	PIN_EnablePullUp(KEY1_PORT,  KEY1_PIN);
	PIN_EnablePullUp(KEY2_PORT,  KEY2_PIN); 
}


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
uint8_t KEY_Read(uint8_t mode)
{
    static uint8_t xdata key_up=1;     //按键松开标志
    if(mode==1) 
    {
        key_up=1;      //支持连按
    }
    if(key_up && (P(KEY0_PORT,  KEY0_PIN)==0 || P(KEY1_PORT,  KEY1_PIN)==0 || P(KEY2_PORT,  KEY2_PIN)==0))
    {
        delayms(10);   //消抖
        key_up=0;
        if(P(KEY0_PORT,  KEY0_PIN)==0)      
        {
            return 1;
        }
        
        else if(P(KEY1_PORT,  KEY1_PIN)==0) 
        {
            return 2;    
        }
        
        else if(P(KEY2_PORT,  KEY2_PIN)==0) 
        {
            return 3;    
        }
        
    }
    if(P(KEY0_PORT,  KEY0_PIN)==1 && P(KEY1_PORT,  KEY1_PIN)==1 && P(KEY2_PORT,  KEY2_PIN)==1) 
    {
        key_up=1;   
    }
    return 0;   //无按键按下
    
}








