/*
 * LEDek_megszakitassal.c
 * Board: atmega128
 * Created: 2024-09-23 16:29:42
 * Author : RCMD-LaptopB
 */ 
#define F_CPU 8000000UL // legeslegfelul kell
#include <avr/io.h>
#include <avr/interrupt.h>

void port_init(void);
void timer0_ovr_init(void);
void LED_out(uint8_t);
uint8_t led = 0x01, ido = 0, dig_sel=0, ertek[4]={0};


int main(void)
{
    /* Replace with your application code */
	port_init();
	timer0_ovr_init();
	PORTA=0xB3;
    while (1) 
    {
    }
}
void port_init(void)
{
	DDRA= 0xFF;
	DDRB=0xF0;
	DDRD=0xF0;
}
void LED_out(uint8_t ledek)
{
	PORTB= (ledek<<4) & 0xF0;
	PORTD= (ledek) & 0xF0;
}
void timer0_ovr_init(void)
{
	TCCR0= 1 << CS02 | 0<<CS01 | 0<<CS00; // 1 másodperc
	TIMSK= 1 << TOIE0;
	sei();
}
ISR(TIMER0_OVF_vect)
{
	if (!ido--)
	{
		LED_out(led);
		led = led ^ 0x01;
	}
	PORTA = 1<<7 | dig_sel <<4 | ertek[dig_sel];
	if (dig_sel==3) dig_sel=0;
	else dig_sel++;
}

