#include <stdio.h>

// pass by value
void foo(int a)
{
    a++;
}

// pass by reference
void foo2(int *a)
{
    (*a)++;
}

// make the reference constant
void foo3(const int *a)
{
    //(*a)++; // invalid, can't change a constant value
    printf("const *a = %d\n", *a); // valid, can read a constant value
}

int main()
{
    int x = 5;

    // pass by value
    foo1(x);
    pritnf("x = %d\n", x);

    // pass by reference
    foo2(&x);
    printf("x = %d\n", x);
    foo3(&x);
}