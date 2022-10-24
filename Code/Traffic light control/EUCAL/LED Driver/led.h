/*
 * led.h
 *
 * Created: 21/09/2022 12:55:29 AM
 *  Author: LEGION 5
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Timers Driver/timers.h"


	EN_dioError_t LED_init(uint8_t pinNumber, uint8_t portNumber);
	EN_dioError_t LED_on(uint8_t pinNumber, uint8_t portNumber);
	EN_dioError_t LED_off(uint8_t pinNumber, uint8_t portNumber);
	EN_dioError_t LED_toggle(uint8_t pinNumber, uint8_t portNumber);	
	EN_dioError_t LED_blink(uint8_t pinNumber, uint8_t portNumber, int seconds);

	



#endif /* LED_H_ */