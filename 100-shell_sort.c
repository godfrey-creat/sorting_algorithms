#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @c: The first integer to swap.
 * @d: The second integer to swap.
 */
void swap_ints(int *c, int *d)
{
	int tmp;

	tmp = *c;
	*c = *d;
	*d = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, k, l;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (k = gap; k < size; k++)
		{
			l = k;
			while (l >= gap && array[l - gap] > array[l])
			{
				swap_ints(array + l, array + (l - gap));
				l -= gap;
			}
		}
		print_array(array, size);
	}
}
