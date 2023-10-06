#include <stdio.h>

typedef struct {
  char name[10];
  int score[5];
} node;

void sort(node *n) {
  int temp;
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 4; j++)
      if (n->score[j] < n->score[j+1]) {
        temp = n->score[j];
        n->score[j] = n->score[j+1];
        n->score[j+1] = temp;
      }
}

int main() {
  node n1;
  scanf("%s", n1.name);

  for (int i = 0; i < 5; i++)
    scanf("%d", &n1.score[i]);
  sort(&n1);

  printf("\nName : %s\n", n1.name);
  printf("Sort Result : ");
  for (int i = 0; i < 5; i++)
    printf("%d ", n1.score[i]);
  printf("\n");

  return 0;
}