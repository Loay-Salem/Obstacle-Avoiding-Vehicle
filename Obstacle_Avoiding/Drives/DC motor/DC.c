/*
 * DC.c
 *
 * Created: 08/07/2020 12:47:16 ص
 *  Author: dell
 */ 
#include "../STD_Types.h"
#include "../BitMath.h"
#include "DC.h"
#include "../DIO/DIO_HW.h"
void DC_Forward(uint8 Speed){
	Set(DC_REG1,Forward1);
	Set(DC_REG2,Forward2);
	Clear(DC_REG1,Backward1);
	Clear(DC_REG2,Backward2);
	OCR0_REG=(2.55*(Speed-100))+255;
	OCR2_REG=(2.55*(Speed-100))+255;

}
void DC_Right(uint8 Speed){
	Set(DC_REG1,Forward1);
	Set(DC_REG2,Forward2);
	Clear(DC_REG1,Backward1);
	Clear(DC_REG2,Backward2);
	OCR0_REG=0;
	OCR2_REG=(2.55*(Speed-100))+255;	
}
void DC_Left(uint8 Speed){
	Set(DC_REG1,Forward1);
	Set(DC_REG2,Forward2);
	Clear(DC_REG1,Backward1);
	Clear(DC_REG2,Backward2);
	OCR0_REG=(2.55*(Speed-100))+255;
	OCR2_REG=0;
}
void DC_Back(uint8 Speed){
	Set(DC_REG1,Backward1);
	Set(DC_REG2,Backward2);
	Clear(DC_REG1,Forward1);
	Clear(DC_REG2,Forward2);
	OCR0_REG=(2.55*(Speed-100))+255;
	OCR2_REG=(2.55*(Speed-100))+255;
}
void DC_Stop(){
	Clear(DC_REG1,Backward1);
	Clear(DC_REG2,Backward2);
	Clear(DC_REG1,Forward1);
	Clear(DC_REG2,Forward2);
	OCR0_REG=0;
	OCR2_REG=0;
}