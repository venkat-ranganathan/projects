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
    struct foo f;

    printf("Size of char: %ld\n", sizeof(char)); // notes %ld\n
    printf("Size of short: %ld\n", sizeof(short));
    printf("Size of int: %ld\n", sizeof(int));
    printf("Size of float: %ld\n", sizeof(float));
    printf("Size of double: %ld\n", sizeof(double));
    printf("Size of int pointer: %ld\n", sizeof(int *));

    printf("Size of struct foo: %ld\n", sizeof(struct foo));

    printf("Address of f.y: %p\n", &f.y); // notes %p\n
    printf("Address of f.s: %p\n", &f.s);
    printf("Address of f.x: %p\n", &f.x);
    printf("Address of f.ptr: %p\n", &f.ptr);
}