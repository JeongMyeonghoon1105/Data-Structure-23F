#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// max 함수의 매크로 정의
#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef int element;

typedef struct TreeNode {
  element key;
  struct TreeNode *left, *right;
} TreeNode;

TreeNode* makeNode(element data) {
  TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));

  node->key = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

TreeNode* insertNode(TreeNode *root, element key) {
  if (root == NULL)
    return makeNode(key);

  if (key < root->key)
    root->left = insertNode(root->left, key);
  else if (key > root->key) 
    root->right = insertNode(root->right, key);

  return root;
}

void preOrder(TreeNode *n) {
  if (n == NULL)
    return;
  printf("%d ", n->key);
  preOrder(n->left);
  preOrder(n->right);
}

int getNodeCount(TreeNode *n) {
  
}

int getHeight(TreeNode *n) {
  
}

int getLeafCount(TreeNode *n) {
  
}

TreeNode* iterFindNode(TreeNode *root, element key) {
  // while (root) {
  //   if (key == root->key)
      
  // }
}

int main(void) {
  TreeNode *root = NULL;
  srand(time(NULL));

  /*
  난수 생성 및 insert
  for (int i = 0; i < 15; i++)
    root
  */
  
  preOrder(root); printf("\n"); getchar();

  // 결과 출력
  printf("Node Count: ");
  
  return 0;
}
