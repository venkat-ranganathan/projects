/*
Venkat Ranganathan
EECE 558 - Embedded Systems Design
Prof Summerville
Assignment 1

"pb0.h" is the header file for "pb0.c", it includes header guards & function prototypes
*/

// header guards
#ifndef PB0_H
#define PB0_H

// pre-processor directives
#include <rp2040/resets.h>
#include <rp2040/sio.h>
#include <rp2040/io_bank0.h>
#include <rp2040/pads_bank0.h>
#include <stdbool.h>

// function prototypes
void configure_pb(void);
_Bool pb_is_pressed();
_Bool pb_not_pressed();

// close header guard
#endif
