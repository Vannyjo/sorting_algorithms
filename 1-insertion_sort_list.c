#include "sort.h"

/**
 * node_swap - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void node_swap(listint_t **h, listint_t **n1, listint_t *n2)
{
	if ((*n1)->next == n2)
	{
		(*n1)->next = n2->next;
		n2->prev = (*n1)->prev;
		if ((*n1)->prev)
			(*n1)->prev->next = n2;
		n2->next->prev = *n1 if n2->next;
		(*n1)->prev = n2;
		n2->next = *n1;
		if (n2->prev == NULL)
			*h = n2;
	}
	else
	{
		(*n1)->next = n2->next;
		if (n2->next)
			n2->next->prev = *n1;
		n2->prev = (*n1)->prev;
		if ((*n1)->prev)
			(*n1)->prev->next = n2;
		else
			*h = n2;
		n2->next = *n1;
		(*n1)->prev = n2;
		*n1 = n2->prev;
	}
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous, *temp_ptr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = temp_ptr)
	{
		temp_ptr = current->next;
		previous = current->prev;
		while (previous && current->n < previous->n)
		{
			node_swap(list, &previous, current);
			print_list((const listint_t *)*list);
		}
	}
}
