/*
Venkat Ranganathan
EECE 558 - Embedded Systems Design
Prof Summerville
Assignment 1

"pb0.c" is the driver for the pushbutton

"pb0.c" configures the push button. The pushbutton is assigned to GP 19 (pin 25)
The input is set to enable, along with pull up (optional), and function select
is set to 5. Two boolean functions are in the file: "pb_is_pressed" & 
"pb_is_not_pressed". "pb_is_pressed" checks if the input detects that the button
is pressed, and returns false if it is. The function returns false because
we are using an active-low configuration.
*/

#include "pb0.h"

void configure_pb( void )
{
    resets -> clr_reset = 
	    RESETS_RESET_IO_BANK0_MASK
	    | RESETS_RESET_PADS_BANK0_MASK;

    while(! (resets -> reset_done & RESETS_RESET_IO_BANK0_MASK))
    	continue;

    while(! (resets -> reset_done & RESETS_RESET_PADS_BANK0_MASK))
    	continue;

    pads_bank0 -> gpio19 = 
	PADS_BANK0_GPIO19_OD(0) 
	| PADS_BANK0_GPIO19_IE(1) 
	| PADS_BANK0_GPIO19_DRIVE(0) 
	| PADS_BANK0_GPIO19_PUE(1) 
	| PADS_BANK0_GPIO19_PDE(0) 
	| PADS_BANK0_GPIO19_SCHMITT(0) 
	| PADS_BANK0_GPIO19_SLEWFAST(0);

    io_bank0 -> gpio19_ctrl = 
	IO_BANK0_GPIO19_CTRL_IRQOVER(0) |
	IO_BANK0_GPIO19_CTRL_INOVER(0)  |
	IO_BANK0_GPIO19_CTRL_OEOVER(0)  |
	IO_BANK0_GPIO19_CTRL_OUTOVER(0) |
	IO_BANK0_GPIO19_CTRL_FUNCSEL(5);

}

_Bool pb_is_pressed()
{
    if(sio -> gpio_in & (1<<19))
        return false;
    else
        return true;
}

_Bool pb_not_pressed()
{
        return !pb_is_pressed();
}
