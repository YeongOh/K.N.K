#include <stdio.h>
#include <stdbool.h>

#define COUNTRY_COUNT \
	((int) (sizeof(country_codes) / sizeof(country_codes[0])))

struct dialing_code {
	char *country;
	int code;
};

const struct dialing_code country_codes[] =
{{"United States", 1}, {"Aregentina", 12}};

int main(void) {
	int code;
	printf("Enter an international dialing code: ");
	scanf("%d", &code);

	bool found = false;
	for (int i = 0; i < COUNTRY_COUNT; i++) {
		if (code == country_codes[i].code) {
			printf("%s\n", country_codes[i].country);
			found = true;
		}
	}
	if (!found) {
		printf("Error, not found\n");
	}
	return 0;
}
