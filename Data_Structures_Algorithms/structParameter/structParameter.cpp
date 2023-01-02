//
// Created by Venkat Ranganathan on 1/1/2023.
//
#include "structParameter.h"

int main() {

  // declare struct variable type Rectangle called 'r'
  struct Rectangle r;

  // define values of variables inside struct
  r.length = 10;
  r.breadth = 5;

  // pass struct variable to function "area", and return result
  return printf("%d", area(r));
}

// function calculates area of rectangle using struct
int area(struct Rectangle r1) { return r1.length * r1.breadth; }