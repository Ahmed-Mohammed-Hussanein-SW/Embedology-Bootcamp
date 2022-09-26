/*
 * UART.c
 *
 * Created: 4/4/2021 7:51:46 PM
 *  Author: A.yaser
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "DIO.h"
#include "UART.h"
#include "SEG.h"
int main(void)
{
	char x,count=0;
	DIO_Init();
	UART_Init();
	SEG_Init();
    while(1)
    {
        //TODO:: Please write your application code 
		UART_Transmit(count);
		UART_Receive(&x);
		SEG_Write(x);
		_delay_ms(500);
		if(count!=9)
		count++;
		else
		count=0;
    }
}