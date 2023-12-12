#include <stdio.h>
#include <stdlib.h>

#define M 13

typedef struct {
  int key;
  int probeCount;
} Bucket;

typedef struct HashTable {
  Bucket B[M];
} HashTable;

void init(HashTable *HT) {
  for (int i = 0; i < M; i++) {
    HT->B[i].key = 0;
    HT->B[i].probeCount = 0;
  }
}

// 해시 함수
int hash(int key) {
  return key % M;
}

int isEmpty(HashTable *HT, int addr) {
  return HT->B[addr].key == 0;
}

// 선형 조사
int getNextBucketLinear(int v, int inc) {
  return (v + inc) % M;
}

// 이차 조사
int getNextBucketDouble(int v, int inc) {
  return (v + inc * inc) % M;
}

// 삽입
void insertItem(HashTable *HT, int num) {
  int b = hash(num), inc = 0, count = 0;

  while (inc < M) {
    count++;
    b = getNextBucketLinear(b, inc);

    if (isEmpty(HT, b)) {
      HT->B[b].key = num;
      HT->B[b].probeCount = count;
      return;
    } else
      inc++;
  }
}

// 탐색
void searchItem(HashTable *HT, int key) {
  int b = hash(key), inc = 0;
  
  while (inc < M) {
    b = getNextBucketLinear(b, inc);

    if (key == HT->B[b].key) {
      printf("Key was found at address %d.\n", b);
      return;
    } else
      inc++;
  }

  printf("Key was not found.\n");
}

// 삭제
void deleteItem(HashTable *HT, int key) {
  int b = hash(key), inc = 0;

  while (inc < M) {
    b = getNextBucketLinear(b, inc);
    if (key == HT->B[b].key) {
      HT->B[b].key = -1;
      return;
    } else
      inc++;
  }

  printf("Key was not found.\n");
}

// 출력
void print(HashTable *HT) {
  for (int i = 0; i < M; i++)
    printf(" %2d", HT->B[i].key);
  printf("\n");
}

void printHash(HashTable *HT) {
  printf("\nBucket   Key Probe\n");
  printf("==================\n");

  for (int i = 0; i < M; i++)
    printf("HT[%02d] :  %2d     %d\n", i, HT->B[i].key, HT->B[i].probeCount);
}

int main() {
  HashTable HT;
  init(&HT);

  int data[10] = {25, 13, 16, 15, 7, 28, 31, 20, 1, 38};

  printf("h(key)      0  1  2  3  4  5  6  7  8  9 10 11 12\n");
  printf("=========  ======================================\n");

  for (int i = 0; i < 10; i++) {
    printf("h(%02d): %2d ", data[i], hash(data[i]));
    insertItem(&HT, data[i]);
    print(&HT);
  }

  printHash(&HT);

  int key = 0;
  for (int i = 0; i < 3; i++) {
    // search
    printf("\nEnter key to be searched: ");
    scanf("%d", &key);
    searchItem(&HT, key);

    // delete
    printf("\nEnter key to be deleted: ");
    scanf("%d", &key);
    deleteItem(&HT, key);
    printHash(&HT);
  }

  return 0;
}