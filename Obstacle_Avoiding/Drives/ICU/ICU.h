/*
 * ICU.h
 *
 * Created: 09/07/2020 06:46:58 م
 *  Author: dell
 */ 


#ifndef ICU_H_
#define ICU_H_
#include "../DIO/DIO_HW.h"
#define ICU_Trigger PORTD_REG
#define Trigger 3
void ICU_Init();
long ICU_Distance();
void LCD_ICU();
#endif /* ICU_H_ */