#include "main.h"

void eeprom_r(){
	uint8_t i;
	float pdata frData[14];
	for(i = 0; i < sizeof(frData); i++)
	{
		EEPROM_Read(0x0000 + i, ((uint8_t *)frData)[i]);
	}
	Stand_Set 	= frData[0];
	Stand_P		= frData[1];
	Stand_D 	= frData[2];
	Speed_Set 	= frData[3];
	Speed_New 	= frData[4];
	Speed_P 	= frData[5];
	Speed_I 	= frData[6];
	Turn_Set 	= frData[7];
	Turn_P 		= frData[8];
	Turn_D 		= frData[9];
	ADC_H_P 	= frData[10];
	ADC_H_D 	= frData[11];
	ADC_P 		= frData[12];
	ADC_D 		= frData[13];
}

void eeprom_w(){
	uint8_t i;
	float xdata fwData[14];
	fwData[0]  = Stand_Set;
	fwData[1]  = Stand_P;
	fwData[2]  = Stand_D;
	fwData[3]  = Speed_Set;
	fwData[4]  = Speed_New;
	fwData[5]  = Speed_P;
	fwData[6]  = Speed_I;
	fwData[7]  = Turn_Set;
	fwData[8]  = Turn_P;
	fwData[9]  = Turn_D;
	fwData[10] = ADC_H_P;
	fwData[11] = ADC_H_D;
	fwData[12] = ADC_P;
	fwData[13] = ADC_D;
	
	
	EEPROM_Erase(0x0000);
	for(i = 0; i < sizeof(fwData); i++)
	{
		EEPROM_Write(0x0000 + i, ((uint8_t *)fwData)[i]);
	}
}
