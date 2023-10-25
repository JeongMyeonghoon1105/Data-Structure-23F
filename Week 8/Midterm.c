#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;

typedef struct ListNode {
  element data;
  struct ListNode *next;
} ListNode;

typedef struct ListType {
  ListNode *H;
} ListType;

void init(ListType *L) {
  L->H = NULL;
}

int isEmpty(ListType *L) {
  return L->H == NULL;
}

// void insertPos(ListType *L, int pos, element e) {
//   ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
//   ListNode *p;

//   printf("pos : %d\n", pos);

//   newNode->data = e;
//   p = L->H;

//   if (pos) {
//     for (int i = 0; i < pos; i++)
//       p = p->next;
//     p->next = newNode;
//     newNode->next = p->next;
//   } else {
//     L->H = newNode;
//     newNode->next = NULL;
//   }
// }

void makeSet(ListType *L, element e) {
  ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
  newNode->data = e;
  newNode->next = NULL;

  if (isEmpty(L))
    L->H = newNode;
  else {
    ListNode *p = L->H;
    ListNode *q = NULL;

    if (e < p->data) {
      newNode->next = p;
      L->H = newNode;
    } else {
      while (p != NULL && p->data < e) {
        q = p;
        p = p->next;
      }
      if (p != NULL && p->data == e)
        return;
      newNode->next = q->next;
      q->next = newNode;
    }
  }
}

void intersect(ListType *L1, ListType *L2) {
  printf("Intersect : {");
  ListNode *p = L1->H, *q = L2->H;
  while (p != NULL) {
    q = L2->H;
    while (q != NULL) {
      if (p->data == q->data)
        printf("%d ", p->data);
      q = q->next;
    }
    p = p->next;
  }
  printf("}\n");
}

void set_union(ListType *L1, ListType *L2) {
  printf("Union : {");
  ListNode *p = L1->H, *q = L2->H;
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
  while (q != NULL) {
    p = L1->H;
    int overlap = 0;
    while (p != NULL) {
      if (p->data == q->data)
        overlap = 1;
      p = p->next;
    }
    if (!(overlap))
      printf("%d ", q->data);
    q = q->next;
  }
  printf("}\n");
}

void difference(ListType *L1, ListType *L2) {
  printf("Difference : {");
  ListNode *p = L1->H, *q = L2->H;

  while (p != NULL) {
    q = L2->H;
    int overlap = 0;
    while (q != NULL) {
      if (p->data == q->data)
        overlap = 1;
      q = q->next;
    }
    if (!(overlap))
      printf("%d ", p->data);
    p = p->next;
  }

  p = L1->H;
  q = L2->H;

  while (q != NULL) {
    p = L1->H;
    int overlap = 0;
    while (p != NULL) {
      if (p->data == q->data)
        overlap = 1;
      p = p->next;
    }
    if (!(overlap))
      printf("%d ", q->data);
    q = q->next;
  }

  printf("}\n");
}

void print(ListType *L) {
  ListNode *p = L->H;

  printf("{");
  while (p->next != NULL) {
    printf("%d, ", p->data);
    p = p->next;
  }
  printf("%d}\n", p->data);
}

int main() {
  srand(time(NULL));
  ListType L1, L2;
  init(&L1); init(&L2);

  for (int i = 0; i < 10; i++) {
    makeSet(&L1, rand() % 30 + 1);
    makeSet(&L2, rand() % 30 + 1);
  }

  print(&L1); print(&L2);

  intersect(&L1, &L2);
  set_union(&L1, &L2);
  difference(&L1, &L2);

  return 0;
}
