/*
 * Ultrasonic_Robot_Slave.c
 *
 * Created: 07/07/2020 06:08:13 م
 * Author : Loay
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include "Drives/LCD/LCD.h"
#include "Drives/DIO/DIO_Cfg.h"
#include "Drives/DC motor/DC_PWM.h"
#include "Drives/DC motor/DC.h"
#include "Drives/STD_Types.h"
#include "Drives/BitMath.h"
#include "Drives/DIO/DIO_Types.h"
#include "Drives/ICU/ICU.h"
#include "Drives/UART/UART.h"
#include "Drives/Init.h"
#include "Drives/DC motor/DC_Control.h"
#include <util/delay.h>
int main(void)
{
	Sys_Init();  //Initializes All The system Requirements the DIO,PWM,UART,LCD and ICU
	
	Enter_Password();  // It Following Program requires a password to start
	LCD_Str("Hello :)");
	long dist;	
	while (1)
		{
			dist=ICU_Distance();       //The vehichle moves forward if there is no obstacle within
			if(dist>80){               //the distance of 80 cm, if an obstacle shows up, it tries 
				DC_Forward(100);       //to avoid it by manuvering to the right till the path is
				LCD_NewLine();         //Clear
				LCD_Str("Forward  ");
				
				}
				else {
					DC_Right(100);
					LCD_NewLine();
					LCD_Str("Danger!");
					
				}
					
		}
}
