#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - To swap a node in a listint_t doubly-linked list ahead.
 * @list: This points to the head of a doubly-linked list of integers.
 * @tail: This points to the tail of the doubly-linked list.
 * @shaker: While this points to the current swapping node of the cocktail shaker.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *ken = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = ken;
	else
		*list = ken;
	ken->prev = (*shaker)->prev;
	(*shaker)->next = ken->next;
	if (ken->next != NULL)
		ken->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = ken;
	ken->next = *shaker;
	*shaker = ken;
}

/**
 * swap_node_behind - This swap a node in a listint_t doubly-linked list.
 * @list: Head of a doubly-linked list.
 * @tail: Tail of the doubly-linked list.
 * @shaker: Points to the current swapping node.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *ken = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = ken;
	else
		*tail = ken;
	ken->next = (*shaker)->next;
	(*shaker)->prev = ken->prev;
	if (ken->prev != NULL)
		ken->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = ken;
	ken->prev = *shaker;
	*shaker = ken;
}

/**
 * cocktail_sort_list - This function sort a listint_t doubly-linked list in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: Head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool mercy = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (mercy == false)
	{
		mercy = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				mercy = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				mercy = false;
			}
		}
	}
}
