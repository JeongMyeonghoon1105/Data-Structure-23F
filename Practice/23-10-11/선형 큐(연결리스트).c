#include <stdio.h>

#define MAX 50

typedef int element;

typedef struct Node {
  element e;
  struct Node *next;
} node;

typedef struct {
  node *front;
  node *rear;
} QueueType;

void init(QueueType *q) {
  q->front = NULL;
  q->rear = NULL;
}

int isEmpty(QueueType *q);
int isFull(QueueType *q);

node *enqueue(QueueType *q, element elem) {
  if (isFull(q)) {
    printf("Full\n");
    return q->rear;
  }
  node *newNode = (node*)malloc(sizeof(node));
  newNode->e = elem;
  newNode->next = NULL;
  q->rear->next = newNode;
  return newNode;
}

void dequeue(QueueType *q);
element peek();
void print();
