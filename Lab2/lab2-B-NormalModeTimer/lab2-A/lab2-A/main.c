/*
 * lab2-A.c
 *
 * Created: 10/10/2022 3:41:51 pm
 * Author : 20041751d
 */ 

#include <avr/io.h>

void T1Delay(int sec){ //CTC Delay
	TCCR1B |= (1<<CS10)|(1<<CS12);
	for (int i = 0; i<sec; i++)
	{
		TCNT1 = 49910;
		while ((TIFR1 & (1<<TOV1))==0);
		TCNT1 = 0;
		TIFR1 = (1<<TOV1);
	}
}

void small_delay() //delay 333ms
{
	TCCR1B |= (1<<CS10)|(1<<CS12);
	TCNT1 = 60327;
	while ((TIFR1 & (1<<TOV1))==0);
	TCNT1 = 0;
	TIFR1 = (1<<TOV1);
}


int main(void)
{
    DDRB = 0xFF; 
	DDRC = 0b00110000;
    while (1) 
    {
		PORTC = (1<<4);
		PORTB = (1<<4)|(1<<0);
		T1Delay(5);
		PORTB = (1<<5)|(1<<0);		
		T1Delay(1);
		PORTB = (1<<3)|(1<<0);
		T1Delay(1);
		PORTB = (1<<3)|(1<<0)|(1<<2);
		T1Delay(1);
		PORTC = (1<<5);
		PORTB = (1<<3)|(1<<1);
		T1Delay(5);

		//blinking part
		PORTC = 0x00;
		PORTB = (1<<3)|(1<<2);
		small_delay();
		PORTC = (1<<5);
		small_delay();
		PORTC = 0x00;
		small_delay();

		PORTC = (1<<4);
		PORTB = (1<<3)|(1<<0);
		T1Delay(1);

		PORTC = (1<<4);
		PORTB = (1<<3)|(1<<5)|(1<<0);
		T1Delay(1);
    }
}

