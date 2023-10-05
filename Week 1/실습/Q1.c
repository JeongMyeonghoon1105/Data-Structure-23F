#include <stdio.h>

int main() {
  int k = 0, n = 0, m = 0;
  scanf("%d %d %d", &k, &n, &m);
  if (m >= k * n) {
    printf("%d\n", 0);
  } else {
    printf("%d\n", k * n - m);
  }
  return 0;
}
