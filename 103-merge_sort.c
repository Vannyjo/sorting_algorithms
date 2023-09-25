#include "sort.h"

/**
 * combine_arrays - Combine two subarrays of integers.
 * @arr: The main array.
 * @temp: Temporary array for merging.
 * @start: The starting index of the left subarray.
 * @middle: The end index of the left subarray.
 * @end: The end index of the right subarray.
 */
void combine_arrays(int *arr, int *temp, size_t start, size_t middle, size_t end)
{
	size_t i = start, j = middle, k = 0;

	printf("Merging...\n[left]: ");
	print_array(arr + start, middle - start);

	printf("[right]: ");
	print_array(arr + middle, end - middle);

	for (; i < middle && j < end; k++)
		temp[k] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
	while (i < middle)
		temp[k++] = arr[i++];
	while (j < end)
		temp[k++] = arr[j++];

	for (i = start, k = 0; i < end; i++)
		arr[i] = temp[k++];

	printf("[Done]: ");
	print_array(arr + start, end - start);
}

/**
 * sort_recursive - Recursively sort subarrays.
 * @arr: The main array.
 * @temp: Temporary array for merging.
 * @start: The starting index of the current subarray.
 * @end: The ending index of the current subarray.
 */
void sort_recursive(int *arr, int *temp, size_t start, size_t end)
{
	size_t mid;

	if (end - start > 1)
	{
		mid = start + (end - start) / 2;
		sort_recursive(arr, temp, start, mid);
		sort_recursive(arr, temp, mid, end);
		combine_arrays(arr, temp, start, mid, end);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending order.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp_arr;

	if (!array || size < 2)
		return;

	temp_arr = malloc(sizeof(int) * size);
	if (!temp_arr)
		return;

	sort_recursive(array, temp_arr, 0, size);
	free(temp_arr);
}
