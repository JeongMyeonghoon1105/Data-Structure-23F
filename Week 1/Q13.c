#include <stdio.h>

typedef struct bank {
  int num;
  char name[50];
  int balance;
} Bank;

int main() {
  Bank user1;
  scanf("%d %s %d", &user1.num, user1.name, &user1.balance);
  printf("%s의 %d계좌의 잔액은 %d원\n", user1.name, user1.num, user1.balance);
  return 0;
}