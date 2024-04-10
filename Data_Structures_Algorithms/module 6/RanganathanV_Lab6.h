#ifndef RANGANATHANV_LAB6_H
#define RANGANATHANV_LAB6_H

// preprocessor directives
#include <stdio.h>

// Include for the srand and rand function
#include <stdlib.h>

// Include for strlen
#include <string.h>

// Include for the time function
#include <time.h>

// Comment line out if you don't want to capture file in the debug output file
#define DEBUG

// Macros used for dividers
#define SCREEN_WIDTH 100
#define STAR '*'
#define DASH '-'

// Macros used for header
#define SCHOOL "Binghamton University"
#define PROGRAMMER "Program written by: Venkat Ranganathan"
#define LAB "Lab 6"

// structures
typedef struct
{
	//
	// All the data that will be stored in one record
	// will be declared here.
	//

	int sampleData;

} recordType;

typedef struct node
{
	// Declare a record
	recordType data;

	struct node* pNext;

} nodeType;

typedef struct
{
	nodeType* pTop;

} stackType;

// function prototypes
// function 0
void PrintHeader(FILE* pOutput);
void PrintDivider(FILE* pOutput, char symbol, int numberOf);
void CenterString(FILE* pOutput, char string[], int lengthToCenterAcross);

void InitializeStack(stackType* pTop);
int StackIsEmpty(stackType stack);

// function 1
void Push(stackType* pTop, nodeType* newElement);

// function 2
void Pop(stackType* pTop);

// function 3
int ReturnPriority(char symbol);

// function 4
void OpenDataFile(FILE** pOutputLog, FILE** pDebugLog);

// function 5
void CloseFile(FILE ** pFile);

#endif