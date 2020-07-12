/*
 * UART.h
 *
 * Created: 09/07/2020 07:38:04 م
 *  Author: dell
 */ 


#ifndef UART_H_
#define UART_H_
#include "../STD_Types.h"
#define F_CPU 16000000
#define BAUD 9600
#define BAUD_EQ ((F_CPU/(BAUD*16UL)-1))
void UART_Init();
void Send(uint8 data);
unsigned char Rec();
void Send_Str(char * Str);
unsigned char URec();


#endif /* UART_H_ */