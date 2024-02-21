#include <assert.h>
#include <complex.h>
#include <ctype.h>
#include <math.h>
#include <stdalign.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

enum Animal { DOG, CAT, FISH };

struct animal {
  char *name;
  int leg_count;
  enum Animal type;
};

union dt {
  float distance;
  int time;
};

struct s {
  int a, b;
};

int sum(struct s *x) { return x->a + x->b; }

float divide(int a, int b) {
  assert(b != 0);
  return (float)a / b;
}

int add(int count, ...) {
  int total = 0;
  va_list args;
  va_start(args, count);
  for (int i = 0; i < count; i++) {
    printf("i is %d\n", i);
    int n = va_arg(args, int);
    printf("n is %d\n", n);
    total += n;
  }
  va_end(args);
  return total;
}

int main() {
  struct animal a2 = {"spider", 8};
  struct animal *cp = &a2;
  printf("%s\n", cp->name);

  union dt a;
  union dt b;
  union dt c = {.distance = 3.5};
  union dt d = {.time = 3};

  union dt *p = &b;
  p->distance = 3.5;
  printf("%f\n", p->distance);
  printf("%f\n", b.distance);
  b.distance = 4.5;
  printf("%f\n", p->distance);
  printf("%f\n", b.distance);

  enum Animal cat = FISH;
  cp->type = cat;
  printf("%d\n", cp->type);

  char *greeting = "Hello world";
  printf("%s\n", greeting);

  struct s x = {3, 4};
  printf("%d\n", sum(&x));
  printf("Sum from %d\n", add(3, 1, 2, 3));

  float dives = divide(2, 3);
  printf("%f\n", dives);

  double complex complexx = 8 + 1.5708 * I;
  printf("complex %f\n", creal(complexx));

  printf("isalnum %d\n", isalnum('a') ? 1 : 0);
  printf("isalnum %d\n", isalnum('B') ? 1 : 0);
  printf("isalnum %d\n", ispunct('?') ? 1 : 0);
  return 0;
}
