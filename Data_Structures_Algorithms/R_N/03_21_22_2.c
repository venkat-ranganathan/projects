#include <stdio.h>

int main()

{
    int n = 5; // n address is 0x10
    int *ptr = &n; // ptr address is 0x50

    printf("%p\n", &n);
    printf("%p\n", ptr);
    printf("%p\n", &ptr);
    printf("%p\n", *(&ptr));
    printf("%p\n", &(*ptr));

    printf("%d\n", *ptr);
}