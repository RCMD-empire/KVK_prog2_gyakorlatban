/*
 * Keyboard.cpp
 *
 * Created: 10/7/2024 5:52:25 PM
 *  Author: tomi
 */ 


#define BASE 0x08
#include <avr/io.h>

uint8_t get_key(void) {
	uint8_t keys_add[12] = {0x0E, 0x0D, 0x0B, 0x16, 0x15, 0x13, 0x26, 0x25, 0x23, 0x46, 0x45, 0x43};
	uint8_t keys[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0};
		
	//PORTC = BASE << row;
	for (uint8_t i = 0; i < 12; i++) {
		PORTC = BASE << i;
		uint8_t state = (PINC & 0x7F);
		for (uint8_t k = 0; k < 12; k++) {
			if(state == keys_add[k]) return keys[k];
		}
	}
	
	return 12;
}