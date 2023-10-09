#include "스택(연결리스트).c"
#include <stdlib.h>
#include <time.h>

int main() {
  StackType s;
  initStack(&s);
  srand(time(NULL));
  int num;

  for (int i = 0; i < 5; i++) {
    num = rand() % 10;
    s.top = push(&s, num);
  }
  printStack(&s);

  return 0;
}