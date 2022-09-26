/*
 * CountOn7Seg.c
 *
 * Created: 2/6/2021 3:06:48 PM
 *  Author: A.yaser
 */ 


#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include "DIO.h"
#include "SEG.h"

int main(void)
{
	char i=0;
	DIO_Init();
	SEG_Init();
	SEG1_Display(ENABLE);
    while(1)
    {
        //TODO:: Please write your application code
		SEG_Write(i);
		_delay_ms(1000);
		if(i!=9)
		{
			i++;
		}
		else
		{
			i=0;
		}
		 
    }
}