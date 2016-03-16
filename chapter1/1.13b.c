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
	int j;
	int c;
	int wl = 0;
	int max_freq = 0;
	int state = OUT;

	for (i = 0; i < MAX_WORD_LENGTH; ++i)
		word_length[i] = 0;

	/* Find the frequencies of word lengths */
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
				if (word_length[wl] > max_freq) 
					max_freq = word_length[wl];

				wl = 0;
			}
		}
	}

	/* Plot the frequencies of word lengths */
	for (i = 0; i < max_freq; ++i) {
		for (j = 0; j < MAX_WORD_LENGTH; ++j) 
			if ((max_freq - i) > word_length[j])
				printf("  ");
			else
				printf("* ");
		printf("\n");

	}

	for (j = 0; j < MAX_WORD_LENGTH; ++j) 
		printf("%d ", j);
	printf("\n");
}
