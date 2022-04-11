#include <stdint.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/io.h>
#include "lcd_driver.h"
#include "port_macros.h"

int main()
{

	/* Write you code here*/

	// Copy over Lab_7 button turns on LEDs over here and use it to tie buttons
	// to moving forward/left/right/reverse (left is left button, right is right button,
	// forward is both buttons, and reverse is middle button)

	// Start by setting the ports to an input or output
	// Set the specified bits of the port to be on or off based on what you want to do

	DDRD |= (0 << 3) | (0 << 5) | (0 << 6);	   // set D3, D5, D6 as outputs
	DDRB |= (0 << 3);						   // set B3 as output
	DDRB &= ~((1 << 1) | (1 << 4) | (1 << 5)); // set B1, B4, B5 as inputs

	while (1)
	{

		// Since you need to read the value of the button at any moment it must be done within a loop
		if ((PINB & (1 << 1)) == 0)
		{
			PORTD ^= (1 << 6) | (0 << 5) | (0 << 3); // Turn LEFT
			PORTB ^= (0 << 3);
		}

		if ((PINB & (1 << 4)) == 0)
		{
			PORTD ^= (0 << 3) | (0 << 5) | (1 << 6); // Both motors REVERSE
			PORTB ^= (1 << 3);
		}

		if ((PINB & (1 << 1) & (1 << 5)) == 0)
		{
			PORTD ^= (0 << 6) | (1 << 5); // MOTOR1 FORWARD
			PORTD ^= (1 << 3);
			PORTB ^= (0 << 3); // MOTOR2  FORWARD
		}

		if ((PINB & (1 << 5)) == 0)
		{
			PORTD ^= (0 << 3) | (0 << 5) | (0 << 6);
			PORTB ^= (1 << 3); // Turn RIGHT
		}

		// All MOTORS BRAKE
		else
		{
			PORTD ^= (1 << 6) | (1 << 5);
			PORTD ^= (1 << 3);
			PORTB ^= (1 << 3);
		}
	}
	return 0;
}