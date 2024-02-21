#include "RanganathanV_Lab3.h"

//-----------------------------------------------------------------------------
// Function Name: PrintHeader
// Description:
//   This function will call the functions needed to print a header to the 
//  screen. 
//
//-----------------------------------------------------------------------------
void PrintHeader(FILE* pOutput, int option)
{
	switch (option)
	{
		case 0:
			fprintf(pOutput, "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣤⣀⣀\n");
			fprintf(pOutput, "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⠿⠿⠟\n");
			fprintf(pOutput, "⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⣀⣀⣤⣴⣶⣶⣶⣤⣿⡿⠁⠀⠀⠀\n");
			fprintf(pOutput, "⣀⠤⠴⠒⠒⠛⠛⠛⠛⠛⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀\n");
			fprintf(pOutput, "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⣿⣿⣿⡟⠻⢿⡀⠀⠀⠀⠀⠀\n");
			fprintf(pOutput, "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⢿⣿⠟⠀⠸⣊⡽⠀⠀⠀⠀⠀\n");
			fprintf(pOutput, "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⣿⡁⠀⠀⠀⠉⠁⠀⠀⠀⠀⠀\n");
			fprintf(pOutput, "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⠿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");

			// Call function to print a divider to the screen
			PrintDivider(pOutput, STAR, SCREEN_WIDTH, 0);

			// Call functions to print three strings to center to the screen
			CenterString(pOutput, SCHOOL, SCREEN_WIDTH, option);
			CenterString(pOutput, PROGRAMMER, SCREEN_WIDTH, option);
			CenterString(pOutput, LAB, SCREEN_WIDTH, option);

			// Call function to print a divider to the screen
			PrintDivider(pOutput, STAR, SCREEN_WIDTH, 0);

			break;

		case 1:
			printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣤⣀⣀\n");
			printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⠿⠿⠟\n");
			printf("⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⣀⣀⣤⣴⣶⣶⣶⣤⣿⡿⠁⠀⠀⠀\n");
			printf("⣀⠤⠴⠒⠒⠛⠛⠛⠛⠛⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀\n");
			printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⣿⣿⣿⡟⠻⢿⡀⠀⠀⠀⠀⠀\n");
			printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⢿⣿⠟⠀⠸⣊⡽⠀⠀⠀⠀⠀\n");
			printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⣿⡁⠀⠀⠀⠉⠁⠀⠀⠀⠀⠀\n");
			printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⠿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");

			// Call function to print a divider to the screen
			//PrintDividerScreen(STAR, SCREEN_WIDTH);
			PrintDivider(pOutput, STAR, SCREEN_WIDTH, 1);
			// Call functions to print three strings to center to the screen
			CenterString(pOutput, SCHOOL, SCREEN_WIDTH, option);
			CenterString(pOutput, PROGRAMMER, SCREEN_WIDTH, option);
			CenterString(pOutput, LAB, SCREEN_WIDTH, option);

			// Call function to print a divider to the screen
			//PrintDividerScreen(STAR, SCREEN_WIDTH);
			PrintDivider(pOutput, STAR, SCREEN_WIDTH, 1);
			break;
	}


} // End PrintHeader


//-----------------------------------------------------------------------------
// Function Name: PrintDivider
// Description:
//   Symbols will be printed to the output file. 
//
//-----------------------------------------------------------------------------
void PrintDivider(FILE* pOutput, char symbol, int numberOf, int option)
{
	// Initialize LCV (Loop Control Variable) to 0
	int counter = 0;

	switch (option)
	{
		case 0:
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
			break;

		case 1:
			// Print a bunch of symbols across the screen
			while (counter < numberOf)
			{
				// Print one character to the screen
				printf("%c", symbol);

				// Increment counter
				counter++;
			}

			// Move the cursor down to the next line
			printf("\n");
			break;
	}
} // END PrintDivider


//-----------------------------------------------------------------------------
// Function Name: CenterString
// Description:
//   The array of characters passed into the function will be centered
//  across the screen using the following formula:
//  
//    (lengthToCenterAcross + the string length) / 2
//
//-----------------------------------------------------------------------------
void CenterString(FILE* pOutput, char string[], int lengthToCenterAcross, int option)
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

	switch (option)
	{
		case 0:
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

			break;
			
		case 1:
			// Print the spaces needed to center the string
			while (counter < numberOfBlankSpaces)
			{
				// Print one space
				printf(" ");

				// Increment counter
				counter++;
			}

			// Print the string
			printf("%s\n", string);

			break;
	}
} // END CenterString

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
void OpenFile(FILE** filePointer, char message[], char type[])
{
	// filePointer is a double pointer, so need to dereference to access file
	*filePointer = fopen(message, type);

} // END OpenFile

//-----------------------------------------------------------------------------
// Function Name: CloseFile (single file)
// Description:
//  This function will close a single file
//
//  Because FILE is a pointer and we want to change the value of the address
//  we will need to use a double pointer. 
// 
//  The double pointer uses ** in the parameters.
//-----------------------------------------------------------------------------
void CloseFile(FILE** file)
{
	// Check to see if file is valid
	if (*file != NULL)
	{
		// Close file
		fclose(*file);
	}
} // END CloseFile

//-----------------------------------------------------------------------------
// Function Name: StarPatternFile
// Description:
//   This function will print a pattern of stars to an output 
//  file and will recursively print the pattern from 1 until the set number is reached
//  The program also includes an option to choose between printing to an output file or printing to the screen
//-----------------------------------------------------------------------------
void StarPattern(FILE * pFout, int number, int counter, int option) 
{ 
	if (number == 0)
	{
		return;
	}

	PrintDivider(pFout, STAR, counter, option);

	if (number > 1)
	{
		StarPattern(pFout, number - 1, counter + 1, option);
	}

} // END StarPatternFile

//-----------------------------------------------------------------------------
// Function Name: FillArrayWithRandomNumbers
// Description:
//   Every element of the array will be assigned a value between 0 and the number passed ot the function.
//
//-----------------------------------------------------------------------------
void FillArrayWithRandomNumbers(int intArray[], int maximum, int number)
{
	for (int index = 0; index < maximum; index++)
	{		
		// Set each element of the array to a number between 0 and number value
		intArray[index] = rand() % number + 1;
	}
} // END FillArrayWithRandomNumbers

//-----------------------------------------------------------------------------
// Function Name:PrintArray
// Description:
//  This function will print the contents of the integer array
// 
//  Because FILE is a pointer and we want to change the value of the address
//  we will need to use a double pointer. 
// 
//  The double pointer uses ** in the parameters.
//-----------------------------------------------------------------------------
void PrintArray(FILE * pFout, const int intArray[], int arrayCounter, int option)
{
	switch (option)
	{
		case 0:
			fprintf(pFout, "\n");

			for (int index = 0; index < arrayCounter; index++)
			{
				// Print one integer to the screen in a width of 5 and right justified
				fprintf(pFout, "%5d", intArray[index]);

				// Check to see if 2 integers have been printed
				if ((index + 1) % 2 == 0)
				{
					// Move the cursor down to the next line and print row number
					fprintf(pFout, "\n");
				}
			}

			// Move the cursor down two lines
			fprintf(pFout, "\n");
			break;

		case 1:		
			printf("\n");

			for (int index = 0; index < arrayCounter; index++)
			{
				// Print one integer to the screen in a width of 5 and right justified
				printf("%5d", intArray[index]);

				// Check to see if 2 integers have been printed
				if ((index + 1) % 2 == 0)
				{
					// Move the cursor down to the next line and print row number
					printf("\n");
				}
			}

			// Move the cursor down two lines
			printf("\n");
			break;
	}

} // END PrintArray

//-----------------------------------------------------------------------------
// Function Name: SumArray
// Description: function takes in an array and sums the conent of the array
//
//
//-----------------------------------------------------------------------------
int SumArray(int intArray[], int counter, int size)
{
	if (size <= 0)
	{
		return 0;
	}
		
	return (SumArray(intArray, counter, size - 1) + intArray[size - 1]);
} // END SumArray

//-----------------------------------------------------------------------------
// Function Name: PrintDigits
// Description: function prints digits to of a number recursively in the correct order
// the user selects whether to print to an output file or to the terminal
//
//-----------------------------------------------------------------------------
void PrintDigits(FILE* pFout, int number, int option)
{

	if (number <= 0)
	{
		return;
	}

	PrintDigits(pFout, number / 10, option);
	
	switch (option)
	{
		case 0:
			fprintf(pFout, "%d", number % 10);
			break;
		case 1:
			printf("%d", number % 10);
			break;
	}
} // END PrintDigits

//-----------------------------------------------------------------------------
// Function Name: QuickSort
// Description: function recursively sorts numbers in an array using the
// quick sort algorithm; uses Partition function to carry out sort
//
//-----------------------------------------------------------------------------
void QuickSort (int intArray[], int m, int n) /* to sort the subarray intArray[m:n of intArray into ascending order]*/
{
	int i, j;

	if (m < n) 
	{
		i = m; j = n; /* initially i and j point ot the first and last items */
		Partition(intArray, &i, &j); /* partitions intArray[m:n] into intArray[m:j] and intArray[i:n]*/
		QuickSort(intArray, m, j);
		QuickSort(intArray, i, n);
	}
} // END QuickSort

//-----------------------------------------------------------------------------
// Function Name: Partition
// Description: partition function carries out the actual quick sort algorithm
//
//
//-----------------------------------------------------------------------------
void Partition(int intArray[], int* i, int* j)
{
	int Pivot, Temp;

	Pivot = intArray[(*i + *j) / 2]; /* choose middle key as the pivot*/

	do {
		while (intArray[*i] < Pivot) (*i)++; /* find leftmost i such that intArray[i] >= Pivot */

		while (intArray[*j] > Pivot) (*j)--; /* find rightmost j such that intArray[j] <= Pivot */

		if (*i <= *j) /* if i and j didn't cross over one another, swap */
		{
			Temp = intArray[*i]; /* swapping values between intArray[i] & intArray[j]*/
			intArray[*i] = intArray[*j]; 
			intArray[*j] = Temp;

			(*i)++; /* move i one space right*/
			(*j)--; /* move j one space left*/
		}
	} while (*i <= *j); /* while i and j pointers haven't crossed yet*/
} // END Partition

//-----------------------------------------------------------------------------
// Function Name: ReverseDigitis
// Description: recursively prints digits of a number in reverse
//
//
//-----------------------------------------------------------------------------
int ReverseDigits(int number, int counter)
{
	if (number == 0)
		return counter;
	
	return (ReverseDigits(number / 10, counter * 10 + number % 10));
}
// END ReverseDigits