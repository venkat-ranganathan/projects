#include "RanganathanV_Lab3.h"

int main(void)
{
    // declare file pointers
	FILE* pFout;
	
	OpenFile(&pFout, "Lab3_Output.txt", "w");

	int arrayOne[MAX];
	int arrayTwo[MAX];
	int arrayThree[MAXER];
	int arrayFour[MAXER];

	// need to pass integer values for SumArray function
	int sizeOne = sizeof(arrayOne) / sizeof(arrayOne[0]);
	int sizeTwo = sizeof(arrayTwo) / sizeof(arrayTwo[0]);

	// declare time variable
	time_t t;

	// initialize random number generator to clock so new numbers generated
	// each time code is run
	srand((unsigned int) time(&t));

	/* START PART A */
	
	// option 0 prints to output file, option 1 prints to screen
	// applies to PrintHeader, PrintDivider, CenterString, etc.
	PrintHeader(pFout, 0);
	fprintf(pFout, "\n");

	/* START PART B */

	/* START FUNCTION 3 */

	// Print star pattern to file
	PrintDivider(pFout, STAR, SCREEN_WIDTH, 0);
	fprintf(pFout, "\t\t\tStar Pattern - Printed to output file\n");
	PrintDivider(pFout, STAR, SCREEN_WIDTH, 0);
	fprintf(pFout, "\n");
	// print 12 lines to output file using option 0
	StarPattern(pFout, 12, 1, 0);
	fprintf(pFout, "\n");
	PrintDivider(pFout, STAR, SCREEN_WIDTH, 0);

	// option 1 prints to screen
	PrintHeader(pFout, 1);

	// Print star pattern to screen
	printf("\n");

	PrintDivider(pFout, STAR, SCREEN_WIDTH, 1);
	printf("\n\t\t\tStar Pattern - Printed to screen\n");
	PrintDivider(pFout, STAR, SCREEN_WIDTH, 1);
	printf("\n");
	// print 15 lines to screen using option 1
	StarPattern(pFout, 15, 1, 1);
	printf("\n");
	PrintDivider(pFout, STAR, SCREEN_WIDTH, 1);

	/* END FUNCTION 3 */

	/* START FUNCTION 4 */

	// second recursive function sum array

	// fill array with random numbers
	FillArrayWithRandomNumbers(arrayOne, MAX, 99);

	PrintDivider(pFout, DASH, TABLE_WIDTH+2, 0);
	CenterString(pFout, "2nd Recursive Function: Sum the Array", TABLE_WIDTH+2, 0);
	PrintDivider(pFout, DASH, TABLE_WIDTH+2, 0);

	PrintArray(pFout, arrayOne, MAX, 0);

	fprintf(pFout, "Sum of Array One: %d", SumArray(arrayOne, 0, sizeOne));
	fprintf(pFout, "\n\n");
	PrintDivider(pFout, STAR, SCREEN_WIDTH, 0);

	// fill array with random numbers
	FillArrayWithRandomNumbers(arrayTwo, MAX, 99);
	
	printf("\n");
	PrintArray(pFout, arrayTwo, MAX, 1);

	printf("Sum of Array Two: %d", SumArray(arrayTwo, 0, sizeTwo));
	printf("\n\n");
	PrintDivider(pFout, STAR, SCREEN_WIDTH, 1);

	/* END FUNCTION 4 */

	/* START FUNCTION 5 */

	// 3rd recursive function
	fprintf(pFout, "\n\t\t\t3rd Recursive Function: PrintDigits\n");
	PrintDivider(pFout, STAR, SCREEN_WIDTH, 0);
	fprintf(pFout, "\n");
	fprintf(pFout, "Digits printed recursively to output file: \n");
	PrintDigits(pFout, 1385, 0);

	printf("\n\t\t\t3rd Recursive Function: PrintDigits\n");
	PrintDivider(pFout, STAR, SCREEN_WIDTH, 1);
	printf("\n");
	printf("Digits printed recursively to screen: \n");
	PrintDigits(pFout, 1680, 1);
	printf("\n");

	/* END FUNCTION 5 */

	/* END PART B */

	/* PART C */

	// recursive sort
	// fill array with random numbers
	FillArrayWithRandomNumbers(arrayThree, MAXER, 999);

	fprintf(pFout, "\n");
	PrintDivider(pFout, DASH, TABLE_WIDTH+2, 0);
	CenterString(pFout, "Recursive Sort: arrayThree", TABLE_WIDTH+2, 0);
	PrintDivider(pFout, DASH, TABLE_WIDTH+2, 0);
	PrintArray(pFout, arrayThree, MAXER, 0);

	QuickSort(arrayThree, 0, MAXER);
	fprintf(pFout, "\n");
	PrintDivider(pFout, DASH, TABLE_WIDTH+2, 0);
	CenterString(pFout, "Quick Sort: arrayThree", TABLE_WIDTH+2, 0);
	PrintDivider(pFout, DASH, TABLE_WIDTH+2, 0);
	
	PrintArray(pFout, arrayThree, MAXER, 0);

	// fill array with random numbers
	FillArrayWithRandomNumbers(arrayFour, MAXER, 999);

	printf("\n");
	PrintDivider(pFout, DASH, TABLE_WIDTH+2, 1);
	CenterString(pFout, "Recursive Sort: arrayFour", TABLE_WIDTH+2, 1);
	PrintDivider(pFout, DASH, TABLE_WIDTH+2, 1);
	PrintArray(pFout, arrayFour, MAXER, 1);	

	QuickSort(arrayFour, 0, MAXER);
	printf("\n");
	PrintDivider(pFout, DASH, TABLE_WIDTH+2, 1);
	CenterString(pFout, "Quick Sort: arrayFour", TABLE_WIDTH+2, 1);
	PrintDivider(pFout, DASH, TABLE_WIDTH+2, 1);
	PrintArray(pFout, arrayFour, MAXER, 1);	

	/* END PART C */

	/* START EXTRA CREDIT PART B */

	// first number
	PrintDivider(pFout, STAR, SCREEN_WIDTH, 0);
	fprintf(pFout, "\nExtra Credit: \n\n");
	fprintf(pFout, "Original Digits printed recursively to output file: ");
	PrintDigits(pFout, 25689, 0);
	fprintf(pFout, "\n\n");

	fprintf(pFout, "Reversed Digits printed recursively to output file: ");
	fprintf(pFout, "%d", ReverseDigits(25689, 0));
	fprintf(pFout, "\n\n");
	PrintDivider(pFout, STAR, SCREEN_WIDTH, 0);
	fprintf(pFout, "\n\n");

	// second number
	PrintDivider(pFout, STAR, SCREEN_WIDTH, 1);
	printf("\nExtra Credit: \n\n");
	printf("Original Digits printed recursively to screen: ");
	PrintDigits(pFout, 345621, 1);
	printf("\n\n");

	printf("Reversed Digits printed recursively to screen: ");
	printf("%d", ReverseDigits(345621, 0));
	printf("\n\n");
	PrintDivider(pFout, STAR, SCREEN_WIDTH, 1);
	printf("\n\n");

	/* END EXTRA CREDIT PART B */

	CloseFile(&pFout);

	/* END PART A */

    return 0;
}