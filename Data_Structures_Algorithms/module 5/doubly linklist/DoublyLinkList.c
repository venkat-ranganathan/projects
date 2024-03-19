/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Written by Prof. Foos
| Course:           CS-212: Data Structures for Engineers
| Program  Name:    Doubly Link List
| Date:             March 12, 2024
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|  This program will allow the user to enter integer values and place those numbers in the link
| list while keeping the list in numeric order
|
|   This program will call functions to complete the following tasks:
|     - Create a doulbe link list, keeping all values in order.
|     - Print the link list to the screen
|     - Free (or delete) the link list
|     - Print the link list, showing that the list is empty
|
|   For more assistance with this program read the provided notes:
|     Notes for the Advance Link List Program.docx
|
|--------------------------------------------------------------------------------------------------
| Inputs:
|   Users will enter integers until they enter a 0.
|
|--------------------------------------------------------------------------------------------------
| Processing:
|   All the integers will be stored in a link list using dynamic memory
|  The functions malloc will be used to reserve memory at run-time and the function free will
|  will be used to free memory.
|
|  There are five scenerios that situations when inserting to a link list (when keeping the order)
|
|  Situation 1: There is nothing in the list. (This is when we insert the first node)
|
|  Situation 2: We have a new max value, the node goes end of the list.
|
|  Situation 3: We have a new min node, the node goes at the front of the list
|
|  Situation 4: We have a new value that needs to be inserted in the middle of the list
|
|--------------------------------------------------------------------------------------------------
| Outputs:
|   The doubly link list will be printed to the screen.
|   The doubly link can be printed forward or backwards to the screen without recurrsion. 
|
|   See Functions: PrintList_Forward and PrintList_Backwards
|   After the link list is destroyed a message will be displayed to the screen stating that
|   the list is empty.
|
|--------------------------------------------------------------------------------------------------
*/

#include "DoublyLinkList.h"

int main(void)
{

	// Create a pointer for our linked list
	// Assign the pointer to NULL
	nodeType* pFront = NULL;
	nodeType* pEnd = NULL;

	PrintHeader(stdout);

	// Move cursor down one line
	printf("\n");

	/*
	   NOTE:

	   When creating a link list, the value of the pointer will be changing.

	   Therefore, you will need pass the address of the pointer.

	   The function header will have a double pointer as a parameter.

	*/

	CreateList(&pFront, &pEnd);

	// Print message to the screen
	printf("\nPrint the list after entering all the data:\n\n");

	// Check to see if there is anything in the list
	if (!IsEmpty(pFront))
	{
		// PrintList_Forward(pFront);
		PrintList_Backwards(pEnd);

		// Move cursor down one line
		printf("\n");
	}

	// There is nothing in the list. 
	else
	{
		// Print the list is empty to the screen
		CenterString(stdout, "* * * LIST IS EMPTY * * *", SCREEN_WIDTH);
	}


	FreeTheList(&pFront);

	// Print message to the screen	
	printf("\nPrint the list after freeing all the data:\n\n");

	// Check to see if there is anything in the list
	if (!IsEmpty(pFront)) // <-- Since we just freed the list, this should fail.
	{
		PrintList_Forward(pFront);
		// PrintList_Backwards(pEnd);

		// Move cursor down one line
		printf("\n");
	}

	// There is nothing in the list. 
	else
	{
		// Print the list is empty to the screen
		CenterString(stdout, "* * * LIST IS EMPTY * * *", SCREEN_WIDTH);
	}

	return 0;
}


//-----------------------------------------------------------------------------
// Function Name: PrintHeader
// Description:
//   This function will call the functions needed to print a header to the 
//  screen. 
//
//-----------------------------------------------------------------------------
void PrintHeader(FILE* pOutput)
{
	// Call function to print a divider to the screen
	PrintDivider(pOutput, STAR, SCREEN_WIDTH);

	// Call functions to print three strings to center to the screen
	CenterString(pOutput, SCHOOL, SCREEN_WIDTH);
	CenterString(pOutput, PROGRAMMER, SCREEN_WIDTH);
	CenterString(pOutput, LAB, SCREEN_WIDTH);

	// Call function to print a divider to the screen
	PrintDivider(pOutput, STAR, SCREEN_WIDTH);

}


//-----------------------------------------------------------------------------
// Function Name: PrintDivider
// Description:
//   Symbols will be printed to the screen. 
//
//-----------------------------------------------------------------------------
void PrintDivider(FILE* pOutput, char symbol, int numberOf)
{

	for (int counter = 0; counter < numberOf; counter++)
	{
		// Print one character to the screen
		fprintf(pOutput, "%c", symbol);
	}

	// Move the cursor down to the next line
	fprintf(pOutput, "\n");

}


//-----------------------------------------------------------------------------
// Function Name: CenterString
// Description:
//   The array of characters passed into the function will be centered
//  across the screen using the following formula:
//  
//    (lengthToCenterAcross + the string length) / 2
//
//-----------------------------------------------------------------------------
void CenterString(FILE* pOutput, char string[], int lengthToCenterAcross)
{
	// Capture how long the string is
	// Cast to an integer because strlen technically returns size_t
	int stringLength = (int)strlen(string);

	// Calculate the width to print the string in
	int width = (lengthToCenterAcross + stringLength) / 2;

	// Calculate how many blank spaces are needed before printing the string
	int numberOfBlankSpaces = width - stringLength;

	for (int counter = 0; counter < numberOfBlankSpaces; counter++)
	{
		// Print one space
		fprintf(pOutput, " ");
	}

	// Print the string
	fprintf(pOutput, "%s\n", string);
}


//-----------------------------------------------------------------------------
// Function Name:IsEmpty
// Description:
//   Returns if a link list is empty
//
//-----------------------------------------------------------------------------
int IsEmpty(nodeType* pList)
{
	// Check to see if the link list is empty
	return pList == NULL;
}


//-----------------------------------------------------------------------------
// Function Name:CreateList
// Description:
//   This function will act as the driver to adding numbers to our link list. 
//
//-----------------------------------------------------------------------------
void CreateList(nodeType** pFirst, nodeType** pEnd)
{
	int input;
	nodeType* pTemp;

	nodeType* pPrev;
	nodeType* pCurrent;

	do
	{
		// Enter a number to put into the list
		printf("Enter a number (zero to stop): ");
		scanf("%d", &input);

		if (input != 0)
		{
			// Set pPrev to NULL (pCurrent will get set inside FindLocation)
			pPrev = NULL;

			// Create a new node
			pTemp = (nodeType*)malloc(sizeof(nodeType));

			CreateNode(pTemp, input);

			FindLocation(*pFirst, &pCurrent, &pPrev, pTemp->record.number);

			InsertNewNode(pFirst, pEnd, pCurrent, pPrev, pTemp);

		}

	} while (input != 0);

}


//-----------------------------------------------------------------------------
// Function Name:FindLocation
// Description:
//   The pointers pCurrent and pPrev will be positioned to that the new node
//  can be inserted into the link list. 
//
//-----------------------------------------------------------------------------
void FindLocation(nodeType* pFront, nodeType** pCurrent, nodeType** pPrev, int value)
{
	int done = FALSE;

	// Assign pCurrent to the list
	*pCurrent = pFront;

	// Check to see if our link list is empty
	if (!IsEmpty(pFront))
	{
		while ((*pCurrent)->pNext != NULL && done == FALSE)
		{
			if (value > (*pCurrent)->record.number)
			{
				// Assign previous to current
				*pPrev = *pCurrent;

				// Move current down one node
				*pCurrent = (*pCurrent)->pNext;

			}
			else
			{
				// Found where current is less than our new value
				done = TRUE;
			}
		}
	}
}


//-----------------------------------------------------------------------------
// Function Name: InsertNewNode
// Description:
//   A new node will be inserted to our link list. The number will be inserted
// in order.
//
//-----------------------------------------------------------------------------
void InsertNewNode(nodeType** pFront, nodeType ** pEnd, nodeType* pCurrent, nodeType* pPrev, nodeType* pTemp)
{
	// Check to see if the list is empty
	if (IsEmpty(*pFront))
	{
		// Start the link list by pointing to a new node
		*pFront = pTemp;
		*pEnd = pTemp;

		printf("\nCASE 1: - There was no list -\n\n");
	}

	// We have a new max value 
	else if (pTemp->record.number > pCurrent->record.number)
	{
		// Add new node to the end of the list
		pCurrent->pNext = pTemp;
		pTemp->pPrev = pCurrent;
		*pEnd = pTemp;

		printf("\nCASE 2: - We have a new MAX value -\n\n");

	}

	// If previous is NULL and we don't have a new max, 
	// then we have a new min value
	else if (pPrev == NULL)
	{
		// Place the new node before the first node
		pCurrent->pPrev = pTemp;
		pTemp->pNext = pCurrent;
		*pFront = pTemp;

		printf("\nCASE 3: - We have a new MIN value -\n\n");
	}

	// Place the new node between the previous and the current.
	else
	{
		// Add new node between the previous and the current
		pPrev->pNext = pTemp;
		pCurrent->pPrev = pTemp;
		pTemp->pNext = pCurrent;
		pTemp->pPrev = pPrev;

		printf("\nCASE 4: - Inserted in the MIDDLE -\n\n");

	}

}


//-----------------------------------------------------------------------------
// Function Name:CreateNode
// Description:
//   Both members of the new node will be initialized. 
//
//-----------------------------------------------------------------------------
void CreateNode(nodeType* pNewNode, int input)
{
	// Assign members of the new node
	pNewNode->record.number = input;
	pNewNode->pNext = NULL;
	pNewNode->pPrev = NULL;
}


//-----------------------------------------------------------------------------
// Function Name:PrintList_Forward
// Description:
//  This function will take the pointer to the front of our link list. 
//  Since the address will not be changing there is no reason for a double 
//  pointer. 
//
//  Every item of the link list will be printed to the screen
//
//-----------------------------------------------------------------------------
void PrintList_Forward(nodeType* pFirst)
{
	// Assign temp to the first item in the list
	nodeType* pTemp = pFirst;

	while (pTemp != NULL)
	{
		// Print number to the screen
		printf("%-5d", pTemp->record.number);

		// Move pointer to the next node
		pTemp = pTemp->pNext;
	}

}


//-----------------------------------------------------------------------------
// Function Name:PrintList_Backwards
// Description:
//  This function will take the pointer to the end of our link list. 
//  Since the address will not be changing there is no reason for a double 
//  pointer. 
//
//  Every item of the link list will be printed to the screen
//
//-----------------------------------------------------------------------------
void PrintList_Backwards(nodeType* pEnd)
{
	// Assign temp to the last item in the list
	nodeType * pTemp = pEnd;

	while (pTemp != NULL)
	{
		// Print number to the screen
		printf("%-5d", pTemp->record.number);

		// Move pointer to the next node
		pTemp = pTemp->pPrev;
	}

}


//-----------------------------------------------------------------------------
// Function Name: FreeTheList
// Description:
//  This function will delete every node in the link list
//
//-----------------------------------------------------------------------------
void FreeTheList(nodeType** pList)
{
	nodeType* pTemp;

	while (*pList != NULL)
	{
		// Assign pTemp to pList
		pTemp = *pList;

		// Move pList to the next element
		*pList = (*pList)->pNext;

		// Delete pTemp
		free(pTemp);
	}
}
