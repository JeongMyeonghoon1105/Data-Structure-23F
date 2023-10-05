#include "스택.c"

void sortedPush(StackType *S, element e) {
  int temp;
  if (isStackEmpty(S) || e > S->stack[S->top])
    push(S, e);
  else {
    temp = pop(S);
    sortedPush(S, e);
    push(S, temp);
  }
}

int main() {
  StackType S;
  initStack(&S);
  element data[6] = {5, 3, 8, 1, 2, 7};

  for (int i = 0; i < 7; i++) {
    sortedPush(&S, data[i]);
    printStack(&S);
  }
  
  return 0;
}
