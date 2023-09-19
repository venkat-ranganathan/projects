#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n;
    time_t t;

    n = 5;

    // Initializes random number generator

    srand((unsigned)time(&t));

    // Prints 5 random integers of either 0 or 1

    for (i = 0; i < n; i++)
    {
        printf("%d\n", rand() % 2);
    }

    return (0);
}