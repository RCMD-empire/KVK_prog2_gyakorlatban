/*
 * LED.c
 *
 * Created: 2024-09-30 17:41:10
 *  Author: RCMD-LaptopB
 */ 
#include "LED.h"
void LED_out(uint8_t ledek)
{
	PORTB= (ledek<<4) & 0xF0;
	PORTD= (ledek) & 0xF0;
}