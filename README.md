# AVR-ATmega328p-EIE3105-
Lab exercises from 1 to 4 from EIE3105


**Lab 1**

Section A:
Create your first simple application
Port D is toggled between 0x55 and 0xAA with 1 to 2 seconds time delay. You should use looping to generate the delay and set the optimization level to the first one (level zero). Show the calculation how to generate the delay. Note that the clock frequency of the Arduino Start Kit is 16 MHz. When your program works properly, you should see all LEDs connected to Port D are flashing.


Section B: 
Simple applications
1. Connect a switch to PB0 and the pin diagram is shown in Step 6 of Section A. Connect a LED to the switch. When the switch is pressed, the LED is on. When the switch is released, the LED is off. 
2. Use the circuit in Section A and the connection in Step 6. There are two states in the switch: State 0 and 1. When it is in State 0, all LEDs connected to Port D are off. When it is in State 1, all LEDs are on. At the beginning, the switch is in State 0. When the switch is pressed and it is in State 0, it goes to State 1. When the switch is pressed and it is in State 1, it goes to State 0.



**Lab 2**
Section A: Write a C Program to toggle a LED by using a timer
1. Write a C program to toggle a LED connected to PB0 (you should connect the LED to PB0 with a resistor) in every second. You should use the timer with Normal mode to 
generate the time delay of one second. Note that the clock frequency of the Arduino Start Kit is 16 MHz.
2. Repeat Step 1 but this time the timer is in CTC mode.


Section B: Write a C Program to simulate the traffic lights
1. Write a C program to simulate the traffic lights by using different pins. You should use a 
timer in Normal mode. Note that the clock frequency of the Arduino Start Kit is 16 MHz.
A set of traffic lights for cars (Light 3): PB0, PB1, PB2 (3 LEDs)
A set of traffic lights for cars (Light 2): PB3, PB4, PB5 (3 LEDs)
A set of traffic lights for people (Light 1): PC4, PC5 (2 LEDs)

Repeat the following:
Light 1 (RED), Light 2 (GREEN), Light 3 (RED), period (around 5s)
Light 1 (RED), Light 2 (YELLOW), Light 3 (RED), period (around 1s)
Light 1 (RED), Light 2 (RED), Light 3 (RED), period (around 1s)
Light 1 (RED), Light 2 (RED), Light 3 (RED+YELLOW), period (around 1s)
Light 1 (GREEN), Light 2 (RED), Light 3 (GREEN), period (around 5s)
Light 1 (GREEN Blinking), Light 2 (RED), Light 3 (YELLOW), period (around 1s)
Light 1 (RED), Light 2 (RED), Light 3 (RED), period (around 1s)
Light 1 (RED), Light 2 RED+YELLOW), Light 3 (RED), period (around 1s)
2. Repeat Step 1 but this time the timer is in CTC mode.


Section C: Write a C program to count a switch
Connect a switch to pin T0 (PD4, Counter 0) or T1 (PD5, Counter 1) and a LED to PC0. There are two states in the switch: State 0 and 1. When it is in State 0, the LED is off. When it is in State 1, the LED is on. At the beginning, the switch is in State 0. When the switch is pressed three times and it is in State 0, it goes to State 1. When the switch is pressed three times and it is in State 1, it goes to State 0. You should use counter programming in CTC mode to implement this application.



**Lab 4**

Section A: Write a C program to echo a character
Write a C program to complete the following task: Receive a character from the serial port by using the polling method and then send it to a PC terminal through the serial port. The baud rate should be 4800


Section B: Write a C program to send and receive strings
Write a C program to complete the following tasks:
1. (Do it once at the beginning) Send “We Are Ready” to the serial port by using the polling method. Note that the clock frequency of the Arduino Start Kit is 16 MHz.
2. (Do it repeatedly) Receive data from the serial port by using the polling method. If the received string is “Hi”, your program should send “Bye” to the serial port. (Hint: To get a string from the serial port, your program should receive it character by character. For example, if your program receives a string “abc”, the characters received from the serial port should be “a” first, and then “b”, and finally “c”. ) The string “Hi” can be sent to the Arduino by typing it (i.e., using the keyboard). When you type “Hi”, Tera Term gets the input and sends it to the Arduino through the serial port. When the Arduino gets the string, it will send a message “Bye!” to the serial port and you can read it through Tera Term.


Section C: Write a C program to keep sending and receiving characters
Write a C program to complete the following tasks using the polling method:
1. Before you press any keys, character ‘a’ is printed continuously.
2. When you press a key (say ‘b’), 10 characters of this key (i.e., ‘b’) are printed out and then stop.
3. After that when you press a key other than the first key (i.e., ‘b’), nothing happens.
4. When you press the key again (i.e., ‘b’), character ‘a’ is printed continuously (i.e., resume).
Set the baud rate of the PC terminal (i.e., Tera Term) to 9600.

