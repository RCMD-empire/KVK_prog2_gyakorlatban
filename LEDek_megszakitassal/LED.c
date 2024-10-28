/*
 * LED.c
 *
 * Created: 2024-09-30 17:41:10
 *  Author: RCMD-LaptopB
 */ 


#include "LED.h"
//uint8_t irany=1, led1 = 0x01, led2=0x80; nem kellenek
void LED_out(uint8_t ledek) {
	PORTB= (ledek<<4) & 0xF0;
	PORTD= (ledek) & 0xF0;
}
