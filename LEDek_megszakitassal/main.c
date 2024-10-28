/*
 * LEDek_megszakitassal.c
 * Board: aidoga128
 * Created: 2024-09-23 16:29:42
 * Author : RCMD-LaptopB
 */ 
#include "main.h"

uint8_t c = 'A';
uint8_t ido = 0;
uint8_t led = 0x01;
uint8_t old_key = 12;
uint8_t dig_sel = 0;
uint8_t ertek[4] = {12, 12, 12, 12};
int main(void)
{
	port_init();
	timer0_ovr_init();
	adc_init();
	
	LCD_init();
	
	LCD_pos(2,3);

	LCD_Puts("Hello world!");
	PORTA=0xB3;
	
    while (1) {
		LED_out(lm35());
		//if (c=='z') { c='A'; LCD_data(c++);} else LCD_data(c++);
		//_delay_ms(500);
    }
}

ISR(TIMER0_OVF_vect)
{
	if (!ido--) {
		//LED_out(led);
		//led = led ^ 0x01;
		uint8_t key = get_key();
		if (key < 12 && old_key == 12 ) shift_val(key);
		old_key = key;
	}
	seven_seg();
}

/* 
//nem hasznalat
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

*/


