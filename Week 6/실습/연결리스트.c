/*
연결리스트는 하나의 독립적인 자료구조가 아님.
리스트라는 자료구조를 연결된 표현법으로 나타낸 것.

연결리스트의 모든 동작은 head 포인터로부터 시작.
*/

#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct ListNode {
  element data;
  struct ListNode *next;
} ListNode;

typedef struct ListType {
  ListNode *head;
  int size;   // Optional
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
  newNode->next = L->head;
  L->head = newNode;
  L->size++;
}

void insertLast(ListType *L, element e) {
  ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
  newNode->data = e;
  if (isEmpty(L)) {
    L->head = newNode;
    return;
  }
  ListNode *node = L->head;
  while (node->next != NULL)
    node = node->next;
  node->next = newNode;
  L->size++;
}

void insertPos(ListType *L, int pos, element e) {
  if (pos == 1)
    insertFirst(L, e);
  else if (pos == L->size + 1)
    insertLast(L, e);
  else {
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    ListNode *node = L->head;
    for (int i = 1; i <= pos; i++)
      node = node->next;
    newNode->data = e;
    newNode->next = node->next;
    node->next = newNode;
    L->size++;
  }
}

void insertSearch(ListType *L, element pos, element e) {
  ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
  newNode->data = e;
  ListNode *node = L->head;
  while (node->data != pos) {
    node = node->next;
    if (node == NULL)
      return;
  }
  newNode->next = node->next;
  node->next = newNode;
  L->size++;
}

element deleteFirst(ListType *L) {
  if (isEmpty(L)) {
    printf("Empty!\n");
    return -1;
  }
  ListNode *node = L->head;
  element e = node->data;
  L->head = node->next;  // 노드가 1개였으면 node->next == NULL이므로 NULL이 L->head로 들어와 초기 상태가 된다.
  free(node);
  L->size--;
  return e;
}

element deleteLast(ListType *L) {
  if (isEmpty(L)) {
    printf("Empty!");
    return -1;
  }

  ListNode *p = L->head;
  ListNode *q = NULL;
  element e;
  
  while (p->next != NULL) {
    q = p;
    p = p->next;
  }

  q->next = NULL;
  free(p);
  L->size--;

  return e;
}

element deletePos(ListType *L, int pos) {
  if (isEmpty(L)) {
    printf("Empty!\n");
    return -1;
  }
  
  // node->next->next 사용하지 맙시다!
  // 한 칸 차이로 움직이는 화살표 2개 써서 해결.

  ListNode *p = L->head;
  ListNode *q = NULL;
  element e;
  
  if (pos == 1)
    e = deleteFirst(L);
  else {
    for (int i = 1; i < pos; i++) {
      q = p;
      p = p->next;
    }
    e = p->data;
    q->next = p->next;
    free(p);
    L->size--;
  }

  return e;
}

void print(ListType *L) {
  ListNode *node = L->head;
  while (node != NULL) {
    printf("%c ", node->data);
    node = node->next;
  }
  printf("\n");
}

int main() {
  ListType L;
  init(&L);

  deleteLast(&L); print(&L);
  insertLast(&L, 'A'); print(&L);
  insertFirst(&L, 'B'); print(&L);
  insertFirst(&L, 'C'); print(&L);
  insertLast(&L, 'D'); print(&L);
  insertLast(&L, 'E'); print(&L);
  deleteLast(&L); print(&L);
  insertSearch(&L, 'K', 'F'); print(&L);
  insertSearch(&L, 'B', 'G'); print(&L);
  insertPos(&L, 3, 'H'); print(&L);
  
  return 0;
}
