#include <stdio.h>
#include <string.h>

int count(char * str, char ch, int i) {
  if (i == strlen(str))
    return 0;
  int num = 0;
  if (str[i] == ch)
    num = 1;
  return num += count(str, ch, i+1);
}

int main(void) {
  char str[100];
  char ch;
  scanf("%s %c", str, &ch);
  printf("%d", count(str, ch, 0));
  return 0;
}
