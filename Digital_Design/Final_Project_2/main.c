// Prasanna Ranganathan and Ben Telfer
// EECE 287 - Spring 2022 - Binghamton University

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/io.h>
#include "lcd_driver.h"
#include "port_macros.h"
#define PWM_TOP 500

void display(int RS_status[]);
void navigate(int RS_status[]);
void move(long distance_time, unsigned int duty_cycleL, unsigned int duty_cycleR);
void rotate_90_left(long rot_time_L, unsigned int duty_cycleL, unsigned int duty_cycleR);
void rotate_90_right(long rot_time_R, unsigned int duty_cycleL, unsigned int duty_cycleR);

int main()
{
	// Left and Right motor settings

	long rot_time_L = 0;
	long rot_time_R = 0;

	unsigned int duty_cycleL = 0;
	unsigned int duty_cycleR = 0;

	long ycoord = 0;
	long absycoord = 0;
	long distance_time = 0;

	// Setting reflectance sensors as inputs

	DDRC &= ~(1 << 0);
	DDRC &= ~(1 << 1);
	DDRC &= ~(1 << 2);
	DDRC &= ~(1 << 3);
	DDRC &= ~(1 << 4);

	// Set reflectance sensor register values as '1' to turn on sensors by setting it to 5V

	PORTC |= (1 << 0);
	PORTC |= (1 << 1);
	PORTC |= (1 << 2);
	PORTC |= (1 << 3);
	PORTC |= (1 << 4);

	// Left and Right motors set as outputs and pull-up resistors enabled

	DDRD |= (1 << 5) | (1 << 6); // Left Motor
	DDRD |= (1 << 3);			 // Right Motor
	DDRB |= (1 << 3);			 // Right Motor
	DDRB &= ~(1 << 1);			 // Configure left push-button input
	PORTB |= (1 << 1);			 // enable pull-up resistor
	DDRB &= ~(1 << 4);			 // Configure middle push-button input
	PORTB |= (1 << 4);			 // enable pull-up resistor
	DDRB &= ~(1 << 5);			 // Configure right push-button input
	PORTB |= (1 << 5);			 // enable pull-up resistor

	initialize_LCD_driver();
	LCD_execute_command(TURN_ON_DISPLAY);

	while (1)
	{
		// Reflectance sensor variables set as an array

		int RS_status[] = {0, 0, 0, 0, 0};

		// Loops through sensors 0 to 4 to check status

		for (int i = 0; i < 5; i++)
		{
			// PIN# provides read-only data state from the corresponding PORT#
			// Conditional checks if read-only PIN register is high, and sets RS_status to 1, else 0

			if ((PINC & (1 << i)) >= 1)
			{
				RS_status[i] = 1;
			}
			else
			{
				RS_status[i] = 0;
			}
		}

		// Calls navigation function

		navigate(RS_status);

		// Calls display function

		display(RS_status);
	}
}

// Display function shows status of reflectance sensors on LCD display

void display(int RS_status[])
{

	// Create RS_status character variables to output to LCD

	char char_RS_status_0[8];
	char char_RS_status_1[8];
	char char_RS_status_2[8];
	char char_RS_status_3[8];
	char char_RS_status_4[8];

	// Clear display once at start

	LCD_execute_command(CLEAR_DISPLAY);

	// Print out reflectance sensor states to LCD

	LCD_move_cursor_to_col_row(0, 0);
	sprintf(char_RS_status_0, "%d", RS_status[0]);
	LCD_print_String(char_RS_status_0);

	LCD_move_cursor_to_col_row(1, 0);
	sprintf(char_RS_status_1, "%d", RS_status[1]);
	LCD_print_String(char_RS_status_1);

	LCD_move_cursor_to_col_row(2, 0);
	sprintf(char_RS_status_2, "%d", RS_status[2]);
	LCD_print_String(char_RS_status_2);

	LCD_move_cursor_to_col_row(3, 0);
	sprintf(char_RS_status_3, "%d", RS_status[3]);
	LCD_print_String(char_RS_status_3);

	LCD_move_cursor_to_col_row(4, 0);
	sprintf(char_RS_status_4, "%d", RS_status[4]);
	LCD_print_String(char_RS_status_4);

	// Add small delay at end so LCD doesn't refresh too fast

	_delay_ms(50);
}

// Navigation function

void navigate(int RS_status[])
{
	long rot_time_L = 1300;
	long rot_time_R = 1300;

	unsigned int duty_cycleL = 48;
	unsigned int duty_cycleR = 45;

	long distance_time = 3000;

	// Conditional to navigate forward

	if ((RS_status[1] & RS_status[3]) >= 1)
	{
		// Speeds up left motor and right motor

		duty_cycleL++;
		duty_cycleR++;

		// continues moving

		move(distance_time, duty_cycleL, duty_cycleR);
	}

	// Condtional to correct left oversteer

	if (((RS_status[2] | RS_status[3]) >= 1) & ((RS_status[1]) <= 0))
	{
		// Speeds up left motor and slows down right motor

		duty_cycleL++;
		duty_cycleR--;

		// Makes small right rotations to straighten movement

		rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);

		// continues moving

		move(distance_time, duty_cycleL, duty_cycleR);
	}

	// Condtional to correct right oversteer

	if (((RS_status[1] | RS_status[2]) >= 1) & ((RS_status[3]) <= 0))
	{
		// Speeds up right motor and slows down left motor

		duty_cycleL--;
		duty_cycleR++;

		// Makes small left rotations to straighten movement

		rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);

		// continues moving

		move(distance_time, duty_cycleL, duty_cycleR);
	}

	// Conditional to handle right corner

	if ((RS_status[4] >= 1) & (RS_status[0] & RS_status[1] & RS_status[2] & RS_status[3]) <= 0)
	{
		duty_cycleL++;
		duty_cycleR--;

		long rot_time_R = 5000;

		rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);
		rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);
		rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);
	}

	// Conditional to handle left corner

	if ((RS_status[0] >= 1) & (RS_status[1] & RS_status[2] & RS_status[3] & RS_status[4]) <= 0)
	{
		duty_cycleL--;
		duty_cycleR++;
		duty_cycleL--;
		duty_cycleR++;
		duty_cycleL--;
		duty_cycleR++;
		duty_cycleL--;
		duty_cycleR++;

		long rot_time_L = 5000;

		rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);
		rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);
		rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);
	}

	// Conditional to handle 3-way intersection right

	/* 	if ((RS_status[0] <= 0) & ((RS_status[1] & RS_status[2] & RS_status[3] & RS_status[4]) >= 1))
		{
		} */

	// Conditional to handle 3-way intersection left

	/* 	if ((RS_status[4] <= 0) & ((RS_status[0] & RS_status[1] & RS_status[2] & RS_status[3]) >= 1))
		{
		}
	 */
	// Conditional to handle 4-way intersection

	/* 	if ((RS_status[0] & RS_status[1] & RS_status[2] & RS_status[3] & RS_status[4]) >= 1)
		{
		} */
}
//=============move================
void move(long distance_time, unsigned int duty_cycleL, unsigned int duty_cycleR)
{
	long time = 0;
	unsigned int pwm_counter = 0;
	while (1)
	{
		pwm_counter++;
		if (pwm_counter >= PWM_TOP)
		{
			pwm_counter = 0;
		}
		if (pwm_counter < duty_cycleL)
		{
			PORTD &= ~(1 << 5);
			PORTD |= (1 << 6);
		} // LEFT FORWARD
		else
		{
			PORTD &= ~((1 << 5) | (1 << 6));
		} // COAST MOTORS
		if (pwm_counter < duty_cycleR)
		{
			PORTD &= ~(1 << 3);
			PORTB |= (1 << 3);
		} // RIGHT FORWARD
		else
		{
			PORTD &= ~((1 << 3)); // COAST MOTORS
			PORTB &= ~(1 << 3);
		}
		if (time == distance_time)
		{
			break;
		}
		time++;
		_delay_us(10);
	}
	PORTD |= (1 << 3) | (1 << 5) | (1 << 6); // BRAKE MOTORS
	PORTB |= (1 << 3);

	// Coast left and right motors

	// PORTD &= ~((1 << 5) | (1 << 6));
	// PORTD &= ~((1 << 3));
	// PORTB &= ~(1 << 3);
}
//=============ROTATE_90_LEFT================
void rotate_90_left(long rot_time_L, unsigned int duty_cycleL, unsigned int duty_cycleR)
{
	long time = 0;
	unsigned int pwm_counter = 0;
	//_delay_ms(1000);
	while (1)
	{
		pwm_counter++;
		if (pwm_counter >= PWM_TOP)
		{
			pwm_counter = 0;
		}
		if (pwm_counter < duty_cycleL)
		{
			PORTD |= (1 << 5);
			PORTD &= ~(1 << 6);
		} // LEFT REVERSE
		else
		{
			PORTD &= ~((1 << 5) | (1 << 6));
		} // COAST MOTORS
		if (pwm_counter < duty_cycleR)
		{
			PORTD &= ~(1 << 3);
			PORTB |= (1 << 3);
		} // RIGHT FORWARD
		else
		{
			PORTD &= ~((1 << 3)); // COAST MOTORS
			PORTB &= ~(1 << 3);
		}
		if (time == rot_time_L)
		{
			break;
		}
		time++;
		_delay_us(10);
	}
	PORTD |= (1 << 3) | (1 << 5) | (1 << 6); // BRAKE MOTORS
	PORTB |= (1 << 3);
}
//=============ROTATE_90_RIGHT================
void rotate_90_right(long rot_time_R, unsigned int duty_cycleL, unsigned int duty_cycleR)
{
	long time = 0;
	unsigned int pwm_counter = 0;
	//_delay_ms(1000);
	while (1)
	{
		pwm_counter++;
		if (pwm_counter >= PWM_TOP)
		{
			pwm_counter = 0;
		}
		if (pwm_counter < duty_cycleL)
		{
			PORTD &= ~(1 << 5);
			PORTD |= (1 << 6);
		} // LEFT FORWARD
		else
		{
			PORTD &= ~((1 << 5) | (1 << 6));
		} // COAST MOTORS
		if (pwm_counter < duty_cycleR)
		{
			PORTD |= (1 << 3);
			PORTB &= ~(1 << 3);
		} // RIGHT REVERSE
		else
		{
			PORTD &= ~((1 << 3)); // COAST MOTORS
			PORTB &= ~(1 << 3);
		}
		if (time == rot_time_R)
		{
			break;
		}
		time++;
		_delay_us(10);
	}
	PORTD |= (1 << 3) | (1 << 5) | (1 << 6); // BRAKE MOTORS
	PORTB |= (1 << 3);
}
