/*
 * delay_function_using_ctc_timer0.c
 *
 * Created: 15/04/2026 20:20:46
 * Author : LENOVO
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>

void delay_1s(void)
{
	

//step 1 :
TCNT0 =0;

//step2 : select CTC mode
TCCR0A |= (1<< WGM01);
TCCR0B &=  ~(1<<WGM00);
TCCR0B &= ~(1<< WGM02);

//step3 : prescalar value :64
TCCR0B |= ((1<<CS01) | (1<<CS00));
TCCR0B &=  ~(1 << CS02);

// method I

//calculation part
/*Fclk=16,000,000
prescalar value:64
new frequency = 25,00,00
1 tick = 1/25,00,00 = 4 micro seconds 
1ms = 1000 micro seconds
1000/4 = 250 // check it fit under (0 -255)
250-1 = 249 ----> value to be loaded OCROA

method II

formula:
OCR0A = (fclock / (prescalar value * frequncy))-1
1 ms = 1x10^-3
frequency = 1/ time period = 1/ 1x 10^-3
OCR0A = 16,000,000 / (64 x 1000)-1
      = 16,000,000 / 640000-1
	  = 250-1
	  = 249
*/

OCR0A = 249;

for (uint16_t i = 0; i< 1000; i++)
{
	while(!(TIFR0 & (1<< OCF0A)));
	TIFR0 |= (1<< OCF0A);
}
}
int main(void)
{
    DDRB |= (1<< DDB5);
	PORTB &= ~(1<< PB5);
	
    while (1) 
    {
       PORTB ^= (1 << PB5);
       delay_1s();
    }
}

