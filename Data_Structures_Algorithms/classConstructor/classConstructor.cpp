//
// Created by Venkat Ranganathan on 1/2/2023.

// This program converts a structParameter from C into CPP style

// preprocessor directive
#include "classConstructor.h"

int main() {

  // Rectangle r is now an object and is initialized with length and breadth
  // values of 10 and 5, respectively
  Rectangle r(10, 5);

  // r is the object, area, and changeLength are members
  // r.area();

  printf("This is the original Area of the Rectangle: %d\n", r.area());
  printf("This is the original Perimeter of the Rectangle: %d\n",
         r.perimeter());
  r.changeLength(20);

  printf("This is the new Area of the Rectangle after the length has been "
         "changed: %d\n",
         r.area());
  printf("This is the new Perimeter of the Rectangle after the length has been "
         "changed: %d\n",
         r.perimeter());

  return 0;
}
