#include <stdio.h>
#define MAXLINE 10
#define EXIT_SUCCESS 0

int atoi(char s[]);

int main() {
  char s[MAXLINE];
  int i;
  int c;
  i = 0;
  while (i < MAXLINE - 1) {
    c = getchar();
    if (c == EOF) {
      break;
    }
    s[i] = c;
    ++i;
  }
  int result = atoi(s);
  printf("From a of  to i of %d\n", result);
  printf("%d\n", result);
  return EXIT_SUCCESS;
}

int atoi(char s[]) {
  int i, n;
  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
    printf("%d -----  %d \n", n, s[i]);
    n = 10 * n + (s[i] - '0');
  }
  return n;
}
