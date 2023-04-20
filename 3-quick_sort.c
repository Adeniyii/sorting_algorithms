#include "sort.h"

int partition(int *array, int top, int bottom, size_t size);
void sort(int *array, int top, int bottom, size_t size);

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 *
 * @array: array to sort
 * @size: size of array
*/
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	sort(array, 0, (int) size - 1, size);
}

/**
 * sort - sorts array recursively
 *
 * @array: array to sort
 * @top: top of array
 * @bottom: bottom of array
 * @size: size of array
*/
void sort(int *array, int top, int bottom, size_t size)
{
	int pivot;

	if (top >= bottom)
		return;

	pivot = partition(array, top, bottom, size);
	sort(array, top, pivot - 1, size);
	sort(array, pivot + 1, bottom, size);
}

/**
 * partition - partitions array around pivot
 *
 * @array: array to partition
 * @top: top of array
 * @bottom: bottom of array
 * @size: size of array
 *
 * Return: index of pivot
*/
int partition(int *array, int top, int bottom, size_t size)
{
	int pivot, tmp, i, j;

	pivot = bottom;
	j = top - 1;

	for (i = top; i < pivot; i++)
	{
		if (array[i] < array[pivot])
		{
			j++;

			if (i == j)
				continue;

			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;

			print_array(array, size);
		}
	}

	j++;

	if (j == pivot)
		return (j);

	tmp = array[j];
	array[j] = array[pivot];
	array[pivot] = tmp;

	print_array(array, size);

	return (j);
}
