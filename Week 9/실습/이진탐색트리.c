/*
이진탐색트리

왼쪽 <= 루트 <= 오른쪽
일반적으로는 key값의 중복을 허용하지 않음

탐색 실패
단말 노드까지 탐색했음에도 해당 값을 찾지 못한 경우
해당 위치가 삽입해야할 위치

노드 생성 --> 단말노드이므로 *left, *right 필요 없음
*/

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct TreeNode {
  element key;
  struct TreeNode *left, *right;
} TreeNode;

TreeNode *makeNode(element data) {
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


int main(void) {
  TreeNode *root = NULL;   // 공집합도 이진트리이다. 루트 노드가 NULL을 가리키는 공집합 이진트리 생성
  
  root = insertNode(root, 35);  root = insertNode(root, 68);
  root = insertNode(root, 99);  root = insertNode(root, 18);
  root = insertNode(root, 7);  root = insertNode(root, 3);
  root = insertNode(root, 12);  root = insertNode(root, 26);
  root = insertNode(root, 22);  root = insertNode(root, 30);
  
  preOrder(root);
  
  return 0;
}
