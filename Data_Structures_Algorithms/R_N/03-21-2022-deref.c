#include <stdio.h>

int main()
{
    int n=5;  
    int *ptr = &n; // this is called "referencing"

    printf("%p\n", &n); // prints address of n
    printf("%p\n", ptr); // prints address of n
    printf("%p\n", &ptr); // prints address of ptr
    printf("%p\n", *(&ptr)); // prints address of n
    printf("%p\n", &(*ptr)); // prints address of n

    printf("%d\n", *ptr); // prints value of n. this is called "dereferencing"
}

