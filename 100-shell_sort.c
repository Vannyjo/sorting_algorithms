#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a list.
 * @a: Pointer to the first node.
 * @b: Pointer to the second node.
 */
void swap_nodes(listint_t *a, listint_t *b)
{
	listint_t *temp_prev, *temp_next;

	temp_prev = a->prev;
	temp_next = b->next;

	/* Handling adjacent nodes case */
	if (a->next == b)
	{
		if (temp_prev)
			temp_prev->next = b;
		b->prev = temp_prev;
		a->prev = b;
		b->next = a;
		a->next = temp_next;
		if (temp_next)
			temp_next->prev = a;
	}
	else
	{
		a->prev = b->prev;
		a->next = b->next;
		b->prev = temp_prev;
		b->next = temp_next;
		if (a->prev)
			a->prev->next = a;
		if (a->next)
			a->next->prev = a;
		if (b->prev)
			b->prev->next = b;
		if (b->next)
			b->next->prev = b;
	}
}

/**
 * cocktail_sort_list - Sort a doubly-linked list of integers using
 *                      the cocktail sort algorithm.
 * @list: A pointer to the head of the doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped = 1;

	if (!list || !*list || !(*list)->next)
		return;

	while (swapped)
	{
		swapped = 0;
		for (current = *list; current && current->next; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current, current->next);
				swapped = 1;
				if (!current->prev)
					*list = current;
				print_list(*list);
			}
		}
		if (!swapped)
			break;

		swapped = 0;
		for (; current && current->prev; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(current->prev, current);
				swapped = 1;
				if (!current->prev)
					*list = current;
				print_list(*list);
			}
		}
	}
}
