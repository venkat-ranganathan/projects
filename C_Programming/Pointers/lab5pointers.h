// header guards
#ifndef LAB5POINTERS_H
#define LAB5POINTERS_H

// preprocessor directives
#include <stdio.h>
#include <assert.h>
#include <string.h>

// constant declaration
#define STR_SIZE 50

// function prototypes
int flipSign(int *x);
int compareAndSwap(int *x, int *y);
int searchArray(int array[], int size, int item);
int copyString(char str[], char str2[]);

// close header guard
#endif