//
// Created by CentralCommand on 12/29/2022.
//

#include "pointerStructure.h"

int main() {
  struct Rectangle r;
  // structure variable 'ptrA' references what's stored in memory address of
  // structure 'r'
  // struct Rectangle *ptrA = &r;
  struct Rectangle *ptrA;

  // variables are created inside the stack
  r.breadth = 10;
  r.length = 5;

  // to get memory in heap, use malloc()
  // malloc() returns void pointer
  // typecasting as Rectangle type structure pointer: ptr = (struct Rectangle *)
  ptrA = (struct Rectangle *)malloc(sizeof(struct Rectangle));

  // c++ syntax is simpler:
  // ptrA = new Rectangle;
  // "new" is the syntax to typecast struct Rectangle as struct pointer

  // wrong syntax, use () with * or -> without *
  //*ptrA->length=20;

  // correct method to access structure using pointer
  (*ptrA).length = 20;
  // also correct
  ptrA->length = 20;

  ptrA->breadth = 5;

  printf("%d\n%d\n%d\n%d\n", ptrA->length, ptrA->breadth, r.length, r.breadth);

  return 0;
}