/* Exercise 1-22. Write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blank character that occurs before the
 * n-th column of input. Make sure your program does something intelligent
 * with very long lines, and if there are no blanks or tabs before the
 * specified column. */

#include <stdio.h>
#define MAXLINE 1024
#define MAXCOL 10
#define TABSTOP 4

int fold(char text[], int strlen, int cols);
int gettext_x(char text[], int maxlen);
void printtext(char text[]);

main()
{
	char buffer[MAXLINE];
	int cols = 0;
	int i;
	int n;
	int strlen;
	char last = 0;

	while(n = gettext_x(buffer, MAXLINE)) {
		last = buffer[n - 1];
		if (' ' == last || '\n' == last || '\t' == last) {
			buffer[n - 1] = '\0';
			strlen = n - 1;
		}
		else {
			last = 0;
		}

		if (strlen) {
			cols = fold(buffer, strlen, cols);
			//printf("text strlen:%d cols:%d\n", strlen, cols);
		}

		if (last) {
			buffer[0] = last;
			buffer[1] = 0;
			strlen = 1;
			cols = fold(buffer, strlen, cols);
			//printf("last strlen:%d cols:%d\n", strlen, cols);
		}
	}
}

void printtext(char text[])
{
	int i = 0;
	while (text[i])
		putchar(text[i++]);
}

int fold_newline(char text[], int strlen, int cols)
{
	printtext(text);
	cols = 0;

	return cols;
}

int fold_tab(char text[], int strlen, int cols)
{
	strlen = TABSTOP;

	if (cols && (MAXCOL <= (cols + strlen))) {
		putchar('\n');
		cols = 0;
	}

	printtext(text);
	cols += strlen;

	return cols;
}

int fold_space(char text[], int strlen, int cols)
{
	if (cols && (MAXCOL <= (cols + strlen))) {
		putchar('\n');
		cols = 0;
	}

	printtext(text);
	cols += strlen;

	return cols;
}

int fold_text(char text[], int strlen, int cols)
{
	if (cols && (MAXCOL <= (cols + strlen))) {
		putchar('\n');
		cols = 0;
	}

	printtext(text);
	cols += strlen;

	return cols;
}

int fold(char text[], int strlen, int cols)
{			
	switch (text[0]) {
		case '\n':
			cols = fold_newline(text, strlen, cols);
			break;
		case '\t':
			cols = fold_tab(text, strlen, cols);
			break;
		case ' ':
			cols = fold_space(text, strlen, cols);
			break;
		default:
			cols = fold_text(text, strlen, cols);
			break;
	}
	return cols;
}

int gettext_x(char text[], int maxlen)
{
	int i;
	int c;

	for (i = 0; ((c = getchar()) != EOF) && i < maxlen - 1; ++i) {
		if ('\n' == c || ' ' == c || '\t' == c) {
			text[i++] = c;
			break;
		}
		text[i] = c;
	}

	text[i] = '\0';

	return i;
}

