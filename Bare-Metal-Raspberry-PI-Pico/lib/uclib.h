/*
Venkat Ranganathan
EECE 558 - Embedded Systems Design
Prof Summerville
Assignment 2

header file with header guards, pre-processor directives, and function prototypes

*/

// header guards
#ifndef UCLIB_H
#define UCLIB_H

// preprocessor directives
#include <stdint.h>
#include <usbcdc.h>

// function prototypes
uint16_t rand();
void srand(uint32_t x);
void print_string(char const * str);
void print_hex(uint8_t num_digits, uint32_t value);
void hex_dump(uint32_t start, uint8_t bytes);
uint16_t div10(uint16_t x);
uint16_t mod10(uint16_t x);

// close header guards
#endif