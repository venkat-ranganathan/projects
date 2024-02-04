/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Prof. Foos
| Course:           CS-211: Introduction to C Programming for Engineers
| Program  Name:    Functions_With_Pointers
| Date:             12/14/2022
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|   This program will demonstrate different ways pointers can be used. The majority of this
|  program will use an integer and an integer pointer. Towards the end of the program a double
|  and a double pointer will be used. Because the mechanics are the same for an integer pointer
|  and a double pointer, not all the steps will be repeated.
|
|--------------------------------------------------------------------------------------------------
| Inputs:
|   Variables are either assigned in the program or assigned a value via the keyboard
|
|--------------------------------------------------------------------------------------------------
| Processing:
|   No calculations are used.
|
|--------------------------------------------------------------------------------------------------
| Outputs:
|   All output will be printed to the screen
|
|--------------------------------------------------------------------------------------------------
*/

// Include for scanf and printf
#include <stdio.h>

// Include for strlen
#include <string.h>

// Function Prototype 
void PrintHeader(void);
void PrintDivider(char symbol, int numberOf);
void CenterString(char string[], int lengthToCenterAcross);

void ChangeBlue(int* pAddressOfVariable);
void ReadDouble(double* pDoublePointer);

// Macros
#define SCREEN_WIDTH 80
#define STAR '*'

#define SCHOOL "Binghamton University"
#define PROGRAMMER "Program written by: Prof. Foos"
#define LAB "Advance Link List"

/*
  ------------------------------------------------------------------------------------------------
   NOTES
  ------------------------------------------------------------------------------------------------
	A pointer                - A variable that holds the address of anther variable

	&variable                - The ampersand is the address operator, when placed next to a
							   variable, the address of that variable is returned

	data_type * pointer_name - The * placed after a data type is a declaration of a pointer

	*pointer_type_variable   - The * placed before a pointer, dereference the variable and
							   look at the value of the variable, not the address.

  ------------------------------------------------------------------------------------------------
*/

int main(void)
{
	// Declare an integer and assign it the value 16
	int blue = 16;

	double cost;

	// Declare an integer pointer
	int* pIntPointer;

	// Declare a double pointer
	double* pDoublePointer;

	// Assign the integer pointer to the address of blue
	pIntPointer = &blue;

	// Assign the double pointer to the address of cost
	pDoublePointer = &cost;

	// Dereferenced the integer pointer and changed the value of blue
	*pIntPointer = 80;

	// Move cursor down to the next line
	printf("\n");

	// Print summary to the screen
	printf("An integer named blue has been declared and assigned the value of 16\n");
	printf("An integer pointer named pIntPointer has been declared and assigned the\n");
	printf("address of blue (pIntPointer = &blue).\n\n");

	// Print the address of blue
	// There are two pays to do this, first use the address operator, &, next to the variable
	// The second is to print the pointer.
	printf("ADDRESS of blue (&blue):              %p\n\n", &blue);
	printf("ADDRESS of pIntPointer (pIntPointer): %p\n\n", pIntPointer);

	// Print the new value of blue
	// There are two ways to do this, print the variable as we have done all semester
	// The second way is to dereference the pointer
	printf("Value of blue (via the variable): %d\n\n", blue);
	printf("Value of blue by dereferencing the pointer (*pIntPointer):  %d\n\n", *pIntPointer);

	// Prompt the user for an integer to store in blue
	// NOTE: scanf must use an address of a variable
	// In this example we use the address operator to get the address of the variable
	printf("(Called from main) Enter a new value (scanf will use &blue): ");
	scanf("%d", &blue);

	// Move cursor down to the next line
	printf("\n");

	// Print the new value of blue both ways
	printf("Value of blue (via the variable): %d\n\n", blue);
	printf("Value of blue by dereferencing the pointer (*pIntPointer):  %d\n\n", *pIntPointer);

	// Prompt the user for an integer to store in blue
	// NOTE: scanf must use an address of a variable
	// Since a pointer is already an address, we don't have to use the address operator (&).
	printf("(Called from main) Enter a new value (scanf will use pIntPointer): ");
	scanf("%d", pIntPointer);

	// Move cursor down to the next line
	printf("\n");

	// Print the new value of blue both ways
	printf("Value of blue (via the variable): %d\n\n", blue);
	printf("Value of blue by dereferencing the pointer (*pIntPointer):  %d\n\n", *pIntPointer);

	// NOTE:
	// ChangeBlue is function that takes a pointer to an integer variable
	// In this example we use the address operator to pass in the address of the variable blue

	// Print message to the screen
	printf("Next we will call a function (ChangeBlue) passing in &blue\n\n");

	ChangeBlue(&blue);

	// Print the new value of blue both ways
	printf("Value of blue (via the variable): %d\n\n", blue);
	printf("Value of blue by dereferencing the pointer (*pIntPointer):  %d\n\n", *pIntPointer);

	// NOTE:
	// ChangeBlue is function that takes a pointer to an integer variable
	// In this example we use the pointer to the variable blue to pass in 
	// the pointer that points to blue.

	// Print message to the screen
	printf("Next we will call a function (ChangeBlue) passing in a pointer (pIntPointer)\n\n");

	ChangeBlue(pIntPointer);

	// Print the new value of blue both ways
	printf("Value of blue (via the variable): %d\n\n", blue);
	printf("Value of blue by dereferencing the pointer (*pIntPointer):  %d\n\n", *pIntPointer);

	// NOTE:
	// We will now read in a value for cost (which is a double). Like before, we will
	// do this with the variable and the pointer.

	// Print summary to the screen
	printf("Now we will work with a double pointer. The variable cost has been declared\n");
	printf("but has not been assigned. A double pointer called pDoublePointer has been\n");
	printf("declared and assigned the address of cost (pDoublePointer = &cost)\n\n");

	// Print message to the screen
	printf("First we will call the function ReadDouble using &cost\n\n");

	ReadDouble(&cost);

	// Print the new value for letter and cost.
	printf("Value of cost after the function call (via the variable): = %.2lf\n\n", cost);
	printf("Value of cost after the function call (*pDoublePointer): = %.2lf\n\n", *pDoublePointer);

	// Print message to the screen
	printf("Next, we will call the function ReadDouble using pDoublePointer\n\n");

	ReadDouble(pDoublePointer);

	// Print the new value for letter and cost.
	printf("Value of cost after the function call (via the variable): = %.2lf\n\n", cost);
	printf("Value of cost after the function call (*pDoublePointer): = %.2lf\n\n", *pDoublePointer);

	return 0;
}


//-----------------------------------------------------------------------------
// Function Name: PrintHeader
// Description:
//   This function will call the functions needed to print a header to the 
//  screen. 
//
//-----------------------------------------------------------------------------
void PrintHeader(void)
{
	// Call function to print a divider to the screen
	PrintDivider(STAR, SCREEN_WIDTH);

	// Call functions to print three strings to center to the screen
	CenterString(SCHOOL, SCREEN_WIDTH);
	CenterString(PROGRAMMER, SCREEN_WIDTH);
	CenterString(LAB, SCREEN_WIDTH);

	// Call function to print a divider to the screen
	PrintDivider(STAR, SCREEN_WIDTH);

} // End PrintHeader


//-----------------------------------------------------------------------------
// Function Name: PrintDivider
// Description:
//   Symbols will be printed to the screen. 
//
//-----------------------------------------------------------------------------
void PrintDivider(char symbol, int numberOf)
{
	// Initialize LCV (Loop Control Variable) to 0
	int counter = 0;

	// Print a bunch of symbols across the screen
	while (counter < numberOf)
	{
		// Print one character to the screen
		printf("%c", symbol);

		// Increment counter
		counter++;
	}

	// Move the cursor down to the next line
	printf("\n");

} // END PrintDivider


//-----------------------------------------------------------------------------
// Function Name: CenterString
// Description:
//   The array of characters passed into the function will be centered
//  across the screen using the following formula:
//  
//    (lengthToCenterAcross + the string length) / 2
//
//-----------------------------------------------------------------------------
void CenterString(char string[], int lengthToCenterAcross)
{
	// Capture how long the string is
	// Cast to an integer because strlen technically returns size_t
	int stringLength = (int)strlen(string);

	// Calculate the width to print the string in
	int width = (lengthToCenterAcross + stringLength) / 2;

	// Calculate how many blank spaces are needed before printing the string
	int numberOfBlankSpaces = width - stringLength;

	// Initialize LCV (Loop Control Variable) to 0
	int counter = 0;

	// Print the spaces needed to center the string
	while (counter < numberOfBlankSpaces)
	{
		// Print one space
		printf(" ");

		// Increment counter
		counter++;
	}

	// Print the string
	printf("%s\n", string);

} // END CenterString


//-----------------------------------------------------------------------------
// Function Name: ChangeBlue
// Description:
//   This function will read in an integer and store at the address pointed 
//  to by the parameter.
//
//-----------------------------------------------------------------------------
void ChangeBlue(int* pAddressOfVariable)
{
	// NOTE: scanf must use an address of a variable
	// Because our parameter is already a pointer (an address) we do not need
	// to use the address operator (&).

	// Prompt the user for an integer to store in blue
	printf("(Called from inside ChangeBlue) Enter a new value: ");
	scanf("%d", pAddressOfVariable);

	// Move cursor down to the next line
	printf("\n");
}


//-----------------------------------------------------------------------------
// Function Name: ReadDouble
// Description:
//   This function will read in a double and store at the address pointed 
//  to by the parameter.
//
//-----------------------------------------------------------------------------
void ReadDouble(double* pDoublePointer)
{
	// NOTE: scanf must use an address of a variable
	// Because our parameter is already a pointer (an address) we do not need
	// to use the address operator (&).

	// Prompt user for a double
	printf("(Called from inside ReadDouble) Enter a double: ");
	scanf("%lf", pDoublePointer);

	// Move cursor down to the next line
	printf("\n");
}