/*
 * ICU.c
 *
 * Created: 09/07/2020 06:46:45 م
 *  Author: dell
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include "ICU.h"
#include <util/delay.h>
#include "../LCD/LCD.h"
volatile uint8 over;
long dist;
char temp[16];
void ICU_Init(){
	TCCR1B=(1<<ICES1)|(1<<CS10);
	TIMSK|=(1<<TOIE1);
	sei();
}
long ICU_Distance(){
	
	long value;
	ICU_Trigger|=(1<<Trigger);
	_delay_us(10);
	ICU_Trigger&=~(1<<Trigger);

	
	while(!(TIFR&(1<<ICF1)));
	TIFR|=(1<<ICF1);
	TCCR1B&=~(1<<ICES1);
	over=0;
	TCNT1=0;
	
	while(!(TIFR&(1<<ICF1)));
	TIFR|=(1<<ICF1);
	
	TCCR1B|=(1<<ICES1);
	value=ICR1+(over*65536);
	dist=value/933;
	return dist;
}
void LCD_ICU(){
	//dist=ICU_Distance();
	sprintf(temp,"dist= %d cm     ",(unsigned int)dist);
	LCD_Command(0x80);
	LCD_Str(temp);
	_delay_ms(200);
	memset(temp,0,16);
}
ISR(TIMER1_OVF_vect){
	over++;
}
