// preprocessor directives
#include <stdio.h>

// function prototypes
int searchArray(int array[], int arraySize, int tagField);

// main function
int main()
{
    // declare MAX_SIZE as an integer that will determine how many elements will be in the array
    int MAX_SIZE = 0;

    // declaring array of any size
    int array[] = {};

    // tagField is the specific number we're going to be looking for in our array
    int tagField = 0;

    // ask user to set how many elements will be in the array
    printf("Enter how many elements will be in the array: ");

    // store in memory location of variable MAX_SIZE
    scanf("%d", &MAX_SIZE);

    // use a loop to store the values in the array;
    for (int i = 1; i <= MAX_SIZE; i++)
    {
        // ask user to enter elements one-by-one
        printf("Enter an integer for array[%d]: ", i);

        // store each entered element into its corresponding array
        scanf("%d", &array[i]);

        // next line
        printf("\n");
    }

    // set value to search for in the array
    printf("Enter the value you want to search for in the array: ");
    scanf("%d", &tagField);

    // pass values to to function and print out result simultaneously
    printf("\nThe value %d appears %d times in the array\n", tagField, searchArray(array, MAX_SIZE, tagField));

    return 0;
}

// function
int searchArray(int array[], int arraySize, int tagField)
{
    // declaring counter as an integer with initial value 0
    int counter = 0;

    // I'm using a loop to go through the array and incrementing a counter each time it encounters the tagField value
    for (int i = 1; i <= arraySize; i++)
    {
        // checking if the tagField shows up in the array, and incrementing counter if it does
        if (array[i] == tagField)
        {
            // increment counter
            counter++;
        }
    }

    // return the counter value once the loop is done
    return counter;
}