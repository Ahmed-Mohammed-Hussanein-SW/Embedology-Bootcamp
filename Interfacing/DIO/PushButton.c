/*
 * PushButton.c
 *
 * Created: 2/6/2021 4:01:36 PM
 *  Author: A.yaser
 */ 


#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

#include "DIO.h"
int main(void)
{
	char status=0;
	DIO_Init();
    while(1)
    {
        //TODO:: Please write your application code 
		if(DIO_ReadPinVal(24))
		{
			while(DIO_ReadPinVal(24));
			if(status==0)
			{
				DIO_WritePinVal(16,1);
				status=1;
			}
			else
			{
				DIO_WritePinVal(16,0);
				status=0;
			}
			_delay_ms(1000);
			
		}
			
    }
}