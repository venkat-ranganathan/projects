#include <stdio.h>

// function prototypes

void InitializeArray(int array[]);

void PrintArray(int array[]);

void AddTenToEachElement(int numbers[]);

int TotalArray(int numbers[]);

void PrintTotal(int total);

double CalculateAverage(int numbers[]);

void PrintAverage(double average);

// global constant

#define SIZE 5

int main(void)
{
    // sets numbers as an array with 5 entries

    int numbers[SIZE];

    // declare total and average

    int total;
    double average;

    // call functions

    InitializeArray(numbers);

    PrintArray(numbers);

    AddTenToEachElement(numbers);

    PrintArray(numbers);

    // define total to call function TotalArray()

    total = TotalArray(numbers);

    PrintTotal(total);

    // define average to call function CalculateAverage()

    average = CalculateAverage(numbers);

    PrintAverage(average);

    return 0;
}

void InitializeArray(int array[])
{
    // local variable

    int counter = 0;

    // keep repeating code until counter value is less than the global variable SIZE
    while (counter < SIZE)
    {
        // asks to enter value, and prints out current array value the value will be stored in

        printf("Enter value for element %d: ", counter);

        // entered value will be stored in the array position determined by counter

        scanf("%d", &array[counter]);

        // increments counter and continues loop until break condition is met

        counter++;
    }

    // add new line when loop completes

    printf("\n");
}

void PrintArray(int array[])
{
    int counter = 0;

    // prints header to the user

    printf("     NUMBERS\n");
    printf("     -------\n");

    while (counter < SIZE)
    {
        // \t is a tab, so this hits tab, tells the code to expect an integer, plugs in the value stored in the array
        // in position counter and then goes to a new line

        printf("\t%d\n", array[counter]);

        // changer

        counter++;
    }

    // prints new line

    printf("\n");
}

void AddTenToEachElement(int numbers[])
{
    int counter = 0;

    while (counter < SIZE)
    {
        // += is the same thing as numbers[counter] = numbers[counter] + 10

        numbers[counter] += 10;

        // changer

        counter++;
    }
}

int TotalArray(int numbers[])
{
    int total = 0;
    int counter = 0;

    while (counter < SIZE)
    {
        // continously adds the values of the array together
        // total = total + numbers[counter];

        total += numbers[counter];

        counter++;
    }

    // returns the final value of total

    return total;
}

void PrintTotal(int total)
{
    printf("Total: %d\n\n", total);
}

double CalculateAverage(int numbers[])
{
    double average = 0;

    int total;

    // executes code so long as SIZE doesn't equal zero

    if (SIZE != 0)
    {
        total = TotalArray(numbers);

        // treats the integer total as a double so the average is a decimal value

        average = (double)total / SIZE;
    }

    // returns the final average after the conditional ends

    return average;
}

void PrintAverage(double average)
{
    // %0.2 will print 2 decimal places
    // lf is the modulus operator for double

    printf("Average: %0.2lf\n\n", average);
}