#include "sort.h"

int partition(int *array, size_t size);

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 *
 * @array: array to sort
 * @size: size of array
*/
void quick_sort(int *array, size_t size)
{
	int pivot;

	if (size < 2)
		return;

	pivot = partition(array, size);
	quick_sort(array, pivot);
	quick_sort(array, size - pivot);
}

/**
 * partition - partitions array around pivot
 *
 * @array: array to partition
 * @size: size of array
 *
 * Return: index of pivot
*/
int partition(int *array, size_t size)
{
	size_t pivot, tmp, i, j;

	pivot = size - 1;
	j = -1;

	for (i = 0; i < pivot; i++)
	{
		if (array[i] < array[pivot])
		{
			j++;
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;

			print_array(array, size);
		}
	}

	j++;
	tmp = array[j];
	array[j] = array[pivot];
	array[pivot] = tmp;

	return (j);
}
