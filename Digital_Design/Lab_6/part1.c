#define F_CPU 1000000UL
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#define LEFT_PORT_OUT PORTB // Assigning LEFT_PORT_OUT to PORTB
#define BIT_0 PB0           // Giving a name to bit 0 of PORTB that we shall use as our one-bit

// output
// We've wrapped our code in a main function.
// This works in very much the same way as the main() in a
// PC program-- it tells GCC where our program begins.
// This is often called the "entry point".

int main()
{
    DDRB |= (1 << BIT_0);   // Setting the PB0 to an output
    uint8_t SWITCHES = 150; // initializing SWITCHES to 150
    uint8_t count = 0;      // initializing count to 0
    while (1)
    {
        count++;
        
        if (count > SWITCHES)
        {
            LEFT_PORT_OUT = ~LEFT_PORT_OUT;
            count = 0;
        }
    }
    // Since the loop above executes indefinitely, we'll never reach this function;
    // but the GCC isn't "smart" enough to figure that out.
    // If we don't return something here, GCC will display a warning.
    return 0;
}