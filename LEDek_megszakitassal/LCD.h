/*
 * LCD.h
 *
 * Created: 2024-10-14 17:35:43
 *  Author: RCMD-LaptopB
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU 16000000UL 
#include <util/delay.h>
#include <inttypes.h>
#include <avr/io.h>
#define LCD_CMD_DDR (DDRF) 
#define LCD_DATA_DDR (DDRE)
#define LCD_CMD_PORT (PORTF) 
#define LCD_DATA_PORT (PORTE) 
#define LCD_DATA_PIN (PINE)
#define LCD_RS (PF1) 
#define LCD_RW (PF2) 
#define LCD_EN (PF3)
#define LCD_E 2 //enable 
#define LCD_CUR 1 //cursor 
#define LCD_BL 0 //blink
void LCD_init(); 
void LCD_cmd(uint8_t cmd); 
void LCD_clock(); 
void LCD_data(uint8_t data);
void LCD_Puts (char *s);
void LCD_pos(uint8_t,uint8_t);

#endif /* LCD_H_ */