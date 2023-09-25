#include "sort.h"

/**
 * find_max - Find the highest integer in an array.
 * @arr: The array of integers.
 * @sz: The size of the array.
 *
 * Return: The largest integer in the array.
 */
int find_max(int *arr, int sz)
{
	int mx_value, idx;

	for (mx_value = arr[0], idx = 1; idx < sz; idx++)
	{
		if (arr[idx] > mx_value)
			mx_value = arr[idx];
	}

	return (mx_value);
}

/**
 * counting_sort - Organize an array of integers in ascending order
 *                 using the counting sort method.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Shows the counting array after filling it.
 */
void counting_sort(int *array, size_t size)
{
	int *count_arr, *output, highest, idx;

	if (!array || size < 2)
		return;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	highest = find_max(array, size);

	count_arr = malloc(sizeof(int) * (highest + 1));
	if (!count_arr)
	{
		free(output);
		return;
	}

	for (idx = 0; idx <= highest; idx++)
		count_arr[idx] = 0;

	for (idx = 0; idx < (int)size; idx++)
		count_arr[array[idx]]++;

	for (idx = 1; idx <= highest; idx++)
		count_arr[idx] += count_arr[idx - 1];

	print_array(count_arr, highest + 1);

	for (idx = 0; idx < (int)size; idx++)
	{
		output[count_arr[array[idx]] - 1] = array[idx];
		count_arr[array[idx]]--;
	}

	for (idx = 0; idx < (int)size; idx++)
		array[idx] = output[idx];

	free(output);
	free(count_arr);
}
