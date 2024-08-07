#include "RanganathanV_Lab8.h"

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
	// Initialize LCV (Loop Control Variable) to 0
	int counter = 0;

	// Print a bunch of symbols across the screen
	while (counter < numberOf)
	{
		// Print one character to the screen
		fprintf(pOutput, "%c", symbol);

		// Increment counter
		counter++;
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
void CenterString(FILE* pOutput, const char string[], int lengthToCenterAcross)
{
	// Capture how long the string is
	// Cast to an integer because strlen technically returns size_t
	int stringLength = (int)strlen(string);

	// Calculate the width to print the string in
	int width = (lengthToCenterAcross + stringLength) / 2;

	// Calculate how many blank spaces are needed before printing the string
	int numberOfBlankSpaces = width - stringLength;

	// Initialize LCV (Loop Control Variable) to 0
	int counter = 0;

	// Print the spaces needed to center the string
	while (counter < numberOfBlankSpaces)
	{
		// Print one space
		fprintf(pOutput, " ");

		// Increment counter
		counter++;
	}

	// Print the string
	fprintf(pOutput, "%s\n", string);
}


//-----------------------------------------------------------------------------
// Function Name: OpenFiles
// Description:
//   All data files are opened.
//
//-----------------------------------------------------------------------------
void OpenFiles(FILE** pFin, FILE** pFoutPre, FILE** pFoutIn, FILE** pFoutPost)
{
	// Open files
	*pFin = fopen("Letters.txt", "r");
	*pFoutPre = fopen("PreOutput.txt", "w");
	*pFoutIn = fopen("InOutput.txt", "w");
	*pFoutPost = fopen("PostOutput.txt", "w");
}


//-----------------------------------------------------------------------------
// Function Name: CloseFiles
// Description:
//   All data files are closed
//
//-----------------------------------------------------------------------------
void CloseFiles(FILE** pFin, FILE** pFoutPre, FILE** pFoutIn, FILE** pFoutPost)
{
	// Check to see if the input file pointer is valid
	if (*pFin != NULL)
	{
		// Close the input file
		fclose(*pFin);
	}

	// Check to see if the output file pointer is valid
	if (*pFoutPre != NULL)
	{
		// Close the output file
		fclose(*pFoutPre);
	}

	// Check to see if the output file pointer is valid
	if (*pFoutIn != NULL)
	{
		// Close the output file
		fclose(*pFoutIn);
	}

	// Check to see if the output file pointer is valid
	if (*pFoutPost != NULL)
	{
		// Close the output file
		fclose(*pFoutPost);
	}
}


//-----------------------------------------------------------------------------
// Function Name: ReadDataInFromFile
// Description:
//   Data will be read in from an input file and will be stored in a binary 
//  tree. 
//
//-----------------------------------------------------------------------------
void ReadDataInFromFile(FILE* pFin, node** pRoot)
{
	char newLetter;
	char ignore;
	node* pNewNode;

	if (pFin == NULL)

	{
		// Print message to the screen
		printf("No file has opened\n");
	}
	else
	{
		while (fscanf(pFin, "%c", &newLetter) == 1)
		{
			// Ignore the end line character
			fscanf(pFin, "%c", &ignore);

			while (ignore != '\n' && ignore != 13)
			{
				// Ignore the end line character
				fscanf(pFin, "%c", &ignore);
			}

			// Create a new node 
			pNewNode = (node*)malloc(sizeof(node));

			CreateNode(pNewNode, newLetter);

			InsertNode(pRoot, &pNewNode);
		}
	}
}


//-----------------------------------------------------------------------------
// Function Name: CreateNode
// Description:
//  Members of a new node will be initialized
//
//-----------------------------------------------------------------------------
void CreateNode(node* pNewNode, char newLetter)
{
	// Assign new data to the new node
	pNewNode->record.integer = newLetter;

	// Set new pointers to NULL
	pNewNode->pLeft = NULL;
	pNewNode->pRight = NULL;
}


//-----------------------------------------------------------------------------
// Function Name: IsTreeEmpty
// Description:
//   This function will return true if a tree is empty and false if it is not.
//
//-----------------------------------------------------------------------------
int IsTreeEmpty(node* pRoot)
{
	return pRoot == NULL;
}


//-----------------------------------------------------------------------------
// Function Name: InsertNode
// Description:
//   A new node will be inserted into the tree following the criteria of a 
//  Binary Search Tree (BST)
//
//-----------------------------------------------------------------------------
void InsertNode(node** pRoot, node** pNewNode)
{
	node* pParent;
	node* pCurrent;


	// Check to see if the root is NULL
	if (IsTreeEmpty(*pRoot))
	{
		// Assign the first node of our tree
		*pRoot = *pNewNode;
	}
	else
	{
		// Start searching at the root node
		pParent = NULL;
		pCurrent = *pRoot;

		while (pCurrent != NULL)
		{
			if ((*pNewNode)->record.integer <= pCurrent->record.integer)
			{
				// Update pParent and pCurrent pointers
				pParent = pCurrent;
				pCurrent = pCurrent->pLeft;
			}
			else
			{
				// Update pParent and pCurrent pointers
				pParent = pCurrent;
				pCurrent = pCurrent->pRight;
			}
		}

		if ((*pNewNode)->record.integer <= pParent->record.integer)
		{
			// Assign new node to the tree
			pParent->pLeft = *pNewNode;
		}
		else
		{
			// Assign new node to the tree
			pParent->pRight = *pNewNode;
		}

	}
}

//
//  -- Printing the Binary Search Tree (BST)  --
//


//-----------------------------------------------------------------------------
// Function Name: PrintPreOrder
// Description:
//   Print the tree using Pre Order Traverse 
//
//-----------------------------------------------------------------------------
void PrintPreOrder(FILE* pFout, node* pCurrentNode)
{
	if (pCurrentNode != NULL)
	{
		fprintf(pFout, "%c\n", pCurrentNode->record.integer);
		PrintPreOrder(pFout, pCurrentNode->pLeft);
		PrintPreOrder(pFout, pCurrentNode->pRight);
	}
}


//-----------------------------------------------------------------------------
// Function Name: PrintInOrder
// Description:
//   Print the tree using In Order Traverse 
//
//-----------------------------------------------------------------------------
void PrintInOrder(FILE* pFout, node* pCurrentNode)
{
	if (pCurrentNode != NULL)
	{
		PrintInOrder(pFout, pCurrentNode->pLeft);
		fprintf(pFout, "%c\n", pCurrentNode->record.integer);
		PrintInOrder(pFout, pCurrentNode->pRight);
	}
}


//-----------------------------------------------------------------------------
// Function Name: PrintPostOrder
// Description:
//   Print the tree using Post Order Traverse 
//
//-----------------------------------------------------------------------------
void PrintPostOrder(FILE* pFout, node* pCurrentNode)
{
	if (pCurrentNode != NULL)
	{
		PrintPostOrder(pFout, pCurrentNode->pLeft);
		PrintPostOrder(pFout, pCurrentNode->pRight);
		fprintf(pFout, "%c\n", pCurrentNode->record.integer);
	}
}
