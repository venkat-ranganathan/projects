/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Prof Foos
| Course:           CS-212: Data Structures for Engineers
| Program  Name:    Binary Tree Example
| Date:             January 7, 2023
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|   This program will demonstrate the use of Binary Search Trees (BST) 
|
|--------------------------------------------------------------------------------------------------
| Inputs:
|   A BST will be formed by reading in characters from an input file. 
|
|
|--------------------------------------------------------------------------------------------------
| Processing:
|   The contents of the tree will be printed using PreOrder Traverse, InOrder Traverse, and a 
|  PostOrder  Traverse.
|
|   The tree will count the number letter 'b' in the tree using a Pre Order Traverse. 
|   
|   The nodes will be counted using an In Order Traverse
|
|   The number of letters that come before the letter 'n' will be counted using a Post Order 
|  Traverse. 
|
|--------------------------------------------------------------------------------------------------
| Outputs:
|   There will be three output files. 
|    - One file for Pre Order Traverse tasks
|    - One file for In Order Traverse tasks
|    - One file for Post Order Traverse tasks
|
|--------------------------------------------------------------------------------------------------
*/

#include "BinaryTree.h"

int main(void)
{
	FILE* pFin;
	FILE* pFoutPreOrder;
	FILE* pFoutInOrder;
	FILE* pFoutPostOrder;

	// Create tree
	node* pRoot = NULL;

	int total;
	
	OpenFiles(&pFin, &pFoutPreOrder, &pFoutInOrder, &pFoutPostOrder);

	PrintHeader(stdout);
	PrintHeader(pFoutPreOrder);
	PrintHeader(pFoutInOrder);
	PrintHeader(pFoutPostOrder);

	ReadDataInFromFile(pFin, &pRoot);

	PrintDivider(pFoutPreOrder, DASH, SCREEN_WIDTH);
	CenterString(pFoutPreOrder, "BINARY SEARCH TREE PRINTED USING PRE ORDER", SCREEN_WIDTH);
	PrintDivider(pFoutPreOrder, DASH, SCREEN_WIDTH);

	PrintPreOrder(pFoutPreOrder, pRoot);

	PrintDivider(pFoutInOrder, DASH, SCREEN_WIDTH);
	CenterString(pFoutInOrder, "BINARY SEARCH TREE PRINTED IUSINGN IN ORDER", SCREEN_WIDTH);
	PrintDivider(pFoutInOrder, DASH, SCREEN_WIDTH);

	PrintInOrder(pFoutInOrder, pRoot);

	PrintDivider(pFoutPostOrder, DASH, SCREEN_WIDTH);
	CenterString(pFoutPostOrder, "BINARY SEARCH TREE PRINTED USING POST ORDER", SCREEN_WIDTH);
	PrintDivider(pFoutPostOrder, DASH, SCREEN_WIDTH);

	PrintPostOrder(pFoutPostOrder, pRoot);

	// Set total to 0
	total = 0;

	CountALetterPreOrder(&total, 'b', pRoot);

	PrintLetterCountResult(pFoutPreOrder, 'b', total, 
		"NUMBER OF OCCURANCES OF A SPECIFIC LETTER");

	// Set total to 0
	total = 0;

	CountTotalNodesInOrder(&total, pRoot);

	PrintNodeCountResult(pFoutInOrder, total, "NUMBER OF NODES IN THE TREE");

	// Set total to 0
	total = 0;

	CountLetterBeroreALetterPostOrder(&total, 'n', pRoot);

	PrintNodesBeforeLetterCountResult(pFoutPostOrder, 'n', total, 
		"RESULTS FOR THE NUMBER OF NODES THAT COME BEFORE A LETTER COUNT");

	CloseFiles(&pFin, &pFoutPreOrder, &pFoutInOrder, &pFoutPostOrder);
	
	// Call Free The Nodes 

	return 0;
}