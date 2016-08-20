/* Exercise 1-16. Revise the main routine of the longest-line program so it will
 * correctly print the length of arbitrarily long input lines, and as much as possible
 * of the text. */
#include <stdio.h>
#define MAXLINE 1000	/* maximum input line size */

int getline_x(char line[], int maxline);
void copy(char to[], char from[]);

main ()
{
	int len;	/* current line length */
	int max;	/* maximum length seen so far */
	char line[MAXLINE];	/* current input line */
	char longest[MAXLINE];	/* longest line saved here */

	max = 0;
	while ((len = getline_x(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
			printf("length = %d, line : %s", max, longest);
		}

	return 0;
}

int getline_x(char line[], int maxline)
{
	int c, i;

	for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;

	if (c == '\n') {
		line[i] = c;
		++i;
	}

	line[i] = '\0';
	return i;
}



void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
