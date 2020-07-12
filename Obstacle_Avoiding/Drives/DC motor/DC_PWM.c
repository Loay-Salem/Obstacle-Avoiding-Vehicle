/*
 * DC_Timer.c
 *
 * Created: 08/07/2020 12:22:07 ص
 *  Author: dell
 */ 
#include "../DIO/DIO_HW.h"
#include "DC_PWM.h"
void DC_PWM_Init(){
	TCCR0_REG=(1<<CS00)|(1<<WGM00)|(1<<WGM01)|(1<<COM01);
	TCCR2_REG=(1<<CS20)|(1<<WGM20)|(1<<WGM21)|(1<<COM21);
	OCR0_REG=0;
	OCR2_REG=0;
}