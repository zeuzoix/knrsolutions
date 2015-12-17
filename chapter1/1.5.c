/* Exercise 1-3. Modify the temperature conversion program to print a heading
 * above the table. */

#include <stdio.h>

#define LOWER 0		/* lower limit of the table */
#define UPPER 300	/* upper limit of the table */
#define STEP  20	/* step size */

/* pring Farenheit-Celsius table
 * for fahr = 0, 20, ..., 300 */
main ()
{
	int fahr;

	for (fahr = UPPER; fahr >=  LOWER; fahr = fahr - STEP) 
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr - 32));
}
