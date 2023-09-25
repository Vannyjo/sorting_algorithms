#include "sort.h"

/**
 * move_forward - Move a node ahead in a doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @end: A pointer to the tail of the list.
 * @mover: A pointer to the current node being swapped.
 */
void move_forward(listint_t **head, listint_t **end, listint_t **mover)
{
	listint_t *next_node = (*mover)->next;

	if ((*mover)->prev)
		(*mover)->prev->next = next_node;
	else
		*head = next_node;

	next_node->prev = (*mover)->prev;
	(*mover)->next = next_node->next;

	if (next_node->next)
		next_node->next->prev = *mover;
	else
		*end = *mover;

	(*mover)->prev = next_node;
	next_node->next = *mover;
	*mover = next_node;
}

/**
 * move_backward - Move a node backward in a doubly-linked list.
 * @head: A pointer to the head of the list.
 * @end: A pointer to the tail of the list.
 * @mover: A pointer to the current node being swapped.
 */
void move_backward(listint_t **head, listint_t **end, listint_t **mover)
{
	listint_t *prev_node = (*mover)->prev;

	if ((*mover)->next)
		(*mover)->next->prev = prev_node;
	else
		*end = prev_node;

	prev_node->next = (*mover)->next;
	(*mover)->prev = prev_node->prev;

	if (prev_node->prev)
		prev_node->prev->next = *mover;
	else
		*head = *mover;

	(*mover)->next = prev_node;
	prev_node->prev = *mover;
	*mover = prev_node;
}

/**
 * cocktail_sort_list - Sort a doubly-linked list using the cocktail shaker sort.
 * @list: A pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *end, *mover;
	bool no_swaps = false;

	if (!list || !*list || !(*list)->next)
		return;

	for (end = *list; end->next;)
		end = end->next;

	while (!no_swaps)
	{
		no_swaps = true;
		for (mover = *list; mover != end; mover = mover->next)
			if (mover->n > mover->next->n)
			{
				move_forward(list, &end, &mover);
				print_list((const listint_t *)*list);
				no_swaps = false;
			}

		if (no_swaps)
			break;

		no_swaps = true;
		for (; mover->prev && mover != *list; mover = mover->prev)
			if (mover->n < mover->prev->n)
			{
				move_backward(list, &end, &mover);
				print_list((const listint_t *)*list);
				no_swaps = false;
			}
	}
}
