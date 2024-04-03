/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Written by Prof. Foos
| Course:           CS-212: Data Structures for Engineers
| Program  Name:    Simple Link List
| Date:             12/12/2022 (Updated 3/6/2024)
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|  This program will allow the user to enter integer values and place those numbers at the front
| of the link list.
|
|   This program will call functions to complete the following tasks:
|     - Create a link list
|     - Print the link list to the screen
|     - Free (or delete) the link list
|     - Print the link list, showing that the list is empty
|
|   For more assistance with this program read the provided notes:
|     Notes for the Simple Link List Program.docx
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
|--------------------------------------------------------------------------------------------------
| Outputs:
|   The link list will be printed to the screen.
|   After the link list is destroyed a message will be displayed to the screen stating that
|   the list is empty.
|
|--------------------------------------------------------------------------------------------------
*/

#include "SimpleLinkList.h"

int main(void)
{

	// Create a pointer for our linked list
	// Assign the pointer to NULL
	linkList* pFirst = NULL; // pFirst will always point to the first node
	// always intialize pointer to NULL

	// stdout will be pass in as the file stream, this will print to the screen
	PrintHeader(stdout);

	/*
	| NOTE:
    |
	|  When creating a link list, the value of the pointer will be changing.
    |
	|  Therefore, you will need pass the address of the pointer.
    |
    |  The function header will have a double pointer as a parameter.
    |
	*/

	// We will pass in the address of a pointer, this is a double pointer
	CreateList(&pFirst);


    printf("\n\n");
    CenterString(stdout, "* * * Print the list after entering all the data * * *", SCREEN_WIDTH);
	printf("\n\n");
	
	
    // Check to see if there is anything in the list
	if (!IsEmpty(pFirst))
	{
		//PrintList_WithoutRecursion(pFirst);
        //PrintList_WithRecursion_BeginningOfListFirst(pFirst);
        PrintList_WithRecursion_EndOfListFirst(pFirst);

		// Move the cursor down one line
		printf("\n");
	}
	
	// There is nothing in the list. 
	else
	{
		// Print the list is empty to the screen
		CenterString(stdout, "* * * LIST IS EMPTY * * *", SCREEN_WIDTH);
	}


    // Every node in the link list will be removed from memory
	FreeTheList(&pFirst);


    printf("\n\n");
	CenterString(stdout, "* * * Print the list after freeing all the data * * *", SCREEN_WIDTH);
	printf("\n\n");


    // Check to see if there is anything in the list
	if (!IsEmpty(pFirst))
	{
		PrintList_WithoutRecursion(pFirst);
        // PrintList_WithRecursion_BeginningOfListFirst(pFirst);
        // PrintList_WithRecursion_EndOfListFirst(pFirst);

		// Move the cursor down one line
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

	// Move cursor down one line
	printf("\n");

} // End PrintHeader


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

	for(int counter = 0; counter < numberOfBlankSpaces; counter++)
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
int IsEmpty(linkList* pFirst)
{
	// Check to see if the link list is empty
	return pFirst == NULL;
}


//-----------------------------------------------------------------------------
// Function Name:CreateList
// Description:
//    This function will do the following:
//      - Ask the user for an integer
//      - Create a new node in memory
//      - Insert the new node into a link list
//
//    This will continue until the user enters a 0
//-----------------------------------------------------------------------------
void CreateList(linkList** pFirst)
{
	int input;
	linkList* pTemp;

	do
	{
		// Enter a number to put into the list
		printf("Enter a number (zero to stop): ");
		scanf("%d", &input);

		if (input != 0)
		{
			// Create a new node
			pTemp = (linkList*)malloc(sizeof(linkList));

			// A double pointer is not needed here becuase we are not changing the address. 
			// Instead, we are changeing the values pointed to by the address. 
			InitializeNode(pTemp, input); // only need double pointer when you want to change address
			
			InsertNewNode(pFirst, pTemp);
		}

	} while (input != 0);

}


//-----------------------------------------------------------------------------
// Function Name:CreateNode
// Description:
//   Both members of the new node will be initialized. 
//   The integer in the node will be initialized to the number we entered 
//  from the keyboard.
// 
//   The pointer pNext will be initialzied to NULL.
//
//-----------------------------------------------------------------------------
void InitializeNode(linkList* pTemp, int input)
{
	// Assign members of the new node
	pTemp->record.number = input; // set number equal to input
	pTemp->pNext = NULL; // set next pointer to NULL
}


//-----------------------------------------------------------------------------
// Function Name:InsertNewNode
// Description:
//   A new node will be inserted to our link list
//
//-----------------------------------------------------------------------------
void InsertNewNode(linkList** pFirst, linkList* pTemp)
{
	//-----------------------------------------------------------
	// pFirst points to something. 
	// 
	// The first time in this function, pFirst points to NULL 
	// Everytime after, it points to a node.
	// 
	//                                --------
	//  pFirst -> NULL  or  pFirst -> | #  | |   
	//                                --------
	//----------------------------------------------------------- 
	
	//----------------------------------------------------------- 
	// pTemp points to our new node which hold the next number
	// to place in the list. 
	//
    //          --------
	// pTemp -> | #  |\|   
	//          --------
	//----------------------------------------------------------- 

	// Assign the next pointer to the beggining of the list
	pTemp->pNext = *pFirst; // de-reference pFirst bc it's a double pointer

	//----------------------------------------------------------- 
    // pTemp->pNext points to the front of the list
	// 
	//              pFirst -
	//                     \
    //          --------     --------
    // pTemp -> | #  |*| ->  | #  |\|
    //          --------     --------
    //----------------------------------------------------------- 

	// Assign the list pointer to temp
	*pFirst = pTemp;

	//----------------------------------------------------------- 
    // pFirst points to the front of the list
    // 
    // pFirst -
    //        \
    //          --------     --------
	// pTemp -> | #  |*| ->  | #  |\|
	//          --------     --------
	//----------------------------------------------------------- 

	// pTemp is no longer needed and is free to be overwritten

}


//-----------------------------------------------------------------------------
// Function Name: FreeTheList
// Description:
//  This function will delete every node in the link list
//
//-----------------------------------------------------------------------------
void FreeTheList(linkList** pFirst)
{
	linkList* pTemp;

	while (*pFirst != NULL)
	{
		// Assign pTemp to pFirst
		pTemp = *pFirst;

		//----------------------------------------------------------- 
		// pTemp -
		//        \
		//          --------     --------
		// pFirst -> | #  |*| ->  | #  |\|
		//          --------     --------
		//----------------------------------------------------------- 

		// Move pFirst to the next element
		*pFirst = (*pFirst)->pNext;

		//----------------------------------------------------------- 
		//              pFirst -
		//                     \
		//          --------     --------
		// pTemp -> | #  |*| ->  | #  |\|
		//          --------     --------
		//----------------------------------------------------------- 

		// Delete pTemp
		free(pTemp);
	}
}

//-----------------------------------------------------------------------------
// Function Name:PrintList_WithoutRecursion
// Description:
//  This function will accept the the pointer to our link list as a parameter.
//  Since the address will not be changing there is no reason for a double 
//  pointer. 
//
//  A temp pointer will be created and used to cycle through the link list
//  printing every item in the list. 
//
//-----------------------------------------------------------------------------
void PrintList_WithoutRecursion(linkList* pFirst)
{
	// Assign a temp pointer to the beginning of our list
	linkList* pTemp = pFirst;

	while (pTemp != NULL)
	{
		// Print the number of the current number
		printf("%5d", pTemp->record.number); // %5d means right-justified 5 spaces

		// Move pointer to the next number in the list
		pTemp = pTemp->pNext;
	}

}


//-----------------------------------------------------------------------------
// Function Name:PrintList_WithRecursion_BeginningOfListFirst
// Description:
//  This function will accept the the pointer to our link list as a parameter.
//  Since the address will not be changing there is no reason for a double 
//  pointer. 
//
//  This function will print the number first, then call the function 
//  recursively. 
//
//-----------------------------------------------------------------------------
void PrintList_WithRecursion_BeginningOfListFirst(linkList* pFirst)
{
	if (!IsEmpty(pFirst))
	{
		// Print the number of the current number
		printf("%5d", pFirst->record.number);
	}

	// Check to see if the list is empty
	if (!IsEmpty(pFirst))
	{
		// Print message to the screen
		PrintList_WithRecursion_BeginningOfListFirst(pFirst->pNext);
	}

}


//-----------------------------------------------------------------------------
// Function Name:PrintList_WithRecursion_BeginningOfListFirst
// Description:
//  This function will accept the the pointer to our link list as a parameter.
//  Since the address will not be changing there is no reason for a double 
//  pointer. 
//
//  This function will then call the function recursively first and then 
//  print the number.
//
//-----------------------------------------------------------------------------
void PrintList_WithRecursion_EndOfListFirst(linkList* pFirst)
{
	// Check to see if the list is empty
	if (!IsEmpty(pFirst))
	{
		// Print message to the screen
		PrintList_WithRecursion_EndOfListFirst(pFirst->pNext);
	}
	
	if (!IsEmpty(pFirst))
	{
		// Print the number of the current number
		printf("%5d", pFirst->record.number);
	}

}