#include <bits/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define LEN 120
#define FILEPATH "temp.txt"

double elapsed_ms(struct timespec a, struct timespec b) {
  return (b.tv_sec - a.tv_sec) * 1000.0 + (b.tv_nsec - a.tv_nsec) / 1e6;
}

int main(void) {
  int n;
  scanf("%d", &n);
  if (n <= 0 || (LEN % n) != 0) {
    printf("n must divide %d\n", LEN);
    return 1;
  }

  struct timespec t0, t1;
  clock_gettime(CLOCK_MONOTONIC, &t0);

  int u[LEN], v[LEN];
  srand(time(NULL));
  for (int i = 0; i < LEN; ++i) {
    u[i] = rand() % 100;
    v[i] = rand() % 100;
  }

  FILE *f = fopen(FILEPATH, "w");
  fclose(f);

  int chunk = LEN / n;

  for (int id = 0; id < n; id++) {
    pid_t pid = fork();
    if (pid == 0) {
      int start = id * chunk;
      int end = start + chunk;

      long long part = 0;
      for (int i = start; i < end; ++i) {
        part += (long long)u[i] * (long long)v[i];
      }

      FILE *ff = fopen(FILEPATH, "a");
      if (ff) {
        fprintf(ff, "%lld\n", part);
        fclose(ff);
      }
      _exit(0);
    }
  }

  for (int i = 0; i < n; ++i) {
    wait(NULL);
  }

  long long total = 0, x = 0;
  f = fopen(FILEPATH, "r");
  if (!f) {
    return 1;
  }
  while (fscanf(f, "%lld", &x) == 1) {
    total += x;
  }

  fclose(f);
  clock_gettime(CLOCK_MONOTONIC, &t1);
  printf("dot=%lld   time_ms=%.3f   (LEN=%d, n=%d)\n", total,
         elapsed_ms(t0, t1), LEN, n);
  return 0;
}
