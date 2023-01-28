#include "sort.h"

void swap(int *first, int *second);
void sort(int *array, int low, int high, int size);

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
 * sort - helper function to perform recursive sorting process
 * on partitions less or greater than the pivot
 *
 * @array: Array to be sorted
 * @low: lower index
 * @high: higher index
 * @size: size of the @array
 */
void sort(int *array, int low, int high, int size)
{
        int i, p, w;

        if (low < high)
        {
                p = high;
                w = low;

                for (i = low; i < high; i++)
                {
                        if (array[i] < array[p])
                        {
                                if (i != w)
                                {
                                        swap(&array[i], &array[w]);
                                        print_array(array, size);
                                }
                                w++;
                        }
                }
                if (w != p && array[w] != array[p])
                {
                        swap(&array[w], &array[p]);
                        print_array(array, size);
                }

                sort(array, low, w - 1, size);
                sort(array, w + 1, high, size);
        }
}
