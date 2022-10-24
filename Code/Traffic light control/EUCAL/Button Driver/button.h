/*
 * button.h
 *
 * Created: 21/09/2022 11:47:51 PM
 *  Author: LEGION 5
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Interrupts Driver/interrupts.h"

EN_dioError_t BUTTON_init(uint8_t pinNumber, uint8_t portNumber);
EN_dioError_t BUTTON_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);





#endif /* BUTTON_H_ */