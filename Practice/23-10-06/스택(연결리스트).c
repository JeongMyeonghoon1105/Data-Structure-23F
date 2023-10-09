#include <stdio.h>

#define MAX 100

typedef int element;

typedef struct Node {
  element e;
  struct Node *next;
} node;

typedef struct {
  node start;
  node *top;
  int n;
} StackType;

void initStack(StackType *s) {
  s->start.e = NULL;
  s->start.next = NULL;
  s->top = &(s->start);
  printf("Push: %x\n", s->top);
  s->n = -1;
}

int isStackEmpty(StackType *s) {
  return s->n == -1;
}

int isStackFull(StackType *s) {
  return s->n == MAX-1;
}

node *push(StackType *s, element elem) {
  node *newNode = (node*)malloc(sizeof(node));
  newNode->e = elem;
  newNode->next = NULL;
  s->top->next = newNode;
  return newNode;
}

void pop() {

}

element peekStack(StackType *s) {
  return s->top->e;
}

void printStack(StackType *s) {
  node *travel = s->start.next;
  while (travel != NULL) {
    printf("%d ", travel->e);
    travel = travel->next;
  }
  printf("\n");
}
