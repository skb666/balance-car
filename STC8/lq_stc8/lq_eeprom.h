/*!
  * @file     lq_eeprom.h
  *
  * @brief    eeprom 驱动文件
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
#ifndef __LQ_EEPROM_H
#define __LQ_EEPROM_H

#include "stc8.h"


/*========================================================================================*/
/*========================================================================================*/
/*===============================EEPROM底层 用户无需关心==================================*/
/*========================================================================================*/
/*========================================================================================*/

/* 加载EEPROM地址 */
#define		Iap_LoadAddr(n)					IAP_ADDRH = (n) / 256,	IAP_ADDRL = (n) % 256

/* eeprom 读取 吸入 擦出命令 */
#define     Iap_ReadEepromCmd()             IAP_CMD = 1
#define     Iap_WriteEepromCmd()            IAP_CMD = 2
#define     Iap_EraseEepromCmd()            IAP_CMD = 3

/* 触发命令 */
#define     Iap_TrigCmd()                   IAP_TRIG = 0x5a; IAP_TRIG = 0xa5;

/* EEPROM操作失败标志位 */
#define     Iap_IsOK()                      (IAP_CONTR & 0x10) == 0

/* 软件复位 EEPROM操作失败标志位只可以复位清零*/
#define     Iap_Rst()                        IAP_CONTR |= 0x20

/* 软件复位后，是否进入ISP */
#define     Iap_EnterISP()                   IAP_CONTR |= 0x40

/* EEPROM使能 */
#define     Iap_Enable()                     IAP_CONTR = 0x80
#define     Iap_Disable()                    IAP_CONTR &= ~0x80

/* EEPROM 擦出等待时间 */
#define     Iap_SetTPS()                     IAP_TPS = MAIN_Fosc/1000000UL

/* EEPROM 关闭 */
#define     Iap_Idle()                     {IAP_CONTR = 0;\
											IAP_CMD = 0;\
											IAP_TRIG = 0;\
											IAP_ADDRH = 0x80;\
											IAP_ADDRL = 0;}
/*========================================================================================*/
/*========================================================================================*/
/*==================================EEPROM用户API===========================================*/
/*========================================================================================*/
/*========================================================================================*/

/* EEPROM 擦出扇区  addr 擦出扇区地址 STC8H8K64地址范围 0 - ISP软件设置的EEPROM大小 */
#define     EEPROM_Erase(addr)      Iap_Enable();Iap_SetTPS();Iap_EraseEepromCmd();Iap_LoadAddr(addr);Iap_TrigCmd();_nop_();Iap_Idle();

/* EEPROM 写一个字节   
 * addr   要写入的地址  STC8H8K64地址范围 0 - ISP软件设置的EEPROM大小 
 * dat    要写入数据    一个字节
 */											
#define     EEPROM_Write(addr, dat)	Iap_Enable();Iap_SetTPS();Iap_WriteEepromCmd();Iap_LoadAddr(addr);IAP_DATA = dat;Iap_TrigCmd();_nop_();Iap_Idle();									

/* EEPROM 读一个字节   
 * addr   要读取的地址  STC8H8K64地址范围 0 - ISP软件设置的EEPROM大小 
 * dat    读取数据      一个字节
 */											
#define     EEPROM_Read(addr, dat)  Iap_Enable();Iap_SetTPS();Iap_ReadEepromCmd();Iap_LoadAddr(addr);Iap_TrigCmd();_nop_();dat = IAP_DATA;Iap_Idle();


#endif
