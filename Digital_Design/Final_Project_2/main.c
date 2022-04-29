// Ben Telfer and Prasanna Ranganathan
// EECE 287 - Spring 2022 - Binghamton University

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/io.h>
#include "lcd_driver.h"
#include "port_macros.h"
#define PWM_TOP 500

// Need LCD function?
void move_y(long distance_time_y, unsigned int duty_cycleL, unsigned int duty_cycleR);
void rotate_90_left(long rot_time_L, unsigned int duty_cycleL, unsigned int duty_cycleR);
void rotate_90_right(long rot_time_R, unsigned int duty_cycleL, unsigned int duty_cycleR);
void about_face(long aboutface_time, unsigned int duty_cycleL, unsigned int duty_cycleR);

int main()
{
	// Left and Right motor settings

	long rot_time_L = 12750;
	long rot_time_R = 13980;
	long aboutface_time = 21000;
	unsigned int duty_cycleL = 100;
	unsigned int duty_cycleR = 103;

	// Reflectance sensor variables set as an array

	int RS_status[] = {0, 0, 0, 0, 0};

	// Setting reflectance sensors as inputs

	DDRC &= ~(1 << 0);
	DDRC &= ~(1 << 1);
	DDRC &= ~(1 << 2);
	DDRC &= ~(1 << 3);
	DDRC &= ~(1 << 4);

	// Set reflectance sensor register values as '1' to turn on sensors

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
		// Loops through sensors 0 to 4 to check status

		for (int i = 0; i < 5; i++)
		{
			if ((PINC & (1 << i)) >= 1)
			{
				RS_status[i] = 1;
			}
			else
			{
				RS_status[i] = 0;
			}
		}
		char char_RS_status_0[8]; // Maybe try char char_RS_status_[i][8]?
		char char_RS_status_1[8];
		char char_RS_status_2[8];
		char char_RS_status_3[8];
		char char_RS_status_4[8];

		LCD_execute_command(CLEAR_DISPLAY);
		LCD_move_cursor_to_col_row(0, 0);
		sprintf(char_RS_status_0, "%d", RS_status[0]);
		LCD_print_String(char_RS_status_0);
		//_delay_ms(50);

		// LCD_execute_command(CLEAR_DISPLAY);
		LCD_move_cursor_to_col_row(1, 0);
		sprintf(char_RS_status_1, "%d", RS_status[1]);
		LCD_print_String(char_RS_status_1);
		//_delay_ms(50);

		LCD_move_cursor_to_col_row(2, 0);
		sprintf(char_RS_status_2, "%d", RS_status[2]);
		LCD_print_String(char_RS_status_2);
		//_delay_ms(50);

		LCD_move_cursor_to_col_row(3, 0);
		sprintf(char_RS_status_3, "%d", RS_status[3]);
		LCD_print_String(char_RS_status_3);
		//_delay_ms(50);

		LCD_move_cursor_to_col_row(4, 0);
		sprintf(char_RS_status_4, "%d", RS_status[4]);
		LCD_print_String(char_RS_status_4);
		_delay_ms(50);
	}
}
//=============MOVE_Y================
void move_y(long distance_time_y, unsigned int duty_cycleL, unsigned int duty_cycleR)
{
	long time = 0;
	unsigned int pwm_counter = 0;
	_delay_ms(1000);
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
		if (time == distance_time_y)
		{
			break;
		}
		time++;
		_delay_us(10);
	}
	PORTD |= (1 << 3) | (1 << 5) | (1 << 6); // BRAKE MOTORS
	PORTB |= (1 << 3);
}
//=============ROTATE_90_LEFT================
void rotate_90_left(long rot_time_L, unsigned int duty_cycleL, unsigned int duty_cycleR)
{
	long time = 0;
	unsigned int pwm_counter = 0;
	_delay_ms(1000);
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
	_delay_ms(1000);
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
//===============ABOUT_FACE===(to the left)=============
void about_face(long aboutface_time, unsigned int duty_cycleL, unsigned int duty_cycleR)
{
	long time = 0;
	unsigned int pwm_counter = 0;
	_delay_ms(1000);
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
		if (time == aboutface_time)
		{
			break;
		}
		_delay_us(10);
		time++;
	}
	PORTD |= (1 << 3) | (1 << 5) | (1 << 6); // BRAKE MOTORS
	PORTB |= (1 << 3);
}