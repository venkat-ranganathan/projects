/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Written by Prof. Foos
| Course:           CS-212: Data Structures for Engineers
| Program  Name:    Advance Link List
| Date:             Last updated 3/7/2024
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|  This program will allow the user to enter integer values and place those numbers in the link 
| list while keeping the list in numeric order
|
|   This program will call functions to complete the following tasks:
|     - Create a link list, keeping all values in order.
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
|   The link list will be printed to the screen.
|   After the link list is destroyed a message will be displayed to the screen stating that
|   the list is empty.
|
|--------------------------------------------------------------------------------------------------
*/

#include "AdvancedLinkList.h"

int main(void)
{

	// Create a pointer for our linked list
	// Assign the pointer to NULL
	linkList* pList = NULL;

	PrintHeader(stdout);

	// Move cursor down one line
	printf("\n");

	/*
	   NOTE:

	   When creating a link list, the value of the pointer will be changing.

	   Therefore, you will need pass the address of the pointer.

	   The function header will have a double pointer as a parameter.

	*/

	CreateList(&pList);

	// Print message to the screen
	printf("\nPrint the list after entering all the data:\n\n");

	// Check to see if there is anything in the list
	if (!IsEmpty(pList))
	{
		// PrintList(pList, LEAST_TO_GREATEST);
		PrintList(pList, GREATEST_TO_LEAST);

		// Move cursor down one line
		printf("\n");
	}

	// There is nothing in the list. 
	else
	{
		// Print the list is empty to the screen
		CenterString(stdout, "* * * LIST IS EMPTY * * *", SCREEN_WIDTH);
	}


	FreeTheList(&pList);

	// Print message to the screen	
	printf("\nPrint the list after freeing all the data:\n\n");

	// Check to see if there is anything in the list
	if (!IsEmpty(pList)) // <-- Since we just freed the list, this should fail.
	{
		PrintList(pList, LEAST_TO_GREATEST);
		// PrintList(pList, GREATEST_TO_LEAST);

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
int IsEmpty(linkList* pList)
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
void CreateList(linkList** pList)
{
	int input;
	linkList* pTemp;

	linkList* pPrev;
	linkList* pCurrent;

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
			pTemp = (linkList*)malloc(sizeof(linkList));

			CreateNode(pTemp, input);

			FindLocation(*pList, &pCurrent, &pPrev, pTemp->record.number);

			InsertNewNode(pList, pCurrent, pPrev, pTemp);

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
void FindLocation(linkList* pList, linkList** pCurrent, linkList** pPrev, int value)
{
	int done = FALSE;

	// Assign pCurrent to the list
	*pCurrent = pList;

	// Check to see if our link list is empty
	if (!IsEmpty(pList))
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
void InsertNewNode(linkList** pList, linkList* pCurrent, linkList* pPrev, linkList* pTemp)
{
	// Check to see if the list is empty
	if (IsEmpty(*pList))
	{
		// Start the link list by pointing to a new node
		*pList = pTemp;

		printf("\nCASE 1: - There was no list -\n\n");
	}

	// We have a new max value 
	else if (pTemp->record.number > pCurrent->record.number)
	{
		// Add new node to the end of the list
		pCurrent->pNext = pTemp;

		printf("\nCASE 2: - We have a new MAX value -\n\n");

	}

	// If previous is NULL and we don't have a new max, 
	// then we have a new min value
	else if (pPrev == NULL)
	{
		// Place the new node before the first node
		pTemp->pNext = *pList;
		*pList = pTemp;

		printf("\nCASE 3: - We have a new MIN value -\n\n");
	}
	
	// Place the new node between the previous and the current.
	else
	{
		// Add new node between the previous and the current
		pTemp->pNext = pCurrent;
		pPrev->pNext = pTemp;

		printf("\nCASE 4: - Inserted in the MIDDLE -\n\n");

	}

}


//-----------------------------------------------------------------------------
// Function Name:CreateNode
// Description:
//   Both members of the new node will be initialized. 
//
//-----------------------------------------------------------------------------
void CreateNode(linkList* pNewNode, int input)
{
	// Assign members of the new node
	pNewNode->record.number = input;
	pNewNode->pNext = NULL;
}


//-----------------------------------------------------------------------------
// Function Name:PrintList
// Description:
//  This function will take the pointer to our link list. 
//  Since the address will not be changing there is no reason for a double 
//  pointer. 
//
//  Every item of the link list will be printed to the screen
//
//-----------------------------------------------------------------------------
void PrintList(linkList* pList, orderType order)
{
	if (!IsEmpty(pList) && order == LEAST_TO_GREATEST)
	{
		// Print the number of the current number
		printf("%5d", pList->record.number);
	}

	// Check to see if the list is empty
	if (!IsEmpty(pList))
	{
		// Print message to the screen
		PrintList(pList->pNext, order);
	}

	if (!IsEmpty(pList) && order == GREATEST_TO_LEAST)
	{
		// Print the number of the current number
		printf("%5d", pList->record.number);
	}
}


//-----------------------------------------------------------------------------
// Function Name: FreeTheList
// Description:
//  This function will delete every node in the link list
//
//-----------------------------------------------------------------------------
void FreeTheList(linkList** pList)
{
	linkList* pTemp;

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
