/* Exercise 3-3. Write a function expand (s1, s2) that expands shorthand
   notations like a - z in the string s 1 into the equivalent complete
   list abc ... xyz in s2. Allow for letters of either case and digits,
   and be prepared to handle cases like a-b-c and a-zO-9 and -a-z. Arrange
   that a leading or trailing - is taken literally. */
#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1024

int getline_x(char line[], int maxline);
void expand(char s1[], char s2[]);
int expandable(char s, char e);

main()
{
	char line[MAXLINE];
	char line_exp[MAXLINE];

	while(getline_x(line, MAXLINE)) {
		expand(line, line_exp);
		printf("orig: %s\nexp: %s\n",line, line_exp);
	}
}

int getline_x(char line[], int maxline)
{
	int c;
	int i;
	
	for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c; 

	if ('\n' == c)
		line[i++] = c;

	line[i] = '\0';

	return i;
}

void expand(char s1[], char s2[])
{
	char l = 0;
	char p = 0;
	int i = 0;
	int j = 0;

	while (s1[i]) {
		if (l) {
			if (p) {
				if (expandable(p, s1[i])) {
					while (p < s1[i])
						s2[j++] = p++;
				}
				else {
					s2[j++] = p;
					s2[j++] = l;
				}
				p = 0;
			}
			else {
				if (s1[i] == '-')
					p = l;
				else
					s2[j++] = l;
			}
		}

		l = s1[i++];
	}

	s2[j++] = l;
	s2[j] = s1[i];
}

int expandable(char s, char e)
{
	int check = 0;

	if ((islower(s) && islower(e)) ||
		(isupper(s) && isupper(e)) ||
		(isdigit(s) && isdigit(e))) {
		if (s < e)
			check = 1;
		}

	return check;
}

