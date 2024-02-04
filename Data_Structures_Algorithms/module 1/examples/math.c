/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Prof. Foos
| Course:           CS-211: Introduction to C for Engineers
| Program  Name:    Simple Math Program
| Date:             12/19/2022
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|   This program will display the user with a menu of options that include simple math operations.
|  The answer will be calculated and printed to the screen.
|
|   This program will use the following programming skills:
|     > A do-while loop
|     > A switch statement
|     > Functions with pass by values
|     > Functions with pass by pointers
|
|--------------------------------------------------------------------------------------------------
| Inputs:
|   Input will be provide by the user via the keyboard.
|
|--------------------------------------------------------------------------------------------------
| Processing:
|   The following calculations will be made based on the user's selection.
|     > addition, subtraction, multiplication, division
|
|--------------------------------------------------------------------------------------------------
| Outputs:
|   The output will be displayed to the screen
|
|--------------------------------------------------------------------------------------------------
*/

// Include for input and output to and from the screen
#include <stdio.h>

// Prototypes
void PrintMenu(void);
int GetUsersChoice(void);
void GetTwoNumbers(int* number1, int* number2);
double ExecuteSelection(int selection, int number1, int number2);
void PrintResult(double answer);

// Set the error code
const unsigned int ERROR_CODE = -1;

int main(void)
{
	int choice;
	int number1;
	int number2;

	double answer;

	do
	{
		// Print a menu
		PrintMenu();

		// Get the choice from the user
		choice = GetUsersChoice();

		// Check to see if the user chooses to exit the program
		if (choice != 0)
		{
			// Get the two numbers
			GetTwoNumbers(&number1, &number2);

			// Execute the operation
			answer = ExecuteSelection(choice, number1, number2);

			// Print the results
			PrintResult(answer);

		} // CLOSE if-statement

	} while (choice != 0);

	return 0;
}


//-----------------------------------------------------------------------------
// Function Name: PrintMenu
// Description:
//   A menu is printed to the screen.
//
//-----------------------------------------------------------------------------
void PrintMenu(void)
{
	// Print menu to the screen
	printf("\t1) Addition\n");
	printf("\t2) Subtraction\n");
	printf("\t3) Multiply\n");
	printf("\t4) Division\n");
	printf("\t0) Quit\n");
}


//-----------------------------------------------------------------------------
// Function Name: GetUsersChoice
// Description:
//    The user will be prompted to enter a selection.  The response will be 
//  returned via a function return. 
//
//-----------------------------------------------------------------------------
int GetUsersChoice(void)
{
	// Declare a local variable
	int choice;

	// Print prompt to the screen
	printf("\n\tEnter selection: ");

	// Get choice from the keyboard
	scanf("%d", &choice);

	// Return the choice to where the function was called
	return choice;

}


//-----------------------------------------------------------------------------
// Function Name: GetTwoNumbers
// Description:
//   This function will ask the user for two integer values.
//
//   Notice that the parameters are pointers. This is because we want the 
//  answer to be retained after the function exits. 
//
//   Also notice that the scanf function call does not use the address 
//  operator (&). This is because number1 and number2 are already pointers 
//  (A definition of a pointer is an address)
// 
//-----------------------------------------------------------------------------
void GetTwoNumbers(int* number1, int* number2)
{
	// Prompt user for number1
	printf("Enter first number: ");
	scanf("%d", number1);

	// Prompt user for number2
	printf("Enter second number: ");
	scanf("%d", number2);
}


//-----------------------------------------------------------------------------
// Function Name: ExecuteSelection
// Description:
//   This function will use a switch statement to perform the appropriate 
//  calculation. If an invalid selection was made, an error code will be 
//  returned. 
//
//-----------------------------------------------------------------------------
double ExecuteSelection(int selection, int number1, int number2)
{
	// Declare a local variable
	double answer;

	switch (selection)
	{
	case 1:
		// Perform addition
		answer = number1 + number2;
		break;

	case 2:
		// Perform subtraction
		answer = number1 - number2;
		break;

	case 3:
		// Perform multiplication
		answer = number1 * number2;
		break;

	case 4:
		// Check for divide by 0
		if (number2 != 0)
		{
			// Perform division
			answer = (double)number1 / number2;
		}
		else
		{
			// If there is divide by 0, set the answer to 0
			answer = 0;
		}

		// Shorthand if-statement
		// answer = (number2 != 0) ? ((double)number1 / number2) : 0;
		break;

	default:
		// Set answer to the error code
		answer = ERROR_CODE;

		// Print error message
		printf("\nInvalid selection\n");
		break;

	}

	return answer;
}


//-----------------------------------------------------------------------------
// Function Name: PrintResult
// Description:
//   If the answer does not equal the error code, the answer will be
//  printed to the screen showing 3 decimal places
//
//-----------------------------------------------------------------------------
void PrintResult(double answer)
{
	// Check for error code
	if (answer != ERROR_CODE)
	{
		// Print result to the screen
		printf("\nResult = %.3lf\n\n", answer);
	}
}