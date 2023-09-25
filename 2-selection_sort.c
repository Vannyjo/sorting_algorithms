#include "sort.h"

/**
 * exchange_values - Modify the positions of two numbers.
 * @x: The first number to exchange.
 * @y: The second number to exchange.
 */
void exchange_values(int *x, int *y)
{
	int buffer;

	buffer = *x;
	*x = *y;
	*y = buffer;
}

/**
 * selection_sort - Arrange an array of integers in ascending order
 *                  using the selection sort technique.
 * @array: Pointer to the array of integers.
 * @size: The length of the array.
 *
 * Description: Outputs the array after each exchange.
 */
void selection_sort(int *array, size_t size)
{
	int *min_position;
	size_t main_idx, sub_idx;

	if (array == NULL || size < 2)
		return;

	for (main_idx = 0; main_idx < size - 1; main_idx++)
	{
		min_position = array + main_idx;
		for (sub_idx = main_idx + 1; sub_idx < size; sub_idx++)
			min_position = (array[sub_idx] < *min_position) ? (array + sub_idx) : min_position;

		if ((array + main_idx) != min_position)
		{
			exchange_values(array + main_idx, min_position);
			print_array(array, size);
		}
	}
}
