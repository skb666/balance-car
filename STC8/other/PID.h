#ifndef _PID_H
#define _PID_H

int Stand(float NowValue);
int Speed(int L_Speed, int R_Speed);
int Turn(int L_Speed, int R_Speed);
int ADC_H_PID();
int ADC_PID();

#endif
