/*
 * pull_down_resistor_withled.c
 *
 * Created: 14/04/2026 17:11:34
 * Author : LENOVO
 */ 
#define F_CPU 1600000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	//config as input
	DDRD &= ~(1<<DDD4);
	DDRC |= (1<<DDC1);
	
    while (1) 
    {
		if (PIND & (1 << PIND4))
		{
			PORTC|= (1<<PC1);
		}
		else
		PORTC &= ~(1<<PC1);
    }
}

