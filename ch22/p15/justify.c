#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(int argc, char *argv[])
{
	FILE *input_fp, *output_fp;
	char word[MAX_WORD_LEN+2];
	int word_len;

	if (argc != 3) {
		fprintf(stderr, "usage: justify inputfile outputfile\n");
		exit(EXIT_FAILURE);
	}

	if ((input_fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((output_fp = fopen(argv[2], "w")) == NULL) {
		fprintf(stderr, "can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	clear_line();
	for (;;) {
		read_word(word, MAX_WORD_LEN+1, input_fp);
		word_len = strlen(word);
		if (word_len == 0) {
			flush_line(output_fp);
			return 0;
		}
		if (word_len > MAX_WORD_LEN)
			word[MAX_WORD_LEN] = '*';
		if (word_len + 1 > space_remaining()) {
			write_line(output_fp);
			clear_line();
		}
		add_word(word);
	}
}
