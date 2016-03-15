/* Exercise 1-13. Write a program to print a histogram of the lengths of words in
 * its input. It is easy to draw the histogram with the bars horizontal; a vertical
 * orientation is more challenging. */
#include <stdio.h>

#define MAX_WORD_LENGTH	((int)16)
#define IN 		((int)1)
#define OUT 		((int)0)

main()
{
	int word_length[MAX_WORD_LENGTH];
	int i;
	int c;
	int wl = 0;
	int state = OUT;

	for (i = 0; i < MAX_WORD_LENGTH; ++i)
		word_length[i] = 0;

	while (EOF != (c = getchar())) {
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
			(c >= '0' && c <= '9') || ('\'' == c)) {

			state = IN;
			++wl;
		}
		else {
			if (IN == state) { 
				state = OUT;
				++word_length[wl];
				wl = 0;
			}
		}
	}

	for (i = 0; i < MAX_WORD_LENGTH; ++i)
		printf("%d, %d\n", i, word_length[i]);
}
