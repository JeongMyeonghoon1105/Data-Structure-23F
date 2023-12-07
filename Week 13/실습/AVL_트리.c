#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef int element;

typedef struct TreeNode {
  element key;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

TreeNode* makeNode(element key) {
  TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));

  node->key = key;
  node->left = NULL;
  node->right = NULL;

  return node;
}

// 직접 구현해보기
int getHeight(TreeNode *root) {
  int height = 0;

  if (root)
    height = 1 + max(getHeight(root->left), getHeight(root->right));

  return height;    
}

int getBalance(TreeNode *root) {
  if (root == NULL)
    return 0;

  // (왼쪽 서브트리 높이 - 오른쪽 서브트리 높이) 리턴
  return getHeight(root->left) - getHeight(root->right);    
}

TreeNode* rotateRight(TreeNode *parent) {
  TreeNode *child = parent->left;
  // 원래 child에 붙어있던 서브트리를 parent의 서브트리로 붙인다
  parent->left = child->right;
  // parent를 child의 right로 붙여 회전시킨다
  child->right = parent;
  return child;
}

TreeNode* rotateLeft(TreeNode *parent) {
  TreeNode *child = parent->right;
  // 원래 child에 붙어있던 서브트리를 parent의 서브트리로 붙인다
  parent->right = child->left;
  // parent를 child의 left로 붙여 회전시킨다
  child->left = parent;
  return child;
}

TreeNode* insertNode(TreeNode* root, element key) {
  if(root == NULL)
    return makeNode(key);

  if(key < root->key)
    root->left = insertNode(root->left, key);
  else if(key > root->key)
    root->right = insertNode(root->right, key);

  int balance = getBalance(root);

  // balance > 1 --> L타입
  if (balance > 1 && key < root->left->key)
    // LL 회전
    return rotateRight(root);
  else if (balance > 1 && key > root->left->key) {
    // LR 회전
    // LL 타입으로 변경하기
    root->left = rotateLeft(root->left);
    // LL 회전
    return rotateRight(root);
  }
  // balance < -1 --> R타입
  if (balance < -1 && key > root->right->key)
    // RR 회전
    return rotateLeft(root);
  else if (balance < -1 && key < root->right->key) {
    // RL 회전
    // RR 타입으로 변경하기
    root->right = rotateRight(root->right);
    // RR 회전
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

  // int data[] = {7, 8, 9, 2, 1, 5, 3, 6, 4};

  int data[] = {5, 3, 1, 7, 10, 8, 9};
  
  for (int i = 0; i < 7; i++) {
    root = insertNode(root, data[i]);
    display(root, data[i]);
  }

  return 0;
}
