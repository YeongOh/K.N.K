#include <stdio.h>
#include <ctype.h>

int main(void) {
	char message[50] = {0};
	char c;
	int i = 0;
	
	printf("Enter message: ");
	while ((c = getchar()) != '\n') {
		message[i] = c;
		i++;
	}

	printf("In B1FF-Speak: ");
	for (int j = 0; j < i; j++) {
		char c = toupper(message[j]);
		switch (c) {
			case 'A': putchar('4'); break;
			case 'B': putchar('8'); break;
			case 'E': putchar('3'); break;
			case 'I': putchar('1'); break;
			case 'O': putchar('0'); break;
			case 'S': putchar('5'); break;
			default: putchar(c); break;
		}
	}
	printf("!!!!!!!!!!\n");

	return 0;
}
