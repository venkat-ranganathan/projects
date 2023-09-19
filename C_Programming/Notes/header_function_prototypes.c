#include "Header.h"

// prototype needs a semicolon
void PrintHeader(void);
void PrintDivider(void);
void PrintCost(char name[], double price);
double GetDoubleValue(char message[]);
double CalculateTotal(double total);

// also declare prototype inside header file

int main(void)
{
    double cost;

    // array includes null terminator at the end \0
    char string[] = "hello world";

    char words[] = "blah blah blah";

    cost = 19.95;

    // look up pass by value and pass by copy

    // commented out PrintDivider(); because you can just call it inside the PrintHeader() function

    // PrintDivider();

    PrintHeader();

    // PrintDivider();

    // passing double "cost" to function PrintCost, PrintCost changes the variable name to "price" and uses it in its function

    // printf(string);
    PrintCost(string, cost);

    // printf("Cost = %.2f\n", cost);

    GetDoubleValue(words);

    CalculateTotal(cost);

    return 0;
}

// function header has no semicolon
void PrintHeader(void)
{
    // call function within a function

    PrintDivider();

    printf("\nBinghamton University\n");
    printf("\nSeptember 6, 2022\n");

    PrintDivider();
}

void PrintDivider(void)
{
    // print a bunch of stars
    printf("\n*********************************************************\n");
}

void PrintCost(char name[], double price)
{
    printf("\nThe cost is: %.2f\n", price);

    // for strings, need %s

    printf("\nThis is the value of the string: %s\n", name);

    // don't need to include [] in array variable inside the function
}

double GetDoubleValue(char message[])
{
    // double returnValue;

    // promt user for a value

    printf("%s ", message);

    // scanf_s("%lf", &returnValue);

    // return returnValue;
}

double CalculateTotal(double total)
{
    double final_cost;

    final_cost = (1 + TAX) * total;

    // make sure you're using the correct modifier for the data type, double is 'f' not 'd'

    printf("\nThe value of the total is : %.2f\n", total);
    printf("\nThe value of tax is : %.4f\n", TAX);
    printf("\nThe total cost is: %.2f\n", final_cost);
}