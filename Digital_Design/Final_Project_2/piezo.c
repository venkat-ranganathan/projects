#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/io.h>
#include "lcd_driver.h"
#include "port_macros.h"
#define G 430
#define C 1290
#define D 1150
#define E 1025

void play_note(unsigned int pitch, long note_length, unsigned int rest);

// G6 - 430
// C5 - 1290
// D5 - 1150
// E5 - 1025
int main()
{

    DDRB |= (1 << 2); // sets buzzer as output
    long pitch = 1025;
    long note_length = 200000;
    unsigned int rest = 100;
    play_note(C, 300000, 100);
    play_note(C, 66666, 100);
    play_note(C, 66666, 100);
    play_note(C, 66666, 100);
    play_note(D, 200000, 100);
    play_note(C, 200000, 100);
    play_note(D, 200000, 100);
    play_note(E, 400000, 100);

    return 0;
}

void play_note(unsigned int pitch, long note_length, unsigned int rest)
{
    long timer = 0;
    long pwm_counter = 0;
    for (timer = 0; timer < note_length; timer++)
    {
        pwm_counter++;
        if (pwm_counter >= pitch)
        {
            pwm_counter = 0;
        }
        if (pwm_counter < (pitch / 2)) // makes it a 50% duty cycle square wave
        {
            PORTB |= (1 << 2);
        } // Piezo ON
        else
        {
            PORTB &= ~(1 << 2);
        } // PIEZO OFF
    }
    PORTB &= ~(1 << 2);
    _delay_ms(rest);
}
