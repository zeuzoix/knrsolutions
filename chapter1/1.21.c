/* Exercise 1-21. Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use the
 * same tab stops as for detab. When either a tab or a single blank would suffice
 * to reach a tab stop, which should be given preference? */
#include <stdio.h>

#define MAXLINE 1024
#define TABSTOP 4

int getline_x(char line[], int maxline);
int entab(char line[]);

main()
{
	char buffer[MAXLINE];

	while (getline_x(buffer, MAXLINE)) {
		entab(buffer);
	}
}

int getline_x(char line[], int maxline)
{
	int i;
	int c;
	for (i = 0; ((c = getchar()) != EOF) && c != '\n' && i < maxline - 1; ++i)
		line[i] = c;

	if (c == '\n')
		line[i++] = c;

	line[i] = '\0';

	return i;
}

int entab(char line[])
{
	int i = 0;
	int ip_spaces = 0;
	int op_tabs = 0;
	int op_spaces = 0;

	while(line[i]) {
		if (' ' == line[i]) {
			ip_spaces++;
		}
		else {
			if (ip_spaces) {
				op_tabs = ip_spaces / TABSTOP;
				op_spaces = ip_spaces % TABSTOP;
				while(op_tabs--)
					putchar('\t');
				while(op_spaces--)
					putchar(' ');
				ip_spaces = 0;
			}
			putchar(line[i]);
		}
		i++;
	}

	return 0;
}
