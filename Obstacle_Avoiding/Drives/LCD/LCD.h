/*
 * LCD.h
 *
 * Created: 02/06/2020 02:22:57 ص
 *  Author: dell
 */ 


#ifndef LCD_H_
#include <avr/io.h>
#include "../DIO/DIO_HW.h"
#define LCD_H_
#define LCD_PORT PORTA_REG
#define LCD_CTRL PORTA_REG  //A
#define LCD_Dir  DDRA_REG
#define LCD_DCTRL DDRA_REG //a
#define RS 2  //2  
#define RW 1     //1
#define E  0     //0
void LCD_Str(char * Str);
void LCD_Char(char data);
void LCD_Init();
void LCD_Command(char cmd);
void LCD_OFF(STD_Level cmd);
void LCD_BackSpace();  //char =0x08
void LCD_PreviousLine();
void LCD_NewLine();
void LCD_Clear();
#endif /* LCD_H_ */