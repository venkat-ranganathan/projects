//
// Created by Venkat Ranganathan on 1/2/2023.

// This program converts a structParameter from C into CPP style

// preprocessor directive
#include "classConstructor.h"

int main() {
  // declare local length and breadth values
  // int l = 0, b = 0;

  // ask user to input values for length and breadth
  // printf("Enter the values for Length and Breadth");
  // scanf_s("%d %d", l, b);

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
  printf("This is length: %d\n ", r.getLength());
  printf("This is breadth: %d\n ", r.getBreadth());

  return 0;
}
