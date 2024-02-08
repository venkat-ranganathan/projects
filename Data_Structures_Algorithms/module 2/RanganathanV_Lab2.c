/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Venkat Ranganathan
| Course:           CS-212: Data Structures for Engineers
| Program  Name:    Lab 2
| Date:             01/27/24
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|   program takes data from an input file, processes it into elements of an array, calculates
|	# of even/odd elements, total # of elements in array, element average value, # of elements
|	with values > element average, then prints results and closes the file; process is repeated
|	for second array with randomly generated values between 0 and 500
|--------------------------------------------------------------------------------------------------
| Inputs:
|   Inputs provided by input file
|  
|
|--------------------------------------------------------------------------------------------------
| Processing:
|   Calculations: count, average, even/odd
|  
|
|--------------------------------------------------------------------------------------------------
| Outputs:
|   Results for both arrays printed to output file
|
|
|--------------------------------------------------------------------------------------------------
*/

#include "RanganathanV_Lab2.h"

int main(void)
{
	// declare file pointers
	FILE* pFin;
	FILE* pFout;

	// create two arrays, size 50 set using a macro
	int arrayOne[MAX];
	int arrayTwo[MAX];
	int arrayThree[MAXER];

	// declare and initialize to zero array counter variable
	int arrayCounter = 0;
	int isEven = 0;
	int isOdd = 0;
	
	OpenFile(&pFin, "Numbers.txt", "r");
	OpenFile(&pFout, "OutputFile.txt", "w");

	PrintHeader(pFout);

	ReadDataFromFile(pFin, arrayOne, &arrayCounter);

	FillArrayWithRandomNumbers(arrayTwo);

	// first array
	fprintf(pFout, "\nArray One: numbers from input file\n");

	PrintArray(pFout, arrayOne, arrayCounter);
	
	CountEvenOddNumbers(arrayOne, arrayCounter, &isEven, &isOdd);
	TotalArray(arrayOne, arrayCounter);
	CalculateAverage(arrayOne, arrayCounter);
	CountNumberAboveAverage(arrayOne, arrayCounter);

	PrintResults(pFout, arrayOne, arrayCounter, isEven, isOdd);

	// second array
	fprintf(pFout, "\nArray Two: numbers from rand() function\n");

	// using MAX value instead of arrayCounter since second array doesn't use
	// tag field
	PrintArray(pFout, arrayTwo, MAX);

	CountEvenOddNumbers(arrayTwo, MAX, &isEven, &isOdd);
	TotalArray(arrayTwo, MAX);
	CalculateAverage(arrayTwo, MAX);
	CountNumberAboveAverage(arrayTwo, MAX);

	PrintResults(pFout, arrayTwo, MAX, isEven, isOdd);

	// third array
	assignArray(arrayThree, &arrayCounter);

	fprintf(pFout, "\nArray Three (Extra Credit): numbers from algorithm\n");

	PrintArray(pFout, arrayThree, arrayCounter);

	CountEvenOddNumbers(arrayThree, arrayCounter, &isEven, &isOdd);
	TotalArray(arrayThree, arrayCounter);
	CalculateAverage(arrayThree, arrayCounter);
	CountNumberAboveAverage(arrayThree, arrayCounter);

	PrintResults(pFout, arrayThree, arrayCounter, isEven, isOdd);

	// close input and output files
	CloseFiles(&pFin, &pFout);

    return 0;
}