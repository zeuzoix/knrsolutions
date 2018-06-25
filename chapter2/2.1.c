/* Exercise 2-1. Write a program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned , by printing appropriate values
 * from standard headers and by direct computation.
 * Harder if you compute them: determine the ranges of the various floating-point types.*/

//limits.h is at /usr/include/limits.h

#include <stdio.h>
#include <limits.h>

main()
{
	unsigned char c = ~0;
	unsigned short s = ~0;
	unsigned int i = ~0;
	unsigned long l = ~0;
	unsigned long ll = ~0;

	printf("\nCalculated ranges:\n\n");

	c = ~0;
	c >>= 1;
	printf("signed char range:\t%4d, %4d\n", -c-1, c); 
	printf("unsigned char max:\t%4u\n", 2*c+1); 

	s = ~0;
	s >>= 1;
	printf("signed short range:\t%6d, %6d\n", -s-1, s); 
	printf("unsigned short range:\t%6u\n", 2*s+1); 

	i = ~0;
	i >>= 1;
	printf("signed int range:\t%11d, %11d\n", -i-1, i); 
	printf("unsigned int range:\t%11u\n", 2*i+1); 

	l = ~0;
	l >>= 1;
	printf("signed long range:\t%20ld, %20ld\n", -l-1, l); 
	printf("unsigned long range:\t%20lu\n", 2*l+1); 

	ll = ~0;
	ll >>= 1;
	printf("signed long long range:\t%20ld, %20ld\n", -ll-1, ll); 
	printf("unsigned long long range:\t%20lu\n", 2*ll+1); 

	printf("\nlimit.h ranges:\n\n");
	printf("signed char range:\t%4d, %4d\n", CHAR_MIN, CHAR_MAX); 
	printf("unsigned char max:\t%4u\n", UCHAR_MAX); 
	printf("signed short range:\t%6d, %6d\n", SHRT_MIN, SHRT_MAX); 
	printf("unsigned short max:\t%6u\n", USHRT_MAX); 
	printf("signed int range:\t%11d, %11d\n", INT_MIN, INT_MAX); 
	printf("unsigned int max:\t%11u\n", UINT_MAX); 
	printf("signed long range:\t%20ld, %20ld\n", LONG_MIN, LONG_MAX); 
	printf("unsigned long max:\t%20lu\n", ULONG_MAX); 
	printf("signed long long range:\t%20ld, %20ld\n", LLONG_MIN, LLONG_MAX); 
	printf("unsigned long long max:\t%20lu\n", ULLONG_MAX); 

}
