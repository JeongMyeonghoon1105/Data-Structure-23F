#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 15

void print(int *A) {
  for (int i = 0; i < N; i++)
    printf("%d ", A[i]);
  printf("\n");
}

void selectionSort(int *A) {
  printf("Before Sort : ");
  print(A);

  printf("\n<<<<<<<<<< Selection Sorting... >>>>>>>>>>\n");
  for (int i = 0; i < N; i++) {
    int min = i;
    for (int j = i + 1; j < N; j++)
      if (A[j] < A[min])
        min = j;
    if (min != i) {
      int temp = A[i];
      A[i] = A[min];
      A[min] = temp;
    }
    printf("Step %d : ", i+1);
    print(A);
  }
}

void insertionSort(int *A) {
  printf("Before Sort : ");
  print(A);

  printf("\n<<<<<<<<<< Insertion Sorting... >>>>>>>>>>\n");
  for (int i = 1; i < N; i++) {
    int key = A[i];
    int j = i-1;
    while (j >= 0 && A[j] > key) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
    printf("Step %d : ", i);
    print(A);
  }
}

int count;

int iBinarySearch(int *A, int key) {
  int low = 0, high = N-1, mid;

  while (low <= high) {
    count++;
    mid = (low + high) / 2;
    if (key == A[mid])
      return mid;
    else if (key < A[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }
  
  return -1;
}

int rBinarySearch(int *A, int key, int low, int high) {
  int mid;

  if (low <= high) {
    count++;
    mid = (low + high) / 2;
    
    if (key == A[mid])
      return mid;
    else if (key < A[mid])
      return rBinarySearch(A, key, low, mid - 1);
    else
      return rBinarySearch(A, key, mid + 1, high);
  }

  return -1;
}

int main() {
  int A[N];
  srand(time(NULL));

  for (int i = 0; i < N; i++)
    A[i] = rand() % 100;

  insertionSort(A);

  int key, idx = -1;
  printf("\nSearch Key : ");
  scanf("%d", &key);

  // idx = iBinarySearch(A, key);
  idx = rBinarySearch(A, key, 0, N-1);
  if (idx == -1)
    printf("Data Not Found\n");
  else
    printf("%d Times : %d in A[%d]\n", count, key, idx);
  
  return 0;
}
