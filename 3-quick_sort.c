#include "sort.h"

void swap(int *first, int *second);
int partition(int array[], int low, int high, int size);
void sort(int array[], int low, int high, int size);

/**
 * quick_sort - Quick Sort Algorithm
 *
 * @array: Array to be sorted
 * @size: size of the @array
 */
void quick_sort(int *array, size_t size)
{
	sort(array, 0, size - 1, size);
}

/**
 * swap - swap to integers using pointers
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

/**
 * partition - helper function to divide/partition items in array
 * less than or greater than a pivot
 *
 * @array: Array of integers
 * @low: lower index
 * @high: higher index
 * @size: size of the @array
 *
 * Return: index incremented
 */
int partition(int array[], int low, int high, int size)
{
	int pivot;
	int i, j;

	pivot = array[high];
	i = (low - 1);

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);

	return (i + 1);
}

/**
 * sort - helper function to perform recursive sorting process
 * on partitions less or greater than the pivot
 *
 * @array: Array to be sorted
 * @low: lower index
 * @high: higher index
 * @size: size of the @array
 */
void sort(int array[], int low, int high, int size)
{
	if (low < high)
	{
		int pi = partition(array, low, high, size);

		sort(array, low, pi - 1, size);
		sort(array, pi + 1, high, size);
	}
}
