
#ifndef SIMPLE_LINK_LIST_H
#define SIMPLE_LINK_LIST_H

#define _CRT_SECURE_NO_WARNINGS

// Included for functions printf and scanf
#include <stdio.h>

// Include for functions malloc and free
#include <stdlib.h>

// Include for function strlen
#include <string.h>



typedef struct
{
	int number;
	
} recordType; // where data will be stored inside linkList

// Declare a node
typedef struct dataType
{
	recordType record;

	struct dataType * pNext; // pointer to another node

} linkList; // linkList is the same as calling struct dataType

#define SCREEN_WIDTH 120
#define STAR '*'

#define SCHOOL "Binghamton University"
#define PROGRAMMER "Program written by: Prof. Foos"
#define LAB "Simple Link List"

void PrintHeader(FILE* pOutput);
void PrintDivider(FILE* pOutput, char symbol, int numberOf);
void CenterString(FILE* pOutput, char string[], int lengthToCenterAcross);

// Prototypes
int  IsEmpty(linkList* pFirst);
void CreateList(linkList** pFirst);
void InsertNewNode(linkList** pFirst, linkList* pTemp);
void InitializeNode(linkList* pTemp, int input);
void FreeTheList(linkList** pFirst);

// Prototypes for printing the list
void PrintList_WithoutRecursion(linkList* pFirst);
void PrintList_WithRecursion_BeginningOfListFirst(linkList* pFirst);
void PrintList_WithRecursion_EndOfListFirst(linkList* pFirst);

#endif