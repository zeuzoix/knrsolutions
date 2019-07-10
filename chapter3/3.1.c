/* Exercise 3-1. Our binary search makes two tests inside the loop, when one
would suffice (at the price of more tests outside). Write a version with only one
test inside the loop and measure the difference in run-time. */

#include <stdio.h>
#define ARR_LEN(arr) (sizeof(arr)/sizeof(arr[0]))

int is_sorted(int arr[], int len)
{
	int sorted = 1;
	int i, j;

	if (len > 2) {
		i = 0, j = 1;
		while (j < len) 
			if (arr[i++] > arr[j++]) {
				sorted = 0;
				break;
			}
	}

	return sorted;
}

int binsearch(int x, int arr[], int len)
{
	int s, e, mid, found;
	mid = s = 0;
	e = len - 1;
	
	printf("array length %d\n", len);
	while (s <= e && x != arr[mid]) {
		mid = (e + s)/2;
		//printf("x %d mid %d arr[mid] %d\n", x, mid, arr[mid]);
		if (x > arr[mid])
			s = mid + 1;
		else
			e = mid - 1;
	}

	return -1;
}

int binsearch_knr(int x, int arr[], int len)
{
	int s, e, mid, found;
	mid = s = 0;
	e = len - 1;
	
	printf("array length %d\n", len);
	while (s <= e) {
		mid = (e + s)/2;
		//printf("x %d mid %d arr[mid] %d\n", x, mid, arr[mid]);
		if (x > arr[mid])
			s = mid + 1;
		else if (x < arr[mid])
			e = mid - 1;
		else
			return mid;
	}

	return -1;
}

main()
{
	int arr_srt[] = {1, 4, 5, 9, 13, 15, 19, 22, 25, 28, 33, 35, 39, 47, 49};
	int arr_search[] = {1, 4, 5, 9, 13, 15, 19, 22, 25, 28, 33, 35, 39, 47, 49, 0, 11, 50};
	int i = 0;
	int m = -1;

	if (!is_sorted(arr_srt, ARR_LEN(arr_srt))) {
		printf("array is not sorted, exiting");
		return -1;
	}

	for (i = 0 ; i < ARR_LEN(arr_search) ; ++i)
		m = binsearch(arr_search[i], arr_srt, ARR_LEN(arr_srt));
		if (m >= 0)
			printf("%d : yes position : %d\n", arr_search[i], m);
		else
			printf("%d : no\n", arr_search[i]);

}
