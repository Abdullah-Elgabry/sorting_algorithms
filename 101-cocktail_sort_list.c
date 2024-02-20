#include "sort.h"

void swap_node_ahead(listing_t **list, listing_t **hep, listing_t **mixer);
void swap_node_behind(listing_t **list, listing_t **hep, listing_t **mixer);
void cocktail_sort_list(listing_t **list);

/**
 * swap_node_ahead - this func will move the int to order them asc
 * @list: *head
 * @hep: *hep
 * @mixer: my pos now
 */
void swap_node_ahead(listing_t **list, listing_t **hep, listing_t **mixer)
{
	listing_t *tmp = (*mixer)->next;

	if ((*mixer)->prev != NULL)
		(*mixer)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*mixer)->prev;
	(*mixer)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *mixer;
	else
		*hep = *mixer;
	(*mixer)->prev = tmp;
	tmp->next = *mixer;
	*mixer = tmp;
}

/**
 * swap_node_behind - this func will move the int to order them asc backword
 * @list: *head
 *
 * @hep: *hep
 *
 * @mixer: my pos now.
 */

void swap_node_behind(listing_t **list, listing_t **hep, listing_t **mixer)
{
	listing_t *tmp = (*mixer)->prev;

	if ((*mixer)->next != NULL)
		(*mixer)->next->prev = tmp;
	else
		*hep = tmp;
	tmp->next = (*mixer)->next;
	(*mixer)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *mixer;
	else
		*list = *mixer;
	(*mixer)->next = tmp;
	tmp->prev = *mixer;
	*mixer = tmp;
}

/**
 * cocktail_sort_list - re_order the [] based_on cocktail_algo
 *
 * @list: *head
 *
 */

void cocktail_sort_list(listing_t **list)
{
	listing_t *hep, *mixer;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (hep = *list; hep->next != NULL;)
		hep = hep->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (mixer = *list; mixer != hep; mixer = mixer->next)
		{
			if (mixer->n > mixer->next->n)
			{
				swap_node_ahead(list, &hep, &mixer);
				print_list((const listing_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (mixer = mixer->prev; mixer != *list;
				mixer = mixer->prev)
		{
			if (mixer->n < mixer->prev->n)
			{
				swap_node_behind(list, &hep, &mixer);
				print_list((const listing_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
