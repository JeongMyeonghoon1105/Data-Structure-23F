#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef char element;

typedef struct {
  int top;
  element stack[N];
} StackType;

void initStack(StackType *S) {
  S->top = -1;
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

element peek(StackType *S) {
  if (isStackEmpty(S)) {
    printf("Empty\n");
    return -1;
  }
  return S->stack[S->top];
}

void printStack(StackType *S) {
  for (int i = 0; i < S->top; i++)
    printf("%c ", S->stack[i]);
  printf("\n");
}

int prec(char op) {
  switch (op) {
    case '(': case ')':
      return 0;
    case '+': case '-':
      return 1;
    case '*': case '/':
      return 2;
  }
  return -1;
}

void convert(char *exp, char *postfix) {
  char ch, top_op;
  int len = strlen(exp), index = 0;

  StackType s;
  initStack(&s);

  for (int i = 0; i < len; i++) {
    ch = exp[i];
    switch (ch) {
      case '+': case '-': case '*': case '/':
        while (!isStackEmpty(&s) && (prec(ch)) <= prec(peek(&s))) {
          postfix[index] = pop(&s);
          index++;
        }
        push(&s, ch);
        break;
      case '(':
        push(&s, ch);
        break;
      case ')':
        top_op = pop(&s);
        while (top_op != '(') {
          postfix[index] = top_op;
          index++;
          top_op = pop(&s);
        }
        break;
      default:
        postfix[index] = ch;
        index++;
        break;
    }
  }
  while (!isStackEmpty(&s)) {
    postfix[index] = pop(&s);
    index++;
  }

  postfix[index] = '\0';
  // printf("%s\n", postfix);
}

int evaluate(char *exp) {
  int op1, op2, value;
  int len = strlen(exp);
  char ch;

  StackType s;
  initStack(&s);

  for (int i = 0; i < len; i++) {
    ch = exp[i];
    if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
      value = ch - '0';
      push(&s, value);
    } else {
      op2 = pop(&s);
      op1 = pop(&s);
      switch (ch) {
        case '+':
          push(&s, op1 + op2);
          break;
        case '-':
          push(&s, op1 - op2);
          break;
        case '*':
          push(&s, op1 * op2);
          break;
        case '/':
          push(&s, op1 / op2);
          break;
      }
    }
  }
  return pop(&s);
}

int main(void) {
  char infix[N], postfix[N];
  scanf("%s", infix);

  convert(infix, postfix);
  printf("%d\n", evaluate(postfix));

  return 0;
}
