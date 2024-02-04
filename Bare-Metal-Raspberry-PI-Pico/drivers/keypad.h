/*
Venkat Ranganathan
EECE 558 - Embedded Systems Design
Prof Summerville
Assignment 3
*/

#ifndef KEYPAD_H
#define KEYPAD_H

#include <stdint.h>
#include <rp2040/resets.h>
#include <rp2040/sio.h>
#include <rp2040/io_bank0.h>
#include <rp2040/pads_bank0.h>


void configure_keypad();
void keypad_scan_column(uint8_t col);
uint8_t keypad_get_row();

#endif