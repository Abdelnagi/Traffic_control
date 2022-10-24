/*
 * traffic.h
 *
 * Created: 10/11/2022 11:45:29 PM
 *  Author: boodi
 */ 


#ifndef TRAFFIC_H_
#define TRAFFIC_H_

#include "../LED Driver/led.h"

// Traffic lights pins
#define Red_led_car 0
#define Red_led_man 0
#define Yellow_led_car 1
#define Yellow_led_man 1
#define Green_led_car 2
#define Green_led_man 2
#define Car_port PORT_A
#define Man_port PORT_C


//Pedestrian Button
#define man_click 2

// Current states

typedef enum traffic_states
{
	Red_state, Yellow_RtG_state, Yellow_GtR_state, Green_state
}traffic_states;

typedef enum traffic_lights
{
	Red_light, Yellow_light, Green_light
}traffic_lights;


#define waiting_time 5
//makes the yellow light blink every 0.5 seconds
void yellow_blink(uint8_t pinNumber1, uint8_t pinNumber2, uint8_t portNumber1, uint8_t portNumber2, int seconds); 
//void switcher(traffic_lights from, traffic_lights to); //switch lights from first argument to second argument



#endif /* TRAFFIC_H_ */