#include <stdio.h>

int sum(int n) {
  if (n == 1)
    return 1;
  return n + sum(n-1);
}

int main(void) {
  int N = 0;
  scanf("%d", &N);
  printf("%d", sum(N));
  return 0;
}
