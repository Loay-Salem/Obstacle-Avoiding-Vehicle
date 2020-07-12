/*
 * DC.h
 *
 * Created: 08/07/2020 12:47:47 ص
 *  Author: dell
 */ 


#ifndef DC_H_
#define DC_H_
#define Forward1 0
#define Backward1 1
#define Forward2 6
#define Backward2 7
#define DC_REG1 PORTB_REG
#define DC_REG2 PORTB_REG
void DC_Forward(uint8 Speed);
void DC_Left(uint8 Speed);
void DC_Right(uint8 Speed);
void DC_Back(uint8 Speed);
void DC_Stop();
#endif /* DC_H_ */