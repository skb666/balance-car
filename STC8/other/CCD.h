#ifndef _CCD_H
#define _CCD_H

#include "stc8.h"

#define CCD_AO_CHANNEL 		4     //AO接ADC通道4  管脚P14

#define CCD_CLK_PORT   		1     //CLK接         管脚P15
#define CCD_CLK_PIN    		5

#define CCD_SI_PORT    		2     //SI接          管脚P23
#define CCD_SI_PIN     		3

#define CCD_AO_INIT         ADC_Init(CCD_AO_CHANNEL)
#define CCD_AO_GET(value)   ADC_GetValue(CCD_AO_CHANNEL, value)  
#define CCD_CLK_INIT        PIN_InitPushPull(CCD_CLK_PORT, CCD_CLK_PIN)
#define CCD_SI_INIT         PIN_InitPushPull(CCD_SI_PORT, CCD_SI_PIN)

#define CCD_CLK_H           P(CCD_CLK_PORT, CCD_CLK_PIN) = 1
#define CCD_CLK_L           P(CCD_CLK_PORT, CCD_CLK_PIN) = 0

#define CCD_SI_H            P(CCD_SI_PORT, CCD_SI_PIN)   = 1
#define CCD_SI_L            P(CCD_SI_PORT, CCD_SI_PIN)   = 0

void CCD_Delayus(uint8_t us);
void CCD_Init(void);
void CCD_Collect(uint16_t *p);

#endif
