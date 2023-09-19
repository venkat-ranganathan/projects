//
// Created by Venkat Ranganathan on 12/30/2022.
//
#include "parameterPassing.h"

// main parameter passing methods: pass by value, pass by address, pass by
// reference

// pass-by-value example. swap function swaps value of a and b that are stored
// in variables x and y, but a and b itself aren't changed. can confirm by
// printing out value of a and b after executing swap function, values for a and
// b remain 10 and 20, respectively

int main() {
  int a = 10;
  int b = 20;

  // pass-by-value
  swap(a, b);
  printf("Pass by value: \n%d\n%d\n", a, b);

  // call-by-address
  callAddress(&a, &b);
  printf("Call by address: \n%d\n%d\n", a, b);

  // call by reference only works in cpp
  callReference(a, b);
  printf("Call by reference: \n%d\n%d\n", a, b);
  return 0;
}

// pass-by-value
void swap(int x, int y) {
  int temp;

  temp = x;
  x = y;
  y = temp;
}

// pass-by-address, need to use pointers since values of original passed
// variables are going to be changed
void callAddress(int *x, int *y) {
  int temp;

  temp = *x;
  *x = *y;
  *y = temp;
}

// pass-by-reference only works in cpp
// not used often
void callReference(int &x, int &y) {
  int temp;

  temp = x;
  x = y;
  y = temp;
}