//
// Created by Venkat Ranganathan on 12/31/2022.
//

// header guards
#ifndef BINARYTREE_H
#define BINARYTREE_H

// preprocessor directives
#include "stdio.h"
#include "stdlib.h"
// need stdbool.h to use bool data type
// #include "stdbool.h"

// declare struct variable
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

// function prototype
int checkTree(struct TreeNode *root);

// close header guard
#endif // BINARYTREE_H
