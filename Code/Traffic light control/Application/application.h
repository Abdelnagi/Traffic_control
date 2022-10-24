/*
 * application.h
 *
 * Created: 9/28/2022 12:28:51 AM
 *  Author: boodi
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_


#include "../EUCAL/Traffic lights driver/traffic.h"
#include "../EUCAL/Button Driver/button.h"
#include "../EUCAL/LED Driver/led.h"


traffic_states current_car_state;

typedef enum EN_appError_t
{
	App_OK, start_error, loop_error
}EN_appError_t;
EN_appError_t APP_start();
EN_appError_t APP_loop();




#endif /* APPLICATION_H_ */