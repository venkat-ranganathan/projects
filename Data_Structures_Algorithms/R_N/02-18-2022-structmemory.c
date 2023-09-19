#include <stdio.h>

struct foo
{
    float y;
    short s;
    double x;
    int *ptr;
};

int main()
{
    struct foo f;

    printf("Size of char: %ld byte\n", sizeof(char));
    printf("Size of short: %ld byte\n", sizeof(short));
    printf("Size of int: %ld byte\n", sizeof(int));
    printf("Size of float: %ld byte\n", sizeof(float));
    printf("Size of double: %ld byte\n", sizeof(double));
    printf("Size of int pointer: %ld byte\n", sizeof(int *));

    printf("Size of struct foo: %ld byte\n", sizeof(struct foo));

    printf("Address of f.y: %p\n", &f.y);
    printf("Address of f.s: %p\n", &f.s);
    printf("Address of f.x: %p\n", &f.x);
    printf("Address of f.ptr: %p\n", &f.ptr);
}

