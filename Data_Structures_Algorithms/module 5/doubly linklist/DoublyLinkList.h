
#ifndef DOUBLY_LINK_LIST_H
#define DOUBLY_LINK_LIST_H

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

} recordType;

// Declare a node
typedef struct dataType
{
	recordType record;

	struct dataType* pNext;
	struct dataType* pPrev;

} nodeType;

// Macros
#define TRUE 1
#define FALSE 0

#define SCREEN_WIDTH 80
#define STAR '*'

#define SCHOOL "Binghamton University"
#define PROGRAMMER "Program written by: Prof. Foos"
#define LAB "Doubly Link List"

// Prototypes
void PrintHeader(FILE* pOutput);
void PrintDivider(FILE* pOutput, char symbol, int numberOf);
void CenterString(FILE* pOutput, char string[], int lengthToCenterAcross);

int IsEmpty(nodeType* pList);
void CreateList(nodeType** pFirst, nodeType** pEnd);
void CreateNode(nodeType* pTemp, int input);
void FindLocation(nodeType* pList, nodeType** pCurrent, nodeType** pPrev, int value);
void InsertNewNode(nodeType** pFront, nodeType** pEnd, nodeType* pCurrent, nodeType* pPrev, nodeType* pTemp);
void PrintList_Forward(nodeType* pFirst);
void PrintList_Backwards(nodeType* pEnd);
void FreeTheList(nodeType** pList);

#endif
