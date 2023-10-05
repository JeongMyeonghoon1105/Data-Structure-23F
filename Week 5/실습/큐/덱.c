/*
front = (front-1+N) % N
rear = 

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

typedef char element;

typedef struct {
  element deque[N];
  int front, rear;
} DequeType;

void init(DequeType *D) {
  D->front = D->rear = 0;
}

int isEmpty(DequeType *D) {
  return D->front == D->rear;
}

int isFull(DequeType *D) {
  return D->front == (D->rear+1) % N;
}

void addFront(DequeType *D, element e) {
  if (isFull(D))
    printf("Full\n");
  else {
    D->deque[D->front] = e;
    D->front = (D->front-1+N) % N;
  }
}

void addRear(DequeType *D, element e) {
  if (isFull(D))
    printf("Full\n");
  else {
    D->rear = (D->rear + 1) % N;
    D->deque[D->rear] = e;
  }
}

element deleteFront(DequeType *D) {
  if (isEmpty(D)) {
    printf("Empty\n");
    return -1;
  }
  D->front = (D->front+1)%N;
  return D->deque[D->front];
}

element deleteRear(DequeType *D) {
  if (isEmpty(D)) {
    printf("Empty\n");
    return -1;
  }
  int pos = D->rear;
  D->rear = (D->rear-1+N) % N;  // 반시계방향 이동
  return D->deque[pos];
}

element getFront(DequeType *D) {
  if (isEmpty(D)) {
    printf("Empty\n");
    return -1;
  }
  return D->deque[(D->front+1) % N];
}

element getRear(DequeType *D) {
  if (isEmpty(D)) {
    printf("Empty\n");
    return -1;
  }
  return D->deque[D->rear];
}

void print(DequeType *Q) {
  printf("Front Pos : %d, Rear Pos : %d\n", Q->front, Q->rear);
  
  int i = Q->front;
  while (i != Q -> rear) {
    i = (i + 1) % N;
    printf("[%c] ", Q->deque[i]);
  }
  
  printf("\n");
}

int main(void) {
  DequeType D;
  init(&D);
  srand(time(NULL));

  for (int i = 0; i < 2; i++)
    addFront(&D, rand() % 26 + 65);

  print(&D);
  printf("\n\n");

  for (int i = 0; i < 3; i++)
    printf("[%c] ", deleteRear(&D));
  printf("\n\n");

  print(&D);
  return 0;
}

