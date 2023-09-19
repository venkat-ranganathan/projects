#include <stdio.h>

// pass by value
void foo1(int a)
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
    //(*a)++;   // invalid, can't change a value using a constant reference
    printf("const *a = %d\n", *a);  // valid, can read a value using a constant reference
}

int main()
{
    int x = 5;
    int *ptr = &x;

    // pass by value
    foo1(x);
    printf("x = %d\n", x);

    // pass by reference
    foo2(&x);
    printf("x = %d\n", x);
    foo3(ptr);  // or foo3(&x);
}

