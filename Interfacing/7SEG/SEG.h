/*
 * SEG.h
 *
 * Created: 4/25/2017 2:17:51 AM
 *  Author: A.Aboelmakarem
 */ 
#include <avr/io.h>
#include "DIO.h"
#include "common.h"

/*************Prototypes********************/
void SEG_Write(char val);
void SEG1_Display(char val);
void SEG2_Display(char val);
void SEG_Init(void);




/*************Configuration****************/
#define BCD_DECODER

#define SEG1_EN  16
#define SEG2_EN  17
#define  ENABLE  0
#define  DISABLE 1

#ifndef BCD_DECODER
#define SEG_PORT 3
#define ZERO   0b00111111
#define ONE    0b00000110
#define TWO    0b01011011
#define THREE  0b01001111
#define FOUR   0b01100110
#define FIVE   0b01101101
#define SIX    0b01111101
#define SEVEN  0b00000111
#define EIGHT  0b01111111
#define NINE   0b01101111
#else
#define ON 1
#define OFF 0
#define PINSEG_A 24
#define PINSEG_B 25
#define PINSEG_C 26
#define PINSEG_D 27
#endif

