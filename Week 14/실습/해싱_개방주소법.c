#include <stdio.h>
#include <stdlib.h>

#define M 13

// Bucket
typedef struct {
  int key;
  int probeCount; 
} Bucket;

// Hash Table
typedef struct {
  Bucket B[M];
} HashTable;

void init(HashTable *HT) {
  for (int i = 0; i < M; i++) {
    HT->B[i].key = 0;
    HT->B[i].probeCount = 0;
  }
}

// Hash Function
int h(int key) {
  return key % M;
}

int h2(int key) {
  return 11 - (key % 11);
}

int isEmpty(HashTable *HT, int b) {
  return HT->B[b].key == 0;
}

// 선형 조사
int getNextBacketLinear(int v, int inc) {
  return (v + inc) % M;
}

// 이차 조사
int getNextBacketQuadratic(int v, int inc) {
  return (v + inc * inc) % M;
}

// 이중 해싱
int getNextBacketDouble(int v, int inc, int key) {
  return (v + inc * h2(key)) % M;
}

void insertItem(HashTable *HT, int key) {
  int v = h(key);
  int inc = 0;
  int count = 0;

  while (inc < M) {
    count++;
    int b = getNextBacketLinear(v, inc);
    // int b = getNextBacketQuadratic(v, inc);
    // int b = getNextBacketDouble(v, inc, key);
    
    if (isEmpty(HT, b)) {
      HT->B[b].key = key;
      HT->B[b].probeCount = count;
      return;
    } else
      inc++;
  }
}

void deleteItem(HashTable *HT, int key) {
  // 원래 빈 방인지, 삭제에 의해 빈 방인지 구분
  int v = h(key);
  int inc = 0;
  int count = 0;

  while (inc < M) {
    count++;
    int b = getNextBacketLinear(v, inc);

    if (isEmpty(HT, b)) {
      HT->B[b].key = -1;
      HT->B[b].probeCount = 0;
      return;
    } else
      inc++;
  }
}

int searchItem(HashTable *HT, int key) {
  int v = h(key);
  int inc = 0;

  while (inc < M) {
    int b = getNextBacketLinear(v, inc);
    
    if (isEmpty(HT, b))
      return 0;
    else if (HT->B[b].key == key)
      return key;
    else
      inc++;
  }
}

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
  printf("\n");
}

int main(void) {
  HashTable HT;
  init(&HT);

  int data[] = {25, 13, 16, 15, 7, 28, 31, 20, 1, 38};

  printf("h(key)      0  1  2  3  4  5  6  7  8  9 10 11 12\n");
  printf("=========  ======================================\n");

  for (int i = 0; i < 10; i++) {
    printf("h(%02d): %2d ", data[i], h(data[i]));
    insertItem(&HT, data[i]);
    print(&HT);
  }

  printHash(&HT);

  int key;
  printf("Input Search Key: ");
  scanf("%d", &key);

  if (searchItem(&HT, key)) {
    printf("Found Key: %d\n", key);
  } else {
    printf("Key Not Found\n");
  }

  printf("Input Delete Key: ");
  scanf("%d", &key);

  deleteItem(&HT, key);
  printHash(&HT);

  printf("Input Search Key: ");
  scanf("%d", &key);

  if (searchItem(&HT, key)) {
    printf("Found Key: %d\n", key);
  } else {
    printf("Key Not Found\n");
  }

  printf("Input Delete Key: ");
  scanf("%d", &key);

  deleteItem(&HT, key);
  printHash(&HT);

  printf("Input Search Key: ");
  scanf("%d", &key);

  if (searchItem(&HT, key)) {
    printf("Found Key: %d\n", key);
  } else {
    printf("Key Not Found\n");
  }
  
  return 0;
}
