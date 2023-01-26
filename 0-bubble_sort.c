#include "sort.h"

void swap(int *first, int *second);

/**
 * bubble_sort - Bubble Sort Algorithm
 *
 * @array: Array to be sorted
 * @size: size of the @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
	}
}

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
