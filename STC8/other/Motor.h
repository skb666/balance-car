#ifndef _Motor_H
#define _Motor_H

void Motor_Init();       //电机PWM初始化 C0 C1 C2 C3
void Motor_L_Front(int speed);
void Motor_L_Back(int speed);
void Motor_R_Front(int speed);
void Motor_R_Back(int speed);
void Motor_L_Stop(void);
void Motor_R_Stop(void);
void Motor_Control(int speed_l, int speed_r);

#endif
