/* Exercise 1.8. Write a program to count blanks, tabs, and newlines */

#include <stdio.h>

int main()
{
	long int blanks, tabs, newlines;
	int c;

	blanks = tabs = newlines = 0;

	while (EOF != (c = getchar())) {
		switch (c) {
			case ' ':
				++blanks;
				break;
			case '\t':
				++tabs;
				break;
			case '\n':
				++newlines;
				break;
			default:
				break;
		}
	}

	printf("blanks = %ld, tabs = %ld, newlines = %ld", blanks, tabs, newlines);

	return 0;
}
