// Include that for input and output to and from the screen
#include <stdio.h>

// Include for toupper function
#include <ctype.h>

// Include for strcpy fucntion
#include <string.h>

/* NOTES ON IF-STATEMENTS
----------------------------------------------

	Every test evaluates to true or false
	Examples:
		(age >= 18)
		(age >= 16)
		(value == 100)
		(someChar != 'J')

	Relational Operators:
	---------------------
	  >		Greater than
	  <		Less than
	  >=	Greater than or equal to
	  <=	Less than or equal to
	  ==	Equal to
	  !=	Not equal to

	  Logical Operators:
	  -------------------
	  &&	and
	  ||	or
	  !		not operator

	  Examples of compound test
	  (age >= 18 && value != 7)
	  (selection > 0 && selection < 4)
	  (selection < 1 || selection > 3)

*/

int main(void)
{

	int value;

	value = 10;

	// Example of a simple if-statement
	if (value == 10)
	{
		// Execute if the test is true
		// if the test is false this code is skipped

		// Print message to the screen
		printf("value is equal to 10\n");
	}

	// Example of a simple if-else statement
	if (value == 16)
	{
		// Execute if the test is true
		// If the test is false this code is skipped

		// Print message to the screen
		printf("value is equal to 16\n");
	}
	else
	{
		// Execute if the test is false
		// If the test was true, this code would be skipped

		// Print message to the screen
		printf("value is NOT equal to 16\n");
	}

	// Example of a simple if-else-if statement
	if (value == 16)
	{
		// Execute of the test is true
		// If the test is true, all the remaining
		// if-statements will be skipped

		// Print message to the screen
		printf("Value is equal to 16\n");
	}
	else if (value == 8)
	{
		// This code will execute if the first if-statement is false
		// and the second if-statement is true. If the second if-statement
		// is also false, this code will also be skipped.

		// Print message to the screen
		printf("Value is equal to 8\n");
	}

	// Exmaine the if-else below.
	// (The code to execute for each test has has been ommited for simplicity)
	// Notice there are many else-if conditions.
	// You may have as many as needed, each one will be evaluated until one test
	// becomes true. When a test is true, the remaining if-statements will be skipped.
	// Also notice that last block is an else, which is a catch all remaining conditions.

	/*
	if (value == 10)
	{

	}
	else if (value == 16)
	{

	}
	else if (value == 20)
	{

	}
	else if (value == 25)
	{

	}
	else
	{

	}
*/

	// A switch statement is an extension of a series of if-else
	// Below is the equivlant of the above if-else statements
	switch (value)
	{
	// If value equals 10 then print the message to the screen
	case 10:
		// Print message to the screen
		printf("value == 10");
		break;

	// If value equals 16 then print the message to the screen
	case 16:
		// Print message to the screen
		printf("value == 16");
		break;

	// If value equals 20 then print the message to the screen
	case 20:
		// Print message to the screen
		printf("value == 20");
		break;

	// If value equals 25 then print the message to the screen
	case 25:
		// Print message to the screen
		printf("value == 25");
		break;

	// This is just like an else, and is a catch all
	// The default case is shown here, but it is not needed
	// Just like you don't have to end an if-statement with and else
	default:

		break;
	}

	// EXAMPLE OF A SWITCH STATEMENT

	int vowelCounter = 0;
	int letterECounter = 0;

	char character;

	// Prompt user for a letter
	printf("Enter a letter: ");
	scanf("%s", &character);

	// Covert character to an uppercase letter
	character = toupper(character);

	switch (character)
	{
	case 'E':
		// Increment counter
		letterECounter++;

	case 'A':
	case 'I':
	case 'O':
	case 'U':
		// Increment counter
		vowelCounter++;
		break;
	}

	//----------------------------------------------

	unsigned int cholestoral;
	char message[21];

	/*
		Cholestoral   Message
		----------------------
		0-90 		  Low
		91-110		  Medium
		110 and up    High
	*/

	//
	// First we will solve this problem with compound if-statements
	//

	// Prompt user for cholestoral
	printf("Enter your cholestoral: ");
	scanf("%d", &cholestoral);

	if (cholestoral >= 0 && cholestoral <= 90)
	{
		// Assign message to Low
		strcpy(message, "Low");
	}
	else if (cholestoral >= 91 && cholestoral <= 110)
	{
		// Assign message to Medium
		strcpy(message, "Medium");
	}
	else
	{
		// Assign message to High
		strcpy(message, "High");
	}

	// Print message
	printf("%s", message);

	//
	// Now let's solve the problem with a nested if-statement
	//

	// Prompt user for cholestoral
	printf("Enter your cholestoral: ");
	scanf("%d", &cholestoral);

	// Start by assuming the message is Low
	strcpy(message, "Low");

	if (cholestoral > 90)
	{
		// Change message to Medium
		strcpy(message, "Medium");

		if (cholestoral > 110)
		{
			// Change message to High
			strcpy(message, "High");
		}
	}

	// Print message
	printf("%s", message);

	//-----------------------------------------------
	// Bit Manipulation

	// Every integer is 4 bytes or 32 bits.
	// For the examples below we will only use the first byte of data

	// EXAMPLE #1:

	int A = 157; // (10011101)
	int B = 115; // (01110011)

	// Bitwise AND with 157 and 115
	int ans = A & B;

	// Print answer to the scren
	printf("157 & 115 = %d\n", ans);

	// EXAMPLE #2:

	// Assign X a random value
	int X = 118;

	// But I only want to check bits 3 and 4
	// Bits 3 and 4 are 24 (00011000)

	// So let's create a constant for 24

	// This should be declared above the main or in a header file
	// but for this example, we will just leave here.
	const int MASK_34 = 24;

	// Use a bitwise logical AND to obtain the value of bits 3 and 4
	int code = X & MASK_34;

	// shift code 3 spots to the right so that bits 3 and 4 are
	// located in bits 0 and 1
	code = code >> 3;

	// Print the code to the screen
	printf("Code = %d\n", code);

	return 0;
}