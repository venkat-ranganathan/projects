#include <stdio.h>

// external variable
extern int y;

// external function
extern void foo_ex();

void foo()
{
    // static variable
    static int x = 0;

    x++;
    printf("x = %d\n", x);

    // access the external variable
    printf("y = %d\n", y);
}

int main()
{
    for(int i = 0; i < 10; i++)
        foo();

    // access external function
    foo_ex();
}

