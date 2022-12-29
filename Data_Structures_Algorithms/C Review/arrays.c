//
// Created by CentralCommand on 12/28/2022.
//

#include "arrays.h"

int main() {

    // declare variable of structure
    struct Rectangle r;
    struct student s;
    // structure variable as an array with multiple entries for each array set
    struct card deck[52] = {{1, 0, 0, 10}};

    // access member of structure using dot operator
    r.breadth = 15;
    r.length = 25;

    s.roll = 10;
    strcpy(s.name, "Venkat");

    printf("%s\n", s.name);
    printf_s("Area of a rectangle is %d\n", r.length * r.breadth);

    printf("%d", deck[0].face);
    printf("%d", deck[0].shape);
    printf("%d", deck[0].color);
    printf("%d", deck[0].number);
/*
    int A[5] = {1, 2, 5, 23, 3};

    for (int i = 0; i < 10; i++) {
        printf("%d\n", A[i]);
        printf("%llu\n", sizeof(A[i]));
    }*/

    return 0;
}