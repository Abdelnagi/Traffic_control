/*
 * traffic.c
 *
 * Created: 10/11/2022 11:45:39 PM
 *  Author: boodi
 */ 
#include "traffic.h"

void yellow_blink(uint8_t pinNumber1, uint8_t pinNumber2, uint8_t portNumber1, uint8_t portNumber2, int seconds)
{
	for (int i = 0; i<= 2*seconds; i++)
	{
		
		LED_toggle(pinNumber1, portNumber1);
		LED_toggle(pinNumber2, portNumber2);
		
		Timer0_wait(.5);
	}
}