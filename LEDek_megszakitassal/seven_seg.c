/*
 * seven_seg.c
 *
 * Created: 2024-09-30 17:45:36
 *  Author: RCMD-LaptopB
  */ 

#include "seven_seg.h"
uint8_t dig_sel = 0;
void seven_seg(void){
	PORTA = 1<<7 | dig_sel <<4 | ertek[dig_sel];
	if (dig_sel==3) dig_sel=0;
	else dig_sel++;
}
