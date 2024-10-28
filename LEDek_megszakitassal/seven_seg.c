/*
 * seven_seg.c
 *
 * Created: 2024-09-30 17:45:36
 *  Author: RCMD-LaptopB
  */ 


#include "seven_seg.h"
void seven_seg(void) {
	PORTA = 1<<7 | dig_sel <<4 | ertek[dig_sel];
	if (dig_sel==3) dig_sel=0;
	else dig_sel++;
}

void shift_val(uint8_t num) {
	ertek[3] = ertek[2];
	ertek[2] = ertek[1];
	ertek[1] = ertek[0];
	ertek[0] = num;
}