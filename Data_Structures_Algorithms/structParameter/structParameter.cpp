//
// Created by Venkat Ranganathan on 1/1/2023.
//

// preprocessor directive
#include "structParameter.h"

// declare struct datatype pointer
struct Rectangle *fun() {
  struct Rectangle *ptr;
  // cpp syntax, new means will be created in heap
  // ptr = new Rectangle;

  // c syntax to create object of type Rectangle using pointer created in heap
  ptr = (struct Rectangle *)malloc(sizeof(struct Rectangle));

  ptr->length = 15;
  ptr->breadth = 7;

  // returns pointer to a structure
  return ptr;
}

int main() {

  // declare struct variable type Rectangle called 'r'
  struct Rectangle r;

  // declare struct datatype Rectangle pointer to object created in heap
  struct Rectangle *ptr = fun();

  // define values of variables inside struct
  r.length = 10;
  r.breadth = 5;

  // print initial values of length and breadth
  printf("Original Length: %d\t Original Breadth: %d\n", r.length, r.breadth);

  // pass struct variable to function "area", and return result
  // pass-by-value
  printf("pass-by-value Area: %d\n", area(r));

  // pass-by-reference
  printf("pass-by-reference Area: %d\n", area2(r));

  // pass-by-address, values are changed in function and new area is returned
  printf("pass-by-address with values changed Area: %d\n", area3(&r));

  // print new r.length and r.breadth values to confirm the values are different
  // r.length is now 11 instead of 10 and r.breadth is now 4 instead of 5
  printf("New Length: %d\t New Breadth: %d\n", r.length, r.breadth);

  // print out values of struct Rectangle pointer cast to object created in heap
  printf("Pointer Length: %d\t Pointer Breadth: %d\n", ptr->length,
         ptr->breadth);

  return 0;
}

// function calculates area of rectangle using struct
// this is call-by-value since r1 is just a regular datatype
int area(struct Rectangle r1) { return r1.length * r1.breadth; }

// pass-by-reference
int area2(struct Rectangle &r1) { return r1.length * r1.breadth; }

// pass-by-address, increasing value of length by 1 and decreasing value of
// breadth by 1
int area3(struct Rectangle *r1) {
  r1->length++;
  r1->breadth--;
  return r1->length * r1->breadth;
}