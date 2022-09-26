/*
 * UART.c
 *
 * Created: 6/9/2017 3:52:55 AM
 *  Author: A.Aboelmakarem
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "DIO.h"
#include "SEG.h"
#include "UART.h"
int main(void)
{
	char x,status=0;
	int i=0;
	DIO_Init();
	UART_Init();
	SEG_Init();
	SEG1_Display(ENABLE);
    while(1)
    {
			
			UART_Receive(&x);
			if(x=='I')
			{
				if(i!=9)
				{
				
				i++;	
				}
				else
				{
					
					i=0;
				}
				SEG_Write(i);
				_delay_ms(200);
								
			}
			else if(x=='L')
			{
				if(status==0)
				{
					DIO_WritePinVal(31,1);
					status =1;
				}
				else 
				{
					
					DIO_WritePinVal(31,0);
					status=0;
					
				}
				_delay_ms(200);
				
				UART_Transmit('D');
			}
			

			//if(count!=9)
		//	count++;
			//else
			//count=0;
         
    }
}