
// Include header file
#include <stdio.h>

// Function Prototype - aka the declaration of a function we will write
void ChangeBlue(int *pAddressOfVariable);
void ReadInCharAndDouble(char *pCharPointer, double *pDoublePointer);

/* CLASS NOTES

	A pointer                - A variable that holds the address of anther variable

	&variable                - The ampersand is the address operator, when placed next to a
							   variable, the address of that variable is returned

	data_type * pointer_name - Declaration for a pointer

	*point_type_variable     - Dereference the variable and look at the value of the variable,
							   not the address.

*/

int main(void)
{
	// Declare an integer and assign it the value 16
	int blue = 16;

	char letter;
	double cost;

	// Decalre an integer pointer
	int *pMyValue;

	// Assigned the integer pointer to the address of blue
	pMyValue = &blue;

	// Dereferenced the integer pointer and changed the value of blue
	*pMyValue = 80;

	// Print the address of blue
	// There are two pays to do this, first use the address operator, &, next to the variable
	// The second is to print the pointer.
	printf("ADDRESS: %X\n\n", &blue);
	printf("ADDRESS: %X\n\n", pMyValue);

	// Print the new value of blue
	// There are two ways to do this, print the variable as we have done all semster
	// The second way is to dereference the pointer
	printf("Value of blue: %d\n\n", blue);
	printf("Value of blue: %d\n\n", *pMyValue);

	// Prompt the user for an integer to store in blue
	// NOTE: scanf must use an address of a variable
	// In this example we use the address operator to get the address of the variable
	printf("Enter a new value: ");
	scanf("%d", &blue);

	// Prompt the user for an integer to store in blue
	// NOTE: scanf must use an address of a variable
	// In this example we pass in the pointer which is already an address
	printf("Enter a new value: ");
	scanf("%d", pMyValue);

	// ChangeBlue is function that takes a pointer to an integer variable
	// In this example we use the address operator to pass in the address of the variable blue
	ChangeBlue(&blue);

	// Print the new value for the varaible blue
	printf("Value of blue: %d\n\n", blue);

	// ChangeBlue is function that takes a pointer to an integer variable
	// In this example we use the pointer to the variable blue to pass in
	// the address of the variable blue
	ChangeBlue(pMyValue);

	// Print the new value for the varaible blue, execept this time, dereference the pointer
	printf("Value of blue: %d\n\n", *pMyValue);

	// ReadInCharAndDouble is function that takes two pointers, Both variables will be
	// input and output
	ReadInCharAndDouble(&letter, &cost);

	// Print the new value for letter and cost.
	printf("letter = %c\n\n", letter);
	printf("cost = %.2lf\n\n", cost);

	return 0;
}

void ChangeBlue(int *pAddressOfVariable)
{
	// Prompt the user for an integer to store in blue
	// NOTE: scanf must use an address of a variable
	printf("Enter a new value: ");
	scanf("%d", pAddressOfVariable);
}

void ReadInCharAndDouble(char *pCharPointer, double *pDoublePointer)
{
	// Prompt user for a character
	printf("Enter a character: ");
	scanf("%s", pCharPointer);

	// Prompt user for a double
	printf("Enter a double: ");
	scanf("%lf", pDoublePointer);
}