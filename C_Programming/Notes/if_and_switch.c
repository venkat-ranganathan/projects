// preprocessor directive
#include <stdio.h>

// function prototypes
void if_statement(int code);
void switch_statement(int code);

// main statement
int main()
{
    // declare code as an integer
    int code;

    // ask user to enter a code value and save in code variable
    printf("Select code value 10, 20, or another value: ");
    scanf("%d", &code);

    // pass entered code value to if_statement function
    if_statement(code);

    // pass entered code value to switch_statement function
    switch_statement(code);

    return 0;
}

// PART A
void if_statement(int code)
{
    // declare cost as a float with initial value 0
    float cost = 0;

    // conditionals
    if (code == 10)
    {
        cost = 17.75;
    }

    else if (code == 20)
    {
        cost = 19.95;
    }

    else
    {
        cost = 21.50;
    }

    // prints cost value based on which condition was met
    printf("If statement value of cost is: %.2f \n", cost);
}

// PART B
void switch_statement(int code)
{
    // declare cost as a float with initial value 0
    float cost = 0;

    // apply switch cases
    switch (code)
    {
    case 10:
        cost = 17.75;
        break;

    case 20:
        cost = 19.95;
        break;

    default:
        cost = 21.50;
        break;
    }

    // prints cost value based on which condition was met
    printf("Switch statement value of cost is: %.2f \n", cost);
}