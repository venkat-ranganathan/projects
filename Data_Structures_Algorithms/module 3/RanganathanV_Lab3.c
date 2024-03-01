/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Venkat Ranganathan
| Course:           CS-212: Data Structures for Engineers
| Program  Name:    Lab 3
| Date:             02/23/24
|
|--------------------------------------------------------------------------------------------------
| Program Description: goal of this lab is to learn to write recursive functions
|	and implememnt a Quick Sort algorithm; and to create efficient,
|	re-usable functions with an option for the user to print to an output file or screen
|
|--------------------------------------------------------------------------------------------------
| Inputs:
|   There are no inputs provided by a file or user for this lab
|  
|
|--------------------------------------------------------------------------------------------------
| Processing: 
|   basic math functions are used: addition, subtraction, division, multiplication, and finding
|  the remainder using the modulus operator
|
|--------------------------------------------------------------------------------------------------
| Outputs:
|   Results printed to terminal and output file
|
|
|--------------------------------------------------------------------------------------------------
*/

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
	int sizeThree = sizeof(arrayThree) / sizeof(arrayThree[0]);
	int sizeFour = sizeof(arrayFour) / sizeof(arrayFour[0]);

	// declare time variable
	time_t t;

	// initialize random number generator to clock so new numbers generated
	// each time code is run
	srand((unsigned int) time(&t));

	/* START PART A */
	
	// print to screen using printf(stdout, "blah");
	PrintHeader(pFout);
	fprintf(pFout, "\n");

	/* START PART B */

	/* START FUNCTION 3 */

	// Print star pattern to file
	PrintDivider(pFout, STAR, SCREEN_WIDTH);
	fprintf(pFout, "\t\t\tStar Pattern - Printed to output file\n");
	PrintDivider(pFout, STAR, SCREEN_WIDTH);
	fprintf(pFout, "\n");
	// print 12 lines to output file
	StarPattern(pFout, 12, 1);
	fprintf(pFout, "\n");
	PrintDivider(pFout, STAR, SCREEN_WIDTH);

	PrintHeader(stdout);

	// Print star pattern to screen
	printf("\n");

	PrintDivider(stdout, STAR, SCREEN_WIDTH);
	printf("\n\t\t\tStar Pattern - Printed to screen\n");
	PrintDivider(stdout, STAR, SCREEN_WIDTH);
	printf("\n");
	StarPattern(stdout, 15, 1);
	printf("\n");
	PrintDivider(stdout, STAR, SCREEN_WIDTH);

	/* END FUNCTION 3 */

	/* START FUNCTION 4 */

	// second recursive function sum array

	// fill array with random numbers
	FillArrayWithRandomNumbers(arrayOne, sizeOne, 99);

	PrintDivider(pFout, DASH, TABLE_WIDTH+2);
	CenterString(pFout, "2nd Recursive Function: Sum the Array", TABLE_WIDTH+2);
	PrintDivider(pFout, DASH, TABLE_WIDTH+2);

	PrintArray(pFout, arrayOne, sizeOne);

	fprintf(pFout, "Sum of Array One: %d", SumArray(arrayOne, 0, sizeOne));
	fprintf(pFout, "\n\n");
	PrintDivider(pFout, STAR, SCREEN_WIDTH);

	PrintDivider(stdout, DASH, TABLE_WIDTH+2);
	CenterString(stdout, "2nd Recursive Function: Sum the Array", TABLE_WIDTH+2);
	PrintDivider(stdout, DASH, TABLE_WIDTH+2);
	// fill array with random numbers
	FillArrayWithRandomNumbers(arrayTwo, sizeTwo, 99);
	
	printf("\n");
	PrintArray(stdout, arrayTwo, sizeTwo);

	printf("Sum of Array Two: %d", SumArray(arrayTwo, 0, sizeTwo));
	printf("\n\n");
	PrintDivider(stdout, STAR, SCREEN_WIDTH);

	/* END FUNCTION 4 */

	/* START FUNCTION 5 */

	// 3rd recursive function
	fprintf(pFout, "\t\t\t3rd Recursive Function: PrintDigits\n");
	PrintDivider(pFout, STAR, SCREEN_WIDTH);
	fprintf(pFout, "\n");
	fprintf(pFout, "Digits printed recursively to output file: \n");
	PrintDigits(pFout, 1385);

	printf("\n\t\t\t3rd Recursive Function: PrintDigits\n");
	PrintDivider(pFout, STAR, SCREEN_WIDTH);
	printf("\n");
	printf("Digits printed recursively to screen: \n");
	PrintDigits(pFout, 1680);
	printf("\n");

	/* END FUNCTION 5 */

	/* END PART B */

	/* PART C */

	// recursive sort
	// fill array with random numbers
	FillArrayWithRandomNumbers(arrayThree, sizeThree, 999);

	fprintf(pFout, "\n");
	PrintDivider(pFout, DASH, TABLE_WIDTH+2);
	CenterString(pFout, "Recursive Sort: arrayThree", TABLE_WIDTH+2);
	PrintDivider(pFout, DASH, TABLE_WIDTH+2);

	PrintArray(pFout, arrayThree, sizeThree);

	QuickSort(arrayThree, 0, sizeThree - 1);
	fprintf(pFout, "\n");
	PrintDivider(pFout, DASH, TABLE_WIDTH+2);
	CenterString(pFout, "Quick Sort: arrayThree", TABLE_WIDTH+2);
	PrintDivider(pFout, DASH, TABLE_WIDTH+2);

	PrintArray(pFout, arrayThree, sizeThree);

	// fill array with random numbers
	FillArrayWithRandomNumbers(arrayFour, sizeFour, 999);

	printf("\n");
	PrintDivider(stdout, DASH, TABLE_WIDTH+2);
	CenterString(stdout, "Recursive Sort: arrayFour", TABLE_WIDTH+2);
	PrintDivider(stdout, DASH, TABLE_WIDTH+2);
	PrintArray(stdout, arrayFour, sizeFour);	

	QuickSort(arrayFour, 0, sizeFour - 1);
	printf("\n");
	PrintDivider(stdout, DASH, TABLE_WIDTH+2);
	CenterString(stdout, "Quick Sort: arrayFour", TABLE_WIDTH+2);
	PrintDivider(stdout, DASH, TABLE_WIDTH+2);
	PrintArray(stdout, arrayFour, sizeFour);	

	/* END PART C */

	/* START EXTRA CREDIT PART B */

	// first number
	PrintDivider(pFout, STAR, SCREEN_WIDTH);
	fprintf(pFout, "\nExtra Credit: \n\n");
	fprintf(pFout, "Original Digits printed recursively to output file: ");
	PrintDigits(pFout, 25689);
	fprintf(pFout, "\n\n");

	fprintf(pFout, "Reversed Digits printed recursively to output file: ");
	fprintf(pFout, "%d", ReverseDigits(25689, 0));
	fprintf(pFout, "\n\n");
	PrintDivider(pFout, STAR, SCREEN_WIDTH);
	fprintf(pFout, "\n\n");

	// second number
	PrintDivider(stdout, STAR, SCREEN_WIDTH);
	printf("\nExtra Credit: \n\n");
	printf("Original Digits printed recursively to screen: ");
	PrintDigits(stdout, 345621);
	printf("\n\n");

	printf("Reversed Digits printed recursively to screen: ");
	printf("%d", ReverseDigits(345621, 0));
	printf("\n\n");
	PrintDivider(stdout, STAR, SCREEN_WIDTH);
	printf("\n\n");

	/* END EXTRA CREDIT PART B */

	CloseFile(&pFout);

	/* END PART A */

    return 0;
}