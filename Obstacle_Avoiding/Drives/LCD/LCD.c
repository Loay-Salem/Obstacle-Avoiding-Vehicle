/*
 * LCD.c
 *
 * Created: 02/06/2020 02:22:40 ص
 *  Author: dell
 */ 
#include "LCD.h"
#include "STD_Types.h"
#define F_CPU 16000000
#include <util/delay.h>
#include "../BitMath.h"
void LCD_Command(char cmd){
	LCD_PORT=(LCD_PORT&0x0f)|(cmd&0xf0);
	LCD_CTRL&=~(1<<RS);
	//LCD_CTRL&=~(1<<RW);
	LCD_CTRL|=(1<<E);
	_delay_us(10);
	LCD_CTRL&=~(1<<E);
	_delay_us(1000);
	LCD_PORT=(LCD_PORT&0x0f)|(cmd<<4);
	LCD_CTRL|=(1<<E);
	_delay_us(10);
	LCD_CTRL&=~(1<<E);
	_delay_us(1000);
}
void LCD_Init(){
	LCD_Dir=0xff;
	LCD_DCTRL=(1<<RS);
	LCD_DCTRL|=(1<<RW);
	LCD_DCTRL|=(1<<E);
	LCD_CTRL&=~(1<<RW);
	_delay_ms(20);
	LCD_Command(0x33);
	LCD_Command(0x32);
	LCD_Command(0x28);
	LCD_Command(0x0c);
}
void LCD_Char(char data){
	LCD_PORT=(LCD_PORT&0x0f)|(data&0xf0);
	LCD_CTRL|=(1<<RS);
	LCD_CTRL|=(1<<E);
	_delay_us(20);
	LCD_CTRL&=~(1<<E);
	_delay_us(1000);
	LCD_PORT=(LCD_PORT&0x0f)|(data<<4);
	LCD_CTRL|=(1<<E);
	_delay_us(20);
	LCD_CTRL&=~(1<<E);
	_delay_us(1000);
}
void LCD_Str(char * Str){
	int i=0;
	while(Str[i]!='\0'){
		LCD_Char(Str[i]);
		i++;
	}LCD_Command(0x80);
}
void LCD_OFF(STD_Level cmd){
	if(cmd==high){LCD_Cmd(0x0c);}
	else{LCD_Cmd(0x08);}
}
void LCD_BackSpace(){
	LCD_Command(0x10);
	LCD_Char(' ');
	LCD_Command(0x10);
}
void LCD_PreviousLine(){
	LCD_Command(0x80);
}
void LCD_NewLine(){
	LCD_Command(0xc0);
}
void LCD_Clear(){
	LCD_Command(0x01);
}