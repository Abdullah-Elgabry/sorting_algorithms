#include "sort.h"

/**
 * swap_ints - this func will re-order integers
 *
 * @a: 1st int
 *
 * @b: 2nd int
 *
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * max_heapify - this func will trans tree to bin
 *
 * @array: [bin tree]
 *
 * @size: [size]
 *
 * @base: [tree idx]
 *
 * @root:  nde base
 *
 */

void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t l, r, lga;

	l = 2 * root + 1;
	r = 2 * root + 2;
	lga = root;

	if (l < base && array[l] > array[lga])
		lga = l;
	if (r < base && array[r] > array[lga])
		lga = r;

	if (lga != root)
	{
		swap_ints(array + root, array + lga);
		print_array(array, size);
		max_heapify(array, size, base, lga);
	}
}

/**
 * heap_sort - re-order arr based_on heap algo
 * @array: [int]
 *
 * @size: [size]
 *
 */

void heap_sort(int *array, size_t size)
{
	int xml;

	if (array == NULL || size < 2)
		return;

	for (xml = (size / 2) - 1; xml >= 0; xml--)
		max_heapify(array, size, size, xml);

	for (xml = size - 1; xml > 0; xml--)
	{
		swap_ints(array, array + xml);
		print_array(array, size);
		max_heapify(array, size, xml, 0);
	}
}
