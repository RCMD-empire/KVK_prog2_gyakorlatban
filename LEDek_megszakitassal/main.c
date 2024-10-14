/*
 * LEDek_megszakitassal.c
 * Board: aidoga128
 * Created: 2024-09-23 16:29:42
 * Author : RCMD-LaptopB
 */ 
#define F_CPU 8000000UL // legeslegfelul kell
#include <avr/io.h>
#include <avr/interrupt.h>
#include "main.h"
#include "Keyboard.h"
#include "LCD.h"





void felfeleszamalalo(void);

uint8_t ido = 0;
uint8_t old_key = 12;
uint8_t dig_sel = 0;
uint8_t ertek[4] = {12, 12, 12, 12};
int main(void)
{
    /* Replace with your application code */
	port_init();
	timer0_ovr_init();
	LCD_init();
	LCD_Puts("a");
	PORTA=0xB3;
    while (1) 
    {
    }
}



ISR(TIMER0_OVF_vect)
{
	if (!ido--)
	{
		
		uint8_t key = get_key();
		if (key < 12 && old_key == 12 ) {
			shift_val(key);
		}
		old_key = key;
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
void shift_val(uint8_t num) {
	ertek[3] = ertek[2];
	ertek[2] = ertek[1];
	ertek[1] = ertek[0];
	ertek[0] = num;
}

void seven_seg(void){
	PORTA = 1<<7 | dig_sel <<4 | ertek[dig_sel];
	if (dig_sel==3) dig_sel=0;
	else dig_sel++;
}