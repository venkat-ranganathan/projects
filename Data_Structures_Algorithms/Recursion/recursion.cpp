//
// Created by Venkat Ranganathan on 3/9/2023.
//
#include "recursion.h"

void fun(int n) {
  if (n > 0) {
    fun(n - 1);
    printf("%d", n);
  }
}
int main() {
  int x = 3;
  fun(x);
  return 0;
}
