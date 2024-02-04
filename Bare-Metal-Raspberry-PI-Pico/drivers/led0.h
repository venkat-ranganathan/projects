/*
Venkat Ranganathan
EECE 558 - Embedded Systems Design
Prof Summerville
Assignment 1

"led0.h" is the header file for "led0.c", it includes header guards & function prototypes
*/

// header guards
#ifndef LED0_H
#define LED0_H

// pre-processor directives
#include <rp2040/resets.h>
#include <rp2040/sio.h>
#include <rp2040/io_bank0.h>
#include <rp2040/pads_bank0.h>

// function prototypes
void configure_led( void );
void turn_on_led();
void turn_off_led();
void toggle_led();

// close header guard
#endif
