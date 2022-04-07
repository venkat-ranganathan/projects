#include <avr/io.h>
#define F_CPU 20000000
#include <util/delay.h>

#define PWM_TOP 100
#define INCREMENT 5 // how much the duty cycle changes with each button press

int main()
{
    unsigned int pwm_counter = 0;
    unsigned int duty_cycle = 50;
    unsigned int last_left_button_state = (PINB & (1 << 1));
    unsigned int left_button_pressed;
    unsigned int last_right_button_state = (PINB & (1 << 5));
    unsigned int right_button_pressed;
    // Configure red LED
    DDRD |= (1 << 1); // configure pin as output
    // Configure left push-button
    DDRB &= ~(1 << 1); // configure pin as input
    PORTB |= (1 << 1); // enable pull-up resistor
    // Configure right push-button
    DDRB &= ~(1 << 5);
    PORTB |= (1 << 5);

    while (1)
    {
        // PWM Counter
        pwm_counter = pwm_counter + 1;
        if (pwm_counter >= PWM_TOP)
        {
            pwm_counter = 0;
        }
        // Do PWM on red LED
        if (pwm_counter < duty_cycle)
        {
            PORTD |= (1 << 1); // Turn on red LED
        }
        else
        {
            PORTD &= ~(1 << 1); // Turn off red LED
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
        _delay_us(10);
    }
}