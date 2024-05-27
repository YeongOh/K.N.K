#include <stdio.h>

int main(void)
{
  int n;
  long i;

  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in table: ");
  scanf("%d", &n);

  // int - 32 bit
  // short - 16 bit
  // long - 64 bit
  for (i = 1; i <= n; i++)
    printf("%20ld%20ld\n", i, i * i);

  return 0;
}
