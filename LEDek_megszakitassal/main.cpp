/*
 * p2_Projekt4.cpp
 *
 * Created: 10/7/2024 4:27:13 PM
 * Author : tomi
 
 prog 2 jegyet 238, 117
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Keyboard.h"


void TIMER0_OVF_init(void);
void port_init(void);
void shift_val(uint8_t);
void seven_seg();

uint8_t tme = 0;
uint8_t dig_sel = 0;
uint8_t old_key = 12;
uint8_t value[4] = {12, 12, 12, 12};

int main(void) {
	port_init();
	TIMER0_OVF_init();
	while (1) {}
}

void port_init(void) {
	DDRA = 0xFF; //Display
	DDRC = 0xF8; //Keypad
}

void TIMER0_OVF_init(void) {
	//ATmega64: page 93, 106, 109
	TCCR0 = 1 << CS02 | 0 << CS01 | 0 << CS00;
	TIMSK = 1 << TOIE0;
	sei();
}

void seven_seg() {
	PORTA = 1<<7 | dig_sel<<4 | value[dig_sel];
	if (dig_sel == 3) dig_sel = 0;
	else dig_sel++;
}

ISR(TIMER0_OVF_vect) {
	if (!tme--) {
		tme = 20;
		uint8_t key = get_key();
		if (key < 12 && old_key == 12 ) {
			shift_val(key);
		}
		old_key = key;
	}
	seven_seg();
}

void shift_val(uint8_t num) {
	value[3] = value[2];
	value[2] = value[1];
	value[1] = value[0];
	value[0] = num;
}