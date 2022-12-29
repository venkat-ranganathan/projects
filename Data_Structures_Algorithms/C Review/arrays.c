//
// Created by CentralCommand on 12/28/2022.
//

#include "arrays.h"

int main() {

    // declare variable of structure
    struct Rectangle r;
    struct student s;

    // access member of structure using dot operator
    r.breadth = 15;
    r.length = 25;

    s.roll = 10;
    strcpy(s.name, "Venkat");

    printf_s("Area of a rectangle is %d", r.length * r.breadth);
/*
    int A[5] = {1, 2, 5, 23, 3};

    for (int i = 0; i < 10; i++) {
        printf("%d\n", A[i]);
        printf("%llu\n", sizeof(A[i]));
    }*/

    return 0;
}