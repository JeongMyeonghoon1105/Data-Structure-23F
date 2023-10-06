#include <stdio.h>

int maximum(int n, int max) {
  if (n <= 0)
    return max;
  int input;
  scanf("%d", &input);
  if (input > max)
    return maximum(n-1, input);
  else
    return maximum(n-1, max);
}

int main(void) {
  int N = 0;
  scanf("%d", &N);
  printf("%d", maximum(N, 0));
  return 0;
}
