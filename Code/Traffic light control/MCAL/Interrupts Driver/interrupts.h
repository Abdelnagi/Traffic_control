/*
 * interupts.h
 *
 * Created: 10/11/2022 7:48:13 PM
 *  Author: boodi
 */ 


#ifndef INTERUPTS_H_
#define INTERUPTS_H_

/************************************************************************/
/*			Interrupt Vectors											*/
/************************************************************************/

/*External interrupt vector*/
/*External interrupt Request 0*/
#define EXT_INT_0 __vector_1

/*External interrupt Request 1*/
#define EXT_INT_1 __vector_2

/*External interrupt Request 2*/
#define EXT_INT_2 __vector_3

// Set global interrupts, set the I bit to 1
# define sei()  __asm__ __volatile__ ("sei" ::: "memory")

// Clear global interrupts, set the I bit to 0
# define cli()  __asm__ __volatile__ ("cli" ::: "memory")


#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

#endif /* INTERUPTS_H_ */