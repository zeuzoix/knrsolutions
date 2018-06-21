/* Excercise 1-20. Write a program detab that replaces tabs in the input with the
proper number of blanks to space to the next tab stop. Assume a fixed set of
tab stops, say every n columns. Should n be a variable or a symbolic parame-
ter? */

#include <stdio.h>

#define MAXLINE 1024
#define TABSTOP 4

int getline_x(char line[], int maxline);
int detab(char line[]);
int calculate_next_tabstop(int i, int n);
void printline(char line[]);

main()
{
	char buffer[MAXLINE];

	while (getline_x(buffer, MAXLINE)) {
		detab(buffer);

	}
}

int getline_x(char line[], int maxline)
{
	int c;
	int i;

	for (i = 0; (c = getchar()) != EOF && c != '\n' && i < maxline - 1; ++i)
		line[i] = c;

	if ('\n' == c)
		line[i++] = c;

	line[i] = '\0';

	return i;
}

int detab(char line[])
{
	int i = 0;
	int j = 0;
	int k = 0;

	for (j = 0, i = 0; line[i]; ++i)
		if (line[i] == '\t') {
			k = TABSTOP - (j % TABSTOP);
			j += k;
			while (k--)
				putchar(' ');
		}
		else {
			putchar(line[i]);
			j++;
		}

	return 0;
}
