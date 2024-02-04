// header guard
#ifndef RANGANATHANV_LAB1_H
#define RANGANATHANV_LAB1_H

// include for printf and scanf
#include <stdio.h>

// macros
#define SCHOOL "Binghamton University"
#define NAME "Venkat Ranganathan"
#define LAB "Lab 1"

// constant; need to use static bc gcc doesn't work well with constants in header files
static const double PI = 3.14;

// function prototypes
void PrintHeader();
void PrintDivider();
int PrintMenuAndGetSelection();
void ProcessSelection(int selection, int* valueA, int* valueB, int* valueC, double* area);
void PrintShape(int selection);
void PrintResults(int selection, int valueA, int valueB, int valueC, double area);

// close header guard
#endif