/*
Venkat Ranganathan
EECE 558 - Embedded Systems Design
Prof Summerville
Assignment 1

This is the source file for assignment 1. 

"assign1.c" first calls the header file, "led0.h" which includes the pre-processor directives, & function prototypes used in "led0.c". The "led0.c" file assigns the LED 
to GP 15 (pin 20 on the RPI Pico). Pull up resistor is enabled (set to 1). Function select is enabled (set to 5). GP 15 is cleared to turn the LED on & set to turn the LED off.

"pb0.c" configures the push button. The pushbutton is assigned to GP 19 (pin 25)
The input is set to enable, along with pull up (optional), and function select
is set to 5. Two boolean functions are in the file: "pb_is_pressed" & 
"pb_is_not_pressed". "pb_is_pressed" checks if the input detects that the button
is pressed, and returns false if it is. The function returns falls because
we are using an active-low configuration. "pb_not_pressed" just returns the opposite
of "pb_is_pressed"

"assign1.c" has a single function, main, that calls the led & pushbutton configuration
 functions, then loops forever turning the led on when the button is pressed and
 turning it off when the button isn't pressed

*/

#include "led0.h"
#include "pb0.h"

int main ( void )
{
	configure_led();
	configure_pb();

		while(1)
		{
            if (pb_is_pressed())
				turn_on_led();
			else
				turn_off_led();
		}
		return(0);
}

