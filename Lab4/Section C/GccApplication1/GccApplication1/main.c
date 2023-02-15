#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

void UART_TxChar (char data); //send char from arduino
char UART_RxChar ();		  //receive char to arduino
void UART_TxString(char text[]); // send strings

int main(void)
{
	UBRR0L = 0xd0;//4800 baud rate (bps), see more at USART section, examples of UBRRn Settings
	
	UCSR0B = (1<<TXEN0)|(1<<RXEN0); // TXEN for sending from microcontroller, RXEN to receive to microcontroller
	
	UCSR0C = (1<<UCSZ00)|(1<<UCSZ01); //what is the size of data we want to send. By initializing these two bits, we set the 
									  // size of data to be 8 bit. More on USART Character size in the manual.
	
	
	
		
	//Section C
	
	char currentChar = '\0';
	char comparisonChar;
	while (1) 
	{
		while (1)
		{
			UART_TxChar('a');
			if(UCSR0A&(1<<RXC0))
			{
				currentChar = UDR0;
				break;
			}
			_delay_ms(200);
		}
		for (int i = 0; i < 10; i++)
		{
			UART_TxChar(currentChar);
		}
		while (1)
		{
			comparisonChar = UART_RxChar();
			if (comparisonChar == currentChar) break;
		}
	}	
	
}


void UART_TxChar(char data) { // send char from microcontroller
	while (!(UCSR0A&(1<<UDRE0))); //check UCSR0A register, and whenever UDRE0 is set, we get
	UDR0 = data;				  //the serial value. UDR0 is the bit to be sent.
}

char UART_RxChar () {
	while(!(UCSR0A&(1<<RXC0)));
	return UDR0;
}

void UART_TxString(char text[]) {
	int i = 0;
	while (i<255) {
		if(text[i] == '\0') break; //if null character, breaks the loop
		UART_TxChar(text[i]);
		i++;
	}
}

