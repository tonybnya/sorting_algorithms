#include "sort.h"

/* void selectioovoidn_sort(int *array, size_t size); */
void swap(int *first, int *second);

/**
 * selection_sort - Selection Sort Algorithm
 *
 * @array: Array to be sorted
 * @size: size of th @array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;

			if (min_idx != i)
			{
				swap(&array[min_idx], &array[i]);
				print_array(array, size);
			}
		}
	}
}
