#include "main.h"

float LowPassFilter_kalman(float datan, int w){
	static int Xlast=0;
	static int P=5;
	int Q=2;
	int R=80;
	float S=0.09;
	float Kg, PP;
	float Xnow,x;
	x=datan*100;
	PP=P+Q;
	Kg=PP/(PP+R);
	Xnow=Xlast+Kg*(x-Xlast);
	P=(1-Kg)*PP;
	Xlast=Xnow+w*S;
	return Xnow;
}

