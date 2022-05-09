// Prasanna Ranganathan and Ben Telfer
// EECE 287 - Spring 2022 - Binghamton University
// NO REVERSE ON MOTORS, ONLY COAST -- WITH DIFFERENT DUTY CYCLES
// NEED TO TEST DUTY CYCLES TO GET IT GOING STRAIGHT MOST OF THE TIME
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/io.h>
#include "lcd_driver.h"
#include "port_macros.h"
#define PWM_TOP 255

void display(unsigned int step, unsigned int mines_on_grid, unsigned int mines_found);
uint8_t sensor_detect();
void straight_line(uint8_t sensor_sum, unsigned int forward_time, unsigned int rot_adj_time, unsigned int duty_cycleL, unsigned int duty_cycleR);
uint8_t intersection_detect(unsigned int duty_cycleL, unsigned int duty_cycleR);
void intersection_movement(uint8_t intersection_ID, unsigned int rot_90_time, unsigned int duty_cycleL, unsigned int duty_cycleR);

void forward(unsigned int forward_time, unsigned int duty_cycleL, unsigned int duty_cycleR);
void adjust_left(unsigned int rot_adj_time, unsigned int duty_cycleR);
void adjust_right(unsigned int rot_adj_time, unsigned int duty_cycleL);
void rot_90_left(unsigned int rot_90_time, unsigned int duty_cycleL, unsigned int duty_cycleR);
void rot_90_right(unsigned int rot_90_time, unsigned int duty_cycleL, unsigned int duty_cycleR);
// void celebrate();
// void reverse(unsigned int reverse_time, unsigned int duty_cycleL, unsigned int duty_cycleR);

int main()
{
    DDRC &= ~(1 << 0) & ~(1 << 1) & ~(1 << 2) & ~(1 << 3) & ~(1 << 4); // Sets sensor as inputs
    PORTC |= (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4);     // Pull up resistors
    DDRD |= (1 << 5) | (1 << 6);                                       // Left Motor
    DDRD |= (1 << 3);                                                  // Right Motor
    DDRB |= (1 << 3);                                                  // Right Motor
    DDRB &= ~(1 << 1);                                                 // Configure left push-button input
    PORTB |= (1 << 1);                                                 // enable pull-up resistor
    DDRB &= ~(1 << 4);                                                 // Configure middle push-button input
    PORTB |= (1 << 4);                                                 // enable pull-up resistor
    DDRB &= ~(1 << 5);                                                 // Configure right push-button input
    PORTB |= (1 << 5);                                                 // enable pull-up resistor
    unsigned int duty_cycleL = 40;
    unsigned int duty_cycleR = 40;
    unsigned int rot_adj_time = 1000;
    unsigned int forward_time = 2000;
    unsigned int rot_90_time = 15000;
    uint8_t intersection_ID = 0x00;
    uint8_t sensor_sum = 0x00;
    unsigned int step = 0;
    unsigned int mines_on_grid = 1;
    unsigned int mines_found = 0;
    //	unsigned int reverse_time = 12000;
    unsigned int rotate_180_time = 50000;
    unsigned int last_left_button_state = (PINB & (1 << 1));
    unsigned int left_button_pressed = 0;
    unsigned int last_middle_button_state = (PINB & (1 << 4));
    unsigned int middle_button_pressed = 0;
    unsigned int last_right_button_state = (PINB & (1 << 5));
    unsigned int right_button_pressed = 0;

    initialize_LCD_driver();
    LCD_execute_command(TURN_ON_DISPLAY);

    while (1)
    {
        if (step == 0)
        {
            if (left_button_pressed == 1)
            {
                mines_on_grid--;
            }
            else if (right_button_pressed == 1)
            {
                mines_on_grid++;
            }
            else if (middle_button_pressed == 1) // Press Middle Button to Move On
            {
                step = 1;
            }
        }

        display(step, mines_on_grid, mines_found);

        if (step == 1)
        {
            _delay_ms(1000);
            while (1)
            {
                sensor_sum = sensor_detect();
                if ((sensor_sum == 0x1F) | (sensor_sum == 0x0F) | (sensor_sum == 0x1E)) // INTERSECTION! If either the [0] or [4] sensor = black
                {
                    step = 2;
                    break;
                }
                else if (sensor_sum == 0x00) // MINE! 00000
                {
                    step = 3;
                    break;
                }
                else
                {
                    straight_line(sensor_sum, forward_time, rot_adj_time, duty_cycleL, duty_cycleR);
                }
            }
        }

        if (step == 2)
        {
            intersection_ID = intersection_detect(duty_cycleL, duty_cycleR);               // Determines intersection
            intersection_movement(intersection_ID, rot_90_time, duty_cycleL, duty_cycleR); // Makes mevement based on intersection
            step = 1;                                                                      // Go back to straight line
        }

        if (step == 3)
        {
            _delay_ms(1000);
            mines_found++;
            display(step, mines_on_grid, mines_found);
            // reverse(reverse_time, duty_cycleL, duty_cycleR);
            _delay_ms(250);
            rot_90_left(rotate_180_time, duty_cycleL, duty_cycleR); // turn around
            _delay_ms(1000);
            step = 1; // Go back to straight line
        }

        if (mines_found == mines_on_grid)
        {
            LCD_execute_command(CLEAR_DISPLAY);
            LCD_move_cursor_to_col_row(0, 0);
            LCD_print_String("No More");
            LCD_move_cursor_to_col_row(0, 1);
            LCD_print_String("Mines");
            // Celebration function
            _delay_ms(10000);
            break;
        }
        //================================PULSERS===================================
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
    }
    return 0;
}

//=================================================================================================================================================
//==================DISPLAY=================
void display(unsigned int step, unsigned int mines_on_grid, unsigned int mines_found)
{
    LCD_execute_command(CLEAR_DISPLAY);
    if (step == 0)
    {
        LCD_move_cursor_to_col_row(0, 0);
        LCD_print_String("Mines on");
        LCD_move_cursor_to_col_row(0, 1);
        LCD_print_String("Grid:");
        LCD_move_cursor_to_col_row(6, 1);
        LCD_print_hex4(mines_on_grid);
    }
    if (step >= 1)
    {
        LCD_move_cursor_to_col_row(0, 0);
        LCD_print_String("Mines");
        LCD_move_cursor_to_col_row(0, 1);
        LCD_print_String("Found:");
        LCD_move_cursor_to_col_row(6, 1);
        LCD_print_hex4(mines_found);
    }
    _delay_ms(50);
}
//==================SENSOR_DETECT===================
uint8_t sensor_detect()
{
    unsigned int sensor_arr[5] = {0, 0, 0, 0, 0};
    uint8_t sensor_sum = 0x00;
    for (int i = 0; i < 5; i++)
    {
        sensor_arr[i] = PINC & (1 << i); // Reads all 5 sensors
        sensor_sum = sensor_arr[i] + sensor_sum;
    } // sums all sensor measurements
    return sensor_sum;
}
//==================STRAIGHT_LINE=================
void straight_line(uint8_t sensor_sum, unsigned int forward_time, unsigned int rot_adj_time, unsigned int duty_cycleL, unsigned int duty_cycleR)
{
    if (sensor_sum == 0x0E) // FORWARD
    {
        forward(forward_time, duty_cycleL, duty_cycleR);
    }                                                     // Continues forward movement
    else if ((sensor_sum == 0x06) | (sensor_sum == 0x02)) // LEFT ADJUST
    {
        adjust_left(rot_adj_time, duty_cycleR); // Makes small left rotations to straighten movement
        forward(forward_time, duty_cycleL, duty_cycleR);
    }                                                     // Continues forward movement
    else if ((sensor_sum == 0x0C) | (sensor_sum == 0x08)) // RIGHT ADJUST
    {
        adjust_right(rot_adj_time, duty_cycleL); // Makes small right rotations to straighten movement
        forward(forward_time, duty_cycleL, duty_cycleR);
    } // Continues forward movement
    _delay_ms(40);
}
//=====================INTERSECTION_DETECT============================
uint8_t intersection_detect(unsigned int duty_cycleL, unsigned int duty_cycleR)
{
    unsigned int intersection_ID_arr[5] = {0, 0, 0, 0, 0};
    uint8_t intersection_ID_sum = 0x00;
    _delay_ms(1000); // JUST FOR TESTING PURPOSES
    forward(5000, duty_cycleL, duty_cycleR);
    _delay_ms(200);
    intersection_ID_arr[0] = PINC & (1 << 0);
    intersection_ID_arr[4] = PINC & (1 << 4); // MEASURING IF INTERSECTION HAS LEFT OR RIGHT PATHS
    _delay_ms(1000);                          // JUST FOR TESTING PURPOSES
    forward(11000, duty_cycleL, duty_cycleR);
    _delay_ms(200);
    intersection_ID_arr[1] = PINC & (1 << 1);
    intersection_ID_arr[2] = PINC & (1 << 2);
    intersection_ID_arr[3] = PINC & (1 << 3); // MEASURING IF INTERSECTION HAS FORWARD PATH
    for (int i = 0; i < 5; i++)
    {
        intersection_ID_sum = intersection_ID_arr[i] + intersection_ID_sum;
    } // sums all intersection_ID_arr measurements
    return intersection_ID_sum;
}
//====================INTERSECTION_MOVEMENT========================
void intersection_movement(uint8_t intersection_ID, unsigned int rot_90_time, unsigned int duty_cycleL, unsigned int duty_cycleR)
{
    unsigned int rand_direction = 0;
    if ((intersection_ID == 0x1F) | (intersection_ID == 0x17) | (intersection_ID == 0x1D) | (intersection_ID == 0x13) | (intersection_ID == 0x19)) // 4-WAY
    {
        rand_direction = rand() % 3;
        if (rand_direction == 0) // LEFT
        {
            rot_90_left(rot_90_time, duty_cycleL, duty_cycleR);
        }
        else if (rand_direction == 1) // RIGHT
        {
            rot_90_right(rot_90_time, duty_cycleL, duty_cycleR);
        }
        // 2 = STRAIGHT (no turn)
    }
    else if ((intersection_ID == 0x0F) | (intersection_ID == 0x07) | (intersection_ID == 0x0D) | (intersection_ID == 0x03) | (intersection_ID == 0x09)) // EDGE LEFT
    {
        rand_direction = rand() % 2;
        if (rand_direction == 0) // LEFT
        {
            rot_90_left(rot_90_time, duty_cycleL, duty_cycleR);
        }
        // 1 = STRAIGHT (no turn)
    }
    else if ((intersection_ID == 0x1E) | (intersection_ID == 0x16) | (intersection_ID == 0x1C) | (intersection_ID == 0x12) | (intersection_ID == 0x18)) // EDGE RIGHT
    {
        rand_direction = rand() % 2;
        if (rand_direction == 0) // RIGHT
        {
            rot_90_right(rot_90_time, duty_cycleL, duty_cycleR);
        }
        // 1 = STRAIGHT (no turn)
    }
    else if (intersection_ID == 0x11) // T EDGE
    {
        rand_direction = rand() % 2;
        if (rand_direction == 0) // LEFT
        {
            rot_90_left(rot_90_time, duty_cycleL, duty_cycleR);
        }
        else if (rand_direction == 1) // RIGHT
        {
            rot_90_right(rot_90_time, duty_cycleL, duty_cycleR);
        }
    }
    else if (intersection_ID == 0x01) // CORNER LEFT
    {
        rot_90_left(rot_90_time, duty_cycleL, duty_cycleR);
    }
    else if (intersection_ID == 0x10) // CORNER RIGHT
    {
        rot_90_right(rot_90_time, duty_cycleL, duty_cycleR);
    }
}

//===============FORWARD==================
void forward(unsigned int forward_time, unsigned int duty_cycleL, unsigned int duty_cycleR)
{
    unsigned int timer = 0;
    unsigned int pwm_counter = 0;
    for (timer = 0; timer < forward_time; timer++)
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
        } // LEFT COAST
        if (pwm_counter < duty_cycleR)
        {
            PORTD &= ~(1 << 3);
            PORTB |= (1 << 3);
        } // RIGHT FORWARD
        else
        {
            PORTD &= ~(1 << 3); // RIGHT COAST
            PORTB &= ~(1 << 3);
        }
        _delay_us(10);
    }
    PORTD &= ~((1 << 3) | (1 << 5) | (1 << 6)); // BOTH COAST
    PORTB &= ~(1 << 3);
}

//=============ADJUST_LEFT================
void adjust_left(unsigned int rot_adj_time, unsigned int duty_cycleR)
{
    unsigned int timer = 0;
    unsigned int pwm_counter = 0;
    for (timer = 0; timer < rot_adj_time; timer++)
    {
        pwm_counter++;
        if (pwm_counter >= PWM_TOP)
        {
            pwm_counter = 0;
        }
        if (pwm_counter < duty_cycleR)
        {
            PORTD &= ~(1 << 3);
            PORTB |= (1 << 3);
        } // RIGHT FORWARD
        else
        {
            PORTD &= ~(1 << 3); // RIGHT COAST
            PORTB &= ~(1 << 3);
        }
        PORTD &= ~((1 << 5) | (1 << 6)); // LEFT COAST
        _delay_us(10);
    }
    PORTD &= ~((1 << 3) | (1 << 5) | (1 << 6)); // BOTH COAST
    PORTB &= ~(1 << 3);
}

//=============ADJUST_RIGHT================
void adjust_right(unsigned int rot_adj_time, unsigned int duty_cycleL)
{
    unsigned int timer = 0;
    unsigned int pwm_counter = 0;
    for (timer = 0; timer < rot_adj_time; timer++)
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
        } // LEFT COAST
        PORTD &= ~(1 << 3);
        PORTB &= ~(1 << 3); // RIGHT COAST
        _delay_us(10);
    }
    PORTD &= ~((1 << 3) | (1 << 5) | (1 << 6)); // BOTH COAST
    PORTB &= ~(1 << 3);
}
//=============ROTATE_LEFT===============
void rot_90_left(unsigned int rot_90_time, unsigned int duty_cycleL, unsigned int duty_cycleR)
{
    unsigned int timer = 0;
    unsigned int pwm_counter = 0;
    for (timer = 0; timer < rot_90_time; timer++) // ACTUAL MOVEMENT
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
        } // LEFT FORWARD
        else
        {
            PORTD &= ~((1 << 5) | (1 << 6));
        } // LEFT COAST
        if (pwm_counter < duty_cycleR)
        {
            PORTD &= ~(1 << 3);
            PORTB |= (1 << 3);
        } // RIGHT FORWARD
        else
        {
            PORTD &= ~((1 << 3)); // RIGHT COAST
            PORTB &= ~(1 << 3);
        }
        _delay_us(10);
    }
    PORTD &= ~((1 << 3) | (1 << 5) | (1 << 6)); // BOTH COAST
    PORTB &= ~(1 << 3);
}
//===============ROTATE_RIGHT=================
void rot_90_right(unsigned int rot_90_time, unsigned int duty_cycleL, unsigned int duty_cycleR)
{
    unsigned int timer = 0;
    unsigned int pwm_counter = 0;
    for (timer = 0; timer < rot_90_time; timer++) // ACTUAL MOVEMENT
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
        } // LEFT COAST
        if (pwm_counter < duty_cycleR)
        {
            PORTD |= (1 << 3);
            PORTB &= ~(1 << 3);
        } // RIGHT FORWARD
        else
        {
            PORTD &= ~((1 << 3)); // RIGHT COAST
            PORTB &= ~(1 << 3);
        }
        _delay_us(10);
    }
    PORTD &= ~((1 << 3) | (1 << 5) | (1 << 6)); // BOTH COAST
    PORTB &= ~(1 << 3);
}

//======================REVERSE======================
/*void reverse(unsigned int reverse_time, unsigned int duty_cycleL, unsigned int duty_cycleR)
{
    unsigned int timer = 0;
    unsigned int pwm_counter = 0;
    for (timer = 0; timer < reverse_time; timer++)
    {
    pwm_counter++;
    if (pwm_counter >= PWM_TOP)
    { pwm_counter = 0; }
    if (pwm_counter < duty_cycleL)
    { PORTD |= (1 << 5);
      PORTD &= ~(1 << 6); } // LEFT FORWARD
    else
    { PORTD &= ~((1 << 5) | (1 << 6)); } // LEFT COAST
    if (pwm_counter < duty_cycleR)
    { PORTD |= (1 << 3);
      PORTB &= ~(1 << 3); } // RIGHT FORWARD
    else
    { PORTD &= ~(1 << 3); // RIGHT COAST
      PORTB &= ~(1 << 3); }
        _delay_us(10);
    }
    PORTD &= ~((1 << 3) | (1 << 5) | (1 << 6)); // BOTH COAST
    PORTB &= ~(1 << 3);
}*/
