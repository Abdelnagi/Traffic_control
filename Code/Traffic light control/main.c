/*
 * main.c
 *
 * Created: 10/23/2022 5:30:57 PM
 *  Author: boodi
 */ 
#include "Application/application.h"

void testButtonfunctions()
{
	uint8_t value;
	BUTTON_init(1, PORT_A);
	LED_init(2, PORT_A);
	while(BUTTON_read(1, PORT_A, &value) == DIO_OK)
	{
		if (value == HIGH)
		{
			LED_on(2, PORT_A);
		}
		else if(value == LOW)
		{
			LED_off(2, PORT_A);
		}
	}
}
void testLEDfunctions()
{
	LED_init(1, PORT_A);
	LED_on(1, PORT_A);
	for(int i = 1; i < 4; i++)
	{
		LED_toggle(1, PORT_A);
	}
	LED_off(1, PORT_A);
}

void testTimerFunctions()
{
	Timer0_wait(1);		//wait 1 second
}
int main()
{
	APP_start();
	while(1)
		APP_loop();
}

