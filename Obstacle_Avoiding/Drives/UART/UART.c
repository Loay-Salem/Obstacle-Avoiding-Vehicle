/*
 * UART.c
 *
 * Created: 09/07/2020 07:38:16 م
 *  Author: dell
 */ 
#include <avr/io.h>
#include "UART.h"
void UART_Init(){    
	UBRRL=BAUD_EQ;
	UCSRC|=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UCSRB|=(1<<RXEN)|(1<<TXEN);
}
unsigned char Rec(){          //The UART Receive function doesn't wait to receive so it wouldn't pause the DC control
	return UDR;
}
unsigned char URec(){         //This UART Receive wait and doesn't execute the next line till data is received
	while(!(UCSRA&(1<<RXC)));
	return UDR;
}
void Send(unsigned char data){
	while(!(UCSRA&(1<<UDRE)));
	UDR=data;
}

void Send_Str(char * Str){
	int i=0;
	while(Str[i]!='\0'){
		Send(Str[i]);
		i++;
	}
}