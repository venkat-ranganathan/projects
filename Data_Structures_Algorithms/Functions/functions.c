//
// Created by Venkat Ranganathan on 12/30/2022.
//

#include "functions.h"

// using functions is called modular programming, breaks program into smaller
// parts
int main() {
  int num1, num2, sum;

  num1 = 10;
  num2 = 15;

  sum = add(num1, num2);

  return printf("%d\n", sum);
}

int add(int a, int b) {
  int c = a + b;
  return c;
};
