#include <stdio.h>
#include <stdlib.h>

// 해시 테이블의 크기는 주로 소수
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

// Hash Function
int h2(int key) {
  return 11 - (key % 11);
}

int isEmpty(HashTable *HT, int b) {
  return HT->B[b].key == 0;
}

// 선형 조사
int getNextBucketLinear(int v, int inc) {
  return (v + inc) % M;
}

// 이차 조사
int getNextBucketQuadratic(int v, int inc) {
  return (v + inc * inc) % M;
}

// 이중 해싱
int getNextBucketDouble(int v, int inc, int key) {
  return (v + inc * h2(key)) % M;
}

void insertItem(HashTable *HT, int key) {
  int v = h(key);
  int inc = 0;
  int count = 0;

  // 한바퀴 돌 동안 빈 버킷을 찾지 못하고 제자리로 돌아오면 반복 탈출
  while (inc < M) {
    count++;
    int b = getNextBucketLinear(v, inc);
    // int b = getNextBucketQuadratic(v, inc);
    // int b = getNextBucketDouble(v, inc, key);
    
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
    int b = getNextBucketLinear(v, inc);

    if (HT->B[b].key == key) {
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
    int b = getNextBucketLinear(v, inc);
    
    if (isEmpty(HT, b))
      return 0;
    else if (HT->B[b].key == key)
      return key;
    else
      inc++;
  }
}

// 해시 테이블 출력
void print(HashTable *HT) {
  for (int i = 0; i < M; i++)
    printf(" %2d", HT->B[i].key);
  printf("\n");
}

// 각 버킷에 저장된 키 값과, 버킷 결정에 소요된 빈 버킷 탐색 횟수를 표로 출력
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
    // 키와 그 해시 주소값 출력
    printf("h(%02d): %2d ", data[i], h(data[i]));
    insertItem(&HT, data[i]);
    print(&HT);
  }

  printHash(&HT);

  int key;

  for (int i = 0; i < 3; i++) {
    // Search
    printf("Input Search Key: ");
    scanf("%d", &key);
    if (searchItem(&HT, key))
      printf("Found Key: %d\n", key);
    else
      printf("Key Not Found\n");
    
    // Delete
    printf("Input Delete Key: ");
    scanf("%d", &key);

    deleteItem(&HT, key);
    printHash(&HT);
  }
  
  return 0;
}
