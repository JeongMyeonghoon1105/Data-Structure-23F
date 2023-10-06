#include <stdio.h>

void hanoi(char fr, char by, char to, int n) {
  if (n < 1)
    return;
  hanoi(fr, to, by, n-1);
  printf("%c %c\n", fr, to);
  hanoi(by, fr, to, n-1);
}

int main(void) {
  int N = 0;
  scanf("%d", &N);
  hanoi('A', 'B', 'C', N);
  return 0;
}
