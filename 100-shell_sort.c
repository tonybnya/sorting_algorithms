#include "sort.h"

/**
 * shell_sort - Shell Sort Algorithm
 *
 * @array: Array to be sorted
 * @size: size of the @array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, n, tmp;

	if (size < 2)
		return;

	n = 1;
	while (n < size / 3)
		n = n * 3 + 1;

	while (n > 0)
	{
		for (i = n; i < size; i++)
		{
			tmp = array[i];
			j = i;
			while (j > n - 1 && array[(int) (j - n)] >= (int) tmp)
			{
				array[j] = array[j - n];
				j -= n;
			}
			array[j] = tmp;
		}
		n = (n - 1) / 3;
		print_array(array, size);
	}
}
