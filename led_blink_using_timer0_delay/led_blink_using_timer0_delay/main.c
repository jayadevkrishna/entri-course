/*
 * led_blink_using_timer0_delay.c
 *
 * Created: 15/04/2026 18:32:59
 * Author : LENOVO
 */ 


#define  F_CPU 16000000UL
#include <avr/io.h>
void delay_1s(void)
{
	//step 1: load 0 to TCNT0
	TCNT0 = 0;
	
	//step  2: choose mode 0
	TCCR0A &= ~((1<< WGM00)| (1<<WGM01));
	TCCR0B &= ~(1<< WGM02);
	
	//step 3 choosing the pre-scalaer value =0	
	TCCR0B &= ~( (1<<CS02) | (1<<CS01));
	TCCR0B |= (1 << CS00);
	
	// step 4: overflow caluculation
	/* Fclk = 16Mhz = 16,000,000 
	 1 tick= 1/16,000,000= 62.5 ns
	256 ticks = 256 * 62.5 = 16 micro seconds--->1 overflow--->16*10^-6
	for 1s = 1/16 micro seconds = 62500 overflow required for 1s delay*/
	
	
	for (uint16_t i = 0;i<62500;i++) 
	{
		while(!(TIFR0 & (1 << TOV0)));
		TIFR0 |= (1 << TOV0); // clearing the bit by writing 1 to it
	}
	}
	



int main(void)
{
    //port config as output
	DDRB |= (1<<DDB2);
	//Make low during starting
	PORTB &= (1<< PB2);
	
	
    while (1) 
    {
		PORTB ^= (1<< PB2);
		delay_1s();
    }
}

