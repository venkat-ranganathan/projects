// preprocessor directive
#include <stdio.h>

// main function
int main()
{
    // name of an array is an address
    // the name of the array points to the first element of the array

    // when array goes from A[0] to A[1], A[1] = 1 * sizeof(int) which is 4 bytes, so adds 4 bytes to memory
    // A[n] = n * sizeof(int), multiples of 4 bytes

    // declare array with no set number of elements, filled with values
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    /*

    pointer review:

    int value = 16;

    // declare pointer
    int *pNumber;

    // point pointer to reference memory address of variable value
    pNumber = &value;

    // dereference pointer
    printf("%d", *pNumber);

    */

    // code continues

    // declare variables for pointer arithmetic
    int sum = 0;

    // declare two pointers, pStart points to first memory address of array, pEnd to last memory address of array
    int *pStart, *pEnd;

    // need to initialize both pointers (done in the for loop)

    // can also set pStart = &array[0], same result as pStart = array;

    // primer sets pStart as first element in array, and value in memory of &pEnd as last element in array
    for (pStart = array, pEnd = &array[9]; pStart <= pEnd; pStart++)
    {
        // pStart++ adds 1 * sizeof(int)

        // de-referance pointer to add the value in its memory to sum variable
        sum += *pStart;
    }

    // prints value in sum
    printf("The sum is %d\n", sum);

    return 0;

    // lab5 extra credit: use two for loops
    // lab5 check for memory errors using valgrind
}