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
  // methods because these functions are bound to class Rectangle
  int area() { return length * breadth; }
  int perimeter() { return 2 * (length + breadth); }
  void changeLength(int l) { length = l; }
};

// close header guard
#endif // CLASSCONSTRUCTOR_CLASSCONSTRUCTOR_H
