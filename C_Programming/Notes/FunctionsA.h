
// Protect against recreateing data in the header file
#ifndef FUNCTIONSA_H
#define FUNCTIONSA_H

// Include for input and output to and from the screen
#include <stdio.h>

// Include so we can use the strlen function
// This header file is used in calculation to center a string
#include <string.h>

// Constants (Macro for the TAX)
#define TAX 0.08

// Constants (Macros for item numbers)
#define ONE 1
#define TWO 2
#define THREE 3

// Constant for the divider sysbols
const char STAR = '*'; // <-- STAR is used for the
const char DASH = '-';

// Constant for calculation regarding centering a string
const int SCREEN_WIDTH = 100;
const int TABLE_WIDTH = 70;

/* -- Prototypes are declarations of which functions are going to be defined -- */

// Prototypes for printing the header to the screen
void PrintHeader(void);
void PrintDivider(char symbol, int numberOf);
void CenterString(char string[], int lengthToCenterAcross);

// Prototype to calculate the cost of items (cosPerItem * quantity)
float CalculateCost(float costPerItem, int quantity);

// Prototype to calculate the cost all three items
float CalculateTotalCost(float cost1, float cost2, float cost3);

// Prototype to retrieve a float value from the keyboard
float GetFloatValue(char message[]);

// Prototype to input the number of items purchases
int GetQuantity(int itemNumber);

// Prototype to calcuste the total (sub-total + tax)
float CalculateTotal(float cost);

// Prototype for printing a value to the screen with a message
void PrintValue(char string[], float value);

// Print a table of information to the screen
void PrintTable(int quantity1, int quantity2, int quantity3,
				float costPerItem1, float costPerItem2, float costPerItem3,
				float cost1, float cost2, float cost3,
				float subTotal, float total);

// End protection
#endif
