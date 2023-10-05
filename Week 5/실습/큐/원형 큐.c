/*
front와 rear를 0으로 초기화
공백 : front == rear
포화 : front == (rear + 1) % N

원형 큐를 꽉 채운다고 가정하면 포화 상태에서도 front == rear가 되므로 rear 다음이 front이면 enqueue를 하지 않음. 즉, 한 칸 비어있는 상태가 포화상태, 꽉 차있는 상태는 오류상태.

원형 큐에서는 front가 rear보다 뒤에 있을 수 있다는 것을 반드시 고려
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

typedef char element;

typedef struct {
  element queue[N];
  int front, rear;
} QueueType;

void init(QueueType *Q) {
  Q->front = Q->rear = 0;
}

int isEmpty(QueueType *Q) {
  return Q->front == Q->rear;
}

int isFull(QueueType *Q) {
  return Q->front == (Q->rear+1) % N;
}

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
  Q->front = (Q->front+1)%N;
  return Q->queue[Q->front];
}

element peek(QueueType *Q) {
  if (isEmpty(Q)) {
    printf("Empty\n");
    return -1;
  }
  return Q->queue[Q->front + 1];
}

void print(QueueType *Q) {
  printf("Front Pos : %d, Rear Pos : %d\n", Q->front, Q->rear);
  
  int i = Q->front;
  while (i != Q -> rear) {
    i = (i + 1) % N;
    printf("[%c] ", Q->queue[i]);
  }
  
  printf("\n");
}

int main(void) {
  QueueType Q;
  init(&Q);
  srand(time(NULL));

  for (int i = 0; i < 7; i++)
    enqueue(&Q, rand() % 26 + 65);

  print(&Q);
  printf("[%c] ", peek(&Q));
  printf("\n\n");

  for (int i = 0; i < 3; i++)
    printf("[%c] ", dequeue(&Q));
  printf("\n\n");

  print(&Q);
  return 0;
}
