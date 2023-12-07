#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

typedef char element;
/*
char형 데이터를 element라는 자료형으로 새로 정의
char -> int or double 등의 자료형 변환 발생시 대처하기 편한 방법(한꺼번에 변환)
*/

typedef struct {
  element queue[N];
  int front, rear;
} QueueType;
/*
자기 참조가 없는 구조체이기 때문에 구조체 태그는 필요없음
*/

void init(QueueType *Q) { Q->front = Q->rear = -1; }

int isEmpty(QueueType *Q) { return Q->front == Q->rear; }

int isFull(QueueType *Q) { return Q->rear == N - 1; }

void enqueue(QueueType *Q, element e) {
  if (isFull(Q))
    printf("Full\n");
  else {
    Q->rear++;
    Q->queue[Q->rear] = e;
  }
}
/*
스택에서는 top == -1이면 empty이지만, 큐에서는 그렇게 할 수 없다.
큐에서는 front == rear이면 empty이다.
*/

element dequeue(QueueType *Q) {
  if (isEmpty(Q)) {
    printf("Empty\n");
    return -1;
  }
  Q->front++;
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
  for (int i = Q->front + 1; i <= Q->rear; i++)
    printf("[%c] ", Q->queue[i]);
  printf("\n");
}

int main(void) {
  QueueType Q;
  init(&Q);
  srand(time(NULL));

  for (int i = 0; i < 7; i++)
    enqueue(&Q, rand() % 26 + 65);
  /*
  element가 char인 경우 => 알파벳 대문자에 해당하는 아스키코드 값을 난수로 생성
  */

  print(&Q);
  printf("[%c] ", peek(&Q));
  printf("\n\n");

  for (int i = 0; i < 3; i++)
    printf("[%c] ", dequeue(&Q));
  printf("\n\n");

  print(&Q);
  return 0;
}
