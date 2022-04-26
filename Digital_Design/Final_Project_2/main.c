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

int main()
{
	int RS_status_0 = 0;
	int RS_status_1 = 0;
	int RS_status_2 = 0;
	int RS_status_3 = 0;
	int RS_status_4 = 0;

	int time = 39999;

	// Setting reflectance sensors as inputs

	DDRC &= ~(1 << 0);
	DDRC &= ~(1 << 1);
	DDRC &= ~(1 << 2);
	DDRC &= ~(1 << 3);
	DDRC &= ~(1 << 4);
	PORTC |= (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4);

	initialize_LCD_driver();
	LCD_execute_command(TURN_ON_DISPLAY);

	while (1)
	{
		while (time < 40000)
		{
			;
			// Live printing reflectance sensor status to LCD
			if ((PINC & (1 << 0)) == 1)
			{
				// Print out status of PC0 reflectance sensor
				RS_status_0 = 1;
				char char_RS_status_0[8];

				// LCD_execute_command(CLEAR_DISPLAY);
				LCD_move_cursor_to_col_row(0, 0);
				sprintf(char_RS_status_0, "%d", RS_status_0);
				LCD_print_String(char_RS_status_0); // Prints xcoord
				_delay_ms(50);
			}
			else
			{
				// Print out status of PC0 reflectance sensor
				RS_status_0 = 0;
				char char_RS_status_0[8];

				// LCD_execute_command(CLEAR_DISPLAY);
				LCD_move_cursor_to_col_row(0, 0);
				sprintf(char_RS_status_0, "%d", RS_status_0);
				LCD_print_String(char_RS_status_0); // Prints xcoord
				_delay_ms(50);
			}
			if ((PINC & (1 << 1)) == 1)
			{
				// Print out status of PC1 reflectance sensor
				RS_status_1 = 1;
				char char_RS_status_1[8];

				// LCD_execute_command(CLEAR_DISPLAY);
				LCD_move_cursor_to_col_row(1, 0);
				sprintf(char_RS_status_1, "%d", RS_status_1);
				LCD_print_String(char_RS_status_1); // Prints xcoord
				_delay_ms(50);
			}
			else
			{
				// Print out status of PC1 reflectance sensor
				RS_status_1 = 0;
				char char_RS_status_1[8];

				// LCD_execute_command(CLEAR_DISPLAY);
				LCD_move_cursor_to_col_row(1, 0);
				sprintf(char_RS_status_1, "%d", RS_status_1);
				LCD_print_String(char_RS_status_1); // Prints xcoord
				_delay_ms(50);
			}
			if ((PINC & (1 << 2)) == 1)
			{
				// Print out status of PC2 reflectance sensor
				RS_status_2 = 1;
				char char_RS_status_2[8];

				// LCD_execute_command(CLEAR_DISPLAY);
				LCD_move_cursor_to_col_row(2, 0);
				sprintf(char_RS_status_2, "%d", RS_status_2);
				LCD_print_String(char_RS_status_2); // Prints xcoord
				_delay_ms(50);
			}
			else
			{
				// Print out status of PC2 reflectance sensor
				RS_status_2 = 0;
				char char_RS_status_2[8];

				// LCD_execute_command(CLEAR_DISPLAY);
				LCD_move_cursor_to_col_row(2, 0);
				sprintf(char_RS_status_2, "%d", RS_status_2);
				LCD_print_String(char_RS_status_2); // Prints xcoord
				_delay_ms(50);
			}
			if ((PINC & (1 << 3)) == 1)
			{
				// Print out status of PC3 reflectance sensor
				RS_status_3 = 1;
				char char_RS_status_3[8];

				// LCD_execute_command(CLEAR_DISPLAY);
				LCD_move_cursor_to_col_row(3, 0);
				sprintf(char_RS_status_3, "%d", RS_status_3);
				LCD_print_String(char_RS_status_3); // Prints xcoord
				_delay_ms(50);
			}
			else
			{
				// Print out status of PC3 reflectance sensor
				RS_status_3 = 0;
				char char_RS_status_3[8];

				// LCD_execute_command(CLEAR_DISPLAY);
				LCD_move_cursor_to_col_row(3, 0);
				sprintf(char_RS_status_3, "%d", RS_status_3);
				LCD_print_String(char_RS_status_3); // Prints xcoord
				_delay_ms(50);
			}
			if ((PINC & (1 << 4)) == 1)
			{
				// Print out status of PC4 reflectance sensor
				RS_status_4 = 1;
				char char_RS_status_4[8];

				// LCD_execute_command(CLEAR_DISPLAY);
				LCD_move_cursor_to_col_row(4, 0);
				sprintf(char_RS_status_4, "%d", RS_status_4);
				LCD_print_String(char_RS_status_4); // Prints xcoord
				_delay_ms(50);
			}
			else
			{
				// Print out status of PC4 reflectance sensor
				RS_status_4 = 0;
				char char_RS_status_4[8];

				// LCD_execute_command(CLEAR_DISPLAY);
				LCD_move_cursor_to_col_row(4, 0);
				sprintf(char_RS_status_4, "%d", RS_status_4);
				LCD_print_String(char_RS_status_4); // Prints xcoord
				_delay_ms(50);
			}
		}
	}
}