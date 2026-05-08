/*
 * dc_motor_rotation.c
 *
 * Created: 13/04/2026 22:34:08
 * Author : LENOVO
 */ 
#define F_CPU 1600000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	// PIND1 and PIND2 as input 1 and 2
    DDRD |= ((1<<DDD1)|(1<<DDD2));
	
    while (1) 
    {
		//clockwise direction
		PORTD |= (1 << PD1); //high
		PORTD &= ~(1 << PD2);//low
		_delay_ms(5000);
		
    }
	PORTD |= (1 << PD2);//high
	PORTD &= ~(1 << PD1);//low
	_delay_ms(8000)
}

