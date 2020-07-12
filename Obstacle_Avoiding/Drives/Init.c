/*
 * Init.c
 *
 * Created: 09/07/2020 08:25:37 م
 *  Author: dell
 */ 

void Sys_Init(){
		DIO_Init();
		DC_PWM_Init();
		LCD_Init();
		ICU_Init();
		UART_Init();
}