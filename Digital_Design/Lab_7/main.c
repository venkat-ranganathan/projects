#include <util/delay.h> // uses F_CPU to achieve us and ms delays
#include <avr/io.h>
#include <stdlib.h>

int main()
{
    // Start by setting the ports to an input or output
    // Set the specified bits of the port to be on or off based on what you want to do

    DDRD |= (1 << 1) | (1 << 7);               // set D1 & D7 as outputs
    DDRB &= ~((1 << 1) | (1 << 4) | (1 << 5)); // set B1, B4, B5 as inputs
    // PORTB |= (1 << 1) | (1 << 4) | (1 << 5);   // enables pull-up resistors for B1, B4, B5

    while (1)
    {

        // Since you need to read the value of the button at any moment it must be done within a loop
        if ((PINB & (1 << 1)) == 0)
        {
            PORTD ^= (1 << 1); // Turns on RED LED
        }

        if ((PINB & (1 << 4)) == 0)
        {
            PORTD ^= (1 << 1) | (1 << 7); // Turns on BOTH LEDs
        }

        if ((PINB & (1 << 5)) == 0)
        {
            PORTD ^= (1 << 7); // Turns on GREEN LED
        }
    }
    return 0;
}