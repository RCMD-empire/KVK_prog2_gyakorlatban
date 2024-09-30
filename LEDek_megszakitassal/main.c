/*
 * LEDek_megszakitassal.c
 * Board: atmega128
 * Created: 2024-09-23 16:29:42
 * Author : RCMD-LaptopB
 */ 
#define F_CPU 8000000UL // legeslegfelul kell
#include <avr/io.h>
#include <avr/interrupt.h>
#include "main.h"





void felfeleszamalalo(void);



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



ISR(TIMER0_OVF_vect)
{
	if (!ido--)
	{
		LED_out(led);
		led = led ^ 0x01;
		felfeleszamalalo();
	}
	seven_seg();
}

void felfeleszamalalo(void){
	if (ertek[0]==9)
	{
		ertek[0]=0;
		if (ertek[1]==9)
		{
			ertek[1]=0;
			if (ertek[2]==9)
			{
				ertek[2]=0;
				if (ertek[3]==9)
				{
					ertek[3]=0;
				}
				else ertek[3]++;
			}
			else ertek[2]++;
		}
		else ertek[1]++;
	} 
	else ertek[0]++;
}
void ora_perc_masodperc(void){
	if (ertek[0]==9)
	{
		ertek[0]=0;
		if (ertek[1]==9)
		{
			ertek[1]=0;
			if (ertek[2]==9)
			{
				ertek[2]=0;
				if (ertek[3]==9)
				{
					ertek[3]=0;
				}
				else ertek[3]++;
			}
			else ertek[2]++;
		}
		else ertek[1]++;
	}
	else ertek[0]++;
}
