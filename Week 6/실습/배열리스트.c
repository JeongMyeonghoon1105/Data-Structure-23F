#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef int element;

typedef struct listType {
  element data[N];
  int size;
} ListType;

void init(ListType *L) {
  L->size = 0;  
}

int isEmpty(ListType *L) {
  return L->size == 0;
}

int isFull(ListType *L) {
  return L->size == N;
}

void insertLast(ListType *L, element e) {
  if (isFull(L)) {
    printf("Full!\n");
    return;
  }
  L->data[L->size] = e;
  L->size++;
}

void insertPos(ListType *L, int pos, element e) {
  if (isFull(L)) {
    printf("Full!\n");
    return;
  }
  if (pos < 0 || pos > L->size) {
    printf("Invalid position!\n");
    return;
  }
  for (int i = L->size; i > pos; i--) {
    L->data[i] = L->data[i-1];
    L->data[pos] = e;
    L->size++;
  }
}

element deleteLast(ListType *L) {
  if (isEmpty(L)) {
    printf("Empty!\n");
    return -1;
  }
  element e = L->data[L->size-1];
  L->size--;
  return e;
}

element deletePos(ListType *L, int pos) {
  element e = L->data[pos];
  for (int i = pos; i < (L->size-1); i++)
    L->data[i] = L->data[i+1];
  L->size--;
  return e;
}

int getPosition(ListType *L) {
  int key;
  printf("Input key: ");
  scanf("%d", &key);

  for (int i = 0; i < L->size; i++)
    if (key == L->data[i])
      return i;
  return -1;
}

void print(ListType *L) {
  for (int i = 0; i < L->size; i++)
    printf("[%d] ", L->data[i]);
  printf("\n");
}

int main() {
  ListType L;
  init(&L);

  insertLast(&L, 10);  print(&L);
  insertLast(&L, 20);  print(&L);
  insertLast(&L, 30);  print(&L);
  
  return 0;
}
