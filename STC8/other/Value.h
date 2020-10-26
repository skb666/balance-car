#ifndef _VALUE_H
#define _VALUE_H

#include "stc8.h"

extern const float AtR;
extern const float RtA;

extern int aacx, aacy, aacz;
extern int gyrox, gyroy, gyroz;
extern int adc_hl[2], adc_hr[2], adc_vl[2], adc_vr[2], adc_z[2];
extern int cap_v[2];

extern uint8_t EEPROM_W_SW;
extern uint8_t EEPROM_R_SW;
extern uint8_t Stand_SW;
extern uint8_t Speed_SW;
extern uint8_t Turn_SW;
extern uint8_t ADC_SW;
extern uint8_t ADC_SW1;
extern uint8_t Stop_Sign;
extern uint8_t RK_Sign;
extern uint8_t RH_Sign;

extern float Stand_Set;
extern float Stand_P;
extern float Stand_D;

extern float Speed_Set;
extern float Speed_New;
extern float Speed_P;
extern float Speed_I;

extern float Turn_Set;
extern float Turn_P;
extern float Turn_D;

extern int ADC_H_Set;
extern float ADC_H_P;
extern float ADC_H_D;

extern int ADC_Set;
extern float ADC_P;
extern float ADC_D;

extern int threshold;

#endif