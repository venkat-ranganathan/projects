//
// Created by Venkat Ranganathan on 12/30/2022.
//
#include "arrayParameter.h"

int main() {
  int A[5] = {2, 4, 6, 8, 10};
  fun(A, 5);
  return 0;
}

// arrays are passed by address
void fun(int A[], int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d", A[i]);
  }
}