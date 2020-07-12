/*
 * Password.c
 *
 * Created: 12/07/2020 01:49:02 ص
 *  Author: dell
 */ 
/* The Password required for the vehichle to start is "abc"*/
#include "Password.h" 

void Enter_Password(){
	uint8 x;
	uint8 count=0;
	uint8 flag=0;
	LCD_Str("Please Enter");
	LCD_Command(0x80);
	LCD_NewLine();
	LCD_Str("Password");
	LCD_Command(0x80);
	while (1){
		x=URec();
		if (count<1){
			LCD_Clear();
		}
		LCD_Char(x);
		if (x=='a'&&count==0){
			count=1;			
			continue;
		}
		if (x=='b'&&count==1){
			count=2;			
			continue;
		} 
			if (x=='c'&&count==2){
			count=3;			
			flag=1;
			continue;
		}
			
			if (flag>0){
				LCD_Clear();
				LCD_Str("Correct");
				_delay_ms(200);
				break;
			}
			if(count>2&&flag==0){
				LCD_Clear();
				LCD_Str("Wrong Password");
				_delay_ms(200);
				LCD_Clear();
				LCD_Str("Please Enter");
				LCD_Command(0x80);
				LCD_NewLine();
				LCD_Str("Password");
				LCD_Command(0x80);
				count=0;
				continue;
			}
			count++;
		
	}
}