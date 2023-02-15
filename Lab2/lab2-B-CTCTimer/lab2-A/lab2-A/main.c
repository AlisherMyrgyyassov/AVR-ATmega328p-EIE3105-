/*
 * lab2-A.c
 *
 * Created: 10/10/2022 3:41:51 pm
 * Author : 20041751d
 */ 

#include <avr/io.h>


/*
void T1Delay(int sec){ //Normal Delay
	TCCR1B |= (1<<CS10)|(1<<CS12);
	for (int i = 0; i<sec; i++)
	{
		TCNT1 = 49910;
		while ((TIFR1 & (1<<TOV1))==0);
		TCNT1 = 0;
		TIFR1 = (1<<TOV1);
	}
}

void small_delay() // normal delay 333ms
{
	TCCR1B |= (1<<CS10)|(1<<CS12);
	TCNT1 = 60327;
	while ((TIFR1 & (1<<TOV1))==0);
	TCNT1 = 0;
	TIFR1 = (1<<TOV1);
}
*/

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
	DDRC = 0b00110000;
    while (1) 
    {
		PORTC = (1<<4);
		PORTB = (1<<4)|(1<<0);
		small_delay(50);
		PORTB = (1<<5)|(1<<0);		
		small_delay(10);
		PORTB = (1<<3)|(1<<0);
		small_delay(10);
		PORTB = (1<<3)|(1<<0)|(1<<2);
		small_delay(10);
		PORTC = (1<<5);
		PORTB = (1<<3)|(1<<1);
		small_delay(50);

		//blinking part
		PORTC = 0x00;
		PORTB = (1<<3)|(1<<2);
		small_delay(3);
		PORTC = (1<<5);
		small_delay(3);
		PORTC = 0x00;
		small_delay(3);

		PORTC = (1<<4);
		PORTB = (1<<3)|(1<<0);
		small_delay(10);

		PORTC = (1<<4);
		PORTB = (1<<3)|(1<<5)|(1<<0);
		small_delay(10);
    }
}


