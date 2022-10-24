/*
 * Traffic light control.c
 *
 * Created: 10/11/2022 8:16:13 PM
 * Author : boodi
 */ 

#include "application.h"

uint8_t readyForInterrupt = 1; 
EN_appError_t APP_start()
{
	
// Initiate pin direction for the LEDs and the Button
	if (					// if any function returns any error APP_start() return error
			LED_init(Red_led_car, Car_port)||
			LED_init(Yellow_led_car, Car_port)||
			LED_init(Green_led_car, Car_port)||
			LED_init(Red_led_man, Man_port)||
			LED_init(Yellow_led_man, Man_port)||
			LED_init(Green_led_man, Man_port)||
			BUTTON_init(man_click, PORT_D)
		)	return start_error;
	
//Set global interrupts	
	sei();
	MCUCR |= (1<<0) | (1<<1);		//activate on rising edge of interrupt 1
	GICR |= (1<<6);					//enable external pin interrupt

	return App_OK;

}

EN_appError_t APP_loop()
{
	switch(current_car_state)
	{
		case Red_state:
			//turn car light red on
			LED_on(Red_led_car, Car_port);
			LED_off(Yellow_led_car, Car_port);
			LED_off(Green_led_car, Car_port);
			//turn man light green on
			LED_off(Red_led_man, Man_port);
			LED_off(Yellow_led_man, Man_port);
			LED_on(Green_led_man, Man_port);
			current_car_state = Yellow_RtG_state;
			readyForInterrupt = 0;
			Timer0_wait(waiting_time);
			return App_OK;
			
		case Yellow_RtG_state:	//yellow light blink from red light to green light

			LED_off(Red_led_car, Car_port);	
			LED_off(Green_led_car, Car_port);

			LED_off(Red_led_man, Man_port);
			LED_off(Green_led_man, Man_port);
			current_car_state = Green_state;
			readyForInterrupt = 1;
			yellow_blink(Yellow_led_car, Yellow_led_man, Car_port, Man_port, waiting_time);		

			return App_OK;
		
		case Yellow_GtR_state:	//yellow light blink from green light to red light

			LED_off(Red_led_car, Car_port);
			LED_off(Green_led_car, Car_port);
			
			LED_off(Red_led_man, Man_port);
			LED_off(Green_led_man, Man_port);
			
			current_car_state = Red_state;
			readyForInterrupt = 0;
			yellow_blink(Yellow_led_car, Yellow_led_man, Car_port, Man_port, waiting_time);
				
			return App_OK;

		case Green_state:
			//turn car light green on
			LED_off(Red_led_car, Car_port);
			LED_off(Yellow_led_car, Car_port);
			LED_on(Green_led_car, Car_port);
			//turn man light red on
			LED_on(Red_led_man, Man_port);
			LED_off(Yellow_led_man, Man_port);
			LED_off(Green_led_man, Man_port);
		
			current_car_state = Yellow_GtR_state;
			Timer0_wait(waiting_time);
			
			return App_OK;
		default: return loop_error;
	}
}


ISR(EXT_INT_0)
{
	if(readyForInterrupt)
	{
		readyForInterrupt = 0;
		switch(current_car_state)
		{
			case Yellow_GtR_state:
				current_car_state = Yellow_GtR_state;
				Timer0_stop();
				break;
			case Red_state:
				current_car_state = Yellow_GtR_state;
				Timer0_stop();
				break;
			case Green_state:
				current_car_state = Yellow_GtR_state;
				Timer0_stop();
				break;
			default: 
				readyForInterrupt = 1;

				break;
				// no change
						
	}
	}

}
