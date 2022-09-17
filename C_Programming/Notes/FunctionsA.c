
// Include our header file
#include "FunctionsA.h"

int main(void)
{
	// Variables for the first set of data
	int quantity1;
	float costPerItem1;
	float cost1;

	// Variables for the second set of data
	int quantity2;
	float costPerItem2;
	float cost2;

	// Variables for the third set of data
	int quantity3;
	float costPerItem3;
	float cost3;

	// Variables for the total cost and the sub-total
	float totalCost;
	float subTotal = 0;

	// Move the cursor down one extra line
	printf("\n");

	// Function call to print the header to the screen
	PrintHeader();

	// Move the cursor down one extra line
	printf("\n");

	// Code to capture first set of data
	quantity1 = GetQuantity(ONE);
	costPerItem1 = GetFloatValue("Enter the cost of item 1: ");
	cost1 = CalculateCost(costPerItem1, quantity1);

	// Code to capture second set of data
	quantity2 = GetQuantity(TWO);
	costPerItem2 = GetFloatValue("Enter the cost of item 2: ");
	cost2 = CalculateCost(costPerItem2, quantity2);

	// Code to capture third set of data
	quantity3 = GetQuantity(THREE);
	costPerItem3 = GetFloatValue("Enter the cost of item 3: ");
	cost3 = CalculateCost(costPerItem3, quantity3);

	// Function call to add up the subtotal
	subTotal = CalculateTotalCost(cost1, cost2, cost3);

	// Function call to calculate the total cost
	totalCost = CalculateTotal(subTotal);

	// Function call to print the table to the screen
	PrintTable(quantity1, quantity2, quantity3,
			   costPerItem1, costPerItem2, costPerItem3,
			   cost1, cost2, cost3,
			   subTotal, totalCost);

	// Move the cursor down one extra line
	printf("\n");

	return 0;

} // END main

void PrintHeader(void)
{
	/*
	This function will call all the functions needed to print the header to the screen
	*/

	// Call funnction to print a divider to the screen
	PrintDivider(STAR, SCREEN_WIDTH);

	// Call functions to print three strings to center to the screen
	CenterString("Binghamton University", SCREEN_WIDTH);
	CenterString("September 7, 2022", SCREEN_WIDTH);
	CenterString("Sample Functions Program", SCREEN_WIDTH);

	// Call funnction to print a divider to the screen
	PrintDivider(STAR, SCREEN_WIDTH);

} // End PrintHeader

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

void CenterString(char string[], int lengthToCenterAcross)
{
	// Capture how long the string is
	// Cast to an integer becuase strlen technically returns size_t
	int stringLength = (int)strlen(string);

	// Calaculate the width to print the string in
	int width = (lengthToCenterAcross + stringLength) / 2;

	// Calcuate how many blank spaces are needed before printing the string
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

float CalculateCost(float costPerItem, int quantity)
{
	// Calculate cost of all items and return to the calling function
	return costPerItem * quantity;

} // END CalculateCost

float CalculateTotalCost(float cost1, float cost2, float cost3)
{
	// Add the cost of all items together and return to the calling function
	return cost1 + cost2 + cost3;

} // END CalculateTotalCost

float GetFloatValue(char message[])
{
	float returnValue;

	// Prompt the user for a value and store the value in the returnValue
	printf("%s", message);
	scanf("%f", &returnValue);

	return returnValue;

} // END GetFloatValue

int GetQuantity(int itemNumber)
{
	int quantity;

	// Prompt user for number of items
	printf("Enter the number of items you would like for item %d: ", itemNumber);
	scanf("%d", &quantity);

	return quantity;

} // END GetQuantity

float CalculateTotal(float cost)
{
	// Calculate the total and return to where the function was called
	return (cost * TAX) + cost;

} // END CalculateTotal

void PrintValue(char string[], float value)
{
	/*
	This function will print a descriptive message to the screen and then print the
	value next to the message.
	*/

	// Print messsage and value to the screen
	printf("%s %.2f\n", string, value);

} // END PrintValue

void PrintTable(int quantity1, int quantity2, int quantity3,
				float costPerItem1, float costPerItem2, float costPerItem3,
				float cost1, float cost2, float cost3,
				float subTotal, float total)
{
	// Move the cursor down one line
	printf("\n");

	// Print table header
	PrintDivider(DASH, TABLE_WIDTH);
	CenterString("CS-211 Financial Report", TABLE_WIDTH);
	PrintDivider(DASH, TABLE_WIDTH);

	// Print coloumn Header
	printf("Quantity\t\tCost Per Item\t\tCost of all items\n");
	printf("--------\t\t-------------\t\t-----------------\n");

	// Print data for the first item
	printf("%d\t\t\t$ %.2f\t\t\t$ %.2f\n", quantity1, costPerItem1, cost1);

	// Print data for the second item
	printf("%d\t\t\t$ %.2f\t\t\t$ %.2f\n", quantity2, costPerItem2, cost2);

	// Print data for the third item
	printf("%d\t\t\t$ %.2f\t\t\t$ %.2f\n\n", quantity3, costPerItem3, cost3);

	// Print Totals
	PrintValue("The sub-total:  $ ", subTotal);
	PrintValue("Total with tax: $ ", total);

} // END PrintTable
