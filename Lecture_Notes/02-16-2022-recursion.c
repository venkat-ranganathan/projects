#include <stdio.h>

void loop(int n)
{
    printf("loop:\n");
    // increasing order
    for(int i = 0; i <= n; i++)
        printf("%d\n", i);

    printf("---\n");
    // decreasing order
    for(int i = n; i >= 0; i--)
        printf("%d\n", i);
}

// head recursion
void headR(int n)
{
    if(n == 0)	// base case
    {
        printf("%d\n", n);
    }
    else	// recursive case
    {
        headR(n-1);
        printf("%d\n", n);
    }
}

// tail recursion
void tailR(int n)
{
    if(n == 0)	// base case
    {
        printf("%d\n", n);
    }
    else	// recursive case
    {
        printf("%d\n", n);
        tailR(n-1);
    }
}

int main()
{
    loop(10);
    printf("head recursion:\n");
    headR(10);
    printf("tail recursion:\n");
    tailR(10);
}

