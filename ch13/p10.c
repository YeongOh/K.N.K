#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define N 20

int read_line(char str[], int n);
void reverse_name(char *name);

int main(void) {
	char c;
	char name[N];

	printf("Enter a first and last name: ");
	read_line(name, N);
	reverse_name(name);

	printf("%s\n", name);
	return 0;
}

void reverse_name(char *name) {
	char last_name[N];
	char *p = name;
	char initial = *name;

	for (; !isspace(*p); p++);
	
	int i = 0;
	while (*p) {
		if (isspace(*p)) {
			p++;
			continue;
		}
		last_name[i++] = *p++;
	}

	last_name[i] = ',';
	last_name[i + 1] = ' ';
	last_name[i + 2] = initial;
	last_name[i + 3] = '.';
	last_name[i + 4] = 0;
	strcpy(name, last_name);
}

int read_line(char str[], int n) {
	int i = 0;
	int ch;

	while ((ch = getchar()) != '\n') {
		if (i == 0 && isspace(ch)) {
			continue;
		}
		if (i < n) {
			str[i++] = ch;
		}
	}
	str[i] = 0;

	return i;
}
