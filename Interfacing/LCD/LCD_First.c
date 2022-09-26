/*
 * LCD_First.c
 *
 * Created: 2/7/2021 1:24:33 PM
 *  Author: A.yaser
 */ 


#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include "DIO.h"
#include "LCD.h"
int main(void)
{
	char str[10]="Ahmed";
	char str2[10]="Mohammed";
	DIO_Init();
	LCD_Init();
    while(1)
    {
        //TODO:: Please write your application code 
		LCD_WriteString(str);
		_delay_ms(500);
		LCD_GoToxy(0,1);
		LCD_WriteString(str2);
		_delay_ms(1000);
		LCD_WriteCommand(0x01);
		_delay_ms(1000);
    }
}