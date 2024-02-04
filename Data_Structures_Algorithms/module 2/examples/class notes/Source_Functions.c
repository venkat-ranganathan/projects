
#include "Source.h"

void CloseFile(FILE** pFile)
{
	// Check that the file was properly opened
	if (*pFile != NULL)
	{
		// Close file
		fclose(*pFile);
	}

}
void OpenFile(FILE** pFile, char fileName[], char type[])
{
	// Open file
	*pFile = fopen(fileName, type);

}
void ReadDataFromFile(FILE* inputFile, int array[], int* pTag)
{
	int value;

	// Set tag to 0
	*pTag = 0;

	if (inputFile != NULL)
	{
		// Primer - Attempt to read in one value
		fscanf(inputFile, "%d", &value);

		while (!feof(inputFile) && *pTag < SIZE)
		{
			// Assign value to the array
			array[*pTag] = value;

			// Increase the tag
			(*pTag)++;

			// Changer - Attempt to read in one value
			fscanf(inputFile, "%d", &value);

		}

	}
	else
	{
		// Print message that file did not open
		printf("File didn't open\n");
	}
}

void PrintArray(FILE* output, const int array[], int tag)
{
	for (int counter = 0; counter < tag; counter++)
	{
		// Print an element of your array in a width of 5, left-justified. 
		fprintf(output, "%-5d", array[counter]);

		// Check to see if there have been 5 numbers printed to the screen
		if ((counter + 1) % 5 == 0)
		{
			// Print the enter key
			fprintf(output, "\n");
		}
	}

}