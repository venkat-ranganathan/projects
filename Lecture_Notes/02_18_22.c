#include <stdio.h>

struct foo
{
    float y;
    short s;
    double x;
    int *ptr;
}; // need ; outside final bracket of struct function

int main()
{
    printf("Size of char: %ld\n", sizeof(char));
    printf("Size of short: %ld\n", sizeof(short));
    printf("Size of int: %ld\n", sizeof(int));
    printf("Size of float: %ld\n", sizeof(float));
    printf("Size of double: %ld\n", sizeof(double));
    printf("Size of int pointer: %ld\n", sizeof(int *));

    printf("Size of struct f: %ld\n", sizeof(struct foo));
}