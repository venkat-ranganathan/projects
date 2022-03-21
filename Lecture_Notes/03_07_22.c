#include <stdio.h>

#define SIZE 10;

// intentionally non-working code to demonstrate ideas
int main()
{
    int a[5][5] = {{1,2,3,4,5}, {6,7,8,9,10}};
    //int a[SIZE][SIZE] = {{1,2,3,4,5}, {6,7,8,9,10}};

    int x = 0;

    x = x + 1;

    for(int i = 0; i < 5; i++)
    {
        a[0][i] = 1;
    }
}