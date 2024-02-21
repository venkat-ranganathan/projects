// header gaurds
#ifndef RANGANATHANV_LAB3_H
#define RANGANATHANV_LAB3_H

// preprocessor directives
// Include for scanf and printf
#include <stdio.h>

// Include for strlen
#include <string.h>

// need for srand and rand functions
#include <stdlib.h>

// need to keep track of time to generate random numbers
#include <time.h>

// macros
#define MAX 20

#define DASH '-'
#define STAR '*'
#define SCREEN_WIDTH 80
#define TABLE_WIDTH 50

#define SCHOOL "Binghamton University"
#define PROGRAMMER "Program written by: Venkat Ranganathan"
#define LAB "Lab 3"

// constants

// function prototypes
void PrintHeader(FILE * pFout, int option);
void PrintDivider(FILE* pOutput, char symbol, int numberOf);
void PrintDividerScreen(char symbol, int numberOf);
void CenterString(FILE* pFout, char string[], int lengthToCenterAcros, int option);

void OpenFile(FILE** filePointer, char message[], char type[]);
void CloseFile(FILE** file);

void StarPattern(FILE* pFout, int number, int counter, int option);

void FillArrayWithRandomNumbers(int intArray[]);
void PrintArray(FILE* pFout, const int intArray[], int arrayCounter, int option);
int SumArray(int intArray[], int counter, int size);

void PrintDigits(FILE* pFOut, int number, int option);

// close header guard
#endif