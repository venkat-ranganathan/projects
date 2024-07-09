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
	FILE * pFin;
	FILE * pFout;

	//int intArray[ARRAY_SIZE];
	//double doubleArray[ARRAY_SIZE];
	
	OpenFiles(&pFin, &pFout);
	
	objectType object;
	//objectType(intArray);
	
	object.PrintHeader(stdout);
	object.PrintHeader(pFout);

	object.ReadDataFromFile(pFin);
	
	object.PrintArray(stdout);
	object.PrintArray(pFout);
	
	CloseFiles(&pFin, &pFout);
	
	return 0;
}

