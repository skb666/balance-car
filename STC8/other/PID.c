#include "main.h"

// 角度控制
int Stand(float NowValue){
	volatile float xdata Err;
	volatile float xdata Output;
	static float xdata LastErr = 0.0f;
	
	Err = Stand_Set - NowValue;
	Output = Stand_P * Err + Stand_D * (Err - LastErr);
	LastErr = Err;
	
	return (int)Output;
}

// 速度控制
int Speed(int L_Speed, int R_Speed){
	volatile int xdata Err;
	static float xdata LastErr = 0.0f;
	volatile float xdata Output;
	static int xdata integration = 0;
	
	Err = Speed_Set - (L_Speed + R_Speed);
	Err = Err * 0.2 + LastErr * 0.8;
	Output = Speed_P * Err + Speed_I * integration;
	integration += Err;
	LastErr = Err;
	
	if(integration>10000)
		integration=10000;
	if(integration<-10000)
		integration=-10000;
	if(Stop_Sign == 0)
		integration=0;
	
	return (int)Output;
}

// 方向控制
int Turn(int L_Speed, int R_Speed){
	volatile float xdata Err;
	static float xdata LastErr = 0.0f;
	volatile float xdata Output;
	
	Err = Turn_Set - (L_Speed - R_Speed);
	Err = Err * 0.7 + LastErr * 0.3;
	Output = Turn_P * Err + Turn_D * (Err - LastErr);
	LastErr = Err;
	
	return (int)Output;
}

// 横电感控制
int ADC_H_PID(){
	volatile float xdata Err;
	volatile float xdata Output;
	static float xdata LastErr = 0.0f;

	Err = (float)(adc_hl[0] - adc_hr[0]) / (adc_hl[0] + adc_hr[0]) - ADC_H_Set;
	Output = ADC_H_P * Err + ADC_H_D * (Err - LastErr);
	LastErr = Err;

	return (int)Output;
}

// 电感控制
int ADC_PID(){
	volatile float xdata Err;
	volatile float xdata Output;
	static float xdata LastErr = 0.0f;

	Err = (float)(adc_hl[0] - adc_hr[0] + adc_vl[0] - adc_vr[0]) / (adc_hl[0] + adc_hr[0] + adc_vl[0] + adc_vr[0] - adc_z[0] / 5) - ADC_Set;
	Output = ADC_P * Err + ADC_D * (Err - LastErr);
	LastErr = Err;

	return (int)Output;
}
