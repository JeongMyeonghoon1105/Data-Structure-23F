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
  for (int i = 0; i <= S->top; i++)
    printf("%c", S->stack[i]);
  printf("\n");
}

int main(void) {
  StackType s1, s2;
  initStack(&s1);
  initStack(&s2);
  element data[N];

  gets(data);
  int len = strlen(data), pal = 1;

  for (int i = 0; i < len; i++)
    if (data[i] >= 65 && data[i] <= 90) {
      data[i] += 32;
      push(&s1, data[i]);
    } else if (data[i] >= 97 && data[i] <= 122)
      push(&s1, data[i]);
  
  for (int i = 0; i <= (s1.top) / 2; i++)
    push(&s2, pop(&s1));

  if (s1.top == s2.top + 1)
    pop(&s1);

  int iter = s2.top;
  for (int i = 0; i <= iter; i++)
    if (pop(&s1) != pop(&s2)) {
      pal = 0;
      break;
    }

  if (pal)
    printf("회문입니다\n");
  else
    printf("회문이 아닙니다\n");

  return 0;
}
