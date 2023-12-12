#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef int element;

typedef struct TreeNode {
  element key;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

TreeNode *makeNode(element data) {
  TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
  node->key = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

int getHeight(TreeNode *root) {
  int height = 0;
  if (root) 
    height = 1 + max(getHeight(root->left), getHeight(root->right));
  return height;
}

int getBalance(TreeNode *root) {
  if (root == NULL)
    return 0;
  return getHeight(root->left) - getHeight(root->right);
}

TreeNode* rotateRight(TreeNode *parent) {
  TreeNode *child = parent->left;
  parent->left = child->right;
  child->right = parent;
  return child;
}

TreeNode* rotateLeft(TreeNode *parent) {
  TreeNode *child = parent->right;
  parent->right = child->left;
  child->left = parent;
  return child;
}

TreeNode *insertNode(TreeNode *root, element data) {
  if (root == NULL)
    return makeNode(data);
  
  if (data < root->key)
    root->left = insertNode(root->left, data);
  else if (data > root->key)
    root->right = insertNode(root->right, data);

  int balance = getBalance(root);

  // LL 타입
  if (balance > 1 && data < root->left->key)
    return rotateRight(root);
  // LR 타입
  else if (balance > 1 && data > root->left->key) {
    root->left = rotateLeft(root->left);
    return rotateRight(root);
  }
  // RR 타입
  if (balance < -1 && data > root->right->key)
    return rotateLeft(root);
  // RL 타입
  else if (balance < -1 && data < root->right->key) {
    root->right = rotateRight(root->right);
    return rotateLeft(root);
  }

  return root;
}

void preOrder(TreeNode *root) {
  if (root) {
    printf("[%d] ", root->key);
    preOrder(root->left);
    preOrder(root->right);
  }
}

void display(TreeNode *root, int key) {
  printf("[Insert %d] : ", key);
  preOrder(root);
  printf("\n");
}

int main() {
  TreeNode *root = NULL;
  int data[] = {5, 3, 1, 7, 10, 8, 9};
  
  for (int i = 0; i < 7; i++) {
    root = insertNode(root, data[i]);
    display(root, data[i]);
  }

  return 0;
}
