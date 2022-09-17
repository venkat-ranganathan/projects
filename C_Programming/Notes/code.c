
#include <stdio.h>

const int FEET = 12;

int main(void)
{
	int counter;
	int inches;
	int totalInches;
	int feet;
	int remainingInches;

	// Set variables to 0
	counter = 0;
	totalInches = 0;

	// FIRST CALCULATIONS -----------------------------------------

	// Increase counter
	counter++;

	// Prompt the user for inches
	printf("Enter height in inches: ");
	scanf("%d", &inches);

	totalInches += inches;

	feet = inches / FEET;
	remainingInches = inches % FEET;

	printf("Inches          = %d\n", inches);
	printf("feet            = %d\n", feet);
	printf("remainingInches = %d\n", remainingInches);
	printf("totalInches     = %d\n", totalInches);

	// SECOND CALCULATIONS -----------------------------------------

	// Increase counter
	counter++;

	// Prompt the user for inches
	printf("Enter height in inches: ");
	scanf("%d", &inches);

	totalInches += inches;

	feet = inches / FEET;
	remainingInches = inches % FEET;

	printf("Inches          = %d\n", inches);
	printf("feet            = %d\n", feet);
	printf("remainingInches = %d\n", remainingInches);
	printf("totalInches     = %d\n", totalInches);

	// THIRD CALCULATIONS -----------------------------------------

	// Increase counter
	counter++;

	// Prompt the user for inches
	printf("Enter height in inches: ");
	scanf("%d", &inches);

	totalInches += inches;

	feet = inches / FEET;
	remainingInches = inches % FEET;

	printf("Inches          = %d\n", inches);
	printf("feet            = %d\n", feet);
	printf("remainingInches = %d\n", remainingInches);
	printf("totalInches     = %d\n", totalInches);

	return 0;
}