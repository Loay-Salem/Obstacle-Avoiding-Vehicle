/*
 * DIO_HW.h
 *
 * Created: 02/06/2020 12:23:22 ص
 *  Author: dell
 */ 


#ifndef DIO_HW_H_
#include "../STD_Types.h"
#define DIO_HW_H_
#define PORTA_REG (*(volatile uint8 *)0x3b)
#define DDRA_REG (*(volatile uint8 *)0x3a)
#define PINA_REG (*(const volatile uint8 *)0x39)
#define PORTB_REG (*(volatile uint8 *)0x38)
#define DDRB_REG (*(volatile uint8 *)0x37)
#define PINB_REG (*(const volatile uint8 *)0x36)
#define PORTC_REG (*(volatile uint8 *)0x35)
#define DDRC_REG (*(volatile uint8 *)0x34)
#define PINC_REG (*(const volatile uint8 *)0x33)
#define PORTD_REG (*(volatile uint8 *)0x32)
#define DDRD_REG (*(volatile uint8 *)0x31)
#define PIND_REG (*(const volatile uint8 *)0x30)
#define TCCR0_REG (*(volatile uint8 *)0x53)
#define OCR0_REG (*(volatile uint8 *)0x5c)
#define TIMSK_REG (*(volatile uint8 *)0x59)
#define TIFR_REG (*(volatile uint8 *)0x58)
#define TCCR2_REG (*(volatile uint8 *)0x45)
#define OCR2_REG (*(volatile uint8 *)0x43)
#define TWAR_REG (*(volatile uint8 *)0x22)
#define TWCR_REG (*(volatile uint8 *)0x56)
#define TWSR_REG (*(volatile uint8 *)0x21)
#define TWDR_REG (*(volatile uint8 *)0x23)
#define TWBR_REG (*(volatile uint8 *)0x21)
#endif /* DIO_HW_H_ */