#include <stdio.h>
#include <stdlib.h>

void swap(int a, int b) {
  int t = a;
  a = b;
  b = t;
  printf("first");
  printf("a = %d\n", a);
  printf("b = %d\n", b);
}

void pointer_swap(int *pa, int *pb) {
  int a = *pa;
  *pa = *pb;
  *pb = a;

  printf("a = %d\n", *pa);
  printf("b = %d\n", *pb);
  return;
}

int main(void) {
  int a = 21;
  int b = 14;
  pointer_swap(&a, &b);

  printf("second");
  printf("a = %d\n", a);
  printf("b = %d\n", b);
  return EXIT_SUCCESS;
}
