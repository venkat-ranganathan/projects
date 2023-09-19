/* #include <stdio.h>

const int RADIUS = 1;

int main()
{
    int x = 0;
    int y = ++x;

    printf("%d", y);

    return 0;
} */

#include <stdio.h>

// Creating function
int main(void)
{
    // Setting counter to 100
    int counter = 100;
    /* Creating for loop that begins at i = 10 to 1 in increments of 1
    It runs the "j" for loop 10 times*/
    for (int i = 10; i > 0; i--)
    {
        // Creating for loop that begins at j = 0 to 9 in increments of 1
        for (int j = 0; j < 10; j++)
        {
            /* Prints a number, counter, and then subtracts counter by 1
            It then does this 10 times*/
            printf("%d", counter);
            printf(" ");
            counter--;
        }
        printf("\n");
    }
    return 0;
}