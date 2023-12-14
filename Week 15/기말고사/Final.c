#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
  int key;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

TreeNode *makeNode(int data, TreeNode *leftChild, TreeNode *rightChild) {
  TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
  newNode->key = data;
  newNode->left = leftChild;
  newNode->right = rightChild;
  return newNode;
}

TreeNode *mergeTree(TreeNode *tree1, TreeNode *tree2) {
  if (tree1 == NULL && tree2 == NULL)
    return NULL;

  TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
  
  if (tree1 == NULL) {
    root->key = tree2->key;
    root->left = mergeTree(NULL, tree2->left);
    root->right = mergeTree(NULL, tree2->right);
  } else if (tree2 == NULL) {
    root->key = tree1->key;
    root->left = mergeTree(tree1->left, NULL);
    root->right = mergeTree(tree1->right, NULL);
  } else {
    root->key = tree1->key + tree2->key;
    root->left = mergeTree(tree1->left, tree2->left);
    root->right = mergeTree(tree1->right, tree2->right);
  }

  return root;
}

void preOrder(TreeNode *root) {
  if (root == NULL)
    return;
  printf("[%d] ", root->key);
  preOrder(root->left);
  preOrder(root->right);
}

int main() {
  TreeNode *N4 = makeNode(5, NULL, NULL);
  TreeNode *N3 = makeNode(2, NULL, NULL);
  TreeNode *N2 = makeNode(3, N4, NULL);
  TreeNode *T1 = makeNode(1, N2, N3);

  TreeNode *M6 = makeNode(7, NULL, NULL);
  TreeNode *M5 = makeNode(4, NULL, NULL);
  TreeNode *M3 = makeNode(3, NULL, M6);
  TreeNode *M2 = makeNode(1, NULL, M5);
  TreeNode *T2 = makeNode(2, M2, M3);

  TreeNode *root = mergeTree(T1, T2);
  preOrder(root);

  return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>

void heapify(int *A, int n, int parent) {
  int max = parent;
  int leftChild = parent * 2 + 1;
  int rightChild = parent * 2 + 2;

  if (leftChild < n && A[parent] < A[leftChild])
    max = leftChild;
  
  if (rightChild < n && A[max] < A[rightChild])
    max = rightChild;
  
  if (max != parent) {
    int temp = A[parent];
    A[parent] = A[max];
    A[max] = temp;
    heapify(A, n, max);
  }
}

void print(int *A, int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", A[i]);
  printf("\n");
}

void heapSort(int *A, int n) {
  printf("\nHeapify ...\n");
  for (int i = 3; i >= 0; i--) {
    printf(" i = %d : ", i);
    heapify(A, n, i);
    print(A, n);
  }

  printf("\nSorting ... \n");
  for (int i = n-2; i >= 0; i--) {
    printf(" i = %d : ", i+1);
    // 정렬
    heapify(A, n, i);
    print(A, n);
  }
}

int main() {
  int data[] = {5, 3, 8, 4, 9, 1, 6, 2, 7};
  int n = sizeof(data) / sizeof(int);
  printf("Origin : ");
  print(data, n);

  heapSort(data, n);
  return 0;
}
*/
