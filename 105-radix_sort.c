#include "sort.h"

int find_maximum(int *arr, int len);
void sort_on_digit(int *arr, size_t len, int place_value, int *temp_buffer);
void radix_sort(int *arr, size_t len);

/**
 * find_maximum - Retrieve the maximum value from an integer array.
 * @arr: The array of integers.
 * @len: The length of the array.
 *
 * Return: The largest integer in the array.
 */
int find_maximum(int *arr, int len)
{
	int highest_value = arr[0];
	int i;

	for (i = 1; i < len; i++)
		if (arr[i] > highest_value)
			highest_value = arr[i];

	return (highest_value);
}

/**
 * sort_on_digit - Sort integers based on a specific digit place using counting sort.
 * @arr: The integer array.
 * @len: The array length.
 * @place_value: The digit's place value.
 * @temp_buffer: A temporary buffer for sorting.
 */
void sort_on_digit(int *arr, size_t len, int place_value, int *temp_buffer)
{
	int frequency[10] = {0};
	size_t i;

	for (i = 0; i < len; i++)
		frequency[(arr[i] / place_value) % 10]++;

	for (i = 1; i < 10; i++)
		frequency[i] += frequency[i - 1];

	for (i = len - 1; (int)i >= 0; i--)
	{
		temp_buffer[frequency[(arr[i] / place_value) % 10] - 1] = arr[i];
		frequency[(arr[i] / place_value) % 10]--;
	}

	for (i = 0; i < len; i++)
		arr[i] = temp_buffer[i];
}

/**
 * radix_sort - Implement radix sort on an integer array.
 * @arr: The integer array.
 * @len: The array length.
 */
void radix_sort(int *arr, size_t len)
{
	int max_val, position_value, *aux_buffer;

	if (!arr || len < 2)
		return;

	aux_buffer = malloc(sizeof(int) * len);
	if (!aux_buffer)
		return;

	max_val = find_maximum(arr, len);
	for (position_value = 1; max_val / position_value > 0; position_value *= 10)
	{
		sort_on_digit(arr, len, position_value, aux_buffer);
		print_array(arr, len);
	}

	free(aux_buffer);
}
