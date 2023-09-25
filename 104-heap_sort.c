#include "sort.h"

void switch_elements(int *a, int *b);
void make_heap(int *arr, size_t arr_size, size_t end, size_t highest);
void heap_sort(int *arr, size_t arr_size);

/**
 * switch_elements - Switch two integers in an array.
 * @a: The first integer to switch.
 * @b: The second integer to switch.
 */
void switch_elements(int *a, int *b)
{
	int holder;

	holder = *a;
	*a = *b;
	*b = holder;
}

/**
 * make_heap - Construct a max binary heap.
 * @arr: The array of integers representing the binary tree.
 * @arr_size: The total size of the array/tree.
 * @end: The limit of the tree where the heap transformation ends.
 * @highest: The top node of the binary tree.
 */
void make_heap(int *arr, size_t arr_size, size_t end, size_t highest)
{
	size_t left_child, right_child, largest;

	left_child = 2 * highest + 1;
	right_child = 2 * highest + 2;
	largest = highest;

	if (left_child < end && arr[left_child] > arr[largest])
		largest = left_child;
	if (right_child < end && arr[right_child] > arr[largest])
		largest = right_child;

	if (largest != highest)
	{
		switch_elements(arr + highest, arr + largest);
		print_array(arr, arr_size);
		make_heap(arr, arr_size, end, largest);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending order.
 * @arr: The array of integers.
 * @arr_size: The size of the array.
 *
 * Description: Implements the sift-down heap sort algorithm.
 */
void heap_sort(int *arr, size_t arr_size)
{
	int idx;

	if (!arr || arr_size < 2)
		return;

	for (idx = (arr_size / 2) - 1; idx >= 0; idx--)
		make_heap(arr, arr_size, arr_size, idx);

	for (idx = arr_size - 1; idx > 0; idx--)
	{
		switch_elements(arr, arr + idx);
		print_array(arr, arr_size);
		make_heap(arr, arr_size, idx, 0);
	}
}
