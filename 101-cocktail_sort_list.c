#include "sort.h"

/**
 * swaper - this func will exchange 2 of nodes
 * @h: ptr
 * @xlm: 1st node
 * @xlv: 2nd node
 */

void swaper(listing_t **h, listing_t **xlm, listing_t *xlv)
{
	(*xlm)->next = xlv->next;
	if (xlv->next != NULL)
		xlv->next->prev = *xlm;
	xlv->prev = (*xlm)->prev;
	xlv->next = *xlm;
	if ((*xlm)->prev != NULL)
		(*xlm)->prev->next = xlv;
	else
		*h = xlv;
	(*xlm)->prev = xlv;
	*xlm = xlv->prev;
}

/**
 * insertion_sort_list - this func will reaarange the int
 *
 * @list: [ptr]
 *
 */
void insertion_sort_list(listing_t **list)
{
	listing_t *tpl, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tpl = (*list)->next; tpl != NULL; tpl = tmp)
	{
		tmp = tpl->next;
		insert = tpl->prev;
		while (insert != NULL && tpl->n < insert->n)
		{
			swaper(list, &insert, tpl);
			print_list((const listing_t *)*list);
		}
	}
}
