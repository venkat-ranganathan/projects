#define F_CPU 20000000
#include <stdint.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/io.h>
#include "lcd_driver.h"
#include "port_macros.h"

#define PWM_TOP 100
#define INCREMENT 1

/* Your ability to use the LCD screen;
use a single button to count up and display the count value in decimal */

int main()
{
	unsigned int last_left_button_state = (PINB & (1 << 1));
	unsigned int left_button_pressed;
	unsigned int last_right_button_state = (PINB & (1 << 5));
	unsigned int right_button_pressed;
	unsigned int count = 0;

	// Configure left push-button
	DDRB &= ~(1 << 1); // configure pin as input
	PORTB |= (1 << 1); // enable pull-up resistor

	// Configure right push-button
	DDRB &= ~(1 << 5);
	PORTB |= (1 << 5);

	// 1) initialize LCD driver
	initialize_LCD_driver();

	// 2) turn on LCD after startup
	LCD_execute_command(TURN_ON_DISPLAY);

	// this is your primary main loop
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

		if (left_button_pressed == 1)
		{
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

		if (right_button_pressed == 1)
		{
			count++;
			LCD_print_hex16(count);
		}

		_delay_ms(50);
	}

	return 0;
}
