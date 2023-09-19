// How to use pointers
// every bite of memory has an address
// A pointer is an address

// int *variableName; int data type pointer
// pointer naming convention: int *pMyValue (MyValue is what you replace with whatever name you choose)
// start variable name with lower case p, so you know it's a pointer

// Header
#include <stdio.h>
#include <stdlib.h>

// Function Prototype aka declaration of a function
void ChangeBlue(int *pAddressOfVariable);
void ReadInCharAndDouble(char *pCharPointer, double *pDoublePointer);

int main()
{
    // integer is 4 bytes

    int blue = 16;
    double cost = 12.23;
    char letter = 'a';

    // don't name the pointer the same as the variable name it's referencing, set it equal to the address of the variable
    // of interest

    // set pointer equal to the address
    // '*' is called the dereference operator

    // this is both the pointer declaration and pointer deference

    int *pMyVariable = &blue;

    // this stores the value into the pointer, which is pointing to the memory address of the variable 'blue'

    *pMyVariable = 80;

    // '&' is the address operator
    // this will print what's stored in the address of the variable

    /*     // this prints the VALUE of what's stored in the memory address of 'blue'
        printf("The value stored in the memory address of blue: %d\n", blue);

        // this prints the MEMORY ADDRESS of blue
        // %X prints the HEXADECIMAL ADDRESS of the variable

        printf("Address of blue is: %X\n", &blue);

        printf("Enter a new value: ");
        scanf("%d", &blue);

        printf("\nThis is the new value of the variable 'blue': %d\n", blue);
        printf("\nThis is the new HEX MEMORY ADDRESS of the variable 'blue': %X\n", &blue);

        // Print the address of blue
        printf("ADDRESS: %X\n\n", &blue);
        printf("ADDRESS: %X\n\n", pMyVariable);

        // Print the new value of blue
        printf("Value of blue: %d\n\n", blue);
        printf("Value of blue: %d\n\n", *pMyVariable);

        // Prompt user for an integer to store in blue
        // NOTE: scanf must use an address of a variable
        printf("Enter a new value: ");
        scanf("%d", &blue);

        // Prompt the user for an integer to store in blue
        // NOTE: scanf must use an address of a variable
        printf("Enter a new value: ");
        scanf("%d", pMyVariable); */

    ChangeBlue(&blue);
    ReadInCharAndDouble(&letter, &cost);

    printf("letter = %c\n", letter);
    printf("cost = %.2lf\n", cost);

    return 0;
}

void ChangeBlue(int *pAddressOfVariable)
{
    // Print the address of blue
    printf("Enter a new value: ");
    scanf("%d", pAddressOfVariable);
}

void ReadInCharAndDouble(char *pCharPointer, double *pDoublePointer)
{
    printf("Enter a character: ");

    // even if variable is a character, using %s operator for string prints it out, %c doesn't work
    scanf("%s", pCharPointer);

    printf("Enter a double: ");
    scanf("%lf", pDoublePointer);
}