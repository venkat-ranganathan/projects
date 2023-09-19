#include <stdio.h> // pre-processor directive

// value += will increase the value of "value" by 1, the same as value++ or value = value + 1;

int main()
{
    int value;

    value = 0;

    // %d tells printf to expect an integer, since value is an int
    // ++value in the below statement, will run after the printf statement, not before
    // \n will hit return so cursor moves to the next line

    printf("value = %d\n", value++); // ++value produces 1 (pre-increment); value++ produces 0 (post=increment)

    return 0;
}