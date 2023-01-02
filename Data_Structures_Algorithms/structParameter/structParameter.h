//
// Created by Venkat Ranganathan on 1/1/2023.
//

// header guards
#ifndef STRUCTPARAMETER_STRUCTPARAMETER_H
#define STRUCTPARAMETER_STRUCTPARAMETER_H

// preprocessor directives
#include "cstdio"
// need cstdlib to use malloc
#include "cstdlib"

// declare struct variable
struct Rectangle {
  int length;
  int breadth;
};

// function prototypes
// pass-by-value
int area(struct Rectangle r1);
// pass-by-reference
int area2(struct Rectangle &r1);
// pass-by-address, pointer of type rectangle
int area3(struct Rectangle *r1);

// close header guard
#endif // STRUCTPARAMETER_STRUCTPARAMETER_H
