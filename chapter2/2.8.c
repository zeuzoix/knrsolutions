/* Exercise 2-8. Write a function rightrot(x,n) that returns the value of the
   integer x rotated to the right by n bit positions. */

#include <stdio.h>
#include <ctype.h>
#define MAXLINE 20

int getline_1(char line[], int limit)
{
	int i;
	char c;

	for (i = 0 ; i < limit - 1 && (c = getchar()) != '\0' && c != '\n' ; ++i)
		line[i] = c;

	if (c == '\n')
		line[i++] = c;

	line[i] = '\0';

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

int atoi(char line[])
{
	int i;
	int r = 0;
	int d = 0;
	int s = 0;

	for (i = 0 ; line[i] ; ++i) {
		/* check sign */
		if (0 == i && '-' == line[i] && (s = 1))
			continue;

		if (isdigit(line[i]))
			d = line[i] - '0';
		else
			break;

		r = r * 10 + d;
	}

	/* set sign */
	r *= (s ? -1 : 1);

	return r;
}


main()
{
	char str[MAXLINE];
	unsigned x;
	int n;


	printf("Enter value for x:\n");
	getline_1(str, MAXLINE);
	x = htoi(str);
	printf("x = 0x%X\n", x);

	printf("Enter value for n:\n");
	getline_1(str, MAXLINE);
	n = atoi(str);
	printf("n = %d\n", n);

	printf("invertbits(0x%X, %d): 0x%X\n", x, n, rightrot(x, n));
}
