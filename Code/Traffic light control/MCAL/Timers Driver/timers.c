/*
 * timers.c
 *
 * Created: 10/11/2022 9:58:20 PM
 *  Author: boodi
 */ 

#include "timers.h"

uint8_t skiptimer = 0;		

EN_tiemrError_t Timer0_wait(float seconds)
{
	int overflow_counter = 0;
	//Set timer mode to normal
	TCCR0 = 0x00;
	//Set timer initial value to 12
	TCNT0 = 0x00 | (1<<3) | (1<<2);
		
	TCCR0 |= (1<<0) | (1<<2); //Prescaler = 1024 and start timer
	//Number of overflows required for 1 sec is equal to 4
	//T_tick = 1.024 msec
	//T_max = 0.262 sec
	//T_inital value = 12
	while(overflow_counter < 4 * seconds && skiptimer == 0)
	{
		while((TIFR&(1<<0)) == 0 && skiptimer == 0);
		//overflow is done
				
		TIFR |=(1<<0);

		overflow_counter++;
		TCNT0 = 0x00 | (1<<3) | (1<<2);
	}
	if (skiptimer)
	{
		skiptimer = 0;
		return timer_skipped;
	}
	overflow_counter = 0;
	TCCR0 =0x00;
	return timer_ok;
}

EN_tiemrError_t Timer0_stop(void)
{
	skiptimer = 1;
	return timer_ok;
}