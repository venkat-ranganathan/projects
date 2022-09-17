// example header file from class

#ifndef HEADER_H
#define HEADER_H

// no equal sign or semicolon when defining constant values; if you add a semicolon at end, it'll get
// transferred into your code when it's called, so don't do it

// definitions doesn't use memory, but you don't get error checking compared to declaring the value as a variable in code

#define TAX 0.0875

// includes
#include <stdio.h>
#include <stdlib.h>

// constants

// PROTOTYPES need to be declared inside header since the prototypes also relies on the header files

void PrintHeader(void);
void PrintHeader(void);

// also need to make sure to declare variable type in function inside header file

void PrintCost(char name[], double price);

double GetDoubleValue(char message[]);

double CalculateTotal(double total);

#endif