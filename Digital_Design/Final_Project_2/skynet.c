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

void display(int RS_status[], int mine_count);
void navigate(int RS_status[]);
void move(long distance_time, unsigned int duty_cycleL, unsigned int duty_cycleR);
void rotate_90_left(long rot_time_L, unsigned int duty_cycleL, unsigned int duty_cycleR);
void rotate_90_right(long rot_time_R, unsigned int duty_cycleL, unsigned int duty_cycleR);
// void random_number_generator(int n);

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

	// mine count

	int mine_count = 0;

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

			// Conditional is >= 1 because it's using the port values in powers of 2

			if ((PINC & (1 << i)) >= 1)
			{
				RS_status[i] = 1;
			}
			else
			{
				RS_status[i] = 0;
			}
		}

		// -101- MINE DETECTION

		/* 		if ((RS_status[1] >= 1) & (RS_status[2] == 0) & (RS_status[3] >= 1))
				{
					// Increments mine count

					mine_count++;

					// Calls display function

					display(RS_status, mine_count);
				} */

		// Calls navigation function

		navigate(RS_status);

		// Calls display function

		display(RS_status, mine_count);
	}
}

// Display function shows status of reflectance sensors on LCD display

void display(int RS_status[], int mine_count)
{

	// Create RS_status character variables to output to LCD

	char char_RS_status_0[8];
	char char_RS_status_1[8];
	char char_RS_status_2[8];
	char char_RS_status_3[8];
	char char_RS_status_4[8];
	char char_mine_count[8];

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

	/* 	LCD_move_cursor_to_col_row(0, 1);
		sprintf(char_mine_count, "%d", mine_count);
		LCD_print_String(char_mine_count); */
}

// Truth table

/* #	RS_0	RS_1	RS_2	RS_3	RS_4	ACTION
0	0	0	0	0	0	Randomly turn left/right x
1	0	0	0	0	1	RIGHT x
2	0	0	0	1	0	Correct left oversteer, shift right x
3	0	0	0	1	1	Shift left x
4	0	0	1	0	0	Randomly shift left/right (implement?) x
5	0	0	1	0	1	Shift right? X
6	0	0	1	1	0	Shift right x
7	0	0	1	1	1	shift right x ALSO 3-way intersection right
8	0	1	0	0	0	Shift right x
9	0	1	0	0	1	4-way stuck on right corner SHIFT LEFT
10	0	1	0	1	0	Mine detection plus forward
11	0	1	0	1	1	Shift right x
12	0	1	1	0	0	Shift right x
13	0	1	1	0	1	Shift right x
14	0	1	1	1	0	Shift right x
15	0	1	1	1	1	3-way right (keeps making left turn)
16	1	0	0	0	0	LEFT x
17	1	0	0	0	1	Mine detection plus Continue right turn x
18	1	0	0	1	0	Stuck on left corner - rotate right x
19	1	0	0	1	1	Stuck on left corner - rotate right x
20	1	0	1	0	0	Shift right x
21	1	0	1	0	1	shift right x
22	1	0	1	1	0	Shift right x
23	1	0	1	1	1	4-way stuck on right corner SHIFT LEFT
24	1	1	0	0	0	Stuck on right corner - rotate left x
25	1	1	0	0	1	Stuck on right corner - rotate left x
26	1	1	0	1	0	Stuck on right corner - rotate left x
27	1	1	0	1	1	4-way stuck on right corner SHIFT LEFT
28	1	1	1	0	0	shift left x ALSO 3-way intersection left
29	1	1	1	0	1	4-way/Stuck on right corner - rotate left
30	1	1	1	1	0	3-way left
31	1	1	1	1	1	4-way RANDOM LEFT/RIGHT/FORWARD		 */

// Navigation function

void navigate(int RS_status[])
{
	// Left and right motor rotation times

	long rot_time_L = 1500;
	long rot_time_R = 1500;

	// Left and right motor power values

	unsigned int duty_cycleL = 38;
	unsigned int duty_cycleR = 45;

	// How long to run the motors during each instance navigate() function is called

	long distance_time = 3000;

	// Pseduorandom number generator

	int n;

	int r = rand() % n;

	// Mine count

	int mine_count = 0;

	// 00000 Randomly rotate out of  situation, does about face consistently

	if ((RS_status[0] == 0) & (RS_status[1] == 0) & (RS_status[2] == 0) & (RS_status[3] == 0) & (RS_status[4] == 0))
	{
		// Generates "random" 0 or 1

		n = 2;

		int r = rand() % n;

		// Determines which direction to turn based on random number

		if (r = 0)
		{
			// Sets larger rotation time to allow full 90 degree left turn

			long rot_time_L = 5000;
			long rot_time_R = 5000;

			// Makes left turn

			rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);
		}

		if (r = 1)
		{
			// Sets larger rotation time to allow full 90 degree right turn

			long rot_time_L = 5000;
			long rot_time_R = 5000;

			// Makes right turn

			rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);
		}
	}

	// 00001 Conditional to handle right corner

	if ((RS_status[0] == 0) & (RS_status[1] == 0) & (RS_status[2] == 0) & (RS_status[3] == 0) & (RS_status[4] >= 1))
	{
		// Sets larger rotation time to allow full 90 degree right turn

		long rot_time_L = 5000;
		long rot_time_R = 5000;

		// Makes right turn

		rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);
	}

	// 00010 Correct left oversteer for

	if ((RS_status[0] == 0) & (RS_status[1] == 0) & (RS_status[2] == 0) & (RS_status[3] >= 1) & (RS_status[4] == 0))
	{
		// Speeds up left motor and slows down right motor

		/* 		duty_cycleL++;
				duty_cycleR--; */

		// Makes small right rotations to straighten movement

		rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);

		// continues moving

		move(distance_time, duty_cycleL, duty_cycleR);
	}

	// 00011 Stuck on right edge, shift left OR Stuck on left edge, shift right

	if ((RS_status[0] == 0) & (RS_status[1] == 0) & (RS_status[2] == 0) & (RS_status[3] >= 1) & (RS_status[4] >= 1))
	{
		n = 2;

		int r = rand() % n;

		if (r = 0)
		{
			// Speeds up right motor and slows down left motor

			/* 			duty_cycleL--;
						duty_cycleR++; */

			// Makes small left rotations to straighten movement

			rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);

			// Continues moving

			move(distance_time, duty_cycleL, duty_cycleR);
		}

		if (r = 1)
		{
			// Sets larger rotation time to allow full 90 degree right turn

			long rot_time_L = 5000;
			long rot_time_R = 5000;

			// Makes right turn

			rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);
		}
	}

	// 00100 Stuck on right edge, shift left OR Stuck on left edge, shift right

	if ((RS_status[0] == 0) & (RS_status[1] == 0) & (RS_status[2] >= 1) & (RS_status[3] == 0) & (RS_status[4] == 0))
	{
		n = 2;

		int r = rand() % n;

		if (r = 0)
		{
			// Speeds up right motor and slows down left motor

			/* 			duty_cycleL--;
						duty_cycleR++; */

			// Makes small left rotations to straighten movement

			rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);

			// Continues moving

			move(distance_time, duty_cycleL, duty_cycleR);
		}

		if (r = 1)
		{
			// Sets larger rotation time to allow full 90 degree right turn

			long rot_time_L = 5000;
			long rot_time_R = 5000;

			// Makes right turn

			rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);
		}
	}

	// 00101 Shift right

	if ((RS_status[0] == 0) & (RS_status[1] == 0) & (RS_status[2] >= 1) & (RS_status[3] == 0) & (RS_status[4] >= 1))
	{
		// Speeds up left motor and slows down right motor

		/* 		duty_cycleL++;
				duty_cycleR--; */

		// Makes small right rotations to straighten movement

		rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);

		// continues moving

		move(distance_time, duty_cycleL, duty_cycleR);
	}

	// 00110 Correct left oversteer

	if ((RS_status[0] == 0) & (RS_status[1] == 0) & (RS_status[2] >= 1) & (RS_status[3] >= 1) & (RS_status[4] == 0))
	{
		// Speeds up left motor and slows down right motor

		/* 		duty_cycleL++;
				duty_cycleR--; */

		// Makes small right rotations to straighten movement

		rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);

		// continues moving

		move(distance_time, duty_cycleL, duty_cycleR);
	}

	// 00111 Correct left oversteer AND 3-way intersection from the left, so randomly choose right turn or forward

	if ((RS_status[0] == 0) & (RS_status[1] == 0) & (RS_status[2] >= 1) & (RS_status[3] >= 1) & (RS_status[4] >= 1))
	{

		// Slows down right motor and slows down left motor

		duty_cycleL--;
		duty_cycleR--;

		// Generates "random" 0 or 1

		n = 2;

		int r = rand() % n;

		if (r = 1)
		{
			// Speeds up left motor and slows down right motor

			// duty_cycleL++;
			// duty_cycleR--;

			// Makes small right rotations to straighten movement

			// rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);

			// continues moving

			move(distance_time, duty_cycleL, duty_cycleR);
		}

		if (r = 0)
		{
			// Sets larger rotation time to allow full 90 degree right turn

			long rot_time_L = 5000;
			long rot_time_R = 5000;

			// Makes right turn

			rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);
		}
	}

	// 01000 Correct right oversteer

	if ((RS_status[0] == 0) & (RS_status[1] >= 1) & (RS_status[2] == 0) & (RS_status[3] == 0) & (RS_status[4] == 0))
	{
		// Speeds up right motor and slows down left motor

		/* 		duty_cycleL--;
				duty_cycleR++; */

		// Makes small left rotations to straighten movement

		rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);

		// continues moving

		move(distance_time, duty_cycleL, duty_cycleR);
	}

	// 01001 4-way and stuck on right corner, shift left

	if ((RS_status[0] == 0) & (RS_status[1] >= 1) & (RS_status[2] == 0) & (RS_status[3] == 0) & (RS_status[4] >= 1))
	{
		// Generates "random" 0 or 1

		n = 3;

		int r = rand() % n;

		// Slows down right motor and slows down left motor

		duty_cycleL--;
		duty_cycleR--;

		// Determines which direction to turn based on random number

		if (r = 0)
		{
			// Speeds up right motor and slows down left motor
			/*
						duty_cycleL--;
						duty_cycleR++; */

			// Makes small left rotations to straighten movement

			rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);

			// continues moving

			move(distance_time, duty_cycleL, duty_cycleR);
		}

		if (r = 1)
		{
			// Sets larger rotation time to allow full 90 degree left turn

			long rot_time_L = 15000;
			long rot_time_R = 15000;

			// Makes left turn

			rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);
		}

		if (r = 2)
		{
			// Sets larger rotation time to allow full 90 degree right turn

			long rot_time_L = 15000;
			long rot_time_R = 15000;

			// Makes right turn

			rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);

			// continues moving

			move(distance_time, duty_cycleL, duty_cycleR);
		}
	}

	// 01010 Conditional to navigate forward

	if ((RS_status[0] == 0) & (RS_status[1] >= 1) & (RS_status[2] == 0) & (RS_status[3] >= 1) & (RS_status[4] == 0))
	{
		// Speeds up left motor and right motor

		// duty_cycleL++;
		// duty_cycleR++;

		// Continues moving

		move(distance_time, duty_cycleL, duty_cycleR);
	}

	// 01011 Condtional to correct left oversteer

	if ((RS_status[0] == 0) & (RS_status[1] >= 1) & (RS_status[2] == 0) & (RS_status[3] >= 1) & (RS_status[4] >= 1))
	{
		// Speeds up left motor and slows down right motor
		/*
				duty_cycleL++;
				duty_cycleR--; */

		// Makes small right rotations to straighten movement

		rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);

		// continues moving

		move(distance_time, duty_cycleL, duty_cycleR);
	}

	// 01100 Condtional to correct left oversteer

	if ((RS_status[0] == 0) & (RS_status[1] >= 1) & (RS_status[2] >= 1) & (RS_status[3] == 0) & (RS_status[4] == 0))
	{
		// Speeds up left motor and slows down right motor

		/* 		duty_cycleL++;
				duty_cycleR--; */

		// Makes small right rotations to straighten movement

		rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);

		// continues moving

		move(distance_time, duty_cycleL, duty_cycleR);
	}

	// 01101 Condtional to correct left oversteer

	if ((RS_status[0] == 0) & (RS_status[1] >= 1) & (RS_status[2] >= 1) & (RS_status[3] == 0) & (RS_status[4] >= 1))
	{
		// Speeds up left motor and slows down right motor

		/* 		duty_cycleL++;
				duty_cycleR--; */

		// Makes small right rotations to straighten movement

		rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);

		// continues moving

		move(distance_time, duty_cycleL, duty_cycleR);
	}

	// 01110 Conditional to navigate forward

	if ((RS_status[0] == 0) & (RS_status[1] >= 1) & (RS_status[2] >= 1) & (RS_status[3] >= 1) & (RS_status[4] == 0))
	{
		// Speeds up left motor and right motor

		// duty_cycleL++;
		// duty_cycleR++;

		// Continues moving

		move(distance_time, duty_cycleL, duty_cycleR);
	}

	// 01111 Right 3-way intersection (can go forward or right)

	if ((RS_status[0] == 0) & (RS_status[1] >= 1) & (RS_status[2] >= 1) & (RS_status[3] >= 1) & (RS_status[4] >= 1))
	{

		// Slows down right motor and slows down left motor

		duty_cycleL--;
		duty_cycleR--;

		// Generates "random" 0 or 1

		n = 2;

		int r = rand() % n;

		// Determines which direction to turn based on random number

		if (r = 0)
		{
			// Speeds up right motor and slows down left motor

			// duty_cycleL--;
			// duty_cycleR++;

			// Makes small left rotations to straighten movement

			// rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);

			// continues moving

			move(distance_time, duty_cycleL, duty_cycleR);
		}

		if (r = 1)
		{
			// Sets larger rotation time to allow full 90 degree right turn

			long rot_time_L = 5000;
			long rot_time_R = 5000;

			// Makes right turn

			rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);

			// continues moving

			distance_time = 5000;

			move(distance_time, duty_cycleL, duty_cycleR);
		}
	}

	// 10000 Conditional to handle left corner

	if ((RS_status[0] >= 1) & (RS_status[1] == 0) & (RS_status[2] == 0) & (RS_status[3] == 0) & (RS_status[4] == 0))
	{
		// Sets larger rotation time to allow full 90 degree left turn

		long rot_time_L = 5000;
		long rot_time_R = 5000;

		// Makes left turn

		rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);
	}

	// 10001 MINE DETECTION PLUS Stuck on left edge, shift right

	if ((RS_status[0] >= 1) & (RS_status[1] == 0) & (RS_status[2] == 0) & (RS_status[3] == 0) & (RS_status[4] >= 1))
	{
		// Counts mine

		// mine_count++;

		// Calls display function

		// display(RS_status, mine_count);

		// Sets larger rotation time to allow full 90 degree right turn

		long rot_time_L = 5000;
		long rot_time_R = 5000;

		// Makes right turn

		rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);
	}

	// 10010 Stuck on left corner, rotate right

	if ((RS_status[0] >= 1) & (RS_status[1] == 0) & (RS_status[2] == 0) & (RS_status[3] >= 1) & (RS_status[4] == 0))
	{
		// Sets larger rotation time to allow full 90 degree right turn

		long rot_time_L = 5000;
		long rot_time_R = 5000;

		// Makes right turn

		rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);
	}

	// 10011 Stuck on left corner, rotate right

	if ((RS_status[0] >= 1) & (RS_status[1] == 0) & (RS_status[2] == 0) & (RS_status[3] >= 1) & (RS_status[4] >= 1))
	{
		// Sets larger rotation time to allow full 90 degree right turn

		long rot_time_L = 5000;
		long rot_time_R = 5000;

		// Makes right turn

		rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);
	}

	// 10100 Correct left oversteer

	if ((RS_status[0] >= 1) & (RS_status[1] == 0) & (RS_status[2] >= 1) & (RS_status[3] == 0) & (RS_status[4] == 0))
	{
		// Speeds up left motor and slows down right motor

		/* 		duty_cycleL++;
				duty_cycleR--; */

		// Makes small right rotations to straighten movement

		rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);

		// continues moving

		move(distance_time, duty_cycleL, duty_cycleR);
	}

	// 10101 Correct left oversteer

	if ((RS_status[0] >= 1) & (RS_status[1] == 0) & (RS_status[2] >= 1) & (RS_status[3] == 0) & (RS_status[4] >= 1))
	{
		// Speeds up left motor and slows down right motor

		/* 		duty_cycleL++;
				duty_cycleR--; */

		// Makes small right rotations to straighten movement

		rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);

		// continues moving

		move(distance_time, duty_cycleL, duty_cycleR);
	}

	// 10110 Stuck on left corner, rotate right, 3-way intersection possible randomly choose forward or left?

	if ((RS_status[0] >= 1) & (RS_status[1] == 0) & (RS_status[2] >= 1) & (RS_status[3] >= 1) & (RS_status[4] == 0))
	{
		// Sets larger rotation time to allow full 90 degree right turn

		long rot_time_L = 5000;
		long rot_time_R = 5000;

		// Makes right turn

		rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);
	}

	// 10111 4-way and stuck on right corner, shift left

	if ((RS_status[0] >= 1) & (RS_status[1] == 0) & (RS_status[2] >= 1) & (RS_status[3] >= 1) & (RS_status[4] >= 1))
	{
		// Generates "random" 0 or 1

		n = 3;

		int r = rand() % n;

		// Slows down right motor and slows down left motor

		duty_cycleL--;
		duty_cycleR--;

		// Determines which direction to turn based on random number

		if (r = 0)
		{
			// Speeds up right motor and slows down left motor

			// duty_cycleL--;
			// duty_cycleR++;

			// continues moving

			move(distance_time, duty_cycleL, duty_cycleR);
		}

		if (r = 1)
		{
			// Sets larger rotation time to allow full 90 degree left turn

			long rot_time_L = 15000;
			long rot_time_R = 15000;

			// Makes left turn

			rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);

			// continues moving

			move(distance_time, duty_cycleL, duty_cycleR);
		}

		if (r = 2)
		{
			// Sets larger rotation time to allow full 90 degree right turn

			long rot_time_L = 15000;
			long rot_time_R = 15000;

			// Makes right turn

			rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);

			// continues moving

			move(distance_time, duty_cycleL, duty_cycleR);
		}
	}

	// 11000 Stuck on right corner, rotate left

	if ((RS_status[0] >= 1) & (RS_status[1] >= 1) & (RS_status[2] == 0) & (RS_status[3] == 0) & (RS_status[4] == 0))
	{
		// Sets larger rotation time to allow full 90 degree left turn

		long rot_time_L = 5000;
		long rot_time_R = 5000;

		// Makes left turn

		rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);
	}

	// 11001 Stuck on right corner, rotate left

	if ((RS_status[0] >= 1) & (RS_status[1] >= 1) & (RS_status[2] == 0) & (RS_status[3] == 0) & (RS_status[4] >= 1))
	{
		// Sets larger rotation time to allow full 90 degree left turn

		long rot_time_L = 5000;
		long rot_time_R = 5000;

		// Makes left turn

		rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);
	}

	// 11010 Stuck on right corner, rotate left

	if ((RS_status[0] >= 1) & (RS_status[1] >= 1) & (RS_status[2] == 0) & (RS_status[3] >= 1) & (RS_status[4] == 0))
	{
		// Sets larger rotation time to allow full 90 degree left turn

		long rot_time_L = 5000;
		long rot_time_R = 5000;

		// Makes left turn

		rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);
	}

	// 11011 Conditional to handle 4-way intersection

	if ((RS_status[0] >= 1) & (RS_status[1] >= 1) & (RS_status[2] == 0) & (RS_status[3] >= 1) & (RS_status[4] >= 1))
	{
		// Generates "random" 0 or 1

		n = 3;

		int r = rand() % n;

		// Slows down right motor and slows down left motor

		duty_cycleL--;
		duty_cycleR--;

		// Determines which direction to turn based on random number

		if (r = 0)
		{
			// Speeds up right motor and slows down left motor

			// duty_cycleL--;
			// duty_cycleR++;

			// Makes small left rotations to straighten movement

			// rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);

			// continues moving

			move(distance_time, duty_cycleL, duty_cycleR);
		}

		if (r = 2)
		{
			PORTD |= (1 << 3) | (1 << 5) | (1 << 6); // BRAKE MOTORS
			PORTB |= (1 << 3);

			// Sets larger rotation time to allow full 90 degree left turn

			long rot_time_L = 15000;
			long rot_time_R = 15000;

			// Makes left turn

			rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);

			// Slows down right motor and slows down left motor

			duty_cycleL--;
			duty_cycleR--;

			// continues moving

			distance_time = 5000;

			move(distance_time, duty_cycleL, duty_cycleR);

			// Slows down right motor and slows down left motor

			// duty_cycleL--;
			// duty_cycleR--;
		}

		if (r = 1)
		{
			PORTD |= (1 << 3) | (1 << 5) | (1 << 6); // BRAKE MOTORS
			PORTB |= (1 << 3);

			// Sets larger rotation time to allow full 90 degree right turn

			long rot_time_L = 15000;
			long rot_time_R = 15000;

			// Makes right turn

			rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);

			// Slows down right motor and slows down left motor

			duty_cycleL--;
			duty_cycleR--;

			// continues moving

			distance_time = 5000;

			move(distance_time, duty_cycleL, duty_cycleR);

			// Slows down right motor and slows down left motor

			// duty_cycleL--;
			// duty_cycleR--;
		}
	}

	// 11100 Condtional to correct right oversteer AND 3-way intersection on the left

	if ((RS_status[0] >= 1) & (RS_status[1] >= 1) & (RS_status[2] >= 1) & (RS_status[3] == 0) & (RS_status[4] == 0))
	{

		// Slows down right motor and slows down left motor

		duty_cycleL--;
		duty_cycleR--;

		// Generates "random" 0 or 1

		n = 2;

		int r = rand() % n;

		// Determines which direction to turn based on random number

		if (r = 0)
		{
			// Speeds up right motor and slows down left motor

			/* 			duty_cycleL--;
						duty_cycleR++; */

			// Makes small left rotations to straighten movement

			// rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);

			// continues moving

			move(distance_time, duty_cycleL, duty_cycleR);
		}

		if (r = 1)
		{
			// Sets larger rotation time to allow full 90 degree left turn

			long rot_time_L = 5000;
			long rot_time_R = 5000;

			// Makes left turn

			rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);
		}
	}

	// 11101 Conditional to handle 4-way intersection

	if ((RS_status[0] >= 1) & (RS_status[1] >= 1) & (RS_status[2] >= 1) & (RS_status[3] == 0) & (RS_status[4] >= 1))
	{
		// Generates "random" 0 or 1

		n = 3;

		int r = rand() % n;

		// Slows down right motor and slows down left motor

		duty_cycleL--;
		duty_cycleR--;

		// Determines which direction to turn based on random number

		if (r = 0)
		{
			// Speeds up right motor and slows down left motor

			// duty_cycleL--;
			// duty_cycleR++;

			// Makes small left rotations to straighten movement

			// rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);

			// continues moving

			move(distance_time, duty_cycleL, duty_cycleR);
		}

		if (r = 1)
		{
			// Sets larger rotation time to allow full 90 degree left turn

			long rot_time_L = 15000;
			long rot_time_R = 15000;

			// Makes left turn

			rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);

			// continues moving

			distance_time = 5000;

			move(distance_time, duty_cycleL, duty_cycleR);
		}

		if (r = 2)
		{
			// Sets larger rotation time to allow full 90 degree right turn

			long rot_time_L = 15000;
			long rot_time_R = 15000;

			// Makes right turn

			rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);

			// continues moving

			distance_time = 5000;

			move(distance_time, duty_cycleL, duty_cycleR);
		}
	}

	// 11110 Right 3-way intersection (can go forward or left)

	if ((RS_status[0] >= 1) & (RS_status[1] >= 1) & (RS_status[2] >= 1) & (RS_status[3] >= 1) & (RS_status[4] == 0))
	{

		// Slows down right motor and slows down left motor

		duty_cycleL--;
		duty_cycleR--;

		// Generates "random" 0 or 1

		n = 2;

		int r = rand() % n;

		// Determines which direction to turn based on random number

		if (r = 1)
		{
			// Speeds up right motor and slows down left motor

			/* 			duty_cycleL--;
						duty_cycleR++; */

			// Makes small left rotations to straighten movement

			// rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);

			// continues moving

			move(distance_time, duty_cycleL, duty_cycleR);
		}

		if (r = 0)
		{
			// Sets larger rotation time to allow full 90 degree left turn

			long rot_time_L = 5000;
			long rot_time_R = 5000;

			// Makes left turn

			rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);

			// continues moving

			distance_time = 5000;

			move(distance_time, duty_cycleL, duty_cycleR);
		}
	}

	// 11111 Conditional to handle 4-way intersection

	if ((RS_status[0] >= 1) & (RS_status[1] >= 1) & (RS_status[2] >= 1) & (RS_status[3] >= 1) & (RS_status[4] >= 1))
	{
		// Generates "random" 0 or 1

		n = 3;

		int r = rand() % n;

		// Slows down right motor and slows down left motor

		duty_cycleL--;
		duty_cycleR--;

		// Determines which direction to turn based on random number

		if (r = 0)
		{

			// continues moving

			move(distance_time, duty_cycleL, duty_cycleR);
		}

		if (r = 1)
		{
			PORTD |= (1 << 3) | (1 << 5) | (1 << 6); // BRAKE MOTORS
			PORTB |= (1 << 3);

			// Sets larger rotation time to allow full 90 degree left turn

			long rot_time_L = 15000;
			long rot_time_R = 15000;

			// Makes left turn

			rotate_90_left(rot_time_L, duty_cycleL, duty_cycleR);

			// Slows down right motor and slows down left motor

			duty_cycleL--;
			duty_cycleR--;

			// continues moving

			distance_time = 5000;

			move(distance_time, duty_cycleL, duty_cycleR);

			// Slows down right motor and slows down left motor

			// duty_cycleL--;
			// duty_cycleR--;
		}

		if (r = 2)
		{
			PORTD |= (1 << 3) | (1 << 5) | (1 << 6); // BRAKE MOTORS
			PORTB |= (1 << 3);

			// Sets larger rotation time to allow full 90 degree right turn

			long rot_time_L = 15000;
			long rot_time_R = 15000;

			// Makes right turn

			rotate_90_right(rot_time_R, duty_cycleL, duty_cycleR);

			// Slows down right motor and slows down left motor

			duty_cycleL--;
			duty_cycleR--;

			// continues moving

			distance_time = 5000;

			move(distance_time, duty_cycleL, duty_cycleR);

			// Slows down right motor and slows down left motor

			// duty_cycleL--;
			// duty_cycleR--;
		}
	}
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
