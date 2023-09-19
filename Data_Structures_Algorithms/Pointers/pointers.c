//
// Created by CentralCommand on 12/28/2022.
//

#include "pointers.h"

int main() {
  int *ptrA;
  int a = 10;

  // malloc requires stdlib.h
  ptrA = (int *)malloc(5 * sizeof(int));

  // assign pointer to value stored in address of 'a'
  // ptrA = &a;

  // print what's stored in memory of de-referenced pointer
  // if you use ptrA without *, it'll print the memory address of ptrA
  printf("%d\n", *ptrA);
  printf("%d\n", a);

  // need to de-allocate memory from malloc
  free(ptrA);

  return 0;
}