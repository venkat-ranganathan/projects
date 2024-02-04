/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Prof. Foos 
| Course:           CS-211: Introduction to C Programming for Engineers
| Program  Name:    Functions_No_Pointers
| Date:             12/14/2022
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|   This program will as the user to enter how many of a specific item and the cost of that item.
|  Some calculations will be done and all the information will be printed to the screen. 
|
|--------------------------------------------------------------------------------------------------
| Inputs:
|   All data will be entered via the keyboard.
|  
|--------------------------------------------------------------------------------------------------
| Processing:
|   The cost (including the sales tax) will be calcualted. 
|  
|--------------------------------------------------------------------------------------------------
| Outputs:
|   All output will be sent to the screen.
|
|--------------------------------------------------------------------------------------------------
*/

// Include our header file 
#include "Functions_No_Pointers.h"

int main(void)
{
	// Variables for the first set of data
	int quantity1;
	double costPerItem1;
	double cost1;
	
	// Variables for the second set of data
	int quantity2;
	double costPerItem2;
	double cost2;
	
	// Variables for the third set of data
	int quantity3;
	double costPerItem3;
	double cost3;
	
	// Variables for the total cost and the sub-total
	double totalCost;
	double subTotal = 0.0f;

	// Move the cursor down one extra line
	printf("\n");
	
	// Function call to print the header to the screen
	PrintHeader();
	
	// Move the cursor down one extra line
	printf("\n");

	// Code to capture first set of data
	quantity1 = GetQuantity(ONE);
	costPerItem1 = GetDoubleValue("Enter the cost of item 1: ");
	cost1 = CalculateCost(costPerItem1, quantity1);
	
	// Code to capture second set of data
	quantity2 = GetQuantity(TWO);
	costPerItem2 = GetDoubleValue("Enter the cost of item 2: ");
	cost2 = CalculateCost(costPerItem2, quantity2);
		
	// Code to capture third set of data
	quantity3 = GetQuantity(THREE);
	costPerItem3 = GetDoubleValue("Enter the cost of item 3: ");
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
	
	return 0;
	
} // END main


//-----------------------------------------------------------------------------
// Function Name: PrintHeader
// Description:
//   This function will call the functions needed to print a header to the 
//  screen. 
//
//-----------------------------------------------------------------------------
void PrintHeader(void) 
{
	/*
	This function will call all the functions needed to print the header to the screen
	*/ 
	
	// Call funnction to print a divider to the screen
	PrintDivider(STAR, SCREEN_WIDTH);

	// Call functions to print three strings to center to the screen
	CenterString(SCHOOL, SCREEN_WIDTH);
	CenterString(LAB, SCREEN_WIDTH);
	CenterString(PROGRAMMER, SCREEN_WIDTH);

	// Call funnction to print a divider to the screen
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
//  accross the screen using the following formula:
//  
//    (lengthToCenterAcross + the string length) / 2
//
//-----------------------------------------------------------------------------
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


//-----------------------------------------------------------------------------
// Function Name: CalculateCost
// Description:
//   This function will multiply the two parameters together and return 
//  the result.
//
//-----------------------------------------------------------------------------
double CalculateCost(double costPerItem, int quantity)
{
	// Calculate cost of all items and return to the calling function
	return costPerItem * quantity;

} // END CalculateCost


//-----------------------------------------------------------------------------
// Function Name: CalculateTotalCost
// Description:
//   This function will add the three parameters together and return the result.
//
//-----------------------------------------------------------------------------
double CalculateTotalCost(double cost1, double cost2, double cost3)
{
	// Add the cost of all items together and return to the calling function
	return cost1 + cost2 + cost3;
	
} // END CalculateTotalCost


//-----------------------------------------------------------------------------
// Function Name: GetDoubleValue
// Description:
//   The function will disply the string that is passed in to the screen.
//  The user will then enter a double value via the keyboard. The result 
//  will be returned. 
//
//-----------------------------------------------------------------------------
double GetDoubleValue(char message[])
{
	double returnValue;

	// Prompt the user for a value and store the value in the returnValue
	printf("%s", message);
	scanf("%lf", &returnValue);

	return returnValue;
	
} // END GetDoubleValue


//-----------------------------------------------------------------------------
// Function Name: GetQuantity
// Description:
//   The item number will be passed into this function. The user will be 
//  promted to enter an integer value via the keyboard. The value will be
//  returned.  
//-----------------------------------------------------------------------------
int GetQuantity(int itemNumber)
{
	int quantity;
	
	// Prompt user for number of items 
	printf("Enter the number of items you would like for item %d: ", itemNumber);
	scanf("%d",&quantity);
	
	return quantity;
	
} // END GetQuantity


//-----------------------------------------------------------------------------
// Function Name: CalculateTotal
// Description:
//   The cost of an item will be passed into this function. The total will 
// be calculated including the tax which is a constant. The value will be 
// returned. 
//
//-----------------------------------------------------------------------------
double CalculateTotal(double cost)
{
	// Calculate the total and return to where the function was called
	return (cost * TAX) + cost;
	
} // END CalculateTotal


//-----------------------------------------------------------------------------
// Function Name: PrintTable
// Description:
//   This funtion will print a table of all the data the screen. Notes are 
//  provided in the function to show you how to format your output. 
//
//-----------------------------------------------------------------------------
void PrintTable(int quantity1, int quantity2, int quantity3,
	           double costPerItem1, double costPerItem2, double costPerItem3,
			   double cost1, double cost2, double cost3, 
			   double subTotal, double total)
{
	// Move the cursor down one line
	printf("\n");
	
	// Print table header
	PrintDivider(DASH, TABLE_WIDTH);
	CenterString(TABLE_TITLE, TABLE_WIDTH);
	PrintDivider(DASH, TABLE_WIDTH);
   
    /* NOTES ON FORMATTING VARIABLES 
       ------------------------------

	   %-24S  The 24 will create a width of 24 spaces. 
	          The string will be placed inside the width
			  Becuase the 24 is negative (-24), the string will be left justified

			  A positive 24 would make the string right justified
	*/

    // Print coloumn Header
	printf("%-24s%-24s%s\n", HEADER1, HEADER2, HEADER3);

	// printf("Quantity\t\tCost Per Item\t\tCost of all items\n");
	
	// Print a divider accross the screen
	PrintDivider(DASH, TABLE_WIDTH);

	/* NOTES ON FORMATTING VARIABLES 
       ------------------------------

	   %-24d  The 24 will create a width of 24 spaces. 
	          The integer will be placed inside the width
			  Becuase the 24 is negative (-24), the integer will be left justified

			  A positive 24 would make the string right justified

			  The %-24.2lf is for the double variables

			  The .2 is the number of decimal places 
	*/

	// Print data for the first item
	printf("%-24d$ %-22.2lf$ %-22.2lf\n", quantity1, costPerItem1, cost1);
	
	// Print data for the second item
	printf("%-24d$ %-22.2lf$ %-22.2lf\n", quantity2, costPerItem2, cost2);
	
	// Print data for the third item
	printf("%-24d$ %-22.2lf$ %-22.2lf\n", quantity3, costPerItem3, cost3);

	PrintDivider(DASH, TABLE_WIDTH);

	// Print Totals
	printf("The sub-total:  $ %.2lf\n", subTotal);
	printf("Total with tax: $ %.2lf\n\n", total);
		   
 } // END PrintTable
