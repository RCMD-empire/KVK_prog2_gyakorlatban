/*
 * seven_seg.h
 *
 * Created: 2024-09-30 17:45:55
 *  Author: RCMD-LaptopB

*/


#ifndef SEVEN_SEG_H_
#include "avr/io.h"
void seven_seg(void);
void shift_val(uint8_t num);
extern uint8_t dig_sel, ertek[4];
#define SEVEN_SEG_H_





#endif // SEVEN_SEG_H_