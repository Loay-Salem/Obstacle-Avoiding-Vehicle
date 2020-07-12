/*
 * DIO_Cfg.c
 *
 * Created: 02/06/2020 01:39:59 ص
 *  Author: dell
 */ 
#include "../DIO/DIO_Cfg.h"
#include "../STD_Types.h"
#include "DIO_HW.h"
#include "DIO_Types.h"
#include "../BitMath.h"
const Pin_Dir Pin_Cfg[Pin_Count]={
	{Output,low},//A0
	{Output,low},//A1
	{Output,low},//A2
	{Output,low},//A3
	{Output,low},//A4
	{Output,low},//A5
	{Output,low},//A6
	{Output,low},//A7
	{Output,low},//B0
	{Output,low},//B1
	{Output,low},//B2
	{Output,low},//B3
	{Output,low},//B4
	{Output,low},//B5
	{Output,low},//B6
	{Output,low},//B7
	{Output,low},//C0
	{Output,low},//C1
	{Output,low},//C2
	{Output,low},//C3
	{Output,low},//C4
	{Output,low},//C5
	{Output,low},//C6
	{Output,low},//C7
	{Input,low},//D0
	{Output,low},//D1
	{Output,low},//D2
	{Output,low},//D3
	{Output,low},//D4
	{Output,low},//D5
	{Input,low},//D6
	{Output,low}//D7
};
void DIO_Init(){
	for(uint16 i=0;i<Pin_Count;i++){
		DIO_Port_Type portx = i/8;
		DIO_Channel_Type pos =i%8;
		switch (portx){
			case PORT_A:
			if (Pin_Cfg[i].Dir==Output){Set(DDRA_REG,pos);}
			else{Clear(DDRA_REG,pos);}
			if(Pin_Cfg[i].lev==high){Set(PORTA_REG,pos);}
			else{Clear(PORTA_REG,pos);}
			break;
			case PORT_B:
			if (Pin_Cfg[i].Dir==Output){Set(DDRB_REG,pos);}
			else{Clear(DDRB_REG,pos);}
			if(Pin_Cfg[i].lev==high){Set(PORTB_REG,pos);}
			else{Clear(PORTB_REG,pos);}
			break;
			case PORT_C:
			if (Pin_Cfg[i].Dir==Output){Set(DDRC_REG,pos);}
			else{Clear(DDRC_REG,pos);}
			if(Pin_Cfg[i].lev==high){Set(PORTC_REG,pos);}
			else{Clear(PORTC_REG,pos);}
			break;
			case PORT_D:
			if (Pin_Cfg[i].Dir==Output){Set(DDRD_REG,pos);}
			else{Clear(DDRD_REG,pos);}
			if(Pin_Cfg[i].lev==high){Set(PORTD_REG,pos);}
			else{Clear(PORTD_REG,pos);}
			break;
		}
	}
	
}