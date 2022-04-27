// Ben Telfer and Prasanna Ranganathan
// EECE 287 - Spring 2022 - Binghamton University

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/io.h>
#include "lcd_driver.h"
#include "port_macros.h"
//#define PWM_TOP 500

int main()
{
	int RS_status[] = {0, 0, 0, 0, 0};

	// Setting reflectance sensors as inputs

	DDRC &= ~(1 << 0);
	DDRC &= ~(1 << 1);
	DDRC &= ~(1 << 2);
	DDRC &= ~(1 << 3);
	DDRC &= ~(1 << 4);

	// Set register values as '1' to turn on sensors

	PORTC |= (1 << 0);
	PORTC |= (1 << 1);
	PORTC |= (1 << 2);
	PORTC |= (1 << 3);
	PORTC |= (1 << 4);

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
		char char_RS_status_0[8];
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