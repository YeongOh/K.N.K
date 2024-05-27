#include <stdbool.h>   /* C99 only */
#include <stdio.h>

int main(void)
{
  int counter[10] = {0};
  int digit;
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);

  while (n > 0) {
    digit = n % 10;
    counter[digit]++;
    n /= 10;
  }

  printf("Digit:      0 1 2 3 4 5 6 7 8 9\n");
  printf("Occurences: ");
  for (int i = 0; i < 10; i++) {
	 printf("%d ", counter[i]); 
  }
  printf("\n");

  return 0;
}
