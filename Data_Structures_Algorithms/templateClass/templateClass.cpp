//
// Created by Venkat Ranganathan on 1/2/2023.
//
#include "templateClass.h"

int main() {
  // need to declare Template data type in <> after class
  arithmetic<int> ar(10, 5);
  printf("Add values: %d\n", ar.add());

  // different Template data type, but need new class variable name
  arithmetic<float> ar1(10, 5);
  printf("Subtract values: %d\n", ar.sub());

  return 0;
}