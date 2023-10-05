#include <stdio.h>

#define N 100

typedef int element;

typedef struct {
  int top;
  element stack[N];
} StackType;

void initStack(StackType *S) {
  S -> top = -1;
}

int isStackEmpty(StackType *S) {
  return S->top == -1;
}

int isStackFull(StackType *S) {
  return S->top == N-1;
}

void push(StackType *S, element e) {
  if (isStackFull(S))
    printf("Full\n");
  S->top++;
  S->stack[S->top] = e;
}

element pop(StackType *S) {
  if (isStackEmpty(S)) {
    printf("Empty\n");
    return -1;
  }
  element e = S->stack[S->top];
  S->top--;
  return e;
}

void printStack(StackType *S) {
  for (int i = 0; i < S->top; i++)
    printf("%d ", S->stack[i]);
  printf("\n");
}

/*
int main(void) {
  StackType S;
  initStack(&S);
  element data[6] = {5, 3, 8, 1, 2, 7};

  for (int i = 0; i < 7; i++) {
    push(&S, data[i]);
    printStack(&S);
  }

  for (int i = 0; i < 3; i++)
    pop(&S);
  
  return 0;
}
*/
