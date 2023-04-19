#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using the
 * Selection sort algorithm.
 *
 * @array: array to sort
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	int min_idx, tmp, swapped;
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		min_idx = i;
		swapped = 0;

		for (j = i; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
				swapped = 1;
			}
		}
		if (swapped)
		{
			tmp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = tmp;
			print_array(array, size);
		}
	}
}
