/* Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with th
   n bits that begin at position p set to the rightmost n bits of y,
   leaving the other bits unchanged. */

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

	line [i] = '\0';

	return i;
}

unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return getbits(x, p, n) | (y & (~0 << n));
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
	unsigned y;
	int p;
	int n;


	printf("Enter value for x:\n");
	getline_1(str, MAXLINE);
	x = htoi(str);
	printf("x = 0x%X\n", x);

	printf("Enter value for y:\n");
	getline_1(str, MAXLINE);
	y = htoi(str);
	printf("y = 0x%X\n", y);

	printf("Enter value for p:\n");
	getline_1(str, MAXLINE);
	p = atoi(str);
	printf("p = %d\n", p);

	printf("Enter value for n:\n");
	getline_1(str, MAXLINE);
	n = atoi(str);
	printf("n = %d\n", n);

	printf("setbits(0x%X, %d, %d ,0x%X): 0x%X\n", x, p, n, y, setbits(x, p, n, y));

}
