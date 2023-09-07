#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int dice[7] = {0};
  for (int i = 0; i < 10000; i++)
    dice[rand() % 6 + 1]++;
  for (int i = 1; i < 7; i++)
    printf("%d번 눈 : %d회\n", i, dice[i]);
  return 0;
}