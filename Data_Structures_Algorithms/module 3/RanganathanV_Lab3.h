#ifndef RANGANATHANV_LAB3_H
#define RANGANATHANV_LAB3_H

// preprocessor directives
// Include for scanf and printf
#include <stdio.h>

// Include for strlen
#include <string.h>

// macros
#define MAX 50
#define MAXER 100
#define MAXERER 1500

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
void PrintDivider(FILE* pFout, char symbol, int numberOf);
void CenterString(FILE* pFout, char string[], int lengthToCenterAcross);

void OpenFile(FILE** filePointer, char message[], char type[]);
void CloseFile(FILE** file);
void CloseFiles(FILE** file1, FILE** file2);

#endif