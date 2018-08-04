/* Exercise 2-5. Write the function any (s1, s2), which returns the first location
   in the string s1 where any character from the string s2 occurs, or -1 if s 1
   contains no characters from s2. (The standard library function strpbrk does
   the same job but returns a pointer to the location. */

#include <stdio.h>
#define MAXLINE 20

int getline_1(char line[], int limit)
{
	int i;
	int c;

	for (i = 0 ; i < limit - 1 && (c = getchar()) != '\0' && c != '\n'; ++i)
		line[i] = c;

	if (c == '\n')
		line[i++] = c;

	line[i] = '\0';

	return i;
}

int stribrk(char s1[], char s2[])
{
	int i;
	int j;

	for (i =0 ; s1[i] ; ++i)
		for (j = 0 ; s2[j] ; ++j)
			if (s1[i] == s2[j])
				return i;

	return -1;

}

main()
{
	char str1[MAXLINE];
	char str2[MAXLINE];


	printf("Enter string 1:\n");
	(void)getline_1(str1, MAXLINE);
	/*In the beginning*/

	printf("Enter string 2:\n");
	(void)getline_1(str2, MAXLINE);
	/*aeiou*/

	printf("First match index: %d\n", stribrk(str1, str2));

}
