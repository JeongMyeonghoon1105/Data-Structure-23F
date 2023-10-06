#include <stdio.h>

void forward(int n) {
  if (n / 10 == 0)
    printf("%d\n", n);
  else {
    forward(n / 10);
    printf("%d\n", n % 10);
  }
}

int main(void) {
  int N = 0;
  scanf("%d", &N);
  forward(N);
  return 0;
}
