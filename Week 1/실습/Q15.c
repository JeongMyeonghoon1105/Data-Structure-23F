#include <stdio.h>

typedef struct bank {
  int num;
  char name[50];
  int balance;
} Bank;

void deposit(Bank * a, int amount) {
  a -> balance = amount;
}

int main() {
  Bank user1;
  int amount;
  scanf("%d", &amount);
  deposit(&user1, amount);
  printf("잔액 : %d원\n", user1.balance);
  return 0;
}