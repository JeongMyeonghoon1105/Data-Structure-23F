#include <stdio.h>
#include <string.h>

#define N 100

typedef char element;

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
    printf("%c", S->stack[i]);
  printf("\n");
}

int palindrome(StackType *S, int len, element *data) {
  for (int i = 0; i < len / 2; i++)
    push(&S, data[i]);
  printStack(&S);
  
  for (int i = len / 2 + 1; i < len; i++) {
    if (data[i] != pop(&S))
      return 0;
  }
  return 1;
}

int main(void) {
  StackType S;
  initStack(&S);
  element data[N];

  gets(data);
  int len = strlen(data), pal = 1;

  for (int i = 0; i <= len / 2; i++) {
    if (data[i] >= 65 && data[i] <= 90) {
      data[i] += 32;
      push(&S, data[i]);
    } else if (data[i] >= 97 && data[i] <= 122)
      push(&S, data[i]);
  }
  
  for (int i = len / 2 + 1; i < len; i++)
    if (data[i] >= 65 && data[i] <= 90 && data[i] >= 97 && data[i] <= 122) {
      if (data[i] != pop(&S))
        pal = 0;
    }

  if (pal)
    printf("회문입니다\n");
  else
    printf("회문이 아닙니다\n");

  return 0;
}
