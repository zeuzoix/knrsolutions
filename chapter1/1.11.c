/* Exercise 1-11. How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?*/
/* Check with one line string */
/* Check with two line string */
/* Check with one line string of greater than 2^32 characters */
/* Check with greater than 2^32 words*/
/* Check with greater than 2^32 strings*/
/* Check with empty file*/
/* Check with file with no EOF*/


#include <stdio.h>

#define IN	1
#define OUT	0

/* count lines, words and characters in input */
main()
{
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	while (EOF != (c =getchar())) {
		++nc;
		if ('\n' == c)
			++nl;
		if (' ' == c || '\n' == c || '\t' == c)
			state = OUT;
		else if (OUT == state) {
			state = IN;
			++nw;
		}
	}

	printf("nl = %d nw = %d nc = %d\n", nl, nw, nc);
}
