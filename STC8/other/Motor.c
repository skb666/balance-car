#include "main.h"

// ËÀÇø
int L_MIN = 0;
int R_MIN = 0;

void Motor_Init()
{
    PWM_Init(0, 7, 15000, 0);
	PWM_Init(0, 5, 15000, 0);
    PWM_Init(5, 3, 15000, 0);
	PWM_Init(5, 2, 15000, 0);
}

void Motor_R_Front(int speed)
{
	PWM_SetDuty(0, 7, 0);
	PWM_SetDuty(0, 5, R_MIN + speed);
}

void Motor_R_Back(int speed)
{
	PWM_SetDuty(0, 7, R_MIN + speed);
	PWM_SetDuty(0, 5, 0);
}

void Motor_L_Front(int speed)
{
	PWM_SetDuty(5, 3, 0);
	PWM_SetDuty(5, 2, L_MIN + speed);
}

void Motor_L_Back(int speed)
{
	PWM_SetDuty(5, 3, L_MIN + speed);
	PWM_SetDuty(5, 2, 0);
}

void Motor_R_Stop(void)
{
	PWM_SetDuty(0, 7, 0);
	PWM_SetDuty(0, 5, 0);
}

void Motor_L_Stop(void)
{
	PWM_SetDuty(5, 3, 0);
	PWM_SetDuty(5, 2, 0);
}

void Motor_Control(int speed_l, int speed_r){
	if(speed_l > 0)
		Motor_L_Front(speed_l);
	else if(speed_l < 0)
		Motor_L_Back(-speed_l);
	else
		Motor_L_Stop();
	
	if(speed_r > 0)
		Motor_R_Front(speed_r);
	else if(speed_r < 0)
		Motor_R_Back(-speed_r);
	else
		Motor_R_Stop();
}
