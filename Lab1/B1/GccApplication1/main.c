/*
 * GccApplication1.c
 *
 * Created: 26/9/2022 3:27:22 pm
 * Author : 20041751d
 */ 

#include <avr/io.h>

void delaysmh (void) 
{
	unsigned k;
	unsigned j;
	for (k = 0; k <42150; k ++)
	{for (j = 0; j <20; j ++);}
}



int main(void)
{
    /* Replace with your application code */
	DDRD = 0xFF;
	DDRB = 0x01;
    while (1) 
    {
		if(PINB & (1<<0)) //if PIN8 is high
		{
			PORTD = 0xFF;
		}
		else //otherwise
		{
			PORTD = 0x00 ;
		}

    }
}

