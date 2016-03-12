/* Exercise 1-12. Write a program that prints its input one word per line */

#include <stdio.h>
#define IN	0
#define OUT	1

main()
{
	int c;
	int state = OUT;

	while (EOF != (c = getchar())) {
		if (' ' == c || '\n' == c || '\t' == c)
			if (IN == state) {
				state = OUT;
				putchar('\n');
			}
			else {
				continue;
			}
		else {
			state = IN;
			putchar(c);
		}
	}
}
