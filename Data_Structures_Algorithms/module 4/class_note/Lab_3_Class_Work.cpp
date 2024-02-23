
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 50

#define DASH '-'
#define STAR '*'
#define SCREEN_WIDTH 80
#define TABLE_WIDTH 50


void CloseFiles(FILE** file1, FILE** file2);
void OpenFile(FILE** filePointer, const char message[], const char type[]);


class lab3Type
{
public:

	lab3Type(void) { arrayCounter1 = arrayCounter3 = 0;  }

	void FillArray(FILE* pFin, int code);

	void PrintArray(FILE* pOutput, int code);


private:
	void PrintArrayHeader(FILE* pOutput, const char message[]);
	void PrintData(FILE* pOutput, int currentArray[], int arrayCounter);

	void CenterString(FILE* pOutput, const char string[], int lengthToCenterAcross);
	void PrintDivider(FILE* pOutput, char symbol, int numberOf);

	int array1[ARRAY_SIZE];
	int arrayCounter1;

	int array2[ARRAY_SIZE];

	int array3[ARRAY_SIZE];
	int arrayCounter3;

};

int main(void)
{
	FILE* pFin1;
	FILE* pFin3;
	FILE* pFout;

	OpenFile(&pFin1, "Enter file name for array 1:", "r");
	OpenFile(&pFin3, "Enter file name for array 3:", "r");
	OpenFile(&pFout, "Enter file name for output:", "w");
	
	lab3Type lab;

	lab.FillArray(pFin1, 1);
	lab.FillArray(pFin3, 3);

	lab.PrintArray(pFout, 1);



	return 0;
}


//-----------------------------------------------------------------------------
// Function Name: OpenFile
// Description:
//  This function will prompt the user for a file and open the file
//
//  Because FILE is a pointer and we want to change the value of the address
//  we will need to use a double pointer. 
// 
//  The double pointer uses ** in the parameters. 
//-----------------------------------------------------------------------------
void OpenFile(FILE** filePointer,  const char message[], const char type[])
{
	char fileName[30];

	printf("%s", message);

	// Check to see if one string was read in
	if (scanf("%s", fileName) == 1)
	{
		// Because fileName is a double pointer, we must dereference it 
		*filePointer = fopen(fileName, type);
	}

}


//-----------------------------------------------------------------------------
// Function Name:CloseFiles
// Description:
//  This function will close both files
//
//  Because FILE is a pointer and we want to change the value of the address
//  we will need to use a double pointer. 
// 
//  The double pointer uses ** in the parameters.
//-----------------------------------------------------------------------------
void CloseFiles(FILE** file1, FILE** file2)
{
	// Check to see if file1 is valid
	if (*file1 != NULL)
	{
		// Close file1
		fclose(*file1);
	}

	// Check to see if file2 is valid
	if (*file2 != NULL)
	{
		// Close file2
		fclose(*file2);
	}
}


//-----------------------------------------------------------------------------
// Function Name:FillArray
// Description:
//  This function will fill the array with integers read in from the input 
//  file. 
//
//-----------------------------------------------------------------------------
void lab3Type::FillArray(FILE* pFin, int code)
{
	int value;
	int dataReadIn;
	int* pCounter;
	int* pArray;

	if (code == 1)
	{
		// Set pointers for the function
		pCounter = &arrayCounter1;
		pArray = array1;

	}
	else
	{
		// Set pointers for the function
		pCounter = &arrayCounter3;
		pArray = array3;
	}

	if (pFin == NULL)
	{
		// Print message to the screen
		printf("\nFile does not exist\n");
	}
	else
	{
		// Primer - attempt to read in a value
		dataReadIn = fscanf(pFin, "%d", &value);

		// Check to see if the file is empty
		if (dataReadIn == -1)
		{
			// Print message to the screen
			printf("File exist, but it is empty\n\n");
		}

		while (dataReadIn == 1 && *pCounter < ARRAY_SIZE)
		{
			// Assign the value to an element of the array
			pArray[*pCounter] = value;

			// Increase the number of elements by one
			(*pCounter)++;

			// Changer - attempt to read in another value
			dataReadIn = fscanf(pFin, "%d", &value);
		}

	}
}

//-----------------------------------------------------------------------------
// Function Name: objectType::PrintArray
// Description:
//   This method will be the driver for printing the array 
//
//-----------------------------------------------------------------------------
void lab3Type::PrintArray(FILE* pOutput, int code)
{
	if (code == 1)
	{
		//  Call private methods
		PrintArrayHeader(pOutput, "Array 1");
		PrintData(pOutput, array1, arrayCounter1);
	}

	
	
}


//-----------------------------------------------------------------------------
// Function Name: objectType::PrintArrayHeader
// Description:
//   The method will print the header for the array output
//
//-----------------------------------------------------------------------------
void lab3Type::PrintArrayHeader(FILE* pOutput, const char message[])
{
	PrintDivider(pOutput, DASH, TABLE_WIDTH);

	CenterString(pOutput, message, TABLE_WIDTH);

	PrintDivider(pOutput, DASH, TABLE_WIDTH);

}


//-----------------------------------------------------------------------------
// Function Name: objectType::PrintData
// Description:
//   This method will print the array
//
//-----------------------------------------------------------------------------
void lab3Type::PrintData(FILE* pOutput, int currentArray[], int arrayCounter)
{
	int NUMBER_PER_LINE = 2;

	for (int index = 0; index < arrayCounter; index++)
	{
		// Print element of the array to the output source
		fprintf(pOutput, "%5d", currentArray[index]);

		// Check to see if we need an enter key
		if ((index + 1) % NUMBER_PER_LINE == 0)
		{
			// Print the enter key
			fprintf(pOutput, "\n");
		}
	}

	// Print the enter key
	fprintf(pOutput, "\n");
}

//-----------------------------------------------------------------------------
// Function Name: objectType::PrintDivider
// Description:
//   Symbols will be printed to the screen. 
//
//-----------------------------------------------------------------------------
void lab3Type::PrintDivider(FILE* pOutput, char symbol, int numberOf)
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
// Function Name: objectType::CenterString
// Description:
//   The array of characters passed into the function will be centered
//  across the screen using the following formula:
//  
//    (lengthToCenterAcross + the string length) / 2
//
//-----------------------------------------------------------------------------
void lab3Type::CenterString(FILE* pOutput, const char string[], int lengthToCenterAcross)
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
