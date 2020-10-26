#ifndef _BLE_H
#define _BLE_H

typedef 	unsigned char	uint8_t;
typedef 	char	        int8_t;
typedef 	unsigned int	uint16_t;
typedef 	int	            int16_t;
typedef 	unsigned long	uint32_t;
typedef 	long	        int32_t;

uint16_t Packet(uint8_t _size, uint8_t n, void *p, uint8_t *buf);
uint16_t UnPacket(uint8_t _size, uint8_t n, uint8_t *buf, void *p);
uint16_t Packet_F(uint8_t _size, uint8_t n, void *p, uint8_t *buf);
uint16_t UnPacket_F(uint8_t _size, uint8_t n, uint8_t *buf, void *p);

#endif
