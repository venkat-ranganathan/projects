#include "PA.h"

int main(void)
{
	int selection;

	// Parallel arrays
	char name[MAX][STRING_SIZE];
	int rating[MAX];
	int highScore[MAX];

	// tag field
	int tagField = 0;

	do
	{

		DisplayMenu();

		selection = GetSelection();

		ExecuteSelection(selection, name, rating, highScore, &tagField);

	} while (selection != DONE);

	return 0;
}

void PrintDivider(char symbol, int length)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name:
// Inputs:
// Outputs:
// Description:
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	// Output divider to the screen
	for (int counter = 0; counter < length; counter++)
	{
		// Print one character to the screen
		printf("%c", symbol);
	}

	// Move cursor down one line
	printf("\n");
}

void ClearBuffer(char lastCharacter)
{
	// check to see if there data in the buffer
	if (lastCharacter != '\n')
	{
		// Clear the buffer
		while (getchar() != '\n')
			;
	}
}

void ReadStringFromKeybaord(char text[], int maxSize)
{
	char oneLetter;
	int index = 0;

	// Retrieve one lettter from the input buffer
	oneLetter = getchar();

	while (oneLetter != '\n' && index < maxSize - 1)
	{
		// Assign letter to the text
		text[index] = oneLetter;

		// Incrament index
		index++;

		// Retrieve one character from the input buffer
		oneLetter = getchar();
	}

	// Assign the null terminator to the string
	text[index] = '\0';

	// Move the cursor down one line
	printf("\n");

	ClearBuffer(oneLetter);
}

void ReadInData(FILE *fin, char names[][STRING_SIZE], int rating[], int highScore[], int *tagField)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name:
// Inputs:
// Outputs:
// Description:
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	// File to open
	char fileName[STRING_SIZE];

	// Single record from the data file
	char nameFromFile[STRING_SIZE];
	int ratingFromFile;
	int highScoreFromfile;

	// Variables needed to process data file
	int dataInFile;
	char processEOL;
	int nameIndex;
	char oneLetter;

	// Prompt the user
	printf("Enter file name to open: ");

	// Get file name from keyboard
	ReadStringFromKeybaord(fileName, STRING_SIZE);

	// Open file
	fin = fopen(fileName, "r");

	// Check to see if the file open
	if (fin != NULL)
	{

		// Set tagField to 0
		*tagField = 0;

		/* Use a file processing loop to read in the data */
		/* This loops assumes that there are an unknown number of records in the file */

		// Initialization - Check to see if there is data in the file
		dataInFile = fgetc(fin);

		// Check to see if you have reached the end of the file and
		// that there is room in the array to store the next record
		while (dataInFile != EOF && *tagField < MAX)
		{
			// Put the character back
			ungetc(dataInFile, fin);

			// Now we know that there is still data in the file
			// Read in all three pieces of data

			/* Use a sentinel loop to store the name */

			// Start nameIndex at 0
			nameIndex = 0;

			// Initialization - Retrieve the first letter of the name
			oneLetter = fgetc(fin);

			while (oneLetter != '#')
			{
				// Store letter in name in the array
				nameFromFile[nameIndex] = oneLetter;

				// Increase index by 1
				nameIndex++;

				// Changer - Retrieve the next letter of the name
				oneLetter = fgetc(fin);
			}

			// Add null terminator to the string
			nameFromFile[nameIndex] = '\0';

			fscanf(fin, "%d", &ratingFromFile);
			fscanf(fin, "%d", &highScoreFromfile);

			// Process the enter key
			processEOL = fgetc(fin);
			while (processEOL != '\n' && processEOL != EOF)
			{
				// Get the next character from the file
				processEOL = fgetc(fin);
			}

			// Set data read in from file to the array
			strcpy(names[*tagField], nameFromFile);
			rating[*tagField] = ratingFromFile;
			highScore[*tagField] = highScoreFromfile;

			// Incrament the tagField
			(*tagField)++;

			// Changer - Check to see if there is data in the file
			dataInFile = fgetc(fin);

		} // CLOSE while-loop

	} // CLOSE if-statement
	else
	{
		// Print error message to the scree
		printf("File did not open\n\n");
	}

	// Close the input file.
	fclose(fin);

} // Close ReadInData

int FindName(char nameToFind[], const char names[][STRING_SIZE], int tagField)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name:
// Inputs:
// Outputs:
// Description:
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	int position = -1;

	for (int index = 0; index < tagField && position == -1; index++)
	{

		// Check to see if the current name and the name to find are equal
		if (strcmp(nameToFind, names[index]) == 0)
		{
			// Set position to the current index
			position = index;
		}
	}

	return position;
}

void DisplayMenu(void)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name:
// Inputs:
// Outputs:
// Description:
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	// Move cursor down two lines
	printf(DOUBLE_RETURN);

	PrintDivider('*', 80);

	// Print menu to the screen
	printf("\t1) Open File\n");
	printf("\t-------------\n");
	printf("\t2) Print one record\n");
	printf("\t3) Print all the records\n");
	printf("\t4) Add one record\n");
	printf("\t5) Delete one record\n");
	printf("\t6) Total ratings\n");
	printf("\t7) Total high score\n");
	printf("\t8) Average ratings\n");
	printf("\t9) Average high score\n");
	printf("\t10) Find the highest rating\n");
	printf("\t11) Find the lowest rating\n");
	printf("\t12) Find the highest high score\n");
	printf("\t13) Find the lowest high score\n");
	printf("\t14) Sort data by rating\n");
	printf("\t15) Sort data by high score\n");
	printf("\t16) Sort data by name\n");

	printf("\t-------------\n");
	printf("\t0) Quit\n");

	PrintDivider('*', 80);
}

int GetSelection(void)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name:
// Inputs:
// Outputs:
// Description:
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	int selection;
	char nextChar;

	// Prompt user for selection
	printf("\tEnter selection: ");

	// Get value from the keyboard
	selection = (getchar() - 48);

	// Grab the next character from the input buffer
	nextChar = getchar();

	// Check to see if the next character was the enter key
	if (nextChar != '\n')
	{
		// Create a two digit number
		selection = (selection * 10) + (nextChar - 48);
	}

	// Mover cursor down to the next line
	printf("\n");

	// Check to see if the next character was the enter key
	if (nextChar != '\n')
	{
		// If it wasn't, then clear the buffer
		ClearBuffer(selection + 48);
	}

	return selection;
}

void ExecuteSelection(int selection, char names[][STRING_SIZE], int rating[], int highScore[], int *tagField)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name:
// Inputs:
// Outputs:
// Description:
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	FILE *fin;
	char nameToFind[STRING_SIZE];
	int location;
	int sum;
	char oneLetter;
	int nameIndex;
	double average = 0;

	switch (selection)
	{
	case 0:
		// Do nothing, but avoid the default case
		break;

	case 1:
		ReadInData(fin, names, rating, highScore, tagField);
		break;

	case 2:
		// Print one record
		printf("Enter name to find: ");

		ReadStringFromKeybaord(nameToFind, STRING_SIZE);

		location = FindName(nameToFind, names, *tagField);

		if (location != -1)
		{
			PrintDataHeader();
			PrintOneRecord(names[location], rating[location], highScore[location]);
		}
		else
		{
			// Send message to the screen
			printf(USER_NOT_FOUND_MESSAGE);
		}
		break;

	case 3:
		// Print all the records
		PrintAllRecords(names, rating, highScore, *tagField);
		break;

	case 4:
		// Add one record
		AddOneRecord(names, rating, highScore, tagField);
		break;

	case 5:
		// Delete one record
		printf("Enter name to find: ");
		scanf("%s", nameToFind);

		location = FindName(nameToFind, names, *tagField);

		if (location != -1)
		{
			DeleteOneRecord(names, rating, highScore, tagField, location);
		}
		else
		{
			// Send message to the screen
			printf(USER_NOT_FOUND_MESSAGE);
		}
		break;

	case 6:
		// Total ratings
		sum = CalculateTotal(rating, *tagField);
		printf("Total ratings for all characters: %d\n\n", sum);
		break;

	case 7:
		// Total hi score
		sum = CalculateTotal(highScore, *tagField);
		printf("Total high score for all characters: %d\n\n", sum);
		break;

	case 8:
		// Average ratings
		sum = CalculateTotal(rating, *tagField);

		if (*tagField != 0)
		{
			// Calcualte the average
			average = (double)sum / *tagField;
		}

		printf("Average high Score = %lf\n", average);

		break;

	case 9:
		// Average hi score
		// Average ratings
		sum = CalculateTotal(highScore, *tagField);

		if (*tagField != 0)
		{
			// Calcualte the average
			average = (double)sum / *tagField;
		}

		printf("Average high Score = %lf\n", average);

		break;

	case 10:
		// Find the highest rating
		location = FindHighest(rating, *tagField);

		if (location != -1)
		{
			printf("The position of the highest rating is: %d\n", location);
			printf("The value of the highest rating is: %d\n", rating[location]);
		}
		else
		{
			printf(ARRAY_IS_EMPTY);
		}

		break;

	case 11:
		// Find the lowest rating
		location = FindLowest(rating, *tagField);

		if (location != -1)
		{
			printf("The position of the lowest rating is: %d\n", location);
			printf("The value of the lowest rating is: %d\n", rating[location]);
		}
		else
		{
			printf(ARRAY_IS_EMPTY);
		}
		break;

	case 12:
		// Find the highest high score
		location = FindHighest(highScore, *tagField);

		if (location != -1)
		{
			printf("The position of the highest high score is: %d\n", location);
			printf("The value of the highest high score is: %d\n", highScore[location]);
		}
		else
		{
			printf(ARRAY_IS_EMPTY);
		}

		break;

	case 13:
		// Find the lowest high score
		location = FindLowest(highScore, *tagField);

		if (location != -1)
		{
			printf("The position of the lowest high score is: %d\n", location);
			printf("The value of the lowest high score is: %d\n", highScore[location]);
		}
		else
		{
			printf(ARRAY_IS_EMPTY);
		}

		break;

	case 14:
		// Sort by rating
		SelectionSort(rating, highScore, names, *tagField);

		break;

	case 15:
		// Sort by high score
		SelectionSort(highScore, rating, names, *tagField);
		break;

	case 16:
		// Sort by name
		SelectionSortByName(highScore, rating, names, *tagField);
		break;

	default:
		// Output error message
		printf(DOUBLE_RETURN);
		printf("\t* * * INVALID SELECTION * * *\n\n");
	}
}

void PrintResult(double value, char message[])
///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name:
// Inputs:
// Outputs:
// Description:
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	// Print result to the screen
	printf("%s %lf\n\n", message, value);
}

void PrintDataHeader(void)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name:
// Inputs:
// Outputs:
// Description:
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	printf("Name                ");
	printf("Rating\t");
	printf("High Score\n");

	PrintDivider('-', 45);
}

void PrintOneRecord(const char name[], int rating, int highScore)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name:
// Inputs:
// Outputs:
// Description:
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	printf("%s", name);

	// Pad the name with spaces
	for (int index = 0; index < (20 - strlen(name)); index++)
	{
		// Print a space
		printf(" ");
	}

	printf("%d\t\t", rating);
	printf("%d\n", highScore);
}

void PrintAllRecords(const char names[][STRING_SIZE], const int rating[], const int highScore[], int tagField)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name:
// Inputs:
// Outputs:
// Description:
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	PrintDataHeader();

	for (int index = 0; index < tagField; index++)
	{
		PrintOneRecord(names[index], rating[index], highScore[index]);
	}
}

void AddOneRecord(char names[][STRING_SIZE], int rating[], int highScore[], int *tagField)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name:
// Inputs:
// Outputs:
// Description:
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	char newName[STRING_SIZE];
	int newRating;
	int newHighScore;

	if (*tagField < MAX)
	{
		// Get the data
		printf("Enter new name: ");
		ReadStringFromKeybaord(newName, STRING_SIZE);

		printf("Enter new rating: ");
		scanf("%d", &newRating);

		printf("Enter new high score: ");
		scanf("%d", &newHighScore);

		// Copy the new data into the array
		strcpy(names[*tagField], newName);
		rating[*tagField] = newRating;
		highScore[*tagField] = newHighScore;

		// Increase the tag
		(*tagField)++;
	}
}

void DeleteOneRecord(char names[][STRING_SIZE], int rating[], int highScore[], int *tagField, int location)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name:
// Inputs:
// Outputs:
// Description:
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	for (int index = location; index < *tagField; index++)
	{
		rating[index] = rating[index + 1];
		highScore[index] = highScore[index + 1];

		strcpy(names[index], names[index + 1]);
	}

	(*tagField)--;
}

int CalculateTotal(const int array[], int tagField)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name:
// Inputs:
// Outputs:
// Description:
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	int total = 0;

	for (int index = 0; index < tagField; index++)
	{
		// Add one element of the array to the total
		total += array[index];
	}

	return total;
}

int FindHighest(const int array[], int tagField)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name:
// Inputs:
// Outputs:
// Description:
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	// Assume that element 0 is the highest
	int highestIndex = 0;

	// Check to make sure the array is not empty
	if (tagField != 0)
	{
		// Compare higest to all other elements of the array
		for (int index = 1; index < tagField; index++)
		{
			// Check one element of the array against the highest
			if (array[index] > array[highestIndex])
			{
				// Record new highest
				highestIndex = index;
			}
		}
	}
	else
	{
		// If the array is empty, set highest to -1
		highestIndex = -1;
	}

	return highestIndex;
}

int FindLowest(const int array[], int tagField)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name:
// Inputs:
// Outputs:
// Description:
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	// Assume that element 0 is the highest
	int lowestIndex = 0;

	// Check to make sure the array is not empty
	if (tagField != 0)
	{
		// Compare higest to all other elements of the array
		for (int index = 1; index < tagField; index++)
		{
			// Check one element of the array against the highest
			if (array[index] < array[lowestIndex])
			{
				// Record new highest
				lowestIndex = index;
			}
		}
	}
	else
	{
		// If the array is empty, set highest to -1
		lowestIndex = -1;
	}

	return lowestIndex;
}

void SwapI(int *first, int *second)
{
	int temp = *first;

	// Swap two variables
	*first = *second;
	*second = temp;
}

void Swap(char first[], char second[])
{
	char temp[STRING_SIZE];

	strncpy(temp, first, STRING_SIZE);

	// Swap two variables
	strncpy(first, second, STRING_SIZE);
	strncpy(second, temp, STRING_SIZE);
}

void SelectionSort(int array1[], int array2[], char names[][STRING_SIZE], int arrayLength)
{
	int smallest;
	/// go through all array elements up to the second to last element. On last iteration,
	/// there are only two elements left in the unsorted array to compare.
	for (int currentElement = 0; currentElement < arrayLength - 1; currentElement++)
	{
		// for the sub-array of currentElement through end-of-array, find the position
		// of the smallest value.
		// Initialize smallest to the first element in the sub array.
		smallest = currentElement;

		/// check ALL other elements in sub-array against current smallest position
		for (int i = currentElement + 1; i < arrayLength; i++)
		{
			if (array1[i] < array1[smallest])
			{
				smallest = i;
			}
		}

		// now that sub-array has been searched, we have the index of the smallest value
		// exchange the values contained in current element and smallest element.
		SwapI(&array1[currentElement], &array1[smallest]);
		SwapI(&array2[currentElement], &array2[smallest]);
		Swap(names[currentElement], names[smallest]);
	}
}

void SelectionSortByName(int array1[], int array2[], char names[][STRING_SIZE], int arrayLength)
{
	int smallest;
	/// go through all array elements up to the second to last element. On last iteration,
	/// there are only two elements left in the unsorted array to compare.
	for (int currentElement = 0; currentElement < arrayLength - 1; currentElement++)
	{
		// for the sub-array of currentElement through end-of-array, find the position
		// of the smallest value.
		// Initialize smallest to the first element in the sub array.
		smallest = currentElement;

		/// check ALL other elements in sub-array against current smallest position
		for (int i = currentElement + 1; i < arrayLength; i++)
		{
			// if (array1[i] < array1[smallest])
			if (strcmp(names[i], names[smallest]) < 0)
			{
				smallest = i;
			}
		}

		// now that sub-array has been searched, we have the index of the smallest value
		// exchange the values contained in current element and smallest element.
		SwapI(&array1[currentElement], &array1[smallest]);
		SwapI(&array2[currentElement], &array2[smallest]);
		Swap(names[currentElement], names[smallest]);
	}
}