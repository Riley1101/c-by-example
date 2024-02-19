#include <stdio.h>

void countChar() {
  int c = getchar();
  if (c == EOF) {
    printf("Value of EOF :  %d\n", c);
  }
  while (c != EOF) {
    printf("Text being typed: %d\n", c);
    putchar(c);
    c = getchar();
  }
}

void fillArray() {
  int c, i, nwhite, nother;
  int ndigit[10];
  nwhite = nother = 0;
  for (i = 0; i < 10; ++i) {
    ndigit[i] = 0;
  }
  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9') {
      ++ndigit[c - '0'];
    } else if (c == ' ' || c == '\n' || c == '\t') {
      ++nwhite;
    } else {
      ++nother;
    }
  }
  for (i = 0; i < 10; ++i) {
    printf("digits = ");
    printf("%d\n", ndigit[i]);
    printf(",white spaces %d\n, other %d\n", nwhite, nother);
  };
}

int main() { fillArray(); }
