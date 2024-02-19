#include "sort.h"

/**
 * swap_nodes - this func will exchange 2 of nodes
 *
 * @h: ptr
 *
 * @n1: 1st node
 * @n2: 2nd node
 */
void swap_nodes(listing_t **h, listing_t **n1, listing_t *n2)
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
 * insertion_sort_list - this func will reaarange the int
 *
 * @list: [ptr]
 *
 */
void insertion_sort_list(listing_t **list)
{
	listing_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listing_t *)*list);
		}
	}
}
