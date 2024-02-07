// header guard
#ifndef RANGANATHANV_LAB2_H
#define RANGANATHANV_LAB2_H

// preprocessor directives
// Include for scanf and printf
#include <stdio.h>

// Include for strlen
#include <string.h>

// Include for srand and rand functions
#include <stdlib.h>

// Include for time function
#include <time.h>

// macros
#define MAX 50

#define DASH '-'
#define STAR '*'
#define SCREEN_WIDTH 80
#define TABLE_WIDTH 50

#define SCHOOL "Binghamton University"
#define PROGRAMMER "Program written by: Venkat Ranganathan"
#define LAB "Lab 2"

// constants

// function prototypes
void PrintHeader(FILE * pFout);
void PrintDivider(FILE* pFout, char symbol, int numberOf);
void CenterString(FILE* pFout, char string[], int lengthToCenterAcross);

void OpenFile(FILE** filePointer, char message[], char type[]);
void CloseFiles(FILE** file1, FILE** file2);

void ReadDataFromFile(FILE* pFin, int intArray[], int* arrayCounter);
void PrintArray(FILE* pFout, const int intArray[], int arrayCounter);

void FillArrayWithRandomNumbers(int intArray[]);

void CountEvenOddNumbers(int intArray[], int* isEven, int* isOdd);
int TotalArray(int intArray[]);
double CalculateAverage(int intArray[], int arrayCounter);
int CountNumberAboveAverage(int intArray[], int arrayCounter);

void PrintResults(FILE* pFout, int intArray[], int arrayCounter, int isEven, int isOdd);

// close header guard
#endif