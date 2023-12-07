#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 13

typedef struct HashNode {
  int key;
  struct HashNode *next;
} HashNode;

void init(HashNode *HT) {
  for (int i = 0; i < M; i++) {
    HT[i].key = -1;
    HT[i].next = NULL;
  }
}

int h(int key) {
  return key % M;
}

void insertItem(HashNode *HT, int key) {
  int b = h(key);

  HashNode *node = (HashNode *)malloc(sizeof(HashNode));
  node->key = key;
  node->next = HT[b].next;
  HT[b].next = node;
}

void print(HashNode *HT) {
  HashNode *p = NULL;

  for (int i = 0; i < M; i++) {
    printf("HT[%02d]: i", i);
    for (p = HT[i].next; p != NULL; p = p->next)
      printf("[%d] ", p->key);
    printf("\n");
  }
}

int main(void) {
  HashNode HT[M];
  init(HT);

  srand(time(NULL));

  for (int i = 0; i < 20; i++)
    insertItem(HT, rand() % 90 + 10);

  print(HT);

  return 0;
}
