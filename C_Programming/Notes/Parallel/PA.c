
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

	do {

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
	for(int counter = 0; counter < length; counter++)
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
		while (getchar() != '\n');
	}
}


void ReadStringFromKeybaord(char text[], int maxSize)
{
	char oneLetter;
	int index = 0;
	
	// Retrieve one lettter from the input buffer
	oneLetter = getchar();
	
	while (oneLetter != '\n' && index < maxSize-1)
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
	
	ClearBuffer(oneLetter);
}

void ReadInData(FILE * fin,  char names[][STRING_SIZE], int rating[], int highScore[], int * tagField)
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
	scanf("%s", fileName);

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
			while ( processEOL != '\n' && processEOL != EOF )
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
	
	for(int index = 0; index < tagField && position == -1; index++)
	{
		
		// Check to see if the current name and the name to find are equal
		if(strcmp(nameToFind, names[index]) == 0)
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
	printf("\t12) Find the highest hi score\n");
	printf("\t13) Find the lowest hi score\n");
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

	// Prompt user for selection 
	printf("\tEnter selection: ");

	// Get value from the keyboard
	selection = (getchar() - 48);

	// Mover cursor down to the next line
	printf("\n");
	
	ClearBuffer(selection + 48);

	return selection;
}

void ExecuteSelection(int selection,  char names[][STRING_SIZE], int rating[], int highScore[], int * tagField)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: 
// Inputs:  
// Outputs: 
// Description:
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	FILE * fin;
	char nameToFind[STRING_SIZE];
	int location;
	int sum;
	char oneLetter;
	int nameIndex;
	// double average;

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
		printf("Total hi score for all characters: %d\n\n", sum);
		break;

	case 8:
	
		break;

	case 9:
		// Average hi score
	
		break;

	case 10:
		// Find the highest rating
	
		break;

	case 11:
		// Find the lowest rating
	
		break;

	case 12:
		// Find the highest hi score
	
		break;

	case 13:
		// Find the lowest hi score
	
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

void AddOneRecord(char names[][STRING_SIZE], int rating[], int highScore[], int * tagField)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: 
// Inputs:  
// Outputs: 
// Description:
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	
}

void DeleteOneRecord(char names[][STRING_SIZE], int rating[], int highScore[], int * tagField, int location)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: 
// Inputs:  
// Outputs: 
// Description:
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	
}

int CalculateTotal(const int array[], int tagField)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: 
// Inputs:  
// Outputs: 
// Description:
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	
	return 0;
}

int FindHighest(const int array[], int tagField)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: 
// Inputs:  
// Outputs: 
// Description:
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	return 0;
}

int FindLowest(const int array[], int tagField)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: 
// Inputs:  
// Outputs: 
// Description:
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	return 0;
}