//
// Created by Venkat Ranganathan on 1/2/2023.
//
#include "templateClass.h"

int main() {
  // need to declare Template datatype in <> after class
  arithmetic<int> ar(10, 5);
  printf("Add values: %d\n", ar.add());

  // different Template datatype, but need new class variable name
  arithmetic<float> ar1(10.99, 5.34);
  printf("Subtract values: %.2f\n", ar1.sub());

  return 0;
}