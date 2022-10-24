/*
 * dio.c
 *
 * Created: 20/09/2022 10:49:27 PM
 *  Author: LEGION 5
 */ 
#include "dio.h"
EN_dioError_t DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction)
{
	if (pinNumber > 7 || pinNumber < 0)
	{
		return init_failed;
	}
	switch(portNumber)
	{
		case PORT_A:
		{
			if(direction == IN) // input
				DDRA &=~(1<<pinNumber);
			else if(direction == OUT) // output	
				DDRA |= (1<<pinNumber);
			else return init_failed;
			break;
		}
		case PORT_B:
		{
			if(direction == IN) // input
				DDRB &=~(1<<pinNumber);
			else if(direction == OUT) // output
				DDRB |= (1<<pinNumber);
			else return init_failed;

			break;
		}
		case PORT_C:
		{
			if(direction == IN) // input
				DDRC &=~(1<<pinNumber);
			else if(direction == OUT) // output
				DDRC |= (1<<pinNumber);
			else return init_failed;

			break;
		}
		case PORT_D:
		{
			if(direction == IN) // input
				DDRD &=~(1<<pinNumber);
			else if(direction == OUT) // output
				DDRD |= (1<<pinNumber);
			else return init_failed;

			break;
		}
		default: return init_failed;
	}
	return DIO_OK;
}

EN_dioError_t DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value)
{
		if (pinNumber > 7 || pinNumber < 0)
		{
			return write_failed;
		}
		switch(portNumber)
		{
			case PORT_A:
			{
				if(value == LOW) // write low
				PORTA &=~(1<<pinNumber);
				else if(value == HIGH) // write high
				PORTA |=(1<<pinNumber);
				else return write_failed;

				break;
			}
			case PORT_B:
			{
				if(value == LOW) // write low
				PORTB &=~(1<<pinNumber);
				else if(value == HIGH) // write high
				PORTB |= (1<<pinNumber);
				else return write_failed;

				break;
			}
			case PORT_C:
			{
				if(value == LOW) // write low
				PORTC &=~(1<<pinNumber);
				else if(value == HIGH) // write high
				PORTC |= (1<<pinNumber);
				else return write_failed;

				break;
			}
			case PORT_D:
			{
				if(value == LOW) // write low
				PORTD &=~(1<<pinNumber);
				else if(value == HIGH) // write high
				PORTD |= (1<<pinNumber);
				else return write_failed;

				break;
			}
			default: return write_failed;
		}
	return DIO_OK;
}
EN_dioError_t DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value)
{
	if (pinNumber > 7 || pinNumber < 0)
	{
		return read_failed;
	}
	
	switch(portNumber)
	{
		case PORT_A:
		{
			*value = ((PINA&(1<<pinNumber))>>pinNumber);
			break;
		}
		case PORT_B:
		{
			*value = ((PINB&(1<<pinNumber))>>pinNumber);
			break;
		}
		case PORT_C:
		{
			*value = ((PINC&(1<<pinNumber))>>pinNumber);
			break;
		}
		case PORT_D:
		{
			*value = ((PIND&(1<<pinNumber))>>pinNumber);
			break;
		}
		default: return read_failed;
	}
	return DIO_OK;
}
EN_dioError_t DIO_toggle(uint8_t pinNumber, uint8_t portNumber)
{
	if (pinNumber > 7 || pinNumber < 0)
	{
		return toggle_failed;
	}
	switch(portNumber)
	{
		case PORT_A:
		{
			PORTA ^= (1<<pinNumber);
			break;
		}
		case PORT_B:
		{
			PORTB ^= (1<<pinNumber);
			break;
		}
		case PORT_C:
		{
			PORTC ^= (1<<pinNumber);
			break;
		}
		case PORT_D:
		{
			PORTD ^= (1<<pinNumber);
			break;
		}
		default: return toggle_failed;
	}
	return DIO_OK;
}