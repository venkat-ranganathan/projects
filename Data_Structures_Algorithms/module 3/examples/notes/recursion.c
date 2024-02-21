
#include <stdio.h>

void recursion(int number)
{
    // check if number is greater than 1
    if (number < 10)
    {
        // recursive case
        // the recursive function call will pass in a number that
        // is one smaller than the original
        printf("%d", number);
        return;
    }

    else
    {
        // base case
        printf("%d", number % 10);
        recursion(number / 10);
    }
}

// every program starts with main, so main is the first function on stack
int main(void)
{
    recursion(345342);

    return 0;
}

