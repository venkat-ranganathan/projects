//
// Created by Venkat Ranganathan on 12/30/2022.
//
#ifndef FUNCTIONS_PARAMETERPASSING_H
#define FUNCTIONS_PARAMETERPASSING_H

// allows using printf in cpp
#include "cstdio"
// #include "stdio.h"

// function prototypes
void swap(int x, int y);
void callAddress(int *x, int *y);
// call by reference only works in cpp
void callReference(int &x, int &y);

#endif // FUNCTIONS_PARAMETERPASSING_H
