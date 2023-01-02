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

// cpp header file for std::cin, std::cout
#include "iostream"

// so you don't have to use std:: for cin and cout
using namespace std;

// declare class variable, class is private by default
// don't need to call Rectangle, and don't need to access member of Rectangle
// since all the data is inside the class
// class can be used in any program, not just the local main
class Rectangle {
private:
  int length;
  int breadth;

public:
  // initialize constructor
  Rectangle() { length = breadth = 1; }
  // constructor overloading, does the job of initialing the object
  Rectangle(int l, int b);
  // methods because these functions are bound to class Rectangle
  int area();
  int perimeter();
  int getLength() { return length; }
  int getBreadth() { return breadth; }
  void changeLength(int l) { length = l; }

  // Destructor
  ~Rectangle();
};

// scope resolution operator, ::, used to access member of class
// initialize members length and breadth
Rectangle::Rectangle(int l, int b) {
  length = l;
  breadth = b;
}

int Rectangle::area() { return length * breadth; }
int Rectangle::perimeter() { return 2 * (length + breadth); }

// destructor
Rectangle::~Rectangle() {}

// close header guard
#endif // CLASSCONSTRUCTOR_CLASSCONSTRUCTOR_H
