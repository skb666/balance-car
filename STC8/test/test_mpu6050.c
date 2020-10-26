/*!
  * @file     test_mpu6050.c
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
#include "test_mpu6050.h"
#include "lq_mpu6050.h"
#include "lq_uart.h"
#include "lq_softiic.h"
#include "lq_led.h"
#include "lq_oled.h"


/* 声明外部延时函数 */
extern void delayms(uint16_t ms);


	
/**
  * @brief    读取MPU6050或者ICM20602原始数据 测试
  *
  * @param    
  *
  * @return   
  *
  * @note     
  *
  * @example  
  *
  * @date     2019/6/12 星期三
  */
void Test_MPU6050()
{
	char  xdata txt[30];
	int  xdata aacx,aacy,aacz;	         //加速度传感器原始数据
	int  xdata gyrox,gyroy,gyroz;        //陀螺仪原始数据
	
    OLED_Init();                          //LCD初始化
    OLED_CLS();                           //LCD清屏
	IIC_Init(); 
	UART1_InitTimer1P30P31(115200);      //初始化串口
	OLED_P8x16Str(15,0,"LQ 6050 Test"); 
    printf("\r\nLQ 6050 Test \r\n");
	
	if(MPU6050_Init())
    {
        OLED_P8x16Str(15,2,"6050 Test Fail \r\n");
		printf("\r\n6050 Test Fail \r\n");
        while(1);
    }
	
	while(1)
    {

        MPU_Get_Raw_data(&aacx,&aacy,&aacz,&gyrox,&gyroy,&gyroz);	//得到加速度传感器数据  
        sprintf((char*)txt,"ax:%06d",aacx);
        OLED_P6x8Str(0,2,txt);
        sprintf((char*)txt,"ay:%06d",aacy);
        OLED_P6x8Str(0,3,txt);
        sprintf((char*)txt,"az:%06d",aacz);
        OLED_P6x8Str(0,4,txt);
        sprintf((char*)txt,"gx:%06d",gyrox);
        OLED_P6x8Str(0,5,txt);
        sprintf((char*)txt,"gy:%06d",gyroy);
        OLED_P6x8Str(0,6,txt);
        sprintf((char*)txt,"gz:%06d",gyroz);
        OLED_P6x8Str(0,7,txt);

        printf("\r\nAX: %d  ",aacx); 
        printf("\r\nAY: %d  ",aacy);
        printf("\r\nAZ: %d  ",aacz); 
        printf("\r\nGX: %d  ",gyrox);
        printf("\r\nGY: %d  ",gyroy); 
        printf("\r\nGZ: %d  ",gyroz);
        delayms(100);
        printf("\r\n*********************\r\n");
    }
	
}
