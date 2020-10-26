#include "main.h"

void Enc_Init(){
	PIN_InitStandard(3, 2);		// R_A
	PIN_EnablePullUp(3, 2);
	PIN_InitStandard(3, 7);		// L_B
	PIN_EnablePullUp(3, 7);
	
	PIN_InitStandard(3, 3);		// R_B
	PIN_EnablePullUp(3, 3);
	PIN_InitStandard(3, 6);		// L_A
	PIN_EnablePullUp(3, 6);
	
	INT0_Enable();
	INT1_Enable();
	
	CCON = 0x00; 
	CMOD = 0x08; 	//PCA 时钟为系统时钟
	CL = 0x00;
	CH = 0x00;
	CCAPM1 = 0x31; 	//扩展外部端口 CCP0 为边沿中断口
	CCAP1L = 0;
	CCAP1H = 0;
	CCAPM2 = 0x31; 	//扩展外部端口 CCP0 为边沿中断口
	CCAP2L = 0;
	CCAP2H = 0;
}
