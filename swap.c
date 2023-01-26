#include "sort.h"

/**
 * swap - swap two integers using pointers
 * @first: pointer to the first integer
 * @second: pointer to the second integer
 */
void swap(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}
