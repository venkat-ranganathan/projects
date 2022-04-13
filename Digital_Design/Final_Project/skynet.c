// Need 3pi to go to a plot point on an XY-plane
// Use _delay_us(n); to set how long to run motors for
// _delay_us(n) is microseconds, _delay_ms(n) is milliseconds
// start with Y-coordinate, go up/down Y-axis
// measure how far both motors move at 50% speed after 10,5,2,1 seconds, respectively
// go to Lowe's and buy thick masking tape, a light color
// stop motors after n time is over
// then repeat for X-coordinate

// start with initiliazing LCD - DONE by Ben

// input Y-coordinate via clicking middle button - DONE by Ben

// input X-coordinate via clicking middle button - Done by Ben

// set 5 second timer before 3pi starts finding coordinates

// starts mooving +/- Y-coordinate first

// changes directions to find +/- X-coordinate

// MOTORS brake and XY coordinates cleared

#include <stdint.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/io.h>
#include "lcd_driver.h"
#include "port_macros.h"

int main()
{
    unsigned int last_left_button_state = (PINB & (1 << 1));
    unsigned int left_button_pressed;
    unsigned int last_middle_button_state = (PINB & (1 << 4));
    unsigned int middle_button_pressed;
    unsigned int last_right_button_state = (PINB & (1 << 5));
    unsigned int right_button_pressed;
    unsigned int stage = 1; // 1 is choose x, 2 is choose y, 3 is move

    initialize_LCD_driver();
    LCD_execute_command(TURN_ON_DISPLAY);
    int8_t xcoord = 0;
    int8_t ycoord = 0;

    // Configure MOTORS
    DDRD |= (1 << 3) | (1 << 5) | (1 << 6); // Right and left motors FORWARD
    DDRB |= (1 << 3);

    while (1)
    {
        char char_x[8];
        char char_y[8];

        //=========================SELECTING COORDS============================
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
        if (stage == 2)
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
        LCD_execute_command(CLEAR_DISPLAY);
        LCD_move_cursor_to_col_row(0, 0);
        sprintf(char_x, "X:%2d", xcoord);
        LCD_print_String(char_x); // Prints X Coord
        LCD_move_cursor_to_col_row(0, 1);
        sprintf(char_y, "Y:%2d", ycoord);
        LCD_print_String(char_y); // Prints Y coord
        _delay_s(6);

        //=========================PULSERS=====================================
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

        //=========================MOTORS======================================
        // MOTOR 1 / M1 / LEFT MOTOR

        // MOTOR 2 / M2 / RIGHT MOTOR
    }
    return 0;
}
