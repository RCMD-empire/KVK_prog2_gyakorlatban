/*
 * init.c
 *
 * Created: 2024-09-30 17:43:26
 *  Author: RCMD-LaptopB
 */ 
#include "init.h"
void port_init(void)
{
	DDRA= 0xFF;//Display
	DDRB=0xF0;
	DDRD=0xF0;
	DDRC = 0xF8; //Keypad
}
void timer0_ovr_init(void)
{
	TCCR0= 1 << CS02 | 0<<CS01 | 0<<CS00; // 1 másodperc
	TIMSK= 1 << TOIE0;
	sei();
}