/* Exercise 1-17. Write a program to print all input lines that are longer than 80
 * characters. */
#include <stdio.h>
#define MAXLINE 1000	/* maximum input line size */

int getline_x(char line[], int maxline);
void printline(char line[]);

main ()
{
	int len;	/* current line length */
	char line[MAXLINE];	/* current input line */

	while ((len = getline_x(line, MAXLINE)) > 0) {
		if (len > 80)
			printline(line);
	}
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

void printline(char line[])
{
	int i = 0;

	while (line[i]) {
		putchar(line[i++]);
	}
}
