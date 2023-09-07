#include <stdio.h>

int main() {
  int arr[3][4] = {
    {0, 1, 2, 3},
    {10, 11, 12, 13},
    {20, 21, 22, 23}
  };
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%d\t", arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}