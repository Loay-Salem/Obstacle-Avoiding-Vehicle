/*
 * DIO_Cfg.h
 *
 * Created: 02/06/2020 01:36:20 ص
 *  Author: dell
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_
#include "../STD_Types.h"
#include "DIO_Types.h"
typedef struct {
	DIO_Dir Dir;
	STD_Level lev;
}Pin_Dir;

#define Pin_Count 32
extern const Pin_Dir Pin_Cfg[Pin_Count];
void DIO_Init();






#endif /* DIO_CFG_H_ */