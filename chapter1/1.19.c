/* Exercise 1-19. Write a function reverse (s) that reverses the character
 * string s. Use it to write a program that reverses its input a line at a time. */
#include <stdio.h>
#define MAXLINE 1000

void reverse(char s[]);
int getline_x(char line[], int maxline);
void printline(char line[]);

main ()
{
	char line[MAXLINE];

	getline_x(line, MAXLINE);
	reverse(line);
	printline(line);


}

int getline_x(char line[], int maxline)
{
	int i = 0;
	char c;

	for (i = 0; i < maxline - 1 && ((c = getchar()) != 0) && c != '\n'; ++i)
		line[i] = c;

	if ('\n' == c)
		line[i++] = '\n';

	line[i] = '\0';
	
	return i;
}

void reverse(char s[])
{
	int len = 0;
	int i = 0;

	while (s[len++]);
	len--;

	for (i = 0; i < len/2; ++i) {
		s[i] = s[i] ^ s[len -i - 1];
		s[len - i - 1] = s[i] ^ s[len -i - 1];
		s[i] = s[i] ^ s[len -i - 1];
	}
}

void printline(char line[])
{
	int i = 0;
	while(line[i]) {
		putchar(line[i++]);
	}
}
