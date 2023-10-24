#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct node {
  element data;
  struct node *prev;
  struct node *next;
} DListNode;

typedef struct {
  DListNode *head;
  DListNode *tail;
  int size;
} DListType;

void init(DListType *DL) {
  DL->head = NULL;
  DL->tail = NULL;
  DL->size = 0;
}

int isEmpty(DListType *DL) {
  return DL->head == NULL;
}

void insertFirst(DListType *DL, element e) {
  DListNode *newNode = (DListNode*)malloc(sizeof(DListNode));
  newNode->data = e;
  newNode->prev = NULL;
  newNode->next = DL->head;

  if (isEmpty(DL))
    DL->head = DL->tail = newNode;
  else {
    DL->head->prev = newNode;
    DL->head = newNode;
  }

  DL->size++;
}

void insertLast(DListType *DL, element e) {
  DListNode *newNode = (DListNode*)malloc(sizeof(DListNode));
  newNode->data = e;
  newNode->next = NULL;
  newNode->prev = DL->tail;

  if (isEmpty(DL))
    DL->head = DL->tail = newNode;
  else {
    DL->tail->next = newNode;
    DL->tail = newNode;
  }

  DL->size++;
}

void print(DListType *DL) {
  if (isEmpty(DL)) {
    printf("Empty!\n");
    return;
  }
  
  DListNode *p = (DListNode*)malloc(sizeof(DListNode));
  p = DL->head;

  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

int main() {
  DListType DL;
  init(&DL);

  for (int i = 1; i <= 10; i++) {
    insertFirst(&DL, i);
    print(&DL);
  }

  return 0;
}
