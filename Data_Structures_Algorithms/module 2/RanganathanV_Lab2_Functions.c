#include "RanganathanV_Lab2.h"

//-----------------------------------------------------------------------------
// Function Name: PrintHeader
// Description:
//   This function will call the functions needed to print a header to the 
//  screen. 
//
//-----------------------------------------------------------------------------
void PrintHeader(FILE* pOutput)
{
	fprintf(pOutput, "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣤⣀⣀\n");
	fprintf(pOutput, "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⠿⠿⠟\n");
	fprintf(pOutput, "⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⣀⣀⣤⣴⣶⣶⣶⣤⣿⡿⠁⠀⠀⠀\n");
	fprintf(pOutput, "⣀⠤⠴⠒⠒⠛⠛⠛⠛⠛⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀\n");
	fprintf(pOutput, "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⣿⣿⣿⡟⠻⢿⡀⠀⠀⠀⠀⠀\n");
	fprintf(pOutput, "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⢿⣿⠟⠀⠸⣊⡽⠀⠀⠀⠀⠀\n");
	fprintf(pOutput, "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⣿⡁⠀⠀⠀⠉⠁⠀⠀⠀⠀⠀\n");
	fprintf(pOutput, "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⠿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");

	// Call function to print a divider to the screen
	PrintDivider(pOutput, STAR, SCREEN_WIDTH);

	// Call functions to print three strings to center to the screen
	CenterString(pOutput, SCHOOL, SCREEN_WIDTH);
	CenterString(pOutput, PROGRAMMER, SCREEN_WIDTH);
	CenterString(pOutput, LAB, SCREEN_WIDTH);

	// Call function to print a divider to the screen
	PrintDivider(pOutput, STAR, SCREEN_WIDTH);

} // End PrintHeader


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
void CenterString(FILE* pOutput, char string[], int lengthToCenterAcross)
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
// Function Name: CloseFiles
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
} // End CloseFiles

//-----------------------------------------------------------------------------
// Function Name: ReadDataFromFile
// Description:
//  This function will fill the array with integers read in from the input 
//  file. 
//
//-----------------------------------------------------------------------------
void ReadDataFromFile(FILE* pFin, int intArray[], int* arrayCounter)
{
	int value;
	int dataReadIn;

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

		while (dataReadIn == 1 && *arrayCounter < MAX)
		{
			// Assign the value to an element of the array
			intArray[*arrayCounter] = value;

			// Increase the number of elements by one
			(*arrayCounter)++;

			// Changer - attempt to read in another value
			dataReadIn = fscanf(pFin, "%d", &value);
		}

	}
} // END ReadDataFromFile

//-----------------------------------------------------------------------------
// Function Name: FillArrayWithRandomNumbers
// Description:
//   Every element of the array will be assigned a value between 0 and 500.
//
//-----------------------------------------------------------------------------
void FillArrayWithRandomNumbers(int intArray[])
{
	// declare time variable
	time_t t;

	// initialize random number generator to clock so new numbers generated
	// each time code is run
	srand((unsigned int) time(&t));

	for (int index = 0; index < MAX; index++)
	{		
		// Set each element of the array to a number between 0 and 500
		intArray[index] = rand() % 500 + 1;
	}
} // END FillArrayWithRandomNumbers

//-----------------------------------------------------------------------------
// Function Name:PrintArray
// Description:
//  This function will print the contents of the integer array in rows of 10
// 
//  Because FILE is a pointer and we want to change the value of the address
//  we will need to use a double pointer. 
// 
//  The double pointer uses ** in the parameters.
//-----------------------------------------------------------------------------
void PrintArray(FILE * pFout, const int intArray[], int arrayCounter)
{
	int counter = 1;
	
	PrintDivider(pFout, DASH, TABLE_WIDTH+2);
	
	CenterString(pFout, "Array Contents", TABLE_WIDTH+2);
	
	PrintDivider(pFout, DASH, TABLE_WIDTH+2);

	// print column
	for (int index = 1; index < 11; index++)
	{
		fprintf(pFout, "   C%d", index);
	}
	
	// primer for row
	fprintf(pFout, "\nR%d", counter);

	for (int index = 0; index < arrayCounter; index++)
	{
		// Print one integer to the screen in a width of 5 and right justified
		fprintf(pFout, "%5d", intArray[index]);

		// Check to see if 10 integers have been printed
		if ((index + 1) % 10 == 0)
		{
			if (counter < arrayCounter / 10 || arrayCounter < MAX)
			{
				// Move the cursor down to the next line and print row number
				fprintf(pFout, "\nR%d", ++counter);
			}
		}
	}

	// Move the cursor down two lines
	fprintf(pFout, "\n\n");
} // END PrintArray

//-----------------------------------------------------------------------------
// Function Name: CountEvenOddNumbers
// Description: function takes in intArray, pointers isEven & isOdd, then updates
// the values based on how many even/odd elements there are in the array
//
//-----------------------------------------------------------------------------
void CountEvenOddNumbers(int intArray[], int* isEven, int* isOdd)
{
	// declare and initliaze to zero integer variables to store count of even and odd numbers in array
	int even = 0;
	int odd = 0;

	// loop through array until MAX value is reached
	for (int index = 0; index < MAX; index++)
	{
		// check if array value is even
		if (intArray[index] % 2 == 0)
		{
			// increment even counter
			even++;
		}

		// else assume array is odd
		else
		{
			// increment odd counter
			odd++;
		}
	}

	// update pointer values for even and odd
	*isEven = even;
	*isOdd = odd;
} // END CountEvenOddNumbers

//-----------------------------------------------------------------------------
// Function Name: TotalArray
// Description: totals all numbers in array
//
//
//-----------------------------------------------------------------------------
int TotalArray(int intArray[])
{
	// declare and initialize to zero array total variable
	int totalArrayNums = 0;

	// loop through array until MAX value is reached
	for (int index = 0; index < MAX; index++)
	{
		// keep rolling tally of value of array
		totalArrayNums = totalArrayNums + intArray[index];
	}
	return totalArrayNums;
} // END TotalArray

//-----------------------------------------------------------------------------
// Function Name: CalculateAverage
// Description: calculates and returns the average value of the elements in the array
// uses arrayCounter value for divisor
//
//-----------------------------------------------------------------------------
double CalculateAverage(int intArray[], int arrayCounter)
{
	// declare and initialize to zero array total variable
	double average = 0;

	// check if dividing by zero, return 0 if true
	if (arrayCounter == 0)
	{
		return 0;
	}

	else
	{
	// calculates average from TotalArray function divided by the arrayCounter value
	average = TotalArray(intArray) / arrayCounter;

	// returns calculated average
	return average;
	}
} // END CalculateAverage

//-----------------------------------------------------------------------------
// Function Name: CountNumberAboveAverage
// Description: counts and returns the number of elements that have values
// greater than the average value of the elements in the array
//
//-----------------------------------------------------------------------------
int CountNumberAboveAverage(int intArray[], int arrayCounter)
{
	int count = 0;

	for (int index = 0; index < MAX; index++)
	{
		if (CalculateAverage(intArray, arrayCounter) < (double)intArray[index])
		{
			count++;
		}
	}

	return count;
} // END CountNumberAboveAverage

//-----------------------------------------------------------------------------
// Function Name: PrintResults
// Description: need to pass in isEven & isOdd since the CountEvenOddNumbers
// function doesn't return a value; prints results to output file
//
//-----------------------------------------------------------------------------
void PrintResults(FILE* pFout, int intArray[], int arrayCounter, int isEven, int isOdd)
{
	fprintf(pFout, "even numbers = %d\n", isEven);
	fprintf(pFout, "odd numbers = %d\n", isOdd);
	fprintf(pFout, "total value of array = %d\n", TotalArray(intArray));
	fprintf(pFout, "average value in array = %0.3lf\n", CalculateAverage(intArray, arrayCounter));
	fprintf(pFout, "# elements > array average = %d\n",CountNumberAboveAverage(intArray, arrayCounter));
} // END PrintResults

//-----------------------------------------------------------------------------
// Function Name: assignArray (Extra Credit)
// Description: this function takes in an array and arrayCounter pointer. Need
// pointer bc value will be changed in function and sent to other functions to
// be used. function initializes the first element of the array to 1500 using a
// macro, then uses an algorithm to set the next element's value based on
// whether the previous element was an even or odd integer. this loops while
// the previous element value doesn't equal one and the arrayCounter value 
// hasn't reached the max value set
//-----------------------------------------------------------------------------
void assignArray(int intArray[], int* arrayCounter)
{
	// reset arrayCounter pointer to zero prior to populating array elements with dummy values
	*arrayCounter = 0;

	// loops through array elements and initializes all elements to zero to start
	// need to do this to avoid having values created by stack allocation
	while (*arrayCounter < MAXER)
	{
		intArray[*arrayCounter] = 0;
		(*arrayCounter)++;
	}
	
	// initialize arrayCounter pointer to one to reset value
	*arrayCounter = 1;

	// set initial value of array
	intArray[0] = MAXERER;
	
	// loop through algorithm until terminating conditions reached
	while (intArray[*arrayCounter - 1] != 1 && *arrayCounter < MAXER)
	{
		if (intArray[*arrayCounter - 1] % 2 == 0)
		{
			intArray[*arrayCounter] = intArray[*arrayCounter - 1] / 2;
			(*arrayCounter)++;
		}

	 	else
		{
			intArray[*arrayCounter] = 3 * intArray[*arrayCounter - 1] + 1;
			(*arrayCounter)++;
		}
	}
}