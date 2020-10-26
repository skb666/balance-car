#include "BLE.h"

// 封包
uint16_t Packet(uint8_t _size, uint8_t n, void *p, uint8_t *buf){
	uint16_t sum = 0;
	uint8_t i, j;
	for(i=0; i<n; i++)
		for(j=0; j<_size; j++){
			*(buf + i*_size + j) = ((uint8_t *)p)[i*_size + j];
			sum += *(buf + i*_size + j);
		}
	return sum;
}

// 解包
uint16_t UnPacket(uint8_t _size, uint8_t n, uint8_t *buf, void *p){
	uint16_t sum = 0;
	uint8_t i, j;
	for(i=0; i<n; i++)
		for(j=0; j<_size; j++){
			((uint8_t *)p)[i*_size + j] = *(buf + i*_size + j);
			sum += ((uint8_t *)p)[i*_size + j];
		}
	return sum;
}

// 封包（反地址位）
uint16_t Packet_F(uint8_t _size, uint8_t n, void *p, uint8_t *buf){
	uint16_t sum = 0;
	uint8_t i, j;
	for(i=0; i<n; i++)
		for(j=0; j<_size; j++){
			*(buf + i*_size + j) = ((uint8_t *)p)[i*_size + _size-1-j];
			sum += *(buf + i*_size + j);
		}
	return sum;
}

// 解包（反地址位）
uint16_t UnPacket_F(uint8_t _size, uint8_t n, uint8_t *buf, void *p){
	uint16_t sum = 0;
	uint8_t i, j;
	for(i=0; i<n; i++)
		for(j=0; j<_size; j++){
			((uint8_t *)p)[i*_size + _size-1-j] = *(buf + i*_size + j);
			sum += ((uint8_t *)p)[i*_size + _size-1-j];
		}
	return sum;
}
