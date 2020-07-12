/*
 * DIO.c
 *
 * Created: 02/06/2020 12:53:44 ص
 *  Author: dell
 */ 
#include "DIO/DIO_Types.h"
#include "../BitMath.h"
#include "../STD_Types.h"
#include "DIO/DIO_HW.h"
void Dio_WriteChannel(DIO_Channel_Type Id,STD_Level lev){
	DIO_Port_Type portx =Id/8;
	DIO_Channel_Type pos =Id%8;
	switch (portx){
		case PORT_A:
		if (lev==high){Set(PORTA_REG,pos);}
		else {Clear(PORTA_REG,pos);}
		break;
		case PORT_B:
		if (lev==high){Set(PORTB_REG,pos);}
		else {Clear(PORTB_REG,pos);}
		break;
		case PORT_C:
		if (lev==high){Set(PORTC_REG,pos);}
		else {Clear(PORTC_REG,pos);}
		break;
		case PORT_D:
		if (lev==high){Set(PORTD_REG,pos);}
		else {Clear(PORTD_REG,pos);}
		break;
	}
}
STD_Level DIO_ReadChannel(DIO_Channel_Type Id){
	STD_Level read=low;
	DIO_Port_Type portx = Id/8;
	DIO_Channel_Type pos = Id%8;
	switch (portx){
		case PORT_A:
		read=Get(PINA_REG,pos);
		break;
		case PORT_B:
		read=Get(PINB_REG,pos);
		break;
		case PORT_C:
		read=Get(PINC_REG,pos);
		break;
		case PORT_D:
		read=Get(PIND_REG,pos);
		break;
	}
	return read;
}
void DIO_WritePort(DIO_Port_Type Port,uint8 Cmd){
	switch (Port){
		case PORT_A:
		PORTA_REG=Cmd;
		break;
		case PORT_B:
		PORTB_REG=Cmd;
		break;
		case PORT_C:
		PORTC_REG=Cmd;
		break;
		case PORT_D:
		PORTD_REG=Cmd;
		break;
	}
}