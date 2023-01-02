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

// declare struct datatype pointer
struct Rectangle *fun() {
  struct Rectangle *ptr;
  // cpp syntax, new means will be created in heap
  // ptr = new Rectangle;

  // c syntax to create object of type Rectangle using pointer created in heap
  ptr = (struct Rectangle *)malloc(sizeof(struct Rectangle));

  ptr->length = 15;
  ptr->breadth = 7;

  // returns pointer to a structure
  return ptr;
}

// function prototypes
// pass-by-value
int area(struct Rectangle r1);
// pass-by-reference
int area2(struct Rectangle &r1);
// pass-by-address, pointer of type rectangle
int area3(struct Rectangle *r1);

// close header guard
#endif // STRUCTPARAMETER_STRUCTPARAMETER_H
