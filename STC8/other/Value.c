#include "Value.h"

const float RtA = 57.2957795f;    	//弧度（radian）转角度（angle）的常数
const float AtR = 0.0174532925f;  	//角度转弧度的常数

int xdata aacx, aacy, aacz;	  		//加速度传感器原始数据
int xdata gyrox, gyroy, gyroz;  	//陀螺仪原始数据
int xdata adc_hl[2]={0}, adc_hr[2]={0}, adc_vl[2]={0}, adc_vr[2]={0}, adc_z[2]={0};		// 电感数据
int xdata cap_v[2];

// 开关标志位
uint8_t xdata EEPROM_W_SW = 0;
uint8_t xdata EEPROM_R_SW = 0;
uint8_t xdata Stand_SW 	  = 1;
uint8_t xdata Speed_SW 	  = 1;
uint8_t xdata Turn_SW 	  = 1;
uint8_t xdata ADC_SW 	  = 1;
uint8_t xdata ADC_SW1 	  = 0;
uint8_t xdata Stop_Sign   = 0;
uint8_t xdata RK_Sign	  = 0;
uint8_t xdata RH_Sign	  = 0;

// 角度
float xdata Stand_Set 	= 20.4f;
float xdata Stand_P 	= 318.6f;
float xdata Stand_D 	= 72.5f;

// 速度
float xdata Speed_Set 	= 36.0f;
float xdata Speed_New 	= 36.0f;
float xdata Speed_P 	= 119.5f;
float xdata Speed_I 	= 0.6f;
 
// 方向
float xdata Turn_Set 	= 0.0f;
float xdata Turn_P 		= 10.0f;
float xdata Turn_D 		= 65.0f;

// 横电感
int   xdata ADC_H_Set 	= 0;
float xdata ADC_H_P 	= 196.0f;
float xdata ADC_H_D 	= 462.0f;

// 电感
int   xdata ADC_Set 	= 0;
float xdata ADC_P 		= 158.0f;
float xdata ADC_D 		= 200.0f;

// CCD阈值
int xdata threshold 	= 888;

