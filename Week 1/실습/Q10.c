#include <stdio.h>

int main() {
  int arr[3][4];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
  int sum;
  for (int i = 0; i < 3; i++) {
    sum = 0;
    for (int j = 0; j < 4; j++) {
      sum += arr[i][j];
    }
    printf("%d행의 합 : %d\n", i + 1, sum);
  }
  for (int j = 0; j < 4; j++) {
    sum = 0;
    for (int i = 0; i < 3; i++) {
      sum += arr[i][j];
    }
    printf("%d열의 합 : %d\n", j + 1, sum);
  }
  return 0;
}