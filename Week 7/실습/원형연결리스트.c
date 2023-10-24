#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct node {
  element data;
  struct node *link;
} ListNode;

typedef struct {
  ListNode *head;
  int size;
} ListType;

void init(ListType *L) {
  L->head = NULL;
  L->size = 0;
}

int isEmpty(ListType *L) {
  return L->head == NULL;
}

void insertFirst(ListType *L, element e) {
  ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
  newNode->data = e;

  if (isEmpty(L)) {
    newNode->link = newNode;
    L->head = newNode;
  } else {
    newNode->link = L->head->link;
    L->head->link = newNode;
  }

  L->size++;
}

void insertLast(ListType *L, element e) {
  ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
  newNode->data = e;

  if (isEmpty(L)) {
    L->head = newNode;
    newNode->link = newNode;
  } else {
    newNode->link = L->head->link;
    L->head->link = newNode;
    L->head = newNode;
  }

  L->size++;
}

void insertPos(ListType *L, int pos, element e) {
  if (pos < 0 || pos > L->size) {
    printf("List index out of range.\n");
  } else if (pos == 0) {
    insertFirst(L, e);
  } else {
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = e;
    p = L->head->link;

    for (int i = 1; i < pos; i++)
      p = p->link;

    newNode->link = p->link;
    p->link = newNode;
    free(p);
    L->size++;
  }
}

element deleteFirst(ListType *L) {
  if (isEmpty(L)) {
    printf("Empty!\n");
    return -1;
  }

  ListNode *p = L->head->link;
  element e = p->data;

  if (L->head == L->head->link)
    L->head = NULL;
  else
    L->head->link = p->link;

  free(p);
  L->size--;

  return e;
}

element deleteLast(ListType *L) {
  if (isEmpty(L)) {
    printf("Empty!\n");
    return -1;
  }

  ListNode *q = L->head;
  ListNode *p = q->link;
  element e = q->data;

  if (p == q) {
    L->head = NULL;
  } else {
    do {
      p = p->link;
    } while (p->link != q);
    p->link = q->link;
    L->head = p;
  }

  free(q);
  L->size--;

  return e;
}

void print(ListType *L) {
  if (isEmpty(L)) {
    printf("Empty!\n");
    return;
  }

  ListNode *p = L->head->link;
  ListNode *q = p;

  do {
    printf("%d ", p->data);
    p = p->link;
  } while (p != q);
  printf("\n");
}

int main() {
  ListType L;
  init(&L);

  

  return 0;
}