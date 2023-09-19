// Ben Telfer and Prasanna Ranganathan
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/io.h>
#include "lcd_driver.h"
#include "port_macros.h"
#define PWM_TOP 500

void lcd_display(int8_t x, int8_t y, int stage);
void move_y(long velocity_coefficient_y, long absycoord, unsigned int duty_cycleL, unsigned int duty_cycleR);
void move_x(long velocity_coefficient_x, long absxcoord, unsigned int duty_cycleL, unsigned int duty_cycleR);
void rotate_90_left(long rot_time_L, unsigned int duty_cycleL, unsigned int duty_cycleR);
void rotate_90_right(long rot_time_R, unsigned int duty_cycleL, unsigned int duty_cycleR);
void about_face(long aboutface_time, unsigned int duty_cycleL, unsigned int duty_cycleR);

int main()
{
	long velocity_coefficient_x = 0;
	long velocity_coefficient_y = 0;
	long xcoord = 0;
	long ycoord = 0;
	long absxcoord = 0;
	long absycoord = 0;
	long velocity[] = {0, 300000, 205000, 174000, 155000, 140000, // 0 - 5
					   132500, 127000, 120000, 117000, 114000,	  // 6- 10
					   113000, 112000, 112000, 110000, 107500,	  // 11 - 15
					   104500, 103500, 102500, 100750, 100500,	  // 16 - 20
					   99500, 98750, 98000, 97500, 97250,		  // 21 - 25
					   95000, 93500, 93250, 93000, 92650};		  // 26 - 30
	long rot_time_L = 12750;
	long rot_time_R = 13980; // 14065
	long aboutface_time = 21000;
	unsigned int duty_cycleL = 100; // Duty cycle for left motor
	unsigned int duty_cycleR = 103; // Duty cycle for right motor
	unsigned int last_left_button_state = (PINB & (1 << 1));
	unsigned int left_button_pressed = 0;
	unsigned int last_middle_button_state = (PINB & (1 << 4));
	unsigned int middle_button_pressed = 0;
	unsigned int last_right_button_state = (PINB & (1 << 5));
	unsigned int right_button_pressed = 0;
	unsigned int stage = 1;		 // 1 is choose x, 2 is choose y, 3 is move
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
		//===========================SELECTING COORDS=============================
		if (middle_button_pressed == 1)
		{
			stage++;
		}
		if (stage == 1)
		{
			if (left_button_pressed == 1)
			{
				xcoord--;
			}
			else if (right_button_pressed == 1)
			{
				xcoord++;
			}
		}
		else if (stage == 2)
		{
			if (left_button_pressed == 1)
			{
				ycoord--;
			}
			else if (right_button_pressed == 1)
			{
				ycoord++;
			}
		}
		if (stage != 0)
		{
			lcd_display(xcoord, ycoord, stage);
		}
		//=================SELECTING APPROPRIATE VELOCITY RATIO===================
		absxcoord = abs(xcoord);
		absycoord = abs(ycoord);
		for (int i = 0; i < 31; i++)
		{
			if (absxcoord == i)
			{
				velocity_coefficient_x = velocity[i];
			}
			if (absycoord == i)
			{
				velocity_coefficient_y = velocity[i];
			}
		}
		//===============================MOVEMENT=================================
		//================================STAGE 3=================================
		if (stage == 3)
		{
			if (ycoord >= 0)
			{ // MOVE Y
				move_y(velocity_coefficient_y, absycoord, duty_cycleL, duty_cycleR);
			}
			else if (ycoord < 0)
			{ // ABOUT FACE
				about_face(aboutface_time, duty_cycleL, duty_cycleR);
				// MOVE Y
				move_y(velocity_coefficient_y, absycoord, duty_cycleL, duty_cycleR);
			}
		}
		//================================STAGE 4=================================
		if (stage == 4)
		{
			if (ycoord >= 0)
			{
				if (xcoord >= 0)
				{ // 90 RIGHT
					rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);
					stage++;
				}
				else if (xcoord < 0)
				{ // 90 LEFT
					rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);
					stage++;
				}
			}
			else if (ycoord < 0)
			{
				if (xcoord >= 0)
				{ // 90 LEFT
					rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);
					stage++;
				}
				else if (xcoord < 0)
				{ // 90 RIGHT
					rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);
					stage++;
				}
			}
		}
		//=================================STAGE 5================================
		if (stage == 5)
		{ // MOVE X
			move_x(velocity_coefficient_x, absxcoord, duty_cycleL, duty_cycleR);
			stage++;
		}
		//=========================PULSERS========================================
		// LEFT BUTTON
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
		// MIDDLE BUTTON
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
		// RIGHT BUTTON
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
		//===========================DELAY========================================
		_delay_us(10);
	}
	return 0;
}

//============================================================FUNCTIONS===============================================================================
void lcd_display(int8_t x, int8_t y, int stage)
{
	char char_x[8];
	char char_y[8];
	char char_s[8];
	LCD_execute_command(CLEAR_DISPLAY);
	LCD_move_cursor_to_col_row(0, 0);
	sprintf(char_x, "X:%2d", x);
	LCD_print_String(char_x); // Prints X Coord
	LCD_move_cursor_to_col_row(0, 1);
	sprintf(char_y, "Y:%2d", y);
	LCD_print_String(char_y); // Prints Y coord
	LCD_move_cursor_to_col_row(6, 1);
	sprintf(char_s, "%2d", stage);
	LCD_print_String(char_s); // Prints Y coord
	_delay_ms(50);
}
//=============MOVE_Y================
void move_y(long velocity_coefficient_y, long absycoord, unsigned int duty_cycleL, unsigned int duty_cycleR)
{
	long time = 0;
	unsigned int pwm_counter = 0;
	_delay_ms(1000);
	while (1)
	{
		pwm_counter++; // PWM pwm_counter
		if (pwm_counter >= PWM_TOP)
		{
			pwm_counter = 0;
		}
		if (pwm_counter < duty_cycleL)
		{
			PORTD &= ~(1 << 5); // LEFT
			PORTD |= (1 << 6);
		} // LEFT //FORWARD
		else
		{
			PORTD &= ~((1 << 5) | (1 << 6));
		} // COAST MOTORS
		if (pwm_counter < duty_cycleR)
		{
			PORTD &= ~(1 << 3); // RIGHT
			PORTB |= (1 << 3);
		} // RIGHT //REVERSE => Turn right
		else
		{
			PORTD &= ~((1 << 3)); // COAST MOTORS
			PORTB &= ~(1 << 3);
		}
		if (time == (velocity_coefficient_y / 30) * absycoord)
		{
			break;
		}
		time++;
		_delay_us(10);
	}
	PORTD |= (1 << 5) | (1 << 6); // BRAKE MOTORS
	_delay_us(50);				  // Delay before braking right motor sicne it brakes before left
	PORTD |= (1 << 3);
	PORTB |= (1 << 3);
}
//=============MOVE_X================
void move_x(long velocity_coefficient_x, long absxcoord, unsigned int duty_cycleL, unsigned int duty_cycleR)
{
	long time = 0;
	unsigned int pwm_counter = 0;
	_delay_ms(1000);
	while (1)
	{
		pwm_counter++; // PWM pwm_counter
		if (pwm_counter >= PWM_TOP)
		{
			pwm_counter = 0;
		}
		if (pwm_counter < duty_cycleL)
		{
			PORTD &= ~(1 << 5); // LEFT
			PORTD |= (1 << 6);
		} // LEFT //FORWARD
		else
		{
			PORTD &= ~((1 << 5) | (1 << 6));
		} // COAST MOTORS
		if (pwm_counter < duty_cycleR)
		{
			PORTD &= ~(1 << 3); // RIGHT
			PORTB |= (1 << 3);
		} // RIGHT //REVERSE => Turn right
		else
		{
			PORTD &= ~((1 << 3)); // COAST MOTORS
			PORTB &= ~(1 << 3);
		}
		if (time == (velocity_coefficient_x / 30) * absxcoord)
		{
			break;
		}
		time++;
		_delay_us(10);
	}
	PORTD |= (1 << 5) | (1 << 6); // BRAKE MOTORS
	_delay_us(50);				  // Delay before braking right motor sicne it brakes before left
	PORTD |= (1 << 3);
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
		pwm_counter++; // PWM pwm_counter
		if (pwm_counter >= PWM_TOP)
		{
			pwm_counter = 0;
		}
		if (pwm_counter < duty_cycleL)
		{
			PORTD |= (1 << 5); // LEFT
			PORTD &= ~(1 << 6);
		} // LEFT //FORWARD
		else
		{
			PORTD &= ~((1 << 5) | (1 << 6));
		} // COAST MOTORS
		if (pwm_counter < duty_cycleR)
		{
			PORTD &= ~(1 << 3); // RIGHT
			PORTB |= (1 << 3);
		} // RIGHT //REVERSE => Turn right
		else
		{
			PORTD &= ~((1 << 3)); // COAST MOTORS
			PORTB &= ~(1 << 3);
		}
		if (time == rot_time_L) // this value is second*100000 //eg 5 sec = 500000
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
		pwm_counter++; // PWM pwm_counter
		if (pwm_counter >= PWM_TOP)
		{
			pwm_counter = 0;
		}
		if (pwm_counter < duty_cycleL)
		{
			PORTD &= ~(1 << 5); // LEFT
			PORTD |= (1 << 6);
		} // LEFT //FORWARD
		else
		{
			PORTD &= ~((1 << 5) | (1 << 6));
		} // COAST MOTORS
		if (pwm_counter < duty_cycleR)
		{
			PORTD |= (1 << 3); // RIGHT
			PORTB &= ~(1 << 3);
		} // RIGHT //REVERSE => Turn right
		else
		{
			PORTD &= ~((1 << 3)); // COAST MOTORS
			PORTB &= ~(1 << 3);
		}
		if (time == rot_time_R) // this value is second*100000 //eg 5 sec = 500000
		{
			break;
		}
		time++;
		_delay_us(10);
	}
	PORTD |= (1 << 3) | (1 << 5) | (1 << 6); // BRAKE MOTORS
	PORTB |= (1 << 3);
}
//===============ABOUT_FACE===============
void about_face(long aboutface_time, unsigned int duty_cycleL, unsigned int duty_cycleR)
{
	long time = 0;
	unsigned int pwm_counter = 0;
	_delay_ms(1000);
	while (1)
	{
		pwm_counter++; // PWM pwm_counter
		if (pwm_counter >= PWM_TOP)
		{
			pwm_counter = 0;
		}
		if (pwm_counter < duty_cycleL)
		{
			PORTD |= (1 << 5); // LEFT
			PORTD &= ~(1 << 6);
		} // LEFT //FORWARD
		else
		{
			PORTD &= ~((1 << 5) | (1 << 6));
		} // COAST MOTORS
		if (pwm_counter < duty_cycleR)
		{
			PORTD &= ~(1 << 3); // RIGHT
			PORTB |= (1 << 3);
		} // RIGHT //REVERSE => Turn right
		else
		{
			PORTD &= ~((1 << 3)); // COAST MOTORS
			PORTB &= ~(1 << 3);
		}
		if (time == aboutface_time) // this value is second*100000 //eg 5 sec = 500000
		{
			break;
		}
		_delay_us(10);
		time++;
	}
	PORTD |= (1 << 3) | (1 << 5) | (1 << 6); // BRAKE MOTORS
	PORTB |= (1 << 3);
}
