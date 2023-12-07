#include <stdio.h>

typedef int element;

typedef struct TreeNode {
  element key;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

TreeNode *makeNode(element key) {
  TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));

  node->key = key;
  node->left = NULL;
  node->right = NULL;

  return node;
}

TreeNode *insertNode(TreeNode *root, element key) {
  if (root == NULL)
    return makeNode(key);
  
  if (key < root->key)
    root->left = insertNode(root->left, key);
  else if (key > root->key)
    root->right = insertNode(root->right, key);

  return root;
}

int main(void) {
  
  return 0;
}
