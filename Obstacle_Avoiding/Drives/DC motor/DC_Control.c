/*
 * DC_Control.c
 *
 * Created: 12/07/2020 05:20:39 ص
 *  Author: dell
 */ 
#include "DC_Control.h"         //A module for controlling the DC motors 
void DC_Control(){
	uint8 x=100;
	uint8 y;
	y=Rec();
	LCD_Clear();
	switch(y){
		case ('2'):		
		DC_Forward(100);
		break;
		case ('4'):
		DC_Left(x);
		break;
		case ('6'):
		DC_Right(x);
		break;
		case ('8'):
		DC_Back(x);
		break;
		case ('0'):
		DC_Stop();
		break;
		case ('5'):
		OCR0=OCR0-10;
		OCR2=OCR2-10;
		break;
		case ('1'):
		OCR0=OCR0+10;
		OCR2=OCR2+10;
		break;
		//default:
		//break;
	}
}