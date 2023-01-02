//
// Created by Venkat Ranganathan on 1/2/2023.
//

// header guards
#ifndef CLASSCONSTRUCTOR_CLASSCONSTRUCTOR_H
#define CLASSCONSTRUCTOR_CLASSCONSTRUCTOR_H

// preprocessor directives
#include "cstdio"
// need cstdlib to use malloc
#include "cstdlib"

// declare class variable, class is private by default
// don't need to call Rectangle, and don't need to access member of Rectangle
// since all the data is inside the class
class Rectangle {
private:
  int length;
  int breadth;

public:
  // constructor, does the job of initialing the object
  Rectangle(int l, int b) {
    length = l;
    breadth = b;
  }
  // function calculates area of rectangle using struct
  // this is call-by-value since r1 is just a regular datatype
  int area() { return length * breadth; }
  void changeLength(int l) { length = l; }
};

// function prototypes
// initializes members length and breadth of Rectangle *r
// void initialize(class Rectangle *r, int l, int b);
// calculates area
int area(class Rectangle r);
// changes length value
void changeLength(class Rectangle *r, int l);

// close header guard
#endif // CLASSCONSTRUCTOR_CLASSCONSTRUCTOR_H
