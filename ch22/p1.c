#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp;

  if (argc < 2) {
    printf("usage: canopen filename\n");
    exit(EXIT_FAILURE);
  }

  for (argv++; *argv != NULL; argv++) {
	  if ((fp = fopen(*argv, "r")) == NULL) {
		  printf("%s can't be opened\n", *argv);
		  exit(EXIT_FAILURE);
	  }

	  printf("%s can be opened\n", *argv);
	  fclose(fp);
  }

  return 0;
}
