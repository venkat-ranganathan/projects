#ifndef LAB2_H
#define LAB2_H

// preprocessor directives

#include <stdio.h>
#include <assert.h>

// constants; no semicolon at end and no equal signs

#define PI 3.14

// function prototype declaration; ends in semicolon; be sure to declare variable type and name

void introduction(void);
float castToFloat(int numi);
double circleArea(int radius);
int circlePerimeter(int radius);
int fahrenheit2Celsius(int fahrenheit);
unsigned int factorial(unsigned int num);

#endif
