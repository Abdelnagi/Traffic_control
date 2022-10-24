/*
 * led.c
 *
 * Created: 21/09/2022 12:55:18 AM
 *  Author: LEGION 5
 */ 

#include "led.h"

	EN_dioError_t LED_init(uint8_t pinNumber, uint8_t portNumber)
	{
		return DIO_init(pinNumber, portNumber, OUT);
	}
	EN_dioError_t LED_on(uint8_t pinNumber, uint8_t portNumber)
	{
		return DIO_write(pinNumber, portNumber, HIGH);
	}
	EN_dioError_t LED_off(uint8_t pinNumber, uint8_t portNumber)
	{
		return DIO_write(pinNumber, portNumber, LOW);
	}
	EN_dioError_t LED_toggle(uint8_t pinNumber, uint8_t portNumber)
	{
		return DIO_toggle(pinNumber,portNumber);
	}
	EN_dioError_t LED_blink(uint8_t pinNumber, uint8_t portNumber, int seconds)
	{
		for (int i = 0; i<= 2*seconds; i++)
		{
			if(LED_toggle(pinNumber, portNumber))	return toggle_failed;
			Timer0_wait(.5);	
		}
		return DIO_OK;
		
	}
