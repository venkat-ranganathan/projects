//
// Created by Venkat Ranganathan on 1/2/2023.
//

// Focus of this code is to convert a class into a template

#ifndef TEMPLATECLASS_TEMPLATECLASS_H
#define TEMPLATECLASS_TEMPLATECLASS_H

#include "iostream"
#include <cstdio>

using namespace std;

// declare class as a Template with datatype 'T'
template <class T>

class arithmetic {
private:
  // 'T' is a generic datatype, can be int, float, double, etc.
  T a;
  T b;

public:
  // Constructor
  arithmetic(T a, T b);
  T add();
  T sub();

  // Destructor
  ~arithmetic();
};

// need to declare Template again
template <class T>

// need to add <T> before scope resolution operator, ::, when using Template
arithmetic<T>::arithmetic(T a, T b) {
  // accessing same object, so need to use -> instead of .
  this->a = a;
  this->b = b;
}

// need to declare Template again
template <class T> T arithmetic<T>::add() { return a + b; }

// need to declare Template again
template <class T> T arithmetic<T>::sub() { return a - b; }

// need to declare Template again
template <class T>
// Destructor
arithmetic<T>::~arithmetic() {}

#endif // TEMPLATECLASS_TEMPLATECLASS_H
