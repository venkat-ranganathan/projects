//
// Created by Venkat Ranganathan on 12/30/2022.
//
#include "arrayParameter.h"

int main() {
  int A[5] = {2, 4, 6, 8, 10};
  fun(A, 5);

  printf("\n%d\n", sizeof(A));
  printf("%d\n", sizeof(int));

  // print first element of (pointer) array after changing its value in function
  // A[0] was originally 2, now it's 15
  printf("%d", A[0]);

  return 0;
}

// arrays are passed by address
// can pass pointer as an array or using *, so fun(int *A, int n) & fun(int A[],
// int n) both work
void fun(int *A, int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d", A[i]);
  }
  // use pointers when you're going to change the value of variable when moving
  // the variable through functions
  A[0] = 15;
}