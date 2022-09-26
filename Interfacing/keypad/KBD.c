/*
 * KBD.c
 *
 * Created: 7/26/2018 12:48:53 AM
 *  Author: ahmed-yasser
 */ 
#include "DIO.h"
#include "KBD.h"

void KBD_Init()
{
	DIO_WritePinVal(ROW0_PIN,0);
	DIO_WritePinVal(ROW1_PIN,0);
	DIO_WritePinVal(ROW2_PIN,0);
	DIO_WritePinVal(ROW3_PIN,0);	
}
char KBD_Read()
{
	char Row0Val=0,Row1Val=0,Row2Val=0,Row3Val=0;
	char i;
	char KBD_value=255;
	for(i=0;i<4;i++)
	{
		/*This Switch case is responsible for generating the pattern of the rows*/
		switch(i)
		{
			case 0 :
			 Row0Val=1;
			 Row1Val=0;
			 Row2Val=0;
			 Row3Val=0;
			 break;
			 
			case 1 :
			Row0Val=0;
			Row1Val=1;
			Row2Val=0;
			Row3Val=0;
			break;
			
			case 2 :
			Row0Val=0;
			Row1Val=0;
			Row2Val=1;
			Row3Val=0;
			break;
			
			case 3 :
			Row0Val=0;
			Row1Val=0;
			Row2Val=0;
			Row3Val=1;
			break;
			
			default:
			break;						 
		}
		DIO_WritePinVal(ROW0_PIN,Row0Val);
		DIO_WritePinVal(ROW1_PIN,Row1Val);
		DIO_WritePinVal(ROW2_PIN,Row2Val);
		DIO_WritePinVal(ROW3_PIN,Row3Val);
		
		if(DIO_ReadPinVal(COL0_PIN)==1)
		{
			switch(i)
			{
				case 0:
				KBD_value =1;
				break;
				case 1:
				KBD_value=4;
				break;
				case 2:
				KBD_value=7;
				break;
				default:
				
				break;
			}		
		}
		else if (DIO_ReadPinVal(COL1_PIN)==1)
		{
			switch(i)
			{
				case 0:
				KBD_value =2;
				break;
				case 1:
				KBD_value=5;
				break;
				case 2:
				KBD_value=8;
				break;
				case 3:
				KBD_value=0;
				default:
				break;
			}		
		}
		else if (DIO_ReadPinVal(COL2_PIN)==1)
		{
			switch(i)
			{
				case 0:
				KBD_value =3;
				break;
				case 1:
				KBD_value=6;
				break;
				case 2:
				KBD_value=9;
				break;
				default:
				break;
			}
		}
		else
		{
		}		
	}
	
	return KBD_value;

}
