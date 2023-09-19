#include <stdio.h>

struct A
{
    float y;
    double x;
    char s[5];
    int *ptr;
};

union B
{
    float y;
    double x;
    char s[5];
    int *ptr;
};

int main()
{
    struct A st;
    union B un;

    printf("Size of char: %ld byte\n", sizeof(char));
    printf("Size of int: %ld byte\n", sizeof(int));
    printf("Size of float: %ld byte\n", sizeof(float));
    printf("Size of double: %ld byte\n", sizeof(double));
    printf("Size of int pointer: %ld byte\n\n", sizeof(int *));

    printf("Size of struct A: %ld byte\n", sizeof(struct A));
    printf("Size of union B: %ld byte\n\n", sizeof(union B));

    printf("Address of st.y (float): %p\n", &st.y);
    printf("Address of st.x (double): %p\n", &st.x);
    printf("Address of st.s (char [5]): %p\n", &st.s);
    printf("Address of st.ptr (pointer): %p\n\n", &st.ptr);

    printf("Address of un.y: %p\n", &un.y);
    printf("Address of un.x: %p\n", &un.x);
    printf("Address of un.s: %p\n", &un.s);
    printf("Address of un.ptr: %p\n\n", &un.ptr);
}

