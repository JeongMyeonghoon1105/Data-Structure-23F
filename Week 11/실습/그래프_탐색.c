#include <stdio.h>
#include <stdlib.h>

#define N 10
#define TRUE 1
#define FALSE 0

typedef char element;

typedef struct AdjacentVertex {
  element aName;
  struct AdjacentVertex *next;
} AdjacentVertex;

typedef struct Vertex {
  element vName;
  int isVisit;
  AdjacentVertex *aHead;
  struct Vertex *next;
} Vertex;

typedef struct {
  Vertex *vHead;
} GraphType;

void init(GraphType *G) {
  G->vHead = NULL;
}

void makeVertex(GraphType *G, element vName) {
  Vertex *v = (Vertex *)malloc(sizeof(Vertex));
  v->vName = vName;
  v->isVisit = FALSE;
  v->aHead = NULL;
  v->next = NULL;
  
  Vertex *p = G->vHead;
  
  if (p == NULL)
    G->vHead = v;
  else {
    while (p->next != NULL)
      p = p->next;
    p->next = v;    
  }
}

Vertex* findVertex(GraphType *G, element vName) {
  Vertex *p = G->vHead;
  
  while (p->vName != vName)
    p = p->next;
  
  return p;    
}

void makeAdjacentVertex(Vertex *v, element aName) {
  AdjacentVertex *a = (AdjacentVertex *)malloc(sizeof(AdjacentVertex));
  a->aName = aName;
  a->next = NULL;
  
  AdjacentVertex *p = v->aHead;
  
  if(p == NULL)
    v->aHead = a;
  else {
    while (p->next != NULL)
      p = p->next;
    p->next = a;    
  }
}

void insertEdge(GraphType *G, element v1, element v2) {
  Vertex *v = findVertex(G, v1);
  makeAdjacentVertex(v, v2);
  
  v = findVertex(G, v2);
  makeAdjacentVertex(v, v1);
}

void print(GraphType *G) {
  Vertex *p = NULL;
  AdjacentVertex *q = NULL;
  
  for (p = G->vHead; p != NULL; p = p->next) {
    printf("[%c] : ", p->vName);
    for (q = p->aHead; q != NULL; q = q->next)
      printf("[%c] ", q->aName);
    printf("\n");    
  }
}

void rDFS(GraphType *G, char vName) {
  Vertex *v = findVertex(G, vName);
  AdjacentVertex *a = NULL;
  
  if (v->isVisit == FALSE) {
      v->isVisit = TRUE;
      printf("[%c] ", v->vName);
  }
  
  for (a = v->aHead; a != NULL; a = a->next) {
    v = findVertex(G, a->aName);
    if (v->isVisit == FALSE)
      rDFS(G, v->vName);
  }
}

typedef struct {
	element data[N];
	int front, rear;
} QueueType;

void initQueue(QueueType* Q) {
	Q->front = Q->rear = 0;
}

int isQueueEmpty(QueueType* Q) {
	return Q->rear == Q->front;
}

int isQueueFull(QueueType* Q) {
	return (Q->rear + 1) % N == Q->front;
}

void enqueue(QueueType* Q, element d) {
	if (isQueueFull(Q))
    printf("Overflow!!\n");
	else {
    Q->rear = (Q->rear + 1) % N;
    Q->data[Q->rear] = d;
	}
}

element dequeue(QueueType* Q) {
	if (isQueueEmpty(Q)) {
		printf("Empty!!\n");
    return -1;
	}
	Q->front = (Q->front + 1) % N;
	return Q->data[Q->front];
}

void BFS(GraphType *G, element vName) {
  Vertex *v = findVertex(G, vName);
  AdjacentVertex *a = NULL;
  
  QueueType Q;
  initQueue(&Q);
  
  v->isVisit = TRUE;
  printf("[%c] ", v->vName);
  enqueue(&Q, v->vName);
  
  while (!isQueueEmpty(&Q)) {
    v = findVertex(G, dequeue(&Q));
    
    for (a = v->aHead; a != NULL; a = a->next) {
      v = findVertex(G, a->aName);
      if (v->isVisit == FALSE) {
        v->isVisit = TRUE;
        printf("[%c] ", v->vName);
        enqueue(&Q, v->vName);
      }
    }
  }
}

typedef struct {
  element data[N];
  int top;
} StackType;

void initStack(StackType* S) {
  S->top = -1;
}

int isStackEmpty(StackType* S) {
  return S->top == -1;
}

int isStackFull(StackType* S) {
  return S->top == N - 1;
}

void push(StackType* S, element d) {
    if (isStackFull(S))
      printf("Overflow!!\n");
    else {
      S->top++;
      S->data[S->top] = d;
    }
}

element pop(StackType* S) {
  if (isStackEmpty(S)) {
    printf("Empty!!\n");
    return -1;
  }
  
  element d = S->data[S->top];
  S->top--;
  return d;
}

element peek(StackType* S) {
  if (isStackEmpty(S)) {
    printf("Empty!!\n");
    return -1;
  }
  
  return S->data[S->top];
}

void DFS(GraphType *G, element vName) {
  Vertex *v = findVertex(G, vName);
  AdjacentVertex *a = NULL;
  
  StackType S;
  initStack(&S);
  
  push(&S, v->vName);
  // int flag;
  while (!isStackEmpty(&S)) {
    v = findVertex(G, peek(&S));
    if (v->isVisit == FALSE) {
      v->isVisit = TRUE;
      printf("[%c] ", v->vName);
    }
      
    // flag = TRUE;   
    for (a = v->aHead; a != NULL; a = a->next) {
      v = findVertex(G, a->aName);
      if (v->isVisit == FALSE) {
        push(&S, v->vName);
        // flag = FALSE; 
        break;
      }
    }
      
    // if(flag == TRUE)
    if(a == NULL)
      pop(&S);
  }
}

int main() {
  GraphType G;
  init(&G);
  
  makeVertex(&G, 'a'); makeVertex(&G, 'b');
  makeVertex(&G, 'c'); makeVertex(&G, 'd');
  makeVertex(&G, 'e'); makeVertex(&G, 'f');
  makeVertex(&G, 'g');
  
  insertEdge(&G, 'a', 'b'); insertEdge(&G, 'a', 'f');
  insertEdge(&G, 'b', 'c'); insertEdge(&G, 'b', 'g');
  insertEdge(&G, 'c', 'd');
  insertEdge(&G, 'd', 'e'); insertEdge(&G, 'd', 'g');
  insertEdge(&G, 'e', 'f'); insertEdge(&G, 'e', 'g');
  
  print(&G); printf("\n");
  
  //printf("rDFS : "); rDFS(&G, 'g');
  //printf("BFS : "); BFS(&G, 'g');
  printf("DFS : "); DFS(&G, 'g');
  
  return 0;
}
