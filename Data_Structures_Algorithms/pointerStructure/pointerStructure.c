//
// Created by CentralCommand on 12/29/2022.
//

#include "pointerStructure.h"

int main() {
  struct Rectangle r;
  // structure variable 'ptrA' references what's stored in memory address of
  // structure 'r'
  struct Rectangle *ptrA = &r;

  r.breadth = 10;
  r.length = 5;

  // wrong syntax, use () with * or -> without *
  //*ptrA->length=20;

  // correct method to access structure using pointer
  (*ptrA).length = 20;
  // also correct
  ptrA->length = 20;

  return 0;
}