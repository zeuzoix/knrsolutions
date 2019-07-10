/* Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the
rightmost l-bit in x. Explain why. Use this observation to write a faster ver-
sion of bitcount. */

#include <stdio.h>

int bitcount(unsigned x)
{
	int b = 0;

	for (b = 0; x; ++b, x &= (x-1))
		;
	
	return b;
}

main()
{
	unsigned int i;

	for (i = 0 ; i < 2048 ; ++i)
	       printf("bitcount(%u) = %d\n", i, bitcount(i));

}
