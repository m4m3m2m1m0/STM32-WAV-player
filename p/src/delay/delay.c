/*
 * delay.c
 *
 *  Created on: 18.11.2017
 *      Author: OSKI
 */
#include "delay.h"

void delay_ms(int ms)
{
	int i, tms;
	tms = 9000*ms;
	for(i = 0; i < tms; i++)
	{
		asm("nop");
		asm("nop");
	}
}

void delay_us(int us)
{
	int i, tus;
	tus = 9*us;
	for(i=0;i<tus;i++)
	{
		asm("nop");
		asm("nop");
	}
}
