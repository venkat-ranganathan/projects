
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

// Include statements
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int integer;

} recordType;

typedef struct nodeType
{
	recordType record;

	struct nodeType* pLeft;
	struct nodeType* pRight;

} node;


#define SCREEN_WIDTH 80
#define STAR '*'
#define DASH '-'

#define SCHOOL "Binghamton University"
#define PROGRAMMER "Program written by: Venkat Ranganathan"
#define LAB "Lab 8"

// Prototypes
void PrintHeader(FILE* pOutput);
void PrintDivider(FILE* pOutput, char symbol, int numberOf);
void CenterString(FILE* pOutput, const char string[], int lengthToCenterAcross);

void OpenFiles(FILE** pFin, FILE** pFoutPre, FILE** pFoutIn, FILE** pFoutPost);
void CloseFiles(FILE** pFin, FILE** pFoutPre, FILE** pFoutIn, FILE** pFoutPost);

void ReadDataInFromFile(FILE* pFin, node** pRoot);
void CreateNode(node* pNewNode, char newLetter);
void InsertNode(node** pRoot, node** pNewNode);
int IsTreeEmpty(node* pRoot);

void PrintPreOrder(FILE* pFout, node* currentNode);
void PrintInOrder(FILE* pFout, node* currentNode);
void PrintPostOrder(FILE* pFout, node* currentNode);

void CountALetterPreOrder(int* total, char letter, node* pCurrentNode);
void CountTotalNodesInOrder(int* total, node* pCurrentNode);
void CountLetterBeroreALetterPostOrder(int* total, char letter, node* pCurrentNode);

void PrintLetterCountResult(FILE* pOutput, char letter, int result, const char message[]);
void PrintNodeCountResult(FILE* pOutput, int result, const char message[]);
void PrintNodesBeforeLetterCountResult(FILE* pOutput, char letter, int result, const char message[]);


#endif