
#include <stdio.h>

#define MAXX 256

int main() {
  char input[MAXX];
  char reversed[MAXX];
  int i = 0;
  char c;

  while (i < MAXX) {
    c = getchar();

    if (c == '.') {
      break;
    }

    input[i] = c;
    i++;
  }

  input[i] = '\0';
  int l = i;

  for (int j = 0; j < l; j++) {
    reversed[j] = input[l - 1 - j];
  }

  reversed[l] = '\0';

  printf("%s\n", reversed);
  return 0;
}
