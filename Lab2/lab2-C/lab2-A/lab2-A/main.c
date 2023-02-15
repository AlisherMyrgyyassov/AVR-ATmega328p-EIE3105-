/*
 * lab2-A.c
 *
 * Created: 10/10/2022 3:41:51 pm
 * Author : 20041751d
 */ 

#include <avr/io.h>

void small_delay(int csec){ //CTC Delay, each iteration is 100 ms
	OCR0A = 255;
	for (int i = 0; i<6*csec; i++)
	{
		TCNT0 = 0x00;
		TCCR0B = (1<<CS00)|(1<<CS02);
		while ((TIFR0 & (1<<OCF0A))==0);
		TCNT0 = 0x00;
		TIFR0 = 1<<OCF0A;
	}
}

int main(void)
{
    DDRB = 0xFF; 
	DDRC = (1<<0);
	DDRD |= (0<<4);

	TCCR0B = (1<<CS00)|(1<<CS01)|(1<<CS02);
	OCR0A = 2; // 012 -> overflow
	TCCR0A = (1<<WGM01)|(0<<WGM00);
	TCNT0 = 0x00;
    while (1) 
    {
		TCNT0 = 0x00;
		while((TIFR0 & (1<<OCF0A))==0);
		TIFR0 = (1<<OCF0A);
		PORTC = PORTC^(1<<PORTC0);		
    }
}


