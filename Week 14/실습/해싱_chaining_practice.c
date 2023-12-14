#include <stdio.h>
#include <stdlib.h>

#define M 5

typedef struct ListNode {
  int key;
  struct ListNode *next;
} ListNode;

typedef struct {
  ListNode *head;
} Bucket;

typedef struct {
  Bucket B[M];
} HashTable;

void init(HashTable *HT) {
  for (int i = 0; i < M; i++)
    HT->B[i].head = NULL;
}

int hash(int key) {
  return key % M;
}

void insertItem(HashTable *HT, int key) {
  int b = hash(key);
  ListNode *node = (ListNode*)malloc(sizeof(ListNode));
  node->key = key;
  node->next = NULL;

  if (HT->B[b].head == NULL)
    HT->B[b].head = node;
  else {
    ListNode *p = HT->B[b].head;
    while (p->next != NULL)
      p = p->next;
    p->next = node;
  }
}

void deleteItem(HashTable *HT, int key) {
  int b = hash(key);
  ListNode *p = HT->B[b].head;

  if (p != NULL) {
    while (p->next != NULL) {
      if (p->next->key == key) {
        ListNode *temp = p->next;
        p->next = temp->next;
        free(temp);
        return;
      }
      p = p->next;
    }
  }

  printf("Key was not found.\n");
}

void print(HashTable *HT) {
  for (int i = 0; i < M; i++) {
    printf("[%d] : ", i);
    ListNode *p = HT->B[i].head;
    if (p != NULL) {
      while (p->next != NULL) {
        p = p->next;
        printf("%02d ", p->key);
      }
    }
    printf("\n");
  }
  printf("\n");
}

int main() {
  HashTable HT;
  init(&HT);

  int key;
  int data[10] = {25, 13, 16, 15, 7, 28, 31, 20, 1, 38};

  for (int i = 0; i < 10; i++) {
    insertItem(&HT, data[i]);
    print(&HT);
  }

  for (int i = 0; i < 3; i++) {
    print("Enter key to be deleted: ");
    scanf("%d", &key);

    deleteItem(&HT, key);
    print(&HT);
  }

  return 0;
}
