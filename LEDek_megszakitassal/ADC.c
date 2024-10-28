/*
 * ADC.c
 *
 * Created: 2024-10-21 17:06:01
 *  Author: RCMD-LaptopB
 */


#include "ADC.h"
void adc_init(void) {
	ADMUX= 0;
	//ADMUX |= 1<< ADLAR;
	ADCSRA = (0 | (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0));
}
uint16_t adc_conv(uint8_t ch) 
{
	ADMUX = (ADMUX & 0xE0) (ch & 0x1F);
	ADCSRA |= 1<<ADSC;
	while(!(ADCSRA&(1<<ADIF)));
	//ADCSRA &= ~(1<<ADSC);
	return ADC;
}