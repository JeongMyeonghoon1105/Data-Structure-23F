#include <stdio.h>
#include <stdlib.h>

#define N 10
#define true 1
#define false 0

int visited[N] = {false};

typedef int element;

// Stack
typedef struct {
  int top;
  element stack[N];
} StackType;

// Queue
typedef struct {
  element queue[N];
  int front, rear;
} QueueType;

// Graph
typedef struct {
  int n;
  int adjMat[N][N];
} GraphType;

// Functions for stack
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

// Functions for queue
void initQueue(QueueType *Q) {
  Q->front = Q->rear = -1;
}

int isQueueEmpty(QueueType *Q) {
  return Q->front == Q->rear;
}

int isQueueFull(QueueType *Q) {
  return Q->rear == N - 1;
}

void enqueue(QueueType *Q, element e) {
  if (isQueueFull(Q))
    printf("Full\n");
  else {
    Q->rear++;
    Q->queue[Q->rear] = e;
  }
}

element dequeue(QueueType *Q) {
  if (isQueueEmpty(Q)) {
    printf("Empty\n");
    return -1;
  }
  Q->front++;
  return Q->queue[Q->front];
}

// Functions for graph
void initGraph(GraphType *G) {
  G->n = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      G->adjMat[i][j] = 0;
}

void makeVertex(GraphType *G) {
  G->n++;
}

void insertEdge(GraphType *G, int u, int v) {
  G->adjMat[u][v] = G->adjMat[v][u] = 1;
}

void print(GraphType *G) {
  for (int i = 1; i <= G->n; i++) {
    for (int j = 1; j <= G->n; j++)
      printf("%d\t", G->adjMat[i][j]);
    printf("\n");
  }
}

void rDFS(GraphType *G, int s) {
  visited[s] = true;
  printf("%d ", s);

  for (int t = 1; t <= G->n; t++)
    if (G->adjMat[s][t] == 1 && visited[t] == false)
      rDFS(G, t);
}

void DFS(GraphType *G, int s) {
  StackType S;
  initStack(&S);

  push(&S, s);
  printf("%d ", s);
  visited[s] = true;

  while (!isStackEmpty(&S)) {
    int v = pop(&S);
    if (!(visited[v])) {
      visited[v] = true;
      for (int u = 1; u <= G->n; u++) {
        if (G->adjMat[v][u] == 1 && visited[u] == false) {
          push(&S, u);
          printf("%d ", u);
        }
      }
    }
  }
}

void BFS(GraphType *G, int s) {
  QueueType Q;
  initQueue(&Q);

  visited[s] = true;
  printf("%d ", s);
  enqueue(&Q, s);

  while (!isQueueEmpty(&Q)) {
    s = dequeue(&Q);
    for (int t = 1; t <= G->n; t++)
      if (G->adjMat[s][t] == 1 && visited[t] == false) {
        visited[t] = true;
        printf("%d ", t);
        enqueue(&Q, t);
      }
  }
}

int main() {
  GraphType G;
  initGraph(&G);

  // 정점 개수 입력
  int n; scanf("%d", &n);

  // 정점 생성
  for (int i = 0; i < n; i++)
    makeVertex(&G);

  // 간선 생성
  insertEdge(&G, 1, 2);  insertEdge(&G, 1, 3);  insertEdge(&G, 1, 5);
  insertEdge(&G, 2, 3);
  insertEdge(&G, 3, 4);  insertEdge(&G, 3, 5);
  insertEdge(&G, 4, 5);

  // 그래프 출력
  print(&G);

  // 깊이 우선 탐색
  printf("\nDFS: ");
  // rDFS(&G, 4);
  DFS(&G, 4);

  // 방문 기록 스택 초기화
  for (int i = 0; i < N; i++)
    visited[i] = false;

  // 너비 우선 탐색
  printf("\nBFS: ");
  BFS(&G, 4);
  
  return 0;
}
