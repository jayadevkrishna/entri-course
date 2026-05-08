/*
 * led_blink_test.c
 *
 * Created: 13/04/2026 16:47:04
 * Author : LENOVO
 */ 
#define F_CPU 1600000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	//port pin configuration - pin2 - output
	DDRD = 0b00011111;
   
    while (1) 
    {
		//port pin2 high
		PORTD = 0b00010101;
		_delay_ms(1000);
		PORTD = 0b00000000;
		_delay_ms(1000);
		PORTD = 0b00001010;
		_delay_ms(1000);
		PORTD = 0b00000000;
		_delay_ms(1000);
    }
}

