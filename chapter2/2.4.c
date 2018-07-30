/* Exercise 2-4. Write an alternate version of squeeze (s1,s2) that deletes
   each character in s1 that matches any character in the string s2. */

#include <stdio.h>
#define MAXLINE 20
int getline_1(char line[], int limit)
{
	int i;
	char c;

	for (i = 0 ; i < limit - 1 && (c = getchar()) != '\0' && c != '\n' ; ++i)
		line[i] = c;

	if (c == '\n')
		line[i++] = c;

	line [i] = '\0';

	return i;
}

void squeeze(char s1[], char s2[])
{
	int i;
	int j;
	int k;

	for (k = 0 ; s2[k] ; ++k) {
		for (i = 0, j =0 ; s1[i] ; ++i)
			if (s1[i] != s2[k])
				s1[j++] = s1[i];

		s1[j] = '\0';
	}
	

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

	squeeze(str1, str2);

	printf("Squeezed string 1: %s\n", str1);

}
