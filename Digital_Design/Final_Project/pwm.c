#define F_CPU 20000000
#include <stdint.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/io.h>
#include "lcd_driver.h"
#include "port_macros.h"

#define PWM_TOP 100
#define INCREMENT 5

int main()
{
    unsigned int pwm_counter = 0;
    unsigned int duty_cycle = 0;
    unsigned int last_left_button_state = (PINB & (1 << 1));
    unsigned int left_button_pressed;
    unsigned int last_right_button_state = (PINB & (1 << 5));
    unsigned int right_button_pressed;
    unsigned int last_middle_button_state = (PINB & (1 << 4));
    unsigned int middle_button_pressed;

    // Configure MOTORS
    DDRD |= (1 << 3) | (1 << 5) | (1 << 6); // Right and left motors FORWARD
    DDRB |= (1 << 3);

    // Configure left push-button
    DDRB &= ~(1 << 1); // configure pin as input
    // PORTB |= (1 << 1); // enable pull-up resistor

    // Configure right push-button
    DDRB &= ~(1 << 5);
    // PORTB |= (1 << 5);

    // 1) initialize LCD driver
    initialize_LCD_driver();

    // 2) turn on LCD after startup
    LCD_execute_command(TURN_ON_DISPLAY);

    while (1)
    {
        // 3) clear lcd buffer for refresh new data
        // LCD_execute_command(CLEAR_DISPLAY);

        // 4) display on botton line
        LCD_move_cursor_to_col_row(0, 0);

        // 5) print char on lcd
        LCD_print_hex16(duty_cycle);

        // PWM Counter
        pwm_counter = pwm_counter + 1;
        if (pwm_counter >= PWM_TOP)
        {
            pwm_counter = 0;
        }
        // Do PWM on MOTORS
        if (pwm_counter < duty_cycle)
        {
            PORTD |= (0 << 3) | (0 << 5) | (1 << 6); // Turn on MOTORS M1 & M2
            PORTB |= (1 << 3);
        }
        else
        {
            PORTD &= ~((1 << 3) | (1 << 5) | (1 << 6)); // Turn OFF motors M1 & M2
            PORTB &= ~(1 << 3);
        }
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

        // Decrement duty cycle when left button pressed
        if (left_button_pressed == 1)
        {
            if (duty_cycle >= INCREMENT)
            {
                duty_cycle = duty_cycle - INCREMENT;
            }
            else
            {
                duty_cycle = 0;
            }
        }
        // Increment duty cycle when right button pressed
        if (right_button_pressed == 1)
        {
            if (duty_cycle <= PWM_TOP - INCREMENT)
            {
                duty_cycle = duty_cycle + INCREMENT;
            }
            else
            {
                duty_cycle = PWM_TOP;
            }
        }
        // small delay to slow down main loop
        _delay_us(50);
    }
    LCD_print_hex16(duty_cycle);
}