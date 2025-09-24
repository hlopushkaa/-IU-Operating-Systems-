#include <math.h>
#include <stdio.h>

typedef struct {
  double x;
  double y;
} Point;

double distance(Point a, Point b) {
  double dx = b.x - a.x;
  double dy = b.y - a.y;
  return sqrt(dx * dx + dy * dy);
}

double area(Point A, Point B, Point C) {
  double s =
      A.x * B.y - B.x * A.y + B.x * C.y - C.x * B.y + C.x * A.y - A.x * C.y;
  return 0.5 * fabs(s);
}

int main() {
  Point A = {2.5, 6.0};
  Point B = {1.0, 2.2};
  Point C = {10.0, 6.0};

  double dist = distance(A, B);
  double S = area(A, B, C);

  printf("A = (%.6f, %.6f)\n", A.x, A.y);
  printf("B = (%.6f, %.6f)\n", B.x, B.y);
  printf("C = (%.6f, %.6f)\n", C.x, C.y);

  printf("Distance: %.6f\n", dist);
  printf("Area: %.6f", S);
}
