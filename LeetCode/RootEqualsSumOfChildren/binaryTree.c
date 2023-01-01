//
// Created by Venkat Ranganathan on 12/31/2022.
//

// preprocessor directive
#include "binaryTree.h"

// checks if the Root value is equal to the sum of its Children
int isSum(struct TreeNode *node) {

  // initialize local variables to store left and right child values
  int left_data = 0, right_data = 0;

  // returns 1 if Root and Children are empty
  if (node == NULL || (node->left == NULL && node->right == NULL)) {
    return 1;
  } else {
    // stores value of left child of root into left_data if left child is not
    // empty
    if (node->left != NULL) {
      left_data = node->left->val;
    }
    // stores value of right child of root into right_data if right child is not
    // empty
    if (node->right != NULL) {
      right_data = node->right->val;
    }

    // checks if root is equal to the sum of its children AND if sum of Children
    // of Child_Root is equal to corresponding Child_Root, then returns 1 if all
    // Root/Child_Root are equal to the sum of its children , zero otherwise
    if ((node->val == left_data + right_data) && isSum(node->left) &&
        isSum(node->right)) {
      return 1;
    } else
      return 0;
  }
}

// declares struct pointer variable called newNode that receives an int value
struct TreeNode *newNode(int val) {
  // typecasting as TreeNode structure pointer
  struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));

  // stores int value as node.val
  node->val = val;
  // initializes node.left and node.right as empty
  node->left = NULL;
  node->right = NULL;

  // returns the node pointer
  return (node);
}

int main() {
  // declares struct TreeNode pointer variable as a Root with value of 10
  struct TreeNode *root = newNode(10);

  // defines values of Children of Root
  root->left = newNode(8);
  root->right = newNode(2);

  // defines values of Children of Child_Root
  root->left->left = newNode(3);
  root->left->right = newNode(5);
  root->right->right = newNode(2);

  // passes root pointer to checkTree function
  checkTree(root);

  // ends program
  return 0;
}

// checkTree receives struct variable pointer root, checks if sum of Children is
// equal to Root, and returns result
int checkTree(struct TreeNode *root) {
  if (isSum(root)) {
    return printf("\nThe Root is equal to the sum of its Children\n");
  } else {
    return printf("\nThe Root DOES NOT equal the sum of its Children\n");
  }
}