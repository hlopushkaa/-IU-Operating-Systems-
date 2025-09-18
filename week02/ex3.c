

#include <ctype.h>
#include <stdio.h>
#include <string.h>
int isValid(char *num, int base) {
  for (int i = 0; num[i] != '\0'; i++) {
    int digit;
    if (isdigit(num[i])) {
      digit = num[i];
      printf("%d\n", digit);
    } else {
      return 0;
    }
    printf("%d: ", digit);

    if (digit >= base) {
      return 0;
    }
  }
  return 1;
}

void convert(char *x, int s, int t) {
  if (s < 2 || s > 10 || t < 2 || t > 10) {
    printf("cannot convert!\n");
    return;
  }

  long decimal = 0;
  int len = strlen(x);

  for (int i = 0; i < len; i++) {
    int digit = x[i] - '0';
    decimal = decimal * s + digit;
  }

  if (t == 10) {
    printf("%ld\n", decimal);
  }

  char result[100];
  int index = 0;
  long temp = decimal;

  if (temp == 0) {
    printf("0\n");
    return;
  }

  while (temp > 0) {
    int reminder = temp % t;
    result[index++] = reminder + '0';
    temp = temp / t;
  }

  for (int i = index - 1; i >= 0; i--) {
    printf("%c", result[i]);
  }
}

int main() {
  char number[100];
  int initial_base, target_base;
  printf("number: ");
  scanf("%s", number);
  printf("initial base: ");
  scanf("%d", &initial_base);
  printf("target base: ");
  scanf("%d", &target_base);

  printf("answer: ");
  convert(number, initial_base, target_base);
  return 0;
}
