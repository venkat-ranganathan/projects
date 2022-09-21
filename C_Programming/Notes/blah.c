#include <stdio.h>

const int RADIUS = 1;

int main()
{
    int x = 0;
    int y = ++x;

    printf("%d", y);

    return 0;
}