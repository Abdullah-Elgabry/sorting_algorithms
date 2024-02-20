#include "sort.h"

/**
 * swap_ints - this func will re-order integers
 * @a: 1st int
 * @b: 2nd int
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - this func will re_order the []
 *
 * @array: the [int]
 *
 * @size: [size]
 *
 * @hoare: st pnt
 *
 * @rotx: nd pnt
 *
 * Return: will ret idx
 *
 */

int hoare_partition(int *array, size_t size, int hoare, int rotx)
{
	int lead, up, down;

	lead = array[rotx];
	for (up = hoare - 1, down = rotx + 1; up < down;)
	{
		do {
			up++;
		} while (array[up] < lead);
		do {
			down--;
		} while (array[down] > lead);

		if (up < down)
		{
			swap_ints(array + up, array + down);
			print_array(array, size);
		}
	}

	return (up);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: will re_arr [int]
 * @size: [size]
 * @hoare: st pov
 * @rotx: nd pov
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int hoare, int rotx)
{
	int belong;

	if (rotx - hoare > 0)
	{
		belong = hoare_partition(array, size, hoare, rotx);
		hoare_sort(array, size, hoare, belong - 1);
		hoare_sort(array, size, belong, rotx);
	}
}

/**
 * quick_sort_hoare - this func will re_order the the [] based_on quick_algo
 * @array: [int]
 *
 * @size: [size]
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
