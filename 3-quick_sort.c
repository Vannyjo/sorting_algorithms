#include "sort.h"

void switch_values(int *x, int *y);
int partition_scheme(int *array, size_t size, int start, int end);
void recursive_sort(int *array, size_t size, int start, int end);
void quick_sort(int *array, size_t size);

/**
 * switch_values - Modify the positions of two numbers in an array.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */
void switch_values(int *x, int *y)
{
	int holder;

	holder = *x;
	*x = *y;
	*y = holder;
}

/**
 * partition_scheme - Organize a sub-array according to the Lomuto scheme.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sub-array to organize.
 * @end: The ending index of the sub-array to organize.
 *
 * Return: New partition index.
 */
int partition_scheme(int *array, size_t size, int start, int end)
{
	int *pivot, upper, lower;

	pivot = array + end;
	for (upper = lower = start; lower < end; lower++)
	{
		if (array[lower] < *pivot)
		{
			if (upper < lower)
			{
				switch_values(array + lower, array + upper);
				print_array(array, size);
			}
			upper++;
		}
	}

	if (array[upper] > *pivot)
	{
		switch_values(array + upper, pivot);
		print_array(array, size);
	}

	return (upper);
}

/**
 * recursive_sort - Carry out the quicksort algorithm using recursion.
 * @array: Pointer to the integer array.
 * @size: Length of the array.
 * @start: Starting point of the sub-array partition.
 * @end: Ending point of the sub-array partition.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void recursive_sort(int *array, size_t size, int start, int end)
{
	int partition_point;

	if (end - start > 0)
	{
		partition_point = partition_scheme(array, size, start, end);
		recursive_sort(array, size, start, partition_point - 1);
		recursive_sort(array, size, partition_point + 1, end);
	}
}

/**
 * quick_sort - Arrange an array of integers in increasing order.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Utilizes the Lomuto partition scheme and outputs
 *              the array after each switch.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive_sort(array, size, 0, size - 1);
}
