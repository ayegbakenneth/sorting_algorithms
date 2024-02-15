#include "sort.h"

/**
 * swap_nodes - Exchange of nodes in a listint_t doubly-linked list.
 * @h: head pointer of a doubly-linked list.
 * @n1: First node to exchange.
 * @n2: Second node to exchange.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - A doubly linked list of integers to sort.
 * @list: A doubly-linked list of integers head pointer.
 *
 * Description: After each swap prints.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cross, *insert, *ken;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (cross = (*list)->next; cross != NULL; cross = ken)
	{
		ken = cross->next;
		insert = cross->prev;
		while (insert != NULL && cross->n < insert->n)
		{
			swap_nodes(list, &insert, cross);
			print_list((const listint_t *)*list);
		}
	}
}
