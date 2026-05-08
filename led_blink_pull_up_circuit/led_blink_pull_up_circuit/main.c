/*
 * led_blink_pull_up_circuit.c
 *
 * Created: 15/04/2026 22:15:36
 * Author : LENOVO
 */ 
#define F_CPU 1600000UL
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
   DDRD &= ~(1<<DDD2); // config PORTD pin 2 as input
   PORTD |= (1<< PD2);  // enabling internal pull up   which will eleminate the external pull up circuit
   DDRC |= (1<< DDC2); // config PORTC pin2 as output
   
    while (1) 
    {
		// checking for the switch press for low
		if (!(PIND & (1<< PIND2))) // !--> not operator to reverse the current value
		{
			PORTC ^= (1<< PC2);
			while (!PIND & (1<< PIND ));
			
		}
		
	
    }
	
}

