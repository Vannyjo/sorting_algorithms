#include "sort.h"

/**
 * switch_values - Interchange two integer values in an array.
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
 */
void switch_values(int *x, int *y)
{
	int temp_val;

	temp_val = *x;
	*x = *y;
	*y = temp_val;
}

/**
 * shell_sort - Organize an array of integers in increasing order
 *              leveraging the shell sort method.
 * @array: Pointer to the array of integers.
 * @size: The count of items in the array.
 *
 * Description: Employs the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t interval, outer, inner;

	if (!array || size < 2)
		return;

	for (interval = 1; interval <= size / 3;)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (outer = interval; outer < size; outer++)
		{
			inner = outer;
			while (inner >= interval && array[inner - interval] > array[inner])
			{
				switch_values(&array[inner], &array[inner - interval]);
				inner -= interval;
			}
		}
		print_array(array, size);
		interval /= 3;
	}
}

