#define F_CPU 20000000
#include <stdint.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/io.h>
#include "lcd_driver.h"
#include "port_macros.h"

#define PWM_TOP 100
#define INCREMENT 1

int main()
{
	unsigned int last_left_button_state = (PINB & (1 << 1));
	unsigned int left_button_pressed;
	unsigned int last_right_button_state = (PINB & (1 << 5));
	unsigned int right_button_pressed;
	unsigned int last_middle_button_state = (PINB & (1 << 4));
	unsigned int middle_button_pressed;
	unsigned int count = 0;

	/* Write you code here*/

	// Copy over Lab_7 button turns on LEDs over here and use it to tie buttons
	// to moving forward/left/right/reverse (left is left button, right is right button,
	// forward is both buttons, and reverse is middle button)

	// Start by setting the ports to an input or output
	// Set the specified bits of the port to be on or off based on what you want to do

	DDRD |= (1 << 3) | (1 << 5) | (1 << 6);	   // set D3, D5, D6 as outputs
	DDRB |= (1 << 3);						   // set B3 as output
	DDRB &= ~((1 << 1) | (1 << 4) | (1 << 5)); // set B1, B4, B5 as inputs

	PORTD &= ~((1 << 5) | (1 << 3));
	PORTB |= (1 << 1);
	PORTB |= (1 << 5);

	// 1) initialize LCD driver
	initialize_LCD_driver();

	// 2) turn on LCD after startup
	LCD_execute_command(TURN_ON_DISPLAY);

	while (1)
	{
		// 3) clear lcd buffer for refresh new data
		LCD_execute_command(CLEAR_DISPLAY);

		// 4) display on botton line
		LCD_move_cursor_to_col_row(0, 0);

		// 5) print char on lcd
		LCD_print_hex16(count);

		// Pulser for left button
		if ((PINB & (1 << 1)) != last_left_button_state)
		{
			if ((PINB & (1 << 1)) == 0)
			{
				left_button_pressed = 1;
			}
			last_left_button_state = (PINB & (1 << 1));
		}
		else
		{
			left_button_pressed = 0;
		}

		// Pulser for right button
		if ((PINB & (1 << 5)) != last_right_button_state)
		{
			if ((PINB & (1 << 5)) == 0)
			{
				right_button_pressed = 1;
			}
			last_right_button_state = (PINB & (1 << 5));
		}
		else
		{
			right_button_pressed = 0;
		}

		// Pulser for middle button
		if ((PINB & (1 << 4)) != last_middle_button_state)
		{
			if ((PINB & (1 << 4)) == 0)
			{
				middle_button_pressed = 1;
			}
			last_middle_button_state = (PINB & (1 << 4));
		}
		else
		{
			middle_button_pressed = 0;
		}

		// Since you need to read the value of the button at any moment it must be done within a loop
		if (left_button_pressed == 1)
		{
			PORTD ^= (1 << 6); // Turn LEFT/Right motor fowards

			if (count != 0)
			{
				count--;
				LCD_print_hex16(count);
			}

			else
			{
				count = 0;
				LCD_print_hex16(count);
			}
		}

		if (middle_button_pressed == 1)
		{
			PORTD ^= (1 << 6); // Both motors REVERSE
			PORTB ^= (1 << 3);
		}

		if (right_button_pressed == 1)
		{
			PORTB ^= (1 << 3); // Turn RIGHT
			count++;
			LCD_print_hex16(count);
		}
		_delay_ms(50);
	}
	return 0;
}