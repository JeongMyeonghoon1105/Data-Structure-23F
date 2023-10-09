#include <stdio.h>

#define MAX 4

typedef int element;

typedef struct Node {
  element e;
  struct Node *next;
} node;

typedef struct {
  node start;
  node *top;
} StackType;

void initStack(StackType *s) {
  s->start.e = NULL;
  s->start.next = NULL;
  s->top = &(s->start);
}

int stackSize(StackType *s) {
  int count = -1;
  node *travel = &(s->start);
  while (travel != NULL) {
    travel = travel->next;
    count++;
  }
  return count;
}

int isStackEmpty(StackType *s) {
  return &(s->start) == s->top;
}

int isStackFull(StackType *s) {
  return stackSize(s) >= MAX;
}

node *push(StackType *s, element elem) {
  if (isStackFull(s)) {
    printf("Full\n");
    return s->top;
  }
  node *newNode = (node*)malloc(sizeof(node));
  newNode->e = elem;
  newNode->next = NULL;
  s->top->next = newNode;
  return newNode;
}

node *pop(StackType *s) {
  if (isStackEmpty(s)) {
    printf("Empty\n");
    return &(s->start);
  }
  node *travel = &(s->start);
  while (travel->next->next != NULL)
    travel = travel->next;
  printf("Pop: %d\n", travel->next->e);
  travel->next = NULL;
  // free(travel->next);
  return travel;
}

element peekStack(StackType *s) {
  return s->top->e;
}

void printStack(StackType *s) {
  node *travel = s->start.next;
  printf("Stack: ");
  while (travel != NULL) {
    printf("%d ", travel->e);
    travel = travel->next;
  }
  printf("\n");
}
