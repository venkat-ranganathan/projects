// preprocessor directive
#include <stdio.h>

// function protype with a pointer variable; "int *" is the data type;
void pointer(int *pValueA, int *pValueB);
void swap(int *sm, int *md, int *lg);

// pointers are an address
// every bite of memory has an address
// size of memory address: 64-bit, 8 bytes; 32-bit, 4 bytes

int main()
{
    // integer takes up 4 bytes of memory
    int value = 80;

    // declare pointer and set it equal to memory address of integer variable
    int *pValue = &value;

    // declaring pointer value (pValue) as a new value will change the value of the original variable
    // because originally set pointer variable to equal the memory address of the other variable
    *pValue = 85;

    // to print value of variable
    printf("%d\n", value);

    // to print address of variable; '&' is the address operator
    // '%X' prints the address as a hexidecimal value
    printf("%X\n", &value);

    // print memory address stored in pointer variable, because it references the memory address of value
    printf("%X\n", pValue);

    // print value pointer memory; "*pValue" is dereferncing the pointer
    // prints the same thing as just printing the value of the original variable
    printf("%d\n", *pValue);

    // new variables for pointer function
    int first = 16;
    int second = 80;

    // want to swap values of first and second variable, so sending address of both to pointer function
    // sending address of first variable to first pointer variable, and second for second
    pointer(&first, &second);

    // for new function swap
    int sm = 100;
    int md = 99;
    int lg = 3;

    swap(&sm, &md, &lg);
}

// this function used to swap values of pointers
void pointer(int *pValueA, int *pValueB)
{
    // dereference pointer to show what's in the pointer variable
    int temp = *pValueA;

    // now derference pointer of first pointer variable and set it equal to dereferenced value of second pointer variable
    // this swaps their values
    *pValueA = *pValueB;

    *pValueB = temp;

    // prints out same pointer values, but now wiht switched values
    // to print multiple variables from the same printf, use 'n' bumber of "%"
    printf("%d\t%d\n", *pValueA, *pValueB);
}

// manually swapping values using conditionals
// this is just an example of changing values, the logic isn't complete
void swap(int *sm, int *md, int *lg)
{
    // swaps values in md and sm if value in sm is greater than value in md
    if (md < sm)
    {
        int temp = *md;
        *md = *sm;
        *sm = temp;
    }

    // swaps values in lg and sm if value in sm is greater than value in lg
    else if (lg < sm)
    {
        int temp = *lg;
        *lg = *sm;
        *sm = temp;
    }

    // swaps values in lg and md if value in md is greater than value in lg
    if (lg < md)
    {
        int temp = *lg;
        *lg = *md;
        *md = temp;
    }

    // swaps values in md and sm if value in sm is greater than value in md
    if (md < sm)
    {
        int temp = *md;
        *md = *sm;
        *sm = temp;
    }

    printf("%d\t%d\t%d\n", *sm, *md, *lg);
}
