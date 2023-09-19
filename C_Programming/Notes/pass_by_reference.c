// preprocessor directive
#include <stdio.h>

// general pseudocode to explain various ways to pass data
void main()
{
    int value;
    int array[10]; // array is a pointer on its own
    int *pInt;

    foo(&array[3]); // passes reference
    foo2(pInt);     // passes pointer
    foo3(*pInt);    // passes integer
    foo4(*array);   // pass dereferenced pointer, which is the first element of the array
}

void foo(int *z)
{
}

void foo2(int *z)
{
}

void foo3(int z)
{
}

void foo4(int z)
{
}

int strcmp(char str1[], char str2[])
{
    /*

    Return Value

    0 - if the strings are equal
    >0 - if str1 > str2
    <0 - if str1 < str2

    */

    return 0;
}