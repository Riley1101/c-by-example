#include <stdalign.h>
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
  return 0;
}
