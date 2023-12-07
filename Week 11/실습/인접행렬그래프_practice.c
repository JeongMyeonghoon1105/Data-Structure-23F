#include <stdio.h>
#include <stdlib.h>

#define M 11
#define true 1
#define false 0

typedef int element;

element visited[M] = {false};

typedef struct {
  int head, tail;
  element queue[M];
} QueueType;

typedef struct {
  int n;
  element adjMat[M][M];
} GraphType;

void initQueue(QueueType *Q) {
  Q->head = Q->tail = 0;
}

int isEmpty(QueueType *Q) {
  return Q->head == Q->tail;
}

int isFull(QueueType *Q) {
  return Q->tail >= M;
}

void enqueue(QueueType *Q, element e) {
  if (isFull(Q))
    return;
  Q->queue[Q->tail] = e;
  Q->tail++;
}

element dequeue(QueueType *Q) {
  if (isEmpty(Q))
    return -1;
  element e = Q->queue[Q->head];
  Q->queue[Q->head] = -1;
  Q->head++;
  return e;
}

void initGraph(GraphType *G) {
  G->n = 0;
  for (int i = 0; i < M; i++)
    for (int j = 0; j < M; j++)
      G->adjMat[i][j] = 0;
}

void makeVertex(GraphType *G, element data) {
  G->n++;
}

void insertEdge(GraphType *G, element n1, element n2) {
  G->adjMat[n1][n2] = G->adjMat[n2][n1] = 1;
}

void printGraph(GraphType *G) {
  printf("\t");
  for (int i = 1; i <= G->n; i++)
    printf("%d번\t", i);
  printf("\n");
  for (int i = 1; i <= G->n; i++) {
    printf("%d번\t", i);
    for (int j = 1; j <= G->n; j++)
      printf("%d\t", G->adjMat[i][j]);
    printf("\n");
  }
}

void rDFS(GraphType *G, element start) {
  visited[start] = true;
  printf("%d ", start);
  for (int i = 1; i <= G->n; i++)
    if (G->adjMat[start][i] && !(visited[i]))
      rDFS(G, i);
}

void BFS(GraphType *G, element start) {
  QueueType *q;
  initQueue(&q);

  enqueue(&q, start);
  printf("%d\n", dequeue(q));

  // while (!isEmpty(&q)) {
  //   element current = dequeue(q);
  //   printf("%d ", current);
  //   visited[current] = true;
  //   for (int i = 1; i <= G->n; i++) {
  //     if (G->adjMat[current][i] && !(visited[i])) {
  //       enqueue(&q, i);
  //     }
  //   }
  // }

  printf("\n");
}

int main() {
  GraphType g;
  initGraph(&g);

  // 정점 생성
  printf("정점 개수 입력 : ");
  int n;  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    makeVertex(&g, i);

  // 간선 생성
  insertEdge(&g, 1, 3); insertEdge(&g, 1, 5);
  insertEdge(&g, 2, 3); 
  insertEdge(&g, 3, 4);
  insertEdge(&g, 4, 5);

  // 결과 출력
  printGraph(&g);

  // 깊이 우선 탐색
  printf("\nInput starting node for DFS search : ");
  int startNode;  scanf("%d", &startNode);
  printf("DFS Search Result : ");
  rDFS(&g, startNode);
  printf("\n");

  // visited 배열 초기화
  for (int i = 0; i < M; i++)
    visited[i] = false;
  
  // 넓이 우선 탐색
  printf("\nInput starting node for BFS search : ");
  scanf("%d", &startNode);
  printf("BFS Search Result : ");
  BFS(&g, startNode);
  printf("\n");

  return 0;
}
