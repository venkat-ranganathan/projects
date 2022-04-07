#include <stdio.h>

/* // swap pointer locally
void swapPointers(int *p1, int *p2)
{
    int *tmp;

    tmp = p1;
    p1 = p2;
    p2 = tmp;
} */

// swap the values the pointers are pointing to, i.e., swap x and y
void swapPointers(int *p1, int *p2)
{
    int tmp;

    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int main()
{
    int x = 5;
    int y = 7;
    int *ptr1 = &x;
    int *ptr2 = &y;

    printf("value of x = %d\n", x);
    printf("value of y = %d\n\n", y);

    printf("address in ptr1: %p\n", ptr1);
    printf("address in ptr2: %p\n\n", ptr2);

    // swapPointers(&x, &y);
    swapPointers(ptr1, ptr2);

    printf("value of x after function = %d\n", x);
    printf("value of y after function = %d\n", y);

    printf("address in ptr1 afer fuction: %p\n", ptr1);
    printf("address in ptr2 afer fuction: %p\n", ptr2);

    /*     // print the value stroed in the variables
        printf("value of x = %d\n", x);
        printf("value of y = %d\n", y);

        // "&" is the REFERENCE operator
        // print the memory address of the variables

        printf("&x = %p\n", &x);
        printf("&y = %p\n", &y);

        // print the address the pointer's are pointing to
        // print the address stored in the pointers
        printf("ptr1 :%p\n", ptr1);
        printf("ptr2 :%p\n\n", ptr2); // note double \n

        // printing the address of the pointers in memory
        printf("&ptr1 :%p\n", &ptr1);
        printf("&ptr2 :%p\n\n", &ptr2); // note double \n

        // "*" is the DEREFERENCE operator
        // prints the value in the memory location that the pointer is pointing to
        printf("*ptr1 :%d\n", *ptr1);
        printf("*ptr2 :%d\n\n", *ptr2); // note double \n */
}