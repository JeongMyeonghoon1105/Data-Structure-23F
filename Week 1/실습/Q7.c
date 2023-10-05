#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  int max = 1;
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 100 + 1;
    if (arr[i] > max)
      max = arr[i];
  }
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n%d\n", max);
}