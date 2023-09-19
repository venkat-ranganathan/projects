#include <stdio.h>

// lecture discuses difference between union and struct functions and size advantage of union function

struct A
{
    float y;
    double x;
    char s[5];
    int *ptr;
}; // need ; outside final bracket of struct function

union B
{
    float y;
    double x;
    char s[5];
    int *ptr;
}; //  also need ; outside {} of union function

int main()
{
    struct A st;
    union B un;

    printf("Size of char: %ld byte\n", sizeof(char)); // notes %ld\n
    printf("Size of int: %ld byte\n", sizeof(int));
    printf("Size of float: %ld byte\n", sizeof(float));
    printf("Size of double: %ld byte\n", sizeof(double));
    printf("Size of int pointer: %ld byte\n", sizeof(int *));

    printf("Size of struct A: %ld byte\n", sizeof(struct A));
    printf("Size of union B: %ld byte\n", sizeof(union B));

    printf("Address of st.y: %p\n", &st.y); // notes %p\n
    printf("Address of st.s: %p\n", &st.s);
    printf("Address of st.x: %p\n", &st.x);
    printf("Address of st.ptr: %p\n", &st.ptr);

    printf("Address of un.y: %p\n", &un.y);
    printf("Address of un.s: %p\n", &un.s);
    printf("Address of un.x: %p\n", &un.x);
    printf("Address of un.ptr: %p\n", &un.ptr);
}