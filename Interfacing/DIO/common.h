/*
 * common.h
 *
 * Created: 7/14/2018 12:00:54 PM
 *  Author: ahmed-yasser
 */ 


#ifndef COMMON_H_
#define COMMON_H_

#define SET_BIT(reg,pos)         reg|=(1<<pos)
#define CLR_BIT(reg,pos)         reg&=~(1<<pos)
#define TOGGLE_BIT(reg,pos)      reg^=(1<<pos)
#define GET_BIT(reg,pos)         (reg &(1<<pos))>>pos




#endif /* COMMON_H_ */