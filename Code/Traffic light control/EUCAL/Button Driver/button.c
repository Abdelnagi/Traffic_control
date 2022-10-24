/*
 * button.c
 *
 * Created: 21/09/2022 11:47:19 PM
 *  Author: LEGION 5
 */ 
#include "button.h"
EN_dioError_t BUTTON_init(uint8_t pinNumber, uint8_t portNumber)
{
	return DIO_init(pinNumber, portNumber, IN);
}
EN_dioError_t BUTTON_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value)
{
	return DIO_read(pinNumber,portNumber, value);
}