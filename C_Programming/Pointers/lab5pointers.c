// preprocessor directives
#include "lab5pointers.h"

// functions
int flipSign(int *x)
{
    // if "x" is pointing to a positive or negative value: switch the signs of the value and return '1'
    if (*x > 0 || *x < 0)
    {
        // if condition met, switches sign of value
        *x = -*x;

        // then returns 1 to complete function
        return 1;
    }

    // if "x" is pointing to a '0' value: return '0'
    else
    {
        // returns 0 if x is pointing to 0
        return 0;
    }
}

int compareAndSwap(int *x, int *y)
{
    // if "x" and "y" are both pointing to the same value: return '0'
    if (*x == *y)
    {
        return 0;
    }

    // if "x" is pointing to a value that is less than the value "y" is pointing to: return '1'
    else if (*x < *y)
    {
        return 1;
    }

    /* if "y" is pointing to a value that is less than the value "x" is pointing to: swap the values
    that are pointed to by the pointers "x" and "y", then return '-1' */
    if (*x > *y)
    {
        // declare temporary variable and store value in memory address of variable 'x'
        int temp = *x;

        // copy value in memory address of variable 'y' into memmory location of variable 'x'
        *x = *y;

        // set original value stored in memory address of variable 'x' into memory address of variable 'y'
        *y = temp;

        // returns -1 to complete function
        return -1;
    }
}

int *searchArray(int array[], int size, int item)
{
    // if "item" is found in the "array": return the address of the "item" location in the "array"
    // AS AN INTEGER POINTER
    // need loop to search through array value-by-value
    // for loop increments from 0 to integer "size"
    for (int i = 0; i <= size; i++)
    {
        // conditionally searches through array elements to search for integer "item"
        if (array[i] == item)
        {
            // returns memory address of array element where search term is stored and completes function
            return &array[i];
        }
    }

    // if "item" is not found in the "array": return "NULL"
    return NULL;
}

int copyString(char str1[], char str2[])
{
    // copy a given string "str1" (array of characters) to another "str2" (array of characters)

    // use for loop to cycle from 0 until the size of the array is reached
    for (int i = 0; i <= strlen(str1); i++)
    {
        // store each element of str1 into corresponding element of str2
        str2[i] = str1[i];
    }

    // the function should return the size of the string copied into "str2" including the null termination character
    // adding a 1 to strlneg(str2) to account for null terminator
    return strlen(str2) + 1;
}