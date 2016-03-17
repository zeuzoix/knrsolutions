/* Exercise 1-14. Write a program to print a histogram of the frequencies of
 * different characters in its input. */
#include <stdio.h>

#define MAX_CHARACTERS	((int)26)
#define MAX_DIGITS 	((int)9)

main()
{
	int c;
	int i;
	int j;
	int upper[MAX_CHARACTERS];
	int lower[MAX_CHARACTERS];
	int digit[MAX_DIGITS];

	for (i = 0; i < MAX_CHARACTERS; ++i) {
		upper[i] = 0;
		lower[i] = 0;
	}

	for (i = 0; i < MAX_DIGITS; ++i) {
		digit[i] = 0;
	}

	while (EOF != (c = getchar())) {
		if (c >= 'A' && c <= 'Z')
			upper[c - 'A']++;

		if (c >= 'a' && c <= 'z')
			lower[c - 'a']++;

		if (c >= '0' && c <= '9')
			digit[c - '0']++;
	}

	for (i = 0; i < MAX_CHARACTERS; ++i) {
		printf("%c ", ('A' + i));
		for (j = 0; j < upper[i]; ++j)
			printf("*");
		printf("\n");
	}

	for (i = 0; i < MAX_CHARACTERS; ++i) {
		printf("%c ", ('a' + i));
		for (j = 0; j < lower[i]; ++j)
			printf("*");
		printf("\n");
	}

	for (i = 0; i < MAX_DIGITS; ++i) {
		printf("%c ", ('0' + i));
		for (j = 0; j < digit[i]; ++j)
			printf("*");
		printf("\n");
	}
}
