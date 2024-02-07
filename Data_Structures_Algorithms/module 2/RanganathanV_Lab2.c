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

	// declare and initialize to zero array counter variable
	int arrayCounter = 0;
	int isEven, isOdd;
	
	OpenFile(&pFin, "Numbers.txt", "r");
	OpenFile(&pFout, "OutputFile.txt", "w");

	PrintHeader(pFout);

	ReadDataFromFile(pFin, arrayOne, &arrayCounter);

	FillArrayWithRandomNumbers(arrayTwo);

	// first array
	fprintf(pFout, "\nArray One\n");

	PrintArray(pFout, arrayOne, arrayCounter);
	
	CountEvenOddNumbers(arrayOne, &isEven, &isOdd);
	TotalArray(arrayOne);
	CalculateAverage(arrayOne, arrayCounter);
	CountNumberAboveAverage(arrayOne, arrayCounter);

	PrintResults(pFout, arrayOne, arrayCounter, isEven, isOdd);

	// second array
	fprintf(pFout, "\nArray Two\n");

	PrintArray(pFout, arrayTwo, arrayCounter);

	CountEvenOddNumbers(arrayTwo, &isEven, &isOdd);
	TotalArray(arrayTwo);
	CalculateAverage(arrayTwo, arrayCounter);
	CountNumberAboveAverage(arrayTwo, arrayCounter);

	PrintResults(pFout, arrayTwo, arrayCounter, isEven, isOdd);

	// close input and output files
	CloseFiles(&pFin, &pFout);

    return 0;
}