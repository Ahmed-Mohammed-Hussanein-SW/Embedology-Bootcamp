/*
 * UART.h
 *
 * Created: 4/4/2021 7:54:04 PM
 *  Author: A.yaser
 */ 


#ifndef UART_H_
#define UART_H_
#define FCPU 8000000UL
#define BAUD 9600UL 


#define UBRR_INIT ((FCPU)/(BAUD*16)-1)
#define UCSRB_INIT 0b00011000
#define UCSRC_INIT 0b10000110

void UART_Init(void);
void UART_Transmit(char Data);
void UART_Receive(char *PtrToData);




#endif /* UART_H_ */