
#ifndef SIMPLE_ARRAY_H
#define SIMPLE_ARRAY_H

// Include for printf and scanf
#include <stdio.h>

// Include for the srand and rand function
#include <stdlib.h>

// Include for the strlen function
#include <string.h>

// Include for the time function
#include <time.h>

// Macros
#define SCHOOL "Binghamton University"
#define PROGRAMMER "Written by: Prof. Foos"
#define LAB "Simple Array Program"

const char STAR = '*';
const char DASH = '-';

const int MAX = 100;
const int SCREEN_WIDTH = 80;
const int TABLE_WIDTH = 50;

// Prototypes
void PrintHeader(void);
void CenterString(char string[], int lengthToCenterAcross);
void PrintDivider(char symbol, int numberOf);

void InitializeArray(int intArray[]);
void DoubleArray(int intArray[]);
void PrintArray(const int intArray[]);

#endif