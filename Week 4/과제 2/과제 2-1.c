#include <stdio.h>

#define N 10

typedef char element;

typedef struct {
  int top;
  element stack[N];
} StackType;

typedef struct {
  element queue[N];
  int front, rear;
} QueueType;

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

void initQueue(QueueType *Q) { Q->front = Q->rear = -1; }

int isQueueEmpty(QueueType *Q) { return Q->front == Q->rear; }

int isQueueFull(QueueType *Q) { return Q->rear == N - 1; }

void enqueue(QueueType *Q, element e) {
  if (isFull(Q))
    printf("Full\n");
  else {
    Q->rear++;
    Q->queue[Q->rear] = e;
  }
}

element dequeue(QueueType *Q) {
  if (isEmpty(Q)) {
    printf("Empty\n");
    return -1;
  }
  Q->front++;
  return Q->queue[Q->front];
}

StackType S;
QueueType Q;

void convert(char * infix, char * postfix) {
  for (int i = 0; i < N; i++) {
    if (infix[i] == '(')
      push(&S, '(');
    else if (infix[i] == ')'){
      char out;
      while (out != '(') {
        out = pop(&S);
        if (out != '(')
          enqueue(&Q, out);
      }
    }
  }
}

int evaluate(char * postfix) {

}

int main() {
  char infix[N], postfix[N];
  scanf("%s", infix);

  convert(infix, postfix);
  printf("%d\n", evaluate(postfix));

  return 0;
}
