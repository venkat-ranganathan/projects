/*
Venkat Ranganathan
EECE 558 - Embedded Systems Design
Prof Summerville
Assignment 1

"led0.c" is the driver for the LED

"led0.c" first calls the header file, "led0.h" which
includes the function prototypes used in "led0.c". The "led0.c" file assigns the LED 
to GP 28 (pin 20 on the RPI Pico). Input is enabled (set to 1). Function select is
enabled (set to 5). GP 28 is cleared to turn the LED on & set to turn the LED off.
*/

#include "led0.h"

void configure_led( void )
{
    resets -> clr_reset = 
	    RESETS_RESET_IO_BANK0_MASK
	    | RESETS_RESET_PADS_BANK0_MASK;

    while(! (resets -> reset_done & RESETS_RESET_IO_BANK0_MASK))
    	continue;

    while(! (resets -> reset_done & RESETS_RESET_PADS_BANK0_MASK))
    	continue;

    pads_bank0 -> gpio28 = 
	PADS_BANK0_GPIO28_OD(0) 
	| PADS_BANK0_GPIO28_IE(1) 
	| PADS_BANK0_GPIO28_DRIVE(0) 
	| PADS_BANK0_GPIO28_PUE(0) 
	| PADS_BANK0_GPIO28_PDE(0) 
	| PADS_BANK0_GPIO28_SCHMITT(0) 
	| PADS_BANK0_GPIO28_SLEWFAST(0);

    io_bank0 -> gpio28_ctrl = 
	IO_BANK0_GPIO28_CTRL_IRQOVER(0) |
	IO_BANK0_GPIO28_CTRL_INOVER(0)  |
	IO_BANK0_GPIO28_CTRL_OEOVER(0)  |
	IO_BANK0_GPIO28_CTRL_OUTOVER(0) |
	IO_BANK0_GPIO28_CTRL_FUNCSEL(5);

    sio->gpio_oe_set = (1<<28);
}
void turn_on_led()
{
    sio -> gpio_out_clr = (1<<28);
}
void turn_off_led()
{
    sio -> gpio_out_set = (1<<28);
}
void toggle_led()
{
    sio -> gpio_out_xor = (1<<28);
}