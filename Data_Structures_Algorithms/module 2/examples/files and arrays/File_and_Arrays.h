
#ifndef FILE_AND_ARRAY_H
#define FILE_AND_ARRAY_H

// define if you are using Microsoft Visual Studio
#define _CRT_SECURE_NO_WARNINGS

// Include for scanf and printf
#include <stdio.h>

// Include for strlen
#include <string.h>

#define MAX 50

#define DASH '-'
#define STAR '*'
#define SCREEN_WIDTH 80
#define TABLE_WIDTH 50

#define SCHOOL "Binghamton University"
#define PROGRAMMER "Program written by: Prof. Foos"
#define LAB "File Processing and Arrays"

// Prototypes
void PrintHeader(FILE * pFout);
void PrintDivider(FILE* pFout, char symbol, int numberOf);
void CenterString(FILE* pFout, char string[], int lengthToCenterAcross);

void OpenFile(FILE** filePointer, char message[], char type[]);
void CloseFiles(FILE** file1, FILE** file2);

void FillArray(FILE* pFin, int intArray[], int* arrayCounter);
void AddThreeWithPointerArithmatic(int intArray[], int arrayCounter);
void PrintArray(FILE* pFout, const int intArray[], int arrayCounter);
void CloseFiles(FILE** fileOne, FILE** fileTwo);

#endif
