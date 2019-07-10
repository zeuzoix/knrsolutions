/* Exercise 2-10. Rewrite the function lower, which converts upper case letters
to lower case, with a conditional expression instead of if-else. */

#include <stdio.h>

char lower(char c)
{
	return c >= 'A' && c <= 'Z' ? 'a' + (c - 'A') : c;
}

main()
{
	char arr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnoprstuvwxyz1234567890!@#$%^&*()";
	int i = 0;

	while (arr[i]) {
		printf("lower('%c') = '%c'\n", arr[i], lower(arr[i]));
		++i;
	} 
}

