#include <stdio.h>
#include <stdlib.h>

#define N 10
#define true 1
#define false 0

typedef char element;

typedef struct AdjacentVertex {
  element aName;
  struct AdjacentVertex *next;
} AdjacentVertex;

typedef struct Vertex {
  element vName;
  AdjacentVertex *aHead;
  struct Vertex *next;
} Vertex;

typedef struct {
  Vertex *vHead;
} GraphType;

void initGraph(GraphType *G) {
  G->vHead = NULL;
}

void makeVertex(GraphType *G, element vName) {
  Vertex *v = (Vertex*)malloc(sizeof(Vertex));
  v->vName = vName;
  v->aHead = NULL;    // 아직 간선이 생성되지 않았으므로 연결된 정점 없음
  v->next = NULL;     // insert last 하기 위한 처리

  Vertex *p = G->vHead;

  // insert
  if (p == NULL)      // 비어있으면 insert first
    G->vHead = v;
  else {              // 이니면 insert last
    while (p->next != NULL)   // 삽입하려면 끝까지 가면 안되므로 p->next != NULL
      p = p->next;
    p->next = v;
  }
}

void makeAdjacentVertex(Vertex *v, element aName) {
  AdjacentVertex *a = (AdjacentVertex*)malloc(sizeof(AdjacentVertex));
  a->aName = aName;
  a->next = NULL;

  AdjacentVertex *p = v->aHead;

  // insert
  if (p == NULL)
    v->aHead = a;
  else {
    while (p->next != NULL)
      p = p->next;
    p->next = a;
  }
}

// vName과 같은 이름을 가진 Vertex 찾아 주소 리턴
Vertex *findVertex(GraphType *G, element vName) {
  Vertex *p = G->vHead;

  while (p->vName != vName)
    p = p->next;

  return p;
}

void insertEdge(GraphType *G, element v1, element v2) {
  // v1, v2는 정점 이름(char) --> 해당 이름을 가진 실제 정점을 찾아야 함
  Vertex *v = findVertex(G, v1);

  makeAdjacentVertex(v, v2);

  v = findVertex(G, v2);
  makeAdjacentVertex(v, v1);
}

void print(GraphType *G) {
  Vertex *p = NULL;
  AdjacentVertex *q = NULL;

  for (p = G->vHead; p != NULL; p = p->next) {
    printf("%c: ", p->vName);
    for (q = p->aHead; q != NULL; q = q->next)
      printf("%c ", q->aName);
    printf("\n");
  }
}

int main() {
  GraphType G;
  initGraph(&G);

  // 정점 생성
  makeVertex(&G, 'a');  makeVertex(&G, 'b');
  makeVertex(&G, 'c');  makeVertex(&G, 'd');
  makeVertex(&G, 'e');  makeVertex(&G, 'f');
  makeVertex(&G, 'g');

  // 간선 생성
  insertEdge(&G, 'a', 'b');  insertEdge(&G, 'a', 'f');
  insertEdge(&G, 'b', 'c');  insertEdge(&G, 'b', 'g');
  insertEdge(&G, 'c', 'd');
  insertEdge(&G, 'd', 'e');  insertEdge(&G, 'd', 'g');
  insertEdge(&G, 'e', 'f');  insertEdge(&G, 'e', 'g');

  // 그래프 출력
  print(&G);
  
  return 0;
}
