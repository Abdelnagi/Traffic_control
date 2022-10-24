/*
 * dio.h
 *
 * Created: 20/09/2022 10:49:40 PM
 *  Author: LEGION 5
 */ 


#ifndef DIO_H_
#define DIO_H_
 #include "../../Utilities/resgisters.h"

//	all internal driver typedefs
//	all driver macros
//	all driver function prototypes

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//	Direction defines
#define IN 0
#define OUT 1

//	Value defines
#define LOW 0
#define HIGH 1

typedef enum EN_dioError_t
{
	DIO_OK, init_failed, write_failed, read_failed, toggle_failed
}EN_dioError_t;

EN_dioError_t DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction);
EN_dioError_t DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value);
EN_dioError_t DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);
EN_dioError_t DIO_toggle(uint8_t pinNumber, uint8_t portNumber);




#endif /* DIO_H_ */