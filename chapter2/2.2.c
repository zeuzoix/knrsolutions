/* for(i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 *     s[i] = c;
 * Exercise 2-2. Write a loop equivalent to the for loop above
 * without using && or ||
 */
#include <stdio.h>
#define MAXLINE 10
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

int getline_2(char line[], int limit)
{
	int i;
	char c;

	for (i = 0 ; i < limit - 1 ; ++i)
	{
		c = getchar();
		if ('\0' == c)
			break;
		if ('\n' == c)
			break;
		line[i] = c;
	}

	if (c == '\n')
		line[i++] = c;

	line [i] = '\0';

	return i;
}

int getline_3(char line[], int limit)
{
	int i;
	char c;

	for (i = 0 ; i < limit - 1 ? (c = getchar()) != '\0' ? c != '\n' : 0 : 0 ; ++i)
		line[i] = c;

	if (c == '\n')
		line[i++] = c;

	line [i] = '\0';

	return i;
}


main()
{
	char my_line[MAXLINE];

	//printf("Got line with %d characters :%s", getline_1(my_line, MAXLINE), my_line);
	//printf("Got line with %d characters :%s", getline_2(my_line, MAXLINE), my_line);
	printf("Got line with %d characters :%s", getline_3(my_line, MAXLINE), my_line);
}
