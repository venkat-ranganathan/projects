
// Header file safe guards - Protect against recreateing data in the header file 
#ifndef FUNCTIONS_NO_POINTERS_H
#define FUNCTIONS_NO_POINTERS_H

// Include for input and output to and from the screen
#include <stdio.h>

// Include so we can use the strlen function
// This header file is used in calculation to center a string
#include <string.h>

// Constants (Macro for the TAX)
#define TAX 0.08f

// Constants (Macros for item numbers)
#define ONE   1
#define TWO   2
#define THREE 3

// Constants (Macros for the header)
#define SCHOOL "Binghamton University"
#define LAB "Function example with no pointers"
#define PROGRAMMER "Written by: Mr. Foos"

// Constants (Macro for the table header)
#define TABLE_TITLE "CS-211 Financial Report"
#define HEADER1 "Quantity"
#define HEADER2 "Cost Per item"
#define HEADER3 "Cost of all items"

// Constant for the divider sysbols
const char STAR = '*';  
const char DASH = '-';

// Constant for calculation regarding centering a string
const int SCREEN_WIDTH = 100;
const int TABLE_WIDTH  = 70;

/* -- Prototypes are declarations of which functions are going to be defined -- */

// Prototypes for printing the header to the screen
void PrintHeader(void);
void PrintDivider(char symbol, int numberOf);
void CenterString(char string[], int lengthToCenterAcross);

// Prototype to print a divider accross the screen
void PrintDivider(char symbol, int numberOf);

// Prototype to calculate the cost of items (cosPerItem * quantity)
double CalculateCost(double costPerItem, int quantity);

// Prototype to calculate the cost all three items 
double CalculateTotalCost(double cost1, double cost2, double cost3);

// Prototype to retrieve a double value from the keyboard
double GetDoubleValue(char message[]);

// Prototype to input the number of items purchases
int GetQuantity(int itemNumber);

// Prototype to calcuste the total (sub-total + tax)
double CalculateTotal(double cost);

// Print a table of information to the screen
void PrintTable(int quantity1, int quantity2, int quantity3,
	           double costPerItem1, double costPerItem2, double costPerItem3,
			   double cost1, double cost2, double cost3, 
			   double subTotal, double total);

// End header file safe guards			   
#endif
