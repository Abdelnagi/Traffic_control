/*
 * timers.h
 *
 * Created: 10/11/2022 9:58:51 PM
 *  Author: boodi
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_

#include "../../Utilities/resgisters.h"
typedef enum EN_tiemrError_t
{
	timer_ok, timer_error, timer_skipped
	}EN_tiemrError_t;

EN_tiemrError_t Timer0_wait(float seconds);
EN_tiemrError_t Timer0_stop(void);




#endif /* TIMERS_H_ */