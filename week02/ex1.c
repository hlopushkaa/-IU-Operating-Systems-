#include <float.h>
#include <limits.h>
#include <stdio.h>

int main() {
  int a = INT_MAX;
  unsigned short b = USHRT_MAX;
  signed long c = LONG_MAX;
  float d = FLT_MAX;
  double e = DBL_MAX;
  printf("%lu bytes %d\n", sizeof(a), a);
  printf("%lu bytes %hu\n", sizeof(b), b);
  printf("%lu bytes %ld\n", sizeof(c), c);
  printf("%lu bytes %e\n", sizeof(d), d);
  printf("%lu bytes %e\n", sizeof(e), e);
}
