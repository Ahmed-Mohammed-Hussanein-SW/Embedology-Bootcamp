/*
 * UART.c
 *
 * Created: 6/9/2017 3:54:22 AM
 *  Author: A.Aboelmakarem
 */ 
#include <avr/io.h>
#include "UART.h"
#include "common.h"
void UART_Init(void )
{
	UBRRH= UBRR_INIT>>8;
	UBRRL=UBRR_INIT;
	UCSRB=UCSRB_INIT;
	UCSRC=UCSRC_INIT;	
}

void UART_Transmit( char Data ) 
{
	
	while(! GET_BIT(UCSRA,UDRE));
	UDR=Data;
	
}

void UART_Receive( char *PtrToData )
{
	
	while(! GET_BIT(UCSRA,7));
	*PtrToData =UDR;
}