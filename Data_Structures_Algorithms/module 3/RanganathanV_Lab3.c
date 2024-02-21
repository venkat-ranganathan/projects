#include "RanganathanV_Lab3.h"

int main(void)
{
    // declare file pointers
	FILE* pFout;
	
	OpenFile(&pFout, "OutputFile.txt", "w");

	int arrayOne[MAX];
	int arrayTwo[MAX];
	int sizeOne = sizeof(arrayOne) / sizeof(arrayOne[0]);
	int sizeTwo = sizeof(arrayTwo) / sizeof(arrayTwo[0]);

	// declare time variable
	time_t t;

	// initialize random number generator to clock so new numbers generated
	// each time code is run
	srand((unsigned int) time(&t));

	// option 0 prints to output file
	PrintHeader(pFout, 0);

	fprintf(pFout, "\n");

	// Print star pattern to file
	PrintDivider(pFout, STAR, SCREEN_WIDTH);
	fprintf(pFout, "\t\t\tStar Pattern - Printed to output file\n");
	PrintDivider(pFout, STAR, SCREEN_WIDTH);
	fprintf(pFout, "\n");
	// print 12 lines to output file using option 0
	StarPattern(pFout, 12, 1, 0);
	fprintf(pFout, "\n");
	PrintDivider(pFout, STAR, SCREEN_WIDTH);

	// option 1 prints to screen
	PrintHeader(pFout, 1);

	// Print star pattern to screen
	printf("\n");
	PrintDividerScreen(STAR, SCREEN_WIDTH);
	printf("\n\t\t\tStar Pattern - Printed to screen\n");
	PrintDividerScreen(STAR, SCREEN_WIDTH);
	printf("\n");
	// print 15 lines to screen using option 1
	StarPattern(pFout, 15, 1, 1);
	printf("\n");
	PrintDividerScreen(STAR, SCREEN_WIDTH);

	// second recursive function sum array

	// fill arrays with random numbers
	FillArrayWithRandomNumbers(arrayOne);
	FillArrayWithRandomNumbers(arrayTwo);

	fprintf(pFout, "\n");
	PrintArray(pFout, arrayOne, MAX, 0);

	fprintf(pFout, "Sum of Array One: %d", SumArray(arrayOne, 0, sizeOne));
	fprintf(pFout, "\n\n");
	PrintDivider(pFout, STAR, SCREEN_WIDTH);

	printf("\n");
	PrintArray(pFout, arrayTwo, MAX, 1);

	printf("Sum of Array Two: %d", SumArray(arrayTwo, 0, sizeTwo));
	printf("\n\n");
	PrintDividerScreen(STAR, SCREEN_WIDTH);

	// 3rd recursive function
	fprintf(pFout, "\n\t\t\t3rd Recursive Function: PrintDigits\n");
	PrintDivider(pFout, STAR, SCREEN_WIDTH);
	fprintf(pFout, "\n");
	fprintf(pFout, "Digits printed recursively to output file: \n");
	PrintDigits(pFout, 1385, 0);

	printf("\n\t\t\t3rd Recursive Function: PrintDigits\n");
	PrintDividerScreen(STAR, SCREEN_WIDTH);
	printf("\n");
	printf("Digits printed recursively to screen: \n");
	PrintDigits(pFout, 1680, 1);
	printf("\n");

	CloseFile(&pFout);

    return 0;
}