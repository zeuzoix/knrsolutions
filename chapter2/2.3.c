/* Exercise 2·3. Write the function htoi (s ), which converts a string of hexa-
 * decimal digits (including an optional Ox or ox) into its equivalent integer value
 * The allowable digits are 0 through 9, a through f, and A through F
 */
#include <stdio.h>
#include <ctype.h>
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

int htoi(char line[])
{
	int i;
	int r = 0;
	int h = 0;
	int s = 0;

	for (i = 0 ; line[i] ; ++i) {
		/* check sign */
		if (0 == i && '-' == line[i] && (s = 1))
			continue;

		if (i == (s + 1) && line[s] == '0' && tolower(line[s + 1]) == 'x')
			continue;

		if (isdigit(line[i]))
			h = line[i] - '0';
		else if (tolower(line[i]) >= 'a' && tolower(line[i]) <= 'f')
				h = 10 + tolower(line[i]) - 'a';
		else
			break;

		r = r * 16  + h;
	}

	/* set sign */
	r *= (s ? -1 : 1);

	return r;
}

main()
{
	int len;
	char line[MAXLINE];

	printf("Enter a hex string:\n");
	if (0 != (len = getline_1(line, MAXLINE)))
		printf("htoi = %d\n", htoi(line));

}
