/*
 * ADC.c
 *
 * Created: 2024-10-21 17:06:01
 *  Author: RCMD-LaptopB
 */


#include "ADC.h"
void adc_init(void) {
	ADMUX= 0;
	ADMUX |= 1<< ADLAR;
	ADCSRA = 0;
	ADCSRA |= 1<<ADEN ;
}
uint16_t adc_conv(uint8_t ch) {
	ADCSRA |= 1<<ADSC;
	while(!(ADCSRA&ADIF));
	ADCSRA &= ~(1<<ADSC);
	return ADC;
}