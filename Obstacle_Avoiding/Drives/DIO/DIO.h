/*
 * DIO.h
 *
 * Created: 02/06/2020 12:53:26 ص
 *  Author: dell
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../STD_Types.h"
#include "DIO_Types.h"
void Dio_WriteChannel(DIO_Channel_Type Id,STD_Level lev);
STD_Level DIO_ReadChannel(DIO_Channel_Type Id);
void DIO_WritePort(DIO_Port_Type Port,uint8 Cmd);




#endif /* DIO_H_ */