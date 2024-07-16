/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Venkat Ranganathan
| Course:           CS-212: Data Structures for Engineers
| Program  Name:    Object Orientated Programming (OOP) Example
| Date:             January 27, 2023
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|   This program is an example of how to write a program using Object Oriented Programming (OOP)
|
|--------------------------------------------------------------------------------------------------
| Inputs:
|   Integers are stored in a data file called Numbers.txt
|  
|--------------------------------------------------------------------------------------------------
| Processing:
|   The integers will be read in from a file and stored in an array. 
|  
|--------------------------------------------------------------------------------------------------
| Outputs:
|   The contents of the array will be printed to an output file and the screen. 
|
|   Before the program exits, the object will be destroyed. The destructor will print a message
| to the screen.
|
|--------------------------------------------------------------------------------------------------
*/

#include "RanganathanV_Lab4.h"

int main(void)
{
	FILE * pFin1;
	FILE * pFin2;
	FILE * pFout;

	// store data from input files into respective arrays
	int iArray[ARRAY_SIZE];
	double dArray[ARRAY_SIZE];
	
	OpenFiles(&pFin1, &pFin2, &pFout);

	ReadDataFromFile(pFin1, iArray);
	ReadDataFromFile(pFin2, dArray);

	objectType object1; // object instance to generate random numbers
	objectType object2(iArray); // object instance to copy integer array read from file to integer array in method
	objectType object3(dArray); // object instance to copy double array read from file to double array in method

	//PrintHeader(stdout);
	//PrintHeader(pFout);

	//PrintDivider(stdout, '*', 20);
	//PrintDivider(pFout, '*', 20);

	//CenterString(stdout, "hello", 5);
	//CenterString(pFout, "hello", 5);
	
	CloseFiles(&pFin1, &pFin2, &pFout);
	
	return 0;
}

