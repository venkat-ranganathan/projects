// Example of how to use declare prototype function, create function, and call function in main code

// preprocessor directives

#include <stdlib.h>
#include <stdio.h>

// prototype function

float protoFunction(int quantity, float cost);

// main function

int main()
{
    // declare variables

    float itemCost, totalCost;
    int itemQuantity;

    // ask user to enter variable value for item cost
    // don't include data type modulus for printf() if you aren't printing out a variable value

    printf("\nEnter the cost of the item: $");

    // need to use reference operator '&' when storing user-input data into variable
    // store value in variable
    // DO include data type modulus for scanf()
    // don't set a modulus decimal place limit for the input value

    scanf("%f", &itemCost);

    // ask user to enter variable value for item quantity

    printf("\nEnter the number of items: ");

    // store value in variable

    scanf("%d", &itemQuantity);

    // pass variables to protoFunction and call function

    totalCost = protoFunction(itemQuantity, itemCost);

    // print result of function calculation

    // if you want specific decimal places, you need to include the decimal value AFTER the modulus (%)

    printf("\nThe total cost is: $%.2f\n", totalCost);

    return 0;
}

// function

float protoFunction(int quantity, float cost)
{
    // for a function whose only purpose is running a calculation, it's simpler to just return the
    // value of the calculation

    return quantity * cost;
}