#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60
#define n 20

struct word {
	char s[n + 1];
	struct word *next;
};

struct word *line = NULL;

int line_len = 0;
int num_words = 0;

void clear_line(void)
{
	struct word *cur;
	cur = line;
	while (cur != NULL) {
		struct word *temp = cur->next;
		free(cur);
		cur = temp;
	}
	line = NULL;

	line_len = 0;
	num_words = 0;
}

void add_word(const char *word)
{
	struct word *new_word = malloc(sizeof(struct word));
	if (new_word == NULL) {
		printf("Not enough memory\n");
		exit(EXIT_FAILURE);
	}

	strncpy(new_word->s, word, n);
	new_word->next = NULL;

	if (line == NULL) {
		line = new_word;
	} else {
		struct word *p = line;
		while (p->next) {
			p = p->next;
		}
		p->next = new_word;
	}
	line_len += strlen(word);
	num_words++;
}

int space_remaining(void)
{
	return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
	int extra_spaces, spaces_to_insert, i, j;
	struct word *p = line;

	extra_spaces = MAX_LINE_LEN - line_len;
	while (p != NULL) {
		printf("%s", p->s);
		p = p->next;
		
		if (num_words > 1) {
			spaces_to_insert = extra_spaces / (num_words - 1);
			for (j = 1; j <= spaces_to_insert + 1; j++) {
				putchar(' ');
			}
		}
		extra_spaces -= spaces_to_insert;
		num_words--;
	}

	putchar('\n');
}

void flush_line(void)
{
	while (line != NULL) {
		printf("%s", line->s);
		struct word *temp = line->next;
		free(line);
		line = temp;
		putchar(' ');
	}
	printf("\n");
}
