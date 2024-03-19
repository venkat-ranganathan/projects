
#ifndef ADVANCED_LINK_LIST_H
#define ADVANCED_LINK_LIST_H

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

} linkList;

// Macros
#define TRUE 1
#define FALSE 0

#define SCREEN_WIDTH 80
#define STAR '*'

#define SCHOOL "Binghamton University"
#define PROGRAMMER "Program written by: Prof. Foos"
#define LAB "Advance Link List"

typedef enum 
{
	LEAST_TO_GREATEST,
	GREATEST_TO_LEAST

} orderType; 

// Prototypes
void PrintHeader(FILE* pOutput);
void PrintDivider(FILE* pOutput, char symbol, int numberOf);
void CenterString(FILE* pOutput, char string[], int lengthToCenterAcross);

int IsEmpty(linkList* pList);
void CreateList(linkList** pList);
void CreateNode(linkList* pTemp, int input);
void FindLocation(linkList* pList, linkList** pCurrent, linkList** pPrev, int value);
void InsertNewNode(linkList** pList, linkList* pCurrent, linkList* pPrev, linkList* pTemp);
void PrintList(linkList* pList, orderType order);
void FreeTheList(linkList** pList);

#endif