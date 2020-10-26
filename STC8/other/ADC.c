#include "main.h"

void My_ADC_Init(void){
	ADC_Init(14);
	ADC_Init(2);
	ADC_Init(3);
	ADC_Init(6);
	ADC_Init(7);
	ADC_Init(10);
}

void Get_ADC_Value(void){
	volatile int xdata i;
	adc_hr[0] = 0;
	adc_hl[0] = 0;
	adc_vr[0] = 0;
	adc_vl[0] = 0;
	adc_z[0] = 0;
	cap_v[0] = 0;
	// Æ½¾ùÂË²¨
	for(i=0; i<20; i++){
		ADC_GetValue(7, adc_hr[1]);
		ADC_GetValue(2, adc_hl[1]);
		ADC_GetValue(6, adc_vr[1]);
		ADC_GetValue(14, adc_vl[1]);
		ADC_GetValue(3, adc_z[1]);
		ADC_GetValue(10, cap_v[1]);
		adc_hr[0] += adc_hr[1];
		adc_hl[0] += adc_hl[1];
		adc_vr[0] += adc_vr[1];
		adc_vl[0] += adc_vl[1];
		adc_z[0] += adc_z[1];
		cap_v[0] += cap_v[1];
	}
	adc_hr[0] /= 20;
	adc_hl[0] /= 20;
	adc_vr[0] /= 20;
	adc_vl[0] /= 20;
	adc_z[0] /= 20;
	cap_v[0] /= 20;
}
