#include <stdio.h>

void backward(int n) {
  if (n / 10 == 0)
    printf("%d", n);
  else {
    printf("%d\n", n % 10);
    backward(n / 10);
  }
}

int main(void) {
  int N = 0;
  scanf("%d", &N);
  backward(N);
  return 0;
}
