/* Exercise 1-6. Verify that the expression getchar() != EOF is 0 or 1. */
/* CTRL + D simulates EOF */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

main()
{
	int result = 0;

	result = (getchar() != EOF); 
	printf("result = %d\n", result);

	return 0;
}
