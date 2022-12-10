// header guards
#ifndef LAB7STRUCTURES_H
#define LAB7STRUCTURES_H

// preprocessor directives
#include <stdio.h>
#include <assert.h>
#include <string.h>

// const definition
#define STR_SIZE 20

// typedef structure declaration
typedef struct
{
    unsigned int year;
    unsigned int month;
    unsigned int day;
} Date; // this struct will be a datatype called "Date" with three variables

// function prototype
unsigned int validate(Date d);
unsigned int calculateYear(Date d);
unsigned int calculateMonth(Date d);
unsigned int calculateN(Date d);
unsigned int elapsedDays(Date d1, Date d2);
unsigned int dayOfWeek(Date d, char daystr[]);

// close header guards
#endif