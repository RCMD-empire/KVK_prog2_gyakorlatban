/*
 * ADC.h
 *
 * Created: 2024-10-21 17:05:42
 *  Author: RCMD-LaptopB
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "avr/io.h"
void adc_init(void);
uint16_t adc_conv(uint8_t);




#endif /* ADC_H_ */