/*
 * LCD.c
 *
 * Created: 2024-10-14 17:35:24
 *  Author: RCMD-LaptopB
 */ 
#include "LCD.h"
void LCD_init(){
	DDRE |= 0xF0;
	//data7...4 out
	DDRF |= (1<<LCD_RS) | (1<<LCD_RW) | (1<<LCD_EN); //RS, R/W, EN out
	//�r�s
	PORTF &= ~(LCD_RW);
	//R/W<-0 ->write
	PORTF &= ~(1<<LCD_RS);
	//RS <-0 ->parancs
	PORTE = 0x20;
	//0x20 parancs: Function set - Sets interface data length
	LCD_clock();
	//delay
	LCD_clock();
	//__| |__
	LCD_clock();
	//4 bites �zemm�d, 8x5pixel, 2soros
	//�zemm�d v�laszt�s
	//nem tudjuk, hogy bekapcsol�s ut�n �ppen milyenben van
	LCD_cmd(0x28);
	LCD_cmd(0x28);
	LCD_cmd(0x28);
	//lcd alaphelyzetbe
	LCD_cmd(0x02);
	//lcd t�rl�se
	LCD_cmd(0x01);
	//kurzor villog, al�h�z�s be, LCD be
	//LCD_command(0x08 | (1<<LCD_E) | (1<<LCD_CUR) | (1<<LCD_BL));
	//kurzor villog ki, al�h�z�s be, LCD be
	//LCD_command(0x08 | (1<<LCD_E) | (1<<LCD_CUR) | (0<<LCD_BL));
	//kurzor villog ki, al�h�z�s ki, LCD be
	LCD_cmd(0x08 | (1<<LCD_E) | (0<<LCD_CUR) | (0<<LCD_BL));
}
void LCD_busy(void){ //BF olvas�sa
	uint8_t busy;
	LCD_DATA_DDR &= ~(1<<PE7); //ott olvassuk majd a BF-et (D7-PE7)
	LCD_CMD_PORT &= ~(1<<LCD_RS); //St�tusz inf�
	LCD_CMD_PORT |= (1<<LCD_RW); //olvas�s
	do{
		busy = 0;
		LCD_CMD_PORT |= (1<<LCD_EN); //EN<-1
		_delay_us(1); //felfut�
		busy=(LCD_DATA_PIN&(1<<PE7)); //�tadjuk a BF �rt�k�t
		LCD_CMD_PORT &= ~(1<<LCD_EN); //EN<-0
		_delay_us(1);
		LCD_CMD_PORT |= (1<<LCD_EN); //EN<-1
		_delay_us(1);
		LCD_CMD_PORT &= ~(1<<LCD_EN); //EN<-0
		_delay_us(1);
	}while(busy);
	LCD_CMD_PORT &= ~(1<<LCD_RW); //R/W<-0 write
	LCD_DATA_DDR |= (1<<PE7); //PE7<-1
}
void LCD_cmd(uint8_t cmd){
	LCD_busy(); //Megv�rjuk m�g felszabadul
	LCD_CMD_PORT &= ~(1<<LCD_RS); //Parancs
	LCD_CMD_PORT &= ~(1<<LCD_RW); //K�ld�s
	LCD_CMD_PORT &= ~(1<<LCD_EN); //EN<-0
	LCD_DATA_PORT &= ~(0xF0);
	LCD_DATA_PORT |= (cmd&0xF0); //fels? 4 bit k�ld�se
	LCD_clock(); //__| |__
	LCD_DATA_PORT &= ~(0xF0);
	LCD_DATA_PORT |= ((cmd<<4)&0xF0); //als� 4 bit k�ld�se
	LCD_clock(); //__| |__
}
void LCD_data(uint8_t data){
	LCD_busy(); //Megv�rjuk m�g felszabadul
	LCD_CMD_PORT |= (1<<LCD_RS); //Adatregiszter
	LCD_CMD_PORT &= ~(1<<LCD_RW); //�r�s
	LCD_CMD_PORT &= ~(1<<LCD_EN); //EN<-0
	LCD_DATA_PORT &= ~(0xF0);
	LCD_DATA_PORT |= (data&0xF0); //4 fels? bit kit�tele
	LCD_clock(); //__| |__
	LCD_DATA_PORT &= ~(0xF0);
	LCD_DATA_PORT |= ((data<<4)&0xF0); //als� 4 bit kit�tele
	LCD_clock(); //__| |__
}
void LCD_clock(){
	LCD_CMD_PORT |= (1<<LCD_EN); //__|
	_delay_us(2); //
	LCD_CMD_PORT &= ~(1<<LCD_EN); // |__
	_delay_us(2);
}
void LCD_Puts (char*s)
{
	while (*s)
	{
		LCD_data(*s);
		s++;
	}
}
void LCD_pos(uint8_t row,uint8_t col)
{
	switch(row)
	{
		case 1:LCD_cmd(0x80|(0+col)); break;
		case 2:LCD_cmd(0x80|(0x40+col)); break;
		case 3:LCD_cmd(0x80|(0x10+col)); break;
		case 4:LCD_cmd(0x80|(0x50+col)); break;SS
	}
}
}