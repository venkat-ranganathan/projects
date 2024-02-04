/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Venkat Ranganathan
| Course:           CS-212: Data Structures for Engineers
| Program  Name:    Lab # 1
| Date:             01/24/24
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|   Program asks users to select a shape, enter values needed to calculate the area of the shape, then prints to terminal the shape chosen, variable values entered, and the calculated area. Error checking is used to verify valid choice made by user

    The answer will be calculated and printed to the screen.
|
|   This program will use the following programming skills:
|     > A do-while loop
|     > A switch statement
|     > Functions with pass by values
|     > Functions with pass by pointers
|
|
|--------------------------------------------------------------------------------------------------
| Inputs:
|   Inputs provided by user via keyboard; constants defined in header file, including PI
|  
|
|--------------------------------------------------------------------------------------------------
| Processing:
|   The following calculations will be made based on the user's selection of shape
    > addition, multiplication, division
    > used to calculate area of selected shape
|  
|
|--------------------------------------------------------------------------------------------------
| Outputs:
|   Outputs printed to terminal, include: shape chosen, shape variables entered, calculated shape area; error message printed for invalid choice;
|
|
|--------------------------------------------------------------------------------------------------
*/

#include "RanganathanV_Lab1.h"

int main(void)
{
    // declare main variables
    int selection;
    int valueA;
    int valueB;
    int valueC;
 
    double area;

    // print header to the screen
    PrintHeader();
    
    // do-while loop until user chooses to quit
    do {
        // print menu and get user selection
        selection = PrintMenuAndGetSelection();

        if (selection != 0) {

            // process selection
            ProcessSelection(selection, &valueA, &valueB, &valueC, &area);

            // print shape
            PrintShape(selection);

            // print results
            PrintResults(selection, valueA, valueB, valueC, area);

            // print divider
            PrintDivider();
        }

    } while (selection != 0);
    
    return 0;
}