#ifndef RANGANATHANV_LAB5_H
#define RANGANATHANV_LAB5_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct
{
	char title[MAX];
    char author[MAX];
    char company[MAX]; 

    int year;

    char ISBN[MAX];
    
    double cost;

} recordType;

typedef struct
{
    recordType oneBook;
    nodeType* pNext;

} nodeType;

#define SCREEN_WIDTH 120
#define STAR '*'

#define SCHOOL "Binghamton University"
#define PROGRAMMER "Program written by: Venkat Ranganathan"
#define LAB "Lab 5"

void PrintHeader(FILE* pOutput);
void PrintDivider(FILE* pOutput, char symbol, int numberOf);
void CenterString(FILE* pOutput, char string[], int lengthToCenterAcross);

void OpenFile(FILE** filePointer, char message[], char type[]);
void CloseFile(FILE** file);
void CloseFiles(FILE** file1, FILE** file2);

void CreateNode(nodeType* pNewNode, int input);

#endif