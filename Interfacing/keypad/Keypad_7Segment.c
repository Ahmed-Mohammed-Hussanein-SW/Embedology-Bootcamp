/*
 * Keypad_7Segment.c
 *
 * Created: 2/7/2021 10:51:00 AM
 *  Author: A.yaser
 */ 


#include <avr/io.h>
#include "DIO.h"
#include "SEG.h"
#include "KBD.h"

int main(void)
{
	char x;
	DIO_Init();
	SEG_Init();
	KBD_Init();
	SEG1_Display(ENABLE);
    while(1)
    {
        //TODO:: Please write your application code
		x=KBD_Read();
		if(x!=255)
		{
			SEG_Write(x);
		}
		 
    }
}