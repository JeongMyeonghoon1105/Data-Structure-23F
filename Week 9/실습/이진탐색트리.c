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

void preOrder(TreeNode *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->key);
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(TreeNode *root) {
  if (root == NULL)
    return;
  inOrder(root->left);
  printf("%d ", root->key);
  inOrder(root->right);
}

int recursiveNodeCount(TreeNode *root) {
  if (root == NULL)
    return 0;
  return 1 + recursiveNodeCount(root->left) + recursiveNodeCount(root->right);
}

int getHeight(TreeNode *root) {
  if (root == NULL)
    return 0;
  return 1 + max(getHeight(root->left), getHeight(root->right));
}

int getLeafCount(TreeNode *root) {
  if (root == NULL)
    return 0;
  else if (root->left == NULL && root->right == NULL)
    return 1;
  return getLeafCount(root->left) + getLeafCount(root->right);
}

TreeNode* iterFindNode(TreeNode *root, element key) {
  while (root) {
    if (key == root->key)
      return root;
    else if (key < root->key)
      root = root->left;
    else
      root = root->right;
  }
}

int main(void) {
  TreeNode *root = NULL;
  srand(time(NULL));

  // 중복 제거하여 난수 생성
  int randNum[15] = {10, 9, 22, 16, 19, 20, 18, 13, 14, 28, 3, 23, 12, 17, 4};
  // int visited[30];
  // for (int i = 0; i < 15; i++) {
  //   int randGen = rand() % 30;
  //   while (visited[randGen])
  //     randGen = rand() % 30;
  //   randNum[i] = randGen;
  //   visited[randGen] = 1;
  // }

  // 노드 생성 및 삽입
  for (int i = 1; i <= 15; i++) 
    root = insertNode(root, randNum[i-1]);
  
  // 결과 출력
  for (int i = 0; i < 15; i++)
    printf("%d ", randNum[i]);
  printf("\n");
  preOrder(root);   printf("\n");
  inOrder(root);    printf("\n");
  
  // 노드 개수 출력
  printf("\n노드 개수 : %d\n", recursiveNodeCount(root));
  
  // 높이 출력
  printf("트리 높이 : %d\n", getHeight(root));

  // 단말 노드 개수 출력
  printf("단말 노드 개수 : %d\n", getLeafCount(root));
  
  return 0;
}

/*
이진탐색트리

왼쪽 <= 루트 <= 오른쪽
일반적으로는 key값의 중복을 허용하지 않음

탐색 실패
단말 노드까지 탐색했음에도 해당 값을 찾지 못한 경우
해당 위치가 삽입해야할 위치

노드 생성 --> 단말노드이므로 *left, *right 필요 없음
*/
