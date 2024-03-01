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
#define MAXER 50

#define DASH '-'
#define STAR '*'
#define SCREEN_WIDTH 80
#define TABLE_WIDTH 50

#define SCHOOL "Binghamton University"
#define PROGRAMMER "Program written by: Venkat Ranganathan"
#define LAB "Lab 3"

// constants

// function prototypes
void PrintHeader(FILE * pFout);
void PrintDivider(FILE* pOutput, char symbol, int numberOf);
void PrintDividerScreen(char symbol, int numberOf);
void CenterString(FILE* pFout, char string[], int lengthToCenterAcros);

void OpenFile(FILE** filePointer, char message[], char type[]);
void CloseFile(FILE** file);

void StarPattern(FILE* pFout, int number, int counter);

void FillArrayWithRandomNumbers(int intArray[], int maximum, int number);
void PrintArray(FILE* pFout, const int intArray[], int arrayCounter);
int SumArray(int intArray[], int counter, int size);

void PrintDigits(FILE* pFOut, int number);

void QuickSort (int intArray[], int m, int n);
void Partition(int intArray[], int* i, int* j);

int ReverseDigits(int number, int counter);


// close header guard
#endif