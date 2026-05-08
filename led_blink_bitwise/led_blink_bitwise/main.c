/*
 * led_blink_bitwise.c
 *
 * Created: 13/04/2026 17:29:13
 * Author : LENOVO
 */ 
#define F_CPU 1600000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // config DDRD PIN§and PIN! as output
	DDRD |= ((1<<DDD3) | (1<<DDD1));
	
    while (1) 
    {
		PORTD |= ((1<<PD3)|(1<<PD1));
		_delay_ms(3000);
		PORTD &= ~((1<<PD3)|(1<<PD1));
		_delay_ms(3000);
    }
}

