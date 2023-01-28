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

void swap(int *first, int *second)
{
        int temp;

        temp = *first;
        *first = *second;
        *second = temp;
}

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

void sort(int array[], int low, int high, int size)
{
        if (low < high)
        {
                int pi = partition(array, low, high, size);
                sort(array, low, pi - 1, size);
                sort(array, pi + 1, high, size);
        }
}
