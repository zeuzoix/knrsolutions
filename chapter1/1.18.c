/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blank lines. */
#include <stdio.h>
#define MAXLINE 1000

int getline_x(char line[], int maxline);
int remove_trailing_blanks(char line[], int len);
void print_line(char line[]);

char test_line[] = "There was a boy   \n";
main()
{
	char line[MAXLINE];
	int len;
	int c;

	while ((len = getline_x(line, MAXLINE)) > 0) {
		if (len)
			len = remove_trailing_blanks(line, len);
		if (line[0] != '\n')
			print_line(line);
	}
//	remove_trailing_blanks(test_line, sizeof(test_line)/sizeof(test_line[0]) - 1);
}

int getline_x(char line[], int maxline)
{
	int i, c;

	for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;

	if ('\n' == c) 
		line[i++] = c;

	line[i] = '\0';

	return i;
}

int remove_trailing_blanks(char line[], int len)
{
	int i;
	int newline = 0;

	if (len == 0)
		return 0;

	for (i = len - 1; i >= 0 ; --i)
	{
		if ((i == (len - 1)) && (line[i] == '\n'))
			newline = 1;
		else if (line[i] != ' ' && line[i] != '\t')
			break;
	}

	if (newline)
		line[++i] = '\n';

	line[++i] = '\0';

	return i;
}

void print_line(char line[])
{
	int i = 0;
	while(line[i])
		putchar(line[i++]);
}
