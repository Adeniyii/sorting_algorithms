#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the
 * Shell sort algorithm, with the Knuth sequence.
 *
 * @array: array to sort
 * @size: size of the array
*/
void shell_sort(int *array, size_t size)
{
	size_t i, j;
	int gap, tmp, cursor;

	gap = 1;

	while (gap < (int)size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j < size; j += gap)
			{
				cursor = j;
				while (array[cursor] < array[cursor - gap])
				{
					tmp = array[cursor];
					array[cursor] = array[cursor - gap];
					array[cursor - gap] = tmp;

					cursor = cursor - gap;

					print_array(array, size);

					if (cursor < 4)
						break;
				}
			}
		}
		if (gap == 1)
			break;

		gap = (gap - 1) / 3;
	}
}
