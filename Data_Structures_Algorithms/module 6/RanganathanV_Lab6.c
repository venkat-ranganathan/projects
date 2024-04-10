/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Venkat Ranganathan
| Course:           CS-212: Data Structures for Engineers
| Program  Name:    Lab 
| Date:             04/05/24
|
|--------------------------------------------------------------------------------------------------
| Program Description: 
|
|--------------------------------------------------------------------------------------------------
| Inputs:
|   There is one input file
|  
|
|--------------------------------------------------------------------------------------------------
| Processing: 
|
|--------------------------------------------------------------------------------------------------
| Outputs:
|   Results printed to terminal and output file
|
|
|--------------------------------------------------------------------------------------------------
*/

#include "RanganathanV_Lab6.h"

int main()
{
    // initialize and open data files
    FILE * pOutput;
	FILE * pDebug = NULL;

    OpenDataFile(&pOutput, &pDebug);

    // Declare our stackType
	stackType stack;

    // initialize stack pointer
	InitializeStack(&stack);

    // close files
    CloseFile(&pOutput);
    CloseFile(&pDebug);
    
    return 0;
}